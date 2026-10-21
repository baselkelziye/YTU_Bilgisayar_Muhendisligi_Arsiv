-- Taken from https://www.depesz.com/2021/10/22/why-is-it-hard-to-automatically-suggest-what-index-to-create/

-- Have a look to https://pganalyze.com/
set search_path to testarea;

create table z (
    id serial primary key,
    a int4,
    b int4,
    c timestamptz,
    d text
);

SELECT
    *
FROM
    z
WHERE
    a = 12
    AND b > 34
    AND c < '2021-10-01'
    AND d = 'done';

-- Generate sample data.

-- pganalyze Recommendation (3.6× faster) is USING btree (b, c, a, d).

-- PROBLEM: Columns that are compared with inequality operator shouldn't be in the middle of index. So columns b and c should be either on their own (with no other columns in index), or at the end. WHY??

select
    count(*) as total_rows,
    count(*) filter (where a = 12) as matching_a,
    count(*) filter (where b > 34) as matching_b,
    count(*) filter (where c < '2021-10-01') as matching_c,
    count(*) filter (where d = 'done') as matching_d
from z;
-- total_rows | matching_a | matching_b | matching_c | matching_d 
------------+------------+------------+------------+------------
--     100000 |       6498 |        784 |      95152 |       4928
--(1 row)


-- Ignore c. The most effective selection is on b, but it is range. Take it out..

select
    count(*) filter (where a = 12) as matching_a,
    count(*) filter (where d = 'done') as matching_d,
    count(*) filter (where a = 12 and d = 'done' ) as matching_ad
from z
where b > 34;
-- matching_a | matching_d | matching_ad 
------------+------------+-------------
--         59 |         31 |           1
--(1 row)

-- adb veya dab ikisi de iyi.  Ancak d= done çok yaygın ise, index on ab when d=done çok daha ufak olacak ve daha hızlı..
--But, if you usually search for d = ‘done' then index on (a,b) where d = ‘done'. The difference is that index with where will be simply smaller.
--For example, on my test table, index on (a, d, b) is 808kB, while index on (a,b) where d = ‘done' is only 72kB. The smaller the index, the faster it is.

create index whatever on z (a, b) where d = 'done'   --> Seems best.


--What are general rules when deciding on index?
---If selectivity of condition is low (almost all rows match) – there is no point in putting the column in index
---If you have condition that you “always" use (or, at least very often) – you can put it in WHERE part of index definition
---Don't add too many columns to index – it will make it larger, and less efficient. If you can get 2 columns to match 1000 rows out of million, and adding 3rd will reduce the match to 900 – don't add the 3rd – it will be, most likely, better in the long term to do index scan on these two columns only, and filter the rest normally.
---Remember that generally speaking you can have only one inequality condition in query being efficiently handled by index scan
---Remember that any columns in index after column used for inequality comparison, will be most likely not compared against index, but rather will be filtered out

