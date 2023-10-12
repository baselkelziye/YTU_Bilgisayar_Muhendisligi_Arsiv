#Girdi olarak verilen 2 sayının toplamını bulan fonksiyonu yazınız ve (22,63) 
parametreleri için çalıştırınız.

CREATE FUNCTION sum1 (num1 NUMERIC, num2 NUMERIC)
RETURNS numeric AS '
DECLARE
total NUMERIC;
BEGIN
total:=num1 + num2;
RETURN total;
END;
'LANGUAGE plpgsql;

#return kullanmadan yapılan fonksiyon

CREATE OR REPLACE FUNCTION sum2 (num1 NUMERIC, num2 NUMERIC, OUT num3 NUMERIC)
AS '
BEGIN
num3:=num1 + num2;
END;
'LANGUAGE plpgsql;

#Fonksiyonu çağırma işlemi

SELECT sum2(4, 3) as total;

#Adı verilen bir departmandaki çalışanların ortalama maaşını bulan bir fonksiyon yazınız.

CREATE OR REPLACE FUNCTION avg_salary(depName department.dname%type)
RETURNS real AS '
DECLARE maas NUMERIC;
BEGIN
SELECT AVG(emp.salary) INTO maas FROM employee as emp, department as dep
WHERE dep.dname=depName AND emp.dno=dep.dnumber;
RETURN maas;
END;
'LANGUAGE plpgsql;

SELECT avg_salary('Research');

#Departman tablosundaki minimum ve maksimum departman numarasını bulup 
#min_deptno ve max_deptno değişkenlerine atan fonksiyonu yazınız.

CREATE OR REPLACE FUNCTION min_max_finder(OUT min_deptno department.dnumber%type, OUT max_deptno department.dnumber%type)
AS '
BEGIN
SELECT MIN(dep.dnumber), MAX(dep.dnumber) INTO min_deptno, max_deptno
FROM department AS dep;
END;
'LANGUAGE plpgsql;

SELECT min_max_finder()

#6 no’lu departmanda çalışanların sayısı 10’dan azsa departmandaki tüm 
#çalışanların maaşına %5 zam yapın. 

CREATE OR REPLACE FUNCTION inc_salary()
RETURNS void AS '
DECLARE
num_worker NUMERIC:=0;
BEGIN
SELECT count(*) INTO num_worker FROM employee as emp
WHERE emp.dno=6;
IF(num_worker < 10) THEN
UPDATE employee SET salary=salary*1.05
WHERE dno=6;
END IF;
END;
'LANGUAGE plpgsql;
SELECT * FROM employee;
SELECT inc_salary();

#case örneği

CREATE OR REPLACE FUNCTION create_msg(num1 NUMERIC)
RETURNS VARCHAR AS '
DECLARE
msg VARCHAR(20);
BEGIN

CASE num1
WHEN num1 < 0 THEN msg:="negative";
WHEN num1 > 0 THEN msg:="positive";
WHEN num1 = 0 THEN msg:="zero";
ELSE msg:="NULL";
END CASE;
RETURN msg;
END;
'LANGUAGE plpgsql;
DROP FUNCTION create_msg(NUMERIC);
SELECT create_msg(4);

#İsmi verilen bir departmanda çalışanların ortalama maaşı, verilen bir değerden düşük 
#ve o departmandaki kadın çalışanların maaşlarının toplamı verilen bir limitin
#üstündeyse, o departmanda 1’den fazla projede çalışanların maaşlarına yine verilen bir 
#oranda zam yapan fonksiyonu yazınız.

CREATE OR REPLACE FUNCTION make_raise(dep_name department.dname%type, avg_salary real,
									 f_top_salary employee.salary%type, raise_rate real)
RETURNS void AS '
DECLARE
get_avg_salary real;
f_salary INTEGER;
dep_no department.dnumber%type;
BEGIN

SELECT dnumber INTO dep_no FROM department WHERE dname = dep_name;
SELECT AVG(salary) INTO get_avg_salary FROM employee WHERE dno=dep_no;
SELECT SUM(salary) INTO f_salary FROM employee WHERE dno=dep_no AND sex="F";

IF(get_avg_salary < avg_salary AND f_salary > f_top_salary) THEN
UPDATE employee SET salary = salary*raise_rate + salary WHERE ssn IN (
SELECT essn FROM employee, works_on WHERE dno=dep_no AND essn=ssn
GROUP BY essn HAVING count(*) > 1
);
END IF;
END;
'	LANGUAGE plpgsql;

#Şirkette çalışan en yaşlı kişinin adını ve doğum tarihini bulan PL/pgSQL fonksiyonunu yazınız

CREATE OR REPLACE FUNCTION older_emp(OUT emp_name employee.fname%type, OUT emp_date employee.bdate%type)
AS '
BEGIN
SELECT fname, bdate INTO emp_name, emp_date FROM employee
ORDER BY bdate LIMIT 1;
END;
'LANGUAGE plpgsql;
SELECT older_emp();

#Şirketin en yüksek maaş ortalamalı 2 departmanı arasındaki ortalama yaş farkının kaç olduğunu bulan PL/pgSQL 
#sorgusunu yazınız

CREATE OR REPLACE FUNCTION find_age_diff()
RETURNS real AS '
DECLARE
first_avg real;
second_avg real;
different real;
first_dep_no department.dnumber%type;
BEGIN

SELECT dnumber, AVG(salary) INTO first_dep_no, first_avg
FROM employee, department WHERE dno=dnumber GROUP BY dnumber
ORDER BY AVG(salary) DESC LIMIT 1;

SELECT AVG(salary) INTO second_avg FROM department, employee
WHERE dnumber<>first_dep_no AND dno=dnumber ORDER BY AVG(salary) DESC LIMIT 1;

different:=first_avg - second_avg;
return different;
END;
'LANGUAGE plpgsql;
SELECT find_age_diff();

#İsmi verilen projede çalışanlar arasından, o projede çalışanların ortalama maaşından daha yüksek maaşı olanlardan, en 
#düşük maaşı olan çalışanın akrabalarından en gencinin ismini bulan PL/pgSQL fonksiyonunu yazınız



									 
									 
									 

