package com.kaansonmezoz.blm3520.homework.Activities.ShowLessonDetailsActivity;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import com.kaansonmezoz.blm3520.homework.Activities.ShowFormActivity.ShowFormActivity;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonDetailsActivity.Controller.ShowLessonDetailsActivityController;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Model.Lesson;
import com.kaansonmezoz.blm3520.homework.R;

public class ShowLessonDetailsActivity extends AppCompatActivity {
    private ShowLessonDetailsActivityController controller;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_show_lesson_details);

        controller = new ShowLessonDetailsActivityController(ShowLessonDetailsActivity.this);
        controller.attachViews();
    }
}
