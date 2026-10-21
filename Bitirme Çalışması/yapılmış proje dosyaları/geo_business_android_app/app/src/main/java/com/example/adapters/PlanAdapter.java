package com.example.adapters;

import android.content.Context;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.models.Plan;
import com.example.geo_business.R;

import java.util.ArrayList;

public class PlanAdapter extends RecyclerView.Adapter<RecyclerView.ViewHolder> {
    public interface OnItemClickListener {
        void onItemClick(Plan plan);
    }

    private OnItemClickListener onItemClickListener;

    public void setOnItemClickListener(OnItemClickListener listener) {
        this.onItemClickListener = listener;
    }

    private ArrayList<Plan> planList;
    private Context planContext;

    public static class PlanViewHolder extends RecyclerView.ViewHolder {

        TextView employeeUsername, travelDate, endLocation, accountantUsername;

        public PlanViewHolder(View view) {
            super(view);

            this.employeeUsername = view.findViewById(R.id.plan_tv_employeeUsername);
            this.travelDate = view.findViewById(R.id.plan_tv_travelDate);
            this.endLocation = view.findViewById(R.id.plan_tv_endLocation);
        }
    }

    public PlanAdapter(ArrayList<Plan> dataSet, Context context) {
        this.planList = dataSet;
        this.planContext = context;
    }


    public RecyclerView.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view;

        view = LayoutInflater.from(parent.getContext()).inflate(R.layout.plan_card, parent, false);
        return new PlanViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull RecyclerView.ViewHolder holder, int position) {
        Plan plan = planList.get(position);

        if (plan != null) {
            ((PlanViewHolder) holder).employeeUsername.setText("Username: " + plan.getEmployeeUsername());
            ((PlanViewHolder) holder).travelDate.setText("Travel Date: " + plan.getTravelDate());
            ((PlanViewHolder) holder).endLocation.setText("End Location: " + plan.getEndLocation());

            holder.itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    if (onItemClickListener != null) {
                        onItemClickListener.onItemClick(plan);
                    }
                }
            });
        }
    }

    public void updateData(ArrayList<Plan> newPlanList) {
        planList.clear();
        planList.addAll(newPlanList);
        notifyDataSetChanged();
    }

    @Override
    public int getItemCount() {
        return planList.size();
    }
}
