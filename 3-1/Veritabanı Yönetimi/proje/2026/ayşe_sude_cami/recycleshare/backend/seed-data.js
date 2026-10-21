const { Pool } = require('pg');
const bcrypt = require('bcrypt');
require('dotenv').config();

const pool = new Pool({
  connectionString: process.env.DATABASE_URL,
  ssl: { rejectUnauthorized: false }
});

async function seedData() {
  try {
    console.log('🌱 Veritabanı seed işlemi başlıyor...\n');
    
    // 1. Users tablosuna veri ekle
    console.log('👤 Users tablosuna veri ekleniyor...');
    const hashedPassword = await bcrypt.hash('Test1234', 12);
    
    const users = [
      ['Ahmet', 'Yılmaz', 'ahmet@test.com', hashedPassword, '+905551111111', 'user', 'İstanbul', 'Kadıköy', 'Moda', 'Bahariye Cad.', 'No: 15'],
      ['Ayşe', 'Kaya', 'ayse@test.com', hashedPassword, '+905552222222', 'user', 'İstanbul', 'Beşiktaş', 'Levent', 'Büyükdere Cad.', 'No: 42'],
      ['Mehmet', 'Demir', 'mehmet@test.com', hashedPassword, '+905553333333', 'user', 'Ankara', 'Çankaya', 'Kızılay', 'Atatürk Blv.', 'No: 8'],
      ['Fatma', 'Şahin', 'fatma@test.com', hashedPassword, '+905554444444', 'user', 'İzmir', 'Konak', 'Alsancak', 'Kordon', 'No: 23'],
      ['Ali', 'Öztürk', 'ali@test.com', hashedPassword, '+905555555555', 'admin', 'İstanbul', 'Üsküdar', 'Çengelköy', 'Çengelköy Cad.', 'No: 7'],
      ['Zeynep', 'Aydın', 'zeynep@test.com', hashedPassword, '+905556666666', 'user', 'Bursa', 'Nilüfer', 'Görükle', 'Üniversite Cad.', 'No: 12'],
      ['Mustafa', 'Çelik', 'mustafa@test.com', hashedPassword, '+905557777777', 'user', 'Antalya', 'Muratpaşa', 'Lara', 'Lara Cad.', 'No: 55'],
      ['Elif', 'Arslan', 'elif@test.com', hashedPassword, '+905558888888', 'user', 'İstanbul', 'Bakırköy', 'Ataköy', 'Sahil Yolu', 'No: 3']
    ];
    
    for (const u of users) {
      try {
        await pool.query(`
          INSERT INTO users (first_name, last_name, email, password, phone, role, city, district, neighborhood, street, address_details, is_verified)
          VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, true)
        `, u);
      } catch (e) {
        // Duplicate hatalarını yoksay
      }
    }
    
    const userCount = await pool.query('SELECT COUNT(*) FROM users');
    console.log(`✅ Users: ${userCount.rows[0].count} kayıt`);
    
    // 2. Waste tablosuna veri ekle
    console.log('\n♻️ Waste tablosuna veri ekleniyor...');
    
    // Önce mevcut user_id'leri al
    const userIds = await pool.query('SELECT user_id FROM users LIMIT 10');
    const ids = userIds.rows.map(r => r.user_id);
    
    // Status değerleri: waiting, reserved, collected, cancelled
    const wastes = [
      [ids[0] || 1, 1, 5.5, 'Temiz karton kutular, ürün ambalajları', 'waiting'],
      [ids[1] || 2, 2, 3.0, 'Cam kavanozlar ve şişeler', 'waiting'],
      [ids[2] || 3, 3, 2.5, 'Eski bilgisayar parçaları', 'waiting'],
      [ids[3] || 4, 4, 10.0, 'PET şişeler ve plastik kaplar', 'waiting'],
      [ids[4] || 5, 5, 1.5, 'Eski piller ve aküler', 'reserved'],
      [ids[0] || 1, 1, 8.0, 'Gazete ve dergiler', 'waiting'],
      [ids[1] || 2, 6, 15.0, 'Organik mutfak atıkları', 'collected'],
      [ids[2] || 3, 2, 4.0, 'Kırık cam eşyalar', 'waiting'],
      [ids[3] || 4, 4, 6.5, 'Plastik oyuncaklar', 'waiting'],
      [ids[4] || 5, 7, 2.0, 'Eski kıyafetler', 'waiting']
    ];
    
    for (const w of wastes) {
      try {
        await pool.query(`
          INSERT INTO waste (user_id, type_id, amount, description, status)
          VALUES ($1, $2, $3, $4, $5)
        `, w);
      } catch (e) {
        console.log('  Waste ekleme hatası:', e.message);
      }
    }
    
    const wasteCount = await pool.query('SELECT COUNT(*) FROM waste');
    console.log(`✅ Waste: ${wasteCount.rows[0].count} kayıt`);
    
    // 3. Reservations tablosuna veri ekle
    console.log('\n📅 Reservations tablosuna veri ekleniyor...');
    
    // Önce waste_id'leri al
    const wasteIds = await pool.query('SELECT waste_id FROM waste LIMIT 10');
    const wIds = wasteIds.rows.map(r => r.waste_id);
    
    // Status değerleri: waiting, reserved, collected, cancelled
    const reservations = [
      [wIds[0] || 1, ids[5] || 6, '2026-01-05 14:00:00', 'waiting'],
      [wIds[1] || 2, ids[6] || 7, '2026-01-06 10:00:00', 'waiting'],
      [wIds[2] || 3, ids[7] || 8, '2026-01-07 16:00:00', 'reserved'],
      [wIds[3] || 4, ids[5] || 6, '2026-01-08 11:00:00', 'waiting'],
      [wIds[4] || 5, ids[6] || 7, '2026-01-09 09:00:00', 'collected'],
      [wIds[5] || 6, ids[7] || 8, '2026-01-10 15:00:00', 'waiting'],
      [wIds[6] || 7, ids[5] || 6, '2026-01-04 13:00:00', 'collected'],
      [wIds[7] || 8, ids[6] || 7, '2026-01-11 17:00:00', 'reserved'],
      [wIds[8] || 9, ids[7] || 8, '2026-01-12 12:00:00', 'waiting'],
      [wIds[9] || 10, ids[5] || 6, '2026-01-13 14:30:00', 'waiting']
    ];
    
    for (const r of reservations) {
      try {
        await pool.query(`
          INSERT INTO reservations (waste_id, collector_id, pickup_datetime, status)
          VALUES ($1, $2, $3, $4)
        `, r);
      } catch (e) {
        console.log('  Reservation ekleme hatası:', e.message);
      }
    }
    
    const resCount = await pool.query('SELECT COUNT(*) FROM reservations');
    console.log(`✅ Reservations: ${resCount.rows[0].count} kayıt`);
    
    // 4. Environmental_scores tablosuna veri ekle
    console.log('\n🌍 Environmental_scores tablosuna veri ekleniyor...');
    
    const scores = [
      [ids[0] || 1, 12, 2025, 150],
      [ids[1] || 2, 12, 2025, 200],
      [ids[2] || 3, 12, 2025, 175],
      [ids[3] || 4, 12, 2025, 120],
      [ids[4] || 5, 12, 2025, 300],
      [ids[0] || 1, 1, 2026, 50],
      [ids[1] || 2, 1, 2026, 80],
      [ids[2] || 3, 1, 2026, 65],
      [ids[3] || 4, 1, 2026, 40],
      [ids[4] || 5, 1, 2026, 95]
    ];
    
    for (const s of scores) {
      try {
        await pool.query(`
          INSERT INTO environmental_scores (user_id, month, year, total_score)
          VALUES ($1, $2, $3, $4)
        `, s);
      } catch (e) {
        console.log('  Score ekleme hatası:', e.message);
      }
    }
    
    const scoreCount = await pool.query('SELECT COUNT(*) FROM environmental_scores');
    console.log(`✅ Environmental_scores: ${scoreCount.rows[0].count} kayıt`);
    
    // Sonuç özeti
    console.log('\n' + '='.repeat(50));
    console.log('📊 SEED İŞLEMİ TAMAMLANDI!');
    console.log('='.repeat(50));
    
    const tables = ['users', 'waste_types', 'waste', 'reservations', 'environmental_scores'];
    for (const t of tables) {
      const count = await pool.query(`SELECT COUNT(*) FROM ${t}`);
      const status = count.rows[0].count >= 10 ? '✅' : '⚠️';
      console.log(`${status} ${t}: ${count.rows[0].count} kayıt`);
    }
    
    await pool.end();
    
  } catch (e) {
    console.error('❌ Hata:', e.message);
    await pool.end();
  }
}

seedData();
