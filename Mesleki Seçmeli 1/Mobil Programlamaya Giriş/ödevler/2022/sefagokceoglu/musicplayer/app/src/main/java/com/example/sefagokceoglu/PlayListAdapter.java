package com.example.sefagokceoglu;

import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.recyclerview.widget.RecyclerView;

import com.example.sefagokceoglu.model.MyPlayList;

import java.io.Serializable;
import java.util.ArrayList;

public class PlayListAdapter extends RecyclerView.Adapter<PlayListAdapter.ViewHolder>{

    ArrayList<MyPlayList> playLists;
    Context context;

    public PlayListAdapter(ArrayList<MyPlayList> playLists, Context context) {
        this.playLists = playLists;
        this.context = context;
    }

    @Override
    public ViewHolder onCreateViewHolder( ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.playlist_item,parent,false);
        return new PlayListAdapter.ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(PlayListAdapter.ViewHolder holder, int position) {
        MyPlayList playlistData = playLists.get(position);
        holder.titleTextView.setText("Playlist Name:"+playlistData.getPlaylistName());
        holder.songCount.setText("Song Count:" +String.valueOf(playlistData.getSongs().size()));

        holder.itemView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //navigate to another acitivty
                Log.d("asdas","asdasa");
                Intent intent = new Intent(context,MainActivity.class);
                intent.putExtra("playlistSongs",(Serializable) playlistData.getSongs());
                intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                context.startActivity(intent);
            }
        });

    }

    @Override
    public int getItemCount() {
        return playLists.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder{

        TextView titleTextView;
        TextView songCount;
        public ViewHolder(View itemView) {
            super(itemView);
            titleTextView = itemView.findViewById(R.id.playlist_title);
            songCount = itemView.findViewById(R.id.playlist_song_count);
        }
    }
}
