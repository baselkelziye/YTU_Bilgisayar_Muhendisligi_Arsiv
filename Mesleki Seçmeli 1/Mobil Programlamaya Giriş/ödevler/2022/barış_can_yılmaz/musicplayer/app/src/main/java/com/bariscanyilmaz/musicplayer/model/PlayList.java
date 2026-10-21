package com.bariscanyilmaz.musicplayer.model;

import androidx.room.ColumnInfo;
import androidx.room.Embedded;
import androidx.room.Entity;
import androidx.room.Ignore;
import androidx.room.PrimaryKey;
import androidx.room.TypeConverter;
import androidx.room.TypeConverters;

import com.bariscanyilmaz.musicplayer.roomdb.SongListDataConverter;
import com.google.gson.annotations.SerializedName;

import java.util.List;

@Entity
public class PlayList {

    @PrimaryKey(autoGenerate = true)
    public int id;

    @ColumnInfo(name = "name")
    public String name;

    public PlayList(String name){
        this.name=name;
    }

    /*
    @ColumnInfo(name = "songs")
    public String songs;
    */
    @Ignore
    public List<Song> songList;


}
