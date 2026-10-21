package com.barissemerci.sanaldolabim;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class EtkinlikleriGorAdapter  extends RecyclerView.Adapter<EtkinlikleriGorAdapter.PostHolder> {
    private ArrayList<Etkinlik> etkinlikler;
    private RecyclerViewClickListener recyclerViewClickListener;
    public EtkinlikleriGorAdapter(ArrayList<Etkinlik> etkinlikler, RecyclerViewClickListener recyclerViewClickListener) {
        this.etkinlikler = etkinlikler;
        this.recyclerViewClickListener=recyclerViewClickListener;
    }

    class PostHolder extends RecyclerView.ViewHolder implements View.OnClickListener{
        TextView textViewEtkinlikAdiRow;
        public PostHolder(@NonNull View itemView) {
            super(itemView);
            textViewEtkinlikAdiRow=itemView.findViewById(R.id.textViewEtkinlikAdiRow);

            itemView.setOnClickListener(this);

        }

        @Override
        public void onClick(View v) {
            recyclerViewClickListener.onClick(itemView,getAdapterPosition());
        }
    }
    @NonNull
    @Override
    public PostHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        LayoutInflater layoutInflater= LayoutInflater.from(parent.getContext());
        View view=layoutInflater.inflate(R.layout.etkinlik_row,parent,false);
        return new PostHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull PostHolder holder, int position) {
        holder.textViewEtkinlikAdiRow.setText(etkinlikler.get(position).getIsim());
    }

    @Override
    public int getItemCount() {
        return etkinlikler.size();
    }
    public interface RecyclerViewClickListener{
        void onClick(View v,int position);
    }
}






