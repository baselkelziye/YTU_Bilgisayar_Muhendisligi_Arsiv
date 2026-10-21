package org.db.hibernate;

import org.db.dao.SpendingRequestDAO;
import org.db.model.SpendingRequest;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;

/**
 * Created by mgunes on 01.01.2017.
 */
public class SpendingRequestTest {
    private SpendingRequest spendingRequest;
    private List<SpendingRequest> spendingRequestList;
    private SpendingRequestDAO spendingRequestDAO;

    @Before
    public void initialize() {
        spendingRequest = new SpendingRequest();
        spendingRequestList = new ArrayList<SpendingRequest>();
        spendingRequestDAO = new SpendingRequestHibernateImpl();
    }

    @Test
    public void getAllSpendingRequest() {
        spendingRequestList = spendingRequestDAO.getAllSpendingRequest();
        assertEquals(6, spendingRequestList.size());
    }

    @Test
    public void getSpendingRequest() {
        spendingRequest = spendingRequestDAO.getSpendingRequest(36);
        assertEquals(20, spendingRequest.getAmount());
    }

    @Test
    public void getSpendingRequestByQuery() {
        String query = "SELECT * FROM spending_request ORDER BY title DESC;";
        spendingRequestList = spendingRequestDAO.getSpendingRequestByQuery(query);
        assertEquals("Yeni Bilgisayar", spendingRequestList.get(0).getTitle());
    }

    @Test
    public void calculateTotalRequestAmount() {
        int total = spendingRequestDAO.calculateTotalRequestAmount("Örem");
        assertEquals(10, total);
    }

}
