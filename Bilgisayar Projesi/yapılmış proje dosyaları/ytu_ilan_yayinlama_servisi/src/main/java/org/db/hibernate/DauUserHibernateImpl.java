package org.db.hibernate;

import org.db.dao.DauUserDAO;
import org.db.model.DauUser;
import org.db.model.User;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

import java.util.List;

public class DauUserHibernateImpl extends AbstractDAO implements DauUserDAO {
    private Session session;

	public boolean saveDauUser(DauUser user) {
		return save(user);
	}

	public boolean deleteUser(String username) {
		String user1 = "DELETE FROM dau_user WHERE user_name ='" + username + "';";
        String user2 = "DELETE FROM users WHERE user_name ='" + username + "';";

        deleteUserBySQLQuery(user1);
        return deleteUserBySQLQuery(user2);
	}

    public List<DauUser> getUsersFromDau(String unitName) {
        String query = "select * from users u, dau_user d WHERE u.user_name = d.user_name and d.unit_name = '" + unitName + "' ";
        List<DauUser> userList = getRowsBySQLQuery(DauUser.class, query);
        return userList;
    }

    private boolean deleteUserBySQLQuery(String sql) {
	    session = HibernateSessionFactory.getSessionFactory().openSession();

        try {
            session.getTransaction().begin();
            SQLQuery query = session.createSQLQuery(sql);
            query.executeUpdate();
            session.getTransaction().commit();
            return true;
        } catch (Exception e) {
            System.out.println("deleteUserBySqlQuery:" + e.getMessage());
            session.getTransaction().rollback();
            return  false;
        } finally {
            session.close();
        }
    }

}
