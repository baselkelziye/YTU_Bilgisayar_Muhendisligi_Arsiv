package com.example.barissemerci;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.text.SpannableStringBuilder;
import android.view.View;
import android.widget.EditText;
import android.widget.RatingBar;
import android.widget.Spinner;
import android.widget.Toast;

public class SettingsActivity extends AppCompatActivity {
    SharedPreferences sharedPreferences;
    EditText editTextTime;
    RatingBar ratingBar;
    EditText editTextQuestionNumber;
    EditText editTextQuestionPoint;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);
        _declare();
        sharedPreferences=this.getSharedPreferences("com.example.barissemerci", Context.MODE_PRIVATE);
    }

    public void saveSettings(View view){
        String time=editTextTime.getText().toString();
        Float rating= ratingBar.getRating();
        String questionNumber= (editTextQuestionNumber.getText().toString());
        String questionPoint= (editTextQuestionPoint.getText().toString());
        sharedPreferences.edit().putString("time",time).apply();
        sharedPreferences.edit().putInt("rating",rating.intValue()).apply();
        sharedPreferences.edit().putString("questionNumber",questionNumber).apply();
        sharedPreferences.edit().putString("questionPoint",questionPoint).apply();
        Toast.makeText(getApplicationContext(),"Successfully Saved",Toast.LENGTH_LONG);

    }
    public void _declare(){
        editTextTime=findViewById(R.id.editTextTime);
        ratingBar=findViewById(R.id.ratingBar);
        editTextQuestionPoint=findViewById(R.id.editTextPoint);
        editTextQuestionNumber=findViewById(R.id.editTextQuestionNumber);
    }


}