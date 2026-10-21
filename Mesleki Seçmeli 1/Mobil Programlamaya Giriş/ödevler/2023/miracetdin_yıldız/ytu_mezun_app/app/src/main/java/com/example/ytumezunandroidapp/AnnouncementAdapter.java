package com.example.ytumezunandroidapp;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class AnnouncementAdapter extends RecyclerView.Adapter<RecyclerView.ViewHolder> {

    public ArrayList<AnnouncementModel> announcementList;
    public Context announcementContext;

    public static class AnnouncementViewHolder extends RecyclerView.ViewHolder {

        ImageView image;
        TextView header, text, date, user;

        public AnnouncementViewHolder(View view) {
            super(view);

            // Her duyuru; görsel, başlık ve tarih içermektedir
            this.image = (ImageView) view.findViewById(R.id.announce_iv_announce);
            this.header = (TextView) view.findViewById(R.id.announce_tv_head);
            this.text = (TextView) view.findViewById(R.id.announce_tv_text);
            this.date = (TextView) view.findViewById(R.id.announce_tv_date);
            this.user = (TextView) view.findViewById(R.id.announce_tv_user);
        }
    }

    public AnnouncementAdapter(ArrayList<AnnouncementModel> dataSet, Context context) {
        this.announcementList = dataSet;
        this.announcementContext = context;
    }

    public RecyclerView.ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view;

        view = LayoutInflater.from(parent.getContext()).inflate(R.layout.announcement, parent, false);
        return new AnnouncementViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull RecyclerView.ViewHolder holder, int position) {
        AnnouncementModel announcement = announcementList.get(position);

        if(announcement != null) {
            ((AnnouncementViewHolder) holder).image.setImageResource(announcement.image);
            ((AnnouncementViewHolder) holder).header.setText(announcement.header);
            ((AnnouncementViewHolder) holder).text.setText(announcement.text);
            ((AnnouncementViewHolder) holder).date.setText(announcement.date);
            ((AnnouncementViewHolder) holder).user.setText(announcement.user);
        }
    }

    public int getItemCount() { return announcementList.size(); }
}