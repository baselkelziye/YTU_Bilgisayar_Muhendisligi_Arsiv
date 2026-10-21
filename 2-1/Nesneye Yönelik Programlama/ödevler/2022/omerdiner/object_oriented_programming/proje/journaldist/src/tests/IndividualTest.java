package tests;

import backend.Individual;
import junit.framework.TestCase;

public class IndividualTest extends TestCase {

    private Individual individual;
    private Individual individual2;

    protected void setUp() {
        individual = new Individual("Kisi1", "istanbul");
        individual2 = new Individual("Kisi2", "bilecik", "123456789", 12, 2020, 123);

    }


    public void testgetName() {
        assertEquals("Kisi1", individual.getName());
    }


    public void testsetName() {
        individual.setName("Kisi3");
        assertEquals("Kisi3", individual.getName());
    }


    public void testgetAddress() {
        assertEquals("bilecik", individual2.getAddress());
    }

    public void testsetAddress() {
        individual2.setAddress("istanbul");
        assertEquals("istanbul", individual2.getAddress());
    }


    public void testgetCreditCardNumber() {
        individual.setCreditCardNo("5555");
        assertEquals("5555", individual.getCreditCardNo());
        assertEquals("123456789", individual2.getCreditCardNo());
    }


}
