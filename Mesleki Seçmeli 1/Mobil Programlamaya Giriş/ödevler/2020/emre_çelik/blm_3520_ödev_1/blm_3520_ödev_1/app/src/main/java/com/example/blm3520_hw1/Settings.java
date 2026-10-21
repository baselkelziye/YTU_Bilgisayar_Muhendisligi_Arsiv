package com.example.blm3520_hw1;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Switch;
import android.widget.Toast;

public class Settings extends AppCompatActivity {
    ConstraintLayout layout;
    EditText usernameText, heightText, weightText, ageText;
    RadioGroup radioGroup;
    RadioButton radioMale, radioFemale;
    Switch themeSwitch;
    Button updateButton;

    SharedPreferences preferences;
    Boolean currentGender;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);

        linkView();

    }

    private void linkView() {
        preferences = this.getSharedPreferences("User", MODE_PRIVATE);

        layout = findViewById(R.id.layout);
        usernameText = findViewById(R.id.usernameText);
        heightText = findViewById(R.id.heightText);
        weightText = findViewById(R.id.weightText);
        ageText = findViewById(R.id.ageText);
        radioGroup = findViewById(R.id.radioGroup);
        radioMale = findViewById(R.id.radioMale);
        radioFemale = findViewById(R.id.radioFemale);
        themeSwitch = findViewById(R.id.themeSwitch);
        updateButton = findViewById(R.id.updateButton);

        fillView();
//        Boolean state = themeSwitch.isChecked();
    }

    private void fillView() {
        usernameText.setText(preferences.getString("username", ""));
        heightText.setText(preferences.getString("height", ""));
        weightText.setText(preferences.getString("weight", ""));
        ageText.setText(preferences.getString("age", ""));

        Boolean gender = preferences.getBoolean("gender", true);    //  True is Male
        currentGender = gender;
        if (gender) { radioMale.setChecked(true); }
        else { radioFemale.setChecked(true); }

        Boolean theme = preferences.getBoolean("theme", false);     // Light Theme is False
        if (theme) {
            themeSwitch.setChecked(true);
            darkTheme();
        }
    }

    private void darkTheme() {
        layout.setBackgroundColor(Color.DKGRAY);
        usernameText.setTextColor(Color.WHITE);
        heightText.setTextColor(Color.WHITE);
        weightText.setTextColor(Color.WHITE);
        ageText.setTextColor(Color.WHITE);
        radioMale.setTextColor(Color.WHITE);
        radioFemale.setTextColor(Color.WHITE);
        themeSwitch.setTextColor(Color.WHITE);
    }

    public void maleSelected(View view) {
        currentGender = true;
    }

    public void femaleSelected(View view) {
        currentGender = false;
    }

    public void updateClicked(View view) {
        String name = usernameText.getText().toString();
        String height = heightText.getText().toString();
        String weight = weightText.getText().toString();
        String age = ageText.getText().toString();

        Boolean theme = themeSwitch.isChecked();
        if (theme) { darkTheme(); }

        SharedPreferences.Editor editor = preferences.edit();
        editor.putString("username", name);
        editor.putString("height", height);
        editor.putString("weight", weight);
        editor.putString("age", age);
        editor.putBoolean("theme", theme);
        editor.putBoolean("gender", currentGender);
        editor.apply();
        Toast.makeText(getApplicationContext(),"Successfully Updated",Toast.LENGTH_SHORT).show();
    }
}
