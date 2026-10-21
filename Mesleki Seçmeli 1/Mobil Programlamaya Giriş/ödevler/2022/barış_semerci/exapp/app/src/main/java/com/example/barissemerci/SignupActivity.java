package com.example.barissemerci;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.ImageDecoder;
import android.media.Image;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;

import android.provider.MediaStore;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Base64;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import java.io.BufferedWriter;
import java.io.ByteArrayOutputStream;
import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Vector;

public class SignupActivity extends AppCompatActivity {
    Bitmap selectedImage;
    ImageView imageView;

    EditText textPassword;
    EditText textConfirmPassword;
    TextView textNotMatched;
    EditText textName;
    EditText textSurname;
    EditText textEmail;
    EditText textPhone;
    EditText textBirthDate;
    Person person = new Person();
    int flag = 0;
    //ArrayList<Person> persons = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_signup);

        _declaring();
        textConfirmPassword.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                // textNotMatched.setText("");
            }

            @Override
            public void afterTextChanged(Editable s) {

                String password = textPassword.getText().toString();
                String confirmPassword = textConfirmPassword.getText().toString();
                if (password.length() > 0 && confirmPassword.length() > 0) {
                    if (!password.equals(confirmPassword)) {
                        textNotMatched.setText("Passwords don't match");
                        flag = 0;
                    } else {
                        textNotMatched.setText("Passwords are same");
                        flag = 1;
                    }
                } else if (password.length() == 0 && confirmPassword.length() > 0) {
                    textNotMatched.setText("Password cannot be empty");
                    flag = 0;
                } else if (password.length() > 0 && confirmPassword.length() == 0) {
                    textNotMatched.setText("Re-enter Password cannot be empty");
                    flag = 0;
                }
            }
        });

        textPassword.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                // textNotMatched.setText("");
            }

            @Override
            public void afterTextChanged(Editable s) {

                String password = textPassword.getText().toString();
                String confirmPassword = textConfirmPassword.getText().toString();
                if (password.length() > 0 && confirmPassword.length() > 0) {
                    if (!password.equals(confirmPassword)) {
                        textNotMatched.setText("Passwords don't match");
                        flag = 0;
                    } else {
                        textNotMatched.setText("Passwords are same");
                        flag = 1;
                    }
                } else if (password.length() == 0 && confirmPassword.length() > 0) {
                    textNotMatched.setText("Password cannot be empty");
                    flag = 0;
                } else if (password.length() > 0 && confirmPassword.length() == 0) {
                    textNotMatched.setText("Re-enter Password cannot be empty");
                    flag = 0;
                }
            }
        });


    }

    public void _declaring() {
        textNotMatched = findViewById(R.id.textPasswordNotMatched);
        textPassword = findViewById(R.id.textPassword);
        textConfirmPassword = findViewById(R.id.textReEnterPassword);
        textName = findViewById(R.id.textName);
        textSurname = findViewById(R.id.textSurname);
        textEmail = findViewById(R.id.textEmail);
        textPhone = findViewById(R.id.textPhone);
        textBirthDate = findViewById(R.id.textBirthDate);
        imageView = findViewById(R.id.imageView);


    }


    public void saveImage(View view) {


        if (ContextCompat.checkSelfPermission(this, Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.READ_EXTERNAL_STORAGE}, 1);
        } else {
            Intent intentToGallery = new Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
            startActivityForResult(intentToGallery, 2);
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        if (requestCode == 1) {
            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                Intent intentToGallery = new Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
                startActivityForResult(intentToGallery, 2);
            }

        }
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        if (requestCode == 2 && resultCode == RESULT_OK && data != null) {
            Uri imageData = data.getData();
            try {
                if (Build.VERSION.SDK_INT >= 28) {
                    ImageDecoder.Source source = ImageDecoder.createSource(this.getContentResolver(), imageData);
                    selectedImage = ImageDecoder.decodeBitmap(source);
                    imageView.setImageBitmap(selectedImage);

                } else {
                    selectedImage = MediaStore.Images.Media.getBitmap(this.getContentResolver(), imageData);
                    imageView.setImageBitmap(selectedImage);

                }

            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        super.onActivityResult(requestCode, resultCode, data);
    }

    public void signUp(View view) {
        String name = textName.getText().toString();
        String surname = textSurname.getText().toString();
        String email = textEmail.getText().toString();
        String phone = textPhone.getText().toString();
        String birthDate = textBirthDate.getText().toString();
        String password = textPassword.getText().toString();
        if (name.length() > 0 && surname.length() > 0 && email.length() > 0 && phone.length() > 0 && password.length() > 0) {




            int flag1 = 0;
            int count = 0;
            while (MainActivity.persons.size() > count && flag1 == 0) {
                if (MainActivity.persons.get(count).getEmail().equals(textEmail.getText().toString()) || MainActivity.persons.get(count).getPhone().equals(textPhone.getText().toString())) {
                    flag1 = 1;
                }
                count++;
            }
            if (flag1 == 1) {
                Toast.makeText(getApplicationContext(), "This e-mail/phone number is already used!", Toast.LENGTH_LONG).show();

            } else {
                if (flag == 1) {
                    ByteArrayOutputStream stream = new ByteArrayOutputStream();
                    if(selectedImage!=null){

                        selectedImage.compress(Bitmap.CompressFormat.PNG, 100, stream);


                    }else{
                        Bitmap icon = BitmapFactory.decodeResource(getApplicationContext().getResources(),
                                R.drawable.defaulticon);
                        icon.compress(Bitmap.CompressFormat.PNG, 100, stream);
                    }

                    byte[] byteArray = stream.toByteArray();
                    String encoded = Base64.encodeToString(byteArray, Base64.DEFAULT);
                    person.setImage(encoded);
                    person.setName(name);
                    person.setSurname(surname);
                    person.setEmail(email);
                    person.setPhone(phone);
                    person.setBirthDate(birthDate);
                    person.setPassword(password);
                    MainActivity.persons.add(person);
                    Toast.makeText(getApplicationContext(), "Signed up successfully!", Toast.LENGTH_LONG).show();

                } else {
                    Toast.makeText(getApplicationContext(), "Passwords don't match!", Toast.LENGTH_LONG).show();
                }


            }


        } else {
            Toast.makeText(getApplicationContext(), "Please fill in all the required fields!", Toast.LENGTH_LONG).show();
        }


    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        Intent intent = new Intent(this, MainActivity.class);
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

            for(Person i:MainActivity.persons){
                objectOutStream.writeObject(i);
            }

            objectOutStream.close();
            outStream.close();
        } catch (FileNotFoundException e1) {
            e1.printStackTrace();
        } catch (IOException e1) {
            e1.printStackTrace();
        }
    }
}