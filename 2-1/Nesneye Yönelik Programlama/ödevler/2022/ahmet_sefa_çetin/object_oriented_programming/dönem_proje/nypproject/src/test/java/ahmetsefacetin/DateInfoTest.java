package ahmetsefacetin;

import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class DateInfoTest {

    DateInfo dateInfo = new DateInfo(5, 6, 2024, 2025);

    @Test
    public void getStartMonth() {
        assertTrue(dateInfo.getStartMonth() == 5);
    }

    @Test
    public void getEndYear() {
        assertTrue(dateInfo.getEndYear() == 2025);
    }

}