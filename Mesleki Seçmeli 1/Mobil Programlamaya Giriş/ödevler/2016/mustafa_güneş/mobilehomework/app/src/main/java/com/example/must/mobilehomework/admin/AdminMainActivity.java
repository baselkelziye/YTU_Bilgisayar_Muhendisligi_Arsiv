package com.example.must.mobilehomework.admin;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.widget.Button;

import com.example.must.mobilehomework.R;

public class AdminMainActivity extends AppCompatActivity {
    private Button btnAddCar;
    private Button btnDisplayCar;
    private Button btnDisplayUser;
    private Button btnDisplayRent;
    private Intent intent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_admin_main);
        initialize();
        clickHandler();

    }

    //login olduktan sonra back butonunun çalışmaması için
    /*
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == KeyEvent.KEYCODE_BACK) {
            // your code
            return true;
        }

        return super.onKeyDown(keyCode, event);
    }*/

    private void initialize(){
        btnAddCar = (Button)findViewById(R.id.btnMainAdd);
        btnDisplayCar = (Button)findViewById(R.id.btnDisplayCar);
        btnDisplayUser = (Button)findViewById(R.id.btnDisplayUser);
        btnDisplayRent = (Button)findViewById(R.id.btnDisplayRent);
    }

    private void clickHandler(){
        btnAddCar.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                intent = new Intent(AdminMainActivity.this, AddCarActivity.class);
                startActivity(intent);
            }
        });

        btnDisplayCar.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                intent = new Intent(AdminMainActivity.this, CarListActivity.class);
                startActivity(intent);
            }
        });
    }
}
