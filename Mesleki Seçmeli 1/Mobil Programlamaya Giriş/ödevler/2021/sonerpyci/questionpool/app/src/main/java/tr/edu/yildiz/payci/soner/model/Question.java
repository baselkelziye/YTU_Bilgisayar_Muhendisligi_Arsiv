package tr.edu.yildiz.payci.soner.model;

import java.io.Serializable;
import java.util.Date;

public class Question implements Serializable {
    private long id;
    private long userId;
    private String text;
    private String a;
    private String b;
    private String c;
    private String d;
    private String e;
    private String correctAnswer;
    private QuestionMedia questionMedia;
    private boolean isSelected;

    public Question(long id, long userId, String text, String a, String b, String c, String d, String e, String correctAnswer) {
        this.id = id;
        this.userId = userId;
        this.text = text;
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.e = e;
        this.correctAnswer = correctAnswer;
    }

    public Question(long id, long userId, String text, String a, String b, String c, String d, String e, String correctAnswer, QuestionMedia questionMedia) {
        this.id = id;
        this.userId = userId;
        this.text = text;
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.e = e;
        this.correctAnswer = correctAnswer;
        this.questionMedia = questionMedia;
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

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public String getA() {
        return a;
    }

    public void setA(String a) {
        this.a = a;
    }

    public String getB() {
        return b;
    }

    public void setB(String b) {
        this.b = b;
    }

    public String getC() {
        return c;
    }

    public void setC(String c) {
        this.c = c;
    }

    public String getD() {
        return d;
    }

    public void setD(String d) {
        this.d = d;
    }

    public String getE() {
        return e;
    }

    public void setE(String e) {
        this.e = e;
    }

    public String getCorrectAnswer() {
        return correctAnswer;
    }

    public void setCorrectAnswer(String correctAnswer) {
        this.correctAnswer = correctAnswer;
    }

    public QuestionMedia getQuestionMedia() {
        return questionMedia;
    }

    public void setQuestionMedia(QuestionMedia questionMedia) {
        this.questionMedia = questionMedia;
    }

    public boolean getIsSelected() {
        return isSelected;
    }

    public void setIsSelected(boolean isSelected) {
        this.isSelected = isSelected;
    }
}
