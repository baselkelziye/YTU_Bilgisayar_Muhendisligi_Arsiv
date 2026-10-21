package com.example.myapplication1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {


    Boolean moving = false;
    Boolean thereIsLight = false;

    Boolean startedApp = false;
    TextView textView;
    SensorManager sensorManager;
    Sensor lightSensor;
    Sensor proximitySensor;
    Sensor accelerometerSensor;
    Button button;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = findViewById(R.id.textView);
        button =findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startedApp = !startedApp;
                if (startedApp) {
                    Toast.makeText(getApplicationContext(), "App started", Toast.LENGTH_SHORT).show();
                }
                else {
                    Toast.makeText(getApplicationContext(), "App stopped", Toast.LENGTH_SHORT).show();
                }
            }
        });
        // calling sensor service.
        sensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);

        // from sensor service we are
        // calling proximity sensor
        //proximitySensor = sensorManager.getDefaultSensor(Sensor.TYPE_PROXIMITY);
        accelerometerSensor =  sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        lightSensor = sensorManager.getDefaultSensor(Sensor.TYPE_LIGHT);

        if(lightSensor == null) {
            Toast.makeText(this, "No light sensor found in device.", Toast.LENGTH_SHORT).show();
            finish();
        } else {
            sensorManager.registerListener(
                    lightSensorEventListener,
                    lightSensor,
                    SensorManager.SENSOR_DELAY_NORMAL);



        }

        if(accelerometerSensor == null) {
            Toast.makeText(this, "No acceleration sensor found in device.", Toast.LENGTH_SHORT).show();
            finish();
        } else {
            sensorManager.registerListener(
                    accelerometerSensorEventListener,
                    accelerometerSensor,
                    SensorManager.SENSOR_DELAY_NORMAL);

        }
        // handling the case if the proximity
        // sensor is not present in users device.
        /*
        if (proximitySensor == null) {
            Toast.makeText(this, "No proximity sensor found in device.", Toast.LENGTH_SHORT).show();
            finish();
        } else {
            // registering our sensor with sensor manager.
            sensorManager.registerListener(proximitySensorEventListener,
                    proximitySensor,
                    SensorManager.SENSOR_DELAY_NORMAL);
        }

         */
    }



    private void getState () {
        if(!startedApp) {
            return;
        }
        if(this.moving && !this.thereIsLight) {
            this.textView.setText("Telefon cebinde ve kişi hareket ediyor!");
            Intent intent = new Intent();
            intent.setAction("com.example.sefagokceoglu.ADJUST_SOUND_INTENT");
            intent.putExtra("value",true);
            sendBroadcast(intent);
        }
        if(!this.moving && this.thereIsLight) {
            this.textView.setText("Telefon masada!");
            Intent intent = new Intent();
            intent.setAction("com.example.sefagokceoglu.ADJUST_SOUND_INTENT");
            intent.putExtra("value",false);
            sendBroadcast(intent);
        }
    }

    SensorEventListener lightSensorEventListener = new SensorEventListener() {
        @Override
        public void onAccuracyChanged(Sensor sensor, int accuracy) {
            // method to check accuracy changed in sensor.
        }

        @Override
        public void onSensorChanged(SensorEvent event) {
            // check if the sensor type is proximity sensor.
            if(event.sensor.getType() == Sensor.TYPE_LIGHT){
                Log.d("TYPE_LIGHT"," TYPE_ACCELEROMETER Changed");
                //textView.setText((int) event.values[0]);
                float currentReading = event.values[0];

                if(currentReading < 250) {
                    thereIsLight = false;
                }else {
                    thereIsLight = true;
                }
                getState();
            }
        }
    };

    SensorEventListener accelerometerSensorEventListener = new SensorEventListener() {
        @Override
        public void onAccuracyChanged(Sensor sensor, int accuracy) {
            // method to check accuracy changed in sensor.
        }

        @Override
        public void onSensorChanged(SensorEvent event) {
            // check if the sensor type is proximity sensor.
            if (event.sensor.getType()==Sensor.TYPE_ACCELEROMETER){
                Log.d("TYPE_ACCELEROMETER"," TYPE_ACCELEROMETER Changed");
                if (Math.abs(event.values[0]) +Math.abs(event.values[1]-9.78f) + Math.abs(event.values[2] -0.81f) >= 0.1 ) {
                    moving = true;
                }else {
                    moving = false;
                }
                getState();
            }
        }
    };


    /*
    SensorEventListener proximitySensorEventListener = new SensorEventListener() {
        @Override
        public void onAccuracyChanged(Sensor sensor, int accuracy) {
            // method to check accuracy changed in sensor.
        }

        @Override
        public void onSensorChanged(SensorEvent event) {
            // check if the sensor type is proximity sensor.
            if (event.sensor.getType() == Sensor.TYPE_PROXIMITY) {
                if (event.values[0] == 0) {
                    // here we are setting our status to our textview..
                    // if sensor event return 0 then object is closed
                    // to sensor else object is away from sensor.
                    isClose = true;
                } else {
                    isClose = false;
                }
            }
        }
    };

     */
}