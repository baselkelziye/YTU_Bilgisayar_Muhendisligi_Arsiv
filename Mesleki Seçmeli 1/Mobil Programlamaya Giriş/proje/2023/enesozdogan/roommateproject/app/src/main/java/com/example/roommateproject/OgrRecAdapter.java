package com.example.roommateproject;

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

public class OgrRecAdapter extends RecyclerView.Adapter<OgrRecAdapter.ViewHolder> {

    private Context context;
    private List<User> userModelList;

    public OgrRecAdapter(Context context, List<User> userModelList) {
        this.context = context;
        this.userModelList = userModelList;
    }

    @NonNull
    @Override
    public OgrRecAdapter.ViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int i) {
        View view= LayoutInflater.from(context)
                .inflate(R.layout.card_item,viewGroup,false);
        return new ViewHolder(view,context);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        User user=userModelList.get(position);
        String imgUrl;
        holder.name.setText(user.getUsername());
        holder.distance.setText(user.getDistance());

        if(user.getImageURL().equals("default")){
            holder.img.setImageResource(R.mipmap.ic_launcher);
        }
        else{
            Glide.with(context).load(user.getImageURL()).into(holder.img);
        }
        holder.itemView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i=new Intent(context,OgrDetay.class);
                i.putExtra("userID",user.getId());
                context.startActivity(i);
            }
        });
    }


    @Override
    public int getItemCount() {
        return userModelList.size();
    }
    public void OgrFiltrele(ArrayList<User> mezunfiltreliList){
        userModelList=mezunfiltreliList;
        notifyDataSetChanged();
    }
    public class ViewHolder extends RecyclerView.ViewHolder{
        public TextView distance,name;
        public ImageView img;
        String userName;

        public ViewHolder(@NonNull View itemView,Context cntx) {
            super(itemView);
            context=cntx;
            distance=itemView.findViewById(R.id.CardDistance);


            img=itemView.findViewById(R.id.cardviewImg);
            name=itemView.findViewById(R.id.cardName);
        }
    }


}
