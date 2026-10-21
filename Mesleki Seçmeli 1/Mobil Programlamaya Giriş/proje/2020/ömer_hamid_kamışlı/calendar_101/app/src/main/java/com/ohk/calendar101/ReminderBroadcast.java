package com.ohk.calendar101;

import android.app.Notification;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.media.Ringtone;
import android.media.RingtoneManager;
import android.net.Uri;

import androidx.core.app.NotificationCompat;
import androidx.core.app.NotificationManagerCompat;

public class ReminderBroadcast extends BroadcastReceiver {
    String title = "Etkinlik Hatırlatması ";
    String message = "Detaylara erişmek için tıklayınız.";
    boolean vibration;
    String soundUri;
    @Override
    public void onReceive(Context context, Intent intent) {
        title += intent.getStringExtra("name");
        message = intent.getStringExtra("desc");
        vibration = intent.getBooleanExtra("vibration",true);
        soundUri = intent.getStringExtra("soundUri");
        NotificationCompat.Builder builder = new NotificationCompat.Builder(context,"notifyCalendarApp")
                .setSmallIcon(R.drawable.icon_notification_background)
                .setPriority(NotificationCompat.PRIORITY_HIGH)
                .setContentTitle(title)
                .setContentText(message);

        NotificationManagerCompat notificationManager = NotificationManagerCompat.from(context);

        Notification n = builder.build();
        try{
            Ringtone toque = RingtoneManager.getRingtone(context, Uri.parse(soundUri));
            toque.play();
        } catch (Exception error){
            System.out.println(error);
        }
        if(vibration){
            n.vibrate = new long[]{150, 300, 150, 400};
        }
        n.flags = Notification.FLAG_AUTO_CANCEL;

        notificationManager.notify(200,n);
    }
}
