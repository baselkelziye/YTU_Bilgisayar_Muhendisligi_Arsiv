package tests;

import backend.DateInfo;
import junit.framework.TestCase;

public class DateInfoTest extends TestCase {

    private DateInfo dateInfo;

    protected void setUp() {
        dateInfo = new DateInfo(1, 6, 2020);
    }

    public void testgetStartMonth() {
        assertEquals(1, dateInfo.getStartMonth());
    }

    public void testsetStartMonth() {
        dateInfo.setStartMonth(2);
        assertEquals(2, dateInfo.getStartMonth());
    }

    public void testgetEndMonth() {
        assertEquals(6, dateInfo.getEndMonth());
    }

    public void testsetEndMonth() {
        dateInfo.setEndMonth(7);
        assertEquals(7, dateInfo.getEndMonth());
    }

    public void testgetStartYear() {
        assertEquals(2020, dateInfo.getStartYear());
    }

    public void testsetStartYear() {
        dateInfo.setStartYear(2021);
        assertEquals(2021, dateInfo.getStartYear());
    }
}
