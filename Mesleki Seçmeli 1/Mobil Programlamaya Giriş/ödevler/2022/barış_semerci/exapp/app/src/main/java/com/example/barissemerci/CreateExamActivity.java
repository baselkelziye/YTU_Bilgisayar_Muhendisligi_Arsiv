package com.example.barissemerci;


import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;

import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.material.snackbar.Snackbar;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class CreateExamActivity extends AppCompatActivity {
    ExamRecyclerAdapter examRecyclerAdapter;
    int userNo;
    String time;
    int rating;
    String questionNumber;
    String questionPoint;
    SharedPreferences sharedPreferences;
    EditText editTextCreateExamTime;
    EditText editTextCreateExamQuestionNumber;
    EditText editTextCreateExamRating;
    EditText editTextCreateExamQuestionPoint;
    EditText getEditTextCreateExamTitle;
    Exam exam;
    ArrayList<String> randomOptions = new ArrayList<>();
    ArrayList<String> options = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_create_exam);
        _declare();
        sharedPreferences = getSharedPreferences("com.example.barissemerci", Context.MODE_PRIVATE);
        time = sharedPreferences.getString("time", "0");
        rating = sharedPreferences.getInt("rating", 0);
        questionNumber = sharedPreferences.getString("questionNumber", "0");
        questionPoint = sharedPreferences.getString("questionPoint", "0");

        editTextCreateExamQuestionNumber.setText(questionNumber);

        editTextCreateExamTime.setText(time);
        editTextCreateExamRating.setText((Integer.toString(rating)));
        editTextCreateExamQuestionPoint.setText(questionPoint);
        Intent intent = getIntent();
        userNo = intent.getIntExtra("userNo", 0);

        RecyclerView recyclerViewExam = findViewById(R.id.recyclerViewExam);
        recyclerViewExam.setLayoutManager(new LinearLayoutManager(this));
        examRecyclerAdapter = new ExamRecyclerAdapter(MainActivity.persons.get(userNo).getQuestions());
        recyclerViewExam.setAdapter(examRecyclerAdapter);

        examRecyclerAdapter.notifyDataSetChanged();

    }


    public void createExam(View view) throws IOException {
        System.out.println(ExamRecyclerAdapter.limitOfQuestions);
        System.out.println(editTextCreateExamQuestionNumber.getText().toString());
        if (ExamRecyclerAdapter.limitOfQuestions == Integer.parseInt(editTextCreateExamQuestionNumber.getText().toString())) {
            exam = new Exam();
            ExamRecyclerAdapter.limitOfQuestions=0;
            int examNo = MainActivity.persons.get(userNo).getExamNumber();

            MainActivity.persons.get(userNo).setExamNumber(examNo + 1);
            String filename = getFilesDir() + "/" + MainActivity.persons.get(userNo).getEmail() + "_" + (MainActivity.persons.get(userNo).getExamNumber()) + ".txt";


            exam.setTitle(getEditTextCreateExamTitle.getText().toString());
            exam.setDifficulty(editTextCreateExamRating.getText().toString());
            exam.setTime(editTextCreateExamTime.getText().toString());
            exam.setNumber(editTextCreateExamQuestionNumber.getText().toString());
            exam.setPoint(editTextCreateExamQuestionPoint.getText().toString());
            exam.setQuestions(ExamRecyclerAdapter.selectedQuestions);
            MainActivity.persons.get(MainActivity.whichPerson).getExams().add(exam);

            String text = MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).getExamNumber()).getTitle() +
                    "\n" + "Exam Time: " +
                    MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).getExamNumber()).getTime() +
                    "\n" + "Exam Difficulty: " +
                    MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).getExamNumber()).getDifficulty() +
                    "\n" + "Number of Questions: " +
                    MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).getExamNumber()).getNumber() +
                    "\n" + "Question Point: " +
                    MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).getExamNumber()).getPoint() +
                    "\n";


            for (int i = 0; i < MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                    getExamNumber()).getQuestions().size(); i++) {


                options.add(MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                        getExamNumber()).getQuestions().get(i).getOptionA());
                options.add(MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                        getExamNumber()).getQuestions().get(i).getOptionB());
                options.add(MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                        getExamNumber()).getQuestions().get(i).getOptionC());
                options.add(MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                        getExamNumber()).getQuestions().get(i).getOptionD());
                options.add(MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                        getExamNumber()).getQuestions().get(i).getOptionE());


                if (MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                        getExamNumber()).getQuestions().get(i).getRightAnswer() == 'A') {
                    randomOptions.add(MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                            getExamNumber()).getQuestions().get(i).getOptionA());
                } else if (MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                        getExamNumber()).getQuestions().get(i).getRightAnswer() == 'B') {
                    randomOptions.add(MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                            getExamNumber()).getQuestions().get(i).getOptionB());
                } else if (MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                        getExamNumber()).getQuestions().get(i).getRightAnswer() == 'C') {
                    randomOptions.add(MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                            getExamNumber()).getQuestions().get(i).getOptionC());
                } else if (MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                        getExamNumber()).getQuestions().get(i).getRightAnswer() == 'D') {
                    randomOptions.add(MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                            getExamNumber()).getQuestions().get(i).getOptionD());
                } else {
                    randomOptions.add(MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                            getExamNumber()).getQuestions().get(i).getOptionE());
                }


                while (randomOptions.size() < Integer.parseInt(editTextCreateExamRating.getText().toString())) {
                    Random r = new Random();
                    int random = r.nextInt(5);

                    if (!randomOptions.contains(options.get(random))) {
                        randomOptions.add(options.get(random));
                    }
                }

                Collections.shuffle(randomOptions);


                text = text + "\n Question " + (i + 1) + ":\n" + MainActivity.persons.get(MainActivity.whichPerson).getExams().get(MainActivity.persons.get(MainActivity.whichPerson).
                        getExamNumber()).getQuestions().get(i).getQuestion() + "\n";


                if (Float.parseFloat(exam.getDifficulty()) == 2) {
                    text = text + "A) " + randomOptions.get(0) + "\n" +
                            "B) " + randomOptions.get(1) + "\n";
                } else if (Float.parseFloat(exam.getDifficulty()) == 3) {
                    text = text + "A) " + randomOptions.get(0) + "\n" +
                            "B) " + randomOptions.get(1) + "\n" +
                            "C) " + randomOptions.get(2) + "\n";

                } else if (Float.parseFloat(exam.getDifficulty()) == 4) {
                    text = text + "A) " + randomOptions.get(0) + "\n" +
                            "B) " + randomOptions.get(1) + "\n" +
                            "C) " + randomOptions.get(2) + "\n" +
                            "D) " + randomOptions.get(3) + "\n";

                } else {
                    text = text + "A) " + randomOptions.get(0) + "\n" +
                            "B) " + randomOptions.get(1) + "\n" +
                            "C) " + randomOptions.get(2) + "\n" +
                            "D) " + randomOptions.get(3) + "\n" +
                            "E) " + randomOptions.get(4) + "\n";

                }


                saveToFile(filename, text);
                text = "";
                options.clear();
                randomOptions.clear();
                Snackbar.make(findViewById(R.id.examLayout), "Exam saved!", Snackbar.LENGTH_LONG).show();
            }

            ExamRecyclerAdapter.selectedQuestions.clear();

        } else {
            Toast.makeText(getApplicationContext(), "Please select the exact amount of questions as you specified!", Toast.LENGTH_LONG).show();
        }


    }

    public void saveToFile(String fileName, String text) throws IOException {
        File file = new File(fileName);
        FileWriter fw = new FileWriter(file, true);
        PrintWriter pw = new PrintWriter(fw);
        pw.println(text);
        pw.close();

    }

    public void _declare() {

        editTextCreateExamTime = findViewById(R.id.editTextCreateExamTime);
        editTextCreateExamQuestionNumber = findViewById(R.id.editTextCreateExamQuestionNumber);
        editTextCreateExamRating = findViewById(R.id.editTextCreateExamRating);
        editTextCreateExamQuestionPoint = findViewById(R.id.editTextCreateExamQuestionPoint);
        getEditTextCreateExamTitle = findViewById(R.id.editTextCreateExamTitle);

    }


    @Override
    protected void onStop() {
        super.onStop();
        File f = new File(getFilesDir() + "/userlist.dat");
        f.delete();
        FileOutputStream outStream = null;
        try {

            f = new File(getFilesDir() + "/userlist.dat");

            outStream = new FileOutputStream(f, true);
            ObjectOutputStream objectOutStream = new ObjectOutputStream(outStream);

            for (Person i : MainActivity.persons) {
                objectOutStream.writeObject(i);
            }

            objectOutStream.close();
        } catch (FileNotFoundException e1) {
            e1.printStackTrace();
        } catch (IOException e1) {
            e1.printStackTrace();
        }
    }


}