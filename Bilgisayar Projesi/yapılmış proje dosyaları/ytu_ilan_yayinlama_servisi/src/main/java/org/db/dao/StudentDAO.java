package org.db.dao;

import org.db.model.Student;

public interface StudentDAO {
	Student getStudent(String username);
	String saveStudent(Student s);
	int activateStudent(Student student, String code);
    boolean isCodeExist(String code);
}
