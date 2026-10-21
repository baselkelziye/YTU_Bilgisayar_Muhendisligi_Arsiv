package com.ohk.calendar101;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
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

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

public class showEvent extends AppCompatActivity {

    Button updateButton;
    Button deleteButton;
    Button shareButton;
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
    int eventID = 0;
    private Toolbar toolbar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_show_event);

        SharedPreferences sharedPref =getSharedPreferences("settings",MODE_PRIVATE);

        toolbar = (Toolbar) findViewById(R.id.toolbar_show_event);
        setSupportActionBar(toolbar);

        shareButton = findViewById(R.id.showEvent_btn_share);
        deleteButton = findViewById(R.id.showEvent_btn_delete);
        updateButton = findViewById(R.id.showEvent_btn_update);
        startDate = findViewById(R.id.showEvent_btn_start_time);
        finishDate = findViewById(R.id.showEvent_btn_finish_time);
        alarm1 = findViewById(R.id.showEvent_btn_alarm1);
        alarm2 = findViewById(R.id.showEvent_btn_alarm2);
        alarm3 = findViewById(R.id.showEvent_btn_alarm3);
        alarm1TXT = findViewById(R.id.showEvent_txt_alarm1);
        alarm2TXT = findViewById(R.id.showEvent_txt_alarm2);
        alarm3TXT = findViewById(R.id.showEvent_txt_alarm3);
        startDateTXT = findViewById(R.id.showEvent_txt_start_time);
        finishDateTXT = findViewById(R.id.showEvent_txt_finish_time);
        eventName = findViewById(R.id.showEvent_name);
        description = findViewById(R.id.showEvent_description);
        location = findViewById(R.id.showEvent_location);
        LinearLayout layout = findViewById(R.id.showEvent_layout);

        final Spinner type = findViewById(R.id.showEvent_Type);
        String[] items = new String[]{"Event Type","Personal","Birthday", "Meeting", "Assigment"};
        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_dropdown_item, items);
        type.setAdapter(adapter);


        if(sharedPref.getBoolean("darkMode",false)){

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

        Intent intent = this.getIntent();
        eventID = intent.getIntExtra("idS",0);
        Log.e("showEvent", String.valueOf(eventID));
        final RepoDatabase database = RepoDatabase.getInstance(getApplicationContext());
        final Event e = database.EventDao().selectEvent(eventID);
        Log.e("Event:",e.toString());

        try {
            alarm1TXT.setText(convertDateString(e.alarm1));
            alarm2TXT.setText(convertDateString(e.alarm2));
            alarm3TXT.setText(convertDateString(e.alarm3));
        }catch (Exception error){

        }
        try {
            startDateTXT.setText(convertDateString(e.calendarStart));

        } catch (Exception error){
            Intent menu = new Intent(showEvent.this,MainActivity.class);
            menu.putExtra("typeMonth",1);
            startActivity(menu);
        }
        try {
            finishDateTXT.setText(convertDateString(e.calendarFinish));

        } catch (Exception error){
            Intent menu = new Intent(showEvent.this,MainActivity.class);
            menu.putExtra("typeMonth",1);
            startActivity(menu);
        }

        eventName.setText(e.title);
        description.setText(e.details);
        location.setText(e.location);
        type.setSelection(e.type);

        updateButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                Event updateEvent = e;
                try {
                    updateEvent.alarm1 = convertStringtoDate((String) alarm1TXT.getText());
                    updateEvent.alarm2 = convertStringtoDate((String) alarm2TXT.getText());
                    updateEvent.alarm3 = convertStringtoDate((String) alarm3TXT.getText());
                } catch (ParseException ex) {
                    ex.printStackTrace();
                }
                try {
                    updateEvent.calendarStart = convertStringtoDate((String) startDateTXT.getText());
                } catch (ParseException ex) {
                    ex.printStackTrace();
                }
                try {
                    updateEvent.calendarFinish = convertStringtoDate((String) finishDateTXT.getText());
                } catch (ParseException ex) {
                    ex.printStackTrace();
                }
                updateEvent.title = eventName.getText().toString();
                updateEvent.details = description.getText().toString();
                updateEvent.type = type.getSelectedItemPosition();

                database.EventDao().update(updateEvent);

                Toast.makeText(getApplicationContext(), "Event updated", Toast.LENGTH_LONG).show();
                Intent menu = new Intent(showEvent.this,MainActivity.class);
                menu.putExtra("typeMonth",1);
                startActivity(menu);

            }
        }
        );

        deleteButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                database.EventDao().delete(e);

                Toast.makeText(getApplicationContext(), "Event Deleted", Toast.LENGTH_LONG).show();
                Intent menu = new Intent(showEvent.this,MainActivity.class);
                menu.putExtra("typeMonth",1);
                startActivity(menu);
            }
        }
        );

        shareButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                Intent shareIntent = new Intent(Intent.ACTION_SEND);
                shareIntent.setType("text/plain");
                shareIntent.putExtra(Intent.EXTRA_SUBJECT,"Calendar 101");
                shareIntent.putExtra(Intent.EXTRA_TEXT,e.ShareToString());
                startActivity(Intent.createChooser(shareIntent,"Share via"));
            }
        }
        );
    }

    public String convertDateString(long val){
        Date date=new Date(val);
        SimpleDateFormat df2 = new SimpleDateFormat("dd-MM-yyyy HH:mm");;
        String dateText = df2.format(date);
        return dateText;
    }
    public long convertStringtoDate(String val) throws ParseException {
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("dd-MM-yyyy HH:mm");
        long date = simpleDateFormat.parse(alarm1TXT.getText().toString()).getTime();
        return date;
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        Intent menu = new Intent(showEvent.this,MainActivity.class);

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
                Intent addEvent = new Intent(showEvent.this,addEvent.class);
                startActivity(addEvent);
                return true;
            case R.id.action_setting:
                Intent settings = new Intent(showEvent.this,Settings.class);
                startActivity(settings);
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }

    }
}
