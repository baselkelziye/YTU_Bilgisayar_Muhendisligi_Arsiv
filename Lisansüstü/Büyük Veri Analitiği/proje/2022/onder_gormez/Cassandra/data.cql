-- Create a keyspace
CREATE KEYSPACE IF NOT EXISTS time_usage WITH REPLICATION = { 'class' : 'SimpleStrategy', 'replication_factor' : '1' };

-- Create time usage summary table
CREATE TABLE IF NOT EXISTS time_usage.summary (
uuid text,
last_update timestamp,
working text,
sex text,
age text,
primary_needs double,
work double,
other double,
PRIMARY KEY (uuid)
);

-- +-----------+------+------+-------------+----+-----+
-- |    Working|   Sex|   Age|Primary Needs|Work|Other|
-- +-----------+------+------+-------------+----+-----+
-- |not working|female|active|         12.4| 0.5| 10.8|
-- |not working|female| elder|         10.9| 0.4| 12.4|
-- |not working|female| young|         12.5| 0.2| 11.1|
-- |not working|  male|active|         11.4| 0.9| 11.4|
-- |not working|  male| elder|         10.7| 0.7| 12.3|
-- |not working|  male| young|         11.6| 0.2| 11.9|
-- |    working|female|active|         11.5| 4.2|  8.1|
-- |    working|female| elder|         10.6| 3.9|  9.3|
-- |    working|female| young|         11.6| 3.3|  8.9|
-- |    working|  male|active|         10.8| 5.2|  7.8|
-- |    working|  male| elder|         10.4| 4.8|  8.6|
-- |    working|  male| young|         10.9| 3.7|  9.2|
-- +-----------+------+------+-------------+----+-----+

-- Insert data above
-- https://www.uuidgenerator.net/
INSERT INTO time_usage.summary (uuid, last_update, working, sex, age, primary_needs, work, other)
VALUES ('43048e0c-1cd6-49e1-a72c-b76c52e3a0cb', toTimeStamp(now()), 'not working', 'female', 'active', 12.4, 0.5, 10.8);

INSERT INTO time_usage.summary (uuid, last_update, working, sex, age, primary_needs, work, other)
VALUES ('65460dd5-37b6-4801-aca4-3cf144c9cc48', toTimeStamp(now()), 'not working', 'female',  'elder', 10.9, 0.4, 12.4);

INSERT INTO time_usage.summary (uuid, last_update, working, sex, age, primary_needs, work, other)
VALUES ('58c044e6-64ba-46bf-bbc5-48afd5df121a', toTimeStamp(now()), 'not working', 'female',  'young', 12.5, 0.2, 11.1);

INSERT INTO time_usage.summary (uuid, last_update, working, sex, age, primary_needs, work, other)
VALUES ('3d189953-c57f-4674-b40e-c432343ba414', toTimeStamp(now()), 'not working',   'male', 'active', 11.4, 0.9, 11.4);

INSERT INTO time_usage.summary (uuid, last_update, working, sex, age, primary_needs, work, other)
VALUES ('eac6a63a-71b6-4c2c-b7f2-98d1dda31a5e', toTimeStamp(now()), 'not working',   'male',  'elder', 10.7, 0.7, 12.3);

INSERT INTO time_usage.summary (uuid, last_update, working, sex, age, primary_needs, work, other)
VALUES ('d9e8a120-12ea-410e-a6fa-b6cca6ed1a28', toTimeStamp(now()), 'not working',   'male',  'young', 11.6, 0.2, 11.9);

INSERT INTO time_usage.summary (uuid, last_update, working, sex, age, primary_needs, work, other)
VALUES ('321e3cb1-9267-4d29-ae09-0a908f211195', toTimeStamp(now()),     'working', 'female', 'active', 11.5, 4.2,  8.1);

INSERT INTO time_usage.summary (uuid, last_update, working, sex, age, primary_needs, work, other)
VALUES ('7967e793-d7bb-4f17-b84a-8b40f666aa46', toTimeStamp(now()),     'working', 'female',  'elder', 10.6, 3.9,  9.3);

INSERT INTO time_usage.summary (uuid, last_update, working, sex, age, primary_needs, work, other)
VALUES ('dd3d4dda-c004-4af2-9e91-a6cefddf114a', toTimeStamp(now()),     'working', 'female',  'young', 11.6, 3.3,  8.9);

INSERT INTO time_usage.summary (uuid, last_update, working, sex, age, primary_needs, work, other)
VALUES ('2a48bd45-d366-4fe1-aafd-c738020a2ff9', toTimeStamp(now()),     'working',   'male', 'active', 10.8, 5.2,  7.8);

INSERT INTO time_usage.summary (uuid, last_update, working, sex, age, primary_needs, work, other)
VALUES ('871d82f8-cdfe-4bb1-8098-6e0851c2e783', toTimeStamp(now()),     'working',   'male',  'elder', 10.4, 4.8,  8.6);

INSERT INTO time_usage.summary (uuid, last_update, working, sex, age, primary_needs, work, other)
VALUES ('5b681078-f86b-4911-8a69-a9612de4a699', toTimeStamp(now()),     'working',   'male',  'young', 10.9, 3.7,  9.2);
