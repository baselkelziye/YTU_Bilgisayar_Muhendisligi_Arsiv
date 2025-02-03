-- PostgreSQL'in built-in fonksiyonlarını kullanarak index oluştururken performans ölçümü
DO $$
DECLARE
    start_time TIMESTAMP;
    end_time TIMESTAMP;
BEGIN
    -- Önceki indeksi sil (eğer varsa)
    DROP INDEX IF EXISTS idx_b;
    
    -- Başlangıç zamanını kaydet
    start_time := clock_timestamp();
    
    -- İndeksi oluştur
    CREATE INDEX idx_b ON T(b);
    
    -- Bitiş zamanını kaydet
    end_time := clock_timestamp();
    
    -- Geçen süreyi göster
    RAISE NOTICE 'İndeks Oluşturma Süresi: %', end_time - start_time;
END $$;

-- İndeks detayları
SELECT 
    relname AS index_name, 
    relpages AS total_pages,
    pg_size_pretty(pg_relation_size(oid)) AS index_size
FROM pg_class
WHERE relname = 'idx_b';

--B+-Tree ayrıntısı
CREATE EXTENSION IF NOT EXISTS pgstattuple;
SELECT
    version AS index_version,
    tree_level AS tree_height,
    internal_pages,
    leaf_pages,
    empty_pages,
    avg_leaf_density
FROM pgstatindex('idx_b_low_fill');


-- İndeks detayları ayrıntılı
SELECT 
    schemaname,
    relname AS table_name,
    indexrelname AS index_name,
    idx_scan,    -- indeks kaç kez taranmış
    idx_tup_read,  -- bu taramalar sonucunda kaç kayıt okunmuş
    idx_tup_fetch,
    idx_tup_read * 1.0 / NULLIF(idx_scan, 0) AS avg_tuples_per_scan
FROM pg_stat_all_indexes
WHERE relname = 't' AND indexrelname = 'idx_b';

-- Tekrar eden değer sayısı (tablodan sql sorgusu ile)
WITH duplicate_values AS (
    SELECT b, COUNT(*) AS repeat_count
    FROM T
    GROUP BY b
    HAVING COUNT(*) > 1
)
SELECT 
    COUNT(*) AS total_duplicate_value_types,
    SUM(repeat_count) AS total_duplicate_records,
    MAX(repeat_count) AS max_duplicates_for_single_value
FROM duplicate_values;

-- Sistem katalog sorgusu ile tekrar değerleri bul
SELECT n_tup_ins - n_tup_del - n_live_tup AS approx_duplicates
FROM pg_stat_all_tables
WHERE relname = 't';

-- Sistem kataloğunu güncelleme
ANALYZE t;
