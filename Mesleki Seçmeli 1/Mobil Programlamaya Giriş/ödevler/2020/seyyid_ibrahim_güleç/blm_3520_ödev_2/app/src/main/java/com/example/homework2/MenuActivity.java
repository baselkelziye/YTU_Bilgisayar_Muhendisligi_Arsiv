package com.example.homework2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MenuActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        Button buttonOne = findViewById(R.id.buttonOne);
        buttonOne.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Intent activity2Intent = new Intent(getApplicationContext(), LoginActivity.class);
                startActivity(activity2Intent);
            }
        });
        Button buttonTwo = findViewById(R.id.buttonTwo);
        buttonTwo.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Intent activity2Intent = new Intent(getApplicationContext(), EmailActivity.class);
                startActivity(activity2Intent);
            }
        });

        Button buttonThree = findViewById(R.id.buttonThree);
        buttonThree.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Intent activity2Intent = new Intent(getApplicationContext(), UserListActivity.class);
                startActivity(activity2Intent);
            }
        });

        Button buttonFour = findViewById(R.id.buttonFour);
        buttonFour.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Intent activity2Intent = new Intent(getApplicationContext(), SettingsActivity.class);
                startActivity(activity2Intent);
            }
        });

        Button buttonFive = findViewById(R.id.buttonFive);
        buttonFive.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Intent activity2Intent = new Intent(getApplicationContext(), NoteActivity.class);
                startActivity(activity2Intent);
            }
        });

    }
}
