package com.example.sefagokceoglu;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.example.sefagokceoglu.model.User;
import com.example.sefagokceoglu.model.Users;

import java.util.List;

public class LoginActivity extends AppCompatActivity {

    private EditText userNameTextEdit;
    private EditText passwordTextEdit;
    private Button loginButton;
    private Button registerButton;

    private List<User> users = Users.userList;
    private int retryCount = 0;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.login);

        userNameTextEdit = findViewById(R.id.editTextUserName);
        passwordTextEdit = findViewById(R.id.editTextTextPassword);

        loginButton = findViewById(R.id.login_button);
        registerButton = findViewById(R.id.register_button);

        loginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String result = Users.login(userNameTextEdit.getText().toString(),passwordTextEdit.getText().toString());

                if(result.equals("Success")) {
                    Toast.makeText(getApplicationContext(),"Success",Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent(view.getContext(), MainActivity.class);
                    view.getContext().startActivity(intent);
                    finish();
                }
                else {
                    Toast.makeText(getApplicationContext(),result,Toast.LENGTH_SHORT).show();
                    retryCount++;
                }

                if(retryCount == 3) {
                    retryCount = 0;
                    Intent intent = new Intent(view.getContext(), RegisterActivity.class);
                    view.getContext().startActivity(intent);
                }
            }
        });

        registerButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                retryCount = 0;
                Intent intent = new Intent(view.getContext(), RegisterActivity.class);
                view.getContext().startActivity(intent);
            }
        });



    }



}
