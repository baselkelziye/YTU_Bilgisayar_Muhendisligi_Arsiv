package com.bariscanyilmaz.musicplayer.view.ui.main;

import android.util.Log;

import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;
import androidx.lifecycle.ViewModel;

import com.bariscanyilmaz.musicplayer.model.PlayList;

import java.util.List;

public class PlayListViewModel extends ViewModel {

    private MutableLiveData<List<PlayList>> playLists=new MutableLiveData<List<PlayList>>();

    public void setPlayLists(List<PlayList> playLists){
        this.playLists.setValue(playLists);
    }

    public LiveData<List<PlayList>> getPlayLists(){
        return playLists;
    }

    public void addNewList(PlayList list){
        List<PlayList> l=this.playLists.getValue();
        Log.v("List",""+l.size());
        l.add(list);
        setPlayLists(l);
    }

}
