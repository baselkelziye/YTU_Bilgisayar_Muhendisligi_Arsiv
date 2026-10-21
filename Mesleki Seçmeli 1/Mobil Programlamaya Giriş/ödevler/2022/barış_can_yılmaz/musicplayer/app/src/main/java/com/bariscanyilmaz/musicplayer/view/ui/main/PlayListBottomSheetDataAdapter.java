package com.bariscanyilmaz.musicplayer.view.ui.main;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.RecyclerView;

import com.bariscanyilmaz.musicplayer.R;
import com.bariscanyilmaz.musicplayer.model.PlaySong;
import com.bariscanyilmaz.musicplayer.model.Song;
import com.bariscanyilmaz.musicplayer.utils.TimeConverter;

import java.util.List;

public class PlayListBottomSheetDataAdapter extends RecyclerView.Adapter<PlayListBottomSheetDataAdapter.ViewHolder> {


    private List<Song> songs;
    private int index;
    private OnItemClickListener<PlaySong>  playSongListener;
    public interface OnItemClickListener<T> {
        void onItemClick(T data);
    }

    public PlayListBottomSheetDataAdapter(
            List<Song> songs,
            OnItemClickListener<PlaySong> playSongListener
    ){
        this.songs=songs;
        this.playSongListener=playSongListener;
    }
    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        Context context= parent.getContext();
        LayoutInflater inflater=LayoutInflater.from(context);

        View dataView=inflater.inflate(R.layout.bottom_sheet_item,parent,false);
        PlayListBottomSheetDataAdapter.ViewHolder viewHolder=new PlayListBottomSheetDataAdapter.ViewHolder(dataView);

        return viewHolder;
    }


    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        Song song= songs.get(position);
        holder.name.setText(song.name);
        holder.duration.setText(TimeConverter.convertToMMSS(song.duration));

        holder.constraintLayout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                playSongListener.onItemClick(new PlaySong(holder.getAdapterPosition(),songs));
            }
        });

    }

    @Override
    public int getItemCount() {
        return songs.size();
    }

    public static class ViewHolder extends RecyclerView.ViewHolder{

        public TextView name;
        public TextView duration;
        public ConstraintLayout constraintLayout;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            name=itemView.findViewById(R.id.bottomSheetItemName);
            duration=itemView.findViewById(R.id.bottomSheetItemDuration);
            constraintLayout=itemView.findViewById(R.id.bottomSheetItemLayout);

        }
    }

}
