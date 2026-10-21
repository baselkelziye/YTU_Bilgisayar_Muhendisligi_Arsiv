package tests;

import backend.Corporation;
import junit.framework.TestCase;

public class CorporationTest extends TestCase {

    private Corporation corporation;

    protected void setUp() {
        corporation = new Corporation("Test", "istanbul");
    }

    public void testgetBankCode() {
        assertEquals(0, corporation.getBankCode());
    }


    public void testsetBankCode() {
        corporation.setBankCode(5);
        assertEquals(5, corporation.getBankCode());
    }

    public void testgetName() {
        assertEquals("Test", corporation.getName());
    }


    public void testsetBankName() {
        corporation.setBankName("bank1");
        assertEquals("bank1", corporation.getBankName());
    }

    public void testgetIssueDay() {
        assertEquals(0, corporation.getIssueDay());
    }


    public void testsetIssueDay() {
        corporation.setIssueDay(5);
        assertEquals(5, corporation.getIssueDay());
    }

    public void testgetIssueMonth() {
        assertEquals(0, corporation.getIssueMonth());
    }

    public void testsetIssueMonth() {
        corporation.setIssueMonth(5);
        assertEquals(5, corporation.getIssueMonth());
    }

    public void testgetIssueYear() {
        assertEquals(0, corporation.getIssueYear());
    }


    public void testsetIssueYear() {
        corporation.setIssueYear(5);
        assertEquals(5, corporation.getIssueYear());
    }

    public void testgetAccountNumber() {
        assertEquals(0, corporation.getAccountNumber());
    }


    public void testsetAccountNumber() {
        corporation.setAccountNumber(5);
        assertEquals(5, corporation.getAccountNumber());
    }


}
