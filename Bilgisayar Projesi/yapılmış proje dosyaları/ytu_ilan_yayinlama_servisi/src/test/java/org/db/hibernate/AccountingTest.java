package org.db.hibernate;

import org.db.dao.AccountingDAO;
import org.db.model.Accounting;
import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;

/**
 * Created by mgunes on 01.01.2017.
 */
public class AccountingTest {
    private List<Accounting> accountingList;
    private AccountingDAO accountingDAO;

    @Before
    public void initialize() {
        accountingList = new ArrayList<Accounting>();
        accountingDAO = new AccountingHibernateImpl();
    }

    @Test
    public void getAccountingsFilterName() {
        accountingList = accountingDAO.getAccountingsFilterName("Mezunlar Derneği");
        assertEquals("Mezunlar Derneği", accountingList.get(0).getDauUser().getDau().getUnitName());
    }

    @Test
    public void getAccountingByQuery() {
        String query = "SELECT * FROM accounting ORDER BY amount asc;";
        accountingList = accountingDAO.getAccountingByQuery(query);
        assertEquals(-100, accountingList.get(0).getAmount());
    }
}
