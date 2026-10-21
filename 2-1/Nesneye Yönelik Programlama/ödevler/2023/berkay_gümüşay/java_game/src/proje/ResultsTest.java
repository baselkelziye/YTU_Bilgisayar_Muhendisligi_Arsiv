package Proje;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import java.util.ArrayList;

public class ResultsTest {

    private Results results;
    private User child;
    private ArrayList<Question> quests;
    private int[] resultsArray;
    private String[] answers;
    private int score;
    private int[] parameters;
    private int[] time;
    private String startDate;

    @Before
    public void setUp() {
        child = new User("John", "Doe", "password", "Child");

        quests = new ArrayList<>();
        quests.add(new Question(5, 3, 15));
        quests.add(new Question(4, 2, 8));
        quests.add(new Question(10, 6, 60));

        resultsArray = new int[] { 3, 3, 0, 60 };
        answers = new String[] { "15", "8", "60" };
        score = 100;
        parameters = new int[] { 10, 10, 10 };
        time = new int[] { 15, 10, 20 };
        startDate = "2023-06-01";

        results = new Results(child, quests, resultsArray, answers, score, parameters, time, startDate);
    }

    @Test
    public void testGetChild() {
        assertEquals(child, results.getChild());
    }

    @Test
    public void testSetChild() {
    	// Results classına Child atama
        User newChild = new User("Jane", "Smith", "password", "Child");
        results.setChild(newChild);
        assertEquals(newChild, results.getChild());
    }

    @Test
    public void testGetQuests() {
    	// Results classının Sorularını alma
        assertEquals(quests, results.getQuests());
    }

    @Test
    public void testSetQuests() {
    	// Results classının Sorularını atama
        ArrayList<Question> newQuests = new ArrayList<>();
        newQuests.add(new Question(2, 2, 4));
        newQuests.add(new Question(3, 3, 9));
        results.setQuests(newQuests);
        assertEquals(newQuests, results.getQuests());
    }

    @Test
    public void testGetResults() {
    	// Soru Sayısı , Doğru Sayısı , Yanlış Sayısı , Süre değerlerini alma
        assertArrayEquals(resultsArray, results.getResults());
    }

    @Test
    public void testSetResults() {
    	// Soru Sayısı , Doğru Sayısı , Yanlış Sayısı , Süre değerlerini atama
        int[] newResultsArray = new int[] { 5, 5, 0, 120 };
        results.setResults(newResultsArray);
        assertArrayEquals(newResultsArray, results.getResults());
    }

    @Test
    public void testGetAnswers() {
    	// Cevapları alma
        assertArrayEquals(answers, results.getAnswers());
    }

    @Test
    public void testSetAnswers() {
    	// Cevapları atama
        String[] newAnswers = new String[] { "4", "9", "36" };
        results.setAnswers(newAnswers);
        assertArrayEquals(newAnswers, results.getAnswers());
    }

    @Test
    public void testPrintQuestionInfo() {
    	// Genel Sonuçları Panele Yazdırma
        String expected = " Soru Sayısı: 3  |  Doğru Sayısı: 3  |  Yanlış Sayısı: 0  |  Bitirme Süresi: 60 Saniye";
        assertEquals(expected, results.printQuestionInfo(resultsArray));
    }

    @Test
    public void testPrintAllQuests() {
    	// Soruları Teker Teker Panele Yazdırma
        String expected = "1.Soru ) 5 * 3 = 15 Verilen Cevap: 15\n";
        expected += "2.Soru ) 4 * 2 = 8 Verilen Cevap: 8\n";
        expected += "3.Soru ) 10 * 6 = 60 Verilen Cevap: 60\n";
        assertEquals(expected, results.printAllQuests(quests, answers, 0));
    }

    @Test
    public void testReturnOneString() {
    	// CSV Verisi Olarak Yazdırma
        String expected = "5,3,15,15,15:";
        expected += "4,2,8,8,10:";
        expected += "10,6,60,60,20:";
        expected += "3,3,0,60,100:10,10,10";
        assertEquals(expected, results.returnOneString(quests, resultsArray, answers, score, parameters, time));
    }

    @Test
    public void testGetScore() {
    	// Skoru alma
        assertEquals(score, results.getScore());
    }

    @Test
    public void testSetScore() {
    	// Skoru atama
        int newScore = 90;
        results.setScore(newScore);
        assertEquals(newScore, results.getScore());
    }

    @Test
    public void testGetParameters() {
    	// A,B,N değerlerini alma
        assertArrayEquals(parameters, results.getParameters());
    }

    @Test
    public void testSetParameters() {
    	// A,B,N değerlerini atama
        int[] newParameters = new int[] { 5, 5, 5 };
        results.setParameters(newParameters);
        assertArrayEquals(newParameters, results.getParameters());
    }

    @Test
    public void testGetTime() {
        assertArrayEquals(time, results.getTime());
    }

    @Test
    public void testSetTime() {
        int[] newTime = new int[] { 20, 15, 25 };
        results.setTime(newTime);
        assertArrayEquals(newTime, results.getTime());
    }

    @Test
    public void testGetStartDate() {
        assertEquals(startDate, results.getStartDate());
    }

    @Test
    public void testSetStartDate() {
        String newStartDate = "2023-06-02";
        results.setStartDate(newStartDate);
        assertEquals(newStartDate, results.getStartDate());
    }

    @Test
    public void testGameToCSV() {
        String expected = "John;Doe;2023-06-01;5*3;15;15;15;";
        expected += "4*2;8;8;10;";
        expected += "10*6;60;60;20;";
        expected += "100;60";
        assertEquals(expected, results.gameToCSV());
    }
}