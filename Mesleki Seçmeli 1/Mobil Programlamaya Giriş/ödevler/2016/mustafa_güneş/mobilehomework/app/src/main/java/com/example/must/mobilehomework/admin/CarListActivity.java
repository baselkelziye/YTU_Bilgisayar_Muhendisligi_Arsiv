package com.example.must.mobilehomework.admin;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ListView;

import com.example.must.mobilehomework.R;
import com.example.must.mobilehomework.file.FileController;
import com.example.must.mobilehomework.model.Car;
import com.example.must.mobilehomework.myadapter.CarAdapter;

import java.util.List;

public class CarListActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_car_list);

        List<Car> carList = new FileController().getAllCars(this);
        ListView liste = (ListView) findViewById(R.id.liste);
        CarAdapter cAdapter = new CarAdapter(this,carList);
        liste.setAdapter(cAdapter);
    }
}
