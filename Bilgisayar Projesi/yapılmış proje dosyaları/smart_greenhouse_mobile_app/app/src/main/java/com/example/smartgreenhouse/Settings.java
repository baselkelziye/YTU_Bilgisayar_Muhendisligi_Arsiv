package com.example.smartgreenhouse;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.app.AppCompatDelegate;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Toast;
import android.widget.ToggleButton;

import com.google.android.material.textfield.TextInputEditText;
import com.google.android.material.textfield.TextInputLayout;

public class Settings extends AppCompatActivity {

    private ToggleButton darkModeToggle;
    private Button homeButton;
    private Button settingsButton;
    private ImageButton applyIpButton;
    private EditText ipBox;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);
        getXmlItems();

        darkModeToggle.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                applyDark();
            }
        });

        settingsButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                refresh();
            }
        });

        homeButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                goHome();
            }
        });

        applyIpButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                applyIP();
            }
        });


    }

    private void applyDark() {
        SharedPreferences setting1 = getSharedPreferences(getString(R.string.memory), 0);
        SharedPreferences.Editor editor1 = setting1.edit();
        editor1.putBoolean(getString(R.string.darkMode), darkModeToggle.isChecked());
        editor1.apply();
        if (darkModeToggle.isChecked()) AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES);
        else AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
        Toast("Applied successfully.");
    }

    private void applyIP() {
        SharedPreferences setting1 = getSharedPreferences(getString(R.string.memory), 0);
        SharedPreferences.Editor editor1 = setting1.edit();
        String ip = ipBox.getText().toString();
        editor1.putString(getString(R.string.ipSelection), ip);
        editor1.apply();
        Toast(getString(R.string.approve3));
    }

    private void getXmlItems() {
        homeButton = findViewById(R.id.homeButton);
        settingsButton = findViewById(R.id.settingsButton);
        settingsButton.setText(getString(R.string.Refresh));
        ipBox = findViewById(R.id.ipBox);
        applyIpButton = findViewById(R.id.setIpButton);
        darkModeToggle = findViewById(R.id.darkModeToggle);

        SharedPreferences setting0 = this.getSharedPreferences(getString(R.string.memory), 0);
        boolean isDark = setting0.getBoolean(getString(R.string.darkMode), false);
        String ip = setting0.getString(getString(R.string.ipSelection), "");

        darkModeToggle.setChecked(isDark);
        ipBox.setText(ip);
    }

    private void refresh(){
        Intent intent = new Intent(Settings.this, Settings.class);
        startActivity(intent);
    }

    private void goHome() {
        Intent intent = new Intent(Settings.this, MainActivity.class);
        Toast(getString(R.string.LoadingMsg));
        startActivity(intent);
    }

    public void Toast(String s) {
        Toast.makeText(this, s, Toast.LENGTH_SHORT).show();
    }
}