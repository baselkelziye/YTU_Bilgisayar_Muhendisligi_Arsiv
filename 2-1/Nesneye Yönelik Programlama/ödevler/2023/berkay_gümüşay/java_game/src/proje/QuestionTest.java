package Proje;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

public class QuestionTest {

    private Question question;

    @Before
    public void setUp() {
        question = new Question(5, 3, 15);
    }

    @Test
    public void testGetNum1() {
    	// Çarpımın ilk parametresini alma
        assertEquals(5, question.getNum1());
    }

    @Test
    public void testSetNum1() {
    	// Çarpımın ilk parametresini atama
        question.setNum1(10);
        assertEquals(10, question.getNum1());
    }

    @Test
    public void testGetNum2() {
    	// Çarpımın ikinci parametresini alma
        assertEquals(3, question.getNum2());
    }

    @Test
    public void testSetNum2() {
    	// Çarpımın ikinci parametresini atama
        question.setNum2(6);
        assertEquals(6, question.getNum2());
    }

    @Test
    public void testGetAnswer() {
    	// Çarpımın sonucunu alma
        assertEquals(15, question.getAnswer());
    }

    @Test
    public void testSetAnswer() {
    	// Çarpımın sonucunu atama
        question.setAnswer(25);
        assertEquals(25, question.getAnswer());
    }

    @Test
    public void testGetString() {
    	// Çarpımın tümünü CSV verisi olarak alma
        String expected = "5,3,15,";
        assertEquals(expected, question.getString(5, 3, 15));
    }

    @Test
    public void testPanelQuestions() {
    	// Çarpımın tümünü çarpım sembolü ile alma
        String expected = "5 * 3 = 15";
        assertEquals(expected, question.panelQuestions(5, 3, 15));
    }
}