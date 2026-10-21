package org.db.hibernate;

import java.util.List;

import org.db.dao.CurrencyDAO;
import org.db.model.Currency;
import org.hibernate.Session;

public class CurrencyHibernateImpl extends AbstractDAO implements CurrencyDAO {
	private Session session;
	
	public List<Currency> getAllCurrencies() {
		List<Currency> currencyList = (List<Currency>) getAllRows(Currency.class);
		return currencyList;
	}

	public Currency getCurrency(int id) {
		Currency currency = new Currency();
		
		try {
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			currency = session.get(Currency.class, id);
			session.getTransaction().commit();
		} catch(Exception ex) {
			System.out.println("Para birimi getirilemedi:" + ex.getMessage());
			session.getTransaction().rollback();
		} finally {
			session.close();
		}
		
		return currency;
	}
}
