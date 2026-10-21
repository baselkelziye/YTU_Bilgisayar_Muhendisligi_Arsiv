--sql lab 7 plpgsql, alias, record/cursor ve trigger tanımlar
CREATE or REPLACE FUNCTION ornek1(num1 NUMERIC, num2 NUMERIC)
RETURNS NUMERIC AS $$ 
DECLARE
toplam NUMERIC;
BEGIN
toplam := num1+num2;
RAISE NOTICE 'sayi1:%, sayi2:%', num1, num2;
RETURN toplam;
END;
$$ LANGUAGE 'plpgsql';

select ornek1(20,30);


CREATE or REPLACE FUNCTION ornek1(num1 NUMERIC, num2 NUMERIC)
RETURNS NUMERIC AS $$ 
DECLARE
	toplam NUMERIC;
BEGIN
	toplam := num1+num2;
RAISE EXCEPTION 'sayi1:%, sayi2:%', num1, num2;
RETURN 
	toplam;
END;
$$ LANGUAGE 'plpgsql';

select ornek1(20,30);

--ssni parmetre olarak verilen çalışanın ismini departmanınn ismini ve maaşını döndüren fonksiyon
CREATE TYPE yeni_tur AS (isim VARCHAR(15), dep_isim VARCHAR(25), maas INTEGER);

CREATE or REPLACE FUNCTION ornek2(eno employee.ssn%type)
RETURNS yeni_tur AS $$
DECLARE 
	bilgi yeni_tur;
BEGIN 
	SELECT fname, dname, salary INTO bilgi
	FROM employee e, department d
	WHERE e.dno=d.dnumber AND e.ssn=eno;

	RAISE NOTICE 'calisan ismi:%, departmaninin ismi:%, maasi:%tldir.',bilgi.isim, 
	bilgi.dep_isim, bilgi.maas;
	RETURN bilgi;
END;
$$ LANGUAGE 'plpgsql';
SELECT ornek2('123456789');
DROP FUNCTION ornek2(employee.ssn%type);

--numarası verilen bir departmandaki çalışanların isimlerini bulan bir fonksiyon yazınızç bir departman numarası vererek fonksiyonu çağırınız
CREATE or REPLACE FUNCTION ornek3(dnum NUMERIC)
RETURNS VOID AS $$
DECLARE
	yeni_cur CURSOR FOR SELECT fname, lname
						FROM employee
						WHERE dno=dnum;
BEGIN
	FOR satir IN yeni_cur LOOP
		RAISE INFO 'Employee name is % %', satir.fname, satir.lname;
	END LOOP;
END;
$$ LANGUAGE 'plpgsql';

SELECT ornek3(6);
DROP FUNCTION ornek3(numeric);

--departman numarası verilen bir departmandaki çalışanların toplam maaşını(sum() fonks kullanmadan) bulan bir fonks
CREATE FUNCTION ornek4(dnum NUMERIC)
RETURNS NUMERIC AS $$
DECLARE 	
	toplam_maas NUMERIC;
	curs CURSOR FOR SELECT salary FROM employee WHERE dno=dnum;
BEGIN 
	toplam_maas:=0;
	FOR satir IN curs LOOP
		toplam_maas:= toplam_maas + satir.salary;
	END LOOP;
	RETURN toplam_maas;
END;
$$ LANGUAGE 'plpgsql';

SELECT ornek4(6);
DROP FUNCTION ornek4(numeric);

--departman numarası verilen bir departmandaki çalışanların toplam maaşını sum() fonks yararlanmadan bulan ve 
--OUT değişkeni üzerinden geri döndüren bir fonks yazınız
CREATE OR REPLACE FUNCTION dep_sum_salary(dnum numeric, OUT sum_sal numeric)
AS '
DECLARE
	emp_cursor CURSOR FOR SELECT salary FROM employee WHERE dno=dnum;
BEGIN
	sum_sal:=0;
	FOR emp_record IN emp_cursor LOOP
			sum_sal:=sum_sal + emp_record.salary;
	END LOOP;
END;
' LANGUAGE 'plpgsql';

SELECT dep_sum_salary(6);
DROP FUNCTION dep_sum_salay(numeric);

--örnek5 numarasi verilen projede çalışanların maaşları verilen bir değere tam bölünüyorsa o
--kişilerin ad soyad ve maaş bilgilerini having kullanmadan geri döndüren fonksiyonu yazınız
CREATE TYPE calisan AS(isim VARCHAR(15), soyisim VARCHAR(15), maas INTEGER);
CREATE OR REPLACE FUNCTION calisan_listele(pnum project.pnumber%TYPE, bolen INTEGER)
RETURNS calisan[] AS $$
DECLARE 
	emp_cursor CURSOR FOR SELECT fname,lname, salary FROM employee, works_on WHERE ssn=essn AND pno=pnum;
	cal calisan[];
	i integer;
