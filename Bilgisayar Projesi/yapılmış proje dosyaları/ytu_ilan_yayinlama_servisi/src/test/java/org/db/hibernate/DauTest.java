package org.db.hibernate;

import static org.junit.Assert.*;

import org.db.dao.DonationAcceptUnitDAO;
import org.db.model.DonationAcceptUnit;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import javax.enterprise.context.Initialized;
import java.util.Date;

public class DauTest {
    private DonationAcceptUnit dau;
    private DonationAcceptUnitDAO dauDAO;
	
	@Before
	public void initialize() {
	    dauDAO = new DauHibernateImpl();

	    dau = new DonationAcceptUnit();
        dau.setUnitName("test dau");
        dau.setBalance(0);
        dau.setCreatedDate(new Date());
    }

    @Test
    public void saveDonationAcceptUnit() {
        assertEquals(true, dauDAO.saveDonationAcceptUnit(dau));
    }

    @After
    public void deleteDau() {
        assertEquals(true, dauDAO.deleteDau(dau.getUnitName()));
    }

}
