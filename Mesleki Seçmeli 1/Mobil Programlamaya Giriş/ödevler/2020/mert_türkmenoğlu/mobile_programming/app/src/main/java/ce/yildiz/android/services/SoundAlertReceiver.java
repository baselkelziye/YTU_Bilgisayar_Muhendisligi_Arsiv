package ce.yildiz.android.services;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.media.Ringtone;
import android.media.RingtoneManager;
import android.net.Uri;
import android.os.Handler;

public class SoundAlertReceiver extends BroadcastReceiver {
    private static final String TAG = SoundAlertReceiver.class.getSimpleName();
    private static final int ALARM_DELAY_MILLIS = 3000;

    @Override
    public void onReceive(Context context, Intent intent) {
        Uri uri = RingtoneManager.getDefaultUri(RingtoneManager.TYPE_ALARM);
        final Ringtone ringtone = RingtoneManager.getRingtone(context, uri);

        if (ringtone == null) return;

        ringtone.play();

        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                ringtone.stop();
            }
        }, ALARM_DELAY_MILLIS);
    }
}
