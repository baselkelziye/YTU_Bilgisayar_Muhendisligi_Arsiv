package ahmetsefacetin;

import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class IndividualTest {

    Subscriber individual = new Individual(1234, "ahmet", "asdasd", 10.9, "1234-5678", 5, 2031, 345);

    @Test
    public void getCCV() {
        assertTrue(individual.getBalance() == 10.9);
    }

    @Test
    public void getExpireYear() {
        assertEquals("ahmet", individual.getName());
    }
}