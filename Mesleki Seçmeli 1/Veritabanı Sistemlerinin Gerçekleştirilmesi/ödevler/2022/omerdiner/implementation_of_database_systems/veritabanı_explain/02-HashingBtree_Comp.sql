--Notes from https://hakibenita.com/postgresql-hash-index

-- COMPARISON OF HASH vs B-tree INDEX SIZES.

--PostgreSQL's hash function maps any database value to a 32-bit integer [-2147483648 to 2147483647]
-- the hash code (about 4 billion possible hash codes).

show search_path;
select current_schema();
set search_path to testarea;

SELECT
    hashtext('text'),
    hashchar('c'),
    hash_array(array[1,2,3]),
    jsonb_hash('{"me": "haki"}'::jsonb),
    timestamp_hash(now()::timestamp);
	
-- It then uses mod(n_buckets) to determine which bucket the tuple should be put in. 
-- This can cause multiple values to end up in the same bucket. 
-- This is why even after the bucket is identified, the database still needs to sift through the hash codes 
-- in the bucket and recheck the condition to filter only the matching tuples.

-- Luckily, PostgreSQL does all the heavy lifting for you, so you don't have to decide what hash function to use, 
-- or how many buckets there are.

-- If you want to learn more about the internals of Hash indexes in PostgreSQL, 
-- https://github.com/postgres/postgres/blob/master/src/backend/access/hash/README

-- Hash indexes were discouraged prior to PostgreSQL 10 due to a recovery problem. 
-- NOW they are totally safe and available.

--A URL shortener service, such as "bit.ly" or the late "goo.gl"

CREATE TABLE shorturl (
    id serial primary key,
    key text not null,  -- this is longer. Definitely unique
    url text not null   -- shorter. Mostly unique. PGSQL13 enables deduplication to make the idx smaller when the data is not unique.
);

CREATE INDEX shorturl_key_hash_index ON shorturl USING hash(key);  -- NOT UNIQUE. Hash indexes currently cannot be used to enforce unique constraints
CREATE UNIQUE INDEX shorturl_key_btree_index ON shorturl USING btree(key);
CREATE INDEX shorturl_url_hash_index ON shorturl USING hash(url);
CREATE INDEX shorturl_url_btree_index ON shorturl USING btree(url);
-- create index allocate an initial EMPTY space ! 
SELECT pg_size_pretty (pg_relation_size('shorturl_key_hash_index')) as hashkey,
	   pg_size_pretty (pg_relation_size('shorturl_key_btree_index')) as btreekey,
	   pg_size_pretty (pg_relation_size('shorturl_url_hash_index')) as hashurl,
	   pg_size_pretty (pg_relation_size('shorturl_url_btree_index')) as btreeurl;


-- RESETTING:
DROP INDEX shorturl_key_hash_index;
DROP INDEX shorturl_key_btree_index;
DROP INDEX shorturl_url_hash_index;
DROP INDEX shorturl_url_btree_index;

TRUNCATE shorturl;  --FASTER THAN DELETE

ALTER SEQUENCE shorturl_id_seq RESTART;
UPDATE shorturl SET id = DEFAULT;

CREATE EXTENSION "uuid-ossp";  --used for generating universally unique identifiers (UUIDs) 

-- A workload of an OLTP-like system, where single rows are constantly being added to the table. 
DO $$
BEGIN
    FOR i IN 0..1000 loop  -- try 1000000 takes long
        INSERT INTO shorturl (key, url) VALUES (
        uuid_generate_v4(),
        'https://www.supercool-url.com/' || round(random() * 10 ^ 6)::text
    	);
		if mod(i, 100) = 0 THEN  --10000
			RAISE NOTICE 'rows:%  Hash key%  B-Tree key:%  Hash url:%  B-Tree url:%',
				to_char(i, '9999999999'),
				to_char(pg_relation_size('shorturl_key_hash_index'), '99999999999'),
				to_char(pg_relation_size('shorturl_key_btree_index'), '99999999999'),
				to_char(pg_relation_size('shorturl_url_hash_index'), '99999999999'),
				to_char(pg_relation_size('shorturl_url_btree_index'), '99999999999');
		END IF;
    END LOOP;
END;
$$;
-- rows: 1000  Hash key       57344  B-Tree key:       90112  Hash url:       57344  B-Tree url:       90112


-- A workload of an OLAP-like system, where all rows are bulkly loaded into the table.
REINDEX TABLE shorturl;


--------
-- HASH IDX LIMITATIONS
DROP INDEX shorturl_key_hash_index;
DROP INDEX shorturl_key_btree_index;
DROP INDEX shorturl_url_hash_index;
DROP INDEX shorturl_url_btree_index;
EXPLAIN (COSTS OFF)SELECT * FROM shorturl WHERE key BETWEEN '1' AND '2';  -- drop keybtree, it will not use keyhash :<
EXPLAIN (COSTS OFF) SELECT * FROM shorturl ORDER BY key LIMIT 10;  -- again keyhash cannot be used.
