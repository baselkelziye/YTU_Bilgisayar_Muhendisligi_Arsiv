package com.example.MyCalendar;

import android.app.AlarmManager;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

import java.util.Calendar;

import static android.content.Context.ALARM_SERVICE;

public class ReminderBroadcast extends BroadcastReceiver {
    public static String NOTIFICATION_ID = "notificationID";
    public static String NOTIFICATION = "notification";

    @Override
    public void onReceive(Context context, Intent intent) {
        //craetes the notification, when it's time
        NotificationManager notificationManager = (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);
        Notification notification = intent.getParcelableExtra(NOTIFICATION);

        int id = intent.getExtras().getInt(NOTIFICATION_ID);
        int repeat = intent.getExtras().getInt("repeat");
        long notTime = System.currentTimeMillis();

        notificationManager.notify(id, notification);

        if (repeat != 0) { //is it a repeating notification? set it again!
            long newNotTime = calNotTime(notTime, repeat);
            Intent myIntent = new Intent(context, ReminderBroadcast.class);
            myIntent.putExtra("repeat", repeat);
            myIntent.putExtra(ReminderBroadcast.NOTIFICATION_ID, id);
            myIntent.putExtra(ReminderBroadcast.NOTIFICATION, notification);

            PendingIntent pendingIntent = PendingIntent.getBroadcast(context, id, myIntent, 0);
            AlarmManager alarmManager = (AlarmManager) context.getSystemService(ALARM_SERVICE);
            assert alarmManager != null;

            alarmManager.setExactAndAllowWhileIdle(AlarmManager.RTC_WAKEUP, newNotTime, pendingIntent);

        }

    }

    public long calNotTime(long notTime, int repeat) {
        Calendar c = Calendar.getInstance();
        c.setTimeInMillis(notTime);
        switch (repeat) {
            case (1):
                c.add(Calendar.DAY_OF_MONTH, 1);
                break;
            case (2):
                c.add(Calendar.DAY_OF_MONTH, 7);
                break;
            case (3):
                c.add(Calendar.MONTH, 1);
                break;
            case (4):
                c.add(Calendar.YEAR, 1);
                break;
        }
        return c.getTimeInMillis();

    }

}
