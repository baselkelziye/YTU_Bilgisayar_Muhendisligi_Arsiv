package com.kaansonmezoz.blm3520.notebook.Activities.MainActivity.AlertDialog;

import android.app.Activity;
import android.app.AlarmManager;
import android.app.DatePickerDialog;

import android.app.PendingIntent;
import android.app.TimePickerDialog;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.util.Log;
import android.widget.DatePicker;
import android.widget.TimePicker;

import com.kaansonmezoz.blm3520.notebook.AlertReceiver;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.ReminderType;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Locale;

public class TimeReminderAlertDialog {
    private Activity activity;
    private String alarmTitle;
    private int mYear, mMonth, mDay, mHourOfDay, mMinute;

    public TimeReminderAlertDialog(Activity activity, String alarmTitle){
        this.activity = activity;
        this.alarmTitle = alarmTitle;
    }

    public void showAlertDialog(){
        createDatePicker().show();
        createTimePickerDialog().show();
    }

    private DatePickerDialog createDatePicker(){
        final Calendar calendar = Calendar.getInstance();

        final DatePickerDialog.OnDateSetListener datePicker = new DatePickerDialog.OnDateSetListener(){
            @Override
            public void onDateSet(DatePicker view, int year, int month, int day){
                calendar.set(Calendar.YEAR, year);
                calendar.set(Calendar.MONTH, month);
                calendar.set(Calendar.DAY_OF_MONTH, day);

                mYear = year;
                mMonth = month;
                mDay = day;
            }
        };

        DatePickerDialog dialog = new DatePickerDialog(activity, datePicker,
                calendar.get(Calendar.YEAR),
                calendar.get(Calendar.MONTH),
                calendar.get(Calendar.DAY_OF_MONTH)
        );

        dialog.setButton(DialogInterface.BUTTON_POSITIVE, "OK", new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int which) {
                if (which == DialogInterface.BUTTON_POSITIVE) {
                    Log.d("Reminder", "TimeReminder: ok tusuna basildi");
                    //TODO: Burada iste alinan zaman ve tarih bilgileriyle alarm manager tarafından bir seyler yaratacagiz
                    calendar.set(Calendar.DATE,mDay);
                    calendar.set(Calendar.MONTH,mMonth);
                    calendar.set(Calendar.YEAR,mYear);
                    calendar.set(Calendar.HOUR_OF_DAY, mHourOfDay);
                    calendar.set(Calendar.MINUTE, mMinute);

                    AlarmManager alarmManager = (AlarmManager) activity.getSystemService(Context.ALARM_SERVICE);

                    Intent intent = new Intent(activity, AlertReceiver.class);
                    intent.putExtra("alarmText", alarmTitle);
                    PendingIntent pendingIntent = PendingIntent.getBroadcast(activity, 1, intent, 0);

                    alarmManager.setExact(AlarmManager.RTC_WAKEUP, calendar.getTimeInMillis(), pendingIntent);
                }
            }
        });

        return dialog;
    }

    private TimePickerDialog createTimePickerDialog() {
        final Calendar calendar = Calendar.getInstance();


        TimePickerDialog.OnTimeSetListener onTimeSetListener = new TimePickerDialog.OnTimeSetListener() {
            @Override
            public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
                calendar.set(Calendar.HOUR_OF_DAY, hourOfDay);
                calendar.set(Calendar.MINUTE, minute);

                mHourOfDay = hourOfDay;
                mMinute = minute;
            }
        };

        // Launch Time Picker Dialog
        TimePickerDialog timePickerDialog = new TimePickerDialog(activity, onTimeSetListener,
                calendar.get(Calendar.HOUR_OF_DAY), calendar.get(Calendar.MINUTE), true);


        return timePickerDialog;
    }
}

