package com.example.sefagokceoglu;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.media.AudioManager;
import android.os.Bundle;
import android.telephony.SmsMessage;
import android.util.Log;

public class MyReceiver extends BroadcastReceiver {

    private Double value = 0.0;

    private float percent = 0.5f;

    @Override
    public void onReceive(Context context, Intent intent) {
        AudioManager audio = (AudioManager) context.getSystemService(Context.AUDIO_SERVICE);
        int currentVolume = audio.getStreamVolume(AudioManager.STREAM_MUSIC);
        int maxVolume = audio.getStreamMaxVolume(AudioManager.STREAM_MUSIC);
        Bundle bundle = intent.getExtras();
        Boolean value = (Boolean) bundle.get("value");
        if(value == true){
            percent = percent + 0.01f;
            if (percent > 1.0f) {
                percent = 1.0f;
            }
            int seventyVolume = (int) (maxVolume*percent);
            audio.setStreamVolume(AudioManager.STREAM_MUSIC, seventyVolume, 0);
        }
        else {
            percent =percent - 0.01f;
            if(percent < 0.0f) {
                percent = 0.0f;
            }
            int seventyVolume = (int) (maxVolume*percent);
            audio.setStreamVolume(AudioManager.STREAM_MUSIC, seventyVolume, 0);
            // Volume Down
        }
        Log.d(getClass().getName().toString(), value.toString());
    }
}