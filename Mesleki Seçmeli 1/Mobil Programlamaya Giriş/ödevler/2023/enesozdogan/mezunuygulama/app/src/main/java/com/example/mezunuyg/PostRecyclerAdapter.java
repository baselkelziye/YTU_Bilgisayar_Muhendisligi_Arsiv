package com.example.mezunuyg;

import android.content.Context;
import android.text.format.DateUtils;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.bumptech.glide.Glide;

import java.util.List;

public class PostRecyclerAdapter extends RecyclerView.Adapter<PostRecyclerAdapter.ViewHolder> {

    private Context context;
    private List<PostModel> postModelList;

    public PostRecyclerAdapter(Context context, List<PostModel> postModelList) {
        this.context = context;
        this.postModelList = postModelList;
    }

    @NonNull
    @Override
    public PostRecyclerAdapter.ViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int i) {
        View view= LayoutInflater.from(context)
                .inflate(R.layout.post_item,viewGroup,false);
        return new ViewHolder(view,context);
    }

    @Override
    public void onBindViewHolder(@NonNull PostRecyclerAdapter.ViewHolder holder, int position) {
            PostModel postModel=postModelList.get(position);
            String imgUrl;
            holder.title.setText(postModel.getTitle());
            holder.duyuru.setText(postModel.getDuyuru());
            holder.name.setText(postModel.getUserName());
            imgUrl=postModel.getImgUrl();

            Glide.with(context)
                    .load(imgUrl)
                    .fitCenter()
                    .into(holder.img);
    }

    @Override
    public int getItemCount() {
        return postModelList.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder{
        public TextView title,duyuru,name;
        public ImageView img;
        String userName;

        public ViewHolder(@NonNull View itemView,Context cntx) {
            super(itemView);
            context=cntx;
            title=itemView.findViewById(R.id.postTitleItem);
            duyuru=itemView.findViewById(R.id.postDuyuruItem);

            img=itemView.findViewById(R.id.postImgItem);
            name=itemView.findViewById(R.id.postUserNameItem);
        }
    }
}
