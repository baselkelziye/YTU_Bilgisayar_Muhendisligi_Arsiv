package test;

import org.junit.jupiter.api.Test;
import subscriber.Corporation;
import subscriber.Subscriber;

import static org.junit.jupiter.api.Assertions.*;

class CorporationTest {
    @Test
    void toStringTest1(){
        Subscriber corporation = new Corporation(5, "silivri", "omer gemalmaz",
                1, 10, 2024, "banka", 12, 1);
        String expected = "Corporation{Subscriber{id='5', name='omer gemalmaz', address=silivri }issueDay=1," +
                " issueMonth=10, issueYear=2024, bankName='banka', bankCode=12, accountNumber=1}";
        assertEquals(expected, corporation.getBillingInformation());
    }
    @Test
    void toStringTest2(){
        Subscriber corporation = new Corporation(101, "kadikoy", "george costanza",
                10, 1, 2023, "bank", 10, 2);
        String expected = "Corporation{Subscriber{id='101', name='george costanza', address=kadikoy }issueDay=10," +
                " issueMonth=1, issueYear=2023, bankName='bank', bankCode=10, accountNumber=2}";
        assertEquals(expected, corporation.getBillingInformation());
    }
}