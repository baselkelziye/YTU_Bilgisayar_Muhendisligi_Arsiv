package com.bariscanyilmaz.musicplayer.view.ui.main;

import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.PopupMenu;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.RecyclerView;

import com.bariscanyilmaz.musicplayer.R;
import com.bariscanyilmaz.musicplayer.model.PlaySong;
import com.bariscanyilmaz.musicplayer.model.Song;

import java.util.ArrayList;
import java.util.List;

public class SongDataAdapter extends RecyclerView.Adapter<SongDataAdapter.ViewHolder> {

    public interface OnItemClickListener<T> {
        void onItemClick(T data);
    }

    private final OnItemClickListener<PlaySong> playButtonOnClickListener;
    private final OnItemClickListener<Song> shareButtonOnClickListener;
    private final OnItemClickListener<Song> deleteButtonOnClickListener;
    private final OnItemClickListener<Song> addToPlayListButtonOnClickListener;


    private List<Song> songs;
    private Song song;

    public  SongDataAdapter(
            OnItemClickListener<PlaySong> playButtonOnClickListener,
            OnItemClickListener<Song> shareButtonOnClickListener,
            OnItemClickListener<Song> deleteButtonOnClickListener,
            OnItemClickListener<Song> addToPlayListButtonOnClickListener
    ){
        this.songs=new ArrayList<>();
        this.playButtonOnClickListener =playButtonOnClickListener;
        this.shareButtonOnClickListener=shareButtonOnClickListener;
        this.deleteButtonOnClickListener=deleteButtonOnClickListener;
        this.addToPlayListButtonOnClickListener=addToPlayListButtonOnClickListener;
    }
    public void setSongs(List<Song> songs)
    {
        this.songs=songs;
        Log.v("Song","RecyclerView update data");
        notifyDataSetChanged();

    }

    @NonNull
    @Override
    public SongDataAdapter.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        Context context= parent.getContext();
        LayoutInflater inflater=LayoutInflater.from(context);

        View dataView=inflater.inflate(R.layout.song_item,parent,false);
        ViewHolder viewHolder=new ViewHolder(dataView);


        return viewHolder;

    }


    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        song=songs.get(position);
        holder.songName.setText(song.name);
        holder.songArtistName.setText(song.artist);
        holder.songIcon.setImageResource(R.drawable.ic_baseline_music_note);
        holder.playButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                playButtonOnClickListener.onItemClick(new PlaySong(holder.getAdapterPosition(),songs));
            }
        });

        holder.moreButton.setOnClickListener( new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                song=songs.get(holder.getAdapterPosition());

                PopupMenu menu =new PopupMenu(view.getContext(), view);
                menu.getMenuInflater().inflate(R.menu.song_item_menu,menu.getMenu());

                menu.setOnMenuItemClickListener(menuItemClickListener);
                menu.show();
            }
        });
    }

    private PopupMenu.OnMenuItemClickListener menuItemClickListener=new PopupMenu.OnMenuItemClickListener() {
        @Override
        public boolean onMenuItemClick(MenuItem menuItem) {
            switch (menuItem.getItemId()){
                case R.id.song_item_delete:

                    deleteButtonOnClickListener.onItemClick(song);
                    return true;
                case R.id.song_item_share:

                    shareButtonOnClickListener.onItemClick(song);

                    return true;

                case R.id.song_item_add_list:
                     //add to list
                    addToPlayListButtonOnClickListener.onItemClick(song);
                    return true;

                default:
                    return false;
            }
        }
    };

    @Override
    public int getItemCount() {
        return songs.size();
    }

    public static class ViewHolder extends RecyclerView.ViewHolder{

        public TextView songName;
        public TextView songArtistName;
        public ConstraintLayout songItemLayout;
        public ImageView songIcon;
        public ImageButton playButton;

        public ImageButton moreButton;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);

            songName=(TextView) itemView.findViewById(R.id.songItemName);
            songArtistName=(TextView) itemView.findViewById(R.id.songItemArtistName);
            songIcon=(ImageView) itemView.findViewById(R.id.songItemIcon);
            songItemLayout=(ConstraintLayout) itemView.findViewById(R.id.songItemLayout);

            playButton=(ImageButton) itemView.findViewById(R.id.songItemPlayButon);
            moreButton=(ImageButton) itemView.findViewById(R.id.songItemMoreButton);

        }
    }

}
