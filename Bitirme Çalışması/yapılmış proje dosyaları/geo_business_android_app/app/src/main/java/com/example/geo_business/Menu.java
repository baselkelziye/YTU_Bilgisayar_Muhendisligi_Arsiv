package com.example.geo_business;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.example.models.User;
import com.example.shared_data.UserData;

public class Menu extends AppCompatActivity {

    TextView userName;
    Button profile, createTravel, viewTravels, travelPlan;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        userName = (TextView) findViewById(R.id.menu_tv_user);

        profile = (Button) findViewById(R.id.menu_bt_profile);
        createTravel = (Button) findViewById(R.id.menu_bt_create);
        viewTravels = (Button) findViewById(R.id.menu_bt_travels);
        travelPlan = (Button) findViewById(R.id.menu_bt_plan);

        User user = UserData.getInstance().getSharedData();
        String name = user.getName() + " " + user.getSurname();
        userName.setText(name);

        profile.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Profile.class);
                startActivity(intent);
            }
        });

        createTravel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Map.class);
                startActivity(intent);
            }
        });

        viewTravels.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Travels.class);
                startActivity(intent);
            }
        });

        travelPlan.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Plans.class);
                startActivity(intent);
            }
        });

    }
}
