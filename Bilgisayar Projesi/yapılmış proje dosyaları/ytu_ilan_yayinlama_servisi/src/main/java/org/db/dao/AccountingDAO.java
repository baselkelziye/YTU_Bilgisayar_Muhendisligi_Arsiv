package org.db.dao;

import java.util.Date;
import java.util.List;

import org.db.model.Accounting;

public interface AccountingDAO {
	boolean saveAccounting(Accounting accounting);
	List<Accounting> getAllAccountings();
	List<Accounting> getUnitAccountings(String unitName);
	List<Accounting> getAccountingsFilterDate(String start, String end);
	List<Accounting> getAccountingsFilterName(String name);
	List<Accounting> getAccountingByQuery(String query);
	List<Accounting> getAccountingsFilterDateAndName(String name, String start, String end);
}
