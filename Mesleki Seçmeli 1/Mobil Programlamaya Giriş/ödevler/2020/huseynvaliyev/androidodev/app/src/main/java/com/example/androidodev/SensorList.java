package com.example.androidodev;

import android.graphics.Color;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.View;
import android.widget.Toast;

import static android.hardware.Sensor.TYPE_ACCELEROMETER;
import static android.hardware.Sensor.TYPE_LIGHT;

import java.util.List;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;


public class SensorList extends AppCompatActivity {

    private SensorManager sensorManager;
    private  Sensor lightSensor;
    private  Sensor accelerometerSensor;
    private SensorEventListener lightEventListener;
    private SensorEventListener accelerometerEventListener;
    private View root;
    boolean fineshed = false;
    private View recycleView;


    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.sensor_list);

        SensorManager mSensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        List<Sensor> sensorList= mSensorManager.getSensorList(Sensor.TYPE_ALL);

        final RecyclerView recyclerView = (RecyclerView) findViewById(R.id.recyclerviewSensor);

        SensorAdapter sensorAdapter = new SensorAdapter(this, sensorList);

        recyclerView.setAdapter(sensorAdapter);

        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(this);
        linearLayoutManager.setOrientation(LinearLayoutManager.VERTICAL);
        recyclerView.setLayoutManager(linearLayoutManager);



        sensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        accelerometerSensor = sensorManager.getDefaultSensor(TYPE_ACCELEROMETER);
        lightSensor = sensorManager.getDefaultSensor(TYPE_LIGHT);
        root = findViewById(R.id.root);
        recycleView = findViewById(R.id.recyclerviewSensor);

        if(accelerometerSensor == null){
            Toast.makeText(this,"This device has not accelerometer sensor ",Toast.LENGTH_SHORT).show();
            finish();
        }

        if(lightSensor == null){
            Toast.makeText(this,"This device has not light sensor ",Toast.LENGTH_SHORT).show();
            finish();
        }

        accelerometerEventListener = new SensorEventListener(){
            public void onSensorChanged(SensorEvent event) {
                new CountDownTimer(5000, 1000) {

                    public void onTick(long millisUntilFinished) {

                    }

                    public void onFinish() {
                        fineshed = true;
                    }

                }.start();

                float[] values = event.values;
                if((Float.compare(values[0], (float) 0.0)==0) && (Float.compare(values[1], (float) 9.81)==0) && (Float.compare(values[2], (float) 0.0)==0) && fineshed){
                    Toast.makeText(getApplicationContext(),"Your phone stable for 5 sec",Toast.LENGTH_SHORT).show();
                    SensorList.super.onPause();
                    finish();
                }
            }

            @Override
            public void onAccuracyChanged(Sensor sensor, int accuracy) {
            }

        };


        lightEventListener = new SensorEventListener() {
            @Override
            public void onSensorChanged(SensorEvent sensorEvent) {
                float value = sensorEvent.values[0];
                if(value< 20000.0){
                    root.setBackgroundColor(Color.BLACK);
                    recycleView.setBackgroundColor(Color.BLACK);
                }
                if(value >= 20000.0){
                    root.setBackgroundColor(Color.WHITE);
                    recycleView.setBackgroundColor(Color.WHITE);
                }
            }

            @Override
            public void onAccuracyChanged(Sensor sensor, int accuracy) {
            }
        };


    }

    @Override
    protected void onResume() {
        super.onResume();
        sensorManager.registerListener(lightEventListener,lightSensor,SensorManager.SENSOR_DELAY_FASTEST);
        sensorManager.registerListener(accelerometerEventListener,accelerometerSensor,SensorManager.SENSOR_DELAY_FASTEST);
    }

    @Override
    protected void onPause() {
        super.onPause();
        sensorManager.unregisterListener(lightEventListener);
        sensorManager.unregisterListener(accelerometerEventListener);
    }
}