package com.kaansonmezoz.blm3520.homework.Activities.ShowLessonDetailsActivity.View;

import android.widget.EditText;

public class ShowLessonDetailsActivityView {
    private EditText lessonName;
    private EditText lessonCode;
    private EditText instructor;
    private EditText aveGradeLetter;
    private EditText aveGradeInFloat;
    private EditText enrolledStudents;
    private EditText studentCapacity;
    private EditText studentGrade;

    public EditText getStudentGrade(){
        return  studentGrade;
    }

    public void setStudentGrade(EditText studentGrade){
        this.studentGrade = studentGrade;
    }

    public EditText getLessonName() {
        return lessonName;
    }

    public void setLessonName(EditText lessonName) {
        this.lessonName = lessonName;
    }

    public EditText getLessonCode() {
        return lessonCode;
    }

    public void setLessonCode(EditText lessonCode) {
        this.lessonCode = lessonCode;
    }

    public EditText getInstructor() {
        return instructor;
    }

    public void setInstructor(EditText instructor) {
        this.instructor = instructor;
    }

    public EditText getAveGradeLetter() {
        return aveGradeLetter;
    }

    public void setAveGradeLetter(EditText aveGradeLetter) {
        this.aveGradeLetter = aveGradeLetter;
    }

    public EditText getAveGradeInFloat() {
        return aveGradeInFloat;
    }

    public void setAveGradeInFloat(EditText aveGradeInFloat) {
        this.aveGradeInFloat = aveGradeInFloat;
    }

    public EditText getEnrolledStudents() {
        return enrolledStudents;
    }

    public void setEnrolledStudents(EditText enrolledStudents) {
        this.enrolledStudents = enrolledStudents;
    }

    public EditText getStudentCapacity() {
        return studentCapacity;
    }

    public void setStudentCapacity(EditText studentCapacity) {
        this.studentCapacity = studentCapacity;
    }
}