BEGIN
	i:=1;
	FOR emp_record IN emp_cursor LOOP
		IF emp_record.salary%bolen=0 THEN
			 cal[i]=emp_record;
			 i:=i+1;
		END IF;
	END LOOP;
RETURN cal;
END;
$$ LANGUAGE 'plpgsql';
SELECT calisan_listele('61',16);
DROP FUNCTION calisan_listele(project.pnumber%TYPE, integer);
			

--trigger örnek 6
--sadece tatil günleri dışında ve mesai saatleri içinde employee tablosuna insert yapılmasına izin veren trigger
CREATE TRIGGER t_ornek_6
BEFORE INSERT
ON EMPLOYEE
FOR EACH ROW EXECUTE PROCEDURE trig_fonks_ornek6();

CREATE FUNCTION trig_fonks_ornek6()
RETURNS TRIGGER AS $$
BEGIN
	IF (to_char(now(),'DY') in ('SAT', 'SUN') OR to_char(now(), 'HH24')) not between '08' and '18' THEN
		RAISE EXCEPTION 'sadece mesai gunlerinde ve mesai saatlerinde insert yapabilirsiniz';
		RETURN NULL;
	ELSE 
		RETURN NEW;
	END IF;
END;
$$ LANGUAGE 'plpgsql';

--triggerlanması cartı curtu
INSERT INTO employee VALUES('Vlademir', 'S',)
--silmek
--1
DROP TRIGGER t_ornek6 on employee;
--2
DROP FUNCTION trig_fonks_ornek6();

--örnek 7
--departman tablosunda dnumber kolonundaki değer değişince employee tablosundaki dnonun da aynı şekilde değişmesini 
--sağlayan triggerı yaz
--öncelikle departman tablosundaki yabancı anahtar olma kısıtlaırnı kaldırmalıyız, departmandaki dnumber kolonuna referans veren 3 tablo var
ALTER TABLE project DROP CONSTRAINT project_dnum_fkey;
ALTER TABLE dept_locations DROP CONSTRAINT dept_locations_dnumber_fkey;
ALTER TABLE employee DROP CONSTRAINT foreign_key_const;

CREATE TRIGGER t_ornek7
AFTER UPDATE
ON department
FOR EACH ROW EXECUTE PROCEDURE trig_fonk_ornek7();

CREATE FUNCTION trig_fonk_ornek7()
RETURNS TRIGGER AS $$
BEGIN
	UPDATE employee
	SET dno=new.dnumber;
	WHERE dno=old.dnumber;
	RETURN new;
END;
$$ LANGUAGE 'plpgsql';
--triggerlanması
UPDATE department SET dnumber=2 WHERE dnumber=5;
--silinmesi
--1
DROP TRIGGER t_ornek7 on department
--2
DROP FUNCTION trig_fonk_ornek7();

--orn8 maaş inişine ve %10dan fazla maaş artışına izin vermeyen trigger
CREATE TRIGGER t_ornek8
BEFORE UPDATE
ON employee
FOR EACH ROW EXECUTE PROCEDURE trig_fonk_ornek8();

CREATE FUNCTION trig_fonk_ornek8()
RETURNS TRIGGER AS $$ 
BEGIN
	IF (old.salary > new.salary OR new.salary > 1.1*old.salary) THEN
		RAISE EXCEPTION 'maasi dusuremezsiniz ve %%10dan fazla zam yapamazsiniz';
		RETURN old;
	ELSE
		RETURN new;
	END IF;
END;
$$ LANGUAGE 'plpgsql';

--triggerlanması 
UPDATE employee SET salary=salary*1.12 ;
--where koşulu vermeyince tüm satırları updatelemeye çalışıyodu
--silinmesi
--1
DROP TRIGGER t_ornek8 ON employee;
--2
DROP FUNCTION trig_fonk_ornek8();

--orn9 departman tablosuna salary ile aynı tipte total_salary kolonu ekle. employee tablosunda maaş sütununda değişiklik
--olunca department tablosundaki total_salary kolonunagerekli güncellemeyi yapıcak triggerı yaz
ALTER TABLE department ADD COLUMN total_salary INTEGER default=0;
UPDATE department SET total_salary = (SELECT SUM (salary) FROM employee WHERE dno=dnumber);
--yazılacak triggerda insert update delete hangisi veyahangileri olmalı HEPSİ
CREATE TRIGGER t_ornek9
AFTER INSERT OR DELETE OR UPDATE
ON employee
FOR EACH ROW EXECUTE PROCEDURE trig_fonk_ornek9();

