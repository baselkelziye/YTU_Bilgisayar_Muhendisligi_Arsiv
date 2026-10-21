-- UNDERSTANDING INDEX BASICS:  
--Sample data are taken from  "https://www.depesz.com/"
-- Movie Rental DB: taken from https://www.postgresqltutorial.com/

show search_path;
set search_path to testarea, public;
select current_schema();

set search_path to testarea;  -- This schema is our test area.

-- PostgreSQL provides the index methods B-tree, R-tree, hash, and GiST. 
-- The B-tree index method is an implementation of Lehman-Yao high-concurrency B-trees. 
-- The R-tree index method implements standard R-trees using "Guttman's quadratic split" algorithm.
-- The hash index method is an implementation of Litwin's "linear hashing". 
-- Users can also define their own index methods, but that is "fairly complicated".

-- List all indexes in a schema in our database.
SELECT
    tablename,
    indexname,
    indexdef
FROM
    pg_indexes
WHERE
    schemaname = 'testarea'
ORDER BY
    tablename,
    indexname;

-- 1-) EXPLAIN gives "only" the plan.  EXPLAIN (ANALYZE) gives "plan" + "real execution"
-- 2-) Graphical Format is possible (with Shift F7)
-- 3-) https://explain.depesz.com/   -- explains the "unexplainable"
-- 4-) https://explain.dalibo.com/

-- How to give some basic hints to planner about using indexes.
show enable_indexscan;

set enable_indexscan=false;  -- false or off
SET enable_indexonlyscan = off;
SET enable_bitmapscan = off;

set enable_indexscan=on;  -- true or on
SET enable_indexonlyscan = on;
SET enable_bitmapscan = on;

-- To enforce index-usage for small or medium-range queries 
-- ref: PostGisIntro.pdf (workshop)
set random_page_cost to 2.0; -- default is 4. Recommended value: 2.0 for spinning media, 1.0 for SSD.
-- the value has meaning relative to seq_page_cost. 
show seq_page_cost;

-- Built a "Test Table" in testarea:
CREATE TABLE test (id serial PRIMARY KEY, i int4);
INSERT INTO test (i) SELECT random() * 1000000000 FROM generate_series(1,100000);  ---- 10 000 000 takes 5 min.
drop table test;
-- After loading so much data it can be a good idea to create optimizer statistics in case 
-- autovacuum has not caught up yet. The PostgreSQL optimizer needs this statistics to decide on 
-- whether to use an index or not:
vacuum analyze test;
select * from test limit 20;
-- Check indexes on "test". We only have "test_pkey" on primary key.
SELECT *
FROM pg_catalog.pg_indexes
WHERE schemaname='testarea'
AND tablename='test';

-- SEQ SCAN: scan ALL table
EXPLAIN analyze SELECT id FROM test;

-- SEQ SCAN: scan "part" of table
EXPLAIN analyze SELECT id FROM test LIMIT 10;

----------------------------------------
-- INDEX SCAN : 
-- opens the index
-- in the index if finds where (in table data) there might be rows that match given condition
-- opens table
-- fetches row(s) pointed to by index via "RANDOM ACCESS"
-- if the rows can be returned – i.e. they are visible to current session – they are returned
EXPLAIN analyze SELECT id FROM test WHERE i=10001;
CREATE INDEX IF NOT EXISTS idx_i1 
ON test USING btree (i); 
DROP INDEX idx_i1;

--------------------------------------------------------
--(BITMAP INDEX SCAN  && BITMAP HEAP SCAN) is always together.
-- BITMAP INDEX: built a bitmap where there would be one bit for every page in your table. 
-- BITMAP INDEX: Set 1 for pages that holds requested record.
-- BITMAP HEAP: Access pages marked as 1 SQUENTIALLY. Becuse Sequential scan is faster !!
-- a bitmap scan enables a data block (that is needed to read) is only accessed only "once" during a scan. 
-- Also, useful when more than one index is needed to scan a single table.
EXPLAIN analyze SELECT id FROM test WHERE i<10001;  -- still generates Index Scan !
EXPLAIN analyze SELECT id FROM test WHERE i<1000001;   -- Now generates Bitmap Idx/Heap scan. (Decreased selectivity, increase "s")
-- another example for Bitmap Idx/Heap: combining two operations, two indexes, together.
EXPLAIN analyze SELECT * FROM test WHERE i < 5000000 OR i > 950000000;

EXPLAIN analyze SELECT id FROM test WHERE i > 50000 order by i;  --High "s". Use Index Scan. Access to heap "sorted by i" by many RANDOM ACCESS ! 
EXPLAIN analyze SELECT id FROM test WHERE i > 950000000 order by i;  -- Low "s". Use BitmapIdx/Heap. Access to heap "not sorted by i" then finally sort.
EXPLAIN analyze SELECT id FROM test WHERE i > 999999999 order by i;  -- Low "s". Again Index Scan.

