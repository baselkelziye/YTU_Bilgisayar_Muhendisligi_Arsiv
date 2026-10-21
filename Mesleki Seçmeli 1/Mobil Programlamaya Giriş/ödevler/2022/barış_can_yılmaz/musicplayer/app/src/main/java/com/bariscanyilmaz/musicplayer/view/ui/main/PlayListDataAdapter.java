package com.bariscanyilmaz.musicplayer.view.ui.main;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.RecyclerView;

import com.bariscanyilmaz.musicplayer.R;
import com.bariscanyilmaz.musicplayer.model.PlayList;

import org.w3c.dom.Text;

import java.util.ArrayList;
import java.util.List;

public class PlayListDataAdapter extends RecyclerView.Adapter<PlayListDataAdapter.ViewHolder>  {

    private List<PlayList> playLists;

    private Context context;

    private OnItemClickListener<PlayList> playListOnLongItemClickListener;
    public PlayListDataAdapter(
            Context context,
             OnItemClickListener<PlayList> playListOnLongItemClickListener){

        this.playListOnLongItemClickListener=playListOnLongItemClickListener;
        this.context=context;
        this.playLists=new ArrayList<>();

    }

    public interface OnItemClickListener<T> {
        void onItemClick(T data);
    }

    public void setPlayLists(List<PlayList> playLists){

        this.playLists=playLists;
        notifyDataSetChanged();
    }


    @NonNull
    @Override
    public PlayListDataAdapter.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        Context context= parent.getContext();
        LayoutInflater inflater=LayoutInflater.from(context);

        View dataView=inflater.inflate(R.layout.play_list_item,parent,false);
        PlayListDataAdapter.ViewHolder viewHolder=new ViewHolder(dataView);

        return viewHolder;
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        PlayList playList=playLists.get(position);

        holder.playListName.setText(playList.name);

        holder.playListLayout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                PlayListBottomSheetDialogFragment dialogFragment=new PlayListBottomSheetDialogFragment(playList);
                dialogFragment.show(((AppCompatActivity)context).getSupportFragmentManager(),dialogFragment.getTag());

            }
        });

        holder.playListLayout.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View view) {


                playListOnLongItemClickListener.onItemClick(playList);
                return true;
            }
        });

    }

    @Override
    public int getItemCount() {
        if (playLists==null) return 0;

        return playLists.size();
    }

    public static class ViewHolder extends RecyclerView.ViewHolder{

        public ConstraintLayout playListLayout;
        public TextView playListName;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);

            playListLayout=itemView.findViewById(R.id.playListItemLayout);
            playListName=itemView.findViewById(R.id.playListItemName);

        }
    }

}
