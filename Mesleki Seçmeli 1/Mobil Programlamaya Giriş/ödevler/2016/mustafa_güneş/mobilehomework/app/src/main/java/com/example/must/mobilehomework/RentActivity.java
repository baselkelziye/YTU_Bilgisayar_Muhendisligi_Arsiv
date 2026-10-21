package com.example.must.mobilehomework;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.Toast;
import android.widget.AdapterView.OnItemSelectedListener;

import com.example.must.mobilehomework.model.CarTypeList;
import com.example.must.mobilehomework.model.CityList;
import com.example.must.mobilehomework.model.DateSelection;
import com.example.must.mobilehomework.model.Log;
import com.example.must.mobilehomework.model.RentSelection;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class RentActivity extends AppCompatActivity {
    private Spinner spnPickup;
    private Spinner spnDropoff;
    private Spinner spnPickupMonth;
    private Spinner spnPickupDay;
    private Spinner spnDropoffMonth;
    private Spinner spnDropoffDay;
    private Spinner spnCarType;
    private Button btnSelect;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_rent);
        initialize();
        clickButton();

    }

    private void clickButton(){
       btnSelect.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                RentSelection rs = new RentSelection();
                rs.setPickupMonth(spnPickupMonth.getSelectedItem().toString());
                rs.setPickupDay(Integer.parseInt(spnPickupDay.getSelectedItem().toString()));
                rs.setDropoffMonth(spnDropoffMonth.getSelectedItem().toString());
                rs.setDropoffDay(Integer.parseInt(spnDropoffDay.getSelectedItem().toString()));
                rs.setPickupCity(spnPickup.getSelectedItem().toString());
                rs.setDropoffCity(spnDropoff.getSelectedItem().toString());
                rs.setCarType(String.valueOf(spnCarType.getSelectedItem().toString()));

                // tarih kontrolü - teslim almadan önce olamaz
                Bundle bundle = new Bundle();
                bundle.putSerializable("RentSelection", rs);
                Intent intent = new Intent(RentActivity.this, CarSelectActivity.class);
                intent.putExtra("userName", getIntent().getStringExtra("userName"));
                intent.putExtras(bundle);
                startActivity(intent);
            }
        });

    }

    private void initialize(){
        btnSelect = (Button)findViewById(R.id.btnSelect);
        spnPickup = (Spinner)findViewById(R.id.spnPickup);
        spnDropoff = (Spinner)findViewById(R.id.spnDropoff);
        spnPickupMonth = (Spinner)findViewById(R.id.spnPickupMonth);
        spnPickupDay = (Spinner)findViewById(R.id.spnPickupDay);
        spnDropoffMonth = (Spinner)findViewById(R.id.spnDropoffMonth);
        spnDropoffDay = (Spinner)findViewById(R.id.spnDropoffDay);
        spnCarType = (Spinner)findViewById(R.id.spnCarType);

        List<String> carTypeList = new CarTypeList().getCarTypeList();
        ArrayAdapter<String> carTypeAdapter = new ArrayAdapter<String>(
                this, android.R.layout.simple_spinner_item, carTypeList);
        carTypeAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spnCarType.setAdapter(carTypeAdapter);

        List<String> cityList;
        cityList = new CityList().getList();
        ArrayAdapter<String> cityAdapter = new ArrayAdapter<String>(
                this, android.R.layout.simple_spinner_item, cityList);

        cityAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spnPickup.setAdapter(cityAdapter);
        spnDropoff.setAdapter(cityAdapter);

        DateSelection ds = new DateSelection();
        List<String> monthList = ds.getMonthList();
        List<String> dayList = ds.getDayList();

        ArrayAdapter<String> monthAdapter = new ArrayAdapter<String>(
                this, android.R.layout.simple_spinner_item, monthList);

        monthAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spnPickupMonth.setAdapter(monthAdapter);
        spnDropoffMonth.setAdapter(monthAdapter);

        ArrayAdapter<String> dayAdapter = new ArrayAdapter<String>(
                this, android.R.layout.simple_spinner_item, dayList);

        dayAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spnPickupDay.setAdapter(dayAdapter);
        spnDropoffDay.setAdapter(dayAdapter);
    }

}
