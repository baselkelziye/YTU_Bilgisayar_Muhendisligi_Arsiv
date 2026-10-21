package com.bariscanyilmaz.musicplayer.roomdb;

import androidx.room.TypeConverter;
import androidx.room.TypeConverters;

import com.bariscanyilmaz.musicplayer.model.Song;
import com.bariscanyilmaz.musicplayer.model.SongList;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.List;

public class SongDataConverter {
    @TypeConverter
    public String fromSong(Song song){
        if (song==null) return (null);

        Gson gson=new Gson();
        Type type=new TypeToken<Song>() {}.getType();
        String json=gson.toJson(song,type);

        return json;
    }

    public Song toSong(String songJson){

        if (songJson==null) return null;

        Gson gson=new Gson();
        Type type = new TypeToken<Song>() {}.getType();
        Song song = gson.fromJson(songJson, type);
        return song;

    }
}
