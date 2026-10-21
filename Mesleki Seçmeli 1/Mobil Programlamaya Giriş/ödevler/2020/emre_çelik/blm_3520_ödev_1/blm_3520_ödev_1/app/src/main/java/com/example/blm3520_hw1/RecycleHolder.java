package com.example.blm3520_hw1;

import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

public class RecycleHolder extends RecyclerView.ViewHolder implements View.OnClickListener {

    ImageView mImageView;
    TextView mName, mDescription;
    ItemClickListener itemClickListener;

    RecycleHolder(@NonNull View itemView) {
        super(itemView);

        this.mImageView = itemView.findViewById(R.id.profileImageView);
        this.mName = itemView.findViewById(R.id.nameText);
        this.mDescription = itemView.findViewById(R.id.descriptionText);

        itemView.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        this.itemClickListener.onItemClickListener(v, getLayoutPosition());
    }

    public void setItemClickListener(ItemClickListener listener) {
        this.itemClickListener = listener;
    }

}
