package com.example.reminderapp;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.Switch;

import com.google.android.material.bottomnavigation.BottomNavigationView;

public class SettingsActivity extends AppCompatActivity {

    Switch darkThemeSwitch;

    SharedPreferences sharedpreferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);

        setupBottomNAvigationBar();
        setupView();

    }

    private void setupView() {
        darkThemeSwitch = findViewById(R.id.darkThemeSwitch);
        sharedpreferences = getSharedPreferences("Settings", MODE_PRIVATE);

        boolean darkmode = sharedpreferences.getBoolean("darkmode", false);
        if (darkmode) {
            darkSide();

            darkThemeSwitch.setChecked(true);
        }
        else {
            lightSide();
        }

        darkThemeSwitch.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (isChecked) {
                    SharedPreferences.Editor editor = sharedpreferences.edit();
                    editor.putBoolean("darkmode", true);
                    editor.commit();
                    darkSide();
                }
                else {
                    SharedPreferences.Editor editor = sharedpreferences.edit();
                    editor.putBoolean("darkmode", false);
                    editor.commit();
                    lightSide();
                }
            }
        });

    }

    private void darkSide() {
        darkThemeSwitch.setTextColor(Color.WHITE);
        View view = findViewById(R.id.settingsScreen);
        view.setBackgroundColor(Color.DKGRAY);
    }

    private void lightSide() {
        darkThemeSwitch.setTextColor(Color.BLACK);
        View view = findViewById(R.id.settingsScreen);
        view.setBackgroundColor(Color.WHITE);
    }

    private void setupBottomNAvigationBar() {
        BottomNavigationView bottomNavigationView = findViewById(R.id.bottom_navigation);
        bottomNavigationView.setSelectedItemId(R.id.settings);

        bottomNavigationView.setOnNavigationItemSelectedListener(new BottomNavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem menuItem) {
                switch (menuItem.getItemId()){
                    case R.id.reminders:
                        startActivity(new Intent(getApplicationContext(), ListActivity.class));
                        overridePendingTransition(0,0);
                        return true;
                    case R.id.settings:
                        return true;
                }
                return false;
            }
        });
    }
}
