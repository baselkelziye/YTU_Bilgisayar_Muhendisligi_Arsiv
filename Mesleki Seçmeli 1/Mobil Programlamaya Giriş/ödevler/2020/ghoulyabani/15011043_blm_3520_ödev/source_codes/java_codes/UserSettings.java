package com.example.classapp;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.app.AppCompatDelegate;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

public class UserSettings extends AppCompatActivity {

    Switch lightDark;
    SharedPreferences pref;
    SharedPreferences.Editor editor;
    String currentUser;
    TextView name;
    TextView sex;
    TextView height;
    TextView weight;
    TextView age;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_user_settings);

        pref = getApplicationContext().getSharedPreferences("MyPref", 0);
        editor = pref.edit();

        currentUser = pref.getString("current_user", null);

        lightDark = findViewById(R.id.swtMode);

        /*lightDark.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (isChecked == true){
                    AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES);
                    editor.putString(currentUser+"_mode", "dark");
                    editor.commit();
                    lightDark.setText("Karanlık");
                }
                else{
                    AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
                    editor.putString(currentUser+"_mode", "light");
                    editor.commit();
                    lightDark.setText("Aydınlık");
                }
            }
        });*/

        lightDark.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(lightDark.isChecked() == true) {
                    AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES);
                    editor.putString(currentUser + "_mode", "dark");
                    editor.commit();
                    lightDark.setText("Karanlık");
                    finish();
                    startActivity(getIntent());
                }
                else {
                    AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
                    editor.putString(currentUser+"_mode", "light");
                    editor.commit();
                    lightDark.setText("Aydınlık");
                    finish();
                    startActivity(getIntent());

                }
            }
        });

        updateUI();
    }

    public void updateUI(){


        if (pref.getString(currentUser+"_mode", "light").equals("dark")){
            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    lightDark.setChecked(true);
                    lightDark.setText("Karanlık");
                }
            });
        }
        else if (pref.getString(currentUser+"_mode", "light").equals("light")) {
            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    lightDark.setChecked(false);
                    lightDark.setText("Aydınlık");
                }
            });
        }

        name = findViewById(R.id.txtSNameVal);
        name.setText(currentUser);
        sex = findViewById(R.id.txtSexVal);
        height = findViewById(R.id.txtHeightVal);
        weight = findViewById(R.id.txtWeightVal);
        age = findViewById(R.id.txtAgeVal);

        sex.setText(pref.getString(currentUser+"_sex", ""));
        height.setText(pref.getString(currentUser+"_height", "")+ "cm");
        weight.setText(pref.getString(currentUser+"_weight", "")+ "kg");
        age.setText(pref.getString(currentUser+"_age",""));
    }

    public void editSettings(View v){
        Intent edtInt = new Intent(this, EditSettings.class);
        startActivityForResult(edtInt, 1);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if(requestCode == 1){
            if (resultCode == Activity.RESULT_CANCELED){
                updateUI();
            }
        }
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        Intent returnIntent = new Intent();
        setResult(Activity.RESULT_CANCELED, returnIntent);
        finish();
    }
}
