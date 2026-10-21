package com.example.sefagokceoglu;

import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import com.example.sefagokceoglu.model.User;
import com.example.sefagokceoglu.model.Users;

public class RegisterActivity extends AppCompatActivity {

    private EditText nameEditText;
    private EditText lastnameEditText;
    private EditText emailEditText;
    private EditText phoneEditText;
    private EditText passwordEditText;
    private EditText verifyPasswordEditText;

    private Button registerButton;
    private Button loginButton;

    private ImageView imageView;
    private Uri selectedImage;

    ActivityResultLauncher<String> mGetContent = registerForActivityResult(new ActivityResultContracts.GetContent(),
            new ActivityResultCallback<Uri>() {
                @Override
                public void onActivityResult(Uri uri) {
                    selectedImage = uri;
                    imageView.setImageURI(uri);

                }
            });



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        imageView = findViewById(R.id.imageView);
        registerButton = findViewById(R.id.register);
        loginButton = findViewById(R.id.login);

        nameEditText = findViewById(R.id.editTextName);
        lastnameEditText = findViewById(R.id.editTextLastName);
        emailEditText = findViewById(R.id.editTextEmailAddress);
        phoneEditText = findViewById(R.id.editTextPhone);
        passwordEditText = findViewById(R.id.editTextPassword);
        verifyPasswordEditText = findViewById(R.id.editTextVerifyPassword);


        imageView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
                mGetContent.launch("image/*");            }
        });



        registerButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                User registerUser = new User(nameEditText.getText().toString(),lastnameEditText.getText().toString(),phoneEditText.getText().toString(),emailEditText.getText().toString(),passwordEditText.getText().toString(),verifyPasswordEditText.getText().toString(),selectedImage);
                String result = Users.register(registerUser);

                if(!result.equals("Registered")) {
                    Toast.makeText(getApplicationContext(),result,Toast.LENGTH_SHORT).show();
                }else {
                    Toast.makeText(getApplicationContext(),result,Toast.LENGTH_SHORT).show();
                    finish();
                }
            }
        });

        loginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
            }
        });




    }
}