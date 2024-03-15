# CASSANDRA

## Installation and Run

```sh
# Taken and adapted from;
# https://cassandra.apache.org/_/quickstart.html

onder@Onder-Dell-G15-5520:~/.../Cassandra$ docker pull cassandra:latest

onder@Onder-Dell-G15-5520:~/.../Cassandra$ docker network create cassandra

onder@Onder-Dell-G15-5520:~/.../Cassandra$ docker run --rm --detach --name cassandra --hostname cassandra --network cassandra cassandra

# WARNING: Kurulan cassandra docker ın içerisindeki "cqlsh" versiyonu ile burada belirtilen versiyonun (CQLVERSION=3.4.6) aynı olması gerekmektedir.
# Kontrol etmek için aşağıdaki adım uygulanabilir.

# onder@Onder-Dell-G15-5520:~/.../Cassandra$ docker exec --interactive --tty cassandra bash
# root@cassandra:/# cqlsh
# Connected to Test Cluster at 127.0.0.1:9042
# [cqlsh 6.1.0 | Cassandra 4.1.0 | CQL spec 3.4.6 | Native protocol v5]
# Use HELP for help.
# cqlsh>

# WARNING: cqlsh ın init olması için 1 dakikadan uzun beklemek gerekiyor yoksa aşağıdaki gibi hata alınacaktır.
# root@cassandra:/# cqlsh
# Connection error: ('Unable to connect to any servers', {'127.0.0.1:9042': ConnectionRefusedError(111, "Tried connecting to [('127.0.0.1', 9042)]. Last error: Connection refused")})

# $(pwd)/data.cql loaded to test cluster
onder@Onder-Dell-G15-5520:~/.../Cassandra$ docker run --rm --network cassandra -v "$(pwd)/data.cql:/scripts/data.cql" -e CQLSH_HOST=cassandra -e CQLSH_PORT=9042 -e CQLVERSION=3.4.6 nuvo/docker-cqlsh

# Much like an SQL shell, you can also of course use CQLSH to run CQL commands interactively.
onder@Onder-Dell-G15-5520:~/.../Cassandra$ docker run --rm -it --network cassandra nuvo/docker-cqlsh cqlsh cassandra 9042 --cqlversion='3.4.6'

# Clean up
onder@Onder-Dell-G15-5520:~/.../Cassandra$ docker kill cassandra

onder@Onder-Dell-G15-5520:~/.../Cassandra$ docker network rm cassandra
```

## Dataset Upload

* Aşağıda verilen dataset i yüklemek için [data.cql](data.cql) dosyası oluşturulmuştur.
* Detaylar [dosya](data.cql) içerisinden bakılabilir.

```
+-----------+------+------+-------------+----+-----+
|    Working|   Sex|   Age|Primary Needs|Work|Other|
+-----------+------+------+-------------+----+-----+
|not working|female|active|         12.4| 0.5| 10.8|
|not working|female| elder|         10.9| 0.4| 12.4|
|not working|female| young|         12.5| 0.2| 11.1|
|not working|  male|active|         11.4| 0.9| 11.4|
|not working|  male| elder|         10.7| 0.7| 12.3|
|not working|  male| young|         11.6| 0.2| 11.9|
|    working|female|active|         11.5| 4.2|  8.1|
|    working|female| elder|         10.6| 3.9|  9.3|
|    working|female| young|         11.6| 3.3|  8.9|
|    working|  male|active|         10.8| 5.2|  7.8|
|    working|  male| elder|         10.4| 4.8|  8.6|
|    working|  male| young|         10.9| 3.7|  9.2|
+-----------+------+------+-------------+----+-----+
```

## Questions
### 1) Answer the following questions based on the dataset:

