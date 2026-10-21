package com.kaansonmezoz.blm3520.notebook.Activities.MainActivity.AlertDialog;

import android.app.Activity;
import android.app.Dialog;
import android.content.DialogInterface;
import android.support.v7.app.AlertDialog;

public class ReminderAlertDialog {
    private Activity activity;
    private String alarmTitle;

    public ReminderAlertDialog(Activity activity, String alarmTitle){
        this.activity = activity;
        this.alarmTitle = alarmTitle;
    }

    public void showAlertDialog(){
        onCreateDialog(activity).show();
    }

    private Dialog onCreateDialog(final Activity activity) {
        // Use the Builder class for convenient dialog construction
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        builder.setMessage("Select Reminder Type")
                .setPositiveButton("Time Based", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        TimeReminderAlertDialog alertDialog = new TimeReminderAlertDialog(activity, alarmTitle);
                        alertDialog.showAlertDialog();
                    }
                })
                .setNegativeButton("Location Based", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        LocationBasedReminderAlertDialog alertDialog = new LocationBasedReminderAlertDialog(activity, alarmTitle);
                    }
                });

        return builder.create();
    }

}
