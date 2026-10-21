Sql sorguları

--Sql sorgular 4.lab dahil
--Sql sorular
-- 1select * from employee
-- 5 numaralı departmanda çalışan işçilerin adı soyadı
select fname, lname, dno
from employee
where dno = 5

--2sales departmanın hangi şehirlerde ofisi olduğunu bulan sorgu
--select dlocation
--from dept_locations, department
--where department.dnumber = dept_locations.dnumber and dname = 'Sales'

select dlocation
from dept_locations dl, department d
where d.dnumber = dl.dnumber and dname = 'Sales'

--3atlanta şehrinde yaşayan kişilerin ad,soyad, departman adı
select fname, lname, dname
from employee, department
where address LIKE '%Atlanta%' and dno = dnumber

--4 "OperatingSystems" projesinde çalışanların ad,soyad bilgilerini listeleyen sorgu
select fname, lname, pname
from project, works_on, employee
where pno = pnumber and essn = ssn and pname = 'OperatingSystems'

--5 kızının ismi Alice olan çalışanların çaloştıkları departmanların isimlerini bulan sorgu
select distinct dname --burada unique olan kayıtları görmek için select distinct dname yaz 
from dependent, employee, department
where essn = ssn and dno = dnumber and dependent_name = 'Alice' and relationship='Daughter'

--6 maaşı 70.000in üzerinde olan çalışanların çalıştıkları projelerin isimlerini listeleyin
select pname
from project, employee, works_on
where salary > '70000' and pno = pnumber and essn = ssn

--"Alice” isminde akrabası olan çalışanların ad, soyad bilgilerini “IN” kullanarak bulan sorguyu yazınız.
SELECT fname, lname
FROM  employee  
WHERE ssn IN (select essn from dependent where dependent_name='Alice') 

Select fname,lname
from employee, dependent
where ssn = essn  and dependent_name='Alice'

---Hiçbir projesi bulunmayan departmanları listeleyen sorguyu yazınız.
SELECT dname 
FROM department 
WHERE NOT EXISTS (SELECT null FROM project WHERE dnumber = dnum);

--‘Sales’ departmanında kaç kişinin çalıştığını, en düşük, en yüksek,ortalama ve toplam maaşı bulunuz.
SELECT count(*),
sum(salary),
max(salary),
min(salary),
avg(salary)
FROM department, employee
WHERE dname='Sales' AND dnumber=dno

--Hiçbir departmanın veya hiçbir çalışanın yöneticisi olmayan çalışanların isimlerini bulunuz.

SELECT fname, lname
FROM employee e
WHERE not exists (select null from department where mgrssn=e.ssn) and
not exists (select null from employee e2 where e.ssn=e2.superssn)

--Kendi cinsiyetiyle aynı cinsiyette yöneticisi olan çalışanları bulunuz 
select e1.fname, e2.lname, e1.sex as calisancins, e2.sex as yoneticicinsiyet
from employee e1, employee e2
where e1.sex = e2.sex and e1.superssn=e2.ssn




---- 4. lab dersi
-- ortalama maaşın üzerinde kazanan çalışanların isimlerini ve maaşlarını bulun
select fname, lname, salary
from employee 
where salary > (select avg(salary) from employee)
order by salary; --artan sırada sıralıyor

SELECT fname, salary
FROM Employee
WHERE salary > (SELECT AVG(salary) FROM Employee)


SELECT fname, salary
FROM Employee
WHERE salary > (SELECT AVG(salary) FROM Employee)

--yalnızca ortalama maaşın 50000'im üzerinde olduğu 
--bölümler için departman numaralarını ve ortalama maaşlarını bulun
--departmanlara group by yapman lazım 
select dno, avg(salary) as ortalama_maas
from employee
group by dno
having avg(salary)> 50000;

--proje adlarını ve her projede çalışan kişi sayısnı bulun
select p.pname, count(w.essn) as calisan_sayisi
from project p, works_on w
where p.pnumber = w.pno
group by p.pnumber

--yalnızca toplam 100 saatten fazla olan projeler için proje adlarını ve toplam saatlerini bulun
select p.pname, sum (w.hours) as toplam_saat
from project p, works_on w
where p.pnumber = w.pno
group by p.pname, p.pnumber
having sum(w.hours) > 100;

--birden fazla projede çalışanların adlarını bulun
select fname,lname
from employee
where ssn in (select essn from works_on GROUP BY essn having count(pno)>1);

--yalnızca çalışan sayısının tek olduğu değartmanlar için 
--departman numaralarını ve toplam çalışan sayısını bulun
select dno, count(ssn)
from employee
group by dno
having count(ssn) % 2 <> 0

--ortalama maaşın genel ortalama maaştan yüksek olduğu departman numaralarını bulun
select dno
from employee
group by dno
having avg(salary) > (select avg(salary)from employee);





--toplam çalışılan saat sayısı en yüksek olan projeyi bulun
select p.pnumber, p.pname
from project p, works_on w
where w.pno = p.pnumber 
group by p.pnumber
--having max(hours)
order by sum(w.hours) desc 
limit 1

---