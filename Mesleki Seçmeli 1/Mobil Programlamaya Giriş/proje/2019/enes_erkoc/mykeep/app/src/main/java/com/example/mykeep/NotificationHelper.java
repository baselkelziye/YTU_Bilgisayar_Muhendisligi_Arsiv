package com.example.mykeep;

import android.annotation.TargetApi;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.content.Context;
import android.content.ContextWrapper;
import android.os.Build;
import android.support.v4.app.NotificationCompat;
import android.text.TextUtils;
import android.util.Log;

public class NotificationHelper extends ContextWrapper {
    public static final String channelID = "channelID";
    public static final String channelName = "Channel Name";

    private NotificationManager mManager;

    public NotificationHelper(Context base) {
        super(base);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            createChannel();
        }
    }

    @TargetApi(Build.VERSION_CODES.O)
    private void createChannel() {
        NotificationChannel channel = new NotificationChannel(channelID, channelName, NotificationManager.IMPORTANCE_HIGH);

        getManager().createNotificationChannel(channel);
    }

    public NotificationManager getManager() {
        if (mManager == null) {
            mManager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
        }

        return mManager;
    }

    public NotificationCompat.Builder getChannelNotification(String title, String content) {

        if(TextUtils.isEmpty(title)){

            return new NotificationCompat.Builder(getApplicationContext(), channelID)
                    .setContentText(content)
                    .setSmallIcon(R.drawable.ic_add_alert_black_24dp)
                    .setStyle(new NotificationCompat.BigTextStyle()
                            .bigText(content));
        }else{
            if(TextUtils.isEmpty(content)){
                return new NotificationCompat.Builder(getApplicationContext(), channelID)
                        .setContentTitle(title)
                        .setSmallIcon(R.drawable.ic_add_alert_black_24dp)
                        .setStyle(new NotificationCompat.BigTextStyle()
                                .bigText(content));
            }
            else {

                return new NotificationCompat.Builder(getApplicationContext(), channelID)
                        .setContentTitle(title)
                        .setContentText(content)
                        .setSmallIcon(R.drawable.ic_add_alert_black_24dp)
                        .setStyle(new NotificationCompat.BigTextStyle()
                                .bigText(content));
            }
        }

    }
}