package com.example.blm3520_hw1;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.drawable.BitmapDrawable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Filter;
import android.widget.Filterable;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.io.ByteArrayOutputStream;
import java.util.ArrayList;

public class RecycleAdapter extends RecyclerView.Adapter<RecycleHolder> implements Filterable {

    Context c;
    ArrayList<User> userList, filterList;
    UserFilter filter;

    public RecycleAdapter(Context c, ArrayList<User> userList) {
        this.c = c;
        this.userList = userList;
        this.filterList = userList;
    }

    @NonNull
    @Override
    public RecycleHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.row, null);
        return new RecycleHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull final RecycleHolder holder, int position) {
        holder.mName.setText(userList.get(position).getName());
        holder.mDescription.setText(userList.get(position).getDescription());
//        holder.mImageView.setImageResource(userList.get(position).getImage());
        holder.mImageView.setImageResource(c.getResources().getIdentifier(
                userList.get(position).getImage(), "drawable", "com.example.blm3520_hw1"));



        holder.setItemClickListener(new ItemClickListener() {
            @Override
            public void onItemClickListener(View view, int position) {

                int id = userList.get(position).getId();
                String name = userList.get(position).getName();
                String description = userList.get(position).getDescription();
                BitmapDrawable bitmapDrawable = (BitmapDrawable)holder.mImageView.getDrawable();

                Bitmap bitmap = bitmapDrawable.getBitmap();

                ByteArrayOutputStream stream = new ByteArrayOutputStream();

                bitmap.compress(Bitmap.CompressFormat.PNG, 100,stream);

                byte[] bytes = stream.toByteArray();

                Intent intent = new Intent(c, UserDetail.class);
                intent.putExtra("iID", id);
                intent.putExtra("iName", name);
                intent.putExtra("iDescription", description);
                intent.putExtra("iImage", bytes);
                c.startActivity(intent);

            }
        });

    }

    @Override
    public int getItemCount() {
        return userList.size();
    }

    @Override
    public Filter getFilter() {
        if (filter == null) {
            filter = new UserFilter(filterList, this);
        }
        return filter;
    }
}
