const { Pool } = require('pg');

// DATABASE_URL varsa kullan, yoksa local değerleri kullan
const connectionString = process.env.DATABASE_URL;

// SSL sadece cloud (Neon/Railway) için gerekli - URL'de sslmode varsa kullan
const useSSL = connectionString && connectionString.includes('sslmode=require');

const pool = connectionString
  ? new Pool({
    connectionString: connectionString,
    ssl: useSSL ? { rejectUnauthorized: false } : false
  })
  : new Pool({
    host: process.env.DB_HOST || 'localhost',
    port: process.env.DB_PORT || 5432,
    database: process.env.DB_NAME || 'recycleshare',
    user: process.env.DB_USER,
    password: process.env.DB_PASSWORD,
  });


// Test connection
pool.on('connect', () => {
  console.log('✅ Connected to PostgreSQL database');
});

pool.on('error', (err) => {
  console.error('❌ PostgreSQL connection error:', err);
  process.exit(-1);
});

// Initialize database with schema
const initializeDatabase = async () => {
  const fs = require('fs');
  const path = require('path');

  // Log current environment
  const env = process.env.NODE_ENV || 'development';
  console.log(`🌍 Environment: ${env}`);

  // Her zaman schema.sql'i çalıştır (IF NOT EXISTS güvenli yapar)
  console.log('🔧 Checking database schema...');


  try {
    const schemaPath = path.join(__dirname, '../../database/schema.sql');

    // schema.sql dosyası var mı kontrol et
    if (!fs.existsSync(schemaPath)) {
      console.log('⚠️ schema.sql not found - using basic initialization');
      // Fallback: sadece users tablosunu oluştur
      await pool.query(`
        CREATE TABLE IF NOT EXISTS users (
          user_id SERIAL PRIMARY KEY,
          first_name VARCHAR(50) NOT NULL,
          last_name VARCHAR(50) NOT NULL,
          email VARCHAR(100) UNIQUE NOT NULL,
          password VARCHAR(255),
          google_id VARCHAR(255) UNIQUE,
          profile_picture VARCHAR(500),
          phone VARCHAR(20) UNIQUE NOT NULL,
          role VARCHAR(20) NOT NULL DEFAULT 'resident',
          is_verified BOOLEAN DEFAULT FALSE,
          verification_code VARCHAR(6),
          verification_code_expires TIMESTAMP,
          created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
          is_active BOOLEAN DEFAULT TRUE
        );
      `);
      console.log('✅ Basic database schema initialized');
      return;
    }

    // schema.sql dosyasını oku ve çalıştır
    const schema = fs.readFileSync(schemaPath, 'utf8');
    await pool.query(schema);
    console.log('✅ Full database schema initialized from schema.sql');

  } catch (error) {
    // Hata olursa sadece logla, uygulamayı durdurma
    console.error('⚠️ Schema initialization warning:', error.message);
    console.log('📝 Note: Tables may already exist (this is normal)');
  }
};


// Query helper
const query = async (text, params) => {
  const start = Date.now();
  try {
    const result = await pool.query(text, params);
    const duration = Date.now() - start;
    console.log('📊 Query executed', { text: text.substring(0, 50), duration: `${duration}ms`, rows: result.rowCount });
    return result;
  } catch (error) {
    console.error('❌ Query error:', error.message);
    throw error;
  }
};

module.exports = {
  pool,
  query,
  initializeDatabase
};
