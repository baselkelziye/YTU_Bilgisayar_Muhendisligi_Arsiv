package test;

import distributor.DateInfo;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DateInfoTest {
    @Test
    void betweenDateTest1(){
        DateInfo dateInfo = new DateInfo(11, 2022);
        boolean actual = dateInfo.betweenDate(11,2023);
        assertFalse(actual);
    }
    @Test
    void betweenDateTest2(){
        DateInfo dateInfo = new DateInfo(5, 2024);
        boolean actual = dateInfo.betweenDate(1,2025);
        assertTrue(actual);
    }
    @Test
    void toStringTest1(){
        DateInfo dateInfo = new DateInfo(11, 2022);
        String actual = dateInfo.toString();
        String expected = "DateInfo{startMonth=11, endMonth=10, startYear=2022, endYear=2023}";
        assertEquals(expected, actual);
    }
    @Test
    void toStringTest2(){
        DateInfo dateInfo = new DateInfo(5, 2024);
        String actual = dateInfo.toString();
        String expected = "DateInfo{startMonth=5, endMonth=4, startYear=2024, endYear=2025}";
        assertEquals(expected, actual);
    }
}