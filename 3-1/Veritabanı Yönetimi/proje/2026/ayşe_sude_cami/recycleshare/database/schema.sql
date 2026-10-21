-- ============================================
-- RecycleShare - Veritabanı Şeması
-- PostgreSQL 17 (Neon Cloud)
-- ============================================
-- Ödev Gereksinimleri:
-- ✅ En az 4 tablo (6 tablo var: users, waste_types, waste, reservations, environmental_scores, trigger_logs)
-- ✅ Her tabloda en az 10 kayıt
-- ✅ Primary key ve foreign key kısıtları
-- ✅ Silme kısıtı (ON DELETE CASCADE/RESTRICT)
-- ✅ Sayı kısıtı (CHECK constraint)
-- ✅ VIEW tanımı
-- ✅ INDEX tanımı
-- ✅ SEQUENCE tanımı
-- ✅ 3 SQL fonksiyonu (biri RECORD ve CURSOR ile)
-- ✅ 2 TRIGGER
-- ✅ UNION/INTERSECT/EXCEPT sorgusu
-- ✅ Aggregate fonksiyonlar ve HAVING
-- ============================================

-- ============================================
-- 1. TABLOLAR (6 tablo: users, waste_types, waste, reservations, environmental_scores, trigger_logs)
-- ============================================

-- Users (Kullanıcılar)
CREATE TABLE IF NOT EXISTS users (
    user_id SERIAL PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    password VARCHAR(255),
    google_id VARCHAR(255) UNIQUE,
    profile_picture VARCHAR(500),
    phone VARCHAR(20) UNIQUE NOT NULL,
    role VARCHAR(20) NOT NULL DEFAULT 'resident' CHECK (role IN ('admin', 'resident')),
    city VARCHAR(100),
    district VARCHAR(100),
    neighborhood VARCHAR(100),
    street VARCHAR(200),
    address_details TEXT,
    is_verified BOOLEAN DEFAULT FALSE,
    verification_code VARCHAR(6),
    verification_code_expires TIMESTAMP,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    is_active BOOLEAN DEFAULT TRUE
);

-- Waste Types (Atık Türleri)
CREATE TABLE IF NOT EXISTS waste_types (
    type_id SERIAL PRIMARY KEY,
    type_name VARCHAR(100) NOT NULL UNIQUE,
    official_unit VARCHAR(20) NOT NULL,
    recycle_score INTEGER NOT NULL CHECK (recycle_score >= 0 AND recycle_score <= 300)
);

-- Waste (Atıklar) - Silme ve Sayı Kısıtı Örneği
CREATE TABLE IF NOT EXISTS waste (
    waste_id SERIAL PRIMARY KEY,
    user_id INTEGER NOT NULL REFERENCES users(user_id) ON DELETE CASCADE,
    type_id INTEGER NOT NULL REFERENCES waste_types(type_id) ON DELETE RESTRICT,
    amount DECIMAL(10,2) NOT NULL CHECK (amount > 0 AND amount <= 1000),
    description TEXT,
    record_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    status VARCHAR(20) DEFAULT 'waiting' CHECK (status IN ('waiting', 'reserved', 'collected', 'cancelled'))
);

-- Reservations (Rezervasyonlar)
CREATE TABLE IF NOT EXISTS reservations (
    reservation_id SERIAL PRIMARY KEY,
    waste_id INTEGER NOT NULL REFERENCES waste(waste_id) ON DELETE CASCADE,
    collector_id INTEGER NOT NULL REFERENCES users(user_id) ON DELETE CASCADE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    pickup_datetime TIMESTAMP NOT NULL,
    status VARCHAR(20) DEFAULT 'waiting' CHECK (status IN ('waiting', 'reserved', 'collected', 'cancelled'))
);

-- Environmental Scores (Çevresel Puanlar)
CREATE TABLE IF NOT EXISTS environmental_scores (
    score_id SERIAL PRIMARY KEY,
    user_id INTEGER NOT NULL REFERENCES users(user_id) ON DELETE CASCADE,
    month INTEGER NOT NULL CHECK (month >= 1 AND month <= 12),
    year INTEGER NOT NULL CHECK (year >= 2020 AND year <= 2100),
    total_score INTEGER DEFAULT 0,
    UNIQUE(user_id, month, year)
);

