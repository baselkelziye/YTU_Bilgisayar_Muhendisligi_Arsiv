package com.example.barissemerci;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.app.ShareCompat;
import androidx.core.content.FileProvider;


import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.os.StrictMode;
import android.util.Base64;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import java.io.File;
import java.util.ArrayList;

import static android.Manifest.permission.READ_EXTERNAL_STORAGE;
import static android.Manifest.permission.WRITE_EXTERNAL_STORAGE;


public class ProfileActivity extends AppCompatActivity {


    TextView nameProfile;
    TextView surnameProfile;
    TextView emailProfile;
    TextView phoneProfile;
    TextView birthDateProfile;
    ImageView imageViewProfile;
    Spinner spinnerProfile;

    Button buttonProfileShare;

    String fileName;

    ArrayList<String> exams = new ArrayList<String>();

    int numberOfFileToSend;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_profile);
        _declare();
        nameProfile.setText("Name: " + MainActivity.persons.get(MainActivity.whichPerson).getName());
        surnameProfile.setText("Surname: " + MainActivity.persons.get(MainActivity.whichPerson).getSurname());
        emailProfile.setText("Email: " + MainActivity.persons.get(MainActivity.whichPerson).getEmail());
        phoneProfile.setText("Phone: " + MainActivity.persons.get(MainActivity.whichPerson).getPhone());
        birthDateProfile.setText("Birth Date: " + MainActivity.persons.get(MainActivity.whichPerson).getBirthDate());

        int examNumber = MainActivity.persons.get(MainActivity.whichPerson).getExamNumber();
        for (int i = 0; i <= examNumber; i++) {
            fileName = getFilesDir() + "/" + MainActivity.persons.get(MainActivity.whichPerson).getEmail() + "_" + i + ".txt";
            File f = new File(fileName);
            if (f.exists()) {
                exams.add(MainActivity.persons.get(MainActivity.whichPerson).getExams().get(i).getTitle());
            }

        }


        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_spinner_dropdown_item, exams);
        spinnerProfile.setAdapter(adapter);
        spinnerProfile.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            public void onItemSelected(AdapterView<?> parent, View view,
                                       int position, long arg3) {
                numberOfFileToSend = position;

            }

            public void onNothingSelected(AdapterView<?> arg0) {
                // TODO Auto-generated method stub
            }
        });


        byte[] decodedString = Base64.decode(MainActivity.persons.get(MainActivity.whichPerson).getImage(), Base64.DEFAULT);
        Bitmap decodedByte = BitmapFactory.decodeByteArray(decodedString, 0, decodedString.length);
        imageViewProfile.setImageBitmap(decodedByte);


        ActivityCompat.requestPermissions(this, new String[]{READ_EXTERNAL_STORAGE, WRITE_EXTERNAL_STORAGE}, PackageManager.PERMISSION_GRANTED);
        StrictMode.VmPolicy.Builder builder = new StrictMode.VmPolicy.Builder();
        StrictMode.setVmPolicy(builder.build());


    }

    public void _declare() {
        nameProfile = findViewById(R.id.nameProfile);
        surnameProfile = findViewById(R.id.surnameProfile);
        emailProfile = findViewById(R.id.emailProfile);
        phoneProfile = findViewById(R.id.phoneProfile);
        birthDateProfile = findViewById(R.id.birthDateProfile);
        imageViewProfile = findViewById(R.id.imageViewProfile);
        spinnerProfile = findViewById(R.id.spinnerProfile);
        buttonProfileShare = findViewById(R.id.buttonProfileShare);


    }

    public void shareExam(View view) {


        File sendToFile= new File(getFilesDir() + "/"+MainActivity.persons.get(MainActivity.whichPerson).getEmail()+"_"+numberOfFileToSend+".txt");
        Uri uri = FileProvider.getUriForFile(this, getPackageName(), sendToFile);
        Intent intentShare= new Intent(Intent.ACTION_SEND);
        intentShare.setType("text/plain");
        intentShare.putExtra(Intent.EXTRA_STREAM, uri);
        intentShare.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
        startActivity(Intent.createChooser(intentShare,"Share the file..."));

    }


}