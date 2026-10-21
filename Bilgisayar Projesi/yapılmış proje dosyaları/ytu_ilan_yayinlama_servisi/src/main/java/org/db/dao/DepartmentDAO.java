package org.db.dao;

import java.util.List;

import org.db.model.Department;

public interface DepartmentDAO {
	List<Department> getAllDepartments();
	boolean isExist(String code);
	boolean addDepartment(Department department);
	boolean deleteDepartment(String code);
	boolean updateDepartment(String oldCode, String newCode, String name);
}
