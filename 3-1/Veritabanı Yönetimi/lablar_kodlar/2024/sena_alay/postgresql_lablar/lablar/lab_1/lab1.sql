CREATE TABLE student (
	student_no int not null primary key,
	firstName VARCHAR(20) not null,
	lastName VARCHAR(20) not null,
	address VARCHAR(255)

);

--tablo silme:
DROP TABLE student;

--tablo adı değiştirme:
ALTER TABLE student RENAME TO öğrenci
ALTER TABLE öğrenci RENAME TO student

--tabloya sütun ekleme:
ALTER TABLE student ADD birthYear char(4);

--tablodan sütun silme:
ALTER TABLE student DROP birthYear;

--tablo sütun adı değiştirme:
ALTER TABLE student RENAME student_no TO stdNo

--tabloya kayıt ekleme:
INSERT INTO student VALUES(134, 'Ali', 'Demir');
INSERT INTO student(stdno, lastname, firstname) VALUES(234, 'Yılmaz','Ahmet')

--kayıt silme:
DELETE FROM student WHERE stdNo=134
DELETE FROM student 

--kayıt güncelleme:
UPDATE student SET firstname='Ayşe'  WHERE stdNo=134

--student tablosunda ismi Ali olan kayıtları siliniz.
DELETE FROM student WHERE firstname='Ali'

--address sütunun ismini 'şehir' olarak değiştirin.
ALTER TABLE student RENAME address  TO şehir

--tablonun tüm satırlarını listele:
SELECT * FROM student

--student tablosundan ad-soyad sütunlarını getir:
SELECT firstname, lastname
FROM student

--ismi Ayşe olan öğrencilerin tüm bilgilerini getirin:
SELECT *
FROM student
WHERE firstname='Ayşe'

--soyadında 'r' harfi geçen kişileri listeleyin:
SELECT *
FROM student
WHERE lastname LIKE '%r%'

--öğrenci numarası 104 ile 289 arasında olan öğrencileri listele:
SELECT *
FROM student
WHERE 104<stdNo AND stdNo<289

--üstteki örnekte sınırları da dahil etmek istersek:
SELECT *
FROM student
WHERE 104<=stdNo AND stdNo<=289

SELECT *
FROM student
WHERE stdNo BETWEEN 104 AND 289

