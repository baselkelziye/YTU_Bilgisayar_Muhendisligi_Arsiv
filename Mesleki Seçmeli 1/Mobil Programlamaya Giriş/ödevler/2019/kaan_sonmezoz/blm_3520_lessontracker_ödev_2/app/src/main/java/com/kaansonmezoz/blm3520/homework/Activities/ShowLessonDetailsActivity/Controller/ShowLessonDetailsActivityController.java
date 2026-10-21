package com.kaansonmezoz.blm3520.homework.Activities.ShowLessonDetailsActivity.Controller;

import android.content.Intent;
import android.widget.EditText;

import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonDetailsActivity.ShowLessonDetailsActivity;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonDetailsActivity.View.ShowLessonDetailsActivityView;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Model.Lesson;
import com.kaansonmezoz.blm3520.homework.R;

public class ShowLessonDetailsActivityController {
    private ShowLessonDetailsActivity activity;
    private ShowLessonDetailsActivityView activityView;

    public ShowLessonDetailsActivityController(ShowLessonDetailsActivity activity){
        this.activity = activity;
    }

    public void attachViews(){
        activityView = new ShowLessonDetailsActivityView();

        activityView.setLessonName((EditText)activity.findViewById(R.id.lessonName));
        activityView.setLessonCode((EditText)activity.findViewById(R.id.lessonCode));
        activityView.setInstructor((EditText)activity.findViewById(R.id.instructor));
        activityView.setAveGradeInFloat((EditText)activity.findViewById(R.id.aveFloatGrade));
        activityView.setAveGradeLetter((EditText)activity.findViewById(R.id.aveGrade));
        activityView.setStudentCapacity((EditText)activity.findViewById(R.id.capacitydStudent));
        activityView.setEnrolledStudents((EditText)activity.findViewById(R.id.enrolledStudent));
        activityView.setStudentGrade((EditText)activity.findViewById(R.id.studentGrade));

        setViewsInitialData();
    }

    private void setViewsInitialData(){
        Intent intent = activity.getIntent();
        Lesson lesson = (Lesson) intent.getSerializableExtra("lesson");

        activityView.getAveGradeInFloat().setText("" + lesson.getDetails().getAverageGradeInFloat());
        activityView.getAveGradeLetter().setText("" + lesson.getDetails().getAverageGrade());
        activityView.getEnrolledStudents().setText("" + lesson.getDetails().getEnrolledStudents());
        activityView.getInstructor().setText(lesson.getDetails().getInstructor());
        activityView.getLessonCode().setText(lesson.getLessonCode());
        activityView.getLessonName().setText(lesson.getLessonName());
        activityView.getStudentGrade().setText(lesson.getGrade());
        activityView.getStudentCapacity().setText("" + lesson.getDetails().getCapacity());
    }
}
