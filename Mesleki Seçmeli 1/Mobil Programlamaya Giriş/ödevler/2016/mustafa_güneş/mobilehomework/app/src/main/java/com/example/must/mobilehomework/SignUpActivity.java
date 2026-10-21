package com.example.must.mobilehomework;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.must.mobilehomework.file.FileController;
import com.example.must.mobilehomework.model.User;

public class SignUpActivity extends AppCompatActivity {
    private EditText edtName;
    private EditText edtSurname;
    private EditText edtUserName;
    private EditText edtPassword;
    private String name;
    private String surname;
    private String userName;
    private String password;
    private Button btnSave;
    private Intent intent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sign_up);
        initialize();
        buttonClick();
    }

    private void initialize(){
        edtName = (EditText)findViewById(R.id.edtName);
        edtSurname = (EditText)findViewById(R.id.edtSurname);
        edtUserName = (EditText)findViewById(R.id.edtUserName);
        edtPassword = (EditText)findViewById(R.id.edtPassword);
        btnSave = (Button)findViewById(R.id.btnSave);
    }

    private void buttonClick(){
        btnSave.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(readFields() == true) {
                    intent = new Intent(SignUpActivity.this, LoginActivity.class);
                    FileController fc = new FileController();
                    fc.saveUser(new User(name, surname, userName, password),SignUpActivity.this);
                    Toast.makeText(SignUpActivity.this, "Kaydınız Başarıyla Oluşturuldu\n" +
                            "Giriş Yapabilirsiniz", Toast.LENGTH_LONG).show();
                    startActivity(intent);
                }
            }
        });
    }

    //edittext alanları burada okunur
    private boolean readFields(){
        name = edtName.getText().toString();
        surname = edtSurname.getText().toString();
        userName = edtUserName.getText().toString();
        password = edtPassword.getText().toString();

        if(name.length() == 0){
            edtName.requestFocus();
            edtName.setError("İsim alanı boş bırakılamaz");
            return false;
        }
        else if(!name.matches("[a-zA-Z]+")){ //regex ile
            edtName.requestFocus();
            edtName.setError("Sadece alfabetik karakterler girilebilir");
            return false;
        }
        else if(surname.length() == 0){
            edtSurname.requestFocus();
            edtSurname.setError("soyisim alanı boş bırakılamaz");
            return false;
        }
        else if(!surname.matches("[a-zA-Z]+")){
            edtSurname.requestFocus();
            edtSurname.setError("Sadece alfabetik karakterler girilebilir");
            return false;
        }
        else if(userName.length() == 0){
            edtUserName.requestFocus();
            edtUserName.setError("Kullanıcı adı alanı boş bırakılamaz");
            return false;
        }
        else if(new FileController().isExistUserName(userName,this)){ // dosyadan kontrol yap --
            edtUserName.requestFocus();
            edtUserName.setError("Bu kullanıcı adı zaten alınmış");
            return false;
        }
        else if(password.length() < 4){
            edtPassword.requestFocus();
            edtPassword.setError("En az 4 haneli bir şifre giriniz");
            return false;
        }

        return true;
    }
}
