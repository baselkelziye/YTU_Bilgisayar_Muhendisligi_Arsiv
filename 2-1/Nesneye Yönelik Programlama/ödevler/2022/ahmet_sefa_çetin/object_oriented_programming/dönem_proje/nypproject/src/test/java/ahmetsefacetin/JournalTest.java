package ahmetsefacetin;

import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class JournalTest {

    Journal journal = new Journal("journal", "1234", 3, 34.5);

    @Test
    public void getIssuePrice() {
        assertEquals(journal.getIssuePrice(), 34.5);
    }

    @Test
    public void getAdress() {
        assertEquals("1234", journal.getIssn());
    }

}