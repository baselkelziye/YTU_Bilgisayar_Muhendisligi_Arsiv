package com.example.barissemerci;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    int loginCounter = 0;
    public static ArrayList<Person> persons = new ArrayList<>();
    public static int whichPerson = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        try {
            FileInputStream fileIn = new FileInputStream(getFilesDir() + "/userlist.dat");
            ObjectInputStream objectIn = new ObjectInputStream(fileIn);
            boolean keepReading = true;
            try {
                while (keepReading) {
                    Person user = (Person) objectIn.readObject();
                    persons.add(user);


                    objectIn = new ObjectInputStream(fileIn);

                }
                objectIn.close();
                fileIn.close();
            } catch (EOFException e) {
                keepReading = false;
            }
        } catch (Exception ex) {
            ex.printStackTrace();

        }
    }

    public void login(View view) {


        TextView textView = findViewById(R.id.textView);
        EditText textName = findViewById(R.id.editTextTextEmailAddress);
        EditText textPassword = findViewById(R.id.editTextNumberPassword);
        int count = 0;
        int flag = 0;
        while (persons.size() > count) {
            if (persons.get(count).getEmail().equals(textName.getText().toString()) && persons.get(count).getPassword().equals(textPassword.getText().toString()) && flag == 0) {
                Toast.makeText(getApplicationContext(), "Successful Login!", Toast.LENGTH_LONG).show();
                Intent intent = new Intent(this, MenuActivity.class);
                intent.putExtra("count", count);
                startActivity(intent);
                whichPerson = count;
                flag = 1;
                finish();
            }
            count++;
        }
        if (flag == 0) {
            loginCounter++;

            textView.setText("Wrong e-mail or password!");
            if (loginCounter > 2) {
                Toast.makeText(getApplicationContext(), "You tried more than 3 times! You have to sign up!", Toast.LENGTH_LONG).show();
                Intent intent = new Intent(this, SignupActivity.class);
                startActivity(intent);
                loginCounter = 0;
            }
        }


    }


    public void signup(View view) {

        Intent intent = new Intent(this, SignupActivity.class);
        startActivity(intent);


    }

    @Override
    protected void onStop() {
        super.onStop();
        File f = new File(getFilesDir() + "/userlist.dat");
        f.delete();
        FileOutputStream outStream = null;
        try {

            f = new File(getFilesDir() + "/userlist.dat");

            outStream = new FileOutputStream(f, true);
            ObjectOutputStream objectOutStream = new ObjectOutputStream(outStream);

            for (Person i : persons) {
                objectOutStream.writeObject(i);
            }

            objectOutStream.close();
        } catch (FileNotFoundException e1) {
            e1.printStackTrace();
        } catch (IOException e1) {
            e1.printStackTrace();
        }
    }
}