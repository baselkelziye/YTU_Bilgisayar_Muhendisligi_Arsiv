CREATE INDEX idx_b_low_fill ON T (b) WITH (fillfactor = 60);

REINDEX INDEX idx_b_low_fill;

-- İndeks ayrıntıları
SELECT 
    relname AS index_name, 
    relpages AS total_pages,
    pg_size_pretty(pg_relation_size(oid)) AS index_size
FROM pg_class
WHERE relname = 'idx_b_low_fill';

-- İndeks Karşılaştırma
SELECT relname AS index_name,
       relpages AS total_pages,
       reltuples AS total_tuples,
	   pg_size_pretty(pg_relation_size(oid)) AS index_size
FROM pg_class
WHERE relname IN ('idx_b', 'idx_b_low_fill');
