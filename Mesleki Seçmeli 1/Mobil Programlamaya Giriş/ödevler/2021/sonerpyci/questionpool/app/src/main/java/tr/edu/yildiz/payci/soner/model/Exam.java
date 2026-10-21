package tr.edu.yildiz.payci.soner.model;

import java.io.Serializable;
import java.util.ArrayList;

public class Exam implements Serializable {

    private long id;
    private long userId;
    private String examName;
    private long difficulty;
    private long minDuration;
    private long maxDuration;
    private ArrayList<Question> questions;
    public Exam() {
    }

    public Exam(long id, long userId, String examName, long difficulty, long minDuration, long maxDuration) {
        this.id = id;
        this.userId = userId;
        this.examName = examName;
        this.difficulty = difficulty;
        this.minDuration = minDuration;
        this.maxDuration = maxDuration;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public long getUserId() {
        return userId;
    }

    public void setUserId(long userId) {
        this.userId = userId;
    }

    public String getExamName() {
        return examName;
    }

    public void setExamName(String examName) {
        this.examName = examName;
    }

    public long getDifficulty() {
        return difficulty;
    }

    public void setDifficulty(long difficulty) {
        this.difficulty = difficulty;
    }

    public long getMinDuration() {
        return minDuration;
    }

    public void setMinDuration(long minDuration) {
        this.minDuration = minDuration;
    }

    public long getMaxDuration() {
        return maxDuration;
    }

    public void setMaxDuration(long maxDuration) {
        this.maxDuration = maxDuration;
    }

    public ArrayList<Question> getQuestions() {
        return questions;
    }

    public void setQuestions(ArrayList<Question> questions) {
        this.questions = questions;
    }
}
