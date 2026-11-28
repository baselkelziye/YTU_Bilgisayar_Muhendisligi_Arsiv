# Ders 2 Genişletilmiş Notu: İç İçe Sorgular, WITH, Veri Değiştirme, Birleştirmeler ve Görünümler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Küme Karşılaştırma: SOME ve ALL
- 2. EXISTS, NOT EXISTS ve UNIQUE
- 3. FROM İçinde Alt Sorgu
- 4. WITH Yan Cümlesi
- 5. Skaler Alt Sorgu
- 6. Veritabanında Değişiklik: DELETE, INSERT, UPDATE
- 7. CASE ile Koşullu Güncelleme
- 8. Birleştirmeler (Joins)
- 9. Görünümler (Views)
- Örnek Sorular

Dersin slaytları Silberschatz, Korth ve Sudarshan'ın *Database System Concepts* (7. baskı) kitabının 3. bölümü ("Introduction to SQL") ile 4. bölümünün ("Intermediate SQL") başıdır (ekrandan, 00:05:00; 02:05:00). Ders Zoom üzerinden yapıldı; hoca slaytların yanında Microsoft Whiteboard ve Notepad++ kullandı.

Önceki derste SQL'e genel giriş yapılmış; toplama (aggregate) fonksiyonları, `ORDER BY`, `GROUP BY` ve `HAVING` görülmüştü. Bu ders, iki kümeyi ya da bir değeri bir kümeyle karşılaştıran anahtar kelimelerle başladı.

## 1. Küme Karşılaştırma: SOME ve ALL

### 1.1 SOME yan cümlesi

`SOME`, adından da anlaşılacağı gibi, bir değerin bir kümenin elemanlarından "en az bazılarından" büyük, küçük ya da eşit olup olmadığını sorar. Slayttaki örnek şudur: Biyoloji bölümündeki en az bir hocadan daha fazla maaş alan hocaların adlarını bulun (ekrandan, 00:05:00).

Bu sorgu önce öz-birleştirme (self join) ile yazılabilir. `instructor` tablosu iki kez, biri `T`, diğeri `S` adıyla kullanılır; `T`'deki hocanın maaşı `S`'dekinden büyük, `S`'deki hoca da Biyoloji bölümünden olmalıdır:

```sql
select distinct T.name
from instructor as T, instructor as S
where T.salary > S.salary and S.dept_name = 'Biology';
```

Aynı sorgu `SOME` ile iç içe sorgu biçiminde daha açık yazılır:

```sql
select name
from instructor
where salary > some (select salary
                     from instructor
                     where dept_name = 'Biology');
```

İç sorgu Biyoloji bölümündeki bütün hocaların maaşlarını getirir; kimi yüksek, kimi düşük olabilir. Dış sorgu bunlardan en az birinden büyük olan maaşları seçer. Yani en düşük Biyoloji maaşından yüksek alan her hoca sonuca girer; bütün Biyoloji hocalarından yüksek almak gerekmez.

### 1.2 SOME'un tanımı

Slayttaki tanım (ekrandan, 00:10:00):

$$F \; \langle comp \rangle \; \textbf{some} \; r \iff \exists \, t \in r \text{ öyle ki } (F \; \langle comp \rangle \; t)$$

Burada `<comp>` şunlardan biri olabilir: $<, \leq, >, =, \neq$. Slayttaki örnekler:

| İfade | Sonuç | Neden |
|---|---|---|
| `5 < some {0, 5, 6}` | doğru | 6, 5'ten büyük |
| `5 < some {0, 5}` | yanlış | 5'e eşit olan var, büyük olan yok |
| `5 = some {0, 5}` | doğru | 5'e eşit bir eleman var |
| `5 <> some {0, 5}` | doğru | 0 ≠ 5 |

Hoca son satırda bir uyarı yaptı: `= some` ile `in` denktir, ama `<> some` ile `not in` denk değildir. `5 <> some {0, 5}` doğrudur, çünkü kümede 5 olmayan en az bir eleman (0) vardır. Oysa `5 not in {0, 5}` yanlıştır, çünkü 5 kümenin içindedir. `SOME` biraz kafa karıştırıcı olabildiği için bazı durumlarda doğrudan `IN` kullanmak daha anlaşılırdır, ama ikisi her zaman birebir denk değildir.

### 1.3 ALL yan cümlesi

`ALL` daha kesin bir kısıt koyar. Soru "Biyoloji bölümündeki herhangi bir hocadan" değil de "Biyoloji bölümündeki bütün hocalardan daha çok maaş alan hocalar kimler?" olsaydı `some` yerine `all` yazılırdı. Hoca bunu şöyle özetledi: `> some` kümenin en küçüğünden, `> all` kümenin en büyüğünden büyük olmak gibi düşünülebilir.

Hoca örneği tahtada bir tabloyla çalıştı (ekrandan, 00:15:00):

| Bölüm | Maaş |
|---|---|
| Biyoloji | 70.000 |
| Bilgisayar | 50.000 |
| Fizik | 90.000 |
| Biyoloji | 30.000 |
| Kimya | 60.000 |

İç sorgu (Biyoloji maaşları) {70.000, 30.000} kümesini getirir. Dış sorgu bütün satırları dolaşır: 70.000, 50.000, 90.000, 30.000, 60.000.

`> all` için her maaşın iki Biyoloji maaşından da büyük olması gerekir:

- 70.000: 70.000'e eşit, büyük değil; elenir.
- 50.000: 30.000'den büyük ama 70.000'den değil; elenir.
- 90.000: ikisinden de büyük; seçilir.
- 30.000: 30.000'e eşit, 70.000'den küçük; elenir.
- 60.000: 30.000'den büyük ama 70.000'den değil; elenir.

Sonuç yalnız 90.000 maaşlı Fizik hocasıdır.

`> some` için en az birinden büyük olmak yeter:

- 70.000: 30.000'den büyük; seçilir.
- 50.000: 30.000'den büyük; seçilir.
- 90.000: seçilir.
- 30.000: 30.000'e eşit, 70.000'den küçük; elenir.
- 60.000: 30.000'den büyük; seçilir.

Sonuç 4 satırdır (Biyoloji 70.000, Bilgisayar 50.000, Fizik 90.000, Kimya 60.000). İki sonuç da sqlite3'te `MAX` ve `MIN` karşılıklarıyla denendi ve doğrulandı.

> **Ek bilgi (derste anlatılmadı):** sqlite3 `SOME`/`ANY`/`ALL` anahtar kelimelerini desteklemez. Bu yüzden deneme `salary > (select max(...))` ve `salary > (select min(...))` biçiminde yapıldı; NULL içermeyen kümeler için bu yazımlar sırasıyla `> all` ve `> some` ile aynı sonucu verir.

