package com.ohk.calendar101;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.app.AlarmManager;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Build;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class addEvent extends AppCompatActivity {
    Button saveButton;
    Button startDate;
    Button finishDate;
    Button alarm1;
    Button alarm2;
    Button alarm3;
    TextView alarm1TXT;
    TextView alarm2TXT;
    TextView alarm3TXT;
    TextView startDateTXT;
    TextView finishDateTXT;
    TextView eventName;
    TextView description;
    TextView location;
    private Toolbar toolbar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_event);

        toolbar = (Toolbar) findViewById(R.id.toolbar_event);
        setSupportActionBar(toolbar);

        saveButton = findViewById(R.id.addEvent_btn_save);
        startDate = findViewById(R.id.addEvent_btn_start_time);
        finishDate = findViewById(R.id.addEvent_btn_finish_time);
        alarm1 = findViewById(R.id.addEvent_btn_alarm1);
        alarm2 = findViewById(R.id.addEvent_btn_alarm2);
        alarm3 = findViewById(R.id.addEvent_btn_alarm3);
        alarm1TXT = findViewById(R.id.addEvent_txt_alarm1);
        alarm2TXT = findViewById(R.id.addEvent_txt_alarm2);
        alarm3TXT = findViewById(R.id.addEvent_txt_alarm3);
        startDateTXT = findViewById(R.id.addEvent_txt_start_time);
        finishDateTXT = findViewById(R.id.addEvent_txt_finish_time);
        eventName = findViewById(R.id.addEvent_name);
        description = findViewById(R.id.addEvent_description);
        location = findViewById(R.id.addEvent_location);
        LinearLayout layout = findViewById(R.id.addEvent_layout);

        final Intent intent = new Intent(addEvent.this,ReminderBroadcast.class);
        final AlarmManager alarmManager = (AlarmManager) getSystemService(ALARM_SERVICE);
        createNotificationChannel();
        final RepoDatabase database = RepoDatabase.getInstance(getApplicationContext());

        final Spinner type = findViewById(R.id.addEvent_Type);
        String[] items = new String[]{"Event Type","Personal","Birthday", "Meeting", "Assigment"};
        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_dropdown_item, items);
        type.setAdapter(adapter);

        final Spinner repeatable = findViewById(R.id.addEvent_repeatable);
        String[] items2 = new String[]{"Repatable","Everyday","Every Week", "Every Month", "Every Year"};
        ArrayAdapter<String> adapter2 = new ArrayAdapter<>(this, android.R.layout.simple_spinner_dropdown_item, items2);
        repeatable.setAdapter(adapter2);

        SharedPreferences sharedPref =getSharedPreferences("settings",MODE_PRIVATE);
        Boolean vibration = true;
        String soundUri = "";
        try {
            type.setSelection(sharedPref.getInt("type",0));
            repeatable.setSelection(sharedPref.getInt("repeat",0));
            vibration = sharedPref.getBoolean("vibration",true);
            soundUri =sharedPref.getString("soundUri","");
        } catch (Exception error){
            System.out.println(error);
        }
        if(sharedPref.getBoolean("darkMode",false)){
            System.out.println("Dark mod seçili");

            eventName.setTextColor(Color.parseColor("#FFFFFF"));
            description.setTextColor(Color.parseColor("#FFFFFF"));
            location.setTextColor(Color.parseColor("#FFFFFF"));
            startDateTXT.setTextColor(Color.parseColor("#FFFFFF"));
            finishDateTXT.setTextColor(Color.parseColor("#FFFFFF"));
            alarm1TXT.setTextColor(Color.parseColor("#FFFFFF"));
            alarm2TXT.setTextColor(Color.parseColor("#FFFFFF"));
            alarm3TXT.setTextColor(Color.parseColor("#FFFFFF"));

            eventName.setHintTextColor(Color.parseColor("#FFFFFF"));
            description.setHintTextColor(Color.parseColor("#FFFFFF"));
            location.setHintTextColor(Color.parseColor("#FFFFFF"));
            startDateTXT.setHintTextColor(Color.parseColor("#FFFFFF"));
            finishDateTXT.setHintTextColor(Color.parseColor("#FFFFFF"));
            alarm1TXT.setHintTextColor(Color.parseColor("#FFFFFF"));
            alarm2TXT.setHintTextColor(Color.parseColor("#FFFFFF"));
            alarm3TXT.setHintTextColor(Color.parseColor("#FFFFFF"));
            layout.setBackgroundColor(Color.parseColor("#192841"));
        }

        alarm1.setOnClickListener(new View.OnClickListener() {//saatButona Click Listener ekliyoruz

            @Override
            public void onClick(View v) {

                new CustomDateTimePicker(addEvent.this,
                        new CustomDateTimePicker.ICustomDateTimeListener() {
                            @Override
                            public void onSet(Dialog dialog, Calendar calendarSelected,
                                              Date dateSelected, int year,
                                              String monthFullName,
                                              String monthShortName,
                                              int monthNumber, int date,
                                              String weekDayFullName,
                                              String weekDayShortName, int hour24,
                                              int hour12,
                                              int min, int sec, String AM_PM) {
                                alarm1TXT.setText(calendarSelected.get(Calendar.DAY_OF_MONTH) + "-" + (monthNumber + 1) + "-" + year + " " + hour24 + ":" + min);
                            }

                            @Override
                            public void onCancel() {

                            }
                        }).set24HourFormat(true).setDate(Calendar.getInstance())
                        .showDialog();
            }
        });

        alarm2.setOnClickListener(new View.OnClickListener() {//saatButona Click Listener ekliyoruz

            @Override
            public void onClick(View v) {
                new CustomDateTimePicker(addEvent.this,
                        new CustomDateTimePicker.ICustomDateTimeListener() {
                            @Override
                            public void onSet(Dialog dialog, Calendar calendarSelected,
                                              Date dateSelected, int year,
                                              String monthFullName,
                                              String monthShortName,
                                              int monthNumber, int date,
                                              String weekDayFullName,
                                              String weekDayShortName, int hour24,
                                              int hour12,
                                              int min, int sec, String AM_PM) {
                                alarm2TXT.setText(calendarSelected.get(Calendar.DAY_OF_MONTH) + "-" + (monthNumber + 1) + "-" + year + " " + hour24 + ":" + min);
                            }

                            @Override
                            public void onCancel() {

                            }
                        }).set24HourFormat(true).setDate(Calendar.getInstance())
                        .showDialog();
            }
        });

        alarm3.setOnClickListener(new View.OnClickListener() {//saatButona Click Listener ekliyoruz

            @Override
            public void onClick(View v) {
                new CustomDateTimePicker(addEvent.this,
                        new CustomDateTimePicker.ICustomDateTimeListener() {
                            @Override
                            public void onSet(Dialog dialog, Calendar calendarSelected,
                                              Date dateSelected, int year,
                                              String monthFullName,
                                              String monthShortName,
                                              int monthNumber, int date,
                                              String weekDayFullName,
                                              String weekDayShortName, int hour24,
                                              int hour12,
                                              int min, int sec, String AM_PM) {
                                alarm3TXT.setText(calendarSelected.get(Calendar.DAY_OF_MONTH) + "-" + (monthNumber + 1) + "-" + year + " " + hour24 + ":" + min);
                            }

                            @Override
                            public void onCancel() {

                            }
                        }).set24HourFormat(true).setDate(Calendar.getInstance())
                        .showDialog();
            }
        });

        startDate.setOnClickListener(new View.OnClickListener() {//tarihButona Click Listener ekliyoruz

            @Override
            public void onClick(View v) {
                new CustomDateTimePicker(addEvent.this,
                        new CustomDateTimePicker.ICustomDateTimeListener() {
                            @Override
                            public void onSet(Dialog dialog, Calendar calendarSelected,
                                              Date dateSelected, int year,
                                              String monthFullName,
                                              String monthShortName,
                                              int monthNumber, int date,
                                              String weekDayFullName,
                                              String weekDayShortName, int hour24,
                                              int hour12,
                                              int min, int sec, String AM_PM) {
                                startDateTXT.setText(calendarSelected.get(Calendar.DAY_OF_MONTH) + "-" + (monthNumber + 1) + "-" + year + " " + hour24 + ":" + min);
                            }

                            @Override
                            public void onCancel() {

                            }
                        }).set24HourFormat(true).setDate(Calendar.getInstance())
                        .showDialog();

            }
        });

        finishDate.setOnClickListener(new View.OnClickListener() {//tarihButona Click Listener ekliyoruz

            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub
                new CustomDateTimePicker(addEvent.this,
                        new CustomDateTimePicker.ICustomDateTimeListener() {
                            @Override
                            public void onSet(Dialog dialog, Calendar calendarSelected,
                                              Date dateSelected, int year,
                                              String monthFullName,
                                              String monthShortName,
                                              int monthNumber, int date,
                                              String weekDayFullName,
                                              String weekDayShortName, int hour24,
                                              int hour12,
                                              int min, int sec, String AM_PM) {
                                finishDateTXT.setText(calendarSelected.get(Calendar.DAY_OF_MONTH) + "-" + (monthNumber + 1) + "-" + year + " " + hour24 + ":" + min);
                            }

                            @Override
                            public void onCancel() {

                            }
                        }).set24HourFormat(true).setDate(Calendar.getInstance())
                        .showDialog();

            }
        });

        final Boolean finalVibration = vibration;
        final String finalSoundUri = soundUri;
        saveButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                if(!TextUtils.isEmpty(eventName.getText().toString()) && !TextUtils.isEmpty(finishDate.getText().toString()) && !TextUtils.isEmpty(startDate.getText().toString()) ){
                    SimpleDateFormat simpleDateFormat = new SimpleDateFormat("dd-MM-yyyy HH:mm");
                    long alarm1Field=0,alarm2Field=0,alarm3Field=0,startDateField = 0,finishDateField=0;
                    String name = eventName.getText().toString();
                    String desc = description.getText().toString();
                    int typeValue= type.getSelectedItemPosition();
                    String startDateFinal = startDateTXT.getText().toString()+" 00:00";
                    String finalDateFinal = finishDateTXT.getText().toString()+" 00:00";
                    String locationTXT = location.getText().toString();
                    try {
                        if(alarm1TXT.getText().toString().isEmpty()){
                            alarm1Field = 0;
                        } else {
                            alarm1Field = simpleDateFormat.parse(alarm1TXT.getText().toString()).getTime();
                        }
                    } catch (Exception error){
                        System.out.println(error);
                    }

                    try {
                        if(alarm2TXT.getText().toString().isEmpty()){
                            alarm2Field = 0;
                        } else {
                            alarm2Field = simpleDateFormat.parse(alarm2TXT.getText().toString()).getTime();
                        }
                    } catch (Exception error){
                        System.out.println(error);
                    }

                    try {
                        if(alarm3TXT.getText().toString().isEmpty()){
                            alarm3Field = 0;
                        } else {
                            alarm3Field = simpleDateFormat.parse(alarm3TXT.getText().toString()).getTime();
                        }
                    } catch (Exception error){
                        System.out.println(error);
                    }
                    try {
                        startDateField = simpleDateFormat.parse(startDateFinal).getTime();
                    } catch (Exception error){
                        System.out.println(error);
                    }
                    try {
                        finishDateField = simpleDateFormat.parse(finalDateFinal).getTime();
                    } catch (Exception error){
                        System.out.println(error);
                    }

                    int repeat = repeatable.getSelectedItemPosition();



                    switch (repeat){
                        case 0:
                            Event oneDay = new Event();
                            oneDay.title = name;
                            oneDay.type = typeValue;
                            oneDay.location = locationTXT;
                            oneDay.details= desc;
                            oneDay.calendarStart = startDateField;
                            oneDay.calendarFinish=finishDateField;
                            if(alarm1Field != 0L){
                                oneDay.alarm1 = alarm1Field;
                            }
                            if(alarm2Field != 0L){
                                oneDay.alarm2 = alarm2Field;
                            }
                            if(alarm3Field != 0L){
                                oneDay.alarm3 = alarm3Field;
                            }
                            database.EventDao().insert(oneDay);

                            if(alarm1Field != 0L){
                                intent.putExtra("name",name);
                                intent.putExtra("desc",desc);
                                intent.putExtra("vibration", finalVibration);
                                intent.putExtra("soundUri", finalSoundUri);
                                System.out.println("Alarm 1 Field Value: "+alarm1Field);
                                PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);

                                alarmManager.setExact(AlarmManager.RTC_WAKEUP,alarm1Field,pendingIntent);
                            }
                            if(alarm2Field != 0L){
                                intent.putExtra("name",name);
                                intent.putExtra("desc",desc);
                                intent.putExtra("vibration", finalVibration);
                                intent.putExtra("soundUri", finalSoundUri);
                                PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                alarmManager.setExact(AlarmManager.RTC_WAKEUP,alarm2Field,pendingIntent);
                            }
                            if(alarm3Field != 0L){
                                intent.putExtra("name",name);
                                intent.putExtra("desc",desc);
                                intent.putExtra("vibration", finalVibration);
                                intent.putExtra("soundUri", finalSoundUri);
                                PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                alarmManager.setExact(AlarmManager.RTC_WAKEUP,alarm3Field,pendingIntent);
                            }

                            Toast.makeText(getApplicationContext(), "Alarms and Events set.", Toast.LENGTH_LONG).show();


                            break;
                        case 1:
                            for (int t=0;t<366;t++){
                                Event everyDay = new Event();
                                everyDay.title = name;
                                everyDay.type = typeValue;
                                everyDay.location = locationTXT;
                                everyDay.details= desc;
                                everyDay.calendarStart = startDateField + (t*24*60*60*1000L);
                                everyDay.calendarFinish=finishDateField + (t*24*60*60*1000L);
                                if(alarm1Field != 0L){
                                    everyDay.alarm1 = alarm1Field + (t*24*60*60*1000L);
                                } else {
                                    everyDay.alarm1 = 0L;
                                }
                                if(alarm2Field != 0L){
                                    everyDay.alarm2 = alarm2Field + (t*24*60*60*1000L);
                                } else {
                                    everyDay.alarm2 = 0L;
                                }
                                if(alarm3Field != 0L){
                                    everyDay.alarm3 = alarm3Field + (t*24*60*60*1000L);
                                } else {
                                    everyDay.alarm3 = 0L;
                                }
                                database.EventDao().insert(everyDay);

                                if(alarm1Field != 0L){
                                    long varTime = alarm1Field + (t*24*60*60*1000L);
                                    intent.putExtra("name",name);
                                    intent.putExtra("desc",desc);
                                    intent.putExtra("vibration", finalVibration);
                                    intent.putExtra("soundUri", finalSoundUri);
                                    PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                    alarmManager.setExact(AlarmManager.RTC_WAKEUP,varTime,pendingIntent);
                                } else {
                                    everyDay.alarm1 = alarm1Field;
                                }
                                if(alarm2Field != 0L){
                                    long varTime = alarm2Field + (t*24*60*60*1000L);
                                    intent.putExtra("name",name);
                                    intent.putExtra("desc",desc);
                                    intent.putExtra("vibration", finalVibration);
                                    intent.putExtra("soundUri", finalSoundUri);
                                    PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                    alarmManager.setExact(AlarmManager.RTC_WAKEUP,varTime,pendingIntent);
                                } else {
                                    everyDay.alarm2 = alarm2Field;
                                }
                                if(alarm3Field != 0L){
                                    long varTime = alarm3Field + (t*24*60*60*1000L);
                                    intent.putExtra("name",name);
                                    intent.putExtra("desc",desc);
                                    intent.putExtra("vibration", finalVibration);
                                    intent.putExtra("soundUri", finalSoundUri);
                                    PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                    alarmManager.setExact(AlarmManager.RTC_WAKEUP,varTime,pendingIntent);
                                } else {
                                    everyDay.alarm3 = alarm3Field;
                                }

                            }
                            Toast.makeText(getApplicationContext(), "Alarms and Events set for 1 years. Repeat every day.", Toast.LENGTH_LONG).show();

                            break;
                        case 2:
                            for (int t=0;t<52;t++){

                                Event everyWeek = new Event();
                                everyWeek.title = name;
                                everyWeek.type = typeValue;
                                everyWeek.location = locationTXT;
                                everyWeek.details= desc;
                                everyWeek.calendarStart = startDateField + (t*7*24*60*60*1000L);
                                everyWeek.calendarFinish=finishDateField + (t*7*24*60*60*1000L);
                                long amount = (t*7*24*60*60*1000L);

                                if(alarm1Field != 0L){
                                    everyWeek.alarm1 = alarm1Field + amount;
                                } else {
                                    everyWeek.alarm1 = 0L;
                                }
                                if(alarm2Field != 0L){
                                    everyWeek.alarm2 = alarm2Field + amount;
                                } else {
                                    everyWeek.alarm2 = 0L;
                                }
                                if(alarm3Field != 0L){
                                    everyWeek.alarm3 = alarm3Field + amount;
                                } else {
                                    everyWeek.alarm3 = 0L;
                                }

                                database.EventDao().insert(everyWeek);

                                if(alarm1Field != 0L){
                                    long varTime = alarm1Field + amount;
                                    everyWeek.alarm1 = varTime;
                                    intent.putExtra("name",name);
                                    intent.putExtra("desc",desc);
                                    intent.putExtra("vibration", finalVibration);
                                    intent.putExtra("soundUri", finalSoundUri);
                                    PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                    alarmManager.setExact(AlarmManager.RTC_WAKEUP,varTime,pendingIntent);
                                } else {
                                    everyWeek.alarm1 = alarm1Field;
                                }
                                if(alarm2Field != 0L){
                                    long varTime = alarm2Field + amount;
                                    everyWeek.alarm2 = varTime;
                                    intent.putExtra("name",name);
                                    intent.putExtra("desc",desc);
                                    intent.putExtra("vibration", finalVibration);
                                    intent.putExtra("soundUri", finalSoundUri);
                                    PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                    alarmManager.setExact(AlarmManager.RTC_WAKEUP,varTime,pendingIntent);
                                } else {
                                    everyWeek.alarm2 = alarm2Field;
                                }
                                if(alarm3Field != 0L){
                                    long varTime = alarm3Field + amount;
                                    everyWeek.alarm3 = varTime;
                                    intent.putExtra("name",name);
                                    intent.putExtra("desc",desc);
                                    intent.putExtra("vibration", finalVibration);
                                    intent.putExtra("soundUri", finalSoundUri);
                                    PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                    alarmManager.setExact(AlarmManager.RTC_WAKEUP,varTime,pendingIntent);
                                } else {
                                    everyWeek.alarm3 = alarm3Field;
                                }
                            }
                            Toast.makeText(getApplicationContext(), "Alarms and Events set for 1 year. Repeat every week", Toast.LENGTH_LONG).show();
                            break;
                        case 3:
                            for (int t=0;t<12;t++){
                                Event everyMonth = new Event();
                                everyMonth.title = name;
                                everyMonth.type = typeValue;
                                everyMonth.location = locationTXT;
                                everyMonth.details= desc;
                                everyMonth.calendarStart = startDateField + (t*30*24*60*60*1000L);
                                everyMonth.calendarFinish=finishDateField + (t*30*24*60*60*1000L);
                                long amount = (t*30*24*60*60*1000L);

                                if(alarm1Field != 0L){
                                    everyMonth.alarm1 = alarm1Field + amount;
                                } else {
                                    everyMonth.alarm1 = 0L;
                                }
                                if(alarm2Field != 0L){
                                    everyMonth.alarm2 = alarm2Field + amount;
                                } else {
                                    everyMonth.alarm2 = 0L;
                                }
                                if(alarm3Field != 0L){
                                    everyMonth.alarm3 = alarm3Field + amount;
                                } else {
                                    everyMonth.alarm3 = 0L;
                                }

                                database.EventDao().insert(everyMonth);

                                if(alarm1Field != 0L){
                                    long varTime = alarm1Field + amount;
                                    everyMonth.alarm1 = varTime;
                                    intent.putExtra("name",name);
                                    intent.putExtra("desc",desc);
                                    intent.putExtra("vibration", finalVibration);
                                    intent.putExtra("soundUri", finalSoundUri);
                                    PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                    alarmManager.setExact(AlarmManager.RTC_WAKEUP,varTime,pendingIntent);
                                } else {
                                    everyMonth.alarm1 = alarm1Field;
                                }
                                if(alarm2Field != 0L){
                                    long varTime = alarm2Field + amount;
                                    everyMonth.alarm2 = varTime;
                                    intent.putExtra("name",name);
                                    intent.putExtra("desc",desc);
                                    intent.putExtra("vibration", finalVibration);
                                    intent.putExtra("soundUri", finalSoundUri);
                                    PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                    alarmManager.setExact(AlarmManager.RTC_WAKEUP,varTime,pendingIntent);
                                } else {
                                    everyMonth.alarm2 = alarm2Field;
                                }
                                if(alarm3Field != 0L){
                                    long varTime = alarm3Field + amount;
                                    everyMonth.alarm3 = varTime;
                                    intent.putExtra("name",name);
                                    intent.putExtra("desc",desc);
                                    intent.putExtra("vibration", finalVibration);
                                    intent.putExtra("soundUri", finalSoundUri);
                                    PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                    alarmManager.setExact(AlarmManager.RTC_WAKEUP,varTime,pendingIntent);
                                } else {
                                    everyMonth.alarm3 = alarm3Field;
                                }

                            }
                            Toast.makeText(getApplicationContext(), "Alarms and Events set. Repeat every month", Toast.LENGTH_LONG).show();
                            break;
                        case 4:
                            for (int t=0;t<10;t++){
                                Event everyYear = new Event();
                                everyYear.title = name;
                                everyYear.type = typeValue;
                                everyYear.location = locationTXT;
                                everyYear.details= desc;
                                everyYear.calendarStart = startDateField + (t*365*24*60*60*1000L);
                                everyYear.calendarFinish=finishDateField + (t*7*24*60*60*1000L);
                                long amount = (t*365*24*60*60*1000L);

                                if(alarm1Field != 0L){
                                    everyYear.alarm1 = alarm1Field + amount;
                                } else {
                                    everyYear.alarm1 = 0L;
                                }
                                if(alarm2Field != 0L){
                                    everyYear.alarm2 = alarm2Field + amount;
                                } else {
                                    everyYear.alarm2 = 0L;
                                }
                                if(alarm3Field != 0L){
                                    everyYear.alarm3 = alarm3Field + amount;
                                } else {
                                    everyYear.alarm3 = 0L;
                                }

                                database.EventDao().insert(everyYear);

                                if(alarm1Field != 0L){
                                    long varTime = alarm1Field + amount;
                                    everyYear.alarm1 = varTime;
                                    intent.putExtra("name",name);
                                    intent.putExtra("desc",desc);
                                    intent.putExtra("vibration", finalVibration);
                                    intent.putExtra("soundUri", finalSoundUri);
                                    PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                    alarmManager.setExact(AlarmManager.RTC_WAKEUP,varTime,pendingIntent);
                                } else {
                                    everyYear.alarm1 = alarm1Field;
                                }
                                if(alarm2Field != 0L){
                                    long varTime = alarm2Field + amount;
                                    everyYear.alarm2 = varTime;
                                    intent.putExtra("name",name);
                                    intent.putExtra("desc",desc);
                                    intent.putExtra("vibration", finalVibration);
                                    intent.putExtra("soundUri", finalSoundUri);
                                    PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                    alarmManager.setExact(AlarmManager.RTC_WAKEUP,varTime,pendingIntent);
                                } else {
                                    everyYear.alarm2 = alarm2Field;
                                }
                                if(alarm3Field != 0L){
                                    long varTime = alarm3Field + amount;
                                    everyYear.alarm3 = varTime;
                                    intent.putExtra("name",name);
                                    intent.putExtra("desc",desc);
                                    intent.putExtra("vibration", finalVibration);
                                    intent.putExtra("soundUri", finalSoundUri);
                                    PendingIntent pendingIntent = PendingIntent.getBroadcast(addEvent.this,0,intent,0);
                                    alarmManager.setExact(AlarmManager.RTC_WAKEUP,varTime,pendingIntent);
                                } else {
                                    everyYear.alarm3 = alarm3Field;
                                }
                            }
                            Toast.makeText(getApplicationContext(), "Alarms and Events set for 10 years", Toast.LENGTH_LONG).show();
                            break;
                    }
                    Intent menu = new Intent(addEvent.this,MainActivity.class);
                    menu.putExtra("typeMonth",1);
                    startActivity(menu);
                } else {
                    AlertDialog.Builder dialog=new AlertDialog.Builder(addEvent.this);
                    dialog.setMessage("Title, Start and Finish Date can not be blank.");
                    dialog.setTitle("Attention");
                    dialog.setPositiveButton("OK",
                            new DialogInterface.OnClickListener() {
                                public void onClick(DialogInterface dialog,
                                                    int which) {
                                }
                            });

                    AlertDialog alertDialog=dialog.create();
                    alertDialog.show();
                }
            }
        });
    }


    private void createNotificationChannel(){
        if(Build.VERSION.SDK_INT>=Build.VERSION_CODES.O){
            CharSequence name = "Calendar App Channel";
            String description = "Calendar App Alarm";
            int importance = NotificationManager.IMPORTANCE_DEFAULT;
            NotificationChannel channel = new NotificationChannel("notifyCalendarApp",name,importance);
            channel.setDescription(description);

            NotificationManager notificationManager = getSystemService((NotificationManager.class));
            notificationManager.createNotificationChannel(channel);
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        Intent menu = new Intent(addEvent.this,MainActivity.class);

        switch (item.getItemId()) {
            case R.id.action_month:
                menu.putExtra("typeMonth",1);
                startActivity(menu);
                return true;
            case R.id.action_week:
                menu.putExtra("typeMonth",2);
                startActivity(menu);
                return true;
            case R.id.action_day:
                menu.putExtra("typeMonth",3);
                startActivity(menu);
                return true;
            case R.id.action_addEvent:
                return true;
            case R.id.action_setting:
                Intent settings = new Intent(addEvent.this,Settings.class);
                startActivity(settings);
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }

    }
}
