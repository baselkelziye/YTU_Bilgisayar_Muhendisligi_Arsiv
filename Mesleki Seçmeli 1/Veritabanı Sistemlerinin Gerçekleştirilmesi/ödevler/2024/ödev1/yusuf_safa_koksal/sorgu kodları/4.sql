-- Tabloyu oluştur
CREATE TABLE t_yogun (
    a VARCHAR(40),
    b INT,
    c BOOL
);

INSERT INTO t_yogun
SELECT 'a_value_' || g,
       CASE
           WHEN g % 2 = 0 THEN 500000 + random() * 100000  -- 500.000-600.000 aralığında yoğunluk artışı
           ELSE random() * 1500000                        -- diğer aralıklar daha seyrek
       END::INT,
       (g % 2 = 0)
FROM generate_series(1, 2000000) g;

CREATE INDEX idx_b_low_fill ON t_yogun (b);

-- İndeks Karşılaştırma
SELECT relname AS index_name,
       relpages AS total_pages,
       reltuples AS total_tuples,
	   pg_size_pretty(pg_relation_size(oid)) AS index_size
FROM pg_class
WHERE relname IN ('idx_b', 'idx_b_low_fill', 'b_idx_dense');