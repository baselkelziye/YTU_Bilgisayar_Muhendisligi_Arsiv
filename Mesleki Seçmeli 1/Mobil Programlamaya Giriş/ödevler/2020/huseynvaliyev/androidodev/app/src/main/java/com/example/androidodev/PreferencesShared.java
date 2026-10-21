package com.example.androidodev;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Switch;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class PreferencesShared extends AppCompatActivity {

    EditText nameUser;
    EditText heightUser;
    EditText weightUser;
    EditText ageUser;
    CheckBox maleCheck;
    CheckBox femaleCheck;
    Switch mode;
    Button saveButton;

    public static final String MyPREFERENCES = "MyPrefs" ;
    public static final String UserName = "userNameKey";
    public static final String HeightUser = "userHeightKey";
    public static final String WeightUser = "userWeightKey";
    public static final String AgeUser = "userAgeKey";
    public static  final String MaleCheck = "maleCheckKey";
    public static  final String FemaleCheck = "femaleCheckKey";
    public static  final String Mode = "modeKey";

    SharedPreferences sharedpreferences;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.shared_preferences);

        Bundle bundle = getIntent().getExtras();
        final String userName = bundle.getString("userName");

        nameUser = findViewById(R.id.nameUser);
        heightUser = findViewById(R.id.heightUser);
        weightUser = findViewById(R.id.weightUser);
        ageUser = findViewById(R.id.ageUser);
        maleCheck = findViewById(R.id.maleCheck);
        femaleCheck = findViewById(R.id.femaleCheck);
        mode = findViewById(R.id.mode);
        saveButton = findViewById(R.id.saveButton);
        sharedpreferences = getSharedPreferences(MyPREFERENCES, Context.MODE_PRIVATE);

        nameUser.setText(userName);
        nameUser.setEnabled(false);

        String height = sharedpreferences.getString("userHeightKey", "defaultValue");
        heightUser.setText(height);
        String weight = sharedpreferences.getString("userWeightKey", "defaultValue");
        weightUser.setText(weight);
        String age = sharedpreferences.getString("userAgeKey", "defaultValue");
        ageUser.setText(age);
        boolean male = sharedpreferences.getBoolean("maleCheckKey", true);
        System.out.println(male);
        maleCheck.setChecked(male);
        boolean female = sharedpreferences.getBoolean("femaleCheckKey", true);
        femaleCheck.setChecked(female);
        boolean userMode = sharedpreferences.getBoolean("modeKey",true);
        mode.setChecked(userMode);




        saveButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String un  = nameUser.getText().toString();
                String hu = heightUser.getText().toString();
                String wu = weightUser.getText().toString();
                String ag = ageUser.getText().toString();
                boolean mc = maleCheck.isChecked();
                boolean fc = femaleCheck.isChecked();
                boolean md = mode.isChecked();


                SharedPreferences.Editor editor = sharedpreferences.edit();

                editor.putString(UserName, un).commit();
                editor.putString(HeightUser, hu).commit();
                editor.putString(WeightUser, wu).commit();
                editor.putString(AgeUser, ag).commit();
                editor.putBoolean(MaleCheck,mc).commit();
                editor.putBoolean(FemaleCheck,fc).commit();
                editor.putBoolean(Mode,md).commit();

                Toast.makeText(PreferencesShared.this,"Thanks", Toast.LENGTH_LONG).show();
            }
        });


    }
}