CREATE FUNCTION trig_fonk_ornek9()
RETURNS TRIGGER AS $$
BEGIN
	IF (TG_OP = 'DELETE') THEN
		update department
		set total_salary=total_salary-old.salary
		where dnumber= old.dnumber;
	ELSIF (TG_OP = 'UPDATE') THEN
		update department
		set total_salary=total_salary-old.salary+new.salary
		where dnumber=old.dnumber;
	ELSE 
		update department
		set	 total_salary= total_salary + new.salary
		where dnumber=new.dnumber;
	END IF;
	RETURN new;
END;
$$ LANGUAGE 'plpgsql';

--triggerlanması
INSERT INTO employee VALUES (...)
UPDATE employee SET salary=salary*1.07 WHERE dno=1
DELETE FROM employee WHERE ssn='11111103';
--------------------------------- QUIZ 3 SORULARI -------------------------------
--soru: Departmanlardaki erkek çalışanların sayısının kadın çalışanların sayısından fazla olmasını engelleyen
--trigger'ı, trigger fonksiyonunu ve en az 1 tane tetikleyen ifadeyi yazınız (35P).
-- Tetikleyici fonksiyonunu oluşturma
CREATE OR REPLACE FUNCTION check_male_female_ratio() 
RETURNS TRIGGER AS $$
DECLARE
    male_count INTEGER;
    female_count INTEGER;
BEGIN
    -- Erkek çalışanların sayısını hesapla
    SELECT COUNT(*) INTO male_count
    FROM employee
    WHERE sex = 'M';

    -- Kadın çalışanların sayısını hesapla
    SELECT COUNT(*) INTO female_count
    FROM employee
    WHERE sex = 'F';

    -- Eğer erkek çalışan sayısı kadın çalışan sayısından fazlaysa işlemi geri al
    IF male_count > female_count THEN
        RAISE EXCEPTION 'Department cannot have more male employees than female employees';
		RETURN NULL;
	ELSE
		RETURN NEW;
    END IF;
END;
$$ LANGUAGE 'plpgsql';

-- Tetikleyiciyi oluşturma
CREATE TRIGGER prevent_male_excess
BEFORE INSERT OR UPDATE OR DELETE ON employee
FOR EACH ROW
EXECUTE FUNCTION check_male_female_ratio();

-- Tetikleyiciyi manuel olarak tetikleme
-- Örnek bir veri ekleme işlemi
INSERT INTO employee VALUES 
('Elif', 'A', 'Yılmaz', '777777777', '01-JAN-1990', '123 Avenue, City, Country', 'F', 60000, null, 5);
-- Tetikleyiciyi çalıştıracak bir örnek
-- Yeni bir çalışan ekleme
INSERT INTO employee VALUES ('Mehmet', 'K', 'Yılmaz', '888888888', '01-JAN-1995', '456 Street, City, Country', 'M', 55000, null, 5);

-- Tetikleyiciyi çalıştıracak bir örnek (UPDATE ifadesi)
UPDATE employee
SET sex = 'F' -- Örnek olarak cinsiyet bilgisini güncelliyoruz
WHERE ssn = '777777777'; -- Güncellenecek çalışanın SSN (Sosyal Güvenlik Numarası)
 

--soru: İsimleri verilen 2 farklı projede çalışanların SSN numaralarını ve isimlerini tekil olarak döndüren
--UNION_OZEL isimli PL/pgSQL fonksiyonunu yazınız (35P).
-- İstenilen fonksiyon UNION ifadesi görevini yapmalıdır (Yani UNION ve/veya INTERSECT ifadesi kullanılMAmalıdır).
--CURSOR'ların içerisinde OR ifadesi veya iç içe sorgu kullanılmamalıdır.
CREATE OR REPLACE FUNCTION UNION_OZEL(dnum NUMERIC)
RETURNS VOID AS $$
DECLARE
    emp_record RECORD;
    emp_name VARCHAR;
BEGIN
    FOR emp_record IN SELECT e.fname || ' ' || e.lname AS fullname
                      FROM employee e
                      JOIN works_on wo ON e.ssn = wo.essn
                      WHERE wo.pno IN (SELECT pnumber FROM project WHERE dnum = dnum)
                      GROUP BY e.ssn, fullname
    LOOP
        emp_name := emp_record.fullname;
        RAISE INFO 'Employee name is %', emp_name;
    END LOOP;
END;
$$ LANGUAGE plpgsql;

SELECT UNION_OZEL(5); -- 5 yerine istediğiniz departman numarasını geçebilirsiniz
