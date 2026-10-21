package com.example.blm3520_hw1;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class Login extends AppCompatActivity {

    EditText idText;
    EditText passwordText;
    int wrongEntryCount = 0;
    SharedPreferences preferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        idText = findViewById(R.id.idText);
        passwordText = findViewById(R.id.passwordText);
        preferences = this.getSharedPreferences("User", MODE_PRIVATE);

        Boolean isLoggedIn = preferences.getBoolean("isLoggedIn", false);
        if (isLoggedIn) {
            Intent intent = new Intent(Login.this, Menu.class);
            startActivity(intent);
            finish();
        }
    }

    public void loginClicked(View view) {

        if (idText.getText().toString().matches("") || passwordText.getText().toString().matches("")) { return; }

        if (idText.getText().toString().matches("admin") && passwordText.getText().toString().matches("123")) {
            SharedPreferences.Editor editor = preferences.edit();
            editor.putBoolean("isLoggedIn", true);
            editor.apply();

            Intent intent = new Intent(Login.this, Menu.class);
            startActivity(intent);
            finish();
        }
        else {
            wrongEntryCount++;
            if (wrongEntryCount == 3) { exitApp(); }
            Toast.makeText(getApplicationContext(),"Hint: admin 123 Remaining Entries: " + (3 - wrongEntryCount),Toast.LENGTH_SHORT).show();
        }
    }

    private void exitApp() {
        AlertDialog.Builder alert = new AlertDialog.Builder(this);
        alert.setTitle("Shutting Down");
        alert.setMessage("You have entered 3 incorrect entries...");
        alert.setPositiveButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                int pid = android.os.Process.myPid();
                android.os.Process.killProcess(pid);
            }
        });
        alert.create().show();
    }
}
