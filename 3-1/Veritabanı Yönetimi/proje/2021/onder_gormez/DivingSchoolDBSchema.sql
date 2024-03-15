-- DROP VIEW student_list_with_taken_lessons_view;
-- DROP TABLE Takes;
-- DROP TABLE Students;
-- DROP TABLE Prices;
-- DROP TABLE Lessons;
-- DROP TABLE Teachers;
-- DROP TABLE Classes;

-- DROP TABLE Students;
CREATE TABLE Students(
    id CHAR(5) NOT NULL PRIMARY KEY,
    name VARCHAR(20) NOT NULL,
    surname VARCHAR(20) NOT NULL,
    address VARCHAR(255),
    birthdate DATE
);

-- DROP TABLE Teachers;
CREATE TABLE Teachers(
    id CHAR(5) NOT NULL PRIMARY KEY,
    name VARCHAR(20) NOT NULL,
    surname VARCHAR(20) NOT NULL,
    address VARCHAR(255),
    birthdate DATE
);

-- DROP TABLE Classes;
CREATE TABLE Classes(
    id CHAR(5) NOT NULL PRIMARY KEY,
    name VARCHAR(20) NOT NULL
);

-- DROP TABLE Lessons;
CREATE TABLE Lessons(
    id CHAR(5) NOT NULL,
    name VARCHAR(20) NOT NULL,
    CONSTRAINT pk_lessons PRIMARY KEY (id)
);

-- DROP TABLE Prices;
CREATE TABLE Prices(
    lesson_id CHAR(5) NOT NULL PRIMARY KEY,
    price INTEGER NOT NULL,
	CONSTRAINT fk_prc FOREIGN KEY (lesson_id) REFERENCES Lessons (id) ON DELETE CASCADE,
	CONSTRAINT price_ck CHECK (price < 10000)
);

-- DROP TABLE Takes;
CREATE TABLE Takes(
    student_id CHAR(5) NOT NULL,
    lesson_id CHAR(5) NOT NULL,
    teacher_id CHAR(5) NOT NULL,
    class_id CHAR(5) NOT NULL,
    CONSTRAINT pk_takes PRIMARY KEY (student_id, lesson_id, teacher_id, class_id ),
    CONSTRAINT fk_studt FOREIGN KEY (student_id) REFERENCES Students (id) ON DELETE CASCADE,
    CONSTRAINT fk_teach FOREIGN KEY (teacher_id) REFERENCES Teachers (id) ON DELETE CASCADE,
    CONSTRAINT fk_clas FOREIGN KEY (class_id) REFERENCES Classes (id) ON DELETE CASCADE,
    CONSTRAINT fk_lessons FOREIGN KEY (lesson_id) REFERENCES Lessons (id) ON DELETE CASCADE
);