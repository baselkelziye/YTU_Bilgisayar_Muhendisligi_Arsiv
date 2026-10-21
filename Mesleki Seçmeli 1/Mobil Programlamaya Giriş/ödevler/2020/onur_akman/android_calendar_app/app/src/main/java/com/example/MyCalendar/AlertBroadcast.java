package com.example.MyCalendar;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

public class AlertBroadcast extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        //gets the alert data and passes them to the related activity, when it's time
        String title = intent.getExtras().getString("title");
        String content = intent.getExtras().getString("content");
        int repeat = intent.getExtras().getInt("repeat");
        int alertID = intent.getExtras().getInt("alertID");

        Intent myIntent = new Intent(context.getApplicationContext(), AlertActivity.class);
        myIntent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        myIntent.putExtra("alertID", alertID);
        myIntent.putExtra("content", content);
        myIntent.putExtra("title", title);
        myIntent.putExtra("repeat", repeat);
        context.startActivity(myIntent);
    }
}
