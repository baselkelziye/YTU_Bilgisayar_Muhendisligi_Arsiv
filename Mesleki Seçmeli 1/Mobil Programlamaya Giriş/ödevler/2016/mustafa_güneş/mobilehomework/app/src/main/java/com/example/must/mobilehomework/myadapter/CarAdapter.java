package com.example.must.mobilehomework.myadapter;

import android.app.Activity;
import android.content.Context;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.must.mobilehomework.R;
import com.example.must.mobilehomework.model.Car;

import java.util.List;

/**
 * Created by must on 01.05.2016.
 */
public class CarAdapter extends BaseAdapter{
    private LayoutInflater mInflater;
    private List<Car> carList;

    public CarAdapter(Activity activity, List<Car> carList){
        mInflater = (LayoutInflater)activity.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        this.carList = carList;
    }

    public View getView(int position, View convertView, ViewGroup parent){
        View satirView;
        satirView = mInflater.inflate(R.layout.row_layout, null);
        ImageView carImage = (ImageView) satirView.findViewById(R.id.imgCar);
        TextView carModel = (TextView) satirView.findViewById(R.id.rowCarModel);
        TextView carType = (TextView) satirView.findViewById(R.id.rowCarType);
        TextView carLocation = (TextView) satirView.findViewById(R.id.rowCarLocation);
        TextView carPrice = (TextView) satirView.findViewById(R.id.rowCarPrice);

        Car car = carList.get(position);
        carModel.setText("  "+car.getModel());
        carType.setText("  "+car.getType());
        carLocation.setText("  "+car.getLocationCity());
        carPrice.setText(" "+car.getPrice());


        if(car.getType().contains("Ekonomik")){
            carImage.setImageResource(R.mipmap.ekonomik);
        }
        else if(car.getType().contains("Standart")){
            carImage.setImageResource(R.mipmap.standart);
        }
        else{
            carImage.setImageResource(R.mipmap.luks);
        }

        return satirView;
    }

    public int getCount(){
        return carList.size();
    }

    public Car getItem(int position){
        return carList.get(position);
    }

    public long getItemId(int position){
        return position;
    }
}
