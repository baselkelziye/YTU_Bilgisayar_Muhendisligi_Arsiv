package com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Dialog;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.EditText;

import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Model.Lesson;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.Model.LessonDetails;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.ShowLessonsActivity;
import com.kaansonmezoz.blm3520.homework.R;

public class NewLessonDialog {
    public AlertDialog createDialog(final ShowLessonsActivity activity){
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);

        LayoutInflater inflater = activity.getLayoutInflater();

        final View layout = inflater.inflate(R.layout.dialog_new_lesson, null);

        builder.setView(layout)
                .setPositiveButton(R.string.next, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        EditText lessonName = layout.findViewById(R.id.lessonNameDialog);
                        EditText gpa = layout.findViewById(R.id.gpaDialog);
                        EditText lessonCode = layout.findViewById(R.id.lessonCodeDialog);

                        if(checkLessonFields(lessonName, lessonCode, gpa)){
                            Lesson lesson = new Lesson();
                            lesson.setLessonName(lessonName.getText().toString());
                            lesson.setLessonCode(lessonCode.getText().toString());
                            lesson.setGrade(gpa.getText().toString());

                            createLessonDetailsDialog(activity, lesson).show();
                        }
                    }
                })
                .setNegativeButton(R.string.cancelNewLesson, new DialogInterface.OnClickListener(){
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i){
                        return;
                    }
                });

        return builder.create();
    }

    public AlertDialog createLessonDetailsDialog(final ShowLessonsActivity activity,final Lesson lesson){
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);

        LayoutInflater inflater = activity.getLayoutInflater();

        final View layout = inflater.inflate(R.layout.dialog_new_lesson_details, null);

        builder.setView(layout)
                .setPositiveButton(R.string.newLesson, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        EditText instructor = layout.findViewById(R.id.instructorDialog);
                        EditText aveGrade = layout.findViewById(R.id.aveGradeDialog);
                        EditText aveGradeFloat = layout.findViewById(R.id.aveFloatGradeDialog);
                        EditText enrolledStudent = layout.findViewById(R.id.enrolledStudentDialog);
                        EditText studentCapacity = layout.findViewById(R.id.capacityStudentDialog);

                        Log.d("Lesson", "" + checkLessonDetailFields(instructor, aveGrade, aveGradeFloat, studentCapacity, enrolledStudent));

                       if(checkLessonDetailFields(instructor, aveGrade, aveGradeFloat, studentCapacity, enrolledStudent)){
                            LessonDetails lessonDetails = new LessonDetails();

                            lessonDetails.setInstructor(instructor.getText().toString());
                            lessonDetails.setAverageGrade(aveGrade.getText().toString());
                            lessonDetails.setAverageGradeInFloat(Float.parseFloat(aveGradeFloat.getText().toString()));
                            lessonDetails.setCapacity(Integer.parseInt(enrolledStudent.getText().toString()));
                            lessonDetails.setEnrolledStudents(Integer.parseInt(studentCapacity.getText().toString()));

                            activity.getController().addNewLesson(lesson);
                        }
                    }
                })
                .setNegativeButton(R.string.cancelNewLesson, new DialogInterface.OnClickListener(){
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i){
                        return;
                    }
                });

        return builder.create();
    }

    private boolean checkLessonDetailFields(EditText instructor, EditText aveGrade, EditText aveGradeFloat, EditText capacity, EditText enrolledStudent){
        return instructor.getText().toString() != null && aveGrade.getText().toString() != null && aveGradeFloat.getText().toString() != null &&
                capacity.getText().toString() != null && enrolledStudent.getText().toString() != null;
    }

    private boolean checkLessonFields(EditText lessonName, EditText gpa, EditText lessonCode){
        return lessonName.getText().toString() != null && gpa.getText().toString() != null && lessonCode.getText().toString() != null;
    }
}
