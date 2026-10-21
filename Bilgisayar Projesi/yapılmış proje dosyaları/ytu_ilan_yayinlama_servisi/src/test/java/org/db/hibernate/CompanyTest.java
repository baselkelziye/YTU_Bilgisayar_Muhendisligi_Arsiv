package org.db.hibernate;

import static org.junit.Assert.assertEquals;

import org.db.dao.UserDAO;
import org.db.model.Company;
import org.db.model.UserType;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class CompanyTest {
    private Company company;
    private CompanyHibernateImpl companyDAO;

    @Before
    public void initialize() {
        companyDAO = new CompanyHibernateImpl();

        company = new Company();
        company.setName("test company");
        company.setUserName("test user company");
        company.setCompanyName("test company name");
        company.setPassword("test password");

        UserType type = new UserType();
        type.setType_no(2);
        company.setUserTypeNo(type);
    }
    
    @Test
    public void saveCompany() {
    	assertEquals(true, companyDAO.saveCompany(company));
    }

    @After
    public void deleteCompany() {
        companyDAO.deleteCompany(company);
    }
}
