-- Ders alan öğrencileri aldığı derslerle birlikte 
-- (ders fiyatlarını içererek) listeleyen view tasarımını yapınız.
CREATE OR REPLACE VIEW student_list_with_taken_lessons_view AS
SELECT DISTINCT s.name, s.surname, l.id, t.lesson_id, l.name AS lesson_name, price
FROM Students AS s, Takes AS t, Prices AS p, Lessons l
WHERE s.id = t.student_id AND t.lesson_id = p.lesson_id;

SELECT * 
FROM student_list_with_taken_lessons_view;