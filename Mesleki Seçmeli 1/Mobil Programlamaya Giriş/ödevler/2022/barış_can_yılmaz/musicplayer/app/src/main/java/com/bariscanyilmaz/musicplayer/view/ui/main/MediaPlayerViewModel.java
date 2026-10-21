package com.bariscanyilmaz.musicplayer.view.ui.main;

import androidx.lifecycle.MutableLiveData;
import androidx.lifecycle.ViewModel;

import com.bariscanyilmaz.musicplayer.model.PlaySong;
import com.bariscanyilmaz.musicplayer.model.Song;

import java.util.List;

public class MediaPlayerViewModel extends ViewModel {

    private MutableLiveData<PlaySong> chosenSong=new MutableLiveData<PlaySong>();

    public MutableLiveData<PlaySong> getChosenSong() {
        return chosenSong;
    }


    public void setChosenSong(PlaySong chosenSong) {
        this.chosenSong.setValue(chosenSong);
    }
}
