package com.example.classapp;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.app.AppCompatDelegate;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    EditText txtUserID;
    EditText txtPassword;
    Button btnGiris;
    String[] userId;
    String[] userPw;
    int incorrect = 0;
    SharedPreferences pref;
    SharedPreferences.Editor editor;
    String mode;
    public static boolean killApp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txtUserID = findViewById(R.id.txtUserId);
        txtPassword = findViewById(R.id.txtPassword);
        btnGiris = findViewById(R.id.btnGiris);

        userId = getResources().getStringArray(R.array.Users);
        userPw = getResources().getStringArray(R.array.Passwords);

        pref = getApplicationContext().getSharedPreferences("MyPref", 0);
        editor = pref.edit();

     }


    public void login(View v){
        int length = userId.length;

        String uId = txtUserID.getText().toString();
        String uPw = txtPassword.getText().toString();

        incorrect = incorrect+1;

        for (int i = 0; i < length; i++){
            if (uId.equals(userId[i]) && uPw.equals(userPw[i])){
                incorrect = 0;
                editor.putString("current_user", uId);
                editor.commit();
                Intent menu = new Intent(this, MenuScreen.class);
                if (pref.getString(uId+"_mode",null) == "dark"){
                    AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES);
                }
                else if (pref.getString(uId+"_mode",null) == "light"){
                    AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
                }
                startActivityForResult(menu, 3);
            }
        }
        if (incorrect != 0 && incorrect != 3){
            Toast.makeText(getApplicationContext(),"Kullanıcı adı veya şifre yanlış. Kalan deneme sayısı: " + String.valueOf(3-incorrect),Toast.LENGTH_SHORT).show();
        }
        if (incorrect >= 3){
            AlertDialog.Builder error = new AlertDialog.Builder(this);
            error.setMessage("Şifre 3 kez yanlış girildi, uygulama kapatılıyor!")
                    .setCancelable(false)
                    .setPositiveButton("Tamam", new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int id) {
                            finish();
                            System.exit(0);
                        }
                    });
            AlertDialog alert = error.create();
            alert.show();
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == 3){
            if (resultCode == Activity.RESULT_OK){
                String result = data.getStringExtra("result");
                if (result.equals("kill")){
                    finish();
                    System.exit(0);
                }
            }
        }
    }
}
