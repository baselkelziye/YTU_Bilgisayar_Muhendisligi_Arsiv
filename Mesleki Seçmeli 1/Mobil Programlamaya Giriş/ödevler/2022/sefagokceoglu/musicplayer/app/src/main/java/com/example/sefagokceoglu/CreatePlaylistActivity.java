package com.example.sefagokceoglu;

import android.Manifest;
import android.content.Context;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.example.sefagokceoglu.model.AudioModel;
import com.example.sefagokceoglu.model.MyPlayList;
import com.example.sefagokceoglu.model.Playlist;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.io.File;
import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.List;

public class CreatePlaylistActivity extends AppCompatActivity {

    RecyclerView recyclerView;
    ArrayList<AudioModel> songsList = new ArrayList<>();

    Button createPLButton;
    Button backButton;
    EditText playlistNameEditText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.create_playlist);

        recyclerView = findViewById(R.id.recycler_view_create);
        createPLButton = findViewById(R.id.createPL);
        backButton = findViewById(R.id.buttonBack);
        playlistNameEditText = findViewById(R.id.editTextPlayListName);

        loadPage();

    }

    boolean checkPermission(){
        int result = ContextCompat.checkSelfPermission(CreatePlaylistActivity.this, Manifest.permission.READ_EXTERNAL_STORAGE);
        if(result == PackageManager.PERMISSION_GRANTED){
            return true;
        }else{
            return false;
        }
    }

    void loadPage() {
        recyclerView = findViewById(R.id.recycler_view_create);

        if(checkPermission() == false){
            requestPermission();
            return;
        }

        String[] projection = {
                MediaStore.Audio.Media.TITLE,
                MediaStore.Audio.Media.DATA,
                MediaStore.Audio.Media.DURATION
        };

        String selection = MediaStore.Audio.Media.IS_MUSIC +" != 0";

        Cursor cursor = getContentResolver().query(MediaStore.Audio.Media.EXTERNAL_CONTENT_URI,projection,selection,null,"TITLE ASC");
        while(cursor.moveToNext()){
            AudioModel songData = new AudioModel(cursor.getString(1),cursor.getString(0),cursor.getString(2));
            if(new File(songData.getPath()).exists())
                songsList.add(songData);
        }

        if(songsList.size()==0){

            Toast.makeText(CreatePlaylistActivity.this,"There is No Music !",Toast.LENGTH_SHORT).show();

        }else{
            //recyclerview
            recyclerView.setLayoutManager(new LinearLayoutManager(this));
            recyclerView.setAdapter(new CreatePlayListAdapter(songsList,getApplicationContext()));
        }

        backButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Playlist.reset();
                finish();
            }
        });

        createPLButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(playlistNameEditText.getText().toString().isEmpty()) {
                    Toast.makeText(CreatePlaylistActivity.this,"Please enter playlist name !",Toast.LENGTH_SHORT).show();
                    return;
                }
                if(Playlist.selectedSongs.isEmpty()) {
                    Toast.makeText(CreatePlaylistActivity.this,"You didn't choose any song !",Toast.LENGTH_SHORT).show();
                    return;
                }else {
                    Gson gson = new Gson();
                    SharedPreferences sharedPref = getApplicationContext().getSharedPreferences("SharedPrefs", Context.MODE_PRIVATE);
                    String jsonPreferences = sharedPref.getString("PlayLists", "");

                    Type type = new TypeToken<List<MyPlayList>>() {
                    }.getType();
                    ArrayList<MyPlayList> myPlayLists = gson.fromJson(jsonPreferences, type);
                    if(myPlayLists == null) {
                        myPlayLists = new ArrayList<>();
                    }
                    myPlayLists.add(new MyPlayList(playlistNameEditText.getText().toString(), Playlist.selectedSongs));
                    String jsonMyPlayLists = gson.toJson(myPlayLists);
                    SharedPreferences.Editor editor = sharedPref.edit();
                    editor.putString("PlayLists", jsonMyPlayLists);
                    editor.commit();
                    Playlist.reset();
                    Toast.makeText(CreatePlaylistActivity.this, "Playlist saved !", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    void requestPermission(){
        if(ActivityCompat.shouldShowRequestPermissionRationale(CreatePlaylistActivity.this,Manifest.permission.READ_EXTERNAL_STORAGE)){
            Toast.makeText(CreatePlaylistActivity.this,"READ PERMISSION IS REQUIRED,PLEASE ALLOW FROM SETTINGS",Toast.LENGTH_SHORT).show();
        }else {
            ActivityCompat.requestPermissions(CreatePlaylistActivity.this, new String[]{Manifest.permission.READ_EXTERNAL_STORAGE}, 123);
            this.loadPage();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        if(recyclerView!=null){
            recyclerView.setAdapter(new CreatePlayListAdapter(songsList,getApplicationContext()));
        }
    }
}
