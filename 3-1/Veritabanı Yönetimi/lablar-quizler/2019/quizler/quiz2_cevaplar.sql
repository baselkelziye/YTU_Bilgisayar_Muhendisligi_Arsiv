DSELECT e.fname,count(*) FROM Employee e,project pr WHERE pr.dnum=e.dno GROUP BY e.fname ORDER BY e.fname


SELECT pname proje_ismi, AVG(hours) ort_saat FROM project p, works_on w WHERE p.pnumber=w.pno GROUP BY pname HAVING AVG(hours)>20 ORDER BY pname



CREATE OR REPLACE FUNCTION soru3(depname department.dname%TYPE)
RETURNS VOID AS $$
DECLARE
	male_min integer;
	female_min integer;
	divideTwo integer;
	minSalaryMale integer;
	minSSNMale integer;
BEGIN
	SELECT avg(salary) INTO male_min FROM Employee e,Department dp WHERE dp.dname=depname AND e.sex='M';
	SELECT avg(salary) INTO female_min FROM Employee e,Department dp WHERE dp.dname=depname AND e.sex='F';
	divideTwo := (male_min+female_min)/2;
	SELECT salary INTO minSalaryMale FROM Employee e WHERE e.sex='M' GROUP BY salary ORDER BY salary LIMIT 1;
	IF divideTwo>minSalaryMale THEN
			SELECT e.ssn INTO minSSNMale FROM Employee e WHERE e.sex='M' AND e.salary = minSalaryMale;
			UPDATE Employee SET salary=divideTwo WHERE employee.ssn=minSSNMale;
	END IF;
END;
$$ LANGUAGE 'plpgsql';


CREATE OR REPLACE FUNCTION soru4(peopleNumber integer,value1 integer,value2 integer)
RETURNS VOID AS $$
DECLARE
	youngestSSN integer;
	youngestDepartment integer;
	howManyWorker integer;
	howManyProject integer;
	departmentManager integer;
BEGIN
	SELECT e.ssn INTO youngestSSN FROM Employee e WHERE bdate IN(SELECT max(bdate) FROM Employee e);
	SELECT e.dno INTO youngestDepartment FROM Employee e WHERE e.ssn=youngestSSN;
	SELECT count(*) INTO howManyWorker FROM Department dp WHERE dp.dname=youngestDepartment;
	SELECT count(*) INTO howManyProject FROM Project pr WHERE pr.dnum=youngestDepartment;
	IF (howManyWorker>peopleNumber)AND(howManyProject<value1) THEN
		SELECT mgrssn INTO departmentManager FROM Department dp WHERE dp.dnumber=youngestDepartment;
		DELETE FROM Works_on wo WHERE essn IN (SELECT ssn FROM Employee e WHERE e.ssn<departmentManager AND e.sex='F'); 
		SELECT max(salary) FROM Employee e,Department dp WHERE dp.dno=youngestDepartment GROUP BY salary ORDER BY salary 
		
	END IF;
END;
$$ LANGUAGE 'plpgsql';