package com.kaansonmezoz.blm3520.notebook;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.support.v4.app.NotificationCompat;

import com.kaansonmezoz.blm3520.notebook.Activities.NotificationHelper;


public class AlertReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        NotificationHelper notificationHelper = new NotificationHelper(context);
        NotificationCompat.Builder nb = notificationHelper.getChannelNotification(intent.getStringExtra("alarmText"));
        notificationHelper.getManager().notify(1, nb.build());
    }
}