package com.barissemerci.sanaldolabim;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class KombinleriGorAdapter extends RecyclerView.Adapter<KombinleriGorAdapter.PostHolder> {
private ArrayList<Kombin> kombinler;
private RecyclerViewClickListener recyclerViewClickListener;
    public KombinleriGorAdapter(ArrayList<Kombin> kombinler,RecyclerViewClickListener recyclerViewClickListener) {
        this.kombinler = kombinler;
        this.recyclerViewClickListener=recyclerViewClickListener;
    }

    class PostHolder extends RecyclerView.ViewHolder implements View.OnClickListener{
TextView textViewKombinIsmi;
    public PostHolder(@NonNull View itemView) {
        super(itemView);
        textViewKombinIsmi=itemView.findViewById(R.id.textViewKombinAdi);

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
        View view=layoutInflater.inflate(R.layout.recycler_view_row_kombin_paylas,parent,false);
    return new PostHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull PostHolder holder, int position) {
holder.textViewKombinIsmi.setText(kombinler.get(position).getIsim());
    }

    @Override
    public int getItemCount() {
        return kombinler.size();
    }
    public interface RecyclerViewClickListener{
        void onClick(View v,int position);
    }
}
