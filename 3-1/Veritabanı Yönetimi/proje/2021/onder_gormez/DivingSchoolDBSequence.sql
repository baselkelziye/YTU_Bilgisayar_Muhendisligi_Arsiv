-- Beşer beşer artacak şekilde öğrenci id lerini otomatik olarak
-- verebileceğimiz bir sequence tanımı yapınız.
CREATE SEQUENCE AutoIncrementStudentNumberSeq
INCREMENT BY 5
MINVALUE 12210
MAXVALUE 18000;

SELECT *
FROM AutoIncrementStudentNumberSeq;

SELECT NEXTVAL('AutoIncrementStudentNumberSeq');

DO $$
DECLARE uniqueIDValue INTEGER := NEXTVAL('AutoIncrementStudentNumberSeq');
BEGIN
INSERT INTO Students(name, surname, id) VALUES(CONCAT('Name ', uniqueIDValue), CONCAT('Surname ', uniqueIDValue), uniqueIDValue);
END $$;

SELECT * FROM Students WHERE name LIKE 'Name %';
