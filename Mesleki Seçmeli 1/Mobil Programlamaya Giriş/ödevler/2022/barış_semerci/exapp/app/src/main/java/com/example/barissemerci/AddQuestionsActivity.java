package com.example.barissemerci;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;


import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;


import android.widget.Toast;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;


public class AddQuestionsActivity extends AppCompatActivity {
    CheckBox checkBoxA;
    CheckBox checkBoxB;
    CheckBox checkBoxC;
    CheckBox checkBoxD;
    CheckBox checkBoxE;
    EditText editTextQuestion;
    EditText editTextOptionA;
    EditText editTextOptionB;
    EditText editTextOptionC;
    EditText editTextOptionD;
    EditText editTextOptionE;
    Button buttonSave;
    String question;
    String optionA;
    String optionB;
    String optionC;
    String optionD;
    String optionE;

    char rightAnswer;
    Question questionObject;
    int personNumber;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_questions);
        _declare();
        Intent intent = getIntent();
        personNumber = intent.getIntExtra("personNumber", 0);


    }

    public void save(View view) {

        questionObject = new Question();
        int counter = 0;
        question = editTextQuestion.getText().toString();
        optionA = editTextOptionA.getText().toString();
        optionB = editTextOptionB.getText().toString();
        optionC = editTextOptionC.getText().toString();
        optionD = editTextOptionD.getText().toString();
        optionE = editTextOptionE.getText().toString();
        if (checkBoxA.isChecked()) {
            rightAnswer = 'A';
            counter++;
        }
        if (checkBoxB.isChecked()) {
            rightAnswer = 'B';
            counter++;
        }
        if (checkBoxC.isChecked()) {
            rightAnswer = 'C';
            counter++;
        }
        if (checkBoxD.isChecked()) {
            rightAnswer = 'D';
            counter++;
        }
        if (checkBoxE.isChecked()) {
            rightAnswer = 'E';
            counter++;
        }


        if (question.length() > 0 && optionA.length() > 0 && optionB.length() > 0 && optionC.length() > 0 && optionD.length() > 0 && optionE.length() > 0 && counter == 1) {
            questionObject.setOptionA(optionA);
            questionObject.setOptionB(optionB);
            questionObject.setOptionC(optionC);
            questionObject.setOptionD(optionD);
            questionObject.setOptionE(optionE);
            questionObject.setQuestion(question);
            questionObject.setRightAnswer(rightAnswer);



            MainActivity.persons.get(personNumber).getQuestions().add(questionObject);
            Toast.makeText(getApplicationContext(), "Saved Successfully!", Toast.LENGTH_LONG).show();


        } else if (counter > 1) {
            Toast.makeText(getApplicationContext(), "You must select only one right answer!", Toast.LENGTH_LONG).show();
        } else if (counter == 0) {
            Toast.makeText(getApplicationContext(), "You didn't select the right answer!", Toast.LENGTH_LONG).show();
        } else {
            Toast.makeText(getApplicationContext(), "All fields must be filled!", Toast.LENGTH_LONG).show();
        }

    }

    public void _declare() {
        checkBoxA = findViewById(R.id.checkBoxA);
        checkBoxB = findViewById(R.id.checkBoxB);
        checkBoxC = findViewById(R.id.checkBoxC);
        checkBoxD = findViewById(R.id.checkBoxD);
        checkBoxE = findViewById(R.id.checkBoxE);
        editTextQuestion = findViewById(R.id.editTextQuestion);
        editTextOptionA = findViewById(R.id.editTextOptionA);
        editTextOptionB = findViewById(R.id.editTextOptionB);
        editTextOptionC = findViewById(R.id.editTextOptionC);
        editTextOptionD = findViewById(R.id.editTextOptionD);
        editTextOptionE = findViewById(R.id.editTextOptionE);
        buttonSave = findViewById(R.id.buttonSave);


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