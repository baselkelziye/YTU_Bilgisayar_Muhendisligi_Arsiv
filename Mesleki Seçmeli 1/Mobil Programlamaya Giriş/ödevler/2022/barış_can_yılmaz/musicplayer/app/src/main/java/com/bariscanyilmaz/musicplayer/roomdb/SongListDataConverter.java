package com.bariscanyilmaz.musicplayer.roomdb;


import androidx.room.TypeConverter;

import com.bariscanyilmaz.musicplayer.model.Song;
import com.bariscanyilmaz.musicplayer.model.SongList;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.List;

public class SongListDataConverter {

    @TypeConverter
    public String fromSongList(SongList songs){
        if (songs==null) return (null);

        Gson gson=new Gson();
        Type type=new TypeToken<List<Song>>() {}.getType();
        String json=gson.toJson(songs.songs,type);

        return json;
    }

    public SongList toSongList(String songListJson){

        if (songListJson==null) return null;

        Gson gson=new Gson();
        Type type = new TypeToken<SongList>() {}.getType();
        List<Song> songList = gson.fromJson(songListJson, type);
        return new SongList(songList);

    }
}
