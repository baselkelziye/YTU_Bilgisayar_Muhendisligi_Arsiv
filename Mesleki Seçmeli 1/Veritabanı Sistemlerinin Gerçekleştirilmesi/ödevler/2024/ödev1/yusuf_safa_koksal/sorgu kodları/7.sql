EXPLAIN SELECT COUNT(DISTINCT b) FROM t;

--Çıktı
"Aggregate  (cost=53272.43..53272.44 rows=1 width=8)"
"  ->  Index Only Scan using idx_b on t  (cost=0.43..48272.43 rows=2000000 width=4)"

işlem idx_b indeksi üzerinden gerçekleştiriliyor
Sorgu veritabanı sayfasına gitmeye gerek kalmadan sadece indeks kullanılarak gerçekleştiriliyor
