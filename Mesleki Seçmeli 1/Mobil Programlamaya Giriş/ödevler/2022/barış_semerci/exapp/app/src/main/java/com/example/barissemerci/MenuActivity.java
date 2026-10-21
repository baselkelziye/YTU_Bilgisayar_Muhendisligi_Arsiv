package com.example.barissemerci;

import androidx.appcompat.app.AppCompatActivity;


import android.content.Intent;

import android.os.Bundle;

import android.view.View;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class MenuActivity extends AppCompatActivity {
    int count;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);
        Intent intent = getIntent();
        count = intent.getIntExtra("count", 0);


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

    public void exit(View view) {
        finish();
    }

    public void goToProfile(View view) {
        Intent intent = new Intent(getApplicationContext(), ProfileActivity.class);
        startActivity(intent);
    }

    public void goToCustomizeExam(View view) {
        Intent intent = new Intent(getApplicationContext(), SettingsActivity.class);
        intent.putExtra("personNumber", count);
        startActivity(intent);
    }

    public void goToCreateExam(View view) {
        Intent intent = new Intent(getApplicationContext(), CreateExamActivity.class);
        intent.putExtra("userNo", count);
        startActivity(intent);
    }

    public void goToListQuestions(View view) {
        Intent intent = new Intent(getApplicationContext(), ListQuestionsActivity.class);
        intent.putExtra("personNo", count);
        startActivity(intent);
    }

    public void goToAddQuestion(View view) {
        Intent intent = new Intent(getApplicationContext(), AddQuestionsActivity.class);
        intent.putExtra("personNumber", count);
        startActivity(intent);
    }
}