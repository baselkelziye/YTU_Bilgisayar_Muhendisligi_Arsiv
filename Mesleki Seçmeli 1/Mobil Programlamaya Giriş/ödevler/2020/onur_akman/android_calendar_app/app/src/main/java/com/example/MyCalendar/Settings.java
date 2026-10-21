package com.example.MyCalendar;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.app.AppCompatDelegate;

import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.media.MediaPlayer;
import android.media.RingtoneManager;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.Toast;
import android.widget.ToggleButton;

import java.util.ArrayList;
import java.util.List;

public class Settings extends AppCompatActivity {

    private Button HomeButton;
    private Button SettingsButton;
    private Button AddButton;
    private ToggleButton DarkTheme;
    private Button Save;
    private Spinner defRemSpinner;
    private Spinner defRingtone;
    List<String> NameList = new ArrayList<>();

    boolean shouldPlay = false;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);

        getNotifications();
        getXmlItems();

        defRingtone.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                if (shouldPlay) {
                    if (position != 0) {
                        try {
                            playSound(position);
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                } else shouldPlay = true;
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });

        DarkTheme.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (DarkTheme.isChecked())
                    AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES);
                else AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
            }
        });

        Save.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                applyChanges();
                Toast("Applied");
                openSettings();
            }
        });


        HomeButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openHome();
            }
        });
        AddButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openAdd();
            }
        });
        SettingsButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openSettings();
            }
        });

    }

    private void getXmlItems() {
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this, R.array.reminder_options, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        defRemSpinner = findViewById(R.id.defRemSpinner);
        defRemSpinner.setAdapter(adapter);

        ArrayAdapter<String> adapter2 = new ArrayAdapter(Settings.this, android.R.layout.simple_spinner_item, NameList);
        adapter2.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        defRingtone = findViewById(R.id.defRingtone);
        defRingtone.setAdapter(adapter2);

        HomeButton = findViewById(R.id.HomeButton);
        AddButton = findViewById(R.id.AddButton);
        SettingsButton = findViewById(R.id.SettingsButton);
        DarkTheme = findViewById(R.id.DarkModeSettings);
        Save = findViewById(R.id.applyButton);

        if (AppCompatDelegate.getDefaultNightMode() == AppCompatDelegate.MODE_NIGHT_YES)
            DarkTheme.setChecked(true);
        else DarkTheme.setChecked(false);

        SharedPreferences setting0 = this.getSharedPreferences("toneIndex", 0);
        int position = setting0.getInt("toneIndex", 0);
        defRingtone.setSelection(position);

        setting0 = this.getSharedPreferences("defaultReminder", 0);
        position = setting0.getInt("defaultReminder", 0);
        defRemSpinner.setSelection(position);
    }

    public void getNotifications() {
        RingtoneManager manager = new RingtoneManager(this);
        manager.setType(RingtoneManager.TYPE_NOTIFICATION);
        Cursor cursor = manager.getCursor();
        NameList.add("Default");
        while (cursor.moveToNext()) {
            String notificationTitle = cursor.getString(RingtoneManager.TITLE_COLUMN_INDEX);
            //String notificationUri = cursor.getString(RingtoneManager.URI_COLUMN_INDEX) + "/" + cursor.getString(RingtoneManager.ID_COLUMN_INDEX);

            NameList.add(notificationTitle);
            //ringToneUri.add(notificationUri);
        }

    }

    public void playSound(int index) {
        Uri alarmSound = Uri.parse(getSound(index));
        MediaPlayer mp = MediaPlayer.create(getApplicationContext(), alarmSound);
        mp.start();
    }

    private void applyChanges() {
        SharedPreferences setting1 = getSharedPreferences("nightMode", 0);
        SharedPreferences.Editor editor1 = setting1.edit();
        editor1.putBoolean("nightKey", DarkTheme.isChecked());
        editor1.apply();
        setting1 = getSharedPreferences("toneIndex", 0);
        editor1 = setting1.edit();
        editor1.putInt("toneIndex", defRingtone.getSelectedItemPosition());
        editor1.apply();
        setting1 = getSharedPreferences("defaultReminder", 0);
        editor1 = setting1.edit();
        editor1.putInt("defaultReminder", defRemSpinner.getSelectedItemPosition());
        editor1.apply();
    }

    public String getSound(int index) {
        RingtoneManager manager = new RingtoneManager(this);
        manager.setType(RingtoneManager.TYPE_NOTIFICATION);
        Cursor cursor = manager.getCursor();
        String uriString = "";
        while (cursor.moveToNext()) {
            String id = cursor.getString(RingtoneManager.ID_COLUMN_INDEX);
            String uri = cursor.getString(RingtoneManager.URI_COLUMN_INDEX);
            index--;
            if (index == 0) {
                uriString = uri + "/" + id;
                return uriString;
            }
        }
        return uriString;
    }

    public void Toast(String s) {
        Toast.makeText(Settings.this, s, Toast.LENGTH_SHORT).show();
    }

    private void openAdd() {
        Intent intent = new Intent(this, Add.class);
        intent.putExtra("request", 0);
        startActivity(intent);
    }

    private void openSettings() {
        Intent intent = new Intent(this, Settings.class);
        startActivity(intent);
    }

    private void openHome() {
        Intent intent = new Intent(this, MainActivity.class);
        intent.putExtra("request", 0);
        startActivity(intent);
    }
}
