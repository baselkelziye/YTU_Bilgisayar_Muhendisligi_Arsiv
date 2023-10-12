#Cursor kullanımı

CREATE OR REPLACE FUNCTION dep_sum_salary(dnum numeric, OUT sum_sal numeric)
AS '
DECLARE
	emp_cursor CURSOR FOR SELECT salary FROM employee WHERE dno = dnum;

BEGIN
	sum_sal:=0;
	FOR record IN emp_cursor LOOP
		sum_sal:=sum_sal+record.salary;
		END LOOP;
END;
'LANGUAGE 'plpgsql';

SELECT dep_sum_salary(6);

DROP FUNCTION dep_sum_salary(numeric);

#TYPE oluşturma ve dizi döndürme
CREATE TYPE calisanlar AS (isim varchar(20), soyisim varchar(20), maas integer);

CREATE OR REPLACE FUNCTION list_of_employee(pnum project.pnumber%TYPE, bolen integer)
RETURNS calisanlar[] AS '
DECLARE
	emp_cursor CURSOR FOR SELECT fname,lname,salary FROM employee, works_on WHERE pno = pnum AND ssn = essn;
	cal calisanlar[];
	i integer;
BEGIN
	i=1;
	FOR record IN emp_cursor LOOP
		IF record.salary % bolen = 0 THEN
			cal[i]=record;
			i=i+1;
		END IF;
	END LOOP;
RETURN cal;
END;
' LANGUAGE 'plpgsql';

SELECT list_of_employee('61', 16)

#Sadece tatil günleri dışında ve mesai saatleri içinde employee tablosuna insert
#yapılmasına izin veren trigger’ı yazınız.

CREATE TRIGGER mesai_saati_mi
BEFORE INSERT
ON employee
FOR EACH ROW EXECUTE PROCEDURE mesai_saati_kontrol();

CREATE OR REPLACE FUNCTION mesai_saati_kontrol()
RETURNS TRIGGER AS $$
BEGIN
	IF(to_char(now(),'DY') IN ('SAT','SUN') OR to_char(now(),'HH24') not between '08' and '18') THEN
		RAISE EXCEPTION 'Sadece mesai saatlerinde çalışan eklenebilir!';
		RETURN null;
	ELSE 
		RETURN new;
	END IF;
END;
$$LANGUAGE 'plpgsql';

DROP TRIGGER mesai_saati_mi ON employee;

DROP FUNCTION mesai_saati_kontrol();

#Departman tablosunda dnumber kolonundaki değer değişince employee tablosunda
#da dno’nun aynı şekilde değişmesini sağlayan trigger’ı yazınız.

CREATE TRIGGER update_dno
AFTER UPDATE
ON department
FOR EACH ROW EXECUTE PROCEDURE update_emp_dno();


CREATE OR REPLACE FUNCTION update_emp_dno()
RETURNS TRIGGER AS $$
BEGIN

	UPDATE employee SET dno=new.dnumber
	WHERE dno=old.dnumber;
	RETURN new;
	
END;
$$LANGUAGE 'plpgsql';

DROP TRIGGER update_dno ON department;
DROP FUNCTION update_emp_dno();

#Maaş inişine ve %10’dan fazla maaş artışına izin vermeyen trigger’ı yazınız.

CREATE TRIGGER maas_kontrol
BEFORE UPDATE
ON employee
FOR EACH ROW EXECUTE PROCEDURE maas_kontrol_et();

CREATE FUNCTION maas_kontrol_et()
RETURNS TRIGGER AS $$
BEGIN
	IF(old.salary > new.salary OR new.salary > 1.1*old.salary) THEN
		RAISE EXCEPTION 'Maas dusurulemez ya da %%10dan fazla zam yapılamaz!';
		RETURN old;
	ELSE
		RETURN new;
	END IF;
END;
$$ LANGUAGE 'plpgsql';

UPDATE employee SET salary = salary*1.2;

DROP TRIGGER maas_kontrol ON employee;
DROP FUNCTION maas_kontrol_et();


#Departman tablonuza salary ile aynı tipte total_salary kolonu ekleyin. Employee
#tablosunda maaş sütununda değişiklik olduğunda department tablosundaki
#total_salary kolonunda gerekli güncellemeyi yapacak trigger’ı yazınız.

ALTER TABLE department ADD COLUMN total_Salary INTEGER default 0;

UPDATE department SET total_salary = (SELECT sum(salary) from employee where dno=dnumber;

									  
CREATE TRIGGER change_total_salary
AFTER INSERT OR UPDATE OR DELETE
ON employee
FOR EACH ROW EXECUTE PROCEDURE change_total_salary_from_department();

CREATE OR REPLACE FUNCTION change_total_salary_from_department()
RETURNS TRIGGER AS $$
BEGIN
	IF(TG_OP='DELETE') THEN
		UPDATE department
		SET total_salary=total_salary-old.salary
		WHERE dnumber=old.dno;
	ELSIF(TG_OP='UPDATE') THEN
		UPDATE department
		SET total_salary=total_salary-old.salary+new.salary
		WHERE dnumber=old.dno;
	ELSE
		UPDATE department
		SET total_salary=total_salary+new.salary
		WHERE dnumber=old.dno;
	END IF;
END;
$$LANGUAGE 'plpgsql';
									  

									 























