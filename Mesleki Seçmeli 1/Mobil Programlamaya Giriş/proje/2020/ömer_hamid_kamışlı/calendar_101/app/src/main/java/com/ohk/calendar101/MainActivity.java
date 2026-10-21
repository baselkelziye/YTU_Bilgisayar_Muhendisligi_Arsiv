package com.ohk.calendar101;

import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.text.Layout;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.LinearLayout;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import com.desai.vatsal.mydynamiccalendar.EventModel;
import com.desai.vatsal.mydynamiccalendar.GetEventListListener;
import com.desai.vatsal.mydynamiccalendar.MyDynamicCalendar;
import com.desai.vatsal.mydynamiccalendar.OnDateClickListener;
import com.desai.vatsal.mydynamiccalendar.OnEventClickListener;
import com.desai.vatsal.mydynamiccalendar.OnWeekDayViewClickListener;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private Toolbar toolbar;
    private MyDynamicCalendar myCalendar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        SharedPreferences sharedPref =getSharedPreferences("settings",MODE_PRIVATE);
        final RepoDatabase database = RepoDatabase.getInstance(getApplicationContext());

        FloatingActionButton floatingActionButton = (FloatingActionButton) findViewById(R.id.floatingActionButton);
        floatingActionButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent myIntent = new Intent(MainActivity.this, addEvent.class);
                MainActivity.this.startActivity(myIntent);
            }
        });


        toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        myCalendar = (MyDynamicCalendar) findViewById(R.id.myCalendar);
        LinearLayout mainLayout = findViewById(R.id.mainLayout);

        myCalendar.setOnDateClickListener(new OnDateClickListener() {
            @Override
            public void onClick(Date date) {
                Log.e("date", String.valueOf(date));
            }

            @Override
            public void onLongClick(Date date) {
                Log.e("date", String.valueOf(date));
            }
        });

        showMonthViewWithBelowEvents();

        Intent intent = this.getIntent();
        Log.e("intent", intent.toString());
        try {
            if(intent !=null){
                int type = intent.getIntExtra("typeMonth",1);
                if(type == 2){
                    showWeekView();
                } else if (type == 3){
                    showDayView();
                } else {
                    showMonthViewWithBelowEvents();
                }
            }
        } catch (Exception error){
            System.out.println(error);
        }

        if(sharedPref.getBoolean("darkMode",false)){
            mainLayout.setBackgroundColor(Color.parseColor("#192841"));
            myCalendar.setCalendarBackgroundColor("#192841");
            myCalendar.setHeaderBackgroundColor("#ff8c00");
            myCalendar.setHeaderTextColor("#ffffff");
            myCalendar.setWeekDayLayoutTextColor("#ff8c00");
            myCalendar.setExtraDatesOfMonthBackgroundColor(Color.LTGRAY);
            myCalendar.setExtraDatesOfMonthTextColor("#ffffff");
            myCalendar.setDatesOfMonthBackgroundColor(Color.GRAY);
            myCalendar.setDatesOfMonthTextColor(Color.BLUE);
            myCalendar.setCurrentDateBackgroundColor("#ffffff");
            myCalendar.setCurrentDateTextColor(Color.RED);
            myCalendar.setBelowMonthEventTextColor("#ffffff");
            myCalendar.setBelowMonthEventDividerColor("#ff8c00");

        }

        try {
            List<Event> eventsEv = database.EventDao().getAllEvents();
            myCalendar.deleteAllEvent();
            for (Event event : eventsEv) {
                Calendar calendarS = Calendar.getInstance();;
                calendarS.setTimeInMillis(event.calendarStart);

                int yearS = calendarS.get(Calendar.YEAR);
                int monthS = calendarS.get(Calendar.MONTH) + 1; // Note: zero based!
                int dayS = calendarS.get(Calendar.DAY_OF_MONTH);
                int hourS = calendarS.get(Calendar.HOUR_OF_DAY);
                int minuteS = calendarS.get(Calendar.MINUTE);

                Calendar calendarF = Calendar.getInstance();;
                calendarF.setTimeInMillis(event.calendarFinish);

                int hourF = calendarF.get(Calendar.HOUR_OF_DAY);
                int minuteF = calendarF.get(Calendar.MINUTE);

                myCalendar.addEvent(dayS+"-"+monthS+"-"+yearS, hourS+":"+minuteS, hourF+":"+minuteF, event.title);

            }

        } catch (Exception error){
            Log.e("Main Error", String.valueOf(error));
        }

        myCalendar.getEventList(new GetEventListListener() {
            @Override
            public void eventList(ArrayList<EventModel> eventList) {

                Log.e("tag", "eventList.size():-" + eventList.size());
                for (int i = 0; i < eventList.size(); i++) {
                    Log.e("tag", "eventList.getStrName:-" + eventList.get(i).getStrName());
                }

            }
        });


        myCalendar.setHolidayCellClickable(false);
        myCalendar.addHoliday("2-11-2016");
        myCalendar.addHoliday("8-11-2016");
        myCalendar.addHoliday("12-11-2016");
        myCalendar.addHoliday("13-11-2016");
        myCalendar.addHoliday("8-10-2016");
        myCalendar.addHoliday("10-12-2016");

    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {

        switch (item.getItemId()) {
            case R.id.action_month:
                showMonthViewWithBelowEvents();
                return true;
            case R.id.action_week:
                showWeekView();
                return true;
            case R.id.action_day:
                showDayView();
                return true;
            case R.id.action_addEvent:
                Intent addEvent = new Intent(MainActivity.this,addEvent.class);
                startActivity(addEvent);
                return true;
            case R.id.action_setting:
                Intent settings = new Intent(MainActivity.this,Settings.class);
                startActivity(settings);
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }

    }
    

    private void showMonthViewWithBelowEvents() {

        myCalendar.showMonthViewWithBelowEvents();

        myCalendar.setOnDateClickListener(new OnDateClickListener() {
            @Override
            public void onClick(Date date) {
                Log.e("date", String.valueOf(date));
            }

            @Override
            public void onLongClick(Date date) {
                Log.e("date", String.valueOf(date));
            }
        });

    }

    private void showWeekView() {

        myCalendar.showWeekView();

        myCalendar.setOnEventClickListener(new OnEventClickListener() {
            @Override
            public void onClick() {
                Log.e("showWeekView","from setOnEventClickListener onClick");
            }

            @Override
            public void onLongClick() {
                Log.e("showWeekView","from setOnEventClickListener onLongClick");

            }
        });

        myCalendar.setOnWeekDayViewClickListener(new OnWeekDayViewClickListener() {
            @Override
            public void onClick(String date, String time) {
                Intent showEvent = new Intent(MainActivity.this,selectEvent.class);
                showEvent.putExtra("dateS",date + " " + time);
                Log.e("date", date + " " + time);
                startActivity(showEvent);

            }

            @Override
            public void onLongClick(String date, String time) {
                Intent showEvent = new Intent(MainActivity.this,selectEvent.class);
                showEvent.putExtra("dateS",date + " " + time);
                Log.e("date", date + " " + time);
                startActivity(showEvent);

            }
        });


    }

    private void showDayView() {

        myCalendar.showDayView();

        myCalendar.setOnEventClickListener(new OnEventClickListener() {
            @Override
            public void onClick() {
                Log.e("showDayView", "from setOnEventClickListener onClick");

            }

            @Override
            public void onLongClick() {
                Log.e("showDayView", "from setOnEventClickListener onLongClick");

            }
        });

        myCalendar.setOnWeekDayViewClickListener(new OnWeekDayViewClickListener() {
            @Override
            public void onClick(String date, String time) {
                Intent showEvent = new Intent(MainActivity.this,selectEvent.class);
                showEvent.putExtra("dateS",date + " " + time);
                Log.e("date", date + " " + time);
                startActivity(showEvent);
            }

            @Override
            public void onLongClick(String date, String time) {
                Intent showEvent = new Intent(MainActivity.this,selectEvent.class);
                showEvent.putExtra("dateS",date + " " + time);
                Log.e("date", date + " " + time);
                startActivity(showEvent);
            }
        });

    }


}