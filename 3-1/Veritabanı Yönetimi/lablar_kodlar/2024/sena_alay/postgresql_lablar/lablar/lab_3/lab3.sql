--3.lab elçin güveyi 9/11
--elizabeth isminde akrabası olan çalışnaın yöneticisinin  adını ve soyadını bulunuz
select e2.fname, e2.lname
from dependent, employee e1, employee e2
where dependent_name = 'Elizabeth' and essn=e1.ssn and e1.superssn = e2.ssn

--constraints
--primary key constrainti oluşturma
--1.yol özel isim vererek
Create table team (
	tnumber numeric(2),
	tname varchar(15)
	CONSTRAINT pk_team PRIMARY KEY(tnumber)
);
--kendim pk_team ismiyle tnumberı primary key yapıyorum
--bu kısıtı silmek istersek
ALTER TABLE team DROP CONSTRAINT pk_team;
--2.yol
CREATE TABLE team(
	tnumber numeric(2) PRIMARY KEY,
	tname varchar(15)
);
--burada biz kısıta bir isim vermesek de primary key kısıtı için default isimlendirme: tabloadı_pkey
--silmek için
ALTER TABLE team DROP CONSTRAINT team_pkey;

--işçilerin tek takımda oynama zorunluluğu yoktur. tno ve essn birlikte primary key olmalıdır.
--iki sutün primary key, yani bu ikisi birlikte farklı kayıtlarda tekrar etmeyecek
CONSTRAINT pk_team_employee PRIMARY KEY (tno,essn) --burada ben isimlendirme verdim
CONSTRAINT PRIMARY KEY (tno,essn) --burada o default isimlendirme yapıcak

--tno, team tablosundaki tnumberı referans almalıdır. team tablosundan 1 satır silindiğinde, bu satıra ait tnolu satırlar da silinmelidir
CONSTRAINT fk_team FOREIGN KEY (tno) REFERENCES team(tnumber) ON DELETE CASCADE

--essn, employee tablosundaki ssni referans almalıdır. employee tablosundan bir satır silindiğinde, bu satıra ait essnli satırlar da silinmelidir.
CONSTRAINT fk_emp FOREIGN KEY(essn) REFERENCES employee(ssn) ON DELETE CASCADE 

--bir çalışan bir takımda 12 haftadan uzun süre oynayamaz.
CONSTRAINT play_time_ck CHECK (play_time<13)
--hepsi bir arada oluştur
create table team_employee(
	tno numeric(2),
	essn char(9),
	play_time numeric(2),
	CONSTRAINT pk_team_employee PRIMARY KEY (tno,essn),
	CONSTRAINT fk_team FOREIGN KEY (tno) REFERENCES team(tnumber) ON DELETE CASCADE,
	CONSTRAINT fk_emp FOREIGN KEY(essn) REFERENCES employee(ssn) ON DELETE CASCADE,
	CONSTRAINT play_time_ck CHECK (play_time<13)
);

--foreign key oluşturmada diğer yöntemler
--1 
create table team employee(
	tno numeric(2) REFERENCES team(number)
)

--2
create table team_employee (
	tno numeric(2)
	foreign key (tno) REFERENCES team(number)
)

--3
ALTER TABLE team_employee ADD CONSTRAINT te_fk FOREIGN KEY (tno) REFERENCES team(tnumber)
--foreign key kısıtı için default isimlendirme : tabloadı_sütunadı_fkey
--foreign key sileceksek 
ALTER TABLE team_employee DROP CONSTRAINT team_employee_tno_fkey;

--view oluşturma
--view: sorguya verilen isim. bir sorgu sonucu oluşan sanal tablo.
--sık kullanacağımız sorguyu 1 kez yazıp, isimlendirme işlemi
create view view_name
as
select ...
from ...
where ...

--maaşı 20000 ile 40000 arasında olan çalışanların isimlerini ve maaşlarını gösteren bir view yazınız
create view maaslar2
as
select fname, lname, salary 
from employee
where salary BETWEEN 20000 and 40000

--view çağırma
select * from maaslar2
select * from maaslar
--not! employee tablosundan bu viewı etkileyen bir bilgi sildiğimizde view otomatik olarak güncellenir


--sequence oluşturma
-- otomatik artan idler oluşturmak için mesela.
--belli bir sırada sayısal değerler üretmemizi sağlar.

create sequence sequence_name
increment by
start with
maxvalue
minvalue
nominvalue
cycle --son değere ulaşınca başa dön
nocycle

--9dan başlayıp 99a kadar birer vbirer artan bir sequence yaz
create sequence seq
minvalue 9 
maxvalue 99
increment by 1

--sequence hakkında bilgi almak için 
select * from seq

--sequencein sıradaki değeri
select nexval('seq') 

--sequencedeki değeri tabloya kayıt eklerken kullanma
insert into employee(fname,ssn) values ('John', nextval('seq'))

--union birleşim
--intersect kesişim
--except fark

-- operatingsystem isimli projde ve software departmanında çalışanların ad soyad  bilgilerini bulunuz
select fname, lname
from project, works_on, employee
where pname= 'OperatingSystems' and pnumber=pno and essn=ssn

intersect

select fname,lname
from department, employee
where dname = 'Software' and dnumber=dno

--BURADA ŞU ÖNEMLİ. kesişim union except yapacaksan selecttan sonra aynı sütun isimlerini vermen lazım!!

-- operatingsystem isimli projde VEYA software departmanında çalışanların ad soyad  bilgilerini bulunuz
select fname, lname
from project, works_on, employee
where pname= 'OperatingSystems' and pnumber=pno and essn=ssn

UNION

select fname,lname
from department, employee
where dname = 'Software' and dnumber=dno

--operating systems projesinde çalışıp software departmanında çalışmayanların ad soyad biglierini
select fname, lname
from project, works_on, employee
where pname= 'OperatingSystems' and pnumber=pno and essn=ssn

EXCEPT

select fname,lname
from department, employee
where dname = 'Software' and dnumber=dno

--hiçbir departmanın veya hiçbir çalışanın yöneticisi olmayan çalışanların isimlerini bul
select fname,lname
from employee e
where not exists (select null from department where mgrssn = e.ssn) and  not exists (select null from employee e2 where e.ssn=e2.superssn)
--null yerine * da koyabiliriz

--ismi john olan işçilerin çalıştıkları departmanların isimlerini in kullanarak bulunuz
select dname
from department
where dnumber in (select dno from employee where fname='John' )

--sales departmanında kaç kişinin çalıştığını, en düşük, en yüksek, ortalama ve toplam maaşı bulunuz
select 	count(*),
		sum(salary),
		max(salary),
		min(salary),
		avg(salary)
from department, employee
where dname='Sales' and dnumber=dno 