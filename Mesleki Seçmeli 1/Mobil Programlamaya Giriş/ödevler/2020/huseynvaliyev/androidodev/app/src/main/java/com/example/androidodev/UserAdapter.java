package com.example.androidodev;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

import androidx.recyclerview.widget.RecyclerView;


public class UserAdapter extends RecyclerView.Adapter<UserAdapter.MyViewHolder> {

    ArrayList<User> mUserList;
    LayoutInflater inflater;

    


    public UserAdapter(Context context, ArrayList<User> users) {
        inflater = LayoutInflater.from(context);
        this.mUserList = users;
    }


    @Override
    public MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = inflater.inflate(R.layout.item_user_card, parent, false);
        MyViewHolder holder = new MyViewHolder(view);
        return holder;
    }

    @Override
    public void onBindViewHolder(MyViewHolder holder, int position) {
        User selectedUser = mUserList.get(position);
        holder.setData(selectedUser, position);

    }

    @Override
    public int getItemCount() {
        return mUserList.size();
    }


    class MyViewHolder extends RecyclerView.ViewHolder  {

        TextView userName;
        EditText userPassword;
        ImageView userImage;

        public MyViewHolder(View itemView) {
            super(itemView);
            userName = (TextView) itemView.findViewById(R.id.userName);
            userPassword = (EditText) itemView.findViewById(R.id.userPassword);
            userImage = (ImageView) itemView.findViewById(R.id.userImage);
        }

        public void setData(User selectedUser, int position) {

            this.userName.setText(selectedUser.getUsername());
            this.userPassword.setText(selectedUser.getPassword());
            this.userImage.setImageResource(selectedUser.getImageID());
        }


    }
}
