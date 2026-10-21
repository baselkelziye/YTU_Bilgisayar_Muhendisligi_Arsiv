package com.example.barissemerci;

import android.net.Uri;

import java.io.Serializable;
import java.net.URI;

public class Question implements Serializable {
    private String question;
    private String optionA;
    private String optionB;
    private String optionC;
    private String optionD;
    private String optionE;
    private String uriImage;
    private String uriVideo;
    private String uriSound;
    private char rightAnswer;

    public String getUriImage() {
        return uriImage;
    }

    public void setUriImage(String uriImage) {
        this.uriImage = uriImage;
    }

    public String getUriVideo() {
        return uriVideo;
    }

    public void setUriVideo(String uriVideo) {
        this.uriVideo = uriVideo;
    }

    public String getUriSound() {
        return uriSound;
    }

    public void setUriSound(String uriSound) {
        this.uriSound = uriSound;
    }

    public Question() {
    }

    public Question(String question, String optionA, String optionB, String optionC, String optionD, String optionE) {
        this.question = question;
        this.optionA = optionA;
        this.optionB = optionB;
        this.optionC = optionC;
        this.optionD = optionD;
        this.optionE = optionE;
    }

    public char getRightAnswer() {
        return rightAnswer;
    }

    public void setRightAnswer(char rightAnswer) {
        this.rightAnswer = rightAnswer;
    }

    public String getQuestion() {
        return question;
    }

    public void setQuestion(String question) {
        this.question = question;
    }

    public String getOptionA() {
        return optionA;
    }

    public void setOptionA(String optionA) {
        this.optionA = optionA;
    }

    public String getOptionB() {
        return optionB;
    }

    public void setOptionB(String optionB) {
        this.optionB = optionB;
    }

    public String getOptionC() {
        return optionC;
    }

    public void setOptionC(String optionC) {
        this.optionC = optionC;
    }

    public String getOptionD() {
        return optionD;
    }

    public void setOptionD(String optionD) {
        this.optionD = optionD;
    }

    public String getOptionE() {
        return optionE;
    }

    public void setOptionE(String optionE) {
        this.optionE = optionE;
    }
}
