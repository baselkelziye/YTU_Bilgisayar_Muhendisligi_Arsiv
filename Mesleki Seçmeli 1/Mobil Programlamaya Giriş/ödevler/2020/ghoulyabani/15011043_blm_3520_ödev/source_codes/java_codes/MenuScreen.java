package com.example.classapp;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.app.AppCompatDelegate;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MenuScreen extends AppCompatActivity {

    Button btnMail;
    SharedPreferences pref;
    SharedPreferences.Editor editor;
    String currentUser;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu_screen);

        pref = getApplicationContext().getSharedPreferences("MyPref", 0);
        editor = pref.edit();

        currentUser = pref.getString("current_user", null);

        if (pref.getString(currentUser+"_mode","light").equals("dark")){
            AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES);
        }
        else if (pref.getString(currentUser+"_mode","light").equals("light")){
            AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
        }
        else{
            AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
        }


    }

    public void openMail(View v){
        Intent mail = new Intent(this, EMail.class);
        startActivity(mail);
    }

    public void openUsers(View v){
        Intent users = new Intent(this, UserList.class);
        startActivity(users );
    }

    public void openSettings(View v){
        Intent settings = new Intent(this, UserSettings.class);
        startActivityForResult(settings, 2);
    }

    public void openNotes(View v){
        Intent notes = new Intent(this, NoteList.class);
        startActivity(notes);
    }

    public void openSensor(View v){
        Intent sensor = new Intent(this, SensorScreen.class);
        startActivityForResult(sensor, 4);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == 2){
            finish();
            startActivity(getIntent());
        }

        if (requestCode == 4){
            if (resultCode == Activity.RESULT_OK){
                String result = data.getStringExtra("result");
                if (result.equals("kill")){
                    Intent returnIntent = new Intent();
                    returnIntent.putExtra("result", "kill");
                    setResult(Activity.RESULT_OK, returnIntent);
                    finish();
                }
            }
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (pref.getString(currentUser+"_mode","light").equals("dark")){
            AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES);
        }
        else if (pref.getString(currentUser+"_mode","light").equals("light")){
            AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
        }
        else{
            AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
        }
    }
}
