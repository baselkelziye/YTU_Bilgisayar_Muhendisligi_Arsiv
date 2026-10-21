package com.example.reminderapp;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.app.AlarmManager;
import android.app.DatePickerDialog;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.TimePickerDialog;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Color;
import android.media.AudioAttributes;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

import com.google.android.gms.common.GooglePlayServicesNotAvailableException;
import com.google.android.gms.common.GooglePlayServicesRepairableException;
import com.google.android.gms.location.places.Place;
import com.google.android.gms.location.places.ui.PlacePicker;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.Locale;

public class DetailActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {

    private TextView titleTextView;
    private TextView descriptionTextView;
    private TextView startTimeDayTextView;
    private TextView startTimeHourTextView;
    private TextView endTimeDayTextView;
    private TextView endTimeHourTextView;
    private TextView locationTextView;
    private Button addOrUpdateButton;
    private Button deleteButton;
    private Button shareButton;

    private Spinner frequencySpinner;

    int PLACE_PICKER_REQUEST = 1;
    Calendar calendar;
    DatePickerDialog datePickerDialog;
    TimePickerDialog timePickerDialog;
    String[] frequencyArray = {"Day", "Week", "Month", "Year"};
    Boolean isComingFromIntent = false;

    Event event;
    SharedPreferences sharedpreferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_detail);


        setupView();
        checkIncomingIntent();
    }

    private void setupView() {
        calendar = Calendar.getInstance();
        sharedpreferences = getSharedPreferences("Settings", MODE_PRIVATE);

        titleTextView = findViewById(R.id.titleTextView);
        descriptionTextView = findViewById(R.id.descriptionTextView);
        startTimeDayTextView = findViewById(R.id.startTimeDayTextView);
        startTimeHourTextView = findViewById(R.id.startTimeHourTextView);
        endTimeDayTextView = findViewById(R.id.endTimeDayTextView);
        endTimeHourTextView = findViewById(R.id.endTimeHourTextView);
        locationTextView = findViewById(R.id.locationTextView);
        addOrUpdateButton = findViewById(R.id.addOrUpdateButton);
        deleteButton = findViewById(R.id.deleteButton);
        shareButton = findViewById(R.id.shareButton);

        // Spinner
        frequencySpinner = findViewById(R.id.frequencySpinner);
        frequencySpinner.setOnItemSelectedListener(this);
        ArrayAdapter adapter = new ArrayAdapter(this,android.R.layout.simple_spinner_item, frequencyArray){
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
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        frequencySpinner.setAdapter(adapter);

        boolean darkmode = sharedpreferences.getBoolean("darkmode", false);
        if (darkmode) {
            darkSide();
        }
        else {
            lightSide();
        }
    }

    private void darkSide() {
        View view = findViewById(R.id.detailScreen);
        view.setBackgroundColor(Color.DKGRAY);

        titleTextView.setTextColor(Color.WHITE);
        descriptionTextView.setTextColor(Color.WHITE);
        startTimeDayTextView.setTextColor(Color.WHITE);
        startTimeHourTextView.setTextColor(Color.WHITE);
        endTimeDayTextView.setTextColor(Color.WHITE);
        endTimeHourTextView.setTextColor(Color.WHITE);
        locationTextView.setTextColor(Color.WHITE);
    }

    private void lightSide() {
        View view = findViewById(R.id.detailScreen);
        view.setBackgroundColor(Color.WHITE);

        titleTextView.setTextColor(Color.BLACK);
        descriptionTextView.setTextColor(Color.BLACK);
        startTimeDayTextView.setTextColor(Color.BLACK);
        startTimeHourTextView.setTextColor(Color.BLACK);
        endTimeDayTextView.setTextColor(Color.BLACK);
        endTimeHourTextView.setTextColor(Color.BLACK);
        locationTextView.setTextColor(Color.BLACK);
    }

    private void checkIncomingIntent() {
        Intent intent = getIntent();
        Bundle data = getIntent().getExtras();
        if (intent != null && data != null) {
            isComingFromIntent = true;
            int id = intent.getIntExtra("iID", -1);
            if (id == -1) {
                event = new Event();
                event.setTitle("");
                event.setDescription("");
                event.setLatitude(0.00);
                event.setLongitude(0.00);
                return;
            }
            ArrayList<Event> eventList = getAllEvents();
            for (int i = 0; i < eventList.size(); i++) {
                if (eventList.get(i).getId() == id) {
                    event = eventList.get(i);
                    titleTextView.setText(event.getTitle());
                    descriptionTextView.setText(event.getDescription());
                    startTimeDayTextView.setText(event.getStartDay());
                    startTimeHourTextView.setText(event.getStartHour());
                    endTimeDayTextView.setText(event.getEndDay());
                    endTimeHourTextView.setText(event.getEndHour());
                    locationTextView.setText(event.getLatitude() + ", " + event.getLongitude());
                    addOrUpdateButton.setText("Update");
                }
            }
        }
        else {
            event = new Event();
            event.setTitle("");
            event.setDescription("");
            event.setLatitude(0.00);
            event.setLongitude(0.00);

            ViewGroup layout = (ViewGroup) locationTextView.getParent();
            if (layout != null) {
                layout.removeView(deleteButton);
                layout.removeView(shareButton);
            }
        }
    }

    public void startTimeDayClick(View view) {
        datePickerDialog = new DatePickerDialog(DetailActivity.this, new DatePickerDialog.OnDateSetListener() {
            @Override
            public void onDateSet(DatePicker view, int year, int month, int dayOfMonth) {
                startTimeDayTextView.setText(dayOfMonth + "/" + month + "/" + year);
                event.setStartDay(dayOfMonth + "/" + month + "/" + year);
            }
        }, calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH), calendar.get(Calendar.DAY_OF_MONTH));
        datePickerDialog.show();
    }

    public void startTimeHourClick(View view) {
        timePickerDialog = new TimePickerDialog(DetailActivity.this, new TimePickerDialog.OnTimeSetListener() {
            @Override
            public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
                startTimeHourTextView.setText(hourOfDay + ":" + minute);
                event.setStartHour(hourOfDay + ":" + minute);
            }
        }, calendar.get(Calendar.HOUR_OF_DAY), calendar.get(Calendar.MINUTE), true);
        timePickerDialog.show();
    }

    public void endTimeDayClick(View view) {
        datePickerDialog = new DatePickerDialog(DetailActivity.this, new DatePickerDialog.OnDateSetListener() {
            @Override
            public void onDateSet(DatePicker view, int year, int month, int dayOfMonth) {
                endTimeDayTextView.setText(dayOfMonth + "/" + month + "/" + year);
                event.setEndDay(dayOfMonth + "/" + month + "/" + year);
            }
        }, calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH), calendar.get(Calendar.DAY_OF_MONTH));
        datePickerDialog.show();
    }

    public void endTimeHourClick(View view) {
        timePickerDialog = new TimePickerDialog(DetailActivity.this, new TimePickerDialog.OnTimeSetListener() {
            @Override
            public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
                endTimeHourTextView.setText(hourOfDay + ":" + minute);
                event.setEndHour(hourOfDay + ":" + minute);
            }
        }, calendar.get(Calendar.HOUR_OF_DAY), calendar.get(Calendar.MINUTE), true);
        timePickerDialog.show();
    }

    public void selectLocationClicked(View view) {
        PlacePicker.IntentBuilder builder = new PlacePicker.IntentBuilder();
        try {
            startActivityForResult(builder.build(DetailActivity.this), PLACE_PICKER_REQUEST);
        } catch (GooglePlayServicesRepairableException e) {
            e.printStackTrace();
        } catch (GooglePlayServicesNotAvailableException e) {
            e.printStackTrace();
        }
    }

    public void shareButtonClicked(View view) {
        String title = event.getTitle();
        String content = event.getDescription() + " - " + event.getStartDay() + " " + event.getStartHour() + "  /  " + event.getEndDay() + " " + event.getEndHour();

        Intent intent = new Intent(Intent.ACTION_SEND);
        intent.setType("plain/text");
        intent.putExtra(Intent.EXTRA_SUBJECT, title);
        intent.putExtra(Intent.EXTRA_TEXT, content);
        startActivity(Intent.createChooser(intent, ""));
    }

    public void addUpdateClicked(View view) {
        String title = titleTextView.getText().toString();
        String description = descriptionTextView.getText().toString();
        String frequency = frequencySpinner.getSelectedItem().toString();

        event.setTitle(title);
        event.setDescription(description);
        event.setFrequence(frequency);

        if (event.getStartDay() == "" || event.getStartHour() == "" || event.getEndDay() == "" || event.getEndHour() == "") {
            Toast.makeText(getApplicationContext(),"Set Time Correctly Pls",Toast.LENGTH_SHORT).show();
            return;
        }
        createNotificationChannel(event.getTitle());
        createAlarm();
        if (isComingFromIntent) {
            updateEvent();
        }
        else {
            createEvent();
        }

    }

    public void deleteClicked(View view){
        deleteUser();
    }

    private void createAlarm() {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm", Locale.ENGLISH);
        Calendar cal = sdf.getCalendar();
        try {
            Date date = sdf.parse(event.getStartDay() + " " + event.getStartHour());
            cal.setTime(date);
        } catch (ParseException e) {
            e.printStackTrace();
            return;
        }

        Intent intent = new Intent(DetailActivity.this, ReminderBroadcast.class);
        PendingIntent pendingIntent = PendingIntent.getBroadcast(DetailActivity.this, 0, intent, 0);
        AlarmManager alarmManager = (AlarmManager) getSystemService(ALARM_SERVICE);

        switch (event.getFrequence()){
            case "Day":
                alarmManager.setRepeating(AlarmManager.RTC_WAKEUP,
                    cal.getTimeInMillis() - System.currentTimeMillis(),
                    daySeconds(),
                    pendingIntent);
                break;
            case "Week":
                alarmManager.setRepeating(AlarmManager.RTC_WAKEUP,
                    cal.getTimeInMillis() - System.currentTimeMillis(),
                    weekSeconds(),
                    pendingIntent);
                break;
            case "Month":
                alarmManager.setRepeating(AlarmManager.RTC_WAKEUP,
                    cal.getTimeInMillis() - System.currentTimeMillis(),
                    monthSeconds(),
                    pendingIntent);
                break;
            case "Year":
                alarmManager.setRepeating(AlarmManager.RTC_WAKEUP,
                    cal.getTimeInMillis() - System.currentTimeMillis(),
                    yearSeconds(),
                    pendingIntent);
                break;
            default:
                alarmManager.setRepeating(AlarmManager.RTC_WAKEUP,
                    cal.getTimeInMillis() - System.currentTimeMillis(),
                    daySeconds(),
                    pendingIntent);
        }


    }

    private void createNotificationChannel(String title){

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            CharSequence name = title;
            String description = "Description";
            int importance = NotificationManager.IMPORTANCE_DEFAULT;
            NotificationChannel channel = new NotificationChannel("notify", name, importance);
            channel.setDescription(description);

            AudioAttributes audioAttributes = new AudioAttributes.Builder()
                    .setContentType(AudioAttributes.CONTENT_TYPE_SONIFICATION)
                    .setUsage(AudioAttributes.USAGE_NOTIFICATION)
                    .build();
            // Setup Sound
            channel.setSound(Uri.parse("android.resource://" + "com.example.reminderapp" + "/" + R.raw.hasty_ba_dum_tss), audioAttributes);

            NotificationManager notificationManager = getSystemService(NotificationManager.class);
            notificationManager.createNotificationChannel(channel);

        }

    }

    private void createEvent() {
        try {
            SQLiteDatabase database = this.openOrCreateDatabase("Events", MODE_PRIVATE, null);
            database.execSQL("CREATE TABLE IF NOT EXISTS events (id INTEGER PRIMARY KEY, title VARCHAR, description VARCHAR, startDay VARCHAR, startHour VARCHAR, endDay VARCHAR, endHour VARCHAR, frequence VARCHAR, latitude REAL, longitude REAL)");
            database.execSQL("INSERT INTO events (title, description, startDay, startHour, endDay, endHour, frequence, latitude, longitude) VALUES ('" + event.getTitle() + "','" + event.getDescription() + "','" + event.getStartDay() + "','" + event.getStartHour() + "','" + event.getEndDay() + "','" + event.getEndHour() + "','" + event.getFrequence() + "','" + event.getLatitude() + "','" + event.getLongitude() + "')");
        }
        catch (Exception e) {
            Toast.makeText(getApplicationContext(),"Something Happened -__-",Toast.LENGTH_SHORT).show();
            e.printStackTrace();
        }
        Toast.makeText(getApplicationContext(),"Added Successfully",Toast.LENGTH_SHORT).show();
    }

    private void deleteUser() {
        try {
            SQLiteDatabase database = this.openOrCreateDatabase("Events", MODE_PRIVATE, null);
            database.execSQL("CREATE TABLE IF NOT EXISTS events (id INTEGER PRIMARY KEY, title VARCHAR, description VARCHAR, startDay VARCHAR, startHour VARCHAR, endDay VARCHAR, endHour VARCHAR, frequence VARCHAR, latitude REAL, longitude REAL)");
            database.execSQL("DELETE FROM events WHERE id = " + event.getId());
        }
        catch (Exception e) {
            Toast.makeText(getApplicationContext(),"Something Happened -__-",Toast.LENGTH_SHORT).show();
            e.printStackTrace();
        }
        Toast.makeText(getApplicationContext(),"Deleted Successfully",Toast.LENGTH_SHORT).show();
    }

    private void updateEvent() {
        try {
            SQLiteDatabase database = this.openOrCreateDatabase("Events", MODE_PRIVATE, null);
            database.execSQL("CREATE TABLE IF NOT EXISTS events (id INTEGER PRIMARY KEY, title VARCHAR, description VARCHAR, startDay VARCHAR, startHour VARCHAR, endDay VARCHAR, endHour VARCHAR, frequence VARCHAR, latitude REAL, longitude REAL)");
            database.execSQL("UPDATE events SET title = '" + event.getTitle() + "', description = '" + event.getDescription() + "', startDay = '" + event.getStartDay() + "' ,startHour = '" + event.getStartHour() + "' ,endDay = '" + event.getEndDay() + "' ,endHour = '" + event.getEndHour() + "' ,frequence = '" + event.getFrequence() + "' ,latitude = '" + event.getLatitude() + "' ,longitude = '" + event.getLongitude() + "' WHERE id = '" + event.getId() + "'");
        }
        catch (Exception e) {
            Toast.makeText(getApplicationContext(),"Something Happened -__-",Toast.LENGTH_SHORT).show();
            e.printStackTrace();
        }
        Toast.makeText(getApplicationContext(),"Updated Successfully",Toast.LENGTH_SHORT).show();
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
            System.out.println(event.print());
        }
        catch (Exception e) {
            e.printStackTrace();
        }
        return eventList;
    }

    // Google Maps
    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        if (requestCode == PLACE_PICKER_REQUEST) {
            if (resultCode == RESULT_OK) {
                Place place = PlacePicker.getPlace(this, data);

                String latitude = String.valueOf(place.getLatLng().latitude);
                String longitude = String.valueOf(place.getLatLng().longitude);
                event.setLatitude(new Double(latitude));
                event.setLongitude(new Double(longitude));
                locationTextView.setText(latitude + " , " + longitude);
            }
        }
    }

    // Frequency Adapter Funcs
    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        if (parent.getId() == R.id.frequencySpinner) {
            String spinnerValue = parent.getItemAtPosition(position).toString();
            if (event != null) {
                event.setFrequence(spinnerValue);
            }
        }
    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {

    }

    // DateTime Things
    private int daySeconds() {
        return 1000 * 60 * 60 * 24;
    }

    private int weekSeconds() {
        return 1000 * 60 * 60 * 24 * 7;
    }

    private int monthSeconds() {
        return 1000 * 60 * 60 * 24 * 30;
    }

    private int yearSeconds() {
        return 1000 * 60 * 60 * 24 * 365;
    }
}
