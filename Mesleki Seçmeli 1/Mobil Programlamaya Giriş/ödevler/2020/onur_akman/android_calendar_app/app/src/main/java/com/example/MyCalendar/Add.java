package com.example.MyCalendar;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TimePicker;
import android.widget.Toast;
import android.widget.ToggleButton;

import java.sql.Date;
import java.util.ArrayList;
import java.util.Calendar;

public class Add extends AppCompatActivity {

    private Button HomeButton;
    private Button SettingsButton;
    private Button AddButton;
    private EditText NameInput;
    private EditText DetailInput;
    private DatePicker DateInput;
    private TimePicker StartingInput;
    private TimePicker EndingInput;
    private Button AddLocationInput;
    private EditText AddressInput;
    private ToggleButton NotTypeInput;
    private ToggleButton SoundInput;
    private Button AddReminderInput;
    private Button SaveButton;
    private Spinner RepeatInput;

    private ArrayList<Spinner> spinners = new ArrayList<>();

    private int id;
    private String name;
    private String detail;
    private int day;
    private int dofweek;
    private int month;
    private int year;
    private int starthr;
    private int startmin;
    private int endhr;
    private int endmin;
    private int repeat;
    private String address;
    private boolean notWithTone;
    private boolean notWithAlarm;
    private int rem1;
    private int rem2;
    private int rem3;

