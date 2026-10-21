package com.ohk.calendar101;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.Spinner;
import android.widget.TextView;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class selectEvent extends AppCompatActivity {

    private Toolbar toolbar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_select_event);

        toolbar = (Toolbar) findViewById(R.id.toolbar_select_event);
        setSupportActionBar(toolbar);
        Button selectButton = findViewById(R.id.selectEvent_Select);
        LinearLayout layout = findViewById(R.id.selectEvent_layout);
        TextView txt = findViewById(R.id.selectEvent_textView);
        final Spinner selecter = findViewById(R.id.selectEvent_spinner);


        SharedPreferences sharedPref =getSharedPreferences("settings",MODE_PRIVATE);
        if(sharedPref.getBoolean("darkMode",false)){
            txt.setTextColor(Color.parseColor("#FFFFFF"));
            layout.setBackgroundColor(Color.parseColor("#192841"));
        }

        ArrayList<String> items = new ArrayList<>();
        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_dropdown_item, items);

        Intent intent = this.getIntent();
        String dateString = intent.getStringExtra("dateS");
        final RepoDatabase database = RepoDatabase.getInstance(getApplicationContext());
        Calendar cal = Calendar.getInstance();
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("dd-MM-yyyy hh:mm");
        try {
            cal.setTime(simpleDateFormat.parse(dateString));// all done
        } catch (ParseException e) {
            e.printStackTrace();
        }
        final List<Event> e = database.EventDao().getEvent(cal.getTimeInMillis(),cal.getTimeInMillis() +(1*60*60*1000L));
        if(e.size() == 0){
            Intent menu = new Intent(selectEvent.this,MainActivity.class);
            menu.putExtra("typeMonth",2);
            startActivity(menu);
        }
        for(Event b:e){
            items.add(b.title);
        }

        selecter.setAdapter(adapter);

        selectButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                Intent showEvent = new Intent(selectEvent.this,showEvent.class);
                showEvent.putExtra("idS",e.get(selecter.getSelectedItemPosition()).id);
                Log.e("Select Event Id: ", String.valueOf(e.get(selecter.getSelectedItemPosition()).id));
                startActivity(showEvent);
            }
        }
        );

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        Intent menu = new Intent(selectEvent.this,MainActivity.class);

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
                Intent addEvent = new Intent(selectEvent.this,addEvent.class);
                startActivity(addEvent);
                return true;
            case R.id.action_setting:
                Intent settings = new Intent(selectEvent.this,Settings.class);
                startActivity(settings);
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }

    }
}
