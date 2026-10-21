package org.db.hibernate;

import java.util.HashMap;
import java.util.List;

import org.db.dao.DepartmentDAO;
import org.db.model.Department;
import org.hibernate.Session;

public class DepartmentHibernateImpl extends AbstractDAO implements DepartmentDAO {
	private Session session;

	public List<Department> getAllDepartments() {
		String hql = "FROM Department ORDER BY code";
		List<Department> departments = getRowsByQuery(Department.class, hql, new HashMap<String, Object>());
		return departments;
	}

	public boolean isExist(String code) {
		Object department = getObject(Department.class, code);
		
		if(department == null)
			return false;
		else
			return true;
	}

	public boolean addDepartment(Department department) {
		return save(department);
	}

	public boolean deleteDepartment(String code) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			String deleteQuery = "delete from Department where code= :code";
			session.beginTransaction();
			session.createQuery(deleteQuery).setString("code", code).executeUpdate();
			session.getTransaction().commit();
			return true;
		} catch (Exception e) {
			System.out.println(e.getMessage());
			session.getTransaction().rollback();
			return false;
		} finally {
			session.close();
		}
	}

    public boolean updateDepartment(String oldCode, String newCode, String name) {
        try {
            session = HibernateSessionFactory.getSessionFactory().openSession();
            String updateQuery = "update Department set code= :newCode ,name= :name where code= :oldCode";
            session.beginTransaction();
            session.createQuery(updateQuery)
                    .setString("newCode", newCode)
                    .setString("oldCode", oldCode)
                    .setString("name", name)
                    .executeUpdate();
            session.getTransaction().commit();
            return true;
        } catch (Exception e) {
            System.out.println(e.getMessage());
            session.getTransaction().rollback();
            return false;
        } finally {
            session.close();
        }
    }

}
