package com.bariscanyilmaz.musicplayer.model;

import java.util.List;

public class PlaySong {

    public int index;
    public List<Song> songs;

    public PlaySong(int index, List<Song> songs){
        this.index=index;
        this.songs=songs;
    }
}
