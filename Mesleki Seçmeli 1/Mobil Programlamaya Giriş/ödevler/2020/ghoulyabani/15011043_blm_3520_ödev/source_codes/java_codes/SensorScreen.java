package com.example.classapp;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.app.AppCompatDelegate;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Service;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.widget.TextView;

public class SensorScreen extends AppCompatActivity implements SensorEventListener {

    SharedPreferences pref;
    SharedPreferences.Editor editor;
    SensorManager sensorManager;
    Sensor light;
    Sensor acc;
    TextView txtSensor;
    private static String isNight = "";
    private static String isStill = "";
    private static boolean timerStarted = false;
    static int time = 5000;
    static int interval = 100;
    int remainingTime;
    AlertDialog alert;
    private static boolean showError = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        isStill = "";
        timerStarted = false;

        AlertDialog.Builder error = new AlertDialog.Builder(SensorScreen.this);
        error.setMessage("5 saniye hareketsiz kalındı, uygulama kapatılıyor!")
                .setCancelable(false)
                .setPositiveButton("Tamam", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        editor.putInt("remaining_time", 5000).apply();
                        Intent returnIntent = new Intent();
                        returnIntent.putExtra("result", "kill");
                        setResult(Activity.RESULT_OK, returnIntent);
                        finish();
                    }
                });
        alert = error.create();

        if (isNight.equals("yes")){
            AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES);
        }
        else {
            AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
        }

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sensor_screen);

        sensorManager = (SensorManager) getSystemService(Service.SENSOR_SERVICE);
        light = sensorManager.getDefaultSensor(Sensor.TYPE_LIGHT);
        acc = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        txtSensor = findViewById(R.id.txtSensorTest);
    }

    @Override
    protected void onPause() {
        super.onPause();
        sensorManager.unregisterListener((SensorEventListener) this);
    }

    @Override
    protected void onResume() {
        super.onResume();
        sensorManager.registerListener((SensorEventListener) this, light, SensorManager.SENSOR_DELAY_NORMAL);
        sensorManager.registerListener((SensorEventListener) this, acc, SensorManager.SENSOR_DELAY_NORMAL);
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        if (showError == false){
            if (event.sensor.getType() == Sensor.TYPE_LIGHT){
                //txtSensor.setText(""+event.values[0]);
                if (event.values[0] < 15.0){
                    AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES);
                    if (isNight.equals("")){
                        isNight = "yes";
                        recreate();
                    }
                    else if (isNight.equals("no")){
                        isNight = "yes";
                        recreate();
                    }
                }
                else {
                    AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
                    if (isNight.equals("yes")){
                        isNight = "no";
                        recreate();
                    }
                }
            }
            else if (event.sensor.getType() == Sensor.TYPE_ACCELEROMETER){
                if (-0.3 < event.values[0] && 0.2 > event.values[0] && -0.2 < event.values[1] && 0.2 > event.values[1]
                        && 9.7 < event.values[2] && 9.9 > event.values[2]){
                    isStill = "yes";
                    if (timerStarted == false){
                        pref = getApplicationContext().getSharedPreferences("MyPref", 0);
                        editor = pref.edit();
                        remainingTime = pref.getInt("remaining_time", 5000);
                        new CountDownTimer(remainingTime, interval){
                            public void onTick(long millisUntilFinished){
                                if(isStill.equals("no"))
                                {
                                    editor.putInt("remaining_time", 5000).apply();
                                    timerStarted = false;
                                    cancel();
                                }
                                remainingTime = remainingTime - 100;
                            }
                            public void onFinish(){
                                showError = true;
                                alert.show();
                            }
                        }.start();
                    }
                    timerStarted = true;
                }
                else {
                    isStill = "no";
                }
            }
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }
}
