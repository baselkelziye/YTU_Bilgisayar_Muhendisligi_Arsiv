package org.db.dao;

import java.util.List;

import org.db.model.Currency;

public interface CurrencyDAO {
	List<Currency> getAllCurrencies();
	Currency getCurrency(int id);
}
