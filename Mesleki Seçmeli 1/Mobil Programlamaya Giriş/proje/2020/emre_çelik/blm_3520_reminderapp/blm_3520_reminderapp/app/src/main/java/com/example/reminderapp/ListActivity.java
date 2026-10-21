package com.example.reminderapp;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Color;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.material.bottomnavigation.BottomNavigationView;

import java.util.ArrayList;

public class ListActivity extends AppCompatActivity {

    ListView listView;
    ArrayList<Event> events;

    SharedPreferences sharedpreferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list);

        setupBottomNavBar();
        setupView();
        getData();

    }

    void itemClicked(int i) {
//        Toast.makeText(ListActivity.this,"Item Selected " + i,Toast.LENGTH_SHORT).show();
        Intent intent = new Intent(getApplicationContext(), DetailActivity.class);
        System.out.println("Intent " + events.get(i).print());
        intent.putExtra("iID", events.get(i).getId());
        startActivity(intent);
    }

    public void addButtonClicked(View view) {
        startActivity(new Intent(getApplicationContext(), DetailActivity.class));
    }

    private void setupView() {
        listView = findViewById(R.id.listview);
        sharedpreferences = getSharedPreferences("Settings", MODE_PRIVATE);

        boolean darkmode = sharedpreferences.getBoolean("darkmode", false);
        if (darkmode) {
            darkSide();
        }
        else {
            lightSide();
        }
    }

    private void darkSide() {
        listView.setBackgroundColor(Color.DKGRAY);
        View view = findViewById(R.id.listScreen);
        view.setBackgroundColor(Color.DKGRAY);
    }

    private void lightSide() {
        listView.setBackgroundColor(Color.WHITE);
        View view = findViewById(R.id.listScreen);
        view.setBackgroundColor(Color.WHITE);
    }

    private void setupBottomNavBar () {
        BottomNavigationView bottomNavigationView = findViewById(R.id.bottom_navigation);
        bottomNavigationView.setSelectedItemId(R.id.reminders);

        bottomNavigationView.setOnNavigationItemSelectedListener(new BottomNavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem menuItem) {
                switch (menuItem.getItemId()){
                    case R.id.reminders:
                        return true;
                    case R.id.settings:
                        startActivity(new Intent(getApplicationContext(), SettingsActivity.class));
                        overridePendingTransition(0,0);
                        return true;
                }
                return false;
            }
        });
    }

    private void getData(){
        events = getAllEvents();
        ArrayList<String> eventsTitle = new ArrayList<>();
        for (int i = 0; i < events.size(); i++ ){
            eventsTitle.add(events.get(i).getTitle());
        }

        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, eventsTitle){
            @NonNull
            @Override
            public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {

                View view = super.getView(position, convertView, parent);
                TextView text = (TextView) view.findViewById(android.R.id.text1);

                boolean darkmode = sharedpreferences.getBoolean("darkmode", false);
                if (darkmode) {
                    text.setTextColor(Color.WHITE);
                }
                else {
                    text.setTextColor(Color.BLACK);
                }

                return view;
            }
        };
        listView.setAdapter(adapter);

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                itemClicked(position);
            }
        });
    }

    private ArrayList<Event> getAllEvents() {
        ArrayList<Event> eventList = new ArrayList<>();
        try {
            SQLiteDatabase database = this.openOrCreateDatabase("Events", MODE_PRIVATE, null);
            database.execSQL("CREATE TABLE IF NOT EXISTS events (id INTEGER PRIMARY KEY, title VARCHAR, description VARCHAR, startDay VARCHAR, startHour VARCHAR, endDay VARCHAR, endHour VARCHAR, frequence VARCHAR, latitude REAL, longitude REAL)");

            Cursor cursor = database.rawQuery("SELECT * FROM events", null);

            int idIx = cursor.getColumnIndex("id");
            int titleIx = cursor.getColumnIndex("title");
            int descriptionIx = cursor.getColumnIndex("description");
            int startDayIx = cursor.getColumnIndex("startDay");
            int startHourIx = cursor.getColumnIndex("startHour");
            int endDayIx = cursor.getColumnIndex("endDay");
            int endHourIx = cursor.getColumnIndex("endHour");
            int frequenceIx = cursor.getColumnIndex("frequence");
            int latitudeIx = cursor.getColumnIndex("latitude");
            int longitudeIx = cursor.getColumnIndex("longitude");

            while (cursor.moveToNext()) {
                int id = cursor.getInt(idIx);
                String title = cursor.getString(titleIx);
                String description = cursor.getString(descriptionIx);
                String startDay = cursor.getString(startDayIx);
                String startHour = cursor.getString(startHourIx);
                String endDay = cursor.getString(endDayIx);
                String endHour = cursor.getString(endHourIx);
                String frequence = cursor.getString(frequenceIx);
                Double latitude = cursor.getDouble(latitudeIx);
                Double longitude = cursor.getDouble(longitudeIx);
                eventList.add(new Event(id, title, description, startDay, startHour, endDay, endHour, frequence, latitude, longitude));
            }
            cursor.close();

            for (int i = 0; i < eventList.size(); i++ ){
                System.out.println("List: " + eventList.get(i).print());
            }

        }
        catch (Exception e) {
            e.printStackTrace();
        }
        return eventList;
    }

}











