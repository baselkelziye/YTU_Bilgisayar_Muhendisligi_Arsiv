package test;

import distributor.Journal;
import distributor.Subscription;
import org.junit.jupiter.api.Test;
import subscriber.Corporation;
import subscriber.Individual;
import subscriber.Subscriber;

import static org.junit.jupiter.api.Assertions.*;

class SubscriptionTest {
    @Test
    void canSendTest1(){
        Subscriber corporation = new Corporation(5, "silivri", "omer gemalmaz",
                1, 10, 2024, "banka", 12, 1);
        Journal journal = new Journal("Leman Dergisi", "1223", 5, 0.5,
                6);
        Subscription subscription = new Subscription(1, 2023, journal, corporation, 2);
        boolean actual = subscription.canSend(3);
        assertTrue(actual);
    }
    @Test
    void canSendTest2(){
        Subscriber individual = new Individual(10, "beyoglu", "murat yıldız",
                "321", 1, 2025, 999, 2.5);
        Journal journal = new Journal("Leman Dergisi", "1223", 5, 0.5,
                6);
        Subscription subscription = new Subscription(1, 2023, journal, individual, 3);
        boolean actual = subscription.canSend(3);
        assertFalse(actual);
    }
    @Test
    void toStringTest1(){
        Subscriber corporation = new Corporation(5, "silivri", "omer gemalmaz",
                1, 10, 2024, "banka", 12, 1);
        Journal journal = new Journal("Leman Dergisi", "1223", 5, 0.5,
                6);
        Subscription subscription = new Subscription(1, 2023, journal, corporation, 2);
        String actual = subscription.toString();
        String expected = "Subscription{dates=DateInfo{startMonth=1, endMonth=12, startYear=2023, " +
                "endYear=2023}, payment=PaymentInfo{discountRatio=0.5, receivedPayment=0.0}, " +
                "journal=Journal{name='Leman Dergisi', issn='1223', issuePrice=5.0, discountRatio=0.5, " +
                "frequency=6}, subscriber=Corporation{Subscriber{id='5', name='omer gemalmaz'," +
                " address=silivri }" + "issueDay=1, issueMonth=10, issueYear=2024, bankName='banka'," +
                " bankCode=12, accountNumber=1}, copies=2}";
        assertEquals(expected, actual);
    }
    @Test
    void toStringTest2(){
        Subscriber individual = new Individual(10, "beyoglu", "murat yıldız",
                "321", 1, 2025, 999, 2.5);
        Journal journal = new Journal("Leman Dergisi", "1223", 5, 0.5,
                6);
        Subscription subscription = new Subscription(1, 2023, journal, individual, 3);
        String actual = subscription.toString();
        String expected = "Subscription{dates=DateInfo{startMonth=1, endMonth=12, startYear=2023," +
                " endYear=2023}, payment=PaymentInfo{discountRatio=0.5, receivedPayment=0.0}," +
                " journal=Journal{name='Leman Dergisi', issn='1223', issuePrice=5.0, discountRatio=0.5," +
                " frequency=6}, subscriber=Individual{Subscriber{id='10', name='murat yıldız'," +
                " address=beyoglu }creditCard=CreditCard{creditCardNr='321', expireMonth=1, expireYear=2025," +
                " CCV=999, balance=2.5}}, copies=3}";
        assertEquals(expected, actual);
    }
}