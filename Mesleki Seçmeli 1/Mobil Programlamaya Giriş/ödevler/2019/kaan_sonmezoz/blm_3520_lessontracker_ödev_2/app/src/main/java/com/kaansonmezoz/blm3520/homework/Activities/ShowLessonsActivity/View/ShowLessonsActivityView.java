package com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.View;

import android.support.design.widget.NavigationView;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.Button;

public class ShowLessonsActivityView {
    private NavigationView navigationView;
    private DrawerLayout drawerLayout;
    private RecyclerView recyclerView;
    private Button  addLessonButton;

    public NavigationView getNavigationView() {
        return navigationView;
    }

    public void setNavigationView(View navigationView) {
        this.navigationView = (NavigationView) navigationView;
    }

    public DrawerLayout getDrawerLayout() {
        return drawerLayout;
    }

    public void setDrawerLayout(View drawerLayout) {
        this.drawerLayout = (DrawerLayout) drawerLayout;
    }

    public RecyclerView getRecyclerView() {
        return recyclerView;
    }

    public void setRecyclerView(View recyclerView) {
        this.recyclerView = (RecyclerView) recyclerView;
    }

    public Button getAddLessonButton(){
        return addLessonButton;
    }

    public void setAddLessonButton(View addLessonButton){
        this.addLessonButton = (Button) addLessonButton;
    }
}
