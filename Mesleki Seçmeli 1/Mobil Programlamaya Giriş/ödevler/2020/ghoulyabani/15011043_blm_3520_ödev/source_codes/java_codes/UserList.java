package com.example.classapp;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.widget.Toast;

public class UserList extends AppCompatActivity {
    private RecyclerView recyclerView;
    //private RecyclerView.Adapter mAdapter;
    private RecyclerView.LayoutManager layoutManager;

    String[] userId, userPw;
    int length;
    String name;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_user_list);

        recyclerView = (RecyclerView) findViewById(R.id.rcyUser);

        userId = getResources().getStringArray(R.array.Users);
        userPw = getResources().getStringArray(R.array.Passwords);

        length = userId.length;

        int[] images = new int[length];

        for (int i = 0; i < length; i++){
            name = userId[i];
            name = name.toLowerCase();//+".jpg";
            images[i] = getResources().getIdentifier(name, "drawable", getPackageName());
        }

        MyAdapter myAdapter = new MyAdapter(this, userId, userPw, images);
        recyclerView.setAdapter(myAdapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
    }
}
