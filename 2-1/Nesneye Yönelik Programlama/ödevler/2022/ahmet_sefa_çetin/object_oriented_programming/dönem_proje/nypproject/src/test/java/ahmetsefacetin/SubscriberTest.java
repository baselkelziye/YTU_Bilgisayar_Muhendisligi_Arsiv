package ahmetsefacetin;

import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class SubscriberTest {

    Subscriber individual = new Individual(423, "burak", "fdgdfgdf", 25, "4564-2344", 1, 2034, 212);

    @Test
    public void getCCV() {
        assertTrue(individual.getBalance() == 25);
    }

    @Test
    public void getExpireYear() {
        assertEquals("burak", individual.getName());
    }
}