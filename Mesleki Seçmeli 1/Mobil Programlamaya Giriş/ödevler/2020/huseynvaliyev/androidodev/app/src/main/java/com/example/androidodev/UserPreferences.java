package com.example.androidodev;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class UserPreferences extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.user_preferences);

        Bundle bundle = getIntent().getExtras();

        final String userName = bundle.getString("userName");

        Toast.makeText(UserPreferences.this,"You are successfully login", Toast.LENGTH_SHORT).show();

        Button sendMail = (Button) findViewById(R.id.buttonMail);
        Button listUser = (Button) findViewById(R.id.buttonUserList);
        Button sharedPreferences = (Button) findViewById(R.id.buttonSharedPreferences);
        Button writeNote = (Button) findViewById(R.id.buttonWriteNote);
        Button sensors = (Button) findViewById(R.id.buttonSensors);

        sendMail.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(UserPreferences.this, Mail.class);
                startActivity(intent);
            }
        });

        listUser.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(UserPreferences.this, UserList.class);
                startActivity(intent);
            }
        });

        sharedPreferences.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(UserPreferences.this, PreferencesShared.class);
                Bundle bundle = new Bundle();
                bundle.putString("userName",userName);
                intent.putExtras(bundle);
                startActivity(intent);
            }
        });

        writeNote.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(UserPreferences.this, Note.class);
                startActivity(intent);
            }
        });

        sensors.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(UserPreferences.this, SensorList.class);
                startActivity(intent);
            }
        });

    }
}
