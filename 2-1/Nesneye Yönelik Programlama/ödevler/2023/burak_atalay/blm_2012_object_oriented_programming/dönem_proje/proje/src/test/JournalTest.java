package test;

import distributor.Journal;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class JournalTest {
    @Test
    void toStringTest1(){
        Journal journal = new Journal("Leman Dergisi", "1223", 5, 0.5,
                6);
        String expected = "Journal{name='Leman Dergisi', issn='1223', issuePrice=5.0, discountRatio=0.5," +
                " frequency=6}";
        assertEquals(expected, journal.toString());
    }
    @Test
    void toStringTest2(){
        Journal journal = new Journal("Bilim Teknik Dergisi", "1221", 2.5, 0.7,
                12);
        String expected = "Journal{name='Bilim Teknik Dergisi', issn='1221', issuePrice=2.5, discountRatio=0.7," +
                " frequency=12}";
        assertEquals(expected, journal.toString());
    }

}