package test;

import org.junit.jupiter.api.Test;
import subscriber.Individual;
import subscriber.Subscriber;

import static org.junit.jupiter.api.Assertions.*;

class IndividualTest {
    @Test
    void toStringTest1(){
        Subscriber individual = new Individual(1, "sultangazi", "ali demir",
                "123", 10, 2028, 998, 100);
        String expected = "Individual{Subscriber{id='1', name='ali demir', address=sultangazi }" +
                "creditCard=CreditCard{creditCardNr='123', expireMonth=10, expireYear=2028, CCV=998," +
                " balance=100.0}}";
        assertEquals(expected, individual.getBillingInformation());
    }
    @Test
    void toStringTest2(){
        Subscriber individual = new Individual(10, "beyoglu", "murat yıldız",
                "321", 1, 2025, 999, 0);
        String expected = "Individual{Subscriber{id='10', name='murat yıldız', address=beyoglu }" +
                "creditCard=CreditCard{creditCardNr='321', expireMonth=1, expireYear=2025, CCV=999," +
                " balance=0.0}}";
        assertEquals(expected, individual.getBillingInformation());
    }
}