package org.db.hibernate;

import org.db.dao.UserTypeDAO;
import org.db.model.UserType;
import org.hibernate.Session;

public class UserTypeHibernateImpl extends AbstractDAO implements UserTypeDAO {
	private Session session;

	public UserType getUserType(int typeNo) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			UserType userType = session.get(UserType.class, typeNo);
			return userType;
		}
		catch(Exception ex) {
			System.out.println(ex);
			return null;
		}
		finally {
			session.close();
		}
	}
	
}
