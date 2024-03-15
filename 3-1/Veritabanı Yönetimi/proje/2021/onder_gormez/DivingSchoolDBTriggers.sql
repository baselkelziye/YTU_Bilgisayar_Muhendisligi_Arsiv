-- Students tablosuna her ekleme yapıldığında üzerinde çalışılan öğrencinin bilgilerini veren trigger ı yazınız.
CREATE OR REPLACE FUNCTION insert_student_observer_trigger_func()
RETURNS TRIGGER AS
$$
  BEGIN
      RAISE WARNING 'New student (named % %) added to database with id number: %!', NEW.name, NEW.surname, NEW.id;
      RETURN NEW;
  END;
$$
LANGUAGE PLpgSQL;

-- DROP TRIGGER student_observer_trigger ON Students;
CREATE TRIGGER insert_student_observer_trigger
AFTER INSERT
ON Students
FOR EACH ROW
EXECUTE PROCEDURE insert_student_observer_trigger_func();

INSERT INTO Students VALUES(12190, 'Hayati', 'Taştekin', 'Sultangazi', '19 August 2003');

-- Students tablosuna her çıkarma yapıldığında üzerinde çalışılan öğrencinin bilgilerini veren trigger ı yazınız.
CREATE OR REPLACE FUNCTION delete_student_observer_trigger_func()
RETURNS TRIGGER AS
$$
  BEGIN
      RAISE WARNING 'Student (named % %) deleted from database with id number: %!', OLD.name, OLD.surname, OLD.id;
      RETURN NEW;
  END;
$$
LANGUAGE PLpgSQL;

-- DROP TRIGGER student_observer_trigger ON Students;
CREATE TRIGGER delete_student_observer_trigger
AFTER DELETE
ON Students
FOR EACH ROW
EXECUTE PROCEDURE delete_student_observer_trigger_func();

DELETE FROM Students WHERE id = '12190';