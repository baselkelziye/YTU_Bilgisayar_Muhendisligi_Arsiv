--  SEQUENTIAL SCAN VS. INDEX SCAN VS. BITMAP SCAN VS INDEX-ONLY SCAN(COVERING INDEX)
-- https://www.cybertec-postgresql.com/en/postgresql-indexing-index-scan-vs-bitmap-scan-vs-sequential-scan-basics/

set search_path to testarea;

-- CREATE TABLE sampletable (x numeric);
-- INSERT INTO sampletable
--          SELECT random() * 10000
--          FROM generate_series(1, 100000); -- 10 000 000 takes 5 min.

CREATE TABLE sampletable (x numeric, y text);
INSERT INTO sampletable (x,y)   --  drop 'values' here. 
         (SELECT random() * 10000, 'nothing'
         FROM generate_series(1, 100000)); -- 10 000 000 takes 5 min.
		 
CREATE INDEX idx_x ON sampletable(x);
SELECT pg_size_pretty (pg_table_size('idx_x'));  -- data table size ~420, B-tree idxsize= ~380 Why?

-- After loading so much data it can be a good idea to create optimizer statistics in case 
-- autovacuum has not caught up yet. The PostgreSQL optimizer needs this statistics to decide on 
-- whether to use an index or not:
ANALYZE;
vacuum sampletable;
-- Before ANALYZE, plans may be different
explain SELECT * FROM sampletable WHERE x < 42353;  --SEQ. SCAN
explain SELECT * FROM sampletable WHERE x = 42353;  --INDEX SCAN
explain SELECT * FROM sampletable WHERE x > 9000;   -- BITMAP IDX/HEAP SCAN.  Test <select x ...>
explain SELECT y FROM sampletable WHERE x > 9000;   -- BITMAP IDX/HEAP SCAN.  Test <select x ...>
explain SELECT y FROM sampletable WHERE x > 7000 order by x;
-- a bitmap scan is that a single block (that is needed to read) is only used once during a scan. 
-- useful when more than one index is needed to scan a single table.

drop index idx_x;
CREATE INDEX idx_x ON sampletable(x) include(y);
explain SELECT y FROM sampletable WHERE x > 9000;  -- INDEX-ONLY SCAN !! (COVERING INDEX)


truncate table sampletable;
drop table sampletable;