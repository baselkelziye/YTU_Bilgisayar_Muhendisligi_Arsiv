package tests;

import backend.*;
import junit.framework.TestCase;

public class SubscriptionTest extends TestCase {

    private Subscription subscription;
    private Journal journal;
    private Subscriber subscriber;

    protected void setUp() {
        journal = new Journal("Journal1", "1059", 3, 57.0);
        subscriber = new Corporation("Corporation1", "address1");

        DateInfo dateInfo = new DateInfo(2, 3, 2024);
        PaymentInfo paymentInfo = new PaymentInfo(0.25);

        subscription = new Subscription(dateInfo, 1, journal, subscriber);
    }

    public void testgetJournal() {
        assertEquals(journal, subscription.getJournal());
    }


    public void testgetSubscriber() {
        assertEquals(subscriber, subscription.getSubscriber());
    }


    public void testacceptPayment() {
        subscription.acceptPayment(100);
        assertEquals(100.0, subscription.getPayment().getReceivedPayment());
    }

    public void testcanSend() {
        //odenen para olmadan gonderilemez
        assertFalse(subscription.canSend(8, 2024));

        subscription.acceptPayment(1000);
        assertFalse(subscription.canSend(1, 2023));
        assertFalse(subscription.canSend(9, 2025));
        assertTrue(subscription.canSend(8, 2024));
        assertTrue(subscription.canSend(9, 2024));
        assertFalse(subscription.canSend(1, 2024));
    }

    public void testgetDateInfo() {
        assertEquals(2, subscription.getDates().getStartMonth());
        assertEquals(3, subscription.getDates().getEndMonth());
        assertEquals(2024, subscription.getDates().getStartYear());
    }


    public void testgetCopies() {
        assertEquals(1, subscription.getCopies());
    }


}
