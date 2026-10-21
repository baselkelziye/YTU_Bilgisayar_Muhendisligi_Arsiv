package com.bariscanyilmaz.musicplayer.view;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.room.Room;

import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Toast;

import com.bariscanyilmaz.musicplayer.databinding.ActivityLoginBinding;
import com.bariscanyilmaz.musicplayer.model.User;
import com.bariscanyilmaz.musicplayer.roomdb.AppDatabase;
import com.bariscanyilmaz.musicplayer.utils.AppSettings;

public class LoginActivity extends AppCompatActivity {

    SharedPreferences sharedPreferences;
    private ActivityLoginBinding binding;

    private AppDatabase db;
    private int loginTry;

    final String emailPattern = "[a-zA-Z0-9._-]+@[a-z]+\\.+[a-z]+";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding=ActivityLoginBinding.inflate(getLayoutInflater());
        View view=binding.getRoot();
        setContentView(view);
        db= Room.databaseBuilder(getApplicationContext(), AppDatabase.class,"app-db").allowMainThreadQueries().build();
        binding.loginUserPassword.addTextChangedListener(textWatcher);
        binding.loginUserEmail.addTextChangedListener(textWatcher);

    }
    final TextWatcher textWatcher=new TextWatcher() {
        @Override
        public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

        }

        @Override
        public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
            String password=binding.loginUserPassword.getText().toString();
            String email=binding.loginUserEmail.getText().toString();

            binding.loginButton.setEnabled(!password.isEmpty() && !email.isEmpty());


        }

        @Override
        public void afterTextChanged(Editable editable) {

        }
    };

    @Override
    protected void onResume() {
        sharedPreferences=getApplicationContext().getSharedPreferences(AppSettings.APP_SHARED_PREFS, Context.MODE_PRIVATE);
        boolean isUserLoggedIn = sharedPreferences.getBoolean("isLoggedIn", false);
        if(isUserLoggedIn){//redirect to songs
            redirectToMain();
        }
        loginTry=0;
        super.onResume();
    }

    public void login(View view){
        String email = binding.loginUserEmail.getText().toString();
        String password = binding.loginUserPassword.getText().toString();

        if(!email.matches(emailPattern)){
            binding.loginUserEmail.setError("Email is not valid");
            return;
        }

         User user= db.userDao().getUserByEmail(email);
         if(user!=null && user.checkPassword(password)){

             //redirect to main activity
             Toast.makeText(this, "Login succeeded", Toast.LENGTH_SHORT).show();

             SharedPreferences.Editor editor= sharedPreferences.edit();
             editor.putBoolean("isLoggedIn",true).apply();
             redirectToMain();

         }else{

             if(loginTry>=3){
                 //redirect to register
                 Toast.makeText(this, "You are redirected to register screen", Toast.LENGTH_SHORT).show();
                 redirectToRegister();
             }else{
                 Toast.makeText(this, "Email or Password is incorrect", Toast.LENGTH_SHORT).show();
                 loginTry++;
             }
         }
    }

    private void redirectToMain(){
        Intent main=new Intent(this,MainActivity.class);
        startActivity(main);
        finish();
    }

    private void redirectToRegister(){
        Intent register=new Intent(this,RegisterActivity.class);
        startActivity(register);
        finish();
    }

    public void createAccount(View view){
        redirectToRegister();
    }




}