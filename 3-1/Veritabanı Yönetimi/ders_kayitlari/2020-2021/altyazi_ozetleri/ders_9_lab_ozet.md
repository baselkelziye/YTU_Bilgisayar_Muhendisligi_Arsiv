# Ders 9 Lab Çalışma Özeti

## Genel Konular

- PL/pgSQL ile Veritabanı Fonksiyon Tanımlama
  - PostgreSQL'de tanımlı 4 prosedürel dil bulunur; bu derste PL/pgSQL kullanılır
  - Fonksiyonlar: karmaşık sorgulama, hesaplama, koşullu işlemler ve tekrarlı işler için kullanılır
  - Programlama dillerindeki fonksiyon mantığıyla aynıdır (parametre alma, dönüş değeri, koşullar, döngüler)

- Fonksiyon Tanımlama Sözdizimi
  - `CREATE FUNCTION` veya `CREATE OR REPLACE FUNCTION` ile başlanır
  - Fonksiyon adından sonra parantez içinde parametreler tanımlanır
  - Parametrelerde önce isim, sonra tip yazılır (diğer dillerden tersi)
  - `RETURNS` veya `OUT` ile dönüş tipi belirtilir (ikisi seçmeli, biri kullanılır)
  - `AS` sonrasında tek tırnak (`'`) veya çift dolar (`$$`) ile gövde açılır
  - `DECLARE` kısmında değişken tanımlamaları yapılır
  - `BEGIN` ve `END` arasında ana gövde yazılır
  - `RETURN` ile değer döndürülür; `RETURN void` ile değer dönmez
  - Fonksiyon sonunda `LANGUAGE plpgsql` belirtilir

- `CREATE OR REPLACE FUNCTION` Kullanımı
  - Aynı isimde fonksiyon tekrar tanımlandığında hata vermek yerine günceller
  - Geliştirme sürecinde fonksiyon içeriği sık değişebileceği için bu yazım tercih edilir

- Değişken Tanımlama (DECLARE)
  - `değişken_adı tip := değer;` şeklinde tanımlanır
  - İlk değer verilmezse sadece `değişken_adı tip;` yazılır
  - `%TYPE` ile bir tablonun sütununun tipi referans alınabilir: `employee.salary%TYPE`
  - Bu yaklaşım, tablo yapısı değiştiğinde fonksiyonun otomatik uyum sağlamasını sağlar

- Dönüş Değerleri
  - `RETURN` anahtar sözcüğüyle tek bir değer döndürülür
  - `OUT` parametresi ile birden fazla çıkış değeri verilebilir
  - Dönüş tek tip veri, birleşik veri (tablo), satır/sütun veya pointer olabilir
  - `RETURN void` ile hiçbir şey dönülmez

- Fonksiyon Çağırma ve Silme
  - Çağırma: `SELECT fonksiyon_adı(parametre1, parametre2);`
  - Silme: `DROP FUNCTION fonksiyon_adı(parametre_tipi1, parametre_tipi2);`

## Hocanın Özellikle Vurguladığı Kısımlar

- Parametrelerin isim önce, tip sonra yazılması gerektiği
  - Diğer programlama dillerinde `int number` yazılırken, PL/pgSQL'de `number int` yazılır
- `CREATE OR REPLACE FUNCTION` kullanımının fonksiyon tanımlamada tercih edilmesi
  - Her seferinde hata almamak ve fonksiyonu güncelleyerek kullanmak için
- Fonksiyon gövdesinin `BEGIN...END` arasında yer aldığı
  - Değişken tanımlamalarının `DECLARE` bloğunda yapılması
- `OUT` ve `RETURNS`'un birbirinin alternatifi olduğu
  - İkisi birden kullanılmaz; biri tercih edilir
- Karmaşık soruların adım adım çözülmesi gerektiği
  - Her adımda bir sorgu yazıp sonucu bir değişkene atama, ardından koşul kontrolü
- For döngüsünde `REVERSE` ile ters yönde, `BY` ile özel artış/azalış belirtilebileceği
- While ve for döngülerinin her zaman `END LOOP` ile kapatılması gerektiği

## Kısa Tekrar Notları

- `CREATE OR REPLACE FUNCTION`: fonksiyon oluştur veya güncelle
- Parametre tanımlama: `isim tip` (örn: `depname department.dname%TYPE`)
- Dönüş belirtme: `RETURNS tip` veya `OUT parametre tip`
- Değişken tanımlama: `DECLARE` bloğunda `isim tip := değer;`
- `%TYPE`: bir tablo sütununun tipini referans alma
- `BEGIN...END`: fonksiyon gövdesi
- `RETURN`: değer döndürme; `RETURN void`: değer dönmemesi
- `IF...THEN...ELSIF...ELSE...END IF`: koşullu ifadeler
- `CASE...WHEN...THEN...ELSE...END CASE`: çoklu durum kontrolü
- `WHILE koşul LOOP...END LOOP`: koşul sağlanana kadar tekrar
- `FOR değişken IN başlangıç..bitiş LOOP...END LOOP`: belirli aralıkta tekrar
- `FOR...IN...REVERSE`: tersten sayma
- `FOR...IN...BY`: özel artış/azalış miktarı
- `RAISE NOTICE`: ekrana bilgilendirme mesajı yazdırma
- `DROP FUNCTION fonksiyon_adı(tip1, tip2);`: fonksiyon silme

## Detaylı Açıklamalar

- **Temel Fonksiyon Örneği (İki Sayının Toplamı):**
  - Kullanıcıdan iki adet numarik parametre alınır
  - `DECLARE` bloğunda `toplam` değişkeni tanımlanır
  - `BEGIN` bloğunda `toplam := num1 + num2` işlemi yapılır
  - `RETURN toplam` ile sonuç döndürülür
  - Çağırma: `SELECT ornek1(3, 5);` → sonuç: 8

- **`OUT` Parametresi ile Çoklu Çıkış:**
  - Department tablosunda min ve max departman numaralarını bulma
  - Kullanıcıdan parametre alınmaz; `OUT min_depno` ve `OUT max_depno` tanımlanır
  - `BEGIN` içinde tek tabloda `SELECT MIN(deptno), MAX(deptno) INTO min_depno, max_depno FROM department;`
  - Çağırma: `SELECT ornek2();` (parantez içi boş因為 parametre almaz)

- **Koşullu İşlem (IF/THEN):**
  - `void` dönüşlü fonksiyonda 6 numaralı departmanda çalışan sayısı bulunur
  - `SELECT COUNT(*) INTO non_worker FROM employee WHERE deptno = 6;`
  - `IF non_worker < 2 THEN UPDATE employee SET salary = salary * 1.05 WHERE deptno = 6; END IF;`
  - Koşul sağlanırsa maaşlara %5 zam yapılır
  - `ELSIF` ile birden fazla koşul zinciri kurulabilir

- **CASE İfadesi:**
  - `CASE değişken WHEN durum1 THEN ... WHEN durum2 THEN ... ELSE ... END CASE;`
  - Bir değişkenin değerine göre farklı işlemler yapılır
  - `ELSE` dalı, hiçbir `WHEN` koşulu sağlanmazsa çalışır

- **WHILE Döngüsü:**
  - `WHILE koşul LOOP ... END LOOP;`
  - Koşul sağlandığı sürece blogun içindeki işlemler tekrar eder
  - `RAISE NOTICE` ile ekrana mesaj yazdırılabilir

- **FOR Döngüsü:**
  - `FOR değişken IN başlangıç..bitiş LOOP ... END LOOP;`
  - `REVERSE` ile ters yönde: `FOR x IN REVERSE 5..1 LOOP`
  - `BY` ile özel artış: `FOR x IN 1..10 BY 2 LOOP`
  - Döngü sayısı, verilen aralıktaki eleman sayısına eşittir

- **Karmaşık Koşullu Zam Örneği:**
  - 4 parametre alınır: departman adı, ortalama maaş eşiği, kadın maaş toplamı eşiği, zam oranı
  - Departman adından departman numarası bulunur (`department.dname%TYPE` referansı ile)
  - Ortalama maaş hesaplanır ve eşik değerle karşılaştırılır
  - Kadın çalışanların toplam maaşı hesaplanır ve ikinci eşikle karşılaştırılır
  - Her iki koşul da sağlanırsa, o departmanda birden fazla projede çalışanların maaşlarına zam yapılır
  - Birden fazla projede çalışanlar: `works_on` tablosunda `GROUP BY essn HAVING COUNT(*) > 1` ile bulunur
  - `UPDATE employee SET salary = salary * (1 + zam_orani) WHERE essn IN (alt sorgu)` ile güncelleme yapılır

- **Trigger Konusuna Geçiş:**
  - Trigger'lar bir sonraki derste işlenecektir
  - Proje dokümanında fonksiyon ve trigger istendiği belirtilmiştir

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