Slayttaki `ALL` örneklerini de hoca benzer biçimde açıkladı: `5 < all {0, 5}` yanlıştır (5 kendisine eşit, 0 ise küçük), `5 < all {6, 10}` doğrudur, `5 = all {4, 5}` yanlıştır (4, 5'e eşit değil), `5 <> all {4, 6}` doğrudur (5 kümede yok). `<> all`, `not in` ile aynı mantıktadır: değer kümenin hiçbir elemanına eşit değildir. Ama tersi geçerli değildir: `= all` ile `in` denk değildir; `in` için bir elemana eşitlik yeter, `= all` için bütün elemanlara eşit olmak gerekir. <!-- BELİRSİZ: ALL slaytının karesi yok; örnek kümeler altyazıdaki anlatımdan (0 ile 5, 6 ile 10, 4 ile 5, 4 ile 6) kurulmuştur. -->

## 2. EXISTS, NOT EXISTS ve UNIQUE

### 2.1 EXISTS

`EXISTS` bir varlık sınamasıdır: alt sorgunun sonucu boş değilse doğru, boşsa yanlış döner. Tersi `NOT EXISTS`'tir: alt sorgu boşsa doğru, değilse yanlış.

Slayttaki örnek: 2017 Güz döneminde ve 2018 Bahar döneminde açılan bütün dersleri bulun (ekrandan, 00:20:00).

```sql
select course_id
from section as S
where semester = 'Fall' and year = 2017 and
      exists (select *
              from section as T
              where semester = 'Spring' and year = 2018
                and S.course_id = T.course_id);
```

Dış sorgu 2017 Güz derslerini getirir. `EXISTS` koşulu, aynı dersin 2018 Baharda da açıldığını sınar; iç sorgu boş değilse ders sonuca girer. Slaytta dış sorgudaki `S` değişkenine **korelasyon adı** (correlation name), içteki sorguya da **ilişkili alt sorgu** (correlated subquery) dendiği belirtiliyordu.

Hoca sorguyu Notepad++'a yazdı ve `S.course_id = T.course_id` satırı silinirse ne olacağını sordu (ekrandan, 00:25:00). Bu durumda iç sorgu yalnız "2018 Baharda açılan bütün dersler" kümesini döndürür; bu küme boş olmadığı sürece `EXISTS` her dış satır için doğru olur. Örneğin Güzde 5, Baharda 7 ders varsa bunların örtüşmesi gerekmez; sorgu yine de 2017 Güzün bütün derslerini getirir ve yanlış sonuç verir. Eşitleme, iki dönemdeki derslerin aynı ders olmasını sağlar. Bu davranış sqlite3'te küçük bir tabloyla denendi: koşulla yalnız iki dönemde de açılan ders, koşulsuz ise 2017 Güzün bütün dersleri geldi.

### 2.2 Aynı sorgu IN ile

Hoca aynı sorgunun başka nasıl yazılabileceğini sordu. Bir öğrencinin önerisiyle `IN` kullanıldı (ekrandan, 00:40:00):

```sql
select course_id
from section as s
where semester = 'Fall' and year = 2017
and course_id in (select course_id
                  from section as T
                  where semester = 'Spring' and year = 2018);
```

Burada iç sorguda `select *` değil yalnız `course_id` seçilir. Hoca `S.course_id = T.course_id` koşuluna hâlâ ihtiyaç olup olmadığını sordu.

**Soru:** `IN` kullanılınca ders kimliği eşitlemesi gerekir mi? **Cevap (öğrenci):** Gerekmez; `IN` zaten ortak olanları getirir, eşitleme `EXISTS`'te aynı dersleri eşlemek için gerekmişti. Hoca da onayladı: `IN`, dış sorgudaki `course_id`'nin iç kümede olmasını zaten şart koşar, ayrıca açık bir eşitleme gerekmez.

Hoca aynı sorgunun join ile de yazılabileceğini ekledi.

### 2.3 NOT EXISTS

Slayttaki örnek: Biyoloji bölümünün açtığı bütün dersleri almış öğrencileri bulun (ekrandan, 00:30:00).

```sql
select distinct S.ID, S.name
from student as S
where not exists ( (select course_id
                    from course
                    where dept_name = 'Biology')
                   except
                   (select T.course_id
                    from takes as T
                    where S.ID = T.ID));
```

Birinci iç sorgu Biyoloji'nin açtığı bütün dersleri, ikinci iç sorgu ise belirli bir öğrencinin aldığı bütün dersleri listeler. Birinciden ikincisi çıkarılır. Öğrenci Biyoloji derslerinin hepsini almışsa geriye ders kalmaz, fark boş küme olur ve `NOT EXISTS` doğru döner. Slayttaki notlar: $X - Y = \emptyset \iff X \subseteq Y$; bu sorgu `= all` ve türevleriyle yazılamaz.

Bir öğrenci `EXCEPT`'in ne olduğunu sordu. Hoca `EXCEPT`'i küme farkı olarak açıkladı: üstteki sorgunun sonucunda olup alttakinde olmayan satırlar. Kümelerde A fark B gibidir; A ve B'nin kesişimi çıkarılır, yalnız A'ya ait kısım kalır.

**Soru:** Bu sorgu başka nasıl yazılabilirdi? **Cevap:** Bir öğrenci `WHERE` koşuluyla `NOT IN` kullanılabileceğini söyledi; hoca da `EXISTS` ile `IN`, `NOT EXISTS` ile `NOT IN` arasında benzer bir eşleşme kurulabileceğini, `NOT EXISTS`'in bazen anlamsal olarak ters gelse de kullanım alanı olduğunu belirtti.

### 2.4 UNIQUE

`UNIQUE`, alt sorgunun sonucunda tekrar eden satır olup olmadığını sınar; tekrar yoksa doğru döner. Örnek: 2017'de en fazla bir kez açılmış dersler, yani 2017'nin iki döneminde de açılmamış dersler.

```sql
select T.course_id
from course as T
where unique (select R.course_id
              from section as R
              where T.course_id = R.course_id
                and R.year = 2017);
```

<!-- BELİRSİZ: UNIQUE slaytının karesi yok; sorgu altyazıdaki anlatıma (T ve R adları, yıl 2017, course_id eşitlemesi) göre kitabın standart yazımıyla verilmiştir. -->

İç sorgu, dış sorgudaki dersin 2017'de açıldığı şubeleri getirir. Ders iki dönemde açıldıysa aynı `course_id` iki kez gelir ve `UNIQUE` yanlış olur.

**Soru:** İç sorgudaki `T.course_id = R.course_id` eşitlemesi olmasaydı ne olurdu? **Cevap (öğrenci):** Kartezyen çarpım gibi olurdu. Hoca onayladı: iç sorgu 2017'deki bütün dersleri getirirdi ve dış sorgudaki dersle eşleşmezdi.

> **Hocanın vurgusu:** İç içe sorgularda dış ve iç sorgudaki değerlerin eşleşmesini istiyorsanız bu eşleştirmeyi alt sorgunun içinde yazmanız gerekir.

Hoca aynı sorgunun `GROUP BY` ile de yapılabileceğini anlattı: `course_id` üzerine gruplayıp her dersin kaç kez açıldığını bir kolon olarak hesaplamak ("number of offer" gibi), sonra bu sayının 1'e eşit olduğu dersleri seçmek. Bu daha karmaşık olur; `UNIQUE` daha kolay bir yoldur.

## 3. FROM İçinde Alt Sorgu

Alt sorgular `WHERE`'in yanında `FROM` ve `SELECT` kısımlarında da kullanılabilir. `FROM` içinde kullanıldığında alt sorgunun sonucu bir tablo gibi davranır ve join işlemlerine de girebilir.

Slayttaki örnek: Ortalama maaşı 42.000 dolardan büyük olan bölümlerin ortalama maaşlarını bulun (ekrandan, 00:35:00).

```sql
select dept_name, avg_salary
from ( select dept_name, avg (salary) as avg_salary
       from instructor
       group by dept_name)
where avg_salary > 42000;
```

İç sorgu bölüm başına ortalama maaşı hesaplar ve bölüm adı, ortalama maaş biçiminde bir tablo üretir. Hoca bunu ekranda Bilgisayar 50, Fizik 45 gibi satırlarla (bin cinsinden) bir tablo olarak yazdı ve bu tablonun normal bir tablodan farkı olmadığını vurguladı; yazılan alt sorgu, örneğin `salary` adlı bir tabloya başvurmakla aynı şeydir (ekrandan, 00:40:00). Dış sorgu bu tabloyu 42.000'in üzerindekilere göre süzer.

Slaytta aynı sorgunun ikinci yazımında alt sorguya ad ve kolon adları verilir: `... ) as dept_avg (dept_name, avg_salary) where avg_salary > 42000;` (ekrandan, 00:35:00).

Alt sorgu bir tablo gibi değerlendirildiği için başka bir tabloyla birleştirilebilir. Hoca ekranda şu taslağı yazdı (ekrandan, 00:40:00):

```sql
select i.name, dept_name, avg_salary
from ( ... ) as salary
     inner join instructor i on i.dept_name = salary.dept_name
where avg_salary > 42000;
```

Böylece hocanın adı, bölüm adı ve bölümün ortalama maaşı birlikte gösterilebilir.

### 3.1 Aynı sorgu HAVING ile

Slayttaki "having yan cümlesine ihtiyacımız yok" notundan sonra hoca bu sorgunun `HAVING` ile yazılıp yazılamayacağını sordu.

**Soru:** Bu sorgunun aynısı `HAVING` ile yazılabilir mi? **Cevap (öğrenci):** `GROUP BY`'dan sonra kullanarak yazılabilir. Hoca onayladı:

```sql
select dept_name, avg(salary) as avg_salary
from instructor
group by dept_name
having avg(salary) > 42000;
```

(ara adım eklendi: altyazıda yalnız "group by'dan sonra having, avg salary büyüktür" deniyor; sorgu bu anlatımdan kuruldu.)

**Soru:** `SELECT`'e `budget` gibi bir kolon da eklenseydi sorgu çalışır mıydı? **Cevap (öğrenci):** `GROUP BY` ile gruplanan kolon ve toplama fonksiyonları dışında kolon yazılamaz. Hoca açıkladı: gruplama bölüme göre yapıldı, `budget` `GROUP BY`'ın parçası değil, bu yüzden sorgu hata verir; çözüm o kolonu `GROUP BY`'a da eklemektir. `salary` kolonunu eklemeye ise gerek yoktur, çünkü o `avg` içinde geçer. Kural: bir kolon toplama fonksiyonunun (average, count, min, max) içinde geçiyorsa `GROUP BY`'a yazılmaz; toplama uygulanmayan diğer kolonlar `GROUP BY`'da belirtilmelidir.

Hoca bu örnekte `HAVING` yazımının daha basit, daha verimli ve daha hızlı olduğunu, ama başka kolonlar getirmek gerektiğinde `GROUP BY` ile yapılamayan durumlar olabileceğini söyledi.

## 4. WITH Yan Cümlesi

Sorgular karmaşıklaştığında ara sonuçları bir tablo gibi özetlemek için `WITH` kullanılır. `WITH`, yalnız içinde geçtiği sorguda geçerli olan geçici bir ilişki tanımlar; sorgunun bir parçasıdır (ekrandan, 01:00:00).

Slayttaki örnek: En yüksek bütçeye sahip bütün bölümleri bulun.

```sql
with max_budget (value) as
    (select max(budget)
     from department)
select department.name
from department, max_budget
where department.budget = max_budget.value;
```

`WITH`'ten sonra bir ad (`max_budget`) verilir, `as` ile tanımın içine herhangi bir sorgu yazılır. Ardından bir `SELECT` gelmelidir. `SELECT` içinde `max_budget` bir tablo gibi kullanılır: önce bölümlerin en yüksek bütçesi bulunur, sonra bu sonuç `department` tablosuyla birleştirilir.

### 4.1 Aynı iş FROM içinde

Hoca aynı işin `FROM` içinde alt sorguyla yapılıp yapılamayacağını sordu ve Notepad++'ta şu denemeyi yazdı (ekrandan, 01:05:00):

```sql
select department.name
from department d, (select department_name, max(salary) value
                    from department
                    group by department_name
                   ) max_budget
where d.department_name = max_budget.department_name
  AND d.budget = max_budget.value;
```

Hoca, yalnız tek bir değer (en yüksek bütçe) çekiliyorsa iç sorgunun `GROUP BY` olmadan da işe yarayacağını; ama bölüme göre bir grup değeri çekiliyorsa `GROUP BY` gerektiğini ve iki tarafın bölüm adı üzerinden de eşleştirilmesi gerektiğini anlattı.

> **Ders sonrası not:** Ekrandaki taslakta iç sorgu `department` tablosundan `max(salary)` alıyor ve dış `SELECT`'te `department.name` yazıyor. Slayt şemasında `department` tablosunda maaş değil bütçe (`budget`) kolonu vardır; tutarlı bir yazımda iç sorgu büyük olasılıkla `max(budget)` almalı, dış `SELECT` de `d` takma adını kullanmalıdır (`d.dept_name`). Ayrıca taslağın en üstünde tamamlanmamış bir `with max_budget (value) as` satırı kalmıştır.

**Soru:** Bu alt sorgu `SELECT` içinde yazılsaydı ne olurdu? **Cevap:** Hoca, sorgunun çalışacağını ama istenen sonucu getirmeyeceğini söyledi: her bölüm için bir satır gelir ve her satırın yanına aynı en yüksek değer yazılırdı. Yalnız en yüksek bütçeli bölümü görmek için bütçenin en yüksek değerle eşleştiği satırları getirmek gerekir.

### 4.2 Karmaşık sorgularda WITH

Slayttaki ikinci örnek: Toplam maaşı, bütün bölümlerdeki toplam maaşların ortalamasından büyük olan bölümleri bulun (ekrandan, 01:10:00).

```sql
with dept_total (dept_name, value) as
       (select dept_name, sum(salary)
        from instructor
        group by dept_name),
     dept_total_avg(value) as
       (select avg(value)
        from dept_total)
select dept_name
from dept_total, dept_total_avg
where dept_total.value > dept_total_avg.value;
```

Birinci geçici ilişki (`dept_total`) bölüm başına toplam maaşı verir; hocanın örneğinde bilgisayar mühendisliği, kimya, fizik, matematik gibi bölümlerin her birinin toplam maaşı. İkinci ilişki (`dept_total_avg`) bu toplamların ortalamasıdır; örneğin 10 bölüm varsa ortalama 150.000 gibi tek bir değer. Son sorgu iki ilişkiyi tablo gibi birleştirir ve toplamı bu ortalamadan büyük olan bölümleri listeler. İki tanım virgülle ayrılır.

**Soru:** `WITH`'ten sonra tablo adının yanına parantez içinde kolon adlarını yazmak gerekli mi? **Cevap:** Gerekli değil. Ama `sum(salary)` gibi hesaplanan bir ifadenin kolon karşılığı olmadığı için onu bir yerde adlandırmak gerekir: ya `WITH` başlığında kolon listesiyle ya da iç sorguda `sum(salary) as value` diyerek.

`WITH` kullanılmasaydı da bu sorgu yazılabilirdi, ama alt sorgular `FROM` içinde iç içe yazılacağı için okunması zorlaşırdı. Bu yüzden karmaşık sorgularda `WITH` önerildi.

## 5. Skaler Alt Sorgu

Skaler alt sorgu, tek bir değerin beklendiği yerde kullanılan alt sorgudur. Hoca, sabit tek bir değer çekiliyorsa bu tür alt sorguları `SELECT` içinde yazmanın mantıklı olduğunu söyledi.

Slayttaki örnek: Bütün bölümleri, her bölümdeki hoca sayısıyla birlikte listeleyin (ekrandan, 01:15:00).

```sql
select dept_name,
       (select count(*)
        from instructor
        where department.dept_name = instructor.dept_name)
       as num_instructors
from department;
```

Bu iş `department` ile `instructor` birleştirilip sayılarak da yapılabilirdi. Burada dış sorgu yalnız bölüm adlarını getirir, iç sorgu her bölüm için `instructor` tablosunda sayım yapar.

**Soru:** İç sorgudaki `where` koşulu olmasaydı ne olurdu? **Cevap (öğrenci):** Bütün hocaların sayısı gelirdi. Hoca onayladı: okulda örneğin 500 hoca varsa bilgisayar, kimya, fizik, matematik, her bölümün yanına 500 yazılırdı. İstenen bölüm başına sayı olduğu için bu koşul yazılmak zorundadır.

**Soru:** Yeni açılmış, henüz hocası olmayan bir bölüm (örneğin oyun geliştirme) için satır gelir mi? **Cevap:** Bir öğrenci "gelir, sıfır gelir" dedi. Hoca satırın geleceğini, sol taraftaki her bölüm için bir satır olacağını, ama sayının boş (NULL) gelebileceğini söyledi.

> **Ders sonrası not:** Hoca bu durumda değerin NULL geleceğini söyledi; doğrusu öğrencinin dediği gibi 0'dır. `count(*)` boş bir küme için 0 döndürür. Bu, sqlite3'te hocası olmayan bir bölümle denendi ve sonuç 0 çıktı.

Slaytta da belirtildiği gibi, alt sorgu birden fazla satır döndürürse çalışma zamanı hatası alınır. Bir bölüme birden çok satır karşılık geliyorsa, örneğin iç sorgu `count` yerine `select *` olsaydı ya da bölüm iki kez girilmiş olsaydı, sorgu hata verirdi. Burada `count` kullanıldığı için sorun yoktur.

## 6. Veritabanında Değişiklik: DELETE, INSERT, UPDATE

Tablolarda kayıt silmek, eklemek ve güncellemek gerekebilir; bunların hepsi SQL ile yapılır.

### 6.1 DELETE, DROP ve TRUNCATE

Hoca `DELETE` ile `TRUNCATE` ya da `DROP` arasındaki farkı sordu.

**Soru:** `DROP` ile `DELETE` arasındaki fark nedir? **Cevap (öğrenci):** `DROP` tabloyu, `DELETE` satırları siler. Hoca ekledi: `DROP` bütün tabloyu yok eder, tabloya ait şema da kalmaz. `DELETE` yalnız satır değerlerini siler. `TRUNCATE` de kayıt siler ve `DROP` gibi tabloyu yok etmez; farkı, `DELETE` ile belli koşulları sağlayan satırlar (bir satır, 500 satır, 1000 satır) silinebilirken `TRUNCATE`'in bütün tabloyu boşaltmasıdır. Koşulsuz `delete from <tablo>` da işlev olarak aynı sonucu verir; ama bütün tabloyu silmek çoğu zaman istenmeyen bir durumdur. Belli kayıtlar `WHERE` ile seçilerek silinir.

**Soru:** `DELETE`'te `SELECT`'teki gibi kolon belirtmek gerekir mi? **Cevap (öğrenci):** Gerekmez, satır silindiği için kolon yazmak çalışmaz. Hoca onayladı: `DELETE` hücre hücre değil satır satır siler, doğrudan `DELETE FROM` yazılır.

### 6.2 Alt sorgulu silme

`DELETE`'te de iç içe sorgu kullanılabilir. Örnek: Watson binasındaki bölümlerin hocalarını silmek. Silinen tablo `instructor`'dır; ama bina bilgisi (`building`) `department` tablosunda olduğu için `department`'a gidilip `building = 'Watson'` olan bölümler bulunur ve bu bölümlerdeki hocalar silinir (bir `IN` alt sorgusuyla).

<!-- BELİRSİZ: Watson örneğinin karesi yok; sorgunun tam metni ekrandan doğrulanamadı. -->

Slayttaki ikinci örnek: Maaşı hocaların ortalama maaşından az olan bütün hocaları silin (ekrandan, 01:20:00).

```sql
delete from instructor
where salary < (select avg (salary)
                from instructor);
```

Slaytta sorun ve çözüm şöyle verilir: hocalar silindikçe ortalama maaş değişir. SQL'in çözümü: önce `avg(salary)` hesaplanır ve silinecek bütün satırlar bulunur; sonra bu satırlar, ortalama yeniden hesaplanmadan ya da satırlar yeniden sınanmadan silinir.

**Soru:** İç sorgu eşleştirilmezse silme sırasında ortalama sürekli değişmez mi? `DELETE` satır satır çalıştığı için `WHERE` her satırda yeniden çalışmaz mı? **Cevap:** Hoca, iç içe sorgularda önce içteki sorgunun sonuçlandığını, sonra dıştaki sorgunun çalıştığını hatırlattı. İç sorgu tabloya gider, bütün maaşlardan bir ortalama bulunur, örneğin 55.300. Bu tek bir değer olduğu için sorgu artık `salary < 55300` gibi sabit bir değerle karşılaştırmaya dönüşür. `WHERE` her satır için çalışır ama sağ taraf sabittir; ortalamaya tekrar gidilmez. İç içe sorgu `for` döngüsü gibi iteratif çalışmaz; bildirimsel diller zaten iteratif çalışmaz. İteratif işlem gerekiyorsa başka mekanizmalar kullanılır; bunlar SQL için çok verimli değildir ve sonraki derslerde konuşulacaktır. Ortalamayı ayrı bir sorguyla bulup bir değişkene atamak ve sonra bu değişkenle silmek de bir yoldur.

### 6.3 INSERT

Bir tablonun bütün kolonlarına değer verilecekse kolon adlarını yazmak gerekmez; örneğin `course` tablosunun dört kolonunun hepsine değer veriliyorsa doğrudan `insert into course values (...)` yazılır. Bir kolon (örneğin ders adı) verilmezse sorun çıkar: dört kolonlu tabloya üç değer girildiğinde hangi değerin hangi kolona gideceği anlaşılmaz ve hata alınır. Bu yüzden eksik değer verilecekse kolon adları yazılmalıdır.

Değeri sonradan girilecek bir kolon için `NULL` verilebilir; ama bu kolonun (örneğin `credits`) NULL alabilir olması gerekir. NULL alamayan bir kolona NULL girilirse veritabanı bu kolona değer girmenin zorunlu olduğunu söyleyerek hata verir.

`INSERT` bir `SELECT` sorgusuyla da yapılabilir. Örnekte `INSERT INTO`'dan sonra yalnız tablo adı yazılır, ardından `student` tablosundan Müzik bölümünde olan ve kredisi belli bir değerin üzerindeki öğrencileri seçen bir `SELECT` gelir; bu koşulu sağlayan kaç öğrenci varsa o kadar satır eklenir. <!-- BELİRSİZ: kredi eşiği altyazıda "114" diye geçiyor, karesi yok; kitaptaki örnekte büyük olasılıkla 144'tür. -->

Hoca, iki tablonun kolonları birebir örtüşüyorsa `select *` yazılabileceğini, ama örtüşmüyorsa sorun çıkacağını söyledi. Örneğin birleştirilmiş bir sorguda iki ID kolonu gelirse hangisinin kullanılacağı belirsizleşir ve hata alınır.

> **Hocanın vurgusu:** `INSERT` yaparken `select *` kullanmayın; kolon adlarını tek tek yazmanızda fayda var.

### 6.4 UPDATE

`UPDATE` çok yaygın kullanılan bir işlemdir. Koşullar düzgün yazılmazsa yanlışlıkla bütün satırlar güncellenebilir.

> **Hocanın vurgusu:** `UPDATE`, `DELETE` ve `INSERT` yapmadan önce sorgunun `SELECT` sürümünü yazın. Böylece kaç satırın etkileneceğini ve hangi satırların değişeceğini görürsünüz; sonra aynı koşulu asıl ifadeye yazarsınız.

Hocanın ekrandaki örneği, maaşı 70.000'den az olan hocalara %5 zam yapar (ekrandan, 01:30:00):

```sql
update instructor
set salary = salary * 1.05
where salary < 70000;
```

Önce `select ID, salary, salary * 1.05 from instructor where salary < 70000` gibi bir sorguyla etkilenecek satırlar ve yeni değerler görülebilir (ara adım eklendi: altyazıda sorgu "SELECT, ID, salary, salary çarpılmış versiyonu, FROM instructor" diye geçiyor).

`UPDATE` iki parçalıdır: tablonun adı ve `SET` ile güncellenecek değer. `SET`'te virgülle birden çok kolon güncellenebilir; hoca `salary` ile birlikte `promoted` gibi bir kolonun da `true` yapılabileceğini örnek verdi. `WHERE` koşulu, güncellenecek satırları bulur; bu satırlarda bir ya da birden çok sütun aynı anda değiştirilir. `SET`'in sol tarafı güncellenen kolonun adıdır; sağ taraf aynı kolonu kullanmak zorunda değildir, `500` gibi sabit bir değer de olabilir.

Slayttaki başka bir örnek, ortalamanın altında maaş alan hocalara %5 zam yapar: `WHERE` içinde `instructor`'dan ortalama maaş hesaplanır, örneğin 50.000'den küçük alanlara zam yapılır.

### 6.5 Güncelleme sırası sorunu

Slayttaki örnek: 100.000'den fazla alanlara %3, geri kalanlara %5 zam yapın. Bu iki ayrı `UPDATE` ile yazılır: önce maaşı 100.000'den fazla olanlara %3, sonra 100.000 ve altındakilere %5.

**Soru:** Sıra ters olsaydı ne olurdu? **Cevap (öğrenci):** Maaşlar artmış olacağı için bazıları 100.000'i geçer ve 100.000'i geçenlere ikinci kez zam yapılırdı. Hoca bunun sorunlu bir sonuç doğuracağını, sorgunun bu sırayla çalıştığını ama daha iyi bir yolun `CASE` olduğunu söyledi.

## 7. CASE ile Koşullu Güncelleme

`CASE`, programlama dillerindeki `switch-case` yapısının SQL karşılığıdır. Java ya da C++'ta `switch` içinde "case 1 ise bunu, case 3 ise şunu uygula" denir. Slayttaki sorgu (ekrandan, 01:35:00):

```sql
update instructor
set salary = case
               when salary <= 100000 then salary * 1.05
               else salary * 1.03
             end
```

Bu `UPDATE`'te `WHERE` yoktur; bütün hocaların maaşı değişir, ama nasıl değişeceği hocanın maaşına göre belirlenir. Hoca okunabilirlik için aynı seviyede çalışan parçaları aynı girintiyle yazmayı ve `CASE` ifadesini parantez içine almayı önerdi.

Hoca bunu Java'daki `switch` ile karşılaştırdı. Bir öğrenci, Java'daki `switch`'in yalnız eşitliğe baktığını, burada ise büyüktür ve küçüktür kullanıldığını belirtti; hoca da `switch`'te `case 100000:` gibi yalnız eşitlik olduğunu, `CASE WHEN`'in ise koşul aldığını, `default`'un `ELSE`'e karşılık geldiğini kabul etti. Ortak mantık şudur: bir satır yalnız bir dala girer, birden fazla dala karşılık gelmez. Bu da bir hocanın hem 100.000'in altında zam alıp hem de zamla 100.000'i geçtiği için ikinci kez zam almasını engeller.

**Soru:** `CASE` birden fazla dalı destekliyor mu? **Cevap:** Evet. Hoca ekranda dört dallı bir örnek yazdı (ekrandan, 01:40:00):

```sql
update instructor
set salary = ( case
                 when salary <= 30000  then salary * 1.0?
                 when salary <= 70000  then salary * 1.04
                 when salary <= 100000 then salary * 1.03
                 else salary * 1.03
               end
             )
```

<!-- BELİRSİZ: ilk dalın çarpanı karede seçili (vurgulu) olduğu için okunamıyor; "1.0?" diye bırakıldı. -->

**Soru:** Şu an çakışma olur mu? **Cevap (öğrenci):** Olmaz, sıra doğru çünkü küçükten büyüğe gidiyor. Hoca dalları tek tek açıkladı:

- 30.000'den küçük bir maaş ilk dala girer.
- 50.000 alan bir hoca ilk dalı geçer, 70.000'den küçük olduğu için ikinci dala girer.
- 90.000 alan bir hoca ilk iki dalı geçer, üçüncü dala girer.
- 120.000 alan bir hoca üç dalı da geçer ve `ELSE` dalına (switch'teki `default`) düşer; 100.000'in üzerindeki herkes %3 zam alır.

Yani her hoca için sorgu, dinamik olarak `update instructor set salary = salary * 1.03` gibi tek bir ifadeye dönüşür. Dallar sırayla denenir; ilk sağlanan dala girilince diğerleri atlanır. Bir öğrenci de bunu "hoca bu ifadeye göre yalnız bir kez zam alabilir" diye özetledi, hoca onayladı.

**Soru:** `<= 100000` dalı en başa yazılsaydı ne olurdu? **Cevap (öğrenci):** 100.000'den küçük olan her şey ilk dalda yakalanır, diğer iki dal tamamen atlanır. Hoca onayladı: o dallar anlamını yitirir; 100.000'in altındaki herkes ilk dalın zammını, üstündekiler `ELSE`'i alır. `CASE` bu şekilde, küçükten büyüğe sıralanarak kullanılmalıdır.

Sqlite3'te beş satırlık örnek tabloyla bu dört dallı yapı (ilk dal ×1.05 varsayılarak) denendi; her satır tek bir zam aldı (30.000 → 31.500, 50.000 → 52.000, 60.000 → 62.400, 70.000 → 72.800, 90.000 → 92.700).

### 7.1 Skaler alt sorgulu güncelleme

`UPDATE` içinde de iç içe sorgu yazılabilir. Slayttaki örnek: Bütün öğrenciler için `tot_cred` değerini yeniden hesaplayıp güncelleyin (ekrandan, 01:45:00).

```sql
update student S
set tot_cred = (select sum(credits)
                from takes, course
                where takes.course_id = course.course_id and
                      S.ID = takes.ID and
                      takes.grade <> 'F' and
                      takes.grade is not null);
```

İç sorgu her öğrenci için geçtiği derslerin kredilerini toplar. Slaytta belirtildiği gibi hiç ders almamış öğrencilerin `tot_cred` değeri NULL olur. NULL yerine 0 yazmak için `sum(credits)` yerine şu kullanılır:

```sql
case
  when sum(credits) is not null then sum(credits)
  else 0
end
```

**Soru:** Sorgudaki `<>` işareti ne anlama geliyor? **Cevap:** Eşit değil demektir; `takes.grade <> 'F'`, notu F olmayanlar demektir. Bir öğrenci `!=` ile aynı olup olmadığını sordu; hoca aynı anlama geldiğini, bazı sistemlerde `!=`, bazılarında `<>` kullanıldığını söyledi. `is not null` ise NULL olmayan anlamına gelir.

> **Ek bilgi (derste anlatılmadı):** SQL standardındaki "eşit değil" işleci `<>`'dir. `!=` standart değildir ama SQL Server, PostgreSQL, MySQL ve SQLite gibi yaygın sistemlerin çoğu büyük olasılıkla ikisini de kabul eder.

## 8. Birleştirmeler (Joins)

Dersin son bölümünde, ileri SQL konularına geçildi; hoca sırasıyla join'ler, view'lar, transaction'lar, bütünlük kısıtları, SQL veri tipleri, şemalar, indeksler ve yetkilendirmenin konuşulacağını söyledi ve join'lerle başladı.

Join, birden çok tabloyu (ilişkiyi) bağlamak için kullanılan yapıdır ve `FROM` yan cümlesinin bir parçası olarak yazılır. Doğrudan tabloya ya da bir alt sorgunun sonucuna bağlanabilir. Türleri: natural join, inner join ve outer join; outer join de kendi içinde left, right ve full outer join olarak ayrılır.

### 8.1 Natural join

Natural join, iki tabloda aynı adlı en az bir kolon varsa satırları bu kolon üzerinde otomatik olarak eşleştirir. Slayttaki tanım: ortak kolonların hepsinde aynı değere sahip satırları eşleştirir ve her ortak kolondan yalnız bir kopya tutar (ekrandan, 02:05:00).

Slayttaki örnek:

```sql
select name, course_id
from students, takes
where student.ID = takes.ID;
```

Aynı sorgu natural join ile:

```sql
select name, course_id
from student natural join takes;
```

> **Ders sonrası not:** Slaytın açıklama satırında "hocaların adlarını ve verdikleri derslerin kimliklerini listeleyin" yazıyor, ama sorgu `student` ve `takes` tablolarını kullanıyor; sorgu öğrencilerin adlarını ve aldıkları derslerin kimliklerini listeler. İlk sorgunun `FROM` kısmındaki `students` de büyük olasılıkla `student` olmalıdır.

Natural join'in çalışması için iki tabloda aynı adlı ve uyumlu veri tipinde kolon olmalıdır. Sol tabloda `ID`, sağda `instructor_ID` gibi farklı adlı bir kolon varsa, aynı veriyi taşısalar bile natural join bunları eşleştirmez.

Bir öğrencinin sorusu üzerine hoca, birden çok ortak kolon varsa natural join'in hepsini eşleştirdiğini vurguladı. Başka bir soru, birden fazla natural join art arda yazılınca yeni tablonun hangisiyle eşleştirileceğiydi; hoca birinci ve ikinci tablonun ortak kolonlarına göre birleştiğini, üçüncü tablonun da bu sonuçla ortak kolonlarına göre birleştiğini, bunun kafa karıştırabileceğini söyledi. Natural join örtük (implicit) bir join yapar; yalnız isim benzerliğinden yola çıkarak beklenmeyen kolonlar üzerinden de birleştirebilir.

> **Ders sonrası not:** Hoca, tablolar `FROM student, takes` biçiminde virgülle yazılıp join türü belirtilmezse sorgunun natural join olarak çalıştığını söyledi. Doğrusu: virgülle yazılan tablolar koşul yoksa Kartezyen çarpım üretir; eşleştirme `WHERE student.ID = takes.ID` gibi bir koşulla yapılır (slayttaki ilk sorguda olduğu gibi). Natural join için `NATURAL JOIN` açıkça yazılmalıdır.

### 8.2 Natural join ile inner join farkı

Hoca tahtada `student (ID, name, dept_name)` ve `takes (ID, course, semester)` tablolarını çizdi (ekrandan, 02:10:00; 02:15:00). `select * from student natural join takes` sorgusu iki tabloyu ortak `ID` kolonu üzerinden birleştirir ve sonuçta `ID` kolonu bir kez yer alır: ID, name, dept_name, course, semester.

Inner join de her iki tarafta bulunan değerler üzerinden birleştirir, ama birleştirme koşulunu açıkça (explicit) yazmak gerekir. Bunun için `ON` kullanılır:

```sql
select *
from student s inner join takes t on s.ID = t.ID;
```

Slaytta da `ON` koşulunun, birleştirilen ilişkiler üzerinde genel bir yüklem (predicate) yazmaya izin verdiği; bu yüklemin `WHERE` gibi yazıldığı ama `on` anahtar kelimesiyle verildiği belirtilir. Örnek: `select * from student join takes on student_ID = takes_ID`, `select * from student, takes where student_ID = takes_ID` ile denktir (ekrandan, 02:20:00).

Hocanın saydığı farklar:

- Natural join'de aynı adlı ve tipli kolonlar için koşul yazılmaz, otomatik uygulanır; inner join'de isimler aynı olsa bile koşul yazmak zorunludur.
- Natural join'de ortak kolon sonuçta bir kez yer alır; inner join'de `select *` yazılırsa iki tablonun `ID` kolonu da gelir. Kolonlar tek tek yazılarak (`s.ID as ...`, `s.name`, `s.dept_name`, `t.ID as takes_ID` gibi) ad verilebilir.
- `takes` tablosundaki kolon `student_ID` olsaydı natural join ortak kolon bulamazdı; inner join'de ise `on s.ID = t.student_ID` yazılarak birleştirme yapılabilir.

**Soru:** `takes` tablosunda zaten yabancı anahtar olduğu için kolonu `student_ID` diye adlandırmak daha iyi olmaz mı? **Cevap:** Hoca da bunu önerdi: aynı adları kullanmak doğru değildir. Bir tablonun kendi kimliği `ID` olabilir, ama yabancı anahtar olarak tutulan kimlik, ait olduğu tablonun adıyla birlikte yazılmalıdır. `name` için de aynısı geçerlidir: bir tabloda `name` hem öğrencinin hem bölümün adı olabilir; `student_name`, `department_name` gibi adlar karışıklığı önler.

> **Hocanın vurgusu:** Natural join doğru bir birleştirme yöntemi değildir; inner join ya da gerekiyorsa outer join kullanın ve koşulu `ON` ile açıkça yazın. Sorguları siz unutacaksınız, başkaları da kullanacak, view'larda başvurulacak; uzun ve açık yazılan sorgular uzun vadede çok daha güvenlidir ve okunabilirliği yükseltir.

Slayttaki örnekte `student (ID, name, dept_name, tot_cred)` ile `takes (ID, course_id, sec_id, semester, year)` natural join ile birleştirildiğinde tek bir `ID` kolonu gelir. Buradaki `ID`'nin hangi tablonun kimliği olduğu kolayca anlaşılmaz. Bir natural join daha eklenip `course` ile birleştirildiğinde ise aynı adlı başka kolonlar (örneğin bölüm adı) da eşleşmeye girer ve sorun çıkar.

Bu sorunu azaltmak için `USING` kullanılabilir: `student natural join takes` önce birleştirilir, sonra sonuç `join course using (course_id)` ile yalnız belirtilen kolon üzerinden `course` ile birleştirilir. `USING` da `ON` gibi hangi kolon üzerinden birleştirileceğini söyler. Hoca bunun da yeterli olmadığını, çünkü iki tablonun nasıl birleştiğinin sorguda görünmediğini ve tabloya gidip bakmak gerektiğini söyledi; genel önerisi mümkün olduğunca inner join kullanmaktı.

### 8.3 Inner join ve outer join: tahtadaki örnek

**Soru:** Outer join'i daha önce duydunuz mu? **Cevap (öğrenci):** Sağ ya da sol tabloda karşılığı olanları alır. Hoca açıkladı: inner join bir filtreleme uygular.

Tahtadaki tablolar (ekrandan, 02:25:00):

| student.ID |
|---|
| 115 |
| 113 |
| 112 |
| 110 |

| takes.ID | Ders |
|---|---|
| 115 | coğrafya |
| 115 | matematik |
| 113 | işletim sistemleri |
| 112 | kimya |

110 kimlikli öğrenci hiç ders almamıştır.

```sql
select *
from student s inner join takes t on s.ID = t.ID;
```

**Soru:** Bu inner join hangi satırları getirir? **Cevap (öğrenci):** 110 gelmez, sağda ve solda eşleşenler gelir. Hoca onayladı: 115'ten 2 satır gelir (öğrencinin adı, bölümü ve iki dersi), 113 ve 112 birer kez gelir; toplam 4 satır. 110'un diğer tabloda karşılığı olmadığı için inner join onu dışarıda bırakır.

Bazı durumlarda karşılığı olmayan satırlar da görülmek istenir. Bunun için `left outer join` yazılır:

```sql
select *
from student s left outer join takes t on s.ID = t.ID;
```

`OUTER` kelimesi sözdiziminde yer alır, ama birçok veritabanı sistemi `LEFT JOIN` ve `RIGHT JOIN`'i de kabul eder. Bu sorgu 5 satır getirir; 5. satır 110'dur. 110'un sol taraftaki (öğrenci) bilgileri doludur, sağ taraftaki (`takes`) kolonları NULL gelir. Left join'de sol tablonun bütün kayıtları kesin gelir; sağ tarafta bir ya da birden çok kayıt eşleşebilir ya da hiç eşleşme olmayabilir.

**Soru:** Bu veride right join olsaydı? **Cevap (öğrenci):** Inner join gibi çalışır, çünkü sağda olup solda olmayan kayıt yok. Hoca onayladı: 4 satır gelir. Ama örneğin sistemden silinmiş bir öğrencinin (109 gibi) `takes`'te ders kaydı kalmış olsaydı, right join yine 5 satır getirirdi ve bu kez 109'un satırında sol taraftaki öğrenci kolonları boş olurdu.

Inner join ile left join satır sayıları (4 ve 5) sqlite3'te aynı tablolarla denendi ve doğrulandı.

Right ve left join'de tabloların sırası önemlidir. Hoca, aslında ikisinden birine gerek olmayabileceğini, `student` ile `takes`'in yerleri değiştirilerek right join yerine left join kullanılabileceğini söyledi. Karşılığı olmayan değerler her durumda NULL olarak gösterilir.

### 8.4 Slayttaki course ve prereq örnekleri

İkinci örnekte `course` tablosunda derslerin adı, bölümü ve kredisi; `prereq` tablosunda ise derslerin ön koşulları vardır. `prereq`'te BIO-301 için BIO-101, CS-190 için CS-101, CS-347 için CS-101 ön koşulu kayıtlıdır. `course` tablosunda CS-347'nin bilgisi yoktur; CS-315'in ise ön koşulu yoktur. Bu yüzden iki yönlü örnek kurulabilir.

`course natural left outer join prereq` sorgusunda (natural yazıldığı için `course_id` ayrıca belirtilmez; natural yazılmasaydı `on course.course_id = prereq.course_id` yazılmalıydı) `course` tablosundaki bütün satırlar gelir; CS-315'in ön koşulu olmadığı için `prereq_id` kolonu NULL olur.

`course natural right outer join prereq` sonucu (ekrandan, 02:30:00):

| course_id | title | dept_name | credits | prereq_id |
|---|---|---|---|---|
| BIO-301 | Genetics | Biology | 4 | BIO-101 |
| CS-190 | Game Design | Comp. Sci. | 4 | CS-101 |
| CS-347 | null | null | null | CS-101 |

Burada `prereq` tablosunun bütün satırları gelir; CS-347'nin `course`'ta karşılığı olmadığı için ders bilgileri NULL olur. CS-315 ise `prereq`'te olmadığı için sonuçta görünmez. Slaytta ilişkisel cebirdeki karşılığı da `course` ile `prereq` arasında sağ dış birleştirme (right outer join) sembolüyle verilmiştir.

Full outer join her iki yönü birlikte uygular: left join'deki CS-315 ve right join'deki CS-347 satırları birlikte gelir, satır sayısı artar. Inner join ise yalnız iki tabloda da bulunan dersleri getirir; NULL değer içermez ve daha az satır döndürür.

Join türleri özetle: inner join, left outer join, right outer join, full outer join. Birleştirme koşulu `natural`, `on <yüklem>` ya da `using (A1, A2, ...)` ile verilir.

**Soru (sohbetten):** Outer join'in başına natural yazılmaz ve iki tabloda aynı adlı kolonlar varsa, hiçbir şey belirtmesek onları baz alır mı? **Cevap:** Hoca, belirtilmezse natural kabul edildiğini, ama bunun doğru bir çözüm olmadığını söyledi. Left ve right join yapılıyorsa hangi kolonun kullanılacağı kesinlikle belirtilmeli; `USING` içinde de yazılabilir, ama hoca `ON` ile iki taraftaki tablo ve kolon adlarını açıkça yazmayı önerdi.

> **Ders sonrası not:** Hoca, `ON` ya da `USING` yazılmayan outer join'in natural kabul edildiğini söyledi. Standart SQL'de `LEFT/RIGHT/FULL OUTER JOIN` için `NATURAL`, `ON` ya da `USING` gerekir; hiçbiri yazılmazsa büyük olasılıkla sözdizimi hatası alınır.

## 9. Görünümler (Views)

View (görünüm), veritabanlarında birçok sorunun çözümünde kullanılan bir yapıdır. Bir sorgunun sanal karşılığı gibi düşünülebilir: bir mantık, tabloya dönüşecek biçimde bir sorgu olarak tanımlanır.

Hoca avantajını tahtada bir örnekle anlattı (ekrandan, 02:40:00). Bir `employee` tablosunda çalışanların ID'si, TC kimlik numarası, adı, adresi, e-posta adresi, doğum yeri gibi birçok bilgi ve en sonda maaş bilgisi vardır. Personeller işe alınırken bütün bu bilgiler veritabanına girilir. Bir web uygulamasında, örneğin personellerin kaç saat mesai yaptığını gösteren bir tablo hazırlanacaktır. Bu uygulamanın çalışan adları için `employee` tablosuna erişmesi gerekir; ama bütün kolonları (kimlik numarası, maaş) uygulama geliştiricilere ya da diğer personele açmak doğru değildir.

Bunun yerine bir görünüm tanımlanır:

```sql
create view employee_view as
select ID, name, email
from employee;
```

Bu görünümün yalnız üç kolonu vardır: ID, ad ve e-posta. Uygulamalara ve kullanıcılara tablo yerine bu görünüme erişim verilir; böylece maaş bilgisini görmezler, ama ihtiyaç duydukları verileri görünümden alabilirler.

`select * from employee_view` çalıştırıldığında gelen kolonlar ID, ad ve e-postadır. Arka planda aslında görünüm tanımındaki `select ID, name, email from employee` sorgusu çalışır. Görünümün kendisi veri taşımaz; her sorgulandığında tanımındaki tabloya gidip bu kolonları çeker. Bu yüzden sanal bir ilişkiye (virtual relation) erişim gibidir ve alan bakımından bir katkısı ya da maliyeti yoktur.

Slayttaki tanım da aynıdır: bazı durumlarda bütün kullanıcıların mantıksal modelin tamamını görmesi istenmez; örneğin bir hocanın adını ve bölümünü bilmesi gereken ama maaşını görmemesi gereken biri için `select ID, name, dept_name from instructor` ilişkisi yeterlidir. Görünüm bazı verileri belirli kullanıcılardan gizleme mekanizması sağlar; kavramsal modelin parçası olmayıp kullanıcıya "sanal ilişki" olarak gösterilen her ilişkiye görünüm denir (ekrandan, 02:35:00).

Görünümün ikinci faydası sadeleştirmedir: çok karmaşık bir sorgunun sonucu bir görünüm olarak tanımlanırsa, o sorgunun bütün mantığını görmeden yalnız görünümdeki veriler sorgulanabilir. Hem veri gizleme hem sorgu sadeleştirme için kullanılır.

Görünüm tanımı normal bir SQL sorgusu gibidir: `create view` yazılır, bir ad verilir (`v`, `employee_view` ya da başka bir ad), `as`'ten sonra herhangi bir `SELECT` sorgusu gelir. Örnek:

```sql
create view faculty as
select ID, name, dept_name
from instructor;
```

Burada `salary` kolonu gösterilmez. Sonra görünüm üzerinde sorgu yapılır:

```sql
select name
from faculty
where dept_name = 'Biology';
```

Görünüm içinde toplama da yapılabilir: bölüm adına göre gruplayıp toplam maaşı veren bir görünüm (`dept_name`, `total_salary` kolonlarıyla) tanımlanırsa, aynı sorguyu her seferinde iç içe yazmak gerekmez; bu görünüm bir tablo gibi birleştirmelerde kullanılır.

Bir öğrenci görünümün sınıfa (class) benzeyip benzemediğini sordu. Hoca görünümü sınıf gibi değil bir arayüz (interface) gibi düşünmek gerektiğini söyledi: veriye arka plandaki sorgunun kendisiyle değil, sorgunun adıyla erişilir. Başka bir öğrenci DTO'ya benzetince hoca bir uyarı yaptı: görünümde veri fiziksel olarak tutulmaz; `insert`, `update`, `delete` gibi işlemler tablonun kendisinde yapılır, görünümde yalnız `SELECT` yapılır.

> **Ders sonrası not:** Hoca görünüm üzerinde `INSERT`, `UPDATE`, `DELETE` yapılamayacağını söyledi. Tek bir tablodan seçilen, toplama, `GROUP BY` ve `DISTINCT` içermeyen basit görünümler çoğu sistemde büyük olasılıkla güncellenebilir; yapılan değişiklik alttaki tabloya yansıtılır.

Dersin sonunda gösterilen slayt, görünümlerin başka görünümlerle tanımlanmasıyla ilgiliydi (ekrandan, 02:45:00): bir görünüm başka bir görünümün tanım ifadesinde kullanılabilir. $v_2$, $v_1$'in tanımında kullanılıyorsa $v_1$, $v_2$'ye **doğrudan bağımlıdır** (depend directly). $v_1$, $v_2$'ye doğrudan bağımlıysa ya da $v_1$'den $v_2$'ye bir bağımlılık yolu varsa $v_1$, $v_2$'ye **bağımlıdır** (depend on). Kendine bağımlı olan görünüme **özyinelemeli** (recursive) denir. Hoca görünümlerle devam edileceğini söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Bölüm ve maaş tablosu şöyledir: Biyoloji 70.000, Bilgisayar 50.000, Fizik 90.000, Biyoloji 30.000, Kimya 60.000. `select ... from instructor where salary > all (select salary from instructor where dept_name = 'Biology')` hangi satırları getirir? `all` yerine `some` yazılırsa ne değişir?

> **Çözüm (derste verildi):** İç sorgu {70.000, 30.000} döndürür. `> all` için 70.000'den büyük olmak gerekir: yalnız Fizik 90.000 gelir. `> some` için 30.000'den büyük olmak yeter: 70.000, 50.000, 90.000 ve 60.000 olmak üzere 4 satır gelir; 30.000 gelmez.

**Soru 2** (ekrandan, 00:10:00): `5 < some {0,5,6}`, `5 < some {0,5}`, `5 = some {0,5}` ve `5 <> some {0,5}` ifadelerinin değerleri nedir? `<> some` ile `not in` denk midir?

> **Çözüm (derste verildi):** Sırasıyla doğru, yanlış, doğru, doğru. `= some` ile `in` denktir; `<> some` ile `not in` denk değildir (`5 <> some {0,5}` doğru, `5 not in {0,5}` yanlış).

**Soru 3** (ekrandan, 00:20:00; derste sözlü, 00:19:56): "2017 Güz ve 2018 Bahar dönemlerinin ikisinde de açılan dersler" sorgusunu `EXISTS` yerine `IN` ile yazın. `S.course_id = T.course_id` koşulu gerekir mi?

> **Çözüm (derste verildi):** `select course_id from section as S where semester = 'Fall' and year = 2017 and course_id in (select course_id from section where semester = 'Spring' and year = 2018);` `IN` zaten ders kimliğinin iç kümede bulunmasını istediği için ayrıca eşitleme gerekmez.

**Soru 4** (derste sözlü, 00:23:37): `EXISTS` sorgusunda `S.course_id = T.course_id` koşulu kaldırılırsa sorgu doğru çalışır mı?

> **Çözüm (derste verildi):** Hayır. İç sorgu yalnız 2018 Baharda açılan bütün dersleri getirir; boş olmadığı sürece `EXISTS` her satır için doğru olur ve 2017 Güzün bütün dersleri listelenir.

**Soru 5** (derste sözlü, 00:32:16): `UNIQUE` örneğinde iç sorgudaki `T.course_id = R.course_id` eşitlemesi yazılmazsa ne olur?

> **Çözüm (derste verildi):** İç sorgu dış satırla eşleşmez, 2017'deki bütün dersleri döndürür (öğrencinin ifadesiyle Kartezyen çarpım gibi olur); sonuç doğru dersleri göstermez.

**Soru 6** (ekrandan, 00:35:00; derste sözlü, 00:40:42): `FROM` içinde alt sorguyla yazılan "ortalama maaşı 42.000'den büyük bölümler" sorgusunu `HAVING` ile yazın. `SELECT`'e `budget` kolonu eklenirse sorgu çalışır mı?

> **Çözüm (derste verildi):** `select dept_name, avg(salary) as avg_salary from instructor group by dept_name having avg(salary) > 42000;` `budget` toplama fonksiyonu içinde olmadığı ve `GROUP BY`'da yer almadığı için sorgu hata verir; kolon `GROUP BY`'a eklenmelidir.

**Soru 7** (ekrandan, 01:10:00; derste sözlü, 01:09:37): `WITH dept_total (dept_name, value) as ...` tanımında parantez içindeki kolon listesi zorunlu mu?

> **Çözüm (derste verildi):** Zorunlu değil; ama `sum(salary)` gibi hesaplanan kolonun bir adı olmalıdır. Kolon listesi yazılmazsa iç sorguda `sum(salary) as value` denir.

**Soru 8** (ekrandan, 01:15:00; derste sözlü, 01:12:54): Bölüm başına hoca sayısını veren skaler alt sorguda `where department.dept_name = instructor.dept_name` koşulu olmasaydı ne olurdu? Hocası olmayan bir bölüm için ne yazılır?

> **Çözüm (derste verildi, düzeltmeyle):** Koşul olmasaydı her bölümün yanına okuldaki toplam hoca sayısı yazılırdı. Hocası olmayan bölüm için de satır gelir; hoca değerin NULL olacağını söyledi, ama `count(*)` boş küme için 0 döndürdüğünden doğru sonuç 0'dır (sqlite3 ile denendi).

**Soru 9** (ekrandan, 01:20:00; derste sözlü, 01:20:32): `delete from instructor where salary < (select avg(salary) from instructor);` sorgusunda satırlar silindikçe ortalama değişir mi?

> **Çözüm (derste verildi):** Hayır. Önce ortalama bir kez hesaplanır ve silinecek satırlar bulunur; sonra bu satırlar ortalama yeniden hesaplanmadan silinir. İç sorgunun sonucu sabit bir değer gibi kullanılır.

**Soru 10** (derste sözlü, 01:33:54): 100.000'den fazla alanlara %3, kalanlara %5 zam iki ayrı `UPDATE` ile yapılıyor. Sıra ters çevrilirse ne olur?

> **Çözüm (derste verildi):** Önce %5 zam yapılırsa bazı hocaların maaşı 100.000'i geçer ve ardından bir de %3 zam alırlar. Çözüm `CASE` ile tek bir `UPDATE` yazmaktır.

**Soru 11** (ekrandan, 01:40:00; derste sözlü, 01:41:53): Dört dallı `CASE` ifadesinde (`<= 30000`, `<= 70000`, `<= 100000`, `else`) çakışma olur mu? `<= 100000` dalı başa yazılırsa ne olur?

> **Çözüm (derste verildi):** Dallar küçükten büyüğe sıralı olduğu için çakışma olmaz; her satır ilk sağladığı dala girer. `<= 100000` başa yazılırsa 100.000'in altındaki herkes o dala girer, diğer iki dal hiç çalışmaz.

**Soru 12** (ekrandan, 02:25:00; derste sözlü, 02:23:01): `student` tablosunda 115, 113, 112, 110; `takes` tablosunda 115 (iki ders), 113, 112 kimlikleri var. Inner join, left outer join ve right outer join kaç satır getirir?

> **Çözüm (derste verildi):** Inner join 4 satır (115 iki kez, 113, 112; 110 gelmez). Left outer join 5 satır (110 da gelir, `takes` kolonları NULL). Right outer join bu veride 4 satır (inner join ile aynı), çünkü `takes`'te olup `student`'ta olmayan kimlik yoktur. Inner ve left sayıları sqlite3 ile doğrulandı.

**Soru 13** (derste sözlü, 01:16:01): `DELETE`, `DROP` ve `TRUNCATE` arasındaki fark nedir? `DELETE`'te kolon yazılır mı?

> **Çözüm (derste verildi):** `DROP` tabloyu şemasıyla siler; `DELETE` koşulu sağlayan satırları siler; `TRUNCATE` tabloyu bırakıp bütün satırları siler. `DELETE` satır satır sildiği için kolon yazılmaz.

## Dersin Toparlaması

Ders, iç içe sorguların karşılaştırma araçlarıyla başladı: `SOME` bir kümenin en az bir elemanıyla, `ALL` bütün elemanlarıyla karşılaştırır; `EXISTS` boş olmama, `UNIQUE` tekrar olmama sınamasıdır. Bu örneklerde en çok vurgulanan nokta, ilişkili alt sorgularda dış ve iç sorgunun eşleştirme koşulunun alt sorgunun içinde yazılması gerektiğiydi. Ardından alt sorguların `FROM` içinde tablo gibi, `SELECT` içinde skaler değer olarak kullanımı ve karmaşık sorguları okunur kılan `WITH` yan cümlesi görüldü. Veri değiştirme kısmında `DELETE`, `INSERT` ve `UPDATE` işlendi; iç sorgunun önce bir kez çalışması, güncelleme sırasının yol açabileceği çift zam sorunu ve bunu çözen `CASE` ifadesi örneklerle anlatıldı.

Son bölümde ileri SQL'e geçildi. Natural join, inner join ve outer join türleri tahtadaki küçük tablolar ve kitaptaki `course`/`prereq` örneğiyle karşılaştırıldı; hoca, okunabilirlik ve güvenlik için birleştirme koşulunun `ON` ile açıkça yazılmasını önerdi. Görünümlerin veri gizleme ve sorgu sadeleştirme için kullanılan, veri tutmayan sanal ilişkiler olduğu anlatıldı ve görünümlerin başka görünümlerle tanımlanmasına giriş yapıldı. Sonraki derste görünümlerle devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
