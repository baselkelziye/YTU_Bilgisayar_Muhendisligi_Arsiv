package mobil.prog.music_app;

import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class MusicListAdapter extends RecyclerView.Adapter<MusicListAdapter.ViewHolder> {

    ArrayList<AudioModel> songsList;
    Context context;

    public MusicListAdapter(ArrayList<AudioModel> songsList, Context context) {
        this.songsList = songsList;
        this.context = context;
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.item_view, parent, false);
        return new MusicListAdapter.ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(ViewHolder holder, int index) {
        AudioModel songData = songsList.get(index);
        holder.titleText.setText(songData.getTitle());

        int minutes = Integer.parseInt(songData.getDuration())/60000;
        int seconds = (Integer.parseInt(songData.getDuration())%60000)/1000;
        if(seconds<10){
            String template = "0" + seconds;
            holder.durationText.setText(minutes + ":" + template);
        }
        else
            holder.durationText.setText(minutes + ":" + seconds);

        holder.itemView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                MyMediaPlayer.getInstance().reset();
                MyMediaPlayer.activeIndex = index;

                Intent intent = new Intent(context, MusicActivity.class);
                intent.putExtra("LIST", songsList);
                intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                context.startActivity(intent);
            }
        });

    }

    @Override
    public int getItemCount() {
        return songsList.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder{

        TextView titleText;
        ImageView iconImage;

        //yeni
        TextView durationText;

        public ViewHolder(View itemView) {
            super(itemView);
            //-------------------------------
            titleText = itemView.findViewById(R.id.music_title);
            iconImage = itemView.findViewById(R.id.icon_view);

            //yeni
            durationText = itemView.findViewById(R.id.music_duration);
        }
    }

}
