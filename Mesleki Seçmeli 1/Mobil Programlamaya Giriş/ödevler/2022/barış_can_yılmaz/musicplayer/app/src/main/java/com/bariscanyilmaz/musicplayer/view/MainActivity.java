package com.bariscanyilmaz.musicplayer.view;

import android.Manifest;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.media.MediaDataSource;
import android.media.MediaPlayer;
import android.net.ConnectivityManager;
import android.net.Uri;
import android.os.Bundle;

import com.bariscanyilmaz.musicplayer.R;
import com.bariscanyilmaz.musicplayer.model.PlayList;
import com.bariscanyilmaz.musicplayer.model.PlaySong;
import com.bariscanyilmaz.musicplayer.model.Song;
import com.bariscanyilmaz.musicplayer.roomdb.AppDatabase;
import com.bariscanyilmaz.musicplayer.roomdb.PlayListDao;
import com.bariscanyilmaz.musicplayer.services.SensorReceiver;
import com.bariscanyilmaz.musicplayer.utils.AppSettings;
import com.bariscanyilmaz.musicplayer.utils.MediaPlayerController;
import com.bariscanyilmaz.musicplayer.utils.SaveSystem;
import com.bariscanyilmaz.musicplayer.view.ui.main.MediaPlayerViewModel;
import com.bariscanyilmaz.musicplayer.view.ui.main.PlayListViewModel;
import com.bariscanyilmaz.musicplayer.view.ui.main.PlayerFragment;
import com.bariscanyilmaz.musicplayer.view.ui.main.SongViewModel;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;
import com.google.android.material.tabs.TabLayout;


import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;
import androidx.room.Room;
import androidx.room.RoomDatabase;
import androidx.viewpager2.widget.ViewPager2;

