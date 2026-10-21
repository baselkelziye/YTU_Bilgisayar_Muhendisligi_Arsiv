package com.example.mykeep;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.NotificationCompat;
import android.util.Log;

public class AlertReceiver extends BroadcastReceiver {



    @Override
    public void onReceive(Context context, Intent intent) {
        Bundle extras = intent.getExtras();
        String reminderTitle = extras.getString("reminderTitle");
        String reminderContent = extras.getString("reminderContent");

        NotificationHelper notificationHelper = new NotificationHelper(context);
        NotificationCompat.Builder nb = notificationHelper.getChannelNotification(reminderTitle, reminderContent);
        notificationHelper.getManager().notify(1, nb.build());
    }
}