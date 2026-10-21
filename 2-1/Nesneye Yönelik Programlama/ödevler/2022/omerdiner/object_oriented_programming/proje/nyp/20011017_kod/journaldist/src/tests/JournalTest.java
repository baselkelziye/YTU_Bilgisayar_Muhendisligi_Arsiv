package tests;

import backend.*;
import junit.framework.TestCase;


public class JournalTest extends TestCase {
    private Journal journal;
    private Subscription subscription;
    private DateInfo dateInfo;

    private PaymentInfo paymentInfo;

    private Subscriber subscriber;


    protected void setUp() {
            journal = new Journal("Journal", "10124", 3, 10.0);
            dateInfo = new DateInfo(1, 5,  2020);
            paymentInfo = new PaymentInfo(0.3);
            subscriber = new Individual("John Doe", "123 Main St.");
            subscription = new Subscription(dateInfo, 1, journal, subscriber);

    }

   public void testgetIssuePrice() {
            assertEquals(10.0, journal.getIssuePrice());
    }

   public void testsetIssuePrice() {
            journal.setIssuePrice(20.0);
            assertEquals(20.0, journal.getIssuePrice());
    }

  public  void testgetSubscriptions() {
            assertEquals(0, journal.getSubscriptions().size());
    }

    public void testaddSubscription() {
            journal.addSubscription(subscription);
            assertEquals(1, journal.getSubscriptions().size());
    }

    public void testgetName() {
            assertEquals("Journal", journal.getName());
    }




}
