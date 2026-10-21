BLM3041 Veritabanı Yönetimi 3.Quizi 02.01.2025  A GRUBU 
Öğrenci No: 22011641
Ad: Burak          Soyad: Atalay
--Tüm sorular 20 puandır. SÜRE: 50 dk. Yükleme için +5 dk süre olacaktır.  Başarılar.

1-) /*SNN numarası verilen çalışanın tüm projelerdeki toplam çalışma saati 60 saati aşmışsa 
'Bu çalışanın toplamda 60 saatten fazla çalıştığı tespit edildi.' şeklinde hata mesajı (Raise Exception) döndüren fonksiyonu yazınız. 
Fonksiyonu '123456789' SSN numaralı çalışan için çağırınız.*/

CREATE OR REPLACE FUNCTION soru1(emp_id employee.ssn%type)
RETURNS NUMERIC AS $$
DECLARE
    total_hour NUMERIC;
BEGIN
    SELECT sum(hours)
    INTO total_hour
    FROM works_on a group by a.essn 
    having a.essn = emp_id;

	IF total_hour > 60 THEN
		RAISE EXCEPTION 'Bu çalışanın toplamda 60 saatten fazla çalıştığı tespit edildi';
	END IF;
	
    RETURN total_hour;
END;
$$ LANGUAGE plpgsql;

SELECT soru1('123456789')

2-) /* Bir çalışanın akrabalarının isim, ilişki türü ve doğum tarihini tutan bir tür (record) tanımı yapınız.*/

CREATE TYPE yeni_tur AS (isim VARCHAR(15), iliski_tur VARCHAR(8), b_date DATE);  


3-) /*Cursor kullanarak, bağlı oldukları departman ismi verilen çalışanların ad, soyad ve maaşlarını 
Raise Info ile ekrana yazdıran fonksiyonu yazınız. Fonksiyonu 'Research' departmanı için çağırınız. */

CREATE OR REPLACE FUNCTION soru3(dept_name department.dname%type)
RETURNS void AS $$
DECLARE
    emp_cursor CURSOR FOR SELECT a.fname, a.lname, a.salary FROM employee a, department b
	WHERE b.dname = dept_name and b.dnumber = a.dno;
	emp RECORD;
BEGIN
    FOR emp IN emp_cursor LOOP
        RAISE INFO 'Calisan ismi: %, Calisan soyismi: %, maasi: % TLdir.', emp.fname, emp.lname, emp.salary;
    END LOOP;
END;
$$ LANGUAGE plpgsql;

select soru3('Research')


4-) /*Bir çalışan eklenmeden önce departman numarasının geçerli olup olmadığını kontrol eden, 
böyle bir departman bulamazsa 'Gecersiz departman numarası' şeklinde hata mesajı yazdıran (Raise Exception) bir trigger oluşturun.
Trigger'ı tetikleyiniz.*/

CREATE TRIGGER trigg
BEFORE INSERT ON employee
FOR EACH ROW EXECUTE PROCEDURE soru4();

CREATE FUNCTION soru4()
RETURNS TRIGGER AS $$
BEGIN
	
    IF new.dno NOT IN (select dnumber from department) THEN
        RAISE EXCEPTION 'Gecersiz departman numarası.';
        RETURN NULL;
    ELSE
        RETURN NEW;
    END IF;
END;
$$ LANGUAGE 'plpgsql';

INSERT INTO employee VALUES('Vlademir', 'S', 'Putin', '666666666', '1952
10-07', '8975 Rusya', 'M', 125000, '333445555', 10);

5-) /*Çalışan maaşına zam yapılmak istendiğinde, sadece bulundukları departmanda 
toplam çalışan sayısı 5'in altında olan departman çalışanlarından maaşı 30.000 ve altında olanlara zam yapılmasına 
izin veren triggerı ve fonksiyonunu yazınız. 5 numaralı departman için Triggerı tetikleyiniz*/

CREATE TRIGGER trigge
BEFORE UPDATE ON employee
FOR EACH ROW EXECUTE PROCEDURE soru5();

CREATE FUNCTION soru5()
RETURNS TRIGGER AS $$
DECLARE
	total_calisan NUMERIC;
BEGIN
	SELECT count(*) into total_calisan from employee a where a.dno = old.dno;  
    IF (old.salary > new.salary and total_calisan < 5 and old.salary <= 30000) THEN
        RETURN NEW;
    ELSE
        RETURN OLD;
    END IF;
END;
$$ LANGUAGE 'plpgsql';

UPDATE employee
set salary = 1.1 * salary
where ssn = '987654321';
