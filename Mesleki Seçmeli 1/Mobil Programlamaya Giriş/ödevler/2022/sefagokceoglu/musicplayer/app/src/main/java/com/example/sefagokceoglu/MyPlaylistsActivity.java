package com.example.sefagokceoglu;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.example.sefagokceoglu.model.AudioModel;
import com.example.sefagokceoglu.model.MyPlayList;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.ArrayList;

public class MyPlaylistsActivity extends AppCompatActivity {

    ArrayList<MyPlayList> myPlayLists;
    ArrayList<AudioModel> songsList;

    TextView noPlaylistTextView;

    RecyclerView recyclerView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_my_playlists);

        songsList = (ArrayList<AudioModel>) getIntent().getSerializableExtra("LIST");

        noPlaylistTextView = findViewById(R.id.no_playlists_text);
        recyclerView = findViewById(R.id.playlist_recycler_view);
        Gson gson = new Gson();
        SharedPreferences sharedPref = getApplicationContext().getSharedPreferences("SharedPrefs", Context.MODE_PRIVATE);
        String jsonPreferences = sharedPref.getString("PlayLists", "");

        Type type = new TypeToken<ArrayList<MyPlayList>>() {}.getType();
        myPlayLists = gson.fromJson(jsonPreferences, type);


        if(myPlayLists == null || myPlayLists.size()==0){
            noPlaylistTextView.setVisibility(View.VISIBLE);
        }else{
            //recyclerview
            recyclerView.setLayoutManager(new LinearLayoutManager(this));
            recyclerView.setAdapter(new PlayListAdapter(myPlayLists,getApplicationContext()));
        }
    }
}