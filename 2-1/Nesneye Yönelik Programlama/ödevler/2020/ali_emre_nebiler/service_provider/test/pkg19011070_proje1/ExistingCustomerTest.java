package pkg19011070_proje1;

import static junit.framework.Assert.assertEquals;
import org.junit.Before;
import org.junit.Test;
import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;

public class ExistingCustomerTest {
    
    ExistingCustomer testCustomer1;
    ServiceProvider testProvider1;
    SubscriptionPlan testSubPlan1;
    Subscription testSubscription1;
    Date testSubStartDate1;
    
    @Before
    public void setUp() throws ParseException {
        testProvider1 = new GSMProvider("TURKCELL");
        testSubPlan1 = new SubscriptionPlan("4GB", testProvider1);
        testSubStartDate1 = new SimpleDateFormat("dd/MM/yyyy").parse("01/04/2021");
        testSubscription1 = new Subscription(testSubStartDate1, testSubPlan1);
    }
    
    @Test
    public void testExistingCustomer1() {
        // create a customer without a subscription
        System.out.println("--> CREATE CUSTOMER TEST 1: Without subscription");
        testCustomer1 = new ExistingCustomer("30123456789", "ALI EMRE NEBILER");
        
        assertEquals("ALI EMRE NEBILER", testCustomer1.getName());
        assertEquals("30123456789", testCustomer1.getCitizenshipNr());
        assertEquals(null, testCustomer1.getSubscription());
    }
    
    @Test
    public void testExistingCustomer2() {
        // create a customer with a subscription
        System.out.println("--> CREATE CUSTOMER TEST 2: With subscription");
        testCustomer1 = new ExistingCustomer("21012345678", "EZGI YILMAZ", testSubscription1);
        
        assertEquals("EZGI YILMAZ", testCustomer1.getName());
        assertEquals("21012345678", testCustomer1.getCitizenshipNr());
        assertEquals(testSubscription1, testCustomer1.getSubscription());
    }
    
    @Test
    public void testGetSetSubscription() {
        System.out.println("--> GET/SET SUBSCRIPTION TEST");
        testCustomer1 = new ExistingCustomer("30123456789", "ALI EMRE NEBILER");
        testCustomer1.setSubscription(testSubscription1);
        
        assertEquals(testSubscription1, testCustomer1.getSubscription());
    }
}
