package tests;

import backend.*;
import junit.framework.TestCase;

import java.util.Hashtable;
import java.util.Vector;

public class DistributorTest extends TestCase {

    private Distributor distributor;
    private Journal journal1;
    private Journal journal2;
    private Subscriber subscriber1;
    private Subscriber subscriber2;

    private Subscription subscription1;
    private Subscription subscription2;

    private Hashtable<String, Journal> journals;
    private Vector<Subscriber> subscribers;

    //setup method
    protected void setUp() {
        journals = new Hashtable<>();
        subscribers = new Vector<>();

        journal1 = new Journal("Journal1", "1056", 2, 50.0);
        journal2 = new Journal("Journal2", "1055", 3, 120.0);
        subscriber1 = new Corporation("Corporation1", "address1");
        subscriber2 = new Individual("Person1", "address2");

        DateInfo dateInfo2 = new DateInfo(1, 6, 2020);
        DateInfo dateInfo1 = new DateInfo(1, 6, 2021);

        PaymentInfo paymentInfo2 = new PaymentInfo(0.1);
        PaymentInfo paymentInfo1 = new PaymentInfo(0.1);

        subscription1 = new Subscription(dateInfo1, 1, journal1, subscriber1);
        subscription2 = new Subscription(dateInfo2, 1, journal2, subscriber2);

        subscribers.add(subscriber1);
        subscribers.add(subscriber2);

        journals.put(journal1.getIssn(), journal1);
        journals.put(journal2.getIssn(), journal2);

        distributor = new Distributor(journals, subscribers);

    }


    public void testaddJournal() {

        //zaten olan bir journal eklenemez
        assertFalse(distributor.addJournal(journal1));

        Journal journal3 = new Journal("Journal3", "1088", 3, 120.0);
        assertTrue(distributor.addJournal(journal3));


    }

    public void testsearchJournal() {
        assertEquals(journal1, distributor.searchJournal("1056"));
        assertEquals(journal2, distributor.searchJournal("1055"));

        //olmayan bir journal aranırsa null döner
        assertNull(distributor.searchJournal("1054"));
    }

    public void testaddSubscriber() {
        //zaten olan bir abone eklenemez
        assertFalse(distributor.addSubscriber(subscriber1));
        assertFalse(distributor.addSubscriber(subscriber2));

        //yeni bir abone eklenebilir
        Subscriber subscriber3 = new Corporation("Corporation3", "address3");
        assertTrue(distributor.addSubscriber(subscriber3));

    }

    public void testsearchSubscriber() {
        assertEquals(subscriber1, distributor.searchSubscriber("Corporation1"));
        assertEquals(subscriber2, distributor.searchSubscriber("Person1"));
        assertNull(distributor.searchSubscriber("Person2"));
    }

    public void testaddSubscription() {

        //olan bir journala abone olabilir
        assertTrue(distributor.addSubscription("1056", subscriber1, subscription1));
        assertTrue(distributor.addSubscription("1055", subscriber2, subscription2));


        //olmayan journala abone olamaz
        assertFalse(distributor.addSubscription("1099", subscriber1, subscription2));

    }
}