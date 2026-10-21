package pkg19011070_proje1;

import static junit.framework.Assert.assertEquals;
import org.junit.Before;
import org.junit.Test;

public class CableProviderTest {
    ServiceProvider testProvider1, testProvider2, testProvider3, testProvider4;
    SubscriptionPlan testSubPlan1, testSubPlan2, testSubPlan3, testSubPlan4,
            testSubPlan5, testSubPlan6, testSubPlan7;
    
    @Before
    public void setUp() {
        testProvider1 = new CableProvider("KABLO NET");
        testSubPlan1 = new SubscriptionPlan("4GB", testProvider1);
        testSubPlan2 = new SubscriptionPlan("8GB", testProvider1);
        testSubPlan3 = new SubscriptionPlan("16GB", testProvider1);
        testSubPlan4 = new SubscriptionPlan("4GB", testProvider1);
        testSubPlan5 = new SubscriptionPlan("8GB", testProvider1);
        testSubPlan6 = new SubscriptionPlan("16GB", testProvider1);
        testSubPlan7 = new SubscriptionPlan("12GB", testProvider1);
    }
    
    @Test
    public void testAddSubscriptionPlan1() {
        // add one sub plan
        System.out.println("--> ADD SUB PLAN TEST 1: Add one sub plan");
        testProvider1.addSubscriptionPlan(testSubPlan1);
        
        assertEquals("4GB", testProvider1.findSubscriptionPlan("4GB").getName());
        assertEquals(1, testProvider1.getSubPlanCounter());
    }
    
    @Test
    public void testAddSubscriptionPlan2() {
        // add multiple sub plans
        System.out.println("--> ADD SUB PLAN TEST 2: Add multiple sub plans");
        testProvider1.addSubscriptionPlan(testSubPlan1);
        testProvider1.addSubscriptionPlan(testSubPlan2);
        testProvider1.addSubscriptionPlan(testSubPlan3);
        
        assertEquals("4GB", testProvider1.findSubscriptionPlan("4GB").getName());
        assertEquals("8GB", testProvider1.findSubscriptionPlan("8GB").getName());
        assertEquals("16GB", testProvider1.findSubscriptionPlan("16GB").getName());
        assertEquals(3, testProvider1.getSubPlanCounter());
    }
    
    @Test
    public void testAddSubscriptionPlan3() {
        // add multiple sub plans, some of them are same
        // it shouldn't add the same ones again
        System.out.println("--> ADD SUB PLAN TEST 2: Add multiple and same sub plans");
        testProvider1.addSubscriptionPlan(testSubPlan1);
        testProvider1.addSubscriptionPlan(testSubPlan2);
        testProvider1.addSubscriptionPlan(testSubPlan3);
        testProvider1.addSubscriptionPlan(testSubPlan4);
        testProvider1.addSubscriptionPlan(testSubPlan5);
        testProvider1.addSubscriptionPlan(testSubPlan6);
        testProvider1.addSubscriptionPlan(testSubPlan7);
        
        assertEquals("4GB", testProvider1.findSubscriptionPlan("4GB").getName());
        assertEquals("8GB", testProvider1.findSubscriptionPlan("8GB").getName());
        assertEquals("16GB", testProvider1.findSubscriptionPlan("16GB").getName());
        assertEquals("12GB", testProvider1.findSubscriptionPlan("12GB").getName());
        assertEquals(4, testProvider1.getSubPlanCounter());
    }

    @Test
    public void testFindSubscriptionPlan() {
        System.out.println("--> FIND SUB PLAN TEST");
        testProvider1.addSubscriptionPlan(testSubPlan1);
        testProvider1.addSubscriptionPlan(testSubPlan2);
        // testSubPlan3 is not added
        
        assertEquals(testSubPlan1, testProvider1.findSubscriptionPlan("4GB"));
        assertEquals(testSubPlan2, testProvider1.findSubscriptionPlan("8GB"));
        assertEquals(null, testProvider1.findSubscriptionPlan("16GB"));
    }
    
    @Test
    public void testGetName() {
        System.out.println("--> GET NAME TEST");
        assertEquals("KABLO NET", testProvider1.getName());
    }
    
    @Test
    public void testSetName() {
        System.out.println("--> SET NAME TEST");
        testProvider1.setName("TURK TELEKOM");
        assertEquals("TURK TELEKOM", testProvider1.getName());
    }
    
    @Test
    public void testGetSetSubPlanCounter() {
        System.out.println("--> GET/SET SUB PLAN COUNTER TEST");
        testProvider1.setSubPlanCounter(3);
        assertEquals(3, testProvider1.getSubPlanCounter());
    }
}
