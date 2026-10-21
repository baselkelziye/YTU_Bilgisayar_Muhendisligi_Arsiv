package com.example.classapp;

import android.content.Context;
import android.graphics.drawable.Drawable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

public class MyAdapter extends RecyclerView.Adapter<MyAdapter.MyViewHolder> {

    String[] uId, uPw;
    int[] img;
    Context context;

    public MyAdapter(Context ct, String[] userId, String[] userPw, int[] images){
        context = ct;
        img = images;
        uId = userId;
        uPw = userPw;
    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(context);
        View v = inflater.inflate(R.layout.my_row, parent, false);
        return new MyViewHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {
        holder.txtNameVal.setText(uId[position]);
        holder.txtPwVal.setText(uPw[position]);
        holder.imgPerson.setImageResource(img[position]);
    }

    @Override
    public int getItemCount() {
        return uId.length;
    }

    public class MyViewHolder extends RecyclerView.ViewHolder{

        TextView txtName, txtNameVal, txtPw, txtPwVal;
        ImageView imgPerson;

        public MyViewHolder(@NonNull View itemView) {
            super(itemView);
            txtName = itemView.findViewById(R.id.txtName);
            txtNameVal = itemView.findViewById(R.id.txtNameVal);
            txtPw = itemView.findViewById(R.id.txtPw);
            txtPwVal = itemView.findViewById(R.id.txtPwVal);
            imgPerson = itemView.findViewById(R.id.imgPerson);
        }
    }
}
