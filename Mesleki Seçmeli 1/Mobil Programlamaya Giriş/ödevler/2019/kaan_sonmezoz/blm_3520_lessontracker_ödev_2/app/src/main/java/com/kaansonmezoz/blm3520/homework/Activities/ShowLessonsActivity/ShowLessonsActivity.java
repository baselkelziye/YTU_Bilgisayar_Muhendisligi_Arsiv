package com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity;

import android.content.Context;
import android.support.v4.view.GravityCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MenuItem;

import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Controller.ShowLessonsActivityController;
import com.kaansonmezoz.blm3520.homework.R;

public class ShowLessonsActivity extends AppCompatActivity {
    private ShowLessonsActivityController controller;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_show_lessons);

        controller = new ShowLessonsActivityController(ShowLessonsActivity.this);

        controller.attachViews();
        controller.attachEventListeners();
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case android.R.id.home:
                controller.getActivityView().getDrawerLayout().openDrawer(GravityCompat.START);
                return true;
        }
        return super.onOptionsItemSelected(item);
    }

    public ShowLessonsActivityController getController(){
        return controller;
    }
}
