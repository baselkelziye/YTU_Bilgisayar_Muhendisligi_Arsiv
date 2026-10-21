package pkg19011070_proje1;

import static junit.framework.Assert.assertEquals;
import org.junit.Before;
import org.junit.Test;

public class SubscriptionPlanTest {
    
    ServiceProvider testProvider1, testProvider2;
    SubscriptionPlan testSubPlan1;
    
    @Before
    public void setUp() {
        testProvider1 = new GSMProvider("TURKCELL");
        testProvider2 = new GSMProvider("VODAFONE");
        testSubPlan1 = new SubscriptionPlan("4GB", testProvider1);
    }
    
    @Test
    public void testGetServiceProvider() {
        System.out.println("--> GET PROVIDER TEST");
        assertEquals(testProvider1, testSubPlan1.getServiceProvider());
    }

    @Test
    public void testSetServiceProvider() {
        System.out.println("--> SET PROVIDER TEST");
        testSubPlan1.setServiceProvider(testProvider2);
        assertEquals(testProvider2, testSubPlan1.getServiceProvider());
    }
    
    @Test
    public void testGetSetName() {
        System.out.println("--> GET/SET NAME TEST");
        testSubPlan1.setName("8GB");
        assertEquals("8GB", testSubPlan1.getName());
    }
}
