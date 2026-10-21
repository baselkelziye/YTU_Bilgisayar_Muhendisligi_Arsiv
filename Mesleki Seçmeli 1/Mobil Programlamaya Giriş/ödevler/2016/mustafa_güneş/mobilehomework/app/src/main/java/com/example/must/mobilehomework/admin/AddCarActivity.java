package com.example.must.mobilehomework.admin;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import com.example.must.mobilehomework.R;
import com.example.must.mobilehomework.file.FileController;
import com.example.must.mobilehomework.model.Car;
import com.example.must.mobilehomework.model.CarTypeList;
import com.example.must.mobilehomework.model.CityList;

import java.io.File;
import java.util.List;

public class AddCarActivity extends AppCompatActivity {
    private EditText edtModel;
    private Spinner spnLocation;
    private Spinner spnType;
    private Button btnAdd;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_car);
        initialize();
        clickHandler();
    }

    private void clickHandler(){
        btnAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Car car = new Car();
                car.setModel(edtModel.getText().toString());
                car.setLocationCity(spnLocation.getSelectedItem().toString());
                car.setType(spnType.getSelectedItem().toString());

                FileController fc = new FileController();

                if(fc.saveCar(car, AddCarActivity.this) == true){
                    Toast.makeText(AddCarActivity.this, "Ekleme Başarılı", Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent(AddCarActivity.this, AdminMainActivity.class);
                    startActivity(intent);
                }

            }
        });
    }

    private void initialize(){
        edtModel = (EditText)findViewById(R.id.edtModel);
        spnLocation = (Spinner)findViewById(R.id.spnLocation);
        spnType = (Spinner)findViewById(R.id.spnType);
        btnAdd = (Button)findViewById(R.id.btnAdd);

        List<String> carTypeList = new CarTypeList().getCarTypeList();
        ArrayAdapter<String> carTypeAdapter = new ArrayAdapter<String>(
                this, android.R.layout.simple_spinner_item, carTypeList);
        carTypeAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spnType.setAdapter(carTypeAdapter);

        List<String> cityList;
        cityList = new CityList().getList();
        ArrayAdapter<String> cityAdapter = new ArrayAdapter<String>(
                this, android.R.layout.simple_spinner_item, cityList);

        cityAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spnLocation.setAdapter(cityAdapter);
    }
}
