package com.example.must.mobilehomework;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.must.mobilehomework.admin.AdminMainActivity;
import com.example.must.mobilehomework.file.LoginController;
import com.example.must.mobilehomework.model.User;

public class LoginActivity extends AppCompatActivity {
    private EditText edtLoginUserName;
    private EditText edtLoginPassword;
    private Button btnSignIn;
    private String loginUserName;
    private String loginPassword;
    private User user;
    private Intent intent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        initialize();
        buttonClick();
    }

    private void initialize(){
        edtLoginUserName = (EditText)findViewById(R.id.edtLoginUserName);
        edtLoginPassword = (EditText)findViewById(R.id.edtLoginPassword);
        btnSignIn = (Button)findViewById(R.id.btnSignIn);
    }

    private void buttonClick(){
        btnSignIn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(readFields() == true){
                    if(!user.getPassword().equals(loginPassword)){
                        Toast.makeText(LoginActivity.this, "Parola yanlış", Toast.LENGTH_SHORT).show();
                    }
                    else{
                        //sistem yöneticisinin anasayfası farklı
                        if(user.getUserName().contains("admin")){
                            intent = new Intent(LoginActivity.this, AdminMainActivity.class);
                            intent.putExtra("userName", loginUserName);
                            startActivity(intent);
                        }
                        else{
                            intent = new Intent(LoginActivity.this, UserMainActivity.class);
                            intent.putExtra("userName", loginUserName);
                            startActivity(intent);
                        }

                    }
                }
            }
        });
    }

    private boolean readFields(){
        loginUserName = edtLoginUserName.getText().toString();
        loginPassword = edtLoginPassword.getText().toString();

        if(loginUserName.length() == 0){
            edtLoginUserName.requestFocus();
            edtLoginUserName.setError("Lütfen kullanıcı adınızı giriniz");
            return false;
        }
        else if(loginPassword.length() < 4){
            edtLoginPassword.requestFocus();
            edtLoginPassword.setError("Lütfen parolanızı giriniz");
            return false;
        }
        //kullanıcı adı-parola bilgilerinin kontrolü
        else if((user = new LoginController().controlLoginInput(loginUserName, loginPassword, this)) == null){
            return false;
        }

        return true;
    }
}
