const { Pool } = require('pg');
require('dotenv').config();

const pool = new Pool({
  connectionString: process.env.DATABASE_URL,
  ssl: { rejectUnauthorized: false }
});

async function setupDatabaseObjects() {
  try {
    console.log('🔧 Veritabanı objeleri oluşturuluyor...\n');

    // 1. Trigger logs tablosu
    console.log('📋 Trigger logs tablosu...');
    await pool.query(`
      CREATE TABLE IF NOT EXISTS trigger_logs (
        log_id SERIAL PRIMARY KEY,
        trigger_name VARCHAR(100) NOT NULL,
        table_name VARCHAR(100) NOT NULL,
        action VARCHAR(20) NOT NULL,
        old_data JSONB,
        new_data JSONB,
        message TEXT NOT NULL,
        created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
      )
    `);
    console.log('✅ trigger_logs tablosu oluşturuldu');

    // 2. Sequence
    console.log('\n📋 Sequence...');
    await pool.query(`
      CREATE SEQUENCE IF NOT EXISTS reservation_number_seq
        START WITH 1000
        INCREMENT BY 1
        NO MAXVALUE
        CACHE 1
    `);
    console.log('✅ reservation_number_seq oluşturuldu');

    // 3. Views
    console.log('\n📋 Views...');

    await pool.query(`
      CREATE OR REPLACE VIEW v_active_waste_details AS
      SELECT 
        w.waste_id,
        w.amount,
        w.description,
        w.status,
        w.record_date,
        wt.type_name,
        wt.official_unit,
        wt.recycle_score,
        u.user_id,
        u.first_name || ' ' || u.last_name AS owner_name,
        u.city,
        u.district,
        u.neighborhood,
        u.phone AS owner_phone
      FROM waste w
      JOIN waste_types wt ON w.type_id = wt.type_id
      JOIN users u ON w.user_id = u.user_id
      WHERE w.status IN ('waiting', 'reserved')
      ORDER BY w.record_date DESC
    `);
    console.log('✅ v_active_waste_details oluşturuldu');

    await pool.query(`
      CREATE OR REPLACE VIEW v_user_statistics AS
      SELECT 
        u.user_id,
        u.first_name || ' ' || u.last_name AS full_name,
        u.email,
        u.city,
        COALESCE((SELECT COUNT(*) FROM waste w WHERE w.user_id = u.user_id), 0) AS total_waste_posted,
        COALESCE((SELECT COUNT(*) FROM reservations r WHERE r.collector_id = u.user_id), 0) AS total_reservations_made,
        COALESCE((SELECT SUM(es.total_score) FROM environmental_scores es WHERE es.user_id = u.user_id), 0) AS total_environmental_score
      FROM users u
    `);
    console.log('✅ v_user_statistics oluşturuldu');

    await pool.query(`
      CREATE OR REPLACE VIEW v_monthly_recycling_report AS
      SELECT 
        EXTRACT(YEAR FROM w.record_date) AS year,
        EXTRACT(MONTH FROM w.record_date) AS month,
        wt.type_name,
        COUNT(*) AS total_items,
        SUM(w.amount) AS total_amount,
        wt.official_unit,
        SUM(w.amount * wt.recycle_score) AS total_score_contribution
      FROM waste w
      JOIN waste_types wt ON w.type_id = wt.type_id
      WHERE w.status = 'collected'
      GROUP BY EXTRACT(YEAR FROM w.record_date), EXTRACT(MONTH FROM w.record_date), wt.type_name, wt.official_unit
      ORDER BY year DESC, month DESC, total_amount DESC
    `);
    console.log('✅ v_monthly_recycling_report oluşturuldu');

    // 4. Functions
    console.log('\n📋 Functions...');

    await pool.query(`
      CREATE OR REPLACE FUNCTION fn_calculate_user_total_score(p_user_id INTEGER)
      RETURNS INTEGER AS $$
      DECLARE
        total INTEGER;
      BEGIN
        SELECT COALESCE(SUM(w.amount * wt.recycle_score), 0)::INTEGER
        INTO total
        FROM waste w
        JOIN waste_types wt ON w.type_id = wt.type_id
        WHERE w.user_id = p_user_id AND w.status = 'collected';
        
        RETURN total;
      END;
      $$ LANGUAGE plpgsql
    `);
    console.log('✅ fn_calculate_user_total_score oluşturuldu');

    await pool.query(`
      CREATE OR REPLACE FUNCTION fn_get_waste_by_city(p_city VARCHAR)
      RETURNS TABLE(
        waste_id INTEGER,
        type_name VARCHAR,
        amount DECIMAL,
        owner_name TEXT,
        district VARCHAR,
        status VARCHAR
      ) AS $$
      BEGIN
        RETURN QUERY
        SELECT 
          w.waste_id,
          wt.type_name,
          w.amount,
          (u.first_name || ' ' || u.last_name)::TEXT,
          u.district,
          w.status
        FROM waste w
        JOIN waste_types wt ON w.type_id = wt.type_id
        JOIN users u ON w.user_id = u.user_id
        WHERE u.city = p_city AND w.status IN ('waiting', 'reserved')
        ORDER BY w.record_date DESC;
      END;
      $$ LANGUAGE plpgsql
    `);
    console.log('✅ fn_get_waste_by_city oluşturuldu');

    await pool.query(`
      CREATE OR REPLACE FUNCTION fn_get_user_monthly_report(
        p_user_id INTEGER,
        p_year INTEGER,
        p_month INTEGER
      )
      RETURNS TABLE(
        report_type VARCHAR,
        type_name VARCHAR,
        item_count BIGINT,
        total_amount DECIMAL,
        total_score BIGINT,
        details TEXT
      ) AS $$
      DECLARE
        waste_cursor CURSOR FOR
          SELECT 
            wt.type_name,
            COUNT(*) as cnt,
            SUM(w.amount) as total_amt,
            SUM(w.amount * wt.recycle_score)::BIGINT as score
          FROM waste w
          JOIN waste_types wt ON w.type_id = wt.type_id
          WHERE w.user_id = p_user_id 
            AND EXTRACT(YEAR FROM w.record_date) = p_year
            AND EXTRACT(MONTH FROM w.record_date) = p_month
            AND w.status = 'collected'
          GROUP BY wt.type_name;
        
        waste_record RECORD;
        total_items BIGINT := 0;
        grand_total_amount DECIMAL := 0;
        grand_total_score BIGINT := 0;
      BEGIN
        OPEN waste_cursor;
        LOOP
          FETCH waste_cursor INTO waste_record;
          EXIT WHEN NOT FOUND;
          
          report_type := 'WASTE_DETAIL';
          type_name := waste_record.type_name;
          item_count := waste_record.cnt;
          total_amount := waste_record.total_amt;
          total_score := waste_record.score;
          details := 'Atık türü detayı: ' || waste_record.type_name;
          RETURN NEXT;
          
          total_items := total_items + waste_record.cnt;
          grand_total_amount := grand_total_amount + waste_record.total_amt;
          grand_total_score := grand_total_score + waste_record.score;
        END LOOP;
        CLOSE waste_cursor;
        
        report_type := 'SUMMARY';
        type_name := 'TOPLAM';
        item_count := total_items;
        total_amount := grand_total_amount;
        total_score := grand_total_score;
        details := p_year || '-' || p_month || ' dönemi özeti';
        RETURN NEXT;
      END;
      $$ LANGUAGE plpgsql
    `);
    console.log('✅ fn_get_user_monthly_report oluşturuldu (CURSOR & RECORD)');

    // 5. Triggers
    console.log('\n📋 Triggers...');

    // Trigger 1: Environmental Score Update
    await pool.query(`
      CREATE OR REPLACE FUNCTION trg_fn_update_environmental_score()
      RETURNS TRIGGER AS $$
      DECLARE
        v_score INTEGER;
        v_current_month INTEGER;
        v_current_year INTEGER;
        v_message TEXT;
      BEGIN
        IF NEW.status = 'collected' AND (TG_OP = 'INSERT' OR OLD.status IS NULL OR OLD.status != 'collected') THEN
          SELECT recycle_score INTO v_score
          FROM waste_types
          WHERE type_id = NEW.type_id;
          
          v_current_month := EXTRACT(MONTH FROM CURRENT_DATE);
          v_current_year := EXTRACT(YEAR FROM CURRENT_DATE);
          
          INSERT INTO environmental_scores (user_id, month, year, total_score)
          VALUES (NEW.user_id, v_current_month, v_current_year, (NEW.amount * v_score)::INTEGER)
          ON CONFLICT (user_id, month, year)
          DO UPDATE SET total_score = environmental_scores.total_score + (NEW.amount * v_score)::INTEGER;
          
          v_message := 'Tebrikler! ' || (NEW.amount * v_score)::INTEGER || ' çevresel puan kazandınız!';
          
          INSERT INTO trigger_logs (trigger_name, table_name, action, new_data, message)
          VALUES ('trg_update_environmental_score', 'waste', TG_OP, row_to_json(NEW), v_message);
        END IF;
        
        RETURN NEW;
      END;
      $$ LANGUAGE plpgsql
    `);

    await pool.query(`DROP TRIGGER IF EXISTS trg_update_environmental_score ON waste`);
    await pool.query(`
      CREATE TRIGGER trg_update_environmental_score
        AFTER INSERT OR UPDATE ON waste
        FOR EACH ROW
        EXECUTE FUNCTION trg_fn_update_environmental_score()
    `);
    console.log('✅ trg_update_environmental_score oluşturuldu');

    // Trigger 2: Reservation Status Change
    await pool.query(`
      CREATE OR REPLACE FUNCTION trg_fn_reservation_status_change()
      RETURNS TRIGGER AS $$
      DECLARE
        v_message TEXT;
        v_collector_name TEXT;
      BEGIN
        IF TG_OP = 'INSERT' THEN
          UPDATE waste SET status = 'reserved' WHERE waste_id = NEW.waste_id;
          
          SELECT first_name || ' ' || last_name INTO v_collector_name 
          FROM users WHERE user_id = NEW.collector_id;
          
          v_message := 'Atığınız için yeni rezervasyon! Toplayıcı: ' || v_collector_name || 
                       ', Tarih: ' || TO_CHAR(NEW.pickup_datetime, 'DD.MM.YYYY HH24:MI');
          
          INSERT INTO trigger_logs (trigger_name, table_name, action, new_data, message)
          VALUES ('trg_reservation_status_change', 'reservations', 'INSERT', row_to_json(NEW), v_message);
          
        ELSIF TG_OP = 'UPDATE' THEN
          IF NEW.status = 'collected' AND OLD.status != 'collected' THEN
            UPDATE waste SET status = 'collected' WHERE waste_id = NEW.waste_id;
            
            v_message := 'Atık başarıyla toplandı! Reservation ID: ' || NEW.reservation_id;
            
            INSERT INTO trigger_logs (trigger_name, table_name, action, old_data, new_data, message)
            VALUES ('trg_reservation_status_change', 'reservations', 'UPDATE', row_to_json(OLD), row_to_json(NEW), v_message);
            
          ELSIF NEW.status = 'cancelled' AND OLD.status != 'cancelled' THEN
            UPDATE waste SET status = 'waiting' WHERE waste_id = NEW.waste_id;
            
            v_message := 'Rezervasyon iptal edildi. Atık tekrar listeye eklendi.';
            
            INSERT INTO trigger_logs (trigger_name, table_name, action, old_data, new_data, message)
            VALUES ('trg_reservation_status_change', 'reservations', 'UPDATE', row_to_json(OLD), row_to_json(NEW), v_message);
          END IF;
        END IF;
        
        RETURN NEW;
      END;
      $$ LANGUAGE plpgsql
    `);

    await pool.query(`DROP TRIGGER IF EXISTS trg_reservation_status_change ON reservations`);
    await pool.query(`
      CREATE TRIGGER trg_reservation_status_change
        AFTER INSERT OR UPDATE ON reservations
        FOR EACH ROW
        EXECUTE FUNCTION trg_fn_reservation_status_change()
    `);
    console.log('✅ trg_reservation_status_change oluşturuldu');

    // 6. Indexler
    console.log('\n📋 Indexes...');

    const indexes = [
      'CREATE INDEX IF NOT EXISTS idx_users_city ON users(city)',
      'CREATE INDEX IF NOT EXISTS idx_waste_status ON waste(status)',
      'CREATE INDEX IF NOT EXISTS idx_waste_type ON waste(type_id)',
      'CREATE INDEX IF NOT EXISTS idx_waste_user ON waste(user_id)',
      'CREATE INDEX IF NOT EXISTS idx_waste_date ON waste(record_date DESC)',
      'CREATE INDEX IF NOT EXISTS idx_reservations_status ON reservations(status)',
      'CREATE INDEX IF NOT EXISTS idx_reservations_collector ON reservations(collector_id)',
      'CREATE INDEX IF NOT EXISTS idx_reservations_pickup ON reservations(pickup_datetime)',
      'CREATE INDEX IF NOT EXISTS idx_scores_user_period ON environmental_scores(user_id, year, month)'
    ];

    for (const idx of indexes) {
      await pool.query(idx);
    }
    console.log('✅ Tüm indexler oluşturuldu');

    // Sonuç
    console.log('\n' + '='.repeat(50));
    console.log('🎉 VERİTABANI OBJELERİ BAŞARIYLA OLUŞTURULDU!');
    console.log('='.repeat(50));
    console.log('\n📊 Oluşturulan objeler:');
    console.log('  - 1 Tablo (trigger_logs)');
    console.log('  - 1 Sequence (reservation_number_seq)');
    console.log('  - 3 View (v_active_waste_details, v_user_statistics, v_monthly_recycling_report)');
    console.log('  - 3 Function (fn_calculate_user_total_score, fn_get_waste_by_city, fn_get_user_monthly_report)');
    console.log('  - 2 Trigger (trg_update_environmental_score, trg_reservation_status_change)');
    console.log('  - 9 Index');

    await pool.end();

  } catch (e) {
    console.error('❌ Hata:', e.message);
    await pool.end();
  }
}

setupDatabaseObjects();
