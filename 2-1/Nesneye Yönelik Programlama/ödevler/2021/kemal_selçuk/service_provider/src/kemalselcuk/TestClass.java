package kemalselcuk;

import java.util.Date;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class TestClass {
    @Test
    public void testFindSubscriptionPlan() { //Controlling if the search is true
        GSMProvider provider = new GSMProvider("TURKCELL");
        SubscriptionPlan test = new SubscriptionPlan("4GB");
        provider.addSubscriptionPlan(test);
        assertTrue(provider.findSubscriptionPlan("4GB").equals(test));
    }
    @Test
    public void testAddSubscriptionPlan() {  //Controlling if the plan is added
        GSMProvider provider = new GSMProvider("TURKCELL");
        provider.addSubscriptionPlan(new SubscriptionPlan("4GB"));
        assertTrue(provider.findSubscriptionPlan("4GB")!= null);


    }
    @Test
    public void testGSMProvider() {
         GSMProvider provider = new GSMProvider("TURKCELL");
         provider.addSubscriptionPlan(new SubscriptionPlan("4GB"));
         assertTrue(provider.findSubscriptionPlan("4GB")!= null);
         assertTrue(provider.getName().equals("TURKCELL"));
    }
    @Test
   public void testCableProvider() {
        CableProvider provider = new CableProvider("TURKCELL");
        provider.addSubscriptionPlan(new SubscriptionPlan("4GB"));
        assertTrue(provider.findSubscriptionPlan("4GB")!= null);
        assertTrue(provider.getName().equals("TURKCELL"));
   }
    @Test
   public void testExistingCustomer() {
       ExistingCustomer customer = new ExistingCustomer("19011916");
       assertTrue(customer.getCitizenshipNr().equals("19011916"));
       customer.setMail("gmail");
       assertTrue(customer.getMail().equals("gmail"));
   }
    @Test
    public void testPossibleCustomer() {
        PossibleCustomer customer = new PossibleCustomer("19011916");
        assertTrue(customer.getCitizenshipNr().equals("19011916"));
        customer.setMail("gmail");
        assertTrue(customer.getMail().equals("gmail"));
    }
    @Test
   public void testSubscription() {
       Date d = new Date();
       SubscriptionPlan plan = new SubscriptionPlan("4GB");
       Subscription sub = new Subscription(d,plan);
       assertTrue(plan == sub.getSubscriptionPlan());
       assertTrue(d == sub.getSubscriptionStartDate());
   }
   

}
