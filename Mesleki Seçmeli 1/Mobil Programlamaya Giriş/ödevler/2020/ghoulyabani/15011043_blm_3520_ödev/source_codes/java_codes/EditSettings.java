package com.example.classapp;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.Spinner;

public class EditSettings extends AppCompatActivity implements AdapterView.OnItemSelectedListener {

    SharedPreferences pref;
    SharedPreferences.Editor editor;
    String currentUser;
    Spinner spnSex;
    ArrayAdapter<CharSequence> adapter;
    String txtSex = "";
    EditText edtWeight;
    EditText edtHeight;
    EditText edtAge;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_settings);

        pref = getApplicationContext().getSharedPreferences("MyPref", 0);
        editor = pref.edit();

        currentUser = pref.getString("current_user", null);

        spnSex = findViewById(R.id.spnSex);
        edtWeight = findViewById(R.id.edtWeight);
        edtHeight = findViewById(R.id.edtHeight);
        edtAge = findViewById(R.id.edtAge);
        adapter = ArrayAdapter.createFromResource(this, R.array.Sex, R.layout.support_simple_spinner_dropdown_item);
        adapter.setDropDownViewResource(R.layout.support_simple_spinner_dropdown_item);
        spnSex.setAdapter(adapter);
        spnSex.setOnItemSelectedListener(this);

        edtWeight.setText(pref.getString(currentUser+"_weight", ""));
        edtHeight.setText(pref.getString(currentUser+"_height", ""));
        edtAge.setText(pref.getString(currentUser+"_age", ""));
        txtSex = pref.getString(currentUser+"_sex", "");
        if (txtSex.equals("")){

        }
        else if (txtSex.equals("Kadın")){
            spnSex.setSelection(0);
        }
        else if(txtSex.equals("Erkek")){
            spnSex.setSelection(1);
        }
    }

    public void cancel(View v){
        Intent returnIntent = new Intent();
        setResult(Activity.RESULT_CANCELED, returnIntent);
        finish();
    }

    public void save(View v){
        pref = getApplicationContext().getSharedPreferences("MyPref", 0);
        editor = pref.edit();

        editor.putString(currentUser+"_weight", edtWeight.getText().toString());
        editor.putString(currentUser+"_height", edtHeight.getText().toString());
        editor.putString(currentUser+"_age", edtAge.getText().toString());
        editor.putString(currentUser+"_sex", spnSex.getSelectedItem().toString());
        editor.commit();
        Intent returnIntent = new Intent();
        setResult(Activity.RESULT_CANCELED, returnIntent);
        finish();
    }

    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        txtSex = parent.getItemAtPosition(position).toString();
    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {

    }
}
