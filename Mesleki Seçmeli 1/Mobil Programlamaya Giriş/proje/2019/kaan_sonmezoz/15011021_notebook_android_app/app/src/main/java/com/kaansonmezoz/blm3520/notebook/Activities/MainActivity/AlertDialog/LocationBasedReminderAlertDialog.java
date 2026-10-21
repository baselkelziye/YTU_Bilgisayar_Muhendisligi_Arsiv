package com.kaansonmezoz.blm3520.notebook.Activities.MainActivity.AlertDialog;

import android.app.Activity;


public class LocationBasedReminderAlertDialog {
    private Activity activity;
    private String alarmTitle;

    public LocationBasedReminderAlertDialog(Activity activity, String alarmTitle){
        this.activity = activity;
        this.alarmTitle = alarmTitle;
    }
}
