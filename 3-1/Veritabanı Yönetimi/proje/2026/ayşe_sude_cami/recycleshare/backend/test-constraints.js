require('dotenv').config();
const { pool } = require('./config/database');

async function testConstraints() {
    console.log('🛡️  SQL Kısıtlamaları Test Ediliyor...\n');
    const client = await pool.connect();

    try {
        // Test 1: CHECK constraint (users.role)
        // Beklenen: Hata (role sadece 'admin' veya 'resident' olabilir)
        console.log('1️⃣  Test: Geçersiz Rol Kontrolü (users.role)');
        try {
            await client.query(`
        INSERT INTO users (first_name, last_name, email, phone, role) 
        VALUES ('Test', 'User', 'fail@test.com', '123456', 'superadmin')
      `);
            console.log('❌ BAŞARISIZ: Geçersiz role izin verildi!');
        } catch (err) {
            if (err.code === '23514') { // check_violation
                console.log('✅ BAŞARILI: Kısıtlama çalıştı! (Hata: ' + err.message + ')');
            } else {
                console.log('⚠️  Farklı bir hata alındı:', err.message);
            }
        }
        console.log('----------------------------------------');

        // Test 2: CHECK constraint (waste.amount)
        // Beklenen: Hata (amount > 0 olmalı)
        console.log('2️⃣  Test: Atık Miktarı Kontrolü (waste.amount <= 0)');
        try {
            await client.query(`
        INSERT INTO waste (user_id, type_id, amount, status) 
        VALUES (2, 1, -5, 'waiting')
      `);
            console.log('❌ BAŞARISIZ: Negatif miktara izin verildi!');
        } catch (err) {
            if (err.code === '23514') {
                console.log('✅ BAŞARILI: Kısıtlama çalıştı! (Hata: ' + err.message + ')');
            } else {
                console.log('⚠️  Farklı bir hata alındı:', err.message);
            }
        }
        console.log('----------------------------------------');

        // Test 3: CHECK constraint (environmental_scores.month)
        // Beklenen: Hata (month 1-12 arasında olmalı)
        console.log('3️⃣  Test: Ay Kontrolü (environmental_scores.month)');
        try {
            await client.query(`
        INSERT INTO environmental_scores (user_id, month, year, total_score) 
        VALUES (2, 13, 2026, 100)
      `);
            console.log('❌ BAŞARISIZ: Geçersiz aya izin verildi!');
        } catch (err) {
            if (err.code === '23514') {
                console.log('✅ BAŞARILI: Kısıtlama çalıştı! (Hata: ' + err.message + ')');
            } else {
                console.log('⚠️  Farklı bir hata alındı:', err.message);
            }
        }
        console.log('----------------------------------------');

        // Test 4: UNIQUE constraint (users.email)
        // Beklenen: Hata (aynı email ile kayıt)
        console.log('4️⃣  Test: Unique Email Kontrolü');
        try {
            // Mevcut bir email kullanalım (örn: asudecmi.98@gmail.com)
            await client.query(`
        INSERT INTO users (first_name, last_name, email, phone) 
        VALUES ('Clone', 'User', 'asudecmi.98@gmail.com', '999999')
      `);
            console.log('❌ BAŞARISIZ: Duplicate email\'e izin verildi!');
        } catch (err) {
            if (err.code === '23505') { // unique_violation
                console.log('✅ BAŞARILI: Kısıtlama çalıştı! (Hata: ' + err.message + ')');
            } else {
                console.log('⚠️  Farklı bir hata alındı:', err.message);
            }
        }
        console.log('----------------------------------------');

        // Test 5: FOREIGN KEY (ON DELETE RESTRICT)
        // Beklenen: Hata (Kullanılan bir atık türü silinemez)
        console.log('5️⃣  Test: Silme Kısıtı (ON DELETE RESTRICT)');
        try {
            // type_id=1 (Cardboard) kullanımda olduğu için silinememeli
            await client.query(`DELETE FROM waste_types WHERE type_id = 1`);
            console.log('❌ BAŞARISIZ: Kullanılan atık türü silindi!');
        } catch (err) {
            if (err.code === '23503') { // foreign_key_violation
                console.log('✅ BAŞARILI: Kısıtlama çalıştı! (Hata: ' + err.message + ')');
            } else {
                console.log('⚠️  Farklı bir hata alındı:', err.message);
            }
        }
        console.log('----------------------------------------');

        console.log('\n🏁 Testler Tamamlandı!');

    } catch (error) {
        console.error('Genel Test Hatası:', error);
    } finally {
        client.release();
        pool.end();
    }
}

testConstraints();
