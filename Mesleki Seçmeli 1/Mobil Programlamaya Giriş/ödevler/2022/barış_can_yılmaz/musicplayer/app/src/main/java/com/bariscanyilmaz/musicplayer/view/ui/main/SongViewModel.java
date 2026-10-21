package com.bariscanyilmaz.musicplayer.view.ui.main;

import android.util.Log;

import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;
import androidx.lifecycle.Transformations;
import androidx.lifecycle.ViewModel;

import com.bariscanyilmaz.musicplayer.model.Song;

import java.util.ArrayList;
import java.util.List;

public class SongViewModel extends ViewModel {

    private MutableLiveData<List<Song>> songs=new MutableLiveData<List<Song>>();

    public void setSongs(List<Song> songs){
        Log.v("Song","set songs new value size:"+songs.size());
        this.songs.setValue(songs);
    }


    public LiveData<List<Song>> getSongs(){
        Log.v("song","Get songs");
        return songs;
    }

}
