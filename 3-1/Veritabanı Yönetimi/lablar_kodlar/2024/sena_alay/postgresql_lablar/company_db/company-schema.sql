--DROP TABLE employee;
CREATE TABLE employee (
  fname    varchar(15) not null, 
  minit    varchar(1),
  lname    varchar(15) not null,
  ssn      char(9),
  bdate    date,
  address  varchar(50),
  sex      char,
--  salary   number(10,2),
  salary   int,
  superssn char(9),
  --dno      number(4),
  dno smallint,
  primary key (ssn),
  foreign key (superssn) references employee(ssn)
--  foreign key (dno) references department(dnumber)
);

--DROP TABLE department;
CREATE TABLE department (
  dname        varchar(25) not null,
  --dnumber      number(4),
  dnumber smallint,
  mgrssn       char(9) not null, 
  mgrstartdate date,
  primary key (dnumber),
  unique (dname),
  foreign key (mgrssn) references employee(ssn)
);

--ALTER TABLE employee ADD (
--  foreign key (dno) references department(dnumber)
--);

ALTER TABLE employee ADD CONSTRAINT foreign_key_const
  foreign key (dno) references department(dnumber);


--DROP TABLE dept_locations;
CREATE TABLE dept_locations (
  --dnumber   number(4),
  dnumber smallint,
  dlocation varchar(15), 
  primary key (dnumber,dlocation),
  foreign key (dnumber) references department(dnumber)
);

--DROP TABLE project;
CREATE TABLE project (
  pname      varchar(25) not null,
  --pnumber    number(4),
  pnumber smallint,
  plocation  varchar(15),
  --dnum       number(4) not null,
  dnum       smallint not null,
  primary key (pnumber),
  unique (pname),
  foreign key (dnum) references department(dnumber)
);

--DROP TABLE works_on;
CREATE TABLE works_on (
  essn   char(9),
--  pno    number(4),
  pno    smallint,
  --hours  number(4,1),
 hours  smallint,
  primary key (essn,pno),
  foreign key (essn) references employee(ssn),
  foreign key (pno) references project(pnumber)
);

--DROP TABLE dependent;
CREATE TABLE dependent (
  essn           char(9),
  dependent_name varchar(15),
  sex            char,
  bdate          date,
  relationship   varchar(8),
  primary key (essn,dependent_name),
  foreign key (essn) references employee(ssn)
);
