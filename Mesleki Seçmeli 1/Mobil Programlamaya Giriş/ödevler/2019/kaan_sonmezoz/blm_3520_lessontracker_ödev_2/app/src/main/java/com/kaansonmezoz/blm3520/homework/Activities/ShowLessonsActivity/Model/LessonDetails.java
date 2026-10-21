package com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Model;

import java.io.Serializable;

public class LessonDetails implements Serializable {
    private String instructor;
    private int capacity;
    private int enrolledStudents;
    private String averageGrade;
    private float averageGradeInFloat;

    public LessonDetails(){}

    public LessonDetails(String instructor, int capacity, int enrolledStudents, String averageGrade, float averageGradeInFloat) {
        this.instructor = instructor;
        this.capacity = capacity;
        this.enrolledStudents = enrolledStudents;
        this.averageGrade = averageGrade;
        this.averageGradeInFloat = averageGradeInFloat;
    }

    public String getInstructor() {
        return instructor;
    }

    public void setInstructor(String instructor) {
        this.instructor = instructor;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public int getEnrolledStudents() {
        return enrolledStudents;
    }

    public void setEnrolledStudents(int enrolledStudents) {
        this.enrolledStudents = enrolledStudents;
    }

    public String getAverageGrade() {
        return averageGrade;
    }

    public void setAverageGrade(String averageGrade) {
        this.averageGrade = averageGrade;
    }

    public float getAverageGradeInFloat() {
        return averageGradeInFloat;
    }

    public void setAverageGradeInFloat(float averageGradeInFloat) {
        this.averageGradeInFloat = averageGradeInFloat;
    }
}
