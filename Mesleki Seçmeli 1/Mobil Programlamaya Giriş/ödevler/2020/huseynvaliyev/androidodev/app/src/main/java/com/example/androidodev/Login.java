package com.example.androidodev;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class Login extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.login);

        final EditText userName = (EditText) findViewById(R.id.userName);
        final EditText password = (EditText) findViewById(R.id.password);
        Button login = (Button) findViewById(R.id.loginButton);


        login.setOnClickListener(new View.OnClickListener() {
            int count = 0;
            public void onClick(View v) {
                User loginUser = new User();
                String userNameStr = userName.getText().toString();
                String passwordStr = password.getText().toString();
                for(int i=0;i<loginUser.getData().size();i++){
                    if((userNameStr.equals(loginUser.getData().get(i).getUsername()))&&(passwordStr.equals(loginUser.getData().get(i).getPassword()))){
                        Intent intent = new Intent(Login.this, UserPreferences.class);
                        Bundle bundle = new Bundle();
                        bundle.putString("userName",userNameStr);
                        intent.putExtras(bundle);
                        startActivity(intent);
                    }
                }
                count ++;
                if(count==3){
                    Toast.makeText(Login.this,"Wrong username or password", Toast.LENGTH_LONG).show();
                    finish();
                }
            }
        });

    }

}
