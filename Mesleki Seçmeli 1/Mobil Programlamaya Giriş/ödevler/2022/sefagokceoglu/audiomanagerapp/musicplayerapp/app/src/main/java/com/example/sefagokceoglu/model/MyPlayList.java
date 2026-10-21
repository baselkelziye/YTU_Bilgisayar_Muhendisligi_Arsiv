package com.example.sefagokceoglu.model;

import java.io.Serializable;
import java.util.Set;

public class MyPlayList implements Serializable {

    private String playlistName;

    private Set<AudioModel> songs;

    public MyPlayList(String playlistName, Set<AudioModel> songs) {
        this.playlistName = playlistName;
        this.songs = songs;
    }

    public String getPlaylistName() {
        return playlistName;
    }

    public void setPlaylistName(String playlistName) {
        this.playlistName = playlistName;
    }

    public Set<AudioModel> getSongs() {
        return songs;
    }

    public void setSongs(Set<AudioModel> songs) {
        this.songs = songs;
    }
}
