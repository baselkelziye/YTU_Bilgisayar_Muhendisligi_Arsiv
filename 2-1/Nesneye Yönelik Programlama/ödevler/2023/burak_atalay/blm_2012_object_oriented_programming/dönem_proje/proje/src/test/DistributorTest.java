package test;

import distributor.Distributor;
import distributor.Journal;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;
import subscriber.Corporation;
import subscriber.Individual;
import subscriber.Subscriber;

import static org.junit.jupiter.api.Assertions.*;

class DistributorTest {
    public static Distributor distributor;
    public static Journal j1, j2;
    public static Subscriber s1, s2, s3;

    @BeforeAll
    public static void setUpClass(){
        distributor = new Distributor();
        j1 = new Journal("Leman Dergisi", "1223", 5, 0.5,
                6);
        j2 = new Journal("Bilim Teknik Dergisi", "1221", 2.5, 0.7,
                12);
        s1 = new Individual(1, "sultangazi", "ali demir",
                "123", 10, 2028, 998, 100);
        s2 = new Individual(10, "beyoglu", "murat yıldız",
                "321", 1, 2025, 999, 0);
        s3 = new Corporation(5, "silivri", "omer gemalmaz",
                1, 10, 2024, "banka", 12, 1);
        distributor.addJournal(j1);
        distributor.addSubscriber(s1);
        distributor.addSubscription(j1.getIssn(), s1.getId(), 1, 2023, 2);
    }

    @Test
    void addJournalTest1(){
        boolean actual = distributor.addJournal(j1);
        assertFalse(actual);
    }
    @Test
    void addJournalTest2(){
        boolean actual = distributor.addJournal(j2);
        assertTrue(actual);
    }
    @Test
    void searchJournalTest1(){
        Journal actual = distributor.searchJournal(j2.getIssn());
        assertNull(actual);
    }
    @Test
    void searchJournalTest2(){
        Journal actual = distributor.searchJournal(j1.getIssn());
        assertEquals(actual.getIssn(), j1.getIssn());
    }
    @Test
    void addSubscriberTest1(){
        boolean actual = distributor.addSubscriber(s1);
        assertFalse(actual);
    }
    @Test
    void addSubscriberTest2(){
        boolean actual = distributor.addSubscriber(s2);
        assertTrue(actual);
    }
    @Test
    void searchSubscriberTest1(){
        Subscriber actual = distributor.searchSubscriber(s3.getId());
        assertNull(actual);
    }
    @Test
    void searchSubscriberTest2(){
        Subscriber actual = distributor.searchSubscriber(s1.getId());
        assertEquals(actual.getId(), s1.getId());
    }
    @Test
    void addSubscriptionTest1(){
        boolean actual = distributor.addSubscription(j1.getIssn(), s1.getId(), 1, 2023,
                1);
        assertTrue(actual);
    }
    @Test
    void addSubscriptionTest2(){
        boolean actual = distributor.addSubscription(j2.getIssn(), s1.getId(), 5, 2024,
                5);
        assertFalse(actual);
    }
    @Test
    void addSubscriptionTest3(){
        boolean actual = distributor.addSubscription(j1.getIssn(), s3.getId(), 5, 2024,
                5);
        assertFalse(actual);
    }
}