package com.example.blm3520_hw1;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.app.AlertDialog;
import android.app.Service;
import android.content.DialogInterface;
import android.graphics.Color;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.widget.TextView;

import java.text.DecimalFormat;

public class Sensors extends AppCompatActivity implements SensorEventListener {

    ConstraintLayout layout;
    TextView lightText, accelerometerText, alertText;

    SensorManager sensorManager;
    Sensor lightSensor;
    Sensor accelerometer;

    CountDownTimer timer;
    float tmpX, tmpY, tmpZ = 0.00f;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sensors);

        bindView();

        sensorManager = (SensorManager) getSystemService(Service.SENSOR_SERVICE);

        lightSensor = sensorManager.getDefaultSensor(Sensor.TYPE_LIGHT);
        accelerometer = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);

        timer = createTimer();
    }

    private void bindView() {
        layout = findViewById(R.id.layout);
        lightText = findViewById(R.id.lightText);
        accelerometerText = findViewById(R.id.accelerometerText);
        alertText = findViewById(R.id.alertText);
    }

    @Override
    protected void onPause() {
        super.onPause();
        sensorManager.unregisterListener(this);
        timer.cancel();
    }

    private CountDownTimer createTimer() {
        return new CountDownTimer(5000, 1000) {
            @Override
            public void onTick(long millisUntilFinished) {
                alertText.setText(millisUntilFinished / 1000 + "Second Left to Shut Down\n\nPlease Move!!!");
            }

            @Override
            public void onFinish() {
                exitApp();
            }
        }.start();
    }

    @Override
    protected void onResume() {
        super.onResume();
        sensorManager.registerListener(this, lightSensor, SensorManager.SENSOR_DELAY_NORMAL);
        sensorManager.registerListener(this, accelerometer, SensorManager.SENSOR_DELAY_NORMAL);
    }


    @Override
    public void onSensorChanged(SensorEvent event) {
        if (event.sensor.getType() == Sensor.TYPE_LIGHT) {
            int sensorValue = (int) event.values[0];
            int value = (int) sensorValue * 255 / 40000;
            int backColor = Color.rgb(value, value, value);
            layout.setBackgroundColor(backColor);
            lightText.setText(sensorValue + " Light(lux), " + value + " RGB \n\n (Dark < 80 < Light)");

            if(value < 80) {    // Dark Theme
                layout.setBackgroundColor(Color.rgb(39,39,39));
                lightText.setTextColor(Color.WHITE);
                accelerometerText.setTextColor(Color.WHITE);
                alertText.setTextColor(Color.WHITE);
            }
            else{               // Light Theme
                layout.setBackgroundColor(Color.WHITE);
                lightText.setTextColor(Color.BLACK);
                accelerometerText.setTextColor(Color.BLACK);
                alertText.setTextColor(Color.BLACK);
            }
        }

        if (event.sensor.getType() == Sensor.TYPE_ACCELEROMETER) {
            DecimalFormat df = new DecimalFormat("#.##");
            float x = Float.valueOf(df.format(event.values[0]));
            float y = Float.valueOf(df.format(event.values[1]));
            float z = Float.valueOf(df.format(event.values[2]));
            accelerometerText.setText("Last= X: " + tmpX + " Y: " + tmpY + " Z: " + tmpZ + "\n\n Now= X: " + x + " Y: " + y + " Z: " + z + "\n\n if changes > 1f, it updates");
            checkMotion(x, y, z);
            System.out.println("X: " + x + " Y: " + y + " Z: " + z);
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }

    private void exitApp() {
        AlertDialog.Builder alert = new AlertDialog.Builder(this);
        alert.setTitle("Shutting Down");
        alert.setMessage("");
        alert.setPositiveButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                finishAffinity();
                System.exit(0);
            }
        });
        alert.create().show();
    }

    private void checkMotion(float x, float y, float z) {
        if ( Math.abs(tmpX - x) < 1f && Math.abs(tmpY - y) < 1f && Math.abs(tmpZ - z) < 1f ) {
            // Timer Devamke
            return;
        }
        tmpX = x;
        tmpY = y;
        tmpZ = z;
        timer.cancel();
        timer = createTimer();
    }
}
