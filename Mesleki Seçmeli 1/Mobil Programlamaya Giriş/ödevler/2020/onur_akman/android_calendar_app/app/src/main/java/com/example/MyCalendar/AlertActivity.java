package com.example.MyCalendar;
//This activity is responsible for setting alertdialogs and resetting them if it's a repeating event

import android.app.Activity;
import android.app.AlarmManager;
import android.app.AlertDialog;
import android.app.PendingIntent;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;

import java.util.Calendar;

public class AlertActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        Intent intent = AlertActivity.this.getIntent();
        Bundle extras = intent.getExtras();
        String title = extras.getString("title");
        String content = extras.getString("content");
        int repeat = extras.getInt("repeat");
        int alertID = extras.getInt("alertID");
        long notTime = System.currentTimeMillis();

        AlertDialog.Builder builder = new AlertDialog.Builder(AlertActivity.this);
        builder.setTitle("Your event is approaching!");
        builder.setIcon(R.drawable.ic_launcher_foreground2);
        if (title != null) builder.setMessage(title + " " + content);
        else builder.setMessage("Click OK to view your events.");
        //this was a problem I could not handle in any other way. Sometimes this activity refuses to
        //get the String value passed from broadcast receiver and I could not find any solution but this.
        builder.setCancelable(false);
        builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int id) {
                Intent intent = new Intent(AlertActivity.this, MainActivity.class);
                intent.putExtra("request", 0);
                startActivity(intent);
            }
        });
        AlertDialog alert = builder.create();
        alert.show();

        if (repeat != 0) { //is it a repeating event
            long newNotTime = calNotTime(notTime, repeat);
            Intent myIntent = new Intent(AlertActivity.this, AlertBroadcast.class);
            myIntent.putExtra("repeat", repeat);
            myIntent.putExtra("alertID", alertID);
            myIntent.putExtra("title", title);
            myIntent.putExtra("content", content);

            PendingIntent pendingIntent = PendingIntent.getBroadcast(AlertActivity.this, alertID, myIntent, 0);
            AlarmManager alarmManager = (AlarmManager) AlertActivity.this.getSystemService(ALARM_SERVICE);
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
