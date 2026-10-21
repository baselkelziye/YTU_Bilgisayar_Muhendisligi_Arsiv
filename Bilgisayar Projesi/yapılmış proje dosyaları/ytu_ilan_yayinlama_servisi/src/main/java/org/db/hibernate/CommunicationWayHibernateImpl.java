package org.db.hibernate;

import org.db.dao.CommunicationWayDAO;
import org.db.model.CommunicationWay;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

public class CommunicationWayHibernateImpl extends AbstractDAO implements CommunicationWayDAO {
	private Session session;

	public boolean saveCommWay(CommunicationWay way) {
		return save(way);
	}

	public boolean deleteCommWay(String title, String value) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.getTransaction().begin();
			String query  = "DELETE FROM communication_way WHERE comm_type = " + "'" + title + "' AND comm_value = " + "'" + value + "';";
			SQLQuery sqlQuery = session.createSQLQuery(query);
			sqlQuery.executeUpdate();
			session.getTransaction().commit();
			return true;
		} catch(Exception ex) {
			session.getTransaction().rollback();
			System.out.println("İletişim bilgisi silinemedi: " + ex.getMessage());
			return false;
		} finally {
			session.close();
		}
	}

	public boolean updateCommWay(String username, String oldType, String oldValue, String newType, String newValue) {
		String sql = "UPDATE communication_way " +
				" SET comm_type = '" + newType + "' , comm_value = '" + newValue + "' " +
				" WHERE comm_type = '" + oldType + "' and comm_value = '" + oldValue + "' ";

		return updateBySQLQuery(CommunicationWay.class, sql);
	}

}
