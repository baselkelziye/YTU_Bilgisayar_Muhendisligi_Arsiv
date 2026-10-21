package ahmetsefacetin;

import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class CorporationTest {

    Subscriber corporaiton = new Corporation(1234, "ahmet", "asdasd", 120, 1234, "myBank", 4, 11, 2026, 123);

    @Test
    public void getId() {
        assertTrue(corporaiton.getId() == 1234);
    }

    @Test
    public void getAdress() {
        assertEquals("asdasd", corporaiton.getAdress());
    }
}