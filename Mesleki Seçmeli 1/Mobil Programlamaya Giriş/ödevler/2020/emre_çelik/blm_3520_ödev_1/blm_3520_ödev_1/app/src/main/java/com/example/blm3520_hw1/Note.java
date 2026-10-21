package com.example.blm3520_hw1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Note extends AppCompatActivity {

    EditText textView;
    Button saveButton, deleteButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_note);

        textView = findViewById(R.id.textView);
        saveButton = findViewById(R.id.saveButton);
        deleteButton = findViewById(R.id.deleteButton);

        String text = readFromFile(this);

        if (text.matches("")) {
            deleteButton.setEnabled(false);
        }
        else {
            textView.setText(text);
        }
    }

    public void deleteButtonClicked(View view) {
        Boolean isDeleted = this.deleteFile("15011902.txt");
        if (isDeleted) {
            Toast.makeText(getApplicationContext(),"Deleted Successfully",Toast.LENGTH_SHORT).show();
            deleteButton.setEnabled(false);
        }
        else {
            Toast.makeText(getApplicationContext(),"Something Happened -__-",Toast.LENGTH_SHORT).show();
        }
    }

    public void saveButtonClicked(View view) {
        Boolean isSaved = writeToFile(textView.getText().toString(), this);
        if (isSaved) {
            Toast.makeText(getApplicationContext(),"Saved Successfully",Toast.LENGTH_SHORT).show();
            deleteButton.setEnabled(true);
        }
    }

    private Boolean writeToFile(String data, Context context) {
        try {
            OutputStreamWriter outputStreamWriter = new OutputStreamWriter(context.openFileOutput("15011902.txt", Context.MODE_PRIVATE));
            outputStreamWriter.write(data);
            outputStreamWriter.close();
        }
        catch (IOException e) {
            System.out.println(e.toString());
            return false;
        }
        return true;
    }

    private String readFromFile(Context context) {

        String ret = "";

        try {
            InputStream inputStream = context.openFileInput("15011902.txt");

            if ( inputStream != null ) {
                InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
                BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
                String receiveString = "";
                StringBuilder stringBuilder = new StringBuilder();

                while ( (receiveString = bufferedReader.readLine()) != null ) {
                    stringBuilder.append("\n").append(receiveString);
                }

                inputStream.close();
                ret = stringBuilder.toString();
            }
        }
        catch (FileNotFoundException e) {   // File Not Found
            System.out.println(e.toString());
        } catch (IOException e) {           // Can not read file
            System.out.println(e.toString());
        }

        return ret;
    }
}
