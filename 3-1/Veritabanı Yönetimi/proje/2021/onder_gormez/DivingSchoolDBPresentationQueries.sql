SELECT *
FROM lessons;

-- 3. En az bir tabloda silme kısıtı ve sayı kısıtı olmalıdır.
-- lessons tablosundan silindiğinde prices tablosundan da otomatik olarak
-- dersin fiyatı siliniyor.
DELETE
FROM lessons
WHERE id = '32101';
-- 10 Bin TL den büyük değer eklenemiyor.
INSERT INTO Prices VALUES(32110, 10001);

-- 4. Arayüzden en az birer tane INSERT, UPDATE ve DELETE işlemi gerçekleştirilebilmelidir.
INSERT INTO Lessons VALUES(32101, 'Serbest dalı');
INSERT INTO Prices VALUES(32101, 2500);

UPDATE Lessons SET name = 'Serbest dalış' WHERE id = '32101';
UPDATE Prices SET price = '3500' WHERE lesson_id = '32101';

INSERT INTO Lessons VALUES(32222, 'Silinecek');
DELETE FROM Lessons WHERE id = '32222';

-- 5. Arayüzden girilecek bir değere göre ekrana sonuçların listelendiği bir sorgu yazmalısınız.
-- Arayüzde bulunan "Fiyat Tablosundan En Yüksek Kaç Tanesini Getireyim?" kısmı ile yapılmıştır.
SELECT lesson_id, price
FROM Prices
GROUP BY lesson_id, price
ORDER BY price DESC
LIMIT 3;

-- 6. Arayüzden çağrılan sorgulardan en az biri “view” olarak tanımlanmış olmalıdır.
-- Student View butonu ile bu iş gerçekleştirilmiştir.

-- 7. En az bir adet "SEQUENCE" oluşturmalı ve arayüzden yapılacak INSERT sırasında ilgili sütundaki değerlerin otomatik olarak atanmasını sağlamalısınız.
-- Sequence butonu ile bu iş gerçekleştirilmiştir.
DELETE 
FROM Students
WHERE name LIKE 'Name %';

-- 8. Arayüzden çağrılan sorgulardan en az birinde UNION veya INTERSECT veya EXCEPT kullanmış olmalısınız.
-- Fiyatı 5 Bin TL'nin üzerinde olup hiçbir öğrenci tarafından alınmayan derslerin id lerini ve isimlerini bulunuz.
SELECT p.lesson_id, name
FROM Prices p
INNER JOIN lessons l ON p.lesson_id = l.id
WHERE p.price > 5000

EXCEPT

SELECT t.lesson_id, name
FROM Takes t
INNER JOIN lessons l ON t.lesson_id = l.id

-- 9. Sorgularınızın en az biri aggregate fonksiyonlar içermeli, HAVING ifadesi kullanılmalıdır.
SELECT DISTINCT s.id, s.name, p.price, COUNT(s.id)
FROM Students AS s, Takes AS t, Prices AS p
WHERE s.id = t.student_id AND t.lesson_id = p.lesson_id
GROUP BY s.id, s.name, p.price
HAVING price > 3000;

-- 10. Arayüzden girilen değerleri parametre olarak alıp ekrana sonuç döndüren 3 farklı SQL fonksiyonu tanımlamış olmalısınız.
-- Bu fonksiyonlarda en az birer tane "RECORD" ve "CURSOR" tanımı-kullanımı olmalıdır.
-- Arayüzde "Öğrenci Veritabanında Mevcut Mu?" butonu ile çalıştırılabilir.
SELECT is_student_exist('12101');
SELECT is_student_exist('12');
-- Arayüzde "Öğrencinin Ödediği Toplam Miktar" butonu ile çalıştırılabilir.
SELECT get_total_paid_amount('12101');
SELECT get_total_paid_amount('12');
-- Arayüzde "Yıllık Okul Geliri" butonu ile çalıştırılabilir.
SELECT get_annual_revenue();

-- 11. 2 adet trigger tanımlamalı ve arayüzden girilecek değerlerle tetiklemelisiniz. Trigger’ın
-- çalıştığına dair arayüze bilgilendirme mesajı döndürülmelidir.
INSERT INTO Students VALUES(NEXTVAL('AutoIncrementStudentNumberSeq'), 'Hayati', 'Taştekin', 'Sultangazi', '19 August 2003');
DELETE FROM Students WHERE id = '12190';