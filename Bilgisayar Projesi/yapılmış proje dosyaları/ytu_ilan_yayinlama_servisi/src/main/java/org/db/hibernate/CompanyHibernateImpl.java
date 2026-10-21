package org.db.hibernate;

import org.db.dao.CompanyDAO;
import org.db.model.Announcement;
import org.db.model.CommunicationWay;
import org.db.model.Company;
import org.db.model.User;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CompanyHibernateImpl extends AbstractDAO implements CompanyDAO {
    private Session session;

	public boolean saveCompany(Company company) {
		return save(company);
	}

	public boolean updateCompanyUser(Company c) {
		String hql = "UPDATE Company " +
                "SET name = :name, surname = :surname, contactMail = :contactMail, contactTel = :contactTel" +
                " WHERE userName = :userName";
		Map<String, Object> parameter = new HashMap<String, Object>();
        parameter.put("name", c.getName());
        parameter.put("surname", c.getSurname());
        parameter.put("contactMail", c.getContactMail());
        parameter.put("contactTel", c.getContactTel());
        parameter.put("userName", c.getUserName());

        return updateByQuery(Company.class, hql, parameter);
	}

    public boolean deleteCompany(Company c) {
        try {
            String query1 = "DELETE FROM company WHERE user_name = '" + c.getUserName() + "' ";
            String query2 = "DELETE FROM users WHERE user_name = '" + c.getUserName() + "' ";
            session = HibernateSessionFactory.getSessionFactory().openSession();
            session.getTransaction().begin();
            SQLQuery q1 = session.createSQLQuery(query1);
            SQLQuery q2 = session.createSQLQuery(query2);
            q1.executeUpdate();
            q2.executeUpdate();
            session.getTransaction().commit();
            return  true;
        } catch (Exception e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
            session.getTransaction().rollback();
            return false;
        } finally {
            session.close();
        }
    }

    public boolean deleteCompany(String username) {
        String query1 = "DELETE FROM communication_way WHERE user_name = '" + username + "';";
        String query2 = "DELETE FROM company WHERE user_name = '" + username + "';";
        String query3 = "DELETE FROM users WHERE user_name = '" + username + "';";

        if(!updateBySQLQuery(CommunicationWay.class, query1))
            return  false;
        if(!updateBySQLQuery(Company.class, query2))
            return  false;
        if(!updateBySQLQuery(User.class, query3))
            return  false;

        return true;
    }

    public List<Announcement> getMyActiveAnnouncements(String username) {
        String query = "SELECT * FROM announcement " +
                " WHERE owner_company = '" + username + "' and (state = 2 or state = 3) and now() < expired_date ORDER BY id";
        return getRowsBySQLQuery(Announcement.class, query);
    }

    public List<Announcement> getMyPassiveAnnouncements(String username) {
        String query = "SELECT * FROM announcement " +
                " WHERE owner_company = '" + username + "' and state = 1 ORDER BY id";
        return getRowsBySQLQuery(Announcement.class, query);
    }

    public List<Announcement> getMySuspendedAnnouncements(String username) {
        String query = "SELECT * FROM announcement " +
                " WHERE owner_company = '" + username + "' and state = 4 ORDER BY id";
        return getRowsBySQLQuery(Announcement.class, query);
    }

    public List<Company> getWaitingApproval() {
        String query = "SELECT * FROM users u, company c WHERE u.user_name = c.user_name and u.membership_status = 4";
        return getRowsBySQLQuery(Company.class, query);
    }

    public Company getCompany(String username) {
        String query = "SELECT * FROM users u, company c WHERE u.user_name = '" + username + "' and c.user_name = '" + username + "';";
        List<Company> companyList = getRowsBySQLQuery(Company.class, query);
        return companyList.get(0);
    }

    public boolean updateCompanyPassword(Company c) {
	    String hql = "UPDATE Company SET password = :password WHERE userName = :userName";
        Map<String, Object> parameter = new HashMap<String, Object>();
        parameter.put("password", c.getPassword());
        parameter.put("userName", c.getUserName());

        return updateByQuery(Company.class, hql, parameter);
    }
}
