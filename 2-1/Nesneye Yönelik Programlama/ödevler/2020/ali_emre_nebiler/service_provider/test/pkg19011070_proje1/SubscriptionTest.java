package pkg19011070_proje1;

import static junit.framework.Assert.assertEquals;
import org.junit.Before;
import org.junit.Test;
import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;

public class SubscriptionTest {
    
    ServiceProvider testProvider1;
    SubscriptionPlan testSubPlan1, testSubPlan2;
    Subscription testSubscription1;
    Date testSubStartDate1, testSubStartDate2;
    
    @Before
    public void setUp() throws ParseException {
        testProvider1 = new GSMProvider("TURKCELL");
        testSubPlan1 = new SubscriptionPlan("4GB", testProvider1);
        testSubPlan2 = new SubscriptionPlan("8GB", testProvider1);
        testSubStartDate1 = new SimpleDateFormat("dd/MM/yyyy").parse("01/04/2021");
        testSubStartDate2 = new SimpleDateFormat("dd/MM/yyyy").parse("02/05/2025");
        testSubscription1 = new Subscription(testSubStartDate1, testSubPlan1);
    }
    
    @Test
    public void testGetSubscriptionStartDate() {
        System.out.println("--> GET SUB START DATE TEST");
        assertEquals(testSubStartDate1, testSubscription1.getSubscriptionStartDate());
    }

    @Test
    public void testSetSubscriptionStartDate() {
        System.out.println("--> SET SUB START DATE TEST");
        testSubscription1.setSubscriptionStartDate(testSubStartDate2);
        assertEquals(testSubStartDate2, testSubscription1.getSubscriptionStartDate());
    }

    @Test
    public void testGetSubscriptionPlan() {
        System.out.println("--> GET SUB PLAN TEST");
        assertEquals(testSubPlan1, testSubscription1.getSubscriptionPlan());
    }

    @Test
    public void testSetSubscriptionPlan() {
        System.out.println("--> SET SUB PLAN TEST");
        testSubscription1.setSubscriptionPlan(testSubPlan2);
        assertEquals(testSubPlan2, testSubscription1.getSubscriptionPlan());
    }
}
