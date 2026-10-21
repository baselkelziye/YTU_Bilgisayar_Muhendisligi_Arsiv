package org.db.hibernate;

import org.db.dao.DepartmentDAO;
import org.db.model.Department;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;

/**
 * Created by mgunes on 01.01.2017.
 */
public class DepartmentTest {
    private Department department;
    private List<Department> departmentList;
    private DepartmentDAO departmentDAO;

    @Before
    public void initialize() {
        department = new Department();
        departmentList = new ArrayList<Department>();
        departmentDAO = new DepartmentHibernateImpl();
    }

    @Test
    public void getAllDepartments() {
        departmentList = departmentDAO.getAllDepartments();
        assertEquals(14, departmentList.size());
    }

    @Test
    public void addDepartment() {
        department.setCode("tst");
        department.setName("test department");
        assertEquals(true, departmentDAO.addDepartment(department));
    }

    @Test
    public void updateDepartment() {
        assertEquals(true, departmentDAO.updateDepartment("tst", "tst", "test update department"));
    }

    @After
    public void deleteDepartment() {
        departmentDAO.deleteDepartment("tst");
    }
}
