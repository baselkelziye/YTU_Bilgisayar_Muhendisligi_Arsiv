const fetch = require('node-fetch');
const { pool } = require('./config/database'); // Database access for OTP

const BASE_URL = 'http://localhost:5001/api';
const UNIQUE_ID = Date.now();
const TEST_USER = {
    firstName: 'Test',
    lastName: 'Robot',
    email: `test_robot_${UNIQUE_ID}@test.com`,
    password: 'Password123!',
    phone: `+90555${String(UNIQUE_ID).slice(-7)}`
};

let TOKEN = '';
let USER_ID = 0;

async function runTests() {
    console.log('🚀 RecycleShare Tam Özellik Testi Başlıyor...\n');
    console.log(`📝 Test Kullanıcısı: ${TEST_USER.email}`);

    // 1. REGISTER
    try {
        console.log('1️⃣  Kayıt Olunuyor...');
        const regRes = await fetch(`${BASE_URL}/auth/register`, {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify(TEST_USER)
        });
        const regData = await regRes.json();

        if (regData.success) {
            console.log('✅ Kayıt Başarılı! (OTP gönderildi)');
        } else {
            console.log('❌ Kayıt Başarısız Detayı:', JSON.stringify(regData, null, 2));
            throw new Error(`Kayıt başarısız: ${regData.message}`);
        }
    } catch (err) {
        console.error('❌ Kayıt Hatası:', err.message);
        process.exit(1);
    }

    // 1.5 VERIFY OTP (Bypass via DB)
    try {
        console.log('🔹 DB\'den OTP kodu alınıyor...');
        const res = await pool.query('SELECT verification_code FROM users WHERE email = $1', [TEST_USER.email]);

        if (res.rows.length === 0) throw new Error('Kullanıcı DB\'de bulunamadı');
        const otpCode = res.rows[0].verification_code;
        console.log(`🔹 OTP Kodu Bulundu: ${otpCode}`);

        console.log('🔹 OTP Doğrulanıyor...');
        const verifyRes = await fetch(`${BASE_URL}/auth/verify-otp`, {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ email: TEST_USER.email, code: otpCode })
        });
        const verifyData = await verifyRes.json();

        if (verifyData.success) {
            console.log('✅ OTP Doğrulandı!');
        } else {
            throw new Error(`OTP Doğrulama başarısız: ${verifyData.message}`);
        }

    } catch (err) {
        console.error('❌ Doğrulama Hatası:', err.message);
        process.exit(1);
    }

    // 2. LOGIN
    try {
        console.log('\n2️⃣  Giriş Yapılıyor...');
        const loginRes = await fetch(`${BASE_URL}/auth/login`, {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ email: TEST_USER.email, password: TEST_USER.password })
        });
        const loginData = await loginRes.json();

        if (loginData.success) {
            console.log('✅ Giriş Başarılı!');
            TOKEN = loginData.data.token;
            USER_ID = loginData.data.user.userId;
            console.log(`🔑 Token alındı (User ID: ${USER_ID})`);
        } else {
            throw new Error(`Giriş başarısız: ${loginData.message}`);
        }
    } catch (err) {
        console.error('❌ Giriş Hatası:', err.message);
        process.exit(1);
    }

    // Headers with Token
    const authHeaders = {
        'Authorization': `Bearer ${TOKEN}`,
        'Content-Type': 'application/json'
    };

    // 3. WASTE TYPES (Public)
    await testEndpoint('GET /waste/types', '/waste/types', 'GET');

    // 4. CREATE WASTE
    let wasteId = 0;
    try {
        console.log('\n4️⃣  Atık Oluşturuluyor...');
        const wasteRes = await fetch(`${BASE_URL}/waste`, {
            method: 'POST',
            headers: authHeaders,
            body: JSON.stringify({
                type_id: 1,
                amount: 5.5,
                description: 'Otomatik test atığı'
            })
        });
        const wasteData = await wasteRes.json();
        if (wasteData.success) {
            console.log('✅ Atık Oluşturuldu!');
            wasteId = wasteData.data.waste_id;
        } else {
            console.log('❌ Atık oluşturma hatası:', wasteData.data);
        }
    } catch (err) { console.log('❌ İstek hatası:', err.message); }

    // 5. LIST WASTE
    await testEndpoint('GET /waste', '/waste', 'GET', authHeaders);

    // 6. SQL FUNCTIONS & VIEWS
    console.log('\n🔍 SQL Fonksiyonları ve View Testleri:');
    await testEndpoint('GET /waste/search (Search)', '/waste/search?city=Istanbul', 'GET', authHeaders);
    await testEndpoint('GET /reports/active-users (View)', '/reports/active-users', 'GET', authHeaders);
    await testEndpoint('GET /reports/user/monthly (Function/Cursor)', `/reports/user/${USER_ID}/monthly?year=2026&month=1`, 'GET', authHeaders);

    // 7. CONSTRAINT CHECK (Expect Failure)
    console.log('\n🛡️  Kısıtlama Kontrolü (Constraint Check):');
    try {
        const start = Date.now();
        const res = await fetch(`${BASE_URL}/waste`, {
            method: 'POST',
            headers: authHeaders,
            body: JSON.stringify({ type_id: 1, amount: -10, description: 'Negatif miktar' })
        });
        const data = await res.json();
        if (data.success === false) {
            console.log('✅ CHECK Constraint Çalıştı! (Negatif miktar reddedildi)');
        } else {
            console.log('❌ HATA: Negatif miktar kabul edildi!');
        }
    } catch (err) { console.log('❌ İstek hatası:', err.message); }

    console.log('\n🏁 Tüm Özellik Testleri Tamamlandı!');
    pool.end(); // Close DB connection
}

async function testEndpoint(name, url, method, headers = {}) {
    try {
        const start = Date.now();
        const res = await fetch(BASE_URL + url, { method, headers });
        const data = await res.json();
        const duration = Date.now() - start;

        if (data.success) {
            console.log(`✅ ${name} (${duration}ms)`);
        } else {
            console.log(`❌ ${name} - ${data.message} ${JSON.stringify(data)}`);
        }
    } catch (err) {
        console.log(`❌ ${name} - ${err.message}`);
    }
}

runTests();
