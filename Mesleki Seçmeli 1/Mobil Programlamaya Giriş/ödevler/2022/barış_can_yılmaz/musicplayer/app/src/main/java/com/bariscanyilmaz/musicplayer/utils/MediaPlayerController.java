package com.bariscanyilmaz.musicplayer.utils;

import android.media.MediaPlayer;
import android.util.Log;

import com.bariscanyilmaz.musicplayer.model.Song;

import java.io.IOException;
import java.util.List;

public class MediaPlayerController {

    static MediaPlayer instance;

    public static MediaPlayer getInstance() {
        if (instance == null)
            instance = new MediaPlayer();

        return instance;
    }

}
