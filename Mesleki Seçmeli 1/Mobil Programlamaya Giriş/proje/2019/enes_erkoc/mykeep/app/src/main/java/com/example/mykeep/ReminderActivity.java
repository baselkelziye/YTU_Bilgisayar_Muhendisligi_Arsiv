package com.example.mykeep;

import android.app.Activity;
import android.app.AlarmManager;
import android.app.DatePickerDialog;
import android.app.PendingIntent;
import android.app.TimePickerDialog;
import android.content.Context;
import android.content.Intent;
import android.support.v4.app.DialogFragment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

import java.text.DateFormat;
import java.util.Calendar;

import com.example.mykeep.calendar.DatePickerFragment;
import com.example.mykeep.calendar.TimePickerFragment;


public class ReminderActivity extends AppCompatActivity implements TimePickerDialog.OnTimeSetListener, DatePickerDialog.OnDateSetListener {

    TextView txtDate, txtTime;
    Button btnSaveReminder;
    LinearLayout dateLayout, timeLayout;
    Calendar c;

    String reminderTitle, reminderContent;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_reminder);

        Bundle extras = getIntent().getExtras();
        reminderTitle = extras.getString("reminderTitle");
        reminderContent = extras.getString("reminderContent");


        getSupportActionBar().setDisplayShowHomeEnabled(true);
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        getSupportActionBar().setTitle(R.string.add_reminder_title);

        txtDate = findViewById(R.id.txt_date);
        txtTime = findViewById(R.id.txt_time);
        dateLayout = findViewById(R.id.date_layout);
        timeLayout = findViewById(R.id.time_layout);
        btnSaveReminder = findViewById(R.id.btn_save_reminder);

        c = Calendar.getInstance();

        txtDate.setText(Integer.toString(c.get(Calendar.DAY_OF_MONTH))+"-"+Integer.toString(c.get(Calendar.MONTH))+"-"+Integer.toString(c.get(Calendar.YEAR)));
        txtTime.setText(Integer.toString(c.get(Calendar.HOUR_OF_DAY))+":"+ Integer.toString(c.get(Calendar.MINUTE)));

        dateLayout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                DialogFragment datePicker = new DatePickerFragment();
                datePicker.show(getSupportFragmentManager(), "date picker");
            }
        });

        timeLayout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                DialogFragment timePicker = new TimePickerFragment();
                timePicker.show(getSupportFragmentManager(), "time picker");
            }
        });

        btnSaveReminder.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startAlarm(c);
                Intent returnIntent = new Intent();
                returnIntent.putExtra("result",txtDate.getText().toString()+" "+txtTime.getText().toString());
                setResult(Activity.RESULT_OK,returnIntent);
                finish();
            }
        });




    }

    @Override
    public void onTimeSet(TimePicker view, int hourOfDay, int minute) {

        c.set(Calendar.HOUR_OF_DAY, hourOfDay);
        c.set(Calendar.MINUTE, minute);
        c.set(Calendar.SECOND, 0);

        updateTimeText(c);

    }

    @Override
    public void onDateSet(DatePicker view, int year, int month, int dayOfMonth) {

        c.set(Calendar.YEAR, year);
        c.set(Calendar.MONTH, month);
        c.set(Calendar.DAY_OF_MONTH, dayOfMonth);

        updateDateText(c);

    }

    private void updateTimeText(Calendar c) {
      txtTime.setText(DateFormat.getTimeInstance(DateFormat.SHORT).format(c.getTime()));

    }

    private void updateDateText(Calendar c) {
        txtDate.setText(DateFormat.getTimeInstance(DateFormat.SHORT).format(c.getTime()));
    }

    private void startAlarm(Calendar c) {
        AlarmManager alarmManager = (AlarmManager) getSystemService(Context.ALARM_SERVICE);
        Intent intent = new Intent(this, AlertReceiver.class);
        intent.putExtra("reminderTitle", reminderTitle);
        intent.putExtra("reminderContent", reminderContent);

        PendingIntent pendingIntent = PendingIntent.getBroadcast(this, 1, intent, PendingIntent.FLAG_UPDATE_CURRENT);

        if (c.before(Calendar.getInstance())) {
            c.add(Calendar.DATE, 1);
        }

        alarmManager.setExact(AlarmManager.RTC_WAKEUP, c.getTimeInMillis(), pendingIntent);
    }

    private void cancelAlarm() {
        AlarmManager alarmManager = (AlarmManager) getSystemService(Context.ALARM_SERVICE);
        Intent intent = new Intent(this, AlertReceiver.class);
        PendingIntent pendingIntent = PendingIntent.getBroadcast(this, 1, intent, 0);

        alarmManager.cancel(pendingIntent);

        Toast.makeText(getApplicationContext(), "Reminder deleted", Toast.LENGTH_LONG).show();

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        getMenuInflater().inflate(R.menu.reminder_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        super.onOptionsItemSelected(item);

        switch (item.getItemId()) {
            case android.R.id.home:
                Toast.makeText(getApplicationContext(), "Reminder discarded", Toast.LENGTH_LONG).show();
                finish();
                break;
        }

        return true;
    }



}
