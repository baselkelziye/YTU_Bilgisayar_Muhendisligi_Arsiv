package com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Model;

import java.io.Serializable;

public class Lesson implements Serializable{
    private int id;
    private String lessonName;
    private String grade;
    private String lessonCode;
    private LessonDetails details;

    public Lesson(){}

    public Lesson(String lessonName, String grade, String lessonCode) {
        this.lessonName = lessonName;
        this.grade = grade;
        this.lessonCode = lessonCode;
    }

    public Lesson(int id, String lessonName, String lessonCode, String grade, LessonDetails details) {
        this.id = id;
        this.lessonName = lessonName;
        this.grade = grade;
        this.lessonCode = lessonCode;
        this.details = details;
    }

    public LessonDetails getDetails(){
        return details;
    }

    public void setDetails(LessonDetails details){
        this.details = details;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getLessonName() {
        return lessonName;
    }

    public void setLessonName(String lessonName) {
        this.lessonName = lessonName;
    }

    public String getGrade() {
        return grade;
    }

    public void setGrade(String grade) {
        this.grade = grade;
    }

    public String getLessonCode(){
        return lessonCode;
    }

    public void setLessonCode(String lessonCode){
        this.lessonCode = lessonCode;
    }
}
