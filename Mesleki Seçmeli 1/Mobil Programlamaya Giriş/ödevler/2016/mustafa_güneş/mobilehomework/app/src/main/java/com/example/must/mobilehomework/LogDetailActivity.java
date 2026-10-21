package com.example.must.mobilehomework;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.example.must.mobilehomework.model.Log;

public class LogDetailActivity extends AppCompatActivity {
    private TextView city;
    private TextView pickupDay;
    private TextView dropoffDay;
    private TextView carId;
    private Intent intent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_log_detail);
        initialize();
    }

    private void initialize(){
        city = (TextView) findViewById(R.id.txtDetailCity);
        pickupDay = (TextView) findViewById(R.id.txtDetailPickupDay);
        dropoffDay = (TextView) findViewById(R.id.txtDetailDropoffDay);
        carId = (TextView) findViewById(R.id.txtDetailCarId);

        intent = getIntent();
        Log log = (Log)intent.getSerializableExtra("log");
        city.setText("Arabayı Alacağınız Şehir: "+log.getPickupCity());
        pickupDay.setText("Kiralama Tarihi: "+log.getDate().getPickupDay()+" "+log.getDate().getPickupMonth());
        dropoffDay.setText("Teslim: "+log.getDate().getDropoffDay()+" "+log.getDate().getDropoffMonth());
        carId.setText("Arabanın ID'si: "+log.getCarId());
    }
}
