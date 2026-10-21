package com.example.sefagokceoglu.model;

import java.util.HashSet;
import java.util.Set;

public class Playlist {

    public static Set<AudioModel> selectedSongs = new HashSet<>();

    public Set<AudioModel> getSelectedSongs() {
        return selectedSongs;
    }

    public void setSelectedSongs(Set<AudioModel> selectedSongs) {
        this.selectedSongs = selectedSongs;
    }

    public static void reset() {
        selectedSongs = new HashSet<>();
    }
}
