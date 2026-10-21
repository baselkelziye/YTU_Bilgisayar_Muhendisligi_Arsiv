package com.bariscanyilmaz.musicplayer.utils;

import android.content.SharedPreferences;
import android.util.Log;

import com.bariscanyilmaz.musicplayer.model.PlayList;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.List;

public class SaveSystem {

    public static void savePlayList(SharedPreferences sharedPreferences, List<PlayList> playLists){

        Gson gson=new Gson();
        Type type=new TypeToken<List<PlayList>>() {}.getType();
        String json=gson.toJson(playLists,type);
        SharedPreferences.Editor editor= sharedPreferences.edit();
        editor.putString(AppSettings.PLAY_LISTS,json).apply();
    }

    public static List<PlayList> getPlayLists(SharedPreferences sharedPreferences){
        String playListsJson="";

        playListsJson=sharedPreferences.getString(AppSettings.PLAY_LISTS,null);

        if (playListsJson==null) return new ArrayList<>();

        Gson gson=new Gson();

        Type type = new TypeToken<List<PlayList>>() {}.getType();

        ArrayList<PlayList> result = gson.fromJson(playListsJson, type);

        return result;
    }
}
