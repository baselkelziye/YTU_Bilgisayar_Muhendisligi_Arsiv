package com.example.barissemerci;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;

public class UpdateQuestionActivity extends AppCompatActivity {


    EditText editTextUpdateQuestion;

    EditText editTextUpdateOptionA;
    EditText editTextUpdateOptionB;
    EditText editTextUpdateOptionC;
    EditText editTextUpdateOptionD;
    EditText editTextUpdateOptionE;
    Button buttonUpdate;
    CheckBox checkBoxUpdateA;
    CheckBox checkBoxUpdateB;
    CheckBox checkBoxUpdateC;
    CheckBox checkBoxUpdateD;
    CheckBox checkBoxUpdateE;

    int personNo;
    int questionNo;
    char rightAnswer;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_update_question);
        _declare();
        Intent intent= getIntent();
        personNo=intent.getIntExtra("personPosition",0);
        questionNo=intent.getIntExtra("questionPosition",0);

        editTextUpdateQuestion.setText(MainActivity.persons.get(personNo).getQuestions().get(questionNo).getQuestion());
        editTextUpdateOptionA.setText(MainActivity.persons.get(personNo).getQuestions().get(questionNo).getOptionA());
        editTextUpdateOptionB.setText(MainActivity.persons.get(personNo).getQuestions().get(questionNo).getOptionB());
        editTextUpdateOptionC.setText(MainActivity.persons.get(personNo).getQuestions().get(questionNo).getOptionC());
        editTextUpdateOptionD.setText(MainActivity.persons.get(personNo).getQuestions().get(questionNo).getOptionD());
        editTextUpdateOptionE.setText(MainActivity.persons.get(personNo).getQuestions().get(questionNo).getOptionE());

        char rightAnswer=MainActivity.persons.get(personNo).getQuestions().get(questionNo).getRightAnswer();

        if(rightAnswer=='A'){
            checkBoxUpdateA.setChecked(true);
            checkBoxUpdateB.setChecked(false);
            checkBoxUpdateC.setChecked(false);
            checkBoxUpdateD.setChecked(false);
            checkBoxUpdateE.setChecked(false);
        }
        else if(rightAnswer=='B'){
            checkBoxUpdateB.setChecked(true);
            checkBoxUpdateA.setChecked(false);
            checkBoxUpdateC.setChecked(false);
            checkBoxUpdateD.setChecked(false);
            checkBoxUpdateE.setChecked(false);
        }
        else if(rightAnswer=='C'){
            checkBoxUpdateC.setChecked(true);
            checkBoxUpdateA.setChecked(false);
            checkBoxUpdateB.setChecked(false);
            checkBoxUpdateD.setChecked(false);
            checkBoxUpdateE.setChecked(false);
        }
        else if(rightAnswer=='D'){
            checkBoxUpdateD.setChecked(true);
            checkBoxUpdateA.setChecked(false);
            checkBoxUpdateC.setChecked(false);
            checkBoxUpdateB.setChecked(false);
            checkBoxUpdateE.setChecked(false);
        }
        else if(rightAnswer=='E'){
            checkBoxUpdateE.setChecked(true);
            checkBoxUpdateA.setChecked(false);
            checkBoxUpdateC.setChecked(false);
            checkBoxUpdateD.setChecked(false);
            checkBoxUpdateB.setChecked(false);
        }

    }

    public void updateQuestion(View view){
        int counter = 0;
        String question=editTextUpdateQuestion.getText().toString();
        String optionA=editTextUpdateOptionA.getText().toString();
        String optionB=editTextUpdateOptionB.getText().toString();
        String optionC=editTextUpdateOptionC.getText().toString();
        String optionD=editTextUpdateOptionD.getText().toString();
        String optionE=editTextUpdateOptionE.getText().toString();



        if(checkBoxUpdateA.isChecked()){
            counter++;
            rightAnswer = 'A';
        }
        if(checkBoxUpdateB.isChecked()){
            counter++;
            rightAnswer = 'B';

        }
         if(checkBoxUpdateC.isChecked()){
            counter++;
             rightAnswer = 'C';

        }
         if(checkBoxUpdateD.isChecked()){
            counter++;
             rightAnswer = 'D';

        }
         if(checkBoxUpdateE.isChecked()){
            counter++;
             rightAnswer = 'E';

        }
        if (question.length() > 0 && optionA.length() > 0 && optionB.length() > 0 && optionC.length() > 0 && optionD.length() > 0 && optionE.length() > 0 && counter == 1) {
            MainActivity.persons.get(personNo).getQuestions().get(questionNo).setQuestion(question);
            MainActivity.persons.get(personNo).getQuestions().get(questionNo).setOptionA(optionA);
            MainActivity.persons.get(personNo).getQuestions().get(questionNo).setOptionB(optionB);
            MainActivity.persons.get(personNo).getQuestions().get(questionNo).setOptionC(optionC);
            MainActivity.persons.get(personNo).getQuestions().get(questionNo).setOptionD(optionD);
            MainActivity.persons.get(personNo).getQuestions().get(questionNo).setOptionE(optionE);
            MainActivity.persons.get(personNo).getQuestions().get(questionNo).setRightAnswer(rightAnswer);
            Toast.makeText(getApplicationContext(), "Updated Succefully!", Toast.LENGTH_LONG).show();
            Intent intent= new Intent(this,ListQuestionsActivity.class);
            startActivity(intent);
            finish();

        }else if (counter > 1) {
            Toast.makeText(getApplicationContext(), "You must select only one right answer!", Toast.LENGTH_LONG).show();
        } else if (counter == 0) {
            Toast.makeText(getApplicationContext(), "You didn't select the right answer!", Toast.LENGTH_LONG).show();
        } else {
            Toast.makeText(getApplicationContext(), "All fields must be filled!", Toast.LENGTH_LONG).show();
        }


    }

    public void _declare() {
        checkBoxUpdateA = findViewById(R.id.checkBoxUpdateA);
        checkBoxUpdateB = findViewById(R.id.checkBoxUpdateB);
        checkBoxUpdateC = findViewById(R.id.checkBoxUpdateC);
        checkBoxUpdateD = findViewById(R.id.checkBoxUpdateD);
        checkBoxUpdateE = findViewById(R.id.checkBoxUpdateE);
        editTextUpdateQuestion = findViewById(R.id.editTextUpdateQuestion);
        editTextUpdateOptionA = findViewById(R.id.editTextUpdateOptionA);
        editTextUpdateOptionB = findViewById(R.id.editTextUpdateOptionB);
        editTextUpdateOptionC = findViewById(R.id.editTextUpdateOptionC);
        editTextUpdateOptionE = findViewById(R.id.editTextUpdateOptionE);
        editTextUpdateOptionD = findViewById(R.id.editTextUpdateOptionD);
        buttonUpdate = findViewById(R.id.buttonUpdate);

    }
}