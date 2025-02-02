-- Tabloyu oluştur
CREATE TABLE T (
    a VARCHAR(40),
    b INT,
    c BOOL
);

-- Veri üretimi
INSERT INTO T 
SELECT 
    'Record_' || i,
    floor(random() * 1500000),
    (random() > 0.5)
FROM generate_series(1, 2000000) AS i;

-- Tablo boyutunu ve sayfa sayısını öğrenme
SELECT 
    pg_size_pretty(pg_relation_size('T')) AS table_size,
    pg_relation_size('T') / 8192 AS page_count;

-- b sütunu istatistikleri
SELECT 
    MIN(b) AS min_b, 
    MAX(b) AS max_b, 
    AVG(b) AS avg_b, 
    STDDEV(b) AS stddev_b 
FROM T;

-- Kayıt yapısını öğrenme
SELECT 
    attname, 
    atttypid::regtype, 
    attlen, 
    attstorage 
FROM pg_attribute 
WHERE attrelid = 'T'::regclass AND attnum > 0;