    private int updateMode;
    private int clickCount = -1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add);

        getXmlItems();

        updateMode = 0;
        getRequest();
        if (updateMode == 1) setUpdates(); //if we are here for updating an event
        else if (updateMode == -1)
            DateInput.updateDate(year, month, day); //if we came here from the home page


        AddLocationInput.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AddressInput.setEnabled(true);
            }
        });

        AddReminderInput.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                clickCount++;
                if (clickCount < 3) spinners.get(clickCount).setEnabled(true);
                else Toast("All reminders are set.");
            }
        });
        NotTypeInput.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (NotTypeInput.isChecked()) {
                    SoundInput.setChecked(false);
                    SoundInput.setEnabled(false);
                } else {
                    SoundInput.setEnabled(true);
                }
            }
        });
        spinners.get(0).setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                if (position == 0) {
                    spinners.get(1).setSelection(0); //you cant add a second reminder if you set the first one as none
                    spinners.get(2).setSelection(0);
                    spinners.get(1).setEnabled(false);
                    spinners.get(2).setEnabled(false);
                    NotTypeInput.setChecked(false);
                    NotTypeInput.setEnabled(false);
                    SoundInput.setChecked(false);
                    SoundInput.setEnabled(false);
                    spinners.get(0).setEnabled(false);
                    clickCount = -1;
                } else {
                    NotTypeInput.setEnabled(true);
                    SoundInput.setEnabled(true);
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
        spinners.get(1).setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                if (spinners.get(1).isEnabled()) {
                    if (position == 0) {
                        spinners.get(2).setSelection(0);
                        spinners.get(1).setEnabled(false);
                        spinners.get(2).setEnabled(false);
                        clickCount = 0;
                    }
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
        spinners.get(2).setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                if (spinners.get(1).isEnabled()) {
                    if (position == 0) {
                        spinners.get(2).setEnabled(false);
                        clickCount = 1;
                    }
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });

        SaveButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if ((StartingInput.getHour() > EndingInput.getHour()) //exceptions
                        || ((StartingInput.getHour() == EndingInput.getHour()) && (StartingInput.getMinute() > EndingInput.getMinute()))) {
                    Toast("Starting and ending time are not compatible.");
                } else if (NameInput.getText().toString().compareTo("") == 0) {
                    Toast("Name cannot be blank.");
                } else { //all good
                    gatherData();
                    sendRequest();
                }
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

    private void getRequest() {
        try {
            Intent intent = this.getIntent();
            if (intent != null) {
                int request = intent.getExtras().getInt("request"); //why are we here
                if (request == 3) { //for updating an event
                    updateMode = 1;
                    id = intent.getExtras().getInt("id");
                    name = intent.getExtras().getString("name");
                    detail = intent.getExtras().getString("detail");
                    day = intent.getExtras().getInt("day");
                    dofweek = intent.getExtras().getInt("dofweek");
                    month = intent.getExtras().getInt("month");
                    year = intent.getExtras().getInt("year");
                    starthr = intent.getExtras().getInt("starthr");
                    startmin = intent.getExtras().getInt("startmin");
                    endhr = intent.getExtras().getInt("endhr");
                    endmin = intent.getExtras().getInt("endmin");
                    repeat = intent.getExtras().getInt("repeat");
                    address = intent.getExtras().getString("address");
                    notWithTone = intent.getExtras().getBoolean("notWithTone");
                    notWithAlarm = intent.getExtras().getBoolean("notWithAlarm");
                    rem1 = intent.getExtras().getInt("reminder1");
                    rem2 = intent.getExtras().getInt("reminder2");
                    rem3 = intent.getExtras().getInt("reminder3");
                } else if (request == -1) { //for adding an event and we came from the home, we have a date value
                    updateMode = -1;
                    day = intent.getExtras().getInt("cDay");
                    month = intent.getExtras().getInt("cMonth");
                    year = intent.getExtras().getInt("cYear");
                } else if (request == 0) { //for adding but from somwhere else
                    updateMode = 0;
                } else {
                    Toast.makeText(getApplicationContext(), "This request cannot be handled.", Toast.LENGTH_SHORT).show();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void setUpdates() { //if we're updating, fill the elements with data
        NameInput.setText(name);
        DetailInput.setText(detail);
        DateInput.updateDate(year, month, day);
        StartingInput.setHour(starthr);
        StartingInput.setMinute(startmin);
        EndingInput.setHour(endhr);
        EndingInput.setMinute(endmin);
        RepeatInput.setSelection(repeat);
        AddressInput.setText(address);
        if (address != null) AddressInput.setEnabled(true);
        if (rem1 != 0) {
            clickCount++;
            NotTypeInput.setChecked(notWithAlarm);
            NotTypeInput.setEnabled(true);
            SoundInput.setChecked(notWithTone);
            SoundInput.setEnabled(true);
            spinners.get(0).setSelection(rem1);
            spinners.get(0).setEnabled(true);
            spinners.get(1).setSelection(rem2);
            if (rem2 != 0) {
                clickCount++;
                spinners.get(1).setEnabled(true);
            }
            spinners.get(2).setSelection(rem3);
            if (rem3 != 0) {
                clickCount++;
                spinners.get(2).setEnabled(true);
            }
        }
        if (NotTypeInput.isChecked()) {
            SoundInput.setChecked(false);
            SoundInput.setEnabled(false);
        }
        if (address.compareTo("") == 0) AddressInput.setEnabled(false);
    }

    private void sendRequest() { //add this event
        Intent intent = new Intent(this, MainActivity.class);
        if (updateMode == 1) { //if it ,s an update, let the home page know
            intent.putExtra("request", 3);
            intent.putExtra("id", id);
        } else if ((updateMode == 0) || (updateMode == -1)) { //just adding
            intent.putExtra("request", 1);
        }
        intent.putExtra("name", name);
        intent.putExtra("detail", detail);
        intent.putExtra("day", day);
        intent.putExtra("dofweek", dofweek);
        intent.putExtra("month", month);
        intent.putExtra("year", year);
        intent.putExtra("starthr", starthr);
        intent.putExtra("startmin", startmin);
        intent.putExtra("endhr", endhr);
        intent.putExtra("endmin", endmin);
        intent.putExtra("repeat", repeat);
        intent.putExtra("address", address);
        intent.putExtra("notWithTone", notWithTone);
        intent.putExtra("notWithAlarm", notWithAlarm);
        intent.putExtra("reminder1", rem1);
        intent.putExtra("reminder2", rem2);
        intent.putExtra("reminder3", rem3);
        startActivity(intent);
    }

    private void getXmlItems() {
        HomeButton = findViewById(R.id.HomeButton);
        AddButton = findViewById(R.id.AddButton);
        SettingsButton = findViewById(R.id.SettingsButton);
        NameInput = findViewById(R.id.NameInput);
        DetailInput = findViewById(R.id.DetailInput);
        DateInput = findViewById(R.id.DateInput);
        StartingInput = findViewById(R.id.StartingInput);
        EndingInput = findViewById(R.id.EndingInput);
        NotTypeInput = findViewById(R.id.NotTypeInput);
        NotTypeInput.setEnabled(false);
        SoundInput = findViewById(R.id.SoundInput);
        SoundInput.setEnabled(false);
        AddLocationInput = findViewById(R.id.AddLocationInput);
        AddressInput = findViewById(R.id.AddressInput);
        AddressInput.setEnabled(false);
        AddReminderInput = findViewById(R.id.AddReminderInput);
        SaveButton = findViewById(R.id.saveButton);

        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this, R.array.reminder_options, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        int sIndex = -1;
        Spinner s = (Spinner) findViewById(R.id.reminderSpinner1);
        s.setAdapter(adapter);
        s.setEnabled(false);
        spinners.add(++sIndex, s);
        s = (Spinner) findViewById(R.id.reminderSpinner2);
        s.setAdapter(adapter);
        s.setEnabled(false);
        spinners.add(++sIndex, s);
        s = (Spinner) findViewById(R.id.reminderSpinner3);
        s.setAdapter(adapter);
        s.setEnabled(false);
        spinners.add(++sIndex, s);

        adapter = ArrayAdapter.createFromResource(this, R.array.repeat_options, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        RepeatInput = (Spinner) findViewById(R.id.repeatSpinner);
        RepeatInput.setAdapter(adapter);

    }

    private void gatherData() { //gather data from the xml elements
        name = NameInput.getText().toString();
        detail = DetailInput.getText().toString();
        day = DateInput.getDayOfMonth();
        month = DateInput.getMonth();
        year = DateInput.getYear();
        starthr = StartingInput.getHour();
        startmin = StartingInput.getMinute();
        endhr = EndingInput.getHour();
        endmin = EndingInput.getMinute();
        repeat = RepeatInput.getSelectedItemPosition();
        address = AddressInput.getText().toString();
        notWithAlarm = NotTypeInput.isChecked();
        notWithTone = SoundInput.isChecked();
        rem1 = spinners.get(0).getSelectedItemPosition();
        rem2 = spinners.get(1).getSelectedItemPosition();
        rem3 = spinners.get(2).getSelectedItemPosition();

        if (rem1 == 0) {
            rem2 = 0;
            rem3 = 0;
            notWithAlarm = false;
            notWithTone = false;
        }
        dofweek = getDOW(year, month, day);
    }

    private void openAdd() {
        Intent intent = new Intent(this, Add.class);
        intent.putExtra("request", 0);
        startActivity(intent);
    }

    private void openSettings() {
        Intent intent = new Intent(this, Settings.class);
        intent.putExtra("request", 0);
        startActivity(intent);
    }

    private void openHome() {
        Intent intent = new Intent(this, MainActivity.class);
        intent.putExtra("request", 0);
        startActivity(intent);
    }

    public int getDOW(int year, int month, int day) {
        Calendar c = Calendar.getInstance();
        Date date = new Date(year, month, day);
        c.setTime(date);
        int result = c.get(Calendar.DAY_OF_WEEK);
        result += 4;
        result %= 7;
        result++;
        return result;
    }

    public void Toast(String s) {
        Toast.makeText(getApplicationContext(), s, Toast.LENGTH_SHORT).show();
    }

}
