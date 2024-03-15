-- Hangi öğrencinin hangi dersi aldığını bulan SQL sorgusunu yazınız.
SELECT DISTINCT s.id AS student_id, s.name AS student_name, s.surname AS student_surname, t.lesson_id, l.name AS lesson_name
FROM Students AS s, Takes AS t, Lessons AS l
WHERE s.id = t.student_id AND t.lesson_id = l.id
ORDER BY s.id, lesson_id;

-- Hangi öğrencinin hangi dersi kimden aldığını bulan sorguyu yazınız.
SELECT DISTINCT s.id AS student_id, s.name AS student_name, s.surname AS student_surname
              , l.id AS lesson_id, l.name AS lesson_name
              , teach.id AS teacher_id, teach.name AS teacher_name, teach.surname AS teacher_surname 
FROM Students AS s, Takes AS t, Lessons AS l, Teachers AS teach
WHERE s.id = t.student_id AND t.lesson_id = l.id AND t.teacher_id = teach.id
ORDER BY student_id;

-- Kişinin dalış okuluna toplam ödediği tutarı bulan sorguyu yazınız.
SELECT DISTINCT s.id AS student_id, s.name AS student_name, s.surname AS student_surname
                  , SUM(price) AS total_paid
FROM Students AS s, Takes AS t, Prices AS p
WHERE s.id = t.student_id AND t.lesson_id = p.lesson_id AND student_id = '12101'
GROUP BY s.id, s.name, s.surname;

-- Öğrencinin aldığı dersleri ve fiyatlarını listeleyen sorguyu yazınız.
SELECT DISTINCT s.id AS student_id, s.name AS student_name, s.surname AS student_surname
                  , l.id AS lesson_id, l.name AS lesson_name
                  , price
FROM Students AS s, Takes AS t, Lessons AS l, Prices AS p
WHERE s.id = t.student_id AND t.lesson_id = l.id AND l.id = p.lesson_id AND student_id = '12101';

-- Öğrencilerin yüzme okuluna ortalama ne kadar para verdiğini bulan fonksiyonu yazınız.
-- Yukarıda yazan fonksiyon tüm öğrenciler için çalıştırılır.
-- Sonrasında ortalama işlemine sokulur.

-- Bir öğrenci 1 dersi sadece 1 hocadan alabilir. 2 kere database e eklenmeye çalışılırsa hata 
-- verecek bir yapı oluşturulmalıdır. Constraints tanımlanabilir.

-- Hangi öğrencinin hangi dersi aldığını ve fiyatlarını görüntüleyen SQL sorgusunu yazınız.
SELECT DISTINCT s.id AS student_id, s.name AS student_name, s.surname AS student_surname
              , l.id AS lesson_id, l.name AS lesson_name
			  , price
FROM Students AS s, Takes AS t, Lessons AS l, Prices AS p
WHERE s.id = t.student_id AND t.lesson_id = l.id AND l.id = p.lesson_id
ORDER BY student_id;

-- Hangi öğrencinin hangi dersi aldığını ve fiyatlarını görüntüleyen bir view tasarımı yapınız.

-- Hangi dersin fiyatının ne kadar olduğunu yazdıran SQL sorgusunu yazınız.
SELECT DISTINCT ON(l.id) l.id AS lesson_id, l.name AS lesson_name, price AS lesson_price
FROM Lessons l , Prices p
WHERE  l.id = p.lesson_id
ORDER BY l.id;