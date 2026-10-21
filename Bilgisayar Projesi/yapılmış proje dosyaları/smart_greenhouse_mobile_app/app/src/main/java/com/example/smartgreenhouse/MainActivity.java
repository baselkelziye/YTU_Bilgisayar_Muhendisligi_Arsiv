package com.example.smartgreenhouse;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.app.AppCompatDelegate;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private Button gh1Button;
    private Button gh2Button;
    private Button gh3Button;
    private Button gh4Button;
    private Button homeButton;
    private Button settingsButton;

    Client client;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        firstTime();
        startListening();
        getConnections();
        getXmlItems();

        gh1Button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openDetails(1);
            }
        });
        gh2Button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openDetails(2);
            }
        });
        gh3Button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openDetails(3);
            }
        });
        gh4Button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openDetails(4);
            }
        });
        homeButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                refresh();
            }
        });
        settingsButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                goToSettings();
            }
        });
    }


    @Override
    protected void onRestart() {
        super.onRestart();
        startListening();
    }

    @Override
    protected void onStop() {
        super.onStop();
        client.turnOff();
    }

    private void firstTime() {
        SharedPreferences setting0 = getSharedPreferences(getString(R.string.memory), 0);
        boolean firstTime = setting0.getBoolean(getString(R.string.firstTime), true);

        if (firstTime) {
            SharedPreferences.Editor editor0 = setting0.edit();
            editor0.putBoolean(getString(R.string.firstTime), false);
            editor0.apply();

            editor0.putBoolean(getString(R.string.darkMode), false);
            editor0.apply();

            editor0.putString(getString(R.string.ipSelection), "25.74.127.57");
            editor0.apply();

            int i;
            for(i=1;i<=4;i++){
                editor0.putInt(String.valueOf(i) + getString(R.string.Temp), 25+i);
                editor0.apply();

                editor0.putInt(String.valueOf(i) + getString(R.string.Goal), 27+i);
                editor0.apply();

                editor0.putBoolean(String.valueOf(i) + getString(R.string.isOn), false);
                editor0.apply();

                editor0.putBoolean(String.valueOf(i) + getString(R.string.isConnected), true);
                editor0.apply();
            }

        }

        boolean darkMode = setting0.getBoolean(getString(R.string.darkMode), false);
        if (darkMode) AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES);
        else AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
    }


    private void getXmlItems() {
        List<Button> buttonArray = new ArrayList<>();
        gh1Button = findViewById(R.id.greenhouse1);
        buttonArray.add(gh1Button);
        gh2Button = findViewById(R.id.greenhouse2);
        buttonArray.add(gh2Button);
        gh3Button = findViewById(R.id.greenhouse3);
        buttonArray.add(gh3Button);
        gh4Button = findViewById(R.id.greenhouse4);
        buttonArray.add(gh4Button);
        settingsButton = findViewById(R.id.settingsButton);
        homeButton = findViewById(R.id.homeButton);
        homeButton.setText(getString(R.string.Refresh));

        SharedPreferences setting0 = getSharedPreferences(getString(R.string.memory), 0);

        int i;
        for(i=1;i<=4;i++){
            int idx = i - 1;
            if ((setting0.getBoolean(String.valueOf(i) + getString(R.string.isConnected), false))){
                CharSequence txt = buttonArray.get(idx).getText();
                txt = txt + "\n" + getString(R.string.nconnected);
                buttonArray.get(idx).setText(txt);
            }
            else {
                CharSequence txt = buttonArray.get(idx).getText();
                buttonArray.get(idx).setEnabled(false);
                txt = txt + "\n" + getString(R.string.connected);
                buttonArray.get(idx).setText(txt);
            }
        }
    }

    private void openDetails(int index){
        client.turnOff();
        Intent intent = new Intent(MainActivity.this, Details.class);
        intent.putExtra(getString(R.string.greenhouse), index);
        int waiter = 0;
        Toast(getString(R.string.LoadingMsg));
        while (client.isActive()) { Log.i("[SMARTGREENHOUSE]", "WAITING FOR SOCKET BEFORE LEAVING"); waiter += 1;}
        startActivity(intent);
    }

    private void goToSettings(){
        client.turnOff();
        Intent intent = new Intent(MainActivity.this, Settings.class);
        int waiter = 0;
        while (client.isActive()) { Log.i("[SMARTGREENHOUSE]", "WAITING FOR SOCKET BEFORE LEAVING"); waiter += 1;}
        startActivity(intent);
    }

    private void refresh(){
        client.turnOff();
        Intent intent = new Intent(MainActivity.this, MainActivity.class);
        int waiter = 0;
        Toast(getString(R.string.LoadingMsg));
        while (client.isActive()) { Log.i("[SMARTGREENHOUSE]", "WAITING FOR SOCKET BEFORE LEAVING"); waiter += 1;}
        startActivity(intent);
    }

    private void startListening(){
        SharedPreferences setting0 = getSharedPreferences(getString(R.string.memory), 0);
        client = new Client();
        client.setPortIp(setting0.getString(getString(R.string.ipSelection), ""), getString(R.string.port));
        client.turnOn();
        client.execute();
    }

    private void getConnections() {
        int waiter = 0;
        client.waitRespond(1);
        client.send("X.1");
        while(client.isWaitingResponse()){Log.i("[SMARTGREENHOUSE]", "WAITING FOR RESPONSE [1]"); waiter += 1; if (waiter > 2000){ waiter = 0; client.send("X.1");}}
        applyClientData();
        client.waitRespond(2);
        client.send("X.2");
        waiter = 0;
        while(client.isWaitingResponse()){ Log.i("[SMARTGREENHOUSE]", "WAITING FOR RESPONSE [2]"); waiter += 1; if (waiter > 2000){ waiter = 0; client.send("X.2");}}
        applyClientData();
        client.waitRespond(3);
        client.send("X.3");
        waiter = 0;
        while(client.isWaitingResponse()){Log.i("[SMARTGREENHOUSE]", "WAITING FOR RESPONSE [3]"); waiter += 1; if (waiter > 2000){ waiter = 0; client.send("X.3");}}
        applyClientData();
        client.waitRespond(4);
        client.send("X.4");
        waiter = 0;
        while(client.isWaitingResponse()){Log.i("[SMARTGREENHOUSE]", "WAITING FOR RESPONSE [4]"); waiter += 1; if (waiter > 2000){ waiter = 0; client.send("X.4");}}
        applyClientData();
    }

    private void applyClientData(){
        SharedPreferences setting0 = getSharedPreferences(getString(R.string.memory), 0);
        SharedPreferences.Editor editor0 = setting0.edit();

        String txt = String.valueOf(client.gCode) + getString(R.string.isOn);
        editor0.putBoolean(txt, (client.goal < 51));
        editor0.apply();

        txt = String.valueOf(client.gCode) + getString(R.string.Temp);
        editor0.putInt(txt, (client.temperature));
        editor0.apply();

        txt = String.valueOf(client.gCode) + getString(R.string.isConnected);
        editor0.putBoolean(txt, (client.goal < 52));
        editor0.apply();

        txt = String.valueOf(client.gCode) + getString(R.string.Goal);
        editor0.putInt(txt, (client.goal));
        editor0.apply();

    }

    public void Toast(String s) {
        Toast.makeText(MainActivity.this, s, Toast.LENGTH_SHORT).show();
    }
}