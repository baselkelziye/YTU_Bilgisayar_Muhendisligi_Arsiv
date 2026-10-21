package org.db.hibernate;

import org.db.dao.ApplicationDAO;
import org.db.model.Application;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

public class ApplicationHibernateImpl extends AbstractDAO implements ApplicationDAO {
	private Session session;
	
	public boolean application(Application app) {
		return save(app);
	}

	public boolean deleteApplication(String userName, int announcementID) {
		try {
			String query = "DELETE FROM application "
					+ "WHERE username = " + "'" + userName + "'" + " AND announcement_id = " + announcementID;
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			SQLQuery sqlQuery = session.createSQLQuery(query);
			sqlQuery.addEntity(Application.class);
			sqlQuery.executeUpdate();
			session.getTransaction().commit();			
			return true;		
		} catch(Exception ex) {
			session.getTransaction().rollback();
			System.err.println("Bekleyen bağışlar getirilemedi:" + ex.getMessage());
			return false;
		}
		finally {
			session.close();
		}
	}

}