-----------------------------------------
-- INDEX ONLY SCAN:   return the data straight from index !!
--select only data (columns) that are in the index. 
-- doesn't need to check anything in the table files. 
EXPLAIN analyze SELECT id FROM test ORDER BY id ASC LIMIT 10000;
EXPLAIN analyze SELECT id FROM test ORDER BY id;
EXPLAIN analyze SELECT i FROM test ORDER BY id;  -- Switch to INDEX SCAN. Use test_pkey idx, not idx_i1
EXPLAIN analyze SELECT i FROM test ORDER BY id ASC LIMIT 10;  -- Planner may generate Bitmap Idx/HEap but did not :<
EXPLAIN analyze SELECT id FROM test;  -- Do not use idx anymore :< Still possible "Idx ONLY"
-- Important:  Index has to contain information that given rows are in pages, that didn't have any changes “recently". 
-- This means that in order to utilize Index Only Scans, you have to have your table well vacuumed.

-----------------------------------------
-- COVERING INDEX :   
DROP INDEX idx_i1;
CREATE INDEX idx_i2 ON test using btree(i) include(id);
EXPLAIN analyze SELECT id FROM test WHERE i > 900000000;  -- INDEX ONLY SCAN !

DROP INDEX idx_i2;
truncate table test;
drop table test;
----------------------------------------------
----------------------------------------------
----------------------------------------------
-- TEST on DVDRENTAL 
-- our largest table: RENTAL
-- List all indexes on a table. "PK and UNIQUE" constraints cause to build index "automatically".
-- Other indexes (s.a on foreign keys) may exist as well, because they are explicitly built in load scripts for some reasons.

set search_path to public;

SELECT *
FROM pg_catalog.pg_indexes
WHERE schemaname='public'
AND tablename='rental';

-- cust_id dağılımına bir göz atalım..
select * from rental limit 100;
select customer_id, count(*) from rental group by customer_id order by 2;  
-- min 12 (cust_id=318), max 46 (cust_id=148).  Not "uniform".

explain  analyze select * from rental where customer_id= 148;
CREATE INDEX IF NOT EXISTS idx_cust_id 
ON rental USING btree (customer_id); 
DROP INDEX idx_cust_id;

-- USe of primary idx, default idx.
explain analyze select * from rental where rental_id= 101;

-- COMPOSITE INDEX USAGE:
explain analyze select rental_id from rental where rental_date ='2005-05-24 23:04:41' and inventory_id=2452 and customer_id=333;
explain analyze select rental_id from rental where inventory_id=2452 and customer_id=333; -- Use 2 singular idx!!. Did not used idx_rentaldate_invontary_id_customer_id
-- Drop idx_cust_id and try again.

------------------------------------------------
-- TEST on a small table. ADDRESS
EXPLAIN SELECT *  
FROM address
LIMIT 10;

--SEARCH ON ADRESS TABLE:
EXPLAIN SELECT *
FROM address
WHERE phone = '223664661973'; -- returns 1 tuple. 

CREATE INDEX IF NOT EXISTS idx_address_phone 
ON address(phone); -- USING btree (phone);  --btree, hash, gist, spgist, gin, and brin.  Default is btree.
DROP INDEX IF EXISTS idx_address_phone;

--SEARCH ON FILM TABLE, a larger table
SELECT LENGTH FROM FILM LIMIT 10;
SELECT COUNT(*) FROM FILM WHERE LENGTH IS NOT NULL;

CREATE INDEX IF NOT EXISTS idx_film_length 
ON film USING btree (length);   -- Or ... ON film(length); is enough. 
DROP INDEX IF EXISTS idx_film_length;

EXPLAIN SELECT *
FROM film
WHERE film_id=101;  -- film_id is PK. returns 1 tuple.

EXPLAIN SELECT film.*
FROM film
WHERE LENGTH=120;   -- returns 9 tuple.   Not so good :( due to high selectivity.

------------------------------------------
-- HASH IDX: ( Hash indexes were discouraged prior to "PostgreSQL 10" )
CREATE INDEX IF NOT EXISTS idx_film_length 
ON film USING hash (length);
DROP INDEX IF EXISTS idx_film_length;

EXPLAIN SELECT film.*
FROM film
WHERE LENGTH=120; -- the same as the b-tree. Because small file.

SELECT pg_size_pretty (pg_indexes_size('film')); --Total index size : 248 KB
SELECT pg_size_pretty (pg_table_size('idx_film_length')); -- hash idx size: 48 B   >32, Larger than B-tree ?  
-- It is not accurate to make a comparison on a small table like 200KB. 
-- Check https://hakibenita.com/postgresql-hash-index

SELECT
    pg_size_pretty (
        pg_relation_size ('film')
    ); --432B

-- SHOW the impact of selectivity
CREATE INDEX IF NOT EXISTS idx_film_length 
ON film USING btree (length);  
DROP INDEX IF EXISTS idx_film_length;

EXPLAIN SELECT film.*
FROM film
WHERE LENGTH>120;  -- First check >120 see it does not use idx, then >500 see that index usage and return 1 tuple 


------------ END OF INDEXING Part #1
