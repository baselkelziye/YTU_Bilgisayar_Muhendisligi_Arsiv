package com.bariscanyilmaz.musicplayer.services;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.media.AudioManager;
import android.util.Log;

import java.util.Timer;
import java.util.TimerTask;
import java.util.function.Function;

public class SensorReceiver extends BroadcastReceiver {

    private AudioManager audioManager;
    private final long delay=500;

    @Override
    public void onReceive(Context context, Intent intent) {

        audioManager=(AudioManager)context.getSystemService(Context.AUDIO_SERVICE);
        Log.v("Receiver","Receiver Called");
        boolean isMoving= intent.getBooleanExtra("isMoving",false);
        boolean isInside= intent.getBooleanExtra("isInside",false);

        if(isMoving && isInside){

            Log.v("Receiver","Moving, Inside, Unmute");
            //unmute music
            new Timer().schedule(new TimerTask() {
                @Override
                public void run() {
                    audioManager.adjustVolume(AudioManager.ADJUST_UNMUTE,AudioManager.FLAG_SHOW_UI);
                }
            },delay);

        }else if(!isMoving && !isInside){

            //mute music
            Log.v("Receiver","Not Moving,Not Inside, Mute");

            new Timer().schedule(new TimerTask() {
                @Override
                public void run() {
                    audioManager.adjustVolume(AudioManager.ADJUST_MUTE,AudioManager.FLAG_SHOW_UI);
                }
            },delay);


        }else if(!isMoving && isInside){

            //unmute music
            Log.v("Receiver","Not Moving, Inside, Unmute");
            new Timer().schedule(new TimerTask() {
                @Override
                public void run() {
                    audioManager.adjustVolume(AudioManager.ADJUST_UNMUTE,AudioManager.FLAG_SHOW_UI);
                }
            },delay);

        }else{
            //unmute music
            Log.v("Receiver","Not Moving, Inside, Unmute");
            new Timer().schedule(new TimerTask() {
                @Override
                public void run() {
                    audioManager.adjustVolume(AudioManager.ADJUST_UNMUTE,AudioManager.FLAG_SHOW_UI);
                }
            },delay);
        }
    }
}