import android.provider.MediaStore;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.bariscanyilmaz.musicplayer.view.ui.main.SectionsPagerAdapter;
import com.bariscanyilmaz.musicplayer.databinding.ActivityMainBinding;
import com.google.android.material.tabs.TabLayoutMediator;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.io.File;
import java.io.IOException;
import java.lang.reflect.Type;
import java.security.Permission;
import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    SharedPreferences sharedPreferences;

    private final MediaPlayer mediaPlayer=MediaPlayerController.getInstance();

    int currentSongIndex;
    List<Song> currentSongList;

    private final String sensorBroadcast="com.bariscanyilmaz.musicsensor.MUSIC_SENSOR";

    private ActivityMainBinding binding;
    private SectionsPagerAdapter sectionsPagerAdapter;
    private final int[] tabLayouts=new int[]{R.string.tab_song,R.string.tab_play_list,R.string.tab_player};

    private SongViewModel songViewModel;
    private PlayListViewModel playListViewModel;
    private MediaPlayerViewModel currentPlayerViewModel;

    private SensorReceiver  sensorReceiver=new SensorReceiver();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        String[] mPermission=new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE,Manifest.permission.READ_EXTERNAL_STORAGE,Manifest.permission.MANAGE_MEDIA};

        //TODO check permissions runtime

        sectionsPagerAdapter= new SectionsPagerAdapter(this);
        ViewPager2 viewPager = binding.viewPager;
        viewPager.setAdapter(sectionsPagerAdapter);

        TabLayout tabs = binding.tabs;

        new  TabLayoutMediator(tabs,viewPager,
                (tab,position)->tab.setText(tabLayouts[position])
        ).attach();

        sharedPreferences=getApplicationContext().getSharedPreferences(AppSettings.APP_SHARED_PREFS, Context.MODE_PRIVATE);

        mediaPlayer.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
            @Override
            public void onCompletion(MediaPlayer mediaPlayer) {
                //mediaPlayer.pause();
                Log.v("MediaPlayer","Song end");
                next();
            }

        });

        songViewModel=new ViewModelProvider(this).get(SongViewModel.class);
        if(checkPermissions()){
            songViewModel.setSongs(getSongs(this));
        }else {
            try {
                if (ActivityCompat.checkSelfPermission(this, mPermission[0])
                        != PackageManager.PERMISSION_GRANTED ||
                        ActivityCompat.checkSelfPermission(this, mPermission[1])
                                != PackageManager.PERMISSION_GRANTED ||
                        ActivityCompat.checkSelfPermission(this, mPermission[2])
                                != PackageManager.PERMISSION_GRANTED ||
                        ActivityCompat.checkSelfPermission(this, mPermission[3])
                                != PackageManager.PERMISSION_GRANTED) {

                    ActivityCompat.requestPermissions(this,
                            mPermission, 101);

                    // If any permission above not allowed by user, this condition will execute every tim, else your else part will work
                }
            } catch (Exception e) {
                e.printStackTrace();
            }

        }


        currentPlayerViewModel=new ViewModelProvider(this).get(MediaPlayerViewModel.class);
        currentPlayerViewModel.getChosenSong().observe(this, updatePlayerSong);

        playListViewModel=new ViewModelProvider(this).get(PlayListViewModel.class);

        playListViewModel.setPlayLists(SaveSystem.getPlayLists(sharedPreferences));

    }


    @Override
    protected void onStart() {
        super.onStart();
        IntentFilter filter=new IntentFilter(sensorBroadcast);
        registerReceiver(sensorReceiver,filter);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        Log.v("Req Code", "" + requestCode);
        if (requestCode == 101) {
            if (grantResults.length == 3 &&
                    grantResults[0] == PackageManager.PERMISSION_GRANTED ||
                    grantResults[1] == PackageManager.PERMISSION_GRANTED ||
                    grantResults[2] == PackageManager.PERMISSION_GRANTED) {


                Log.v("Permission","all permissions granted");
                songViewModel.setSongs(getSongs(getApplicationContext()));

            }
        }



    }

    private Observer<PlaySong> updatePlayerSong= new Observer<PlaySong>() {
        @Override
        public void onChanged(PlaySong playSong) {

            if (currentSongList==null){
                currentSongList=playSong.songs;
                currentSongIndex=playSong.index;
                play();

            }else{

                if(currentSongList.equals(playSong.songs))
                {
                    //same or next item pressed

                    if(currentSongIndex==playSong.index){

                        if(mediaPlayer.isPlaying()){

                            mediaPlayer.pause();

                        }else{

                            mediaPlayer.start();

                        }

                    }else{
                        currentSongIndex=playSong.index;
                        play();
                    }

                }else{
                    currentSongList=playSong.songs;
                    currentSongIndex=playSong.index;

                    play();
                }
            }
        }
    };

    private void next(){
        if (currentSongList==null) return;

        if (currentSongIndex+1<currentSongList.size()){
            currentSongIndex++;

            PlaySong playSong=new PlaySong(currentSongIndex,currentSongList);

            currentPlayerViewModel.setChosenSong(playSong);

            play();
        }
    }
    private void prev(){
        if (currentSongIndex-1>=0){
            currentSongIndex--;

            PlaySong playSong=new PlaySong(currentSongIndex,currentSongList);
            currentPlayerViewModel.setChosenSong(playSong);

            play();
        }
    }

    private void play(){
        if(currentSongList==null) return;

        mediaPlayer.reset();
        Song chosen=currentSongList.get(currentSongIndex);
        try {

            File f=new File(chosen.path);

            if(!f.exists()) {
                Toast.makeText(getApplicationContext(), chosen.name+" is deleted", Toast.LENGTH_SHORT).show();
                return;
            }

            mediaPlayer.setDataSource(chosen.path);
            mediaPlayer.prepare();
            mediaPlayer.start();
        }catch (IOException e){

            e.printStackTrace();
        }
    }
    private void pause(){
        mediaPlayer.pause();
    }

    public boolean checkPermissions(){
        if(
                ContextCompat.checkSelfPermission(getApplicationContext(), Manifest.permission.MANAGE_MEDIA)!= PackageManager.PERMISSION_GRANTED

                        || ContextCompat.checkSelfPermission(getApplicationContext(),Manifest.permission.READ_EXTERNAL_STORAGE)!=PackageManager.PERMISSION_GRANTED
                        ||
                        ContextCompat.checkSelfPermission(getApplicationContext(),Manifest.permission.WRITE_EXTERNAL_STORAGE)!=PackageManager.PERMISSION_GRANTED
        ) {
            return false;
        }

        return true;
    }

    public ArrayList<Song> getSongs(final Context context){



        ArrayList<Song> list = new ArrayList<Song>();

        Uri uri = MediaStore.Audio.Media.EXTERNAL_CONTENT_URI;
        Log.v("Uri",uri.toString());
        String[] projection = {MediaStore.Audio.AudioColumns.DATA,MediaStore.Audio.AudioColumns.TITLE,MediaStore.Audio.AudioColumns.DURATION, MediaStore.Audio.ArtistColumns.ARTIST,};
        String selection = MediaStore.Audio.Media.IS_MUSIC +" != 0";
        //MediaStore.Audio.AudioColumns.DATA + " like ? "
        Cursor c = context.getContentResolver().query(uri, projection, selection, null, null);

        if (c != null) {

            while (c.moveToNext()) {


                String path = c.getString(0);
                String name = c.getString(1);
                String duration = c.getString(2);
                String artist = c.getString(3);

                Song song = new Song(name,path,duration,artist);

                list.add(song);
            }
            c.close();
        }
        Log.v("Songs","Size:"+list.size());
        return list;
    }

    public void playPauseButton(View v){
        if (mediaPlayer.isPlaying()){
            pause();
        }else{
            mediaPlayer.start();
        }
    }

    public void nextButton(View v){

        next();
    }
    public void prevButton(View v)
    {
        prev();
    }

    @Override
    protected void onStop() {
        super.onStop();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(sensorReceiver);
    }
}

