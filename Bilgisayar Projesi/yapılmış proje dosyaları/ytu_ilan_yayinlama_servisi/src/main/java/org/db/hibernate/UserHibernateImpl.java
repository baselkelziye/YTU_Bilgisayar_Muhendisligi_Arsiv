package org.db.hibernate;

import org.db.dao.UserDAO;
import org.db.model.User;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

import java.util.List;

public class UserHibernateImpl extends AbstractDAO implements UserDAO {
	private Session session;

	public User getUser(String username) { // getObject ile abstract daoya
											// yerleştir
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			User user = session.get(User.class, username);
			session.getTransaction().commit();
			return user;
		} catch (Exception ex) {
			System.out.println("kullanıcı getirilemedi");
			session.getTransaction().rollback();
			return null;
		} finally {
			session.close();
		}
	}

	public User getUserByMail(String mail) {
		String query = "SELECT u.user_name " +
                " FROM users u, communication_way c " +
                " WHERE comm_value = '" + mail + "' AND (comm_type = 'mail' OR comm_type = 'Mail') AND u.user_name = c.user_name;";
        String username;

        try {
            session = HibernateSessionFactory.getSessionFactory().openSession();
            session.getTransaction().begin();
            SQLQuery sqlQuery = session.createSQLQuery(query);
            username = (String)sqlQuery.list().get(0);
            session.getTransaction().commit();
            User user = getUser(username);
            return user;
        } catch (Exception ex) {
            session.getTransaction().begin();
            ex.printStackTrace();
            System.out.println("Kullanıcı mail ile getirilemedi " + ex.getMessage());
            return null;
        } finally {
            if(session.isOpen())
                session.close();
        }

	}

	public boolean isUserExist(String username) {
		User user = getUser(username);

		if (user == null) {
			return false;
		} else {
			return true;
		}
	}

	public boolean update(Object user) {
		return save(user);
	}
}
