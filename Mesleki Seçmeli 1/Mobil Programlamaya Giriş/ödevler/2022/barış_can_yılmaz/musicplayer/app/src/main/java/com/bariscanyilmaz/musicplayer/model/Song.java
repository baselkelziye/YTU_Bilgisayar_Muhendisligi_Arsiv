package com.bariscanyilmaz.musicplayer.model;

import android.os.Parcel;
import android.os.Parcelable;

public class Song{

    public String name;
    public String path;
    public String duration;
    public String artist;

    public Song(String name,String path, String duration, String artist){
        this.name=name;
        this.duration=duration;
        this.path=path;
        this.artist=artist;
    }

}