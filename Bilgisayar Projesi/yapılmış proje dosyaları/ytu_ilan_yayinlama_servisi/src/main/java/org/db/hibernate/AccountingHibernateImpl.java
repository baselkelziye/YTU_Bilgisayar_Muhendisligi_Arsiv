package org.db.hibernate;

import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.db.dao.AccountingDAO;
import org.db.model.Accounting;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

public class AccountingHibernateImpl extends AbstractDAO implements AccountingDAO {
	private Session session;

	public boolean saveAccounting(Accounting accounting) {
		return save(accounting);
	}

	public List<Accounting> getAllAccountings() {
		String query = "select * from accounting order by date_time";
		return getRowsBySQLQuery(Accounting.class, query);
	}

	public List<Accounting> getUnitAccountings(String unitName) {
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.getTransaction().begin();
			String query = " SELECT *  FROM accounting where unit_name = '" + unitName + "';";
			SQLQuery sqlQuery = session.createSQLQuery(query);
			sqlQuery.addEntity(Accounting.class);
			List<Accounting> accList = sqlQuery.list();
			session.getTransaction().commit();
			return accList;
		} catch(Exception ex) {
			session.getTransaction().rollback();
			System.out.println("BKB işlem kayıtları getirilemedi:" + ex.getMessage());
			return null;
		} finally {
			session.close();
		}
	}

	public List<Accounting> getAccountingsFilterDate(String start, String end) {
		String query = "select * from accounting where date_time between '" + start + "' and '" +  end + "' order by date_time";
		return getRowsBySQLQuery(Accounting.class, query);
	}

	public List<Accounting> getAccountingsFilterName(String name) {
		String query = "select * from accounting where unit_name = '" + name + "' order by date_time";
		return getRowsBySQLQuery(Accounting.class, query);
	}

	public List<Accounting> getAccountingByQuery(String query) {
		return getRowsBySQLQuery(Accounting.class, query);
	}

	public List<Accounting> getAccountingsFilterDateAndName(String name, String start, String end) {
		String query = "select * from accounting where date_time between '" + start + "' and '" +  end + "' " +
				"and unit_name='" + name + "' order by date_time";
		return getRowsBySQLQuery(Accounting.class, query);
	}

}
