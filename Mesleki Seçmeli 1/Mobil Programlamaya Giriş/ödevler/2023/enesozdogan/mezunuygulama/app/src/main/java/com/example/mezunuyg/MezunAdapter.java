package com.example.mezunuyg;

import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.bumptech.glide.Glide;

import java.util.ArrayList;
import java.util.List;

public class MezunAdapter extends RecyclerView.Adapter<MezunAdapter.ViewHolder> {
    private Context context;
    private List<User> mezunList;

    public MezunAdapter(Context context,List<User> mezunList){
        this.context=context;
        this.mezunList=mezunList;
    }


    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view= LayoutInflater.from(context).inflate(R.layout.user_item,
                parent,
                false);
        return new MezunAdapter.ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
          User user=mezunList.get(position);

          holder.userName.setText(user.getUsername());
          if(user.getYear()==null || user.getYear().equals(" ")){
              holder.userYear.setText("2021");
          }
          else{
              holder.userYear.setText(user.getYear());
          }
          if(user.getImageURL().equals("default")){
              holder.imgView.setImageResource(R.mipmap.ic_launcher);
          }
          else{
              Glide.with(context).load(user.getImageURL()).into(holder.imgView);
          }
          holder.itemView.setOnClickListener(new View.OnClickListener() {
              @Override
              public void onClick(View v) {
                  Intent i=new Intent(context,MezunDetay.class);
                  i.putExtra("userID",user.getId());
                  context.startActivity(i);
              }
          });
    }

    @Override
    public int getItemCount() {
        return  mezunList.size();
    }
    public void mezunFiltrele(ArrayList<User> mezunfiltreliList){
        mezunList=mezunfiltreliList;
        notifyDataSetChanged();
    }
    public class ViewHolder extends RecyclerView.ViewHolder{
        public TextView userName;
        public TextView userYear;
        public ImageView imgView;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            userName=itemView.findViewById(R.id.usrItemName);
            userYear=itemView.findViewById(R.id.usrItemYear);
            imgView=itemView.findViewById(R.id.usrItemImgView);
        }
    }
}
