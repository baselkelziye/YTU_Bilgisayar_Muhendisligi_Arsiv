package com.example.must.mobilehomework;

import android.content.DialogInterface;
import android.content.Intent;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Toast;

import com.example.must.mobilehomework.file.FileController;
import com.example.must.mobilehomework.model.Car;
import com.example.must.mobilehomework.model.Log;
import com.example.must.mobilehomework.model.RentDate;
import com.example.must.mobilehomework.model.RentSelection;
import com.example.must.mobilehomework.model.User;
import com.example.must.mobilehomework.myadapter.CarAdapter;

import java.util.List;

public class CarSelectActivity extends AppCompatActivity {
    private RentSelection rs;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_car_list);

        Intent intent = getIntent();
        rs = (RentSelection) intent.getSerializableExtra("RentSelection");


        final List<Car> carList = new FileController().getFreeCars(this, rs);//uygun araba listesi döner

        //liste boşsa bir önceye döndür uygun araba yok yazdır
        if(carList.size() == 0){
            Intent i = new Intent(CarSelectActivity.this, RentActivity.class);
            startActivity(i);
            Toast.makeText(CarSelectActivity.this, "Uygun araba bulunmamaktadır", Toast.LENGTH_SHORT).show();
        }
        else{
            ListView liste = (ListView) findViewById(R.id.liste);
            CarAdapter cAdapter = new CarAdapter(this,carList);
            liste.setAdapter(cAdapter);

            //onclick ile seçince log a ekle
            liste.setOnItemClickListener(new AdapterView.OnItemClickListener() {
                @Override
                public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                    RentDate rt = new RentDate();
                    rt.setPickupMonth(rs.getPickupMonth());
                    rt.setPickupDay(rs.getPickupDay());
                    rt.setDropoffMonth(rs.getDropoffMonth());
                    rt.setDropoffDay(rs.getDropoffDay());

                    Log log = new Log();
                    log.setCarId(carList.get(position).getId());
                    log.setUser(getIntent().getStringExtra("userName"));
                    log.setDate(rt);
                    log.setPickupCity(rs.getPickupCity());
                    log.setDropoffCity(rs.getDropoffCity());

                    new FileController().saveLog(log, CarSelectActivity.this);

                    Intent i = new Intent(CarSelectActivity.this, LogDetailActivity.class);
                    String userName = getIntent().getStringExtra("userName");
                    i.putExtra("userName", userName);
                    i.putExtra("log", log);
                    startActivity(i);
                }
            });
            //yeni activitye yollayıp detaylı görüntü ver
        }


    }
}
