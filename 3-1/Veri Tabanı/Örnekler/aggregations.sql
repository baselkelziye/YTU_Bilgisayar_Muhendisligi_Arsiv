#«Sales» departmanında kaç kişinin çalıştığını, toplam maaşlarını, 
#en yüksek maaşı, en düşük maaşı ve ortalama maaşı bulunuz.

SELECT COUNT(*) AS emp_count, SUM(emp.salary) AS total_salary,
MAX(emp.salary) AS max_salary, MIN(emp.salary) AS min_salary,
AVG(emp.salary) AS avg_salary
FROM employee AS emp, department AS dep
WHERE dep.dname='Sales' AND emp.dno=dep.dnumber;

#8 numaralı departmanda çalışan işçilerin ortalama ve 
#toplam maaşlarını bulunuz.

SELECT AVG(emp.salary) as avg_salary, SUM(emp.salary) as total_salary
FROM employee as emp WHERE emp.dno=8

#En genç çalışanın çalıştığı projelerin numaralarını listeleyiniz.

SELECT works.pno FROM works_on as works, employee as emp
WHERE emp.bdate IN(SELECT MAX(emp.bdate) FROM employee as emp)
AND works.essn=emp.ssn;

#Her bir projede çalışanların ortalama maaşını bulup proje ismine göre 
#alfabetik olarak sıralayınız.

SELECT pro.pname, AVG(emp.salary) as avg_salary
FROM project as pro, employee as emp, works_on as works
WHERE works.essn=emp.ssn AND pro.pnumber=works.pno
GROUP BY pro.pname
ORDER BY pro.pname ASC;

#Her bir departmanda her bir cinsiyetten kaçar işçi olduğunu 
#ve bu işçilerin ortalama maaşlarını bulunuz.

SELECT dep.dnumber, emp.sex, AVG(emp.salary)
FROM department as dep, employee as emp
WHERE emp.dno=dep.dnumber
GROUP BY dep.dnumber, emp.sex;

#5 numaralı departman dışındaki departmanlar arasından, 
#ortalama maaşı 40000$’dan fazla olan departmanların 
#numaralarını ve bu departmandaki ortalama maaşları bulan 
#sorguyu yazınız.

SELECT dep.dnumber, AVG(emp.salary)
FROM employee as emp, department as dep
WHERE emp.dno=dep.dnumber
AND dep.dnumber<>5
GROUP BY dep.dnumber
HAVING AVG(emp.salary) > 40000;

#En çok maaşı alan işçinin ismini ve soyismini gösteren sorguyu 
#yazınız. (ORDER BY ve LIMIT kullanarak)

SELECT emp.fname, emp.lname FROM employee as emp
ORDER BY emp.salary DESC LIMIT 1

SELECT extract(YEAR FROM emp.bdate) FROM employee as emp;

#İsmi ‘Pro’ ile başlamayan projelerde kaç kişinin çalıştığını ve proje ismini; proje ismine göre ters alfabetik 
#olacak şekilde gösteren sorguyu yazınız. Çalışan sayısının 3’ten az olduğu projeleri dahil etmeyiniz

SELECT count(*), pro.pname FROM project as pro, works_on as works
WHERE pro.pname NOT LIKE 'Pro%' AND pro.pnumber=works.pno
GROUP BY pro.pname
HAVING count(*) > 3
ORDER BY pro.pname DESC;


















