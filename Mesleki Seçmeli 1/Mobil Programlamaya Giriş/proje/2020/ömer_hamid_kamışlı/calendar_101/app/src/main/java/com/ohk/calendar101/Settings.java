package com.ohk.calendar101;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.graphics.Color;
import android.media.RingtoneManager;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.LinearLayout;
import android.widget.Spinner;
import android.widget.Switch;

import java.util.ArrayList;
import java.util.Set;

public class Settings extends AppCompatActivity {

    private Toolbar toolbar;
    private String chosenRingtone;
    ArrayList<String> soundsNames = new ArrayList<>();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);


        toolbar = (Toolbar) findViewById(R.id.toolbar_settings);
        setSupportActionBar(toolbar);

        Button save = findViewById(R.id.settings_btn_save);
        final Switch darkMode = findViewById(R.id.settings_btn_darkMode);
        final CheckBox vibration = findViewById(R.id.settings_cb_vibration);
        final Spinner type = findViewById(R.id.settings_spinner_type);
        final Spinner repeat = findViewById(R.id.settings_spinner_repeatable);
        final Spinner soundSpinner = findViewById(R.id.settings_spinner_sounds);
        LinearLayout layout = findViewById(R.id.settings_layout);

        String[] items = new String[]{"Event Type","Personal","Birthday", "Meeting", "Assigment"};
        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_dropdown_item, items);
        type.setAdapter(adapter);

        String[] items2 = new String[]{"Repatable","Everyday","Every Week", "Every Month", "Every Year"};
        ArrayAdapter<String> adapter2 = new ArrayAdapter<>(this, android.R.layout.simple_spinner_dropdown_item, items2);
        repeat.setAdapter(adapter2);

        final ArrayList<String> sounds = getNotificationSounds();

        ArrayAdapter<String> adapter3 = new ArrayAdapter<>(this, android.R.layout.simple_spinner_dropdown_item, soundsNames);
        soundSpinner.setAdapter(adapter3);
        final SharedPreferences settings =getSharedPreferences("settings",MODE_PRIVATE);

        try {
            darkMode.setChecked(settings.getBoolean("darkMode",false));
            vibration.setChecked(settings.getBoolean("vibration",true));
            type.setSelection(settings.getInt("type",0));
            repeat.setSelection(settings.getInt("repeat",0));
        } catch (Exception error){
            System.out.println(error);
        }
        if(darkMode.isChecked() == true){
            System.out.println("Dark mod seçili");
            layout.setBackgroundColor(Color.parseColor("#192841"));
            save.setTextColor(Color.parseColor("#FFFFFF"));
            darkMode.setTextColor(Color.parseColor("#FFFFFF"));
            vibration.setTextColor(Color.parseColor("#FFFFFF"));

        }


        save.setOnClickListener( new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                SharedPreferences.Editor editor = settings.edit();
                editor.putBoolean("darkMode",darkMode.isChecked());
                editor.putBoolean("vibration",vibration.isChecked());
                editor.putInt("type",type.getSelectedItemPosition());
                editor.putInt("repeat",repeat.getSelectedItemPosition());
                editor.putString("soundUri",sounds.get(soundSpinner.getSelectedItemPosition()));
                editor.commit();

                Intent main = new Intent(Settings.this,MainActivity.class);
                startActivity(main);
            }


        });
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        Intent menu = new Intent(Settings.this,MainActivity.class);

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
                Intent addEvent = new Intent(Settings.this,addEvent.class);
                startActivity(addEvent);
                return true;
            case R.id.action_setting:
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }

    }

    public ArrayList<String> getNotificationSounds() {
        RingtoneManager manager = new RingtoneManager(this);
        manager.setType(RingtoneManager.TYPE_NOTIFICATION);
        Cursor cursor = manager.getCursor();

        ArrayList<String> list = new ArrayList<>();
        while (cursor.moveToNext()) {
            String id = cursor.getString(RingtoneManager.ID_COLUMN_INDEX);
            String uri = cursor.getString(RingtoneManager.URI_COLUMN_INDEX);
            soundsNames.add(cursor.getString(RingtoneManager.TITLE_COLUMN_INDEX));

            list.add(uri + "/" + id);
        }

        return list;
    }

}

