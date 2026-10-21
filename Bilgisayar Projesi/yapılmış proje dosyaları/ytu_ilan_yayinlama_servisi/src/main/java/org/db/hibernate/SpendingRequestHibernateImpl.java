package org.db.hibernate;

import java.util.List;

import org.db.dao.SpendingRequestDAO;
import org.db.model.Announcement;
import org.db.model.SpendingRequest;
import org.hibernate.SQLQuery;
import org.hibernate.Session;
import org.hibernate.Transaction;

public class SpendingRequestHibernateImpl extends AbstractDAO implements SpendingRequestDAO {
	private Session session;

	public boolean sendRequest(SpendingRequest sr) {
		return save(sr);
	}

	public int calculateTotalRequestAmount(String unitName) {
		int totalRequestAmount = -1;
		
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			Transaction tx = session.beginTransaction();
			String sql = "SELECT sum(amount) FROM spending_request WHERE dau=" + "'" + unitName + "' AND state = 1";
			SQLQuery query = session.createSQLQuery(sql);
			totalRequestAmount = Integer.parseInt(query.list().get(0).toString());
			tx.commit();
			
			return totalRequestAmount;
		} catch(Exception ex) {
			session.getTransaction().rollback();
			System.out.println("Toplam bakiye hesaplanamadı " + ex.getMessage());
			return totalRequestAmount;
		} finally {
			session.close();
		}
		
	}

	public List<SpendingRequest> listSpendingRequest(String unitName) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.getTransaction().begin();
			String query = " SELECT *  FROM spending_request where dau = '" + unitName + "';";
			SQLQuery sqlQuery = session.createSQLQuery(query);
			sqlQuery.addEntity(SpendingRequest.class);
			List<SpendingRequest> spendingList = sqlQuery.list();
			session.getTransaction().commit();
			return spendingList;
		} catch(Exception ex) {
			session.getTransaction().rollback();
			System.out.println("Harcama istekleri getirilemedi:" + ex.getMessage());
			return null;
		} finally {
			session.close();
		}
	}

	public boolean updateRequest(SpendingRequest sr) {
		return save(sr);
	}

	public List<SpendingRequest> listSpendingRequest(String unitName, int state) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.getTransaction().begin();
			String query = " SELECT *  FROM spending_request where dau = '" + unitName + "' and state = " + state + " ;";
			SQLQuery sqlQuery = session.createSQLQuery(query);
			sqlQuery.addEntity(SpendingRequest.class);
			List<SpendingRequest> spendingList = sqlQuery.list();
			session.getTransaction().commit();
			return spendingList;
		} catch(Exception ex) {
			session.getTransaction().rollback();
			System.out.println("Harcama istekleri getirilemedi:" + ex.getMessage());
			return null;
		} finally {
			session.close();
		}
	}

	public SpendingRequest getSpendingRequest(int id) {
		return (SpendingRequest) getObject(SpendingRequest.class, (Object)id);
	}

	public List<SpendingRequest> getAllSpendingRequest() {
		return getAllRows(SpendingRequest.class);
	}

	public List<SpendingRequest> getSpendingRequestByQuery(String query) {
		return getRowsBySQLQuery(SpendingRequest.class, query);
	}

}
