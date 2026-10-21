-- PGSQL DOC: 9.25. Set Returning Functions (SRF):
-- Examples below are collected from different sites
--------------------------------------

-- GENERATE DATA:
-- https://blog.timescale.com/blog/how-to-create-lots-of-sample-time-series-data-with-postgresql-generate_series/

SET search_path to testarea;

select * from generate_series(1,10);

select random() as rnd from generate_series(1,10);  -- acts like an iterator.

CREATE TABLE IF NOT EXISTS  rndtbl
(
    num1 float NOT NULL,
    num2 float NOT NULL
)

insert into rndtbl
	select (random()), (random()) from generate_series(1,100);
-- You do not need to define a tmp table like below. Above is pretty fine.
insert into rndtbl
	select (random()), (random()) from (select * from generate_series(1,100))ser;

select num1 from rndtbl order by num1 offset 90 limit 1;  -- ilk 90 kaydı trim edip sonraki kaydı aldık. == percentile90


delete from rndtbl;

select * from rndtbl;

drop table rndtbl;


select generate_series(1,10,2);
select now()
select generate_series( now(), now()+'10 days'::interval, '2 day'::interval)  --day or days OK!
select generate_series(timestamp '2012-08-01', '2012-08-31',interval '1 day')  -- interval is not necessary. But timestamp is MUST.
select generate_series('2012-08-01', '2012-08-31', '1 day')   --error

select 	cast(generate_series(timestamp '2012-08-01',
			'2012-08-31','1 day') as date)   -- extracts only dates..


select *
	from generate_series('2012-10-01','2012-11-01','1 day'::interval) as t
select t.t
	from generate_series('2012-10-01','2012-11-01','1 day'::interval) as t
select t
	from generate_series('2012-10-01','2012-11-01','1 day'::interval) as t

select generate_series('2012-10-01','2012-11-01','1 day'::interval) as t

select cast(t.t as date)
	from generate_series('2012-10-01','2012-11-01','1 day'::interval) as t

-- NL with SRF
select * from generate_series(1,4) cross join lateral generate_series(1,generate_series.generate_series) as t(gs2);


----------------------------------------------