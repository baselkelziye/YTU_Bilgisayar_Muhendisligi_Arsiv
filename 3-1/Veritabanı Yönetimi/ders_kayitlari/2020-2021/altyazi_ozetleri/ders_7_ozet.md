# Ders 7 - İlişkisel Cebir ve SQL'e Giriş

## Genel Konular
- İlişkisel cebirde join (birleştirme) işlemleri
- SQL dili ve temel yapısı
- CASE-ifadesi ile koşullu sorgulama
- FULL OUTER JOIN ve NULL değerlerle çalışma
- NOT IN ile NULL tuzakları
- NATURAL JOIN ve ortak sütun eşleştirme

## Hocanın Özellikle Vurguladığı Kısımlar
- SQL bir programlama dili değil, sorgulama dilidir
- NOT IN ile NULL kullanırken dikkatli olunmalı (sonuç kümesi boş dönebilir)
- NATURAL JOIN'de ortak sütunlar otomatik eşleşir, isim vermek gerekmez
- Cross product (carpma) kontrolsüz büyüklükte sonuç kümesi üretir, dikkatli kullanılmalıdır
- FULL OUTER JOIN'de eşleşmeyen satırlarda NULL değerler oluşur

## Kısa Tekrar Notları
- **Inner Join**: Sadece her iki tabloda eşleşen satırları döndürür
- **Left Outer Join**: Sol tablodaki tüm satırları, sağda eşleşme yoksa NULL ile döndürür
- **Right Outer Join**: Sağ tablodaki tüm satırları, solda eşleşme yoksa NULL ile döndürür
- **Full Outer Join**: Her iki tablodaki tüm satırları döndürür, eşleşme olmayan yerlerde NULL
- **Semijoin (▷)**: Sadece sol tablodaki satırları, sağda eşleşme varsa döndürür (ilişkisel cebirde ∃quantifier ile)
- **Antijoin (▷̸)**: Sadece sol tablodaki satırları, sağda eşleşme yoksa döndürür (ilişkisel cebirde ∀quantifier ile)

## Detaylı Açıklamalar

### İlişkisel Cebir Join İşlemleri
- **Inner Join (Birleştirme)**: R ve S tablolarının ortak alanları üzerinden eşleşme yapılır, sadece eşleşen satırlar sonuç kümesine dahil edilir
- **Left Outer Join (Sol Dış Birleştirme)**: R tablosundaki tüm satırlar korunur, S tablosunda eşleşme yoksa ilgili sütunlara NULL yazılır
- **Right Outer Join (Sağ Dış Birleştirme)**: S tablosundaki tüm satırlar korunur, R tablosunda eşleşme yoksa NULL yazılır
- **Full Outer Join (Tam Dış Birleştirme)**: Her iki tablodaki tüm satırlar korunur, eşleşmeyen tüm sütunlarda NULL değerler oluşur
- **Semijoin**: R tablosundaki satırların S tablosunda en az bir karşılığı varsa o satırları döndürür (ilişkisel cebirde ∃quantifier kullanılır)
- **Antijoin**: R tablosundaki satırların S tablosunda hiçbir karşılığı yoksa o satırları döndürür (ilişkisel cebirde ∀quantifier kullanılır)
- **Cross Product (Cartesian Product)**: İki tablonun her satırı birbiriyle eşleştirilir, sonuç kümesi R × S boyutunda olur (dikkatsiz kullanımda çok büyük sonuç üretir)

### SQL'e Giriş
- SQL (Structured Query Language), veritabanlarında veri sorgulama ve manipülasyon dili
- Programlama dili değildir; döngü, koşul gibi yapıları desteklemez (yerine JOIN, WHERE, HAVING gibi mekanizmalar kullanılır)
- Temel yapı: `SELECT` → hangi sütunları istediğimizi, `FROM` → hangi tablodan, `WHERE` → hangi koşullara göre sorgulama yapılacağını belirtir

### CASE İfadesi (Koşullu Sorgulama)
- SQL'de koşullu mantık��作ları için `CASE WHEN ... THEN ... ELSE ... END` yapısı kullanılır
- Örnek: `CASE WHEN Maas > 5000 THEN 'Yüksek' WHEN Maas > 3000 THEN 'Orta' ELSE 'Düşük' END`
- Tablodaki her satır için koşullar sırasıyla kontrol edilir, ilk eşleşen değer döndürülür
- WHERE bloğu içinde de kullanılabilir (örneğin: `WHERE durum = 'AKTİF'` yerine `WHERE CASE WHEN tarih < CURRENT_DATE THEN 'GEÇMİŞ' ELSE 'GELECEK' END = 'GEÇMİŞ'`)

### FULL OUTER JOIN ve NULL Değerler
- FULL OUTER JOIN, sol ve sağ tabloların tüm satırlarını korur
- Eşleşmeyen satırlarda NULL değerler oluşur (sol veya sağ tarafta karşılık yoksa)
- Örnek: A tablosunda (1,2,3), B tablosunda (2,3,4) varsa → FULL OUTER JOIN sonucu: (1,NULL), (2,2), (3,3), (NULL,4)
- NULL değerlerle karşılaştırma yaparken `=` operatörü çalışmaz; `IS NULL` veya `IS NOT NULL` kullanılmalıdır

### NOT IN ile NULL Tuzakları
- `NOT IN` ifadesi, belirtilen değer listesinde olmayan satırları döndürür
- Ancak değer listesinde NULL varsa, sonuç kümesi boş döner (hiçbir satır seçilmez)
- Neden: `NULL = NULL` sonucu `UNKNOWN` döndürür, bu yüzden `NOT IN` ile hiçbir satır eşleşmez
- Çözüm: `NOT EXISTS` veya `LEFT JOIN ... WHERE S.sütun IS NULL` kullanımı tercih edilmelidir
- Örnek: `SELECT * FROM R WHERE R.id NOT IN (SELECT id FROM S)` → S tablosunda id sütununda NULL varsa boş sonuç döner

### NATURAL JOIN
- NATURAL JOIN, iki tabloda aynı isimli sütunları otomatik olarak eşleştirir
- Eşleştirme koşulunu elle yazmaya gerek yoktur (ON bloğu gereksiz)
- Örnek: `SELECT * FROM R NATURAL JOIN S` → R ve S tablolarında ortak olan tüm sütunlar üzerinden eşleşme yapılır
- Dezavantaj: Eğer tablolarda aynı isimde sütun var ama anlamları farklıysa yanlış eşleştirme yapabilir
- Dikkat: Eşleşme sadece sütun isimlerine göre yapılır, veri türleri kontrol edilmez (hatalı eşleşme riski taşır)

### SQL'in Temel Yapı Taşları
- **SELECT**: Sorgulanacak sütunları belirtir (SELECT * → tüm sütunlar)
- **FROM**: Sorgulanacak tabloyu veya tabloları belirtir
- **WHERE**: Satır filtresi yapar (koşul satır bazında uygulanır)
- **GROUP BY**: Belirli sütunlara göre gruplama yapar (toplama fonksiyonları ile birlikte kullanılır)
- **HAVING**: Gruplama sonrası filtreleme yapar (WHERE gibi çalışır ama grup bazında)
- **ORDER BY**: Sonuç kümesini belirli sütuna göre sıralar (ASC/DESC ile artan/azalan)
