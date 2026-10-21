package com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Controller;

import android.content.Intent;
import android.support.design.widget.NavigationView;
import android.support.v7.app.ActionBar;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.MenuItem;
import android.view.View;

import com.kaansonmezoz.blm3520.homework.Activities.MainActivity.MainActivity;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonDetailsActivity.ShowLessonDetailsActivity;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Adapter.LessonsAdapter;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Dialog.NewLessonDialog;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Model.Lesson;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.RecyclerListener.LessonItemClickListener;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.ShowLessonsActivity;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.View.ShowLessonsActivityView;
import com.kaansonmezoz.blm3520.homework.Interface.ControllerInterface;
import com.kaansonmezoz.blm3520.homework.R;

public class ShowLessonsActivityController implements ControllerInterface {
    private ShowLessonsActivity activity;
    private ShowLessonsActivityView activityView;

    public ShowLessonsActivityController(ShowLessonsActivity activity){
        this.activity = activity;
    }

    public ShowLessonsActivityView getActivityView(){
        return activityView;
    }

    public void attachEventListeners(){
        if(activityView == null){
            attachViews();
        }

        addNewLessonButtonListener();
        addNavigationClickEvents();
        addLessonOnClickListener();
    }

    public void attachViews(){
        activityView = new ShowLessonsActivityView();

        activityView.setRecyclerView(activity.findViewById(R.id.lessonsRecyclerView));
        activityView.setDrawerLayout(activity.findViewById(R.id.drawer_layout));
        activityView.setNavigationView(activity.findViewById(R.id.nav_view));
        activityView.setAddLessonButton(activity.findViewById(R.id.addLessonButton));

        Toolbar toolbar = activity.findViewById(R.id.toolbar);
        activity.setSupportActionBar(toolbar);
        ActionBar actionbar = activity.getSupportActionBar();
        actionbar.setDisplayHomeAsUpEnabled(true);
        actionbar.setHomeAsUpIndicator(R.drawable.ic_menu_black_24dp);

        RecyclerView recyclerView = activityView.getRecyclerView();
        recyclerView.setHasFixedSize(true);
        recyclerView.setLayoutManager(new LinearLayoutManager(activity));
        recyclerView.setAdapter(new LessonsAdapter(activity));
    }

    private void addNewLessonButtonListener(){
        activityView.getAddLessonButton().setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view){
                NewLessonDialog dialog = new NewLessonDialog();
                dialog.createDialog(activity).show();
            }
        });
    }

    public void addNewLesson(Lesson lesson){
        LessonsAdapter adapter = (LessonsAdapter)activityView.getRecyclerView().getAdapter();

        Log.d("Lesson", "Added Lesson Name: " + lesson.getLessonName());

        lesson.setId(adapter.getItemCount());
        adapter.addItem(adapter.getItemCount(), lesson);
    }

    private void addLessonOnClickListener(){
        LessonsAdapter adapter = (LessonsAdapter)activityView.getRecyclerView().getAdapter();
        Log.d("Lesson", "onclicklistener");

        final RecyclerView recyclerView = activityView.getRecyclerView();

        recyclerView.addOnItemTouchListener(
                new LessonItemClickListener(activity, recyclerView ,new LessonItemClickListener.OnItemClickListener() {
                    @Override public void onItemClick(View view, int position) {
                        Log.d("Lesson", "" + position);
                        Lesson lesson = ((LessonsAdapter)recyclerView.getAdapter()).getItem(position);

                        Intent intent = new Intent(activity, ShowLessonDetailsActivity.class);
                        intent.putExtra("lesson", lesson);

                        activity.startActivity(intent);

                    }

                    @Override public void onLongItemClick(View view, int position) {
                        Log.d("Lesson", "onLongItemClick");
                    }
                })
        );

    }

    private void addNavigationClickEvents(){
        activityView.getNavigationView().setNavigationItemSelectedListener(
            new NavigationView.OnNavigationItemSelectedListener() {
                @Override
                public boolean onNavigationItemSelected(MenuItem menuItem) {
                    menuItem.setCheckable(true);
                    activityView.getDrawerLayout().closeDrawers();

                    if(menuItem.getTitle().toString().equals(activity.getResources().getString(R.string.navbar_information))){
                        Intent intent = new Intent(activity, MainActivity.class);
                        activity.startActivity(intent);
                    }

                    return true;
                }
            });

        activityView.getNavigationView().setCheckedItem(R.id.navbar_lessons);
    }


}
