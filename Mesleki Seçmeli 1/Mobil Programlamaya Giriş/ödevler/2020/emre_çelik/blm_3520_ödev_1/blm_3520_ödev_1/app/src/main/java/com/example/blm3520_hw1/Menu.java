package com.example.blm3520_hw1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class Menu extends AppCompatActivity {

    SharedPreferences preferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        preferences = this.getSharedPreferences("User", MODE_PRIVATE);
    }

    public void mailButtonClicked(View view) {
        Intent intent = new Intent(Menu.this, Mail.class);
        startActivity(intent);
    }

    public void usersButtonClicked(View view) {
        Intent intent = new Intent(Menu.this, Users.class);
        startActivity(intent);
    }

    public void notesClicked(View view) {
        Intent intent = new Intent(Menu.this, Note.class);
        startActivity(intent);
    }

    public void sensorsClicked(View view) {
        Intent intent = new Intent(Menu.this, Sensors.class);
        startActivity(intent);
    }

    public void settingsClicked(View view) {
        Intent intent = new Intent(Menu.this, Settings.class);
        startActivity(intent);
    }

    public void signOutClicked(View view) {
        SharedPreferences.Editor editor = preferences.edit();
        editor.putBoolean("isLoggedIn", false);
        editor.apply();

        Intent intent = new Intent(Menu.this, Login.class);
        startActivity(intent);
        finish();
    }
}