-- Trigger Log Tablosu (Trigger bildirimlerini saklamak için)
CREATE TABLE IF NOT EXISTS trigger_logs (
    log_id SERIAL PRIMARY KEY,
    trigger_name VARCHAR(100) NOT NULL,
    table_name VARCHAR(100) NOT NULL,
    action VARCHAR(20) NOT NULL,
    old_data JSONB,
    new_data JSONB,
    message TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- ============================================
-- FIX CASCADE CONSTRAINT (Ensure reservations delete when waste is deleted)
-- ============================================
ALTER TABLE IF EXISTS reservations DROP CONSTRAINT IF EXISTS reservations_waste_id_fkey;
ALTER TABLE IF EXISTS reservations ADD CONSTRAINT reservations_waste_id_fkey 
  FOREIGN KEY (waste_id) REFERENCES waste(waste_id) ON DELETE CASCADE;

-- ============================================
-- 2. SEQUENCE (Ödev Gereksinimi)
-- ============================================
-- Rezervasyon numarası için özel sequence
CREATE SEQUENCE IF NOT EXISTS reservation_number_seq
    START WITH 1000
    INCREMENT BY 1
    NO MAXVALUE
    CACHE 1;

-- ============================================
-- 3. INDEX'LER (Ödev Gereksinimi)
-- Arama performansı için index oluşturuldu
-- ============================================

-- Users tablosu için indexler
CREATE INDEX IF NOT EXISTS idx_users_email ON users(email);
CREATE INDEX IF NOT EXISTS idx_users_phone ON users(phone);
CREATE INDEX IF NOT EXISTS idx_users_city ON users(city);
CREATE INDEX IF NOT EXISTS idx_users_role ON users(role);

-- Waste tablosu için indexler (arama için önemli)
CREATE INDEX IF NOT EXISTS idx_waste_status ON waste(status);
CREATE INDEX IF NOT EXISTS idx_waste_type ON waste(type_id);
CREATE INDEX IF NOT EXISTS idx_waste_user ON waste(user_id);
CREATE INDEX IF NOT EXISTS idx_waste_date ON waste(record_date DESC);

-- Reservations tablosu için indexler
CREATE INDEX IF NOT EXISTS idx_reservations_status ON reservations(status);
CREATE INDEX IF NOT EXISTS idx_reservations_collector ON reservations(collector_id);
CREATE INDEX IF NOT EXISTS idx_reservations_pickup ON reservations(pickup_datetime);

-- Environmental Scores için index
CREATE INDEX IF NOT EXISTS idx_scores_user_period ON environmental_scores(user_id, year, month);

-- ============================================
-- 4. VIEW (Ödev Gereksinimi)
-- Arayüzden çağrılan sorgulardan biri VIEW olmalı
-- ============================================

-- VIEW 1: Aktif atıkların detaylı listesi
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
ORDER BY w.record_date DESC;

-- VIEW 2: Kullanıcı istatistikleri özeti (FIXED: Subquery ile doğru hesaplama)
CREATE OR REPLACE VIEW v_user_statistics AS
SELECT 
    u.user_id,
    u.first_name || ' ' || u.last_name AS full_name,
    u.email,
    u.city,
    COALESCE((SELECT COUNT(*) FROM waste w WHERE w.user_id = u.user_id), 0) AS total_waste_posted,
    COALESCE((SELECT COUNT(*) FROM reservations r WHERE r.collector_id = u.user_id), 0) AS total_reservations_made,
    COALESCE((SELECT SUM(es.total_score) FROM environmental_scores es WHERE es.user_id = u.user_id), 0) AS total_environmental_score
FROM users u;

-- VIEW 3: Aylık geri dönüşüm raporu
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
ORDER BY year DESC, month DESC, total_amount DESC;

-- ============================================
-- 5. SQL FONKSİYONLARI (Ödev Gereksinimi - 3 adet)
-- En az birinde RECORD ve CURSOR kullanılmalı
-- ============================================

-- FONKSİYON 1: Kullanıcının toplam çevresel puanını hesapla
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
$$ LANGUAGE plpgsql;

-- FONKSİYON 2: Belirli bir şehirdeki aktif atıkları getir (RECORD kullanımı)
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
$$ LANGUAGE plpgsql;

-- FONKSİYON 3: Kullanıcının aylık raporunu getir (CURSOR ve RECORD kullanımı)
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
    -- Cursor ile atık verilerini oku
    OPEN waste_cursor;
    LOOP
        FETCH waste_cursor INTO waste_record;
        EXIT WHEN NOT FOUND;
        
        -- Her atık türü için bir satır döndür
        report_type := 'WASTE_DETAIL';
        type_name := waste_record.type_name;
        item_count := waste_record.cnt;
        total_amount := waste_record.total_amt;
        total_score := waste_record.score;
        details := 'Atık türü detayı: ' || waste_record.type_name;
        RETURN NEXT;
        
        -- Toplamları güncelle
        total_items := total_items + waste_record.cnt;
        grand_total_amount := grand_total_amount + waste_record.total_amt;
        grand_total_score := grand_total_score + waste_record.score;
    END LOOP;
    CLOSE waste_cursor;
    
    -- Özet satırı döndür
    report_type := 'SUMMARY';
    type_name := 'TOPLAM';
    item_count := total_items;
    total_amount := grand_total_amount;
    total_score := grand_total_score;
    details := p_year || '-' || p_month || ' dönemi özeti';
    RETURN NEXT;
END;
$$ LANGUAGE plpgsql;

-- ============================================
-- 6. TRIGGER'LAR (Ödev Gereksinimi - 2 adet)
-- Arayüzden tetiklenmeli ve bildirim mesajı dönmeli
-- ============================================

-- TRIGGER 1: Yeni atık eklendiğinde çevresel puanı güncelle
CREATE OR REPLACE FUNCTION trg_fn_update_environmental_score()
RETURNS TRIGGER AS $$
DECLARE
    v_score INTEGER;
    v_current_month INTEGER;
    v_current_year INTEGER;
    v_message TEXT;
BEGIN
    -- Sadece status 'collected' olduğunda puan hesapla
    IF NEW.status = 'collected' AND (TG_OP = 'INSERT' OR OLD.status != 'collected') THEN
        -- Atık türünün puanını al
        SELECT recycle_score INTO v_score
        FROM waste_types
        WHERE type_id = NEW.type_id;
        
        v_current_month := EXTRACT(MONTH FROM CURRENT_DATE);
        v_current_year := EXTRACT(YEAR FROM CURRENT_DATE);
        
        -- Environmental score güncelle veya ekle
        INSERT INTO environmental_scores (user_id, month, year, total_score)
        VALUES (NEW.user_id, v_current_month, v_current_year, (NEW.amount * v_score)::INTEGER)
        ON CONFLICT (user_id, month, year)
        DO UPDATE SET total_score = environmental_scores.total_score + (NEW.amount * v_score)::INTEGER;
        
        v_message := 'Tebrikler! ' || (NEW.amount * v_score)::INTEGER || ' çevresel puan kazandınız!';
        
        -- Trigger log'a kaydet
        INSERT INTO trigger_logs (trigger_name, table_name, action, new_data, message)
        VALUES ('trg_update_environmental_score', 'waste', TG_OP, row_to_json(NEW), v_message);
    END IF;
    
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

DROP TRIGGER IF EXISTS trg_update_environmental_score ON waste;
CREATE TRIGGER trg_update_environmental_score
    AFTER INSERT OR UPDATE ON waste
    FOR EACH ROW
    EXECUTE FUNCTION trg_fn_update_environmental_score();

-- TRIGGER 2: Rezervasyon yapıldığında atık durumunu güncelle
CREATE OR REPLACE FUNCTION trg_fn_reservation_status_change()
RETURNS TRIGGER AS $$
DECLARE
    v_message TEXT;
    v_waste_owner_id INTEGER;
    v_collector_name TEXT;
BEGIN
    IF TG_OP = 'INSERT' THEN
        -- Yeni rezervasyon eklendiğinde atık durumunu 'reserved' yap
        UPDATE waste SET status = 'reserved' WHERE waste_id = NEW.waste_id;
        
        -- Bilgileri al
        SELECT user_id INTO v_waste_owner_id FROM waste WHERE waste_id = NEW.waste_id;
        SELECT first_name || ' ' || last_name INTO v_collector_name FROM users WHERE user_id = NEW.collector_id;
        
        v_message := 'Atığınız için yeni rezervasyon! Toplayıcı: ' || v_collector_name || 
                     ', Tarih: ' || TO_CHAR(NEW.pickup_datetime, 'DD.MM.YYYY HH24:MI');
        
        -- Trigger log'a kaydet
        INSERT INTO trigger_logs (trigger_name, table_name, action, new_data, message)
        VALUES ('trg_reservation_status_change', 'reservations', 'INSERT', row_to_json(NEW), v_message);
        
    ELSIF TG_OP = 'UPDATE' THEN
        -- Rezervasyon durumu değiştiğinde atık durumunu da güncelle
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
$$ LANGUAGE plpgsql;

DROP TRIGGER IF EXISTS trg_reservation_status_change ON reservations;
CREATE TRIGGER trg_reservation_status_change
    AFTER INSERT OR UPDATE ON reservations
    FOR EACH ROW
    EXECUTE FUNCTION trg_fn_reservation_status_change();

-- ============================================
-- 7. ÖRNEK SORGULAR (API'lerde Kullanılacak)
-- ============================================

-- UNION Sorgusu: Hem atık paylaşan hem de toplayan kullanıcılar
-- SELECT user_id, first_name, last_name, 'Paylaşımcı' as role_type
-- FROM users u
-- WHERE EXISTS (SELECT 1 FROM waste w WHERE w.user_id = u.user_id)
-- UNION
-- SELECT user_id, first_name, last_name, 'Toplayıcı' as role_type
-- FROM users u
-- WHERE EXISTS (SELECT 1 FROM reservations r WHERE r.collector_id = u.user_id);

-- Aggregate + HAVING Sorgusu: En az 2 atık paylaşmış kullanıcılar
-- SELECT 
--     u.user_id,
--     u.first_name || ' ' || u.last_name AS full_name,
--     COUNT(w.waste_id) AS waste_count,
--     SUM(w.amount) AS total_amount
-- FROM users u
-- JOIN waste w ON u.user_id = w.user_id
-- GROUP BY u.user_id, u.first_name, u.last_name
-- HAVING COUNT(w.waste_id) >= 2
-- ORDER BY waste_count DESC;

-- EXCEPT Sorgusu: Hiç rezervasyon yapmamış kullanıcılar
-- SELECT user_id, first_name, last_name FROM users
-- EXCEPT
-- SELECT DISTINCT u.user_id, u.first_name, u.last_name 
-- FROM users u 
-- JOIN reservations r ON u.user_id = r.collector_id;

-- ============================================
-- 8. SEED DATA (NEON DATABASE EXPORT)
-- Generated: 2026-01-16
-- ============================================

-- Waste Types (Atık Türleri) - 10 kayıt
INSERT INTO waste_types (type_id, type_name, official_unit, recycle_score) VALUES
(1, 'Cardboard Boxes & Packaging', 'kg', 40),
(2, 'Old Books & Newspapers', 'kg', 60),
(3, 'PET Bottles', 'liter', 100),
(4, 'Hard Plastic Packaging', 'kg', 80),
(5, 'Metal Beverage Cans', 'kg', 120),
(6, 'Kitchen Metal Waste', 'kg', 150),
(7, 'Small Household Appliances', 'unit', 250),
(9, 'Cables & Chargers', 'kg', 180),
(10, 'Recyclable Textiles', 'kg', 50),
(11, 'Glass Bottles & Jars', 'liter', 30)
ON CONFLICT (type_id) DO NOTHING;

-- Users (Kullanıcılar) - 15 kayıt
INSERT INTO users (user_id, first_name, last_name, email, password, google_id, profile_picture, phone, role, city, district, neighborhood, street, address_details, is_verified, created_at, is_active) VALUES
(2, 'Ayşe Sude', 'Cami', 'asudecmi.98@gmail.com', NULL, '108562090585805929423', 'https://lh3.googleusercontent.com/a/ACg8ocKZsbhtLpL2bTtBV3ZsrBjDYDxBJK0nZh-ztbrmfSGj81jDng=s96-c', '+905552225678', 'admin', 'İstanbul', 'Kadıköy', 'Fenerbahçe', 'Bağdat Caddesi', 'No: 45/3', true, '2026-01-01T15:28:04.966Z', true),
(12, 'Bera', 'Çolak', 'bera213342@gmail.com', '$2b$12$TGuEA4vfHOz.XBvpfxxwROQfco5zZMjhAk4IglEndPqmFSA/WDipW', '103643366987285747834', 'https://lh3.googleusercontent.com/a/ACg8ocK4xdD8Y3iU-ODJbQIaS7l1sHDAPPp2xbajvqYywtfoT0ovNdN04g=s96-c', '+905550692182', 'admin', 'İstanbul', 'Beşiktaş', 'Etiler', 'Cevher', 'No:25', true, '2026-01-04T02:25:57.104Z', true),
(13, 'Ahmet', 'Yılmaz', 'ahmet@test.com', '$2b$12$axKyp9/fSu4Ing5BqjmO8urM/gbVVFMLjdUTz7JVlNLFTKcC/Ygya', NULL, NULL, '+905551111111', 'resident', 'İstanbul', 'Kadıköy', 'Moda', 'Bahariye Cad.', 'No: 15', true, '2026-01-04T10:22:15.597Z', true),
(14, 'Ayşe', 'Kaya', 'ayse@test.com', '$2b$12$yabcGr9e8eLmNgOxrgs62uxjEQrn7iyk44yDKZirSuueIE87B6x6i', NULL, NULL, '+905552222222', 'resident', 'İstanbul', 'Beşiktaş', 'Levent', 'Büyükdere Cad.', 'No: 42', true, '2026-01-04T10:22:15.657Z', true),
(15, 'Mehmet', 'Demir', 'mehmet@test.com', '$2b$12$yabcGr9e8eLmNgOxrgs62uxjEQrn7iyk44yDKZirSuueIE87B6x6i', NULL, NULL, '+905553333333', 'resident', 'Ankara', 'Çankaya', 'Kızılay', 'Atatürk Blv.', 'No: 8', true, '2026-01-04T10:22:15.710Z', true),
(16, 'Fatma', 'Şahin', 'fatma@test.com', '$2b$12$yabcGr9e8eLmNgOxrgs62uxjEQrn7iyk44yDKZirSuueIE87B6x6i', NULL, NULL, '+905554444444', 'resident', 'İzmir', 'Konak', 'Alsancak', 'Kordon', 'No: 23', true, '2026-01-04T10:22:15.832Z', true),
(17, 'Ali', 'Öztürk', 'ali@test.com', '$2b$12$yabcGr9e8eLmNgOxrgs62uxjEQrn7iyk44yDKZirSuueIE87B6x6i', NULL, NULL, '+905555555555', 'resident', 'İstanbul', 'Üsküdar', 'Çengelköy', 'Çengelköy Cad.', 'No: 7', true, '2026-01-04T10:22:15.885Z', true),
(18, 'Zeynep', 'Aydın', 'zeynep@test.com', '$2b$12$yabcGr9e8eLmNgOxrgs62uxjEQrn7iyk44yDKZirSuueIE87B6x6i', NULL, NULL, '+905556666666', 'resident', 'Bursa', 'Nilüfer', 'Görükle', 'Üniversite Cad.', 'No: 12', true, '2026-01-04T10:22:15.936Z', true),
(19, 'Mustafa', 'Çelik', 'mustafa@test.com', '$2b$12$yabcGr9e8eLmNgOxrgs62uxjEQrn7iyk44yDKZirSuueIE87B6x6i', NULL, NULL, '+905557777777', 'resident', 'Antalya', 'Muratpaşa', 'Lara', 'Lara Cad.', 'No: 55', true, '2026-01-04T10:22:15.987Z', true),
(20, 'Elif', 'Arslan', 'elif@test.com', '$2b$12$yabcGr9e8eLmNgOxrgs62uxjEQrn7iyk44yDKZirSuueIE87B6x6i', NULL, NULL, '+905558888888', 'resident', 'İstanbul', 'Bakırköy', 'Ataköy', 'Sahil Yolu', 'No: 3', true, '2026-01-04T10:22:16.037Z', true),
(37, 'Sümeyye', 'Yoldaş', 'sumeyyeyoldas3@gmail.com', '$2b$12$qd.8Ic18V2lybYvXLfK/iu6/16Ns96sHthpkOmLK.KtdH8/W8K.7i', '104150523006835820566', NULL, '+905061753769', 'admin', 'İstanbul', 'Esenler', 'Fevzi Çakmak', 'Fatih Cad.', 'No: 22', true, '2026-01-04T14:09:43.360Z', true),
(38, 'Vera', 'Doe', 'fberacolak@gmail.com', '$2b$12$tAOBvSCNmvWFdo4kepIkDeiFgLS339vYjVuFUkXU8f09btAuFi5RC', '104936904192032793040', 'https://lh3.googleusercontent.com/a/ACg8ocL1BGOQ0HeUlI6cHOXX8vy9kyyPKpYnK2p2CCZ_V4Xp8DpHrgM=s96-c', '+90544666789', 'resident', 'İzmir', 'Buca', 'Mustafa Kemal', 'İsmail Sivri', 'No:257', true, '2026-01-05T10:28:04.722Z', true),
(39, 'Ayşe Sude', 'Cami', 'camiaysesude@gmail.com', NULL, '108550615258744692286', 'https://lh3.googleusercontent.com/a/ACg8ocK2m8bJTZCODhvVAcZpA1TGZxzGpinyOSb4DROjmaCOMkSEUA=s96-c', '+905551232132', 'admin', 'İstanbul', 'Esenler', 'ÇifteHavuzlar', '1. cad', 'Davutpaşa Kampüsü Elektrik Elektronik Fakültesi', true, '2026-01-11T10:17:39.369Z', true),
(41, 'Test', 'One', 'artanisnerwel@gmail.com', '$2b$12$6YFpZPsSJZWYkir4XYgjPOADbfH8IKqp940deOBdsQABOccI60Bki', NULL, NULL, '+905559871236', 'resident', 'Marmara', 'deneme', 'deneme', '1.Sok', 'deneme', true, '2026-01-11T11:08:46.434Z', true)
ON CONFLICT (user_id) DO NOTHING;

-- Waste (Atıklar) - 22 kayıt
INSERT INTO waste (waste_id, user_id, type_id, amount, description, record_date, status) VALUES
(1, 2, 1, 5.50, 'Mixed packaging', '2026-01-02T18:27:21.643Z', 'waiting'),
(6, 15, 5, 1.50, 'Eski piller ve aküler', '2026-01-04T10:22:18.289Z', 'reserved'),
(16, 15, 5, 1.50, 'Eski piller ve aküler', '2026-01-04T10:22:34.253Z', 'reserved'),
(22, 2, 1, 5.50, 'Temiz karton kutular, ürün ambalajları', '2026-01-04T10:23:18.089Z', 'waiting'),
(24, 13, 3, 2.50, 'Eski bilgisayar parçaları', '2026-01-04T10:23:18.244Z', 'waiting'),
(25, 14, 4, 10.00, 'PET şişeler ve plastik kaplar', '2026-01-04T10:23:18.299Z', 'waiting'),
(26, 15, 5, 1.50, 'Eski piller ve aküler', '2026-01-04T10:23:18.350Z', 'reserved'),
(27, 2, 1, 8.00, 'Gazete ve dergiler', '2026-01-04T10:23:18.402Z', 'waiting'),
(29, 13, 2, 4.00, 'Kırık cam eşyalar', '2026-01-04T10:23:18.572Z', 'waiting'),
(30, 14, 4, 6.50, 'Plastik oyuncaklar', '2026-01-04T10:23:18.621Z', 'waiting'),
(31, 15, 7, 2.00, 'Eski kıyafetler', '2026-01-04T10:23:18.671Z', 'waiting'),
(32, 13, 1, 3.50, 'Test karton kutu', '2026-01-04T10:44:30.152Z', 'reserved'),
(36, 37, 9, 2.00, NULL, '2026-01-04T16:56:43.784Z', 'collected'),
(37, 37, 1, 3.00, NULL, '2026-01-04T17:43:30.133Z', 'collected'),
(38, 37, 11, 4.00, NULL, '2026-01-04T17:44:04.136Z', 'reserved'),
(39, 12, 2, 4.50, 'eski ders kitapları', '2026-01-04T18:59:36.113Z', 'collected'),
(42, 38, 6, 1.00, 'eski tencereler, metal kutular', '2026-01-05T10:31:10.159Z', 'reserved'),
(43, 12, 9, 1.00, 'USB kablo, adaptör, kulaklık kablosu', '2026-01-08T04:58:26.376Z', 'waiting'),
(45, 41, 2, 3.00, '6 tane kitap', '2026-01-11T11:10:10.272Z', 'collected'),
(46, 12, 7, 2.00, 'eski ütü', '2026-01-13T06:39:53.899Z', 'waiting'),
(47, 38, 11, 2.00, 'gazoz şişeleri ve kavanozlar', '2026-01-14T13:24:26.004Z', 'waiting')
ON CONFLICT (waste_id) DO NOTHING;

-- Reservations (Rezervasyonlar) - 15 kayıt
INSERT INTO reservations (reservation_id, waste_id, collector_id, created_at, pickup_datetime, status) VALUES
(21, 1, 16, '2026-01-04T10:23:18.860Z', '2026-01-05T11:00:00.000Z', 'waiting'),
(22, 6, 17, '2026-01-04T10:23:18.909Z', '2026-01-06T07:00:00.000Z', 'waiting'),
(23, 16, 18, '2026-01-04T10:23:18.956Z', '2026-01-07T13:00:00.000Z', 'reserved'),
(24, 22, 16, '2026-01-04T10:23:19.004Z', '2026-01-08T08:00:00.000Z', 'waiting'),
(26, 24, 18, '2026-01-04T10:23:19.166Z', '2026-01-10T12:00:00.000Z', 'waiting'),
(27, 25, 16, '2026-01-04T10:23:19.218Z', '2026-01-04T10:00:00.000Z', 'collected'),
(28, 26, 17, '2026-01-04T10:23:19.265Z', '2026-01-11T14:00:00.000Z', 'reserved'),
(29, 27, 18, '2026-01-04T10:23:19.312Z', '2026-01-12T09:00:00.000Z', 'waiting'),
(45, 42, 37, '2026-01-07T05:44:23.092Z', '2026-01-07T05:45:00.000Z', 'waiting'),
(46, 37, 12, '2026-01-07T12:55:59.915Z', '2026-01-08T08:00:00.000Z', 'collected'),
(49, 39, 38, '2026-01-07T14:15:34.508Z', '2026-01-08T08:00:00.000Z', 'collected'),
(53, 36, 2, '2026-01-08T13:55:39.807Z', '2026-01-09T08:00:00.000Z', 'collected'),
(54, 45, 39, '2026-01-11T11:12:33.734Z', '2026-01-12T08:00:00.000Z', 'collected'),
(55, 32, 12, '2026-01-13T06:40:38.728Z', '2026-01-13T05:00:00.000Z', 'waiting'),
(56, 38, 38, '2026-01-14T11:09:08.060Z', '2026-01-15T06:00:00.000Z', 'waiting')
ON CONFLICT (reservation_id) DO NOTHING;

-- Environmental Scores (Çevresel Puanlar) - 14 kayıt
INSERT INTO environmental_scores (user_id, month, year, total_score) VALUES
(2, 12, 2025, 150),
(12, 12, 2025, 200),
(13, 12, 2025, 175),
(14, 12, 2025, 120),
(15, 12, 2025, 300),
(2, 1, 2026, 301),
(12, 1, 2026, 704),
(13, 1, 2026, 65),
(14, 1, 2026, 40),
(15, 1, 2026, 95),
(37, 1, 2026, 960),
(38, 1, 2026, 189),
(41, 1, 2026, 360),
(39, 1, 2026, 125)
ON CONFLICT (user_id, month, year) DO NOTHING;

-- Trigger Logs (38 kayıt)
INSERT INTO trigger_logs (log_id, trigger_name, table_name, action, message, created_at) VALUES
(1, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 06.01.2026 11:00', '2026-01-04T20:15:57.112Z'),
(2, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 06.01.2026 11:00', '2026-01-05T05:48:46.684Z'),
(3, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 06.01.2026 11:00', '2026-01-05T05:48:49.498Z'),
(4, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 06.01.2026 12:00', '2026-01-05T05:52:09.758Z'),
(5, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 06.01.2026 09:00', '2026-01-05T08:28:23.611Z'),
(6, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 06.01.2026 11:00', '2026-01-05T08:58:19.091Z'),
(7, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 06.01.2026 16:00', '2026-01-05T09:02:16.234Z'),
(8, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 06.01.2026 11:00', '2026-01-05T09:42:30.955Z'),
(9, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 06.01.2026 11:00', '2026-01-05T09:55:13.845Z'),
(10, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Vera Doe, Tarih: 06.01.2026 12:00', '2026-01-05T10:28:41.684Z'),
(11, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Vera Doe, Tarih: 06.01.2026 11:00', '2026-01-05T10:35:53.801Z'),
(12, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Sümeyye Yoldaş, Tarih: 08.01.2026 11:00', '2026-01-07T05:22:30.065Z'),
(13, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Sümeyye Yoldaş, Tarih: 07.01.2026 08:30', '2026-01-07T05:24:22.387Z'),
(14, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Sümeyye Yoldaş, Tarih: 07.01.2026 08:30', '2026-01-07T05:24:48.901Z'),
(15, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Sümeyye Yoldaş, Tarih: 07.01.2026 08:45', '2026-01-07T05:44:23.092Z'),
(16, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 08.01.2026 11:00', '2026-01-07T12:55:59.915Z'),
(17, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 08.01.2026 11:00', '2026-01-07T12:56:03.825Z'),
(18, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 08.01.2026 11:00', '2026-01-07T13:51:28.556Z'),
(19, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Vera Doe, Tarih: 08.01.2026 11:00', '2026-01-07T14:15:34.508Z'),
(20, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 09.01.2026 11:00', '2026-01-08T01:33:50.505Z'),
(21, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 09.01.2026 11:00', '2026-01-08T01:34:22.620Z'),
(22, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Ayşe Sude Cami, Tarih: 09.01.2026 14:00', '2026-01-08T13:10:53.460Z'),
(23, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Ayşe Sude Cami, Tarih: 09.01.2026 11:00', '2026-01-08T13:55:39.807Z'),
(24, 'trg_update_environmental_score', 'waste', 'UPDATE', 'Tebrikler! 360 çevresel puan kazandınız!', '2026-01-08T14:25:09.521Z'),
(25, 'trg_reservation_status_change', 'reservations', 'UPDATE', 'Atık başarıyla toplandı! Reservation ID: 53', '2026-01-08T14:25:09.521Z'),
(26, 'completeCollection', 'reservations', 'UPDATE', 'Koleksiyon tamamlandı! Owner: +360 PTS, Collector: +251 PTS', '2026-01-08T14:25:09.521Z'),
(27, 'trg_update_environmental_score', 'waste', 'UPDATE', 'Tebrikler! 120 çevresel puan kazandınız!', '2026-01-09T11:33:21.203Z'),
(28, 'trg_reservation_status_change', 'reservations', 'UPDATE', 'Atık başarıyla toplandı! Reservation ID: 46', '2026-01-09T11:33:21.203Z'),
(29, 'completeCollection', 'reservations', 'UPDATE', 'Koleksiyon tamamlandı! Owner: +120 PTS, Collector: +84 PTS', '2026-01-09T11:33:21.203Z'),
(30, 'trg_update_environmental_score', 'waste', 'UPDATE', 'Tebrikler! 270 çevresel puan kazandınız!', '2026-01-09T12:45:54.269Z'),
(31, 'trg_reservation_status_change', 'reservations', 'UPDATE', 'Atık başarıyla toplandı! Reservation ID: 49', '2026-01-09T12:45:54.269Z'),
(32, 'completeCollection', 'reservations', 'UPDATE', 'Koleksiyon tamamlandı! Owner: +270 PTS, Collector: +189 PTS', '2026-01-09T12:45:54.269Z'),
(33, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Ayşe Sude Cami, Tarih: 12.01.2026 11:00', '2026-01-11T11:12:33.734Z'),
(34, 'trg_update_environmental_score', 'waste', 'UPDATE', 'Tebrikler! 180 çevresel puan kazandınız!', '2026-01-11T11:15:52.050Z'),
(35, 'trg_reservation_status_change', 'reservations', 'UPDATE', 'Atık başarıyla toplandı! Reservation ID: 54', '2026-01-11T11:15:52.050Z'),
(36, 'completeCollection', 'reservations', 'UPDATE', 'Koleksiyon tamamlandı! Owner: +180 PTS, Collector: +125 PTS', '2026-01-11T11:15:52.050Z'),
(37, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Bera Çolak, Tarih: 13.01.2026 11:00', '2026-01-13T06:40:38.728Z'),
(38, 'trg_reservation_status_change', 'reservations', 'INSERT', 'Atığınız için yeni rezervasyon! Toplayıcı: Vera Doe, Tarih: 15.01.2026 11:00', '2026-01-14T11:09:08.060Z')
ON CONFLICT (log_id) DO NOTHING;

-- Reset sequences to continue from current max values
SELECT setval('users_user_id_seq', 41);
SELECT setval('waste_waste_id_seq', 47);
SELECT setval('reservations_reservation_id_seq', 56);
SELECT setval('environmental_scores_score_id_seq', 42);
SELECT setval('trigger_logs_log_id_seq', 38);
SELECT setval('waste_types_type_id_seq', 11);

-- ============================================
-- 9. FIX WASTE STATUSES (Trigger overwrites during INSERT)
-- ============================================
-- Reservations INSERT sırasında trigger waste durumunu 'reserved' yapıyor
-- Bu yüzden collected olması gereken atıkları düzeltiyoruz
UPDATE waste SET status = 'collected' WHERE waste_id IN (36, 37, 39, 45);
UPDATE waste SET status = 'waiting' WHERE waste_id IN (1, 22, 24, 25, 27, 29, 30, 31, 43, 46, 47);
UPDATE waste SET status = 'reserved' WHERE waste_id IN (6, 16, 26, 32, 38, 42);

-- ============================================
-- KISITLAMALAR ÖZETİ
-- ============================================
-- 1. Silme Kısıtı:
--    - waste.type_id -> ON DELETE RESTRICT (Atık türü silinemez)
--    - waste.user_id -> ON DELETE CASCADE (Kullanıcı silinince atıklar da silinir)
--
-- 2. Sayı Kısıtları (CHECK):
--    - waste.amount: 0 < amount <= 1000
--    - waste_types.recycle_score: 0 <= score <= 300
--    - environmental_scores.month: 1-12 arası
--    - environmental_scores.year: 2020-2100 arası
--    - waste.status ve reservations.status: Belirli değerler
--    - users.role: 'admin' veya 'resident'
