--çıkmışlar
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
CREATE OR REPLACE FUNCTION UNION_OZEL(project1_name VARCHAR, project2_name VARCHAR)
RETURNS TABLE(ssn CHAR(9), fname VARCHAR) AS $$
DECLARE
    cur1 CURSOR FOR 
        SELECT DISTINCT E.SSN, E.FName 
        FROM Employee E
        JOIN Works_On W ON E.SSN = W.ESSN
        JOIN Project P ON W.PNO = P.PNumber
        WHERE P.PName = project1_name;

    cur2 CURSOR FOR 
        SELECT DISTINCT E.SSN, E.FName 
        FROM Employee E
        JOIN Works_On W ON E.SSN = W.ESSN
        JOIN Project P ON W.PNO = P.PNumber
        WHERE P.PName = project2_name;

    record1 RECORD;
    record2 RECORD;
    found BOOLEAN;
BEGIN
    OPEN cur1;
    LOOP
        FETCH cur1 INTO record1;
        EXIT WHEN NOT FOUND;
        found := FALSE;
        FOR record2 IN cur2 LOOP
            IF record1.ssn = record2.ssn THEN
                found := TRUE;
                EXIT;
            END IF;
        END LOOP;
        IF NOT found THEN
            ssn := record1.ssn;
            fname := record1.fname;
            RETURN NEXT;
        END IF;
    END LOOP;
    CLOSE cur1;

    OPEN cur2;
    LOOP
        FETCH cur2 INTO record2;
        EXIT WHEN NOT FOUND;
        ssn := record2.ssn;
        fname := record2.fname;
        RETURN NEXT;
    END LOOP;
    CLOSE cur2;
END;
$$ LANGUAGE plpgsql;

select UNION_OZEL('OperatingSystems','Middleware');

--İsmi verilen projede çalışanlar arasından, o projede çalışanların ortalama maaşından daha yüksek maaşı
-- olanlardan, en düşük maaşı olan çalışanın akrabalarından en gencinin ismini bulan PL/pgSQL fonksiyonunu yazınız (40 Puan).
CREATE OR REPLACE FUNCTION yakin_bul(pro_isim project.pname%TYPE) RETURNS dependent.dependent_name%TYPE
AS $$
DECLARE
ort_maas real;
en_dusuk employee.salary%TYPE;
calisan employee.ssn%TYPE;
yakin dependent.dependent_name%TYPE;
BEGIN
SELECT AVG(salary) INTO ort_maas FROM employee, works_on, project WHERE essn = ssn AND pno = pnumber
AND pname = pro_isim;
SELECT MIN(salary) INTO en_dusuk FROM employee, works_on, project WHERE essn = ssn AND pno = pnumber
AND pname = pro_isim AND salary > ort_maas;
SELECT ssn INTO calisan FROM employee, works_on, project WHERE essn = ssn AND pno = pnumber AND pname
= pro_isim AND salary = en_dusuk;
SELECT dependent_name INTO yakin FROM dependent WHERE essn = calisan ORDER BY bdate DESC;
RETURN yakin;
END;
$$ LANGUAGE plpgsql;
SELECT yakin_bul('ProductZ');

--Şirketin en yüksek maaş ortalamalı 2 departmanı arasındaki ortalama yaş farkının kaç olduğunu bulan PL/pgSQL
--sorgusunu yazınız (30 Puan).
CREATE OR REPLACE FUNCTION department_ort_maas() 
RETURNS real AS $$
DECLARE
en_yuksek_ort real;
ikinci_yuksek_ort real;
fark real;
en_yuk_dep department.dname%TYPE;
BEGIN
SELECT dname, AVG(salary) INTO en_yuk_dep, en_yuksek_ort FROM employee, department WHERE dno =
dnumber GROUP BY dname ORDER BY AVG(salary) DESC LIMIT 1;
SELECT AVG(salary) INTO ikinci_yuksek_ort FROM employee, department WHERE dno = dnumber AND dname
<> en_yuk_dep GROUP BY dname ORDER BY AVG(salary) DESC LIMIT 1;
fark := en_yuksek_ort - ikinci_yuksek_ort;
RETURN fark;
END;
$$ LANGUAGE plpgsql;
SELECT department_ort_maas();

--İsmi verilen departmanda çalışanların ortalama ve maksimum maaşlarını OUTPUT geri dönüş tipiyle döndüren PL/pgSQL
--fonksiyonunun prototipini yazınız (10 Puan).
CREATE FUNCTION max_min_bul(dep_isim department.dname%TYPE, OUT ort real, OUT maks employee.salary%TYPE)
AS

--2: Şirkette çalışan en yaşlı kişinin adını ve doğum tarihini bulan PL/pgSQL fonksiyonunu yazınız (20 Puan).

CREATE OR REPLACE FUNCTION en_yasli_bul(OUT isim employee.fname%TYPE, OUT dogum employee.bdate%TYPE) 
AS $$
BEGIN
SELECT fname, bdate INTO isim, dogum FROM employee ORDER BY bdate LIMIT 1;
END;
$$ LANGUAGE plpgsql;
SELECT en_yasli_bul();