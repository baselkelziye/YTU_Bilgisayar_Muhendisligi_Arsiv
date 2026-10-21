package com.example.sefagokceoglu;

import android.content.Context;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.TextView;

import androidx.recyclerview.widget.RecyclerView;

import com.example.sefagokceoglu.model.AudioModel;
import com.example.sefagokceoglu.model.Playlist;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class CreatePlayListAdapter extends RecyclerView.Adapter<CreatePlayListAdapter.ViewHolder>{

    ArrayList<AudioModel> songsList;
    Context context;

    Set<AudioModel> selectedSongs = new HashSet<>();

    public CreatePlayListAdapter(ArrayList<AudioModel> songsList, Context context) {
        this.songsList = songsList;
        this.context = context;
    }

    @Override
    public ViewHolder onCreateViewHolder( ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.create_playlist_item,parent,false);
        return new CreatePlayListAdapter.ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(CreatePlayListAdapter.ViewHolder holder, int position) {
        AudioModel songData = songsList.get(position);
        holder.titleTextView.setText(songData.getTitle());
        holder.itemView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d("asd","asds");

                Log.d("asda",selectedSongs.toString());
                //navigate to another acitivty
                /*
                MyMediaPlayer.getInstance().reset();
                MyMediaPlayer.currentIndex = position;
                Intent intent = new Intent(context,MusicPlayerActivity.class);
                intent.putExtra("LIST",songsList);
                intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                context.startActivity(intent);
                */
                if(selectedSongs.contains(songData) ) {
                    selectedSongs.remove(songData);
                    holder.checkBox.setChecked(false);
                }else {
                    selectedSongs.add(songData);
                    holder.checkBox.setChecked(true);
                }

                Playlist.selectedSongs = selectedSongs;



            }
        });


    }

    @Override
    public int getItemCount() {
        return songsList.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder{

        TextView titleTextView;
        CheckBox checkBox;
        public ViewHolder(View itemView) {
            super(itemView);
            titleTextView = itemView.findViewById(R.id.textView2);
            checkBox = itemView.findViewById(R.id.checkBox);
        }
    }
}