```
onder@Onder-Dell-G15-5520:~/.../Cassandra$ docker run --rm -it --network cassandra nuvo/docker-cqlsh cqlsh cassandra 9042 --cqlversion='3.4.6'
Connected to Test Cluster at cassandra:9042.
[cqlsh 5.0.1 | Cassandra 4.1.0 | CQL spec 3.4.6 | Native protocol v5]
Use HELP for help.
cqlsh>
cqlsh> SELECT * FROM time_usage.summary;

 uuid                                 | age    | last_update                     | other | primary_needs | sex    | work | working
--------------------------------------+--------+---------------------------------+-------+---------------+--------+------+-------------
 5b681078-f86b-4911-8a69-a9612de4a699 |  young | 2023-01-02 18:24:13.225000+0000 |   9.2 |          10.9 |   male |  3.7 |     working
 d9e8a120-12ea-410e-a6fa-b6cca6ed1a28 |  young | 2023-01-02 18:24:13.217000+0000 |  11.9 |          11.6 |   male |  0.2 | not working
 321e3cb1-9267-4d29-ae09-0a908f211195 | active | 2023-01-02 18:24:13.219000+0000 |   8.1 |          11.5 | female |  4.2 |     working
 65460dd5-37b6-4801-aca4-3cf144c9cc48 |  elder | 2023-01-02 18:24:13.212000+0000 |  12.4 |          10.9 | female |  0.4 | not working
 3d189953-c57f-4674-b40e-c432343ba414 | active | 2023-01-02 18:24:13.215000+0000 |  11.4 |          11.4 |   male |  0.9 | not working
 eac6a63a-71b6-4c2c-b7f2-98d1dda31a5e |  elder | 2023-01-02 18:24:13.216000+0000 |  12.3 |          10.7 |   male |  0.7 | not working
 dd3d4dda-c004-4af2-9e91-a6cefddf114a |  young | 2023-01-02 18:24:13.221000+0000 |   8.9 |          11.6 | female |  3.3 |     working
 43048e0c-1cd6-49e1-a72c-b76c52e3a0cb | active | 2023-01-02 18:24:13.210000+0000 |  10.8 |          12.4 | female |  0.5 | not working
 2a48bd45-d366-4fe1-aafd-c738020a2ff9 | active | 2023-01-02 18:24:13.223000+0000 |   7.8 |          10.8 |   male |  5.2 |     working
 58c044e6-64ba-46bf-bbc5-48afd5df121a |  young | 2023-01-02 18:24:13.213000+0000 |  11.1 |          12.5 | female |  0.2 | not working
 871d82f8-cdfe-4bb1-8098-6e0851c2e783 |  elder | 2023-01-02 18:24:13.224000+0000 |   8.6 |          10.4 |   male |  4.8 |     working
 7967e793-d7bb-4f17-b84a-8b40f666aa46 |  elder | 2023-01-02 18:24:13.220000+0000 |   9.3 |          10.6 | female |  3.9 |     working

(12 rows)
cqlsh>
```

#### a) How much time do we spend on primary needs compared to other activities?
Aşağıda görüldüğü gibi temel ihtiyaçlarımıza diğer aktivitelerimizden daha fazla zaman ayırmaktayız.

```
cqlsh> SELECT AVG(primary_needs), AVG(other) FROM time_usage.summary;

 system.avg(primary_needs) | system.avg(other)
---------------------------+-------------------
                    11.275 |             10.15

(1 rows)

cqlsh>
```

#### b) Do women and men spend the same amount of time in working?
Sonuçlara göre erkekler kadınlardan daha fazla çalışarak zaman geçirmektedir.

```
cqlsh> SELECT sex, AVG(work) FROM time_usage.summary WHERE sex = 'female' ALLOW FILTERING;

 sex    | system.avg(work)
--------+------------------
 female |          2.08333

(1 rows)

cqlsh> SELECT sex, AVG(work) FROM time_usage.summary WHERE sex = 'male' ALLOW FILTERING;

 sex  | system.avg(work)
------+------------------
 male |          2.58333

(1 rows)

cqlsh>
```

#### c) Does the time spent on primary needs change when people get older? In other words, how much time elder people allocate to leisure compared to active people?
İnsanlar yaşlandıkça temel ihtiyaçlarına ayırdıkları vakitler artmaktadır.

```
cqlsh> SELECT age, AVG(other) FROM time_usage.summary WHERE age = 'active' ALLOW FILTERING;

 age    | system.avg(other)
--------+-------------------
 active |             9.525

(1 rows)

cqlsh> SELECT age, AVG(other) FROM time_usage.summary WHERE age = 'elder' ALLOW FILTERING;

 age   | system.avg(other)
-------+-------------------
 elder |             10.65

(1 rows)

cqlsh>
```
#### d) How much time do employed people spend on leisure compared to unemployed people?
İşsiz insanların 3 saat daha fazla boş vakti vardır.

```
cqlsh> SELECT working, AVG(other) FROM time_usage.summary WHERE working = 'working' ALLOW FILTERING;

 working | system.avg(other)
---------+-------------------
 working |              8.65

(1 rows)

cqlsh> SELECT working, AVG(other) FROM time_usage.summary WHERE working = 'not working' ALLOW FILTERING;

 working     | system.avg(other)
-------------+-------------------
 not working |             11.65

(1 rows)

cqlsh>
```
