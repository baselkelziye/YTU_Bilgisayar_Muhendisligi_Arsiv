-- örnek-1: 5 numaralı departmanda çalışan işçilerin ad,soyad bilgilerini listeleyen sorguyu yazınız. 
select fname,lname
from employee
where dno=5

-- örnek-2: “Sales” departmanının hangi şehirlerde ofisi olduğunu bulan sorguyu yazınız.
select dlocation
from department d, dept_locations dl
where d.dnumber = dl.dnumber and dname='Sales'


-- örnek-3: “Atlanta” şehrinde yaşayan çalışanların ad,soyad ve çalıştığı departmanın ismini bulan sorguyu yazınız.
select fname, lname, dname
from employee, department
where dno = dnumber and address like '%Atlanta%'


-- örnek-4: “OperatingSystems” projesinde çalışanların ad,soyad bilgilerini listeleyen sorguyu yazınız.
select fname,lname
from project, works_on, employee
where pnumber=pno and essn=ssn and pname='OperatingSystems'

-- örnek-5: Kızının ismi ‘Alice’ olan çalışanların, çalıştıkları departmanların isimlerini bulan sorguyu yazınız.
select distinct dname
from dependent, employee, department
where dependent_name='Alice' and relationship='Daughter' and essn=ssn and dno=dnumber

-- örnek-6: Maaşı 70.000’in üzerinde olan çalışanların çalıştıkları projelerin isimlerini listeleyin.
select pname
from employee, works_on, project
where ssn=essn and pno=pnumber and salary>70000

--örnek-7: ‘Elizabeth’ isminde akrabası olan çalışanın yöneticisinin (supervisor) adını ve soyadını bulan SQL sorgusunu yazınız

SELECT e2.fname, e2.lname 
FROM employee e1, employee e2, dependent d WHERE d.dependent_name = 'Elizabeth'
		 AND d.essn = e1.ssn 
		AND e1.superssn = e2.ssn; 














