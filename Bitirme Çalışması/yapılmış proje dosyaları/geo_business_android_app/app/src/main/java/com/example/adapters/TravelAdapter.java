package com.example.adapters;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.models.Travel;
import com.example.geo_business.R;

import java.util.ArrayList;

public class TravelAdapter extends RecyclerView.Adapter<RecyclerView.ViewHolder> {

    public ArrayList<Travel> travelList;
    public Context travelContext;

    public static class TravelViewHolder extends RecyclerView.ViewHolder {
        TextView id, username, travelDate, startLocation, endLocation, invoiceInfo, invoicePrice, status, approveDate;

        public TravelViewHolder(View view) {
            super(view);

            this.id = view.findViewById(R.id.travel_tv_id);
            this.username = view.findViewById(R.id.travel_tv_username);
            this.travelDate = view.findViewById(R.id.travel_tv_travelDate);
            this.startLocation = view.findViewById(R.id.travel_tv_startLocation);
            this.endLocation = view.findViewById(R.id.travel_tv_endLocation);
            this.invoiceInfo = view.findViewById(R.id.travel_tv_invoiceInfo);
            this.invoicePrice = view.findViewById(R.id.travel_tv_invoicePrice);
            this.status = view.findViewById(R.id.travel_tv_status);
            this.approveDate = view.findViewById(R.id.travel_tv_approveDate);
        }

    }

    public TravelAdapter(ArrayList<Travel> dataSet, Context context) {
        this.travelList = dataSet;
        this.travelContext = context;
    }

    public RecyclerView.ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view;

        view = LayoutInflater.from(parent.getContext()).inflate(R.layout.travel_card, parent, false);
        return new TravelViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull RecyclerView.ViewHolder holder, int position) {
        Travel travel = travelList.get(travelList.size() - position - 1);

        if (travel != null) {
            ((TravelViewHolder) holder).id.setText("ID:  " + String.valueOf(travel.getId()));
            ((TravelViewHolder) holder).username.setText("Username:  " + travel.getUsername());
            ((TravelViewHolder) holder).travelDate.setText("Date: " + travel.getTravelDate());
            ((TravelViewHolder) holder).startLocation.setText("Start Location:  " + travel.getStartLocation());
            ((TravelViewHolder) holder).endLocation.setText("End Location:  " + travel.getEndLocation());
            ((TravelViewHolder) holder).invoiceInfo.setText("Distance:  " + travel.getInvoiceInfo());
            ((TravelViewHolder) holder).invoicePrice.setText("Invoice Price:  " + String.valueOf(travel.getInvoicePrice()));
            ((TravelViewHolder) holder).status.setText("Status:  " + travel.getStatus());
            ((TravelViewHolder) holder).approveDate.setText("Approve Date:  " + travel.getApproveDate());
        }
    }

    public void updateData(ArrayList<Travel> newTravelList) {
        travelList.clear();
        travelList.addAll(newTravelList);
        notifyDataSetChanged();
    }

    public int getItemCount() {
        return travelList.size();
    }
}