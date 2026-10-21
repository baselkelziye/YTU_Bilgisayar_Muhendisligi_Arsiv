package com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Adapter;

import android.app.Activity;
//import android.provider.ContactsContract;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Model.Lesson;
//import com.kaansonmezoz.blm3520.homework.StorageOperations.Database.DatabaseOperations;
//import com.kaansonmezoz.blm3520.homework.StorageOperations.Database.Entities.LessonDatabaseEntity;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Model.LessonDetails;
import com.kaansonmezoz.blm3520.homework.R;

import java.util.ArrayList;
import java.util.List;

public class LessonsAdapter extends RecyclerView.Adapter<LessonsAdapter.MyViewHolder> {
    private List<Lesson> lessonList;

    public LessonsAdapter(Activity activity){
        lessonList = new ArrayList<Lesson>();

        lessonList.add(new Lesson(1, "Mobil Programlama", "BLM3520", "CC",
                new LessonDetails("Amaç Güvensan", 45, 45, "CB", 45.0f)));

        lessonList.add(new Lesson(2, "BBG-2", "BLM1331", "AA",
                new LessonDetails("Amaç Güvensan", 65, 65, "DD", 20.0f)));

        lessonList.add(new Lesson(3, "BBG-1", "BLM1231", "CB",
                new LessonDetails("Amaç Güvensan", 90, 90, "CC", 40.0f)));

        lessonList.add(new Lesson(4, "Matematik-1", "MAT1012", "BA",
                new LessonDetails("Amaç Güvensan", 45, 45, "DD", 22.32f)));

        lessonList.add(new Lesson(5, "Matematik-2", "MAT1212", "BB",
                new LessonDetails("Amaç Güvensan", 45, 0, "FF", 0.0f)));

        lessonList.add(new Lesson(6, "Ayrık Matematik", "BLM2231", "BA",
                new LessonDetails("Amaç Güvensan", 45, 45, "BB", 66.77f)));
    }

    @Override
    public LessonsAdapter.MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType){
        View view =  LayoutInflater.from(parent.getContext()).inflate(R.layout.card_item_lesson, parent, false);
        MyViewHolder vh = new MyViewHolder(view);
        return vh;
    }

    @Override
    public void onBindViewHolder(MyViewHolder holder, int position){
        Lesson lesson = lessonList.get(position);
        holder.setData(lesson, position);
    }

    @Override
    public int getItemCount(){
        return lessonList.size();
    }

    public Lesson getItem(int position){
        return lessonList.get(position);
    }

    public void updateData(ArrayList<Lesson> lessons) {
        lessonList.clear();
        lessonList.addAll(lessons);
        notifyDataSetChanged();
    }

    public void addItem(int position, Lesson lesson) {
        lessonList.add(position, lesson);
        notifyItemInserted(position);
    }


    class MyViewHolder extends RecyclerView.ViewHolder { //, View.OnLongClickListener

        TextView lessonCode;
        TextView lessonName;
        TextView lessonGrade;

        public MyViewHolder(View itemView) {
            super(itemView);
            lessonName = (TextView) itemView.findViewById(R.id.lessonName);
            lessonCode = (TextView) itemView.findViewById(R.id.lessonCode);
            lessonGrade = (TextView) itemView.findViewById(R.id.lessonGrade);
        }

        public void setData(Lesson selectedLesson, int position) {

            this.lessonName.setText(selectedLesson.getLessonName());
            this.lessonCode.setText(selectedLesson.getLessonCode());
            this.lessonGrade.setText(selectedLesson.getGrade());
        }
    }
}
