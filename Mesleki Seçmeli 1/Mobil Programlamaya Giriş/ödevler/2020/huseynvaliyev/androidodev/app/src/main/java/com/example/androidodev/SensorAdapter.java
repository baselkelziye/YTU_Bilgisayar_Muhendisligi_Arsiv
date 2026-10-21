package com.example.androidodev;

import android.content.Context;
import android.hardware.Sensor;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import java.util.List;

import androidx.recyclerview.widget.RecyclerView;

public class SensorAdapter extends RecyclerView.Adapter<SensorAdapter.MyViewHolder> {

    List<Sensor> mSensorList;
    LayoutInflater inflater;



    public SensorAdapter(Context context, List<Sensor> sensors) {
        inflater = LayoutInflater.from(context);
        this.mSensorList = sensors;
    }


    @Override
    public MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = inflater.inflate(R.layout.item_sensor_card, parent, false);
        MyViewHolder holder = new MyViewHolder(view);
        return holder;
    }

    @Override
    public void onBindViewHolder(MyViewHolder holder, int position) {
        Sensor selectedSensor = mSensorList.get(position);
        holder.setData(selectedSensor, position);

    }

    @Override
    public int getItemCount() {
        return mSensorList.size();
    }


    class MyViewHolder extends RecyclerView.ViewHolder  {

        TextView sensorName;
        TextView sensorVersion;
        TextView sensorPower;


        public MyViewHolder(View itemView) {
            super(itemView);
            sensorName = (TextView) itemView.findViewById(R.id.sensorName);
            sensorVersion = (TextView) itemView.findViewById(R.id.sensorVersion);
            sensorPower = (TextView) itemView.findViewById(R.id.sensorPower);
        }

        public void setData(Sensor selectedSensor, int position) {
            this.sensorName.setText("Sensor Name:"+mSensorList.get(position).getName());
            this.sensorVersion.setText("Sensor Version:"+mSensorList.get(position).getVersion());
            this.sensorPower.setText("Sensor Power:"+mSensorList.get(position).getPower());
        }


    }
}
