package com.barissemerci.sanaldolabim;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class CekmeceleriGorAdapter extends RecyclerView.Adapter<CekmeceleriGorAdapter.PostHolder> {
    private ArrayList<Cekmece> cekmeceArrayList;
    private RecyclerViewClickListener recyclerViewClickListener;
    public CekmeceleriGorAdapter(ArrayList<Cekmece> cekmeceArrayList,RecyclerViewClickListener recyclerViewClickListener) {
        this.cekmeceArrayList = cekmeceArrayList;
this.recyclerViewClickListener= recyclerViewClickListener;
    }

    @NonNull
    @Override
    public PostHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        LayoutInflater layoutInflater= LayoutInflater.from(parent.getContext());
        View view= layoutInflater.inflate(R.layout.cekmeceleri_gor_row,parent,false);
        return new PostHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull PostHolder holder, int position) {
        holder.textViewCekmeceleriGorRow.setText(cekmeceArrayList.get(position).getIsim());



    }

    @Override
    public int getItemCount() {
        return cekmeceArrayList.size();
    }
    public interface RecyclerViewClickListener{
        void onClick(View v,int position);
    }
    class PostHolder extends RecyclerView.ViewHolder implements View.OnClickListener{
        TextView textViewCekmeceleriGorRow;
        public PostHolder(@NonNull View itemView) {
            super(itemView);
            textViewCekmeceleriGorRow=itemView.findViewById(R.id.textViewCekmeceleriGorRow);
            itemView.setOnClickListener(this);
        }

        @Override
        public void onClick(View v) {
recyclerViewClickListener.onClick(v,getAdapterPosition());
        }
    }
}
