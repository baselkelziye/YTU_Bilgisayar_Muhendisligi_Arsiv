SORU1
-----------------------------------------------------------------------------------------------------------------------------------------------------------
CREATE OR REPLACE FUNCTION addEmployee(name1 Employee.fname%TYPE,lastName Employee.lname%TYPE,number1 Employee.ssn%TYPE)
RETURNS VOID AS $$

DECLARE
projectCursor1 CURSOR FOR SELECT pnumber,dnum FROM Project;
projectCursor2 CURSOR FOR SELECT pnumber,dnum FROM Project;
tempNumber integer:=0;
maxCount integer:=0;
depNumber NUMERIC:=1;
dArray depArray[];
i integer:=0;
j integer:=0;
minimum integer:=10;
BEGIN

FOR satir1 IN projectCursor1 LOOP
	fOR satir2 IN projectCursor2 LOOP
		IF satir1.pnumber=satir2.pnumber THEN
			tempNumber:=tempNumber+1;
			
		END IF;
	END LOOP;
	IF tempNumber>maxCount THEN
		maxCount:=tempNumber;
	ELSEIF tempNumber=maxCount THEN
		dArray[i]:=satir.dnum;
		i:=i+1;
	ELSE
		
	END IF;
END LOOP;

RAISE NOTICE 'Max project number %',maxCount; 

j:=0;
WHILE j<i LOOP
	IF dArray[j]<minimum THEN
		minimum:=dArray[j];
	END IF;
END LOOP;

INSERT INTO Employee VALUES(name1,null,lastName,number1,null,null,null,null,null,minimum);
RAISE NOTICE 'Employee added: % % % %',name1,lastName,number1,minimum; 

END;

$$ LANGUAGE 'plpgsql';

CREATE TYPE depArray AS(dnum NUMERIC);

-----------------------------------------------------------------------------------------------------------------------------------------------------------
SORU2
-----------------------------------------------------------------------------------------------------------------------------------------------------------
CREATE TYPE newType AS(ssn char(9));

CREATE OR REPLACE FUNCTION trigger_q2()
RETURNS TRIGGER AS $$
DECLARE
	averageSalary NUMERIC;
	aType newType[];
	i integer:=0;
	j integer:=0;
	sizeArray integer;
	tempSSN char(9);
	emp CURSOR FOR SELECT * FROM Employee;
BEGIN
	SELECT avg(salary) AS averageSalary FROM Employee e;
	FOR satir IN emp LOOP
		IF satir.salary>averageSalary THEN
			aType[i] = satir.ssn;
			i=i+1;
		END IF;
	END LOOP;
	sizeArray:=i;
	j:=0;
	WHILE j<sizeArray LOOP
		WHILE aType[j].salary<averageSalary LOOP
			tempSSN:=aType[j];
			UPDATE tempSSN SET tempSSN.salary = tempSSN.salary - 100;
			aType[j]:=tempSSN;
		END LOOP;
	
	END LOOP;	
	
	IF superssn IS NULL THEN
		UPDATE Employee SET superssn=ssn;
		RAISE NOTICE 'Manager assigned.';
	END IF;
	
	
END;
$$ LANGUAGE 'plpgsql';


CREATE TRIGGER q2_trigger
BEFORE INSERT or UPDATE 
ON Employee 
FOR EACH ROW EXECUTE PROCEDURE trigger_q2()


INSERT INTO Employee VALUES('Irfan','M','Orga','473543653','1908-10-21','Bir Türk Ailesinin Hikayesi','M',20000,null,8);

-----------------------------------------------------------------------------------------------------------------------------------------------------------
SORU3
----------------------------------------------------
let $com := doc("company.xml")
  for $emp in $com//employee
    let $ilk := $emp/fname
    let $soy := $emp/lname
    let $tc := $emp/@ssn
  for $wo in $com//works_on
    let $etc := $wo/@essn
    let $pnu := $wo/@pno
  for $pr in $com//project
    let $pnum := $pr/@pnumber
    let $pnam := $pr/pname
where $tc=$etc and $pnu=$pnum and $pnam='ProductX'
return $ilk | $soy
----------------------------------------------------