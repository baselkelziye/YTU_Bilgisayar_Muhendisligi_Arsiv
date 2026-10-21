package com.example.must.mobilehomework;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.example.must.mobilehomework.file.FileController;
import com.example.must.mobilehomework.model.User;

public class UserMainActivity extends AppCompatActivity {
    private Button btnRent;
    private Button btnLogs;
    private Button btnExit;
    private TextView txtUserMainTitle;
    private User user;
    private String userName;
    private Intent intent;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_user_main);
        initialize();
        clickButton();
    }

    private void initialize(){
        btnRent = (Button)findViewById(R.id.btnRent);
        btnLogs = (Button)findViewById(R.id.btnLogs);
        btnExit = (Button)findViewById(R.id.btnExit);
        txtUserMainTitle = (TextView)findViewById(R.id.txtUserMainTitle);
        intent = getIntent();
        userName = intent.getStringExtra("userName");
        FileController fc = new FileController();
        String line = fc.getUser(userName, this);
        user = fc.getUser(line);
        txtUserMainTitle.setText("Hoşgeldin " + user.getName());
    }

    private void clickButton(){
        btnRent.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                intent = new Intent(UserMainActivity.this, RentActivity.class);
                intent.putExtra("userName", user.getUserName());
                startActivity(intent);
            }
        });

        btnExit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                intent = new Intent(Intent.ACTION_MAIN);
                intent.addCategory(Intent.CATEGORY_HOME);
                intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                startActivity(intent);
            }
        });
    }

    /*
    //login olduktan sonra back butonunun çalışmaması için
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == KeyEvent.KEYCODE_BACK) {
            // your code
            return true;
        }

        return super.onKeyDown(keyCode, event);
    }*/
}
