package com.example.MyCalendar;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.app.AppCompatDelegate;
import androidx.core.app.NotificationCompat;

import android.app.AlarmManager;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.graphics.Color;
import android.media.RingtoneManager;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.CalendarView;
import android.widget.ListView;
import android.widget.Toast;

import java.sql.Date;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.GregorianCalendar;

//Fonksiyonlarda event'in bazi attributelarinin sayisal degerlerinin kontrol edildigini goreceksiniz.
//Bu sayisal degerlerin ne anlama geldigi Event class'ta anlatilmistir.
public class MainActivity extends AppCompatActivity {

    public static final String NOTIFICATION_CHANNEL_ID = "notifyCalendar";

    private DBHelper dbHelper = new DBHelper(MainActivity.this);
    private CalendarView calendarView;
    private Button dailyButton;
    private Button weeklyButton;
    private Button monthlyButton;
    private Button HomeButton;
    private Button SettingsButton;
    private Button AddButton;

    private static int listingOption = 0;
    private static int index = -1;
    private static ArrayList<Event> events = new ArrayList<Event>();
    private ArrayList<Event> tempEvents;

    private int cday;
    private int cmonth;
    private int cyear;

    private int defcolor;
    private int clickedcolor;

    private ListView listView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        createNotificationChannel();
        firstTime();

        loadFromDB();
        getXmlItems();
        getRequest();


        calendarView.setOnDateChangeListener(new CalendarView.OnDateChangeListener() {
            @Override
            public void onSelectedDayChange(@NonNull CalendarView view, int year, int month, int dayOfMonth) {
                cday = dayOfMonth;
                cmonth = month;
                cyear = year;
                collapseEvents(year, month, dayOfMonth); //list events
            }
        });

        dailyButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                listingOption = 0;
                dailyButton.setBackgroundColor(clickedcolor);
                weeklyButton.setBackgroundColor(defcolor);
                monthlyButton.setBackgroundColor(defcolor);
                collapseEvents(cyear, cmonth, cday);
            }
        });
        weeklyButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                listingOption = 1;
                weeklyButton.setBackgroundColor(clickedcolor);
                dailyButton.setBackgroundColor(defcolor);
                monthlyButton.setBackgroundColor(defcolor);
                collapseEvents(cyear, cmonth, cday);
            }
        });
        monthlyButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                listingOption = 2;
                monthlyButton.setBackgroundColor(clickedcolor);
                weeklyButton.setBackgroundColor(defcolor);
                dailyButton.setBackgroundColor(defcolor);
                collapseEvents(cyear, cmonth, cday);
            }
        });

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                sendRequest(position); //view the details of wanted event
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

        dailyButton.callOnClick();
    }

    private void createNotificationChannel() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            CharSequence name = "CalendarReminderChannel";
            String description = "Channel for calendar reminders.";
            int importance = NotificationManager.IMPORTANCE_DEFAULT;
            NotificationChannel channel = new NotificationChannel(NOTIFICATION_CHANNEL_ID, name, importance);
            channel.setDescription(description);

            NotificationManager notificationManager = getSystemService(NotificationManager.class);
            assert notificationManager != null;
            notificationManager.createNotificationChannel(channel);
        }
    }

    private void firstTime() {
        //fixing when the app is launched for the first time
        SharedPreferences setting0 = getSharedPreferences("SQL", 0);
        boolean firstTime = setting0.getBoolean("firstTime", true);

        if (firstTime) {
            dbHelper.insertEvent(new Event("Cumhuriyet'in İlanı", "Türkiye Cumhuriyeti'nin Resmi Kuruluş Tarihi",
                    29, 9, 1923, 0, 0, 23, 59, 4, "Ankara",
                    false, false, 1, 0, 0, 1));
            dbHelper.insertEvent(new Event("Gençlik ve Spor Bayramı", "Gazi Mustafa Kemal Atatürk'ün Samsun'a Çıkış Tarihi",
                    19, 4, 1919, 0, 0, 23, 59, 4, "Samsun",
                    false, false, 0, 0, 0, 1));
            dbHelper.insertEvent(new Event("U. Egemenlik ve Çocuk Bayramı", "1. Büyük Millet Meclisi'nin Açılış Tarihi",
                    23, 3, 1920, 0, 0, 23, 59, 4, "Ankara",
                    false, false, 0, 0, 0, 5));


            SharedPreferences.Editor editor0 = setting0.edit();
            editor0.putBoolean("firstTime", false);
            editor0.apply();

            setting0 = getSharedPreferences("nightMode", 0);
            editor0 = setting0.edit();
            editor0.putBoolean("nightKey", false);
            editor0.apply();

            setting0 = getSharedPreferences("toneIndex", 0);
            editor0 = setting0.edit();
            editor0.putInt("toneIndex", 0);
            editor0.apply();

            setting0 = getSharedPreferences("defaultReminder", 0);
            editor0 = setting0.edit();
            editor0.putInt("defaultReminder", 0);
            editor0.apply();
        }
    }

    private void loadFromDB() {
        //loading events to the arraylist from databse everytime activity starts
        int flag;
        int j;
        tempEvents = dbHelper.getAllEvents();
        int tmpIndex = tempEvents.size();
        for (int i = 0; i < tmpIndex; i++) {
            j = 0;
            flag = 1;
            while ((j <= index) && (flag == 1)) {
                if (events.get(j).getID() == tempEvents.get(i).getID()) flag = 0;
                j++;
            }
            if (flag == 1) {
                index++;
                events.add(index, tempEvents.get(i));
            }
        }
    }

    private void getRequest() {
        //deletevent, updatevent, addevent
        try {
            Intent intent = this.getIntent();
            if (intent != null) {
                int request = intent.getExtras().getInt("request");
                if (request != 0) { //no purpose
                    String name = intent.getExtras().getString("name");
                    if (request == 1) { //adding
                        String detail = intent.getExtras().getString("detail");
                        int day = intent.getExtras().getInt("day");
                        int dofweek = intent.getExtras().getInt("dofweek");
                        int month = intent.getExtras().getInt("month");
                        int year = intent.getExtras().getInt("year");
                        int starthr = intent.getExtras().getInt("starthr");
                        int startmin = intent.getExtras().getInt("startmin");
                        int endhr = intent.getExtras().getInt("endhr");
                        int endmin = intent.getExtras().getInt("endmin");
                        int repeat = intent.getExtras().getInt("repeat");
                        String address = intent.getExtras().getString("address");
                        boolean notWithTone = intent.getExtras().getBoolean("notWithTone");
                        boolean notWithAlarm = intent.getExtras().getBoolean("notWithAlarm");
                        int rem1 = intent.getExtras().getInt("reminder1");
                        int rem2 = intent.getExtras().getInt("reminder2");
                        int rem3 = intent.getExtras().getInt("reminder3");
                        addEvent(-1, name, detail, day, month, year, starthr, startmin, endhr, endmin, repeat, address, notWithTone, notWithAlarm, rem1, rem2, rem3, dofweek);
                        Toast("Event " + name + " Saved");
                    } else if (request == 2) { //deleting
                        int id = intent.getExtras().getInt("id");
                        deleteEvent(id);
                        Toast("Event " + name + " Deleted");
                    } else if (request == 3) { //updating
                        int id = intent.getExtras().getInt("id");
                        String detail = intent.getExtras().getString("detail");
                        int day = intent.getExtras().getInt("day");
                        int dofweek = intent.getExtras().getInt("dofweek");
                        int month = intent.getExtras().getInt("month");
                        int year = intent.getExtras().getInt("year");
                        int starthr = intent.getExtras().getInt("starthr");
                        int startmin = intent.getExtras().getInt("startmin");
                        int endhr = intent.getExtras().getInt("endhr");
                        int endmin = intent.getExtras().getInt("endmin");
                        int repeat = intent.getExtras().getInt("repeat");
                        String address = intent.getExtras().getString("address");
                        boolean notWithTone = intent.getExtras().getBoolean("notWithTone");
                        boolean notWithAlarm = intent.getExtras().getBoolean("notWithAlarm");
                        int rem1 = intent.getExtras().getInt("reminder1");
                        int rem2 = intent.getExtras().getInt("reminder2");
                        int rem3 = intent.getExtras().getInt("reminder3");
                        deleteEvent(id);
                        addEvent(id, name, detail, day, month, year, starthr, startmin, endhr, endmin, repeat, address, notWithTone, notWithAlarm, rem1, rem2, rem3, dofweek);
                        Toast("Event " + name + " Updated");
                    } else Toast("This request cannot be handled.");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void getXmlItems() {
        SharedPreferences dmsettings = this.getSharedPreferences("nightMode", 0);
        boolean darkMode = dmsettings.getBoolean("nightKey", true);
        if (darkMode) AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES);
        else AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);

        calendarView = (CalendarView) findViewById(R.id.calendarView);
        dailyButton = (Button) findViewById(R.id.dailyButton);
        weeklyButton = (Button) findViewById(R.id.weeklyButton);
        monthlyButton = (Button) findViewById(R.id.monthlyButton);
        HomeButton = (Button) findViewById(R.id.HomeButton);
        AddButton = (Button) findViewById(R.id.AddButton);
        SettingsButton = (Button) findViewById(R.id.SettingsButton);
        listView = (ListView) findViewById(R.id.eventsListView);

        cday = Calendar.getInstance().get(Calendar.DAY_OF_MONTH);
        cmonth = Calendar.getInstance().get(Calendar.MONTH);
        cyear = Calendar.getInstance().get(Calendar.YEAR);

        defcolor = dailyButton.getHighlightColor();
        clickedcolor = Color.parseColor("#008577");
    }

    private void sendRequest(int position) {
        //sending data to viewevent
        Intent intent = new Intent(this, ViewEvent.class);
        intent.putExtra("request", 4);
        intent.putExtra("id", tempEvents.get(position).getID());
        intent.putExtra("name", tempEvents.get(position).getName());
        intent.putExtra("detail", tempEvents.get(position).getDetail());
        intent.putExtra("day", tempEvents.get(position).getDay());
        intent.putExtra("dofweek", tempEvents.get(position).getDofweek());
        intent.putExtra("month", tempEvents.get(position).getMonth());
        intent.putExtra("year", tempEvents.get(position).getYear());
        intent.putExtra("starthr", tempEvents.get(position).getStarthr());
        intent.putExtra("startmin", tempEvents.get(position).getStartmin());
        intent.putExtra("endhr", tempEvents.get(position).getEndhr());
        intent.putExtra("endmin", tempEvents.get(position).getEndmin());
        intent.putExtra("repeat", tempEvents.get(position).getRepeat());
        intent.putExtra("address", tempEvents.get(position).getAddress());
        intent.putExtra("notWithTone", tempEvents.get(position).getIsNotWithTone());
        intent.putExtra("notWithAlarm", tempEvents.get(position).getIsNotWithAlarm());
        intent.putExtra("reminder1", tempEvents.get(position).getReminder(0));
        intent.putExtra("reminder2", tempEvents.get(position).getReminder(1));
        intent.putExtra("reminder3", tempEvents.get(position).getReminder(2));
        startActivity(intent);
    }

    private void collapseEvents(int year, int month, int dayOfMonth) {
        //listing events
        tempEvents = new ArrayList<Event>();
        //holds the data that will be listed
        int eday;
        int edofweek;
        int emonth;
        int eyear;
        int erepeat;
        Calendar mycal;
        if (index > -1) { //if there is any event
            for (int i = 0; i <= index; i++) { //for each event on the arraylist
                eday = events.get(i).getDay();
                edofweek = events.get(i).getDofweek();
                emonth = events.get(i).getMonth();
                eyear = events.get(i).getYear();
                erepeat = events.get(i).getRepeat();
                switch (listingOption) {
                    case (0): //daily
                        if (((eday == dayOfMonth) && (emonth == month) && (eyear == year))
                                || (erepeat == 1)
                                || ((erepeat == 2) && (edofweek == getDOW(year, month, dayOfMonth)))
                                || ((erepeat == 3) && (eday == dayOfMonth))
                                || ((erepeat == 4) && (eday == dayOfMonth) && (emonth == month))) {
                            if ((eyear < year) || ((eyear == year) && (emonth < month)) || ((eyear == year) && (emonth == month) && (eday <= dayOfMonth)))
                                tempEvents.add(events.get(i));
                        }
                        break;
                    case (1): //weekly
                        mycal = new GregorianCalendar(year, month, dayOfMonth);
                        mycal.add(Calendar.DAY_OF_MONTH, -1 * getDOW(year, month, dayOfMonth));
                        for (int j = 0; j < 7; j++) {
                            mycal.add(Calendar.DAY_OF_MONTH, 1);
                            if (((eday == mycal.get(Calendar.DAY_OF_MONTH)) && (emonth == mycal.get(Calendar.MONTH)) && (eyear == mycal.get(Calendar.YEAR)))
                                    || ((erepeat == 3) && (eday == mycal.get(Calendar.DAY_OF_MONTH)))
                                    || ((erepeat == 4) && (eday == mycal.get(Calendar.DAY_OF_MONTH)) && (emonth == mycal.get(Calendar.MONTH)))) {
                                if ((eyear < mycal.get(Calendar.YEAR)) || ((eyear == mycal.get(Calendar.YEAR)) && (emonth < mycal.get(Calendar.MONTH))) || ((eyear == mycal.get(Calendar.YEAR)) && (emonth == mycal.get(Calendar.MONTH)) && (eday <= mycal.get(Calendar.DAY_OF_MONTH))))
                                    tempEvents.add(events.get(i));
                            }
                        }
                        if (((erepeat == 1) || (erepeat == 2)) && (!tempEvents.contains(events.get(i)))) {
                            if ((eyear < mycal.get(Calendar.YEAR)) || ((eyear == mycal.get(Calendar.YEAR)) && (emonth < mycal.get(Calendar.MONTH))) || ((eyear == mycal.get(Calendar.YEAR)) && (emonth == mycal.get(Calendar.MONTH)) && (eday <= mycal.get(Calendar.DAY_OF_MONTH))))
                                tempEvents.add(events.get(i));
                        }
                        break;
                    case (2): //monthly
                        mycal = new GregorianCalendar(year, month, 1);
                        int daysInMonth = mycal.getActualMaximum(Calendar.DAY_OF_MONTH);
                        for (int j = 0; j < daysInMonth; j++) {
                            if (((eday == mycal.get(Calendar.DAY_OF_MONTH)) && (emonth == mycal.get(Calendar.MONTH)) && (eyear == mycal.get(Calendar.YEAR)))
                                    || ((erepeat == 4) && (eday == mycal.get(Calendar.DAY_OF_MONTH)) && (emonth == mycal.get(Calendar.MONTH)))) {
                                if ((eyear < mycal.get(Calendar.YEAR)) || ((eyear == mycal.get(Calendar.YEAR)) && (emonth < mycal.get(Calendar.MONTH))) || ((eyear == mycal.get(Calendar.YEAR)) && (emonth == mycal.get(Calendar.MONTH)) && (eday <= mycal.get(Calendar.DAY_OF_MONTH))))
                                    tempEvents.add(events.get(i));
                            }
                            mycal.add(Calendar.DAY_OF_MONTH, 1);
                        }
                        mycal.add(Calendar.DAY_OF_MONTH, -1);
                        if (((erepeat == 1) || (erepeat == 2) || (erepeat == 3)) && (!tempEvents.contains(events.get(i)))) {
                            if ((eyear < mycal.get(Calendar.YEAR)) || ((eyear == mycal.get(Calendar.YEAR)) && (emonth < mycal.get(Calendar.MONTH))) || ((eyear == mycal.get(Calendar.YEAR)) && (emonth == mycal.get(Calendar.MONTH)) && (eday <= mycal.get(Calendar.DAY_OF_MONTH))))
                                tempEvents.add(events.get(i));
                        }
                        break;
                }
            }
        }
        CustomListViewAdapter listViewAdapter = new CustomListViewAdapter(MainActivity.this, tempEvents);
        listView.setAdapter(listViewAdapter);
    }

    private void deleteEvent(int id) {
        int i = 0;
        int flag = 0;
        while ((flag == 0) && (i <= index)) {
            if (events.get(i).getID() == id) {
                deleteNotifications(id, events.get(i).getIsNotWithAlarm());
                events.remove(i);
                index--;
                flag = 1;
            }
            i++;
        }
        dbHelper.deleteEvent(id);
    }

    private void addEvent(int id, String name, String detail, int day, int month, int year, int starthr, int startmin, int endhr,
                          int endmin, int repeat, String address, boolean notWithTone, boolean notWithAlarm, int rem1, int rem2, int rem3, int dofweek) {
        Event newEvent = new Event(name, detail, day, month, year, starthr, startmin, endhr, endmin, repeat, address, notWithTone, notWithAlarm, rem1, rem2, rem3, dofweek);
        if (id != -1) newEvent.setId(id);
        index++;
        events.add(index, newEvent);
        dbHelper.insertEvent(newEvent);
        int i = 0;
        boolean flag = true;
        while ((newEvent.getReminder(i) != 0) && (i < 3)) { //set reminders, if there is any
            createNotification(newEvent, i);
            flag = false;
            i++;
        }
        if (flag) { //if there is no reminder, set the default reminder
            setDefaultNotification(newEvent);
        }
    }

    public void setDefaultNotification(Event e) { //setting the default reminder
        SharedPreferences settings = this.getSharedPreferences("toneIndex", 0);
        Uri sound = Uri.parse(getSound(settings.getInt("toneIndex", 0)));
        settings = this.getSharedPreferences("defaultReminder", 0);
        int rem = settings.getInt("defaultReminder", 0);
        if (rem != 0) {
            int notID = notIDCreator(e.getID(), 3);
            String content = "";
            int min = 0;
            switch (rem) {
                case (1):
                    content = "Your event is starting now.";
                    min = 0;
                    break;
                case (2):
                    content = "5 minutes remaining for your event.";
                    min = 5;
                    break;
                case (3):
                    content = "15 minutes remaining for your event.";
                    min = 15;
                    break;
                case (4):
                    content = "30 minutes remaining for our event.";
                    min = 30;
                    break;
                case (5):
                    content = "1 hour remaining for your event.";
                    min = 60;
                    break;
            }
            Calendar c = Calendar.getInstance();
            c.set(e.getYear(), e.getMonth(), e.getDay(), e.getStarthr(), e.getStartmin());
            c.add(Calendar.MINUTE, -1 * min);
            long time = c.getTimeInMillis();

            NotificationCompat.Builder builder = new NotificationCompat.Builder(MainActivity.this, NOTIFICATION_CHANNEL_ID);
            builder.setContentTitle(e.getName());
            builder.setContentText(content);
            builder.setAutoCancel(true);
            builder.setSmallIcon(R.drawable.appicon_foreground);
            builder.setPriority(NotificationCompat.PRIORITY_HIGH);
            builder.setWhen(time);
            builder.setChannelId(NOTIFICATION_CHANNEL_ID);
            builder.setVibrate(new long[]{1000, 1000, 1000, 1000, 1000});
            builder.setSound(sound);
            Notification myNotification = builder.build();

            Intent myIntent = new Intent(MainActivity.this, ReminderBroadcast.class);
            myIntent.putExtra(ReminderBroadcast.NOTIFICATION_ID, notID);
            myIntent.putExtra(ReminderBroadcast.NOTIFICATION, myNotification);
            myIntent.putExtra("repeat", e.getRepeat());
            PendingIntent pendingIntent = PendingIntent.getBroadcast(MainActivity.this, notID, myIntent, 0);
            AlarmManager alarmManager = (AlarmManager) getSystemService(ALARM_SERVICE);
            assert alarmManager != null;
            long now = System.currentTimeMillis();
            if (now <= time)
                alarmManager.set(AlarmManager.RTC_WAKEUP, time, pendingIntent);
        }
    }

    public void createNotification(Event e, int remIndex) {
        SharedPreferences settings = this.getSharedPreferences("toneIndex", 0);
        Uri sound = Uri.parse(getSound(settings.getInt("toneIndex", 0)));
        int notID = notIDCreator(e.getID(), remIndex);
        long notTime = calNotTime(e, remIndex);
        String content = "";
        Intent myIntent;
        switch (e.getReminder(remIndex)) {
            case (1):
                content = "Your event is starting now.";
                break;
            case (2):
                content = "5 minutes remaining for your event.";
                break;
            case (3):
                content = "15 minutes remaining for your event.";
                break;
            case (4):
                content = "30 minutes remaining for our event.";
                break;
            case (5):
                content = "1 hour remaining for your event.";
                break;
        }
        if (!e.getIsNotWithAlarm()) { //if it is a notification
            NotificationCompat.Builder builder = new NotificationCompat.Builder(MainActivity.this, NOTIFICATION_CHANNEL_ID);
            builder.setContentTitle(e.getName());
            builder.setContentText(content);
            builder.setAutoCancel(true);
            builder.setWhen(notTime);
            builder.setSmallIcon(R.drawable.appicon_foreground);
            builder.setPriority(NotificationCompat.PRIORITY_HIGH);
            builder.setChannelId(NOTIFICATION_CHANNEL_ID);
            builder.setVibrate(new long[]{1000, 1000, 1000, 1000, 1000});
            if (e.getIsNotWithTone()) builder.setSound(sound);
            Notification myNotification = builder.build();

            myIntent = new Intent(MainActivity.this, ReminderBroadcast.class);
            myIntent.putExtra("repeat", e.getRepeat());
            myIntent.putExtra(ReminderBroadcast.NOTIFICATION_ID, notID);
            myIntent.putExtra(ReminderBroadcast.NOTIFICATION, myNotification);
        } else { //if it is an alertdialog
            myIntent = new Intent(MainActivity.this, AlertBroadcast.class);
            myIntent.putExtra("alertID", notID);
            myIntent.putExtra("title", "Reminder for your event " + e.getName());
            myIntent.putExtra("content", content);
            myIntent.putExtra("repeat", e.getRepeat());
        }
        PendingIntent pendingIntent = PendingIntent.getBroadcast(MainActivity.this, notID, myIntent, 0);
        AlarmManager alarmManager = (AlarmManager) getSystemService(ALARM_SERVICE);
        assert alarmManager != null;
        long now = System.currentTimeMillis();
        if (now <= notTime)
            alarmManager.setExactAndAllowWhileIdle(AlarmManager.RTC_WAKEUP, notTime, pendingIntent);
    }

    public void deleteNotifications(int id, boolean isNotWithAlarm) {
        int notID;
        if (isNotWithAlarm) { //if its an alert
            for (int i = 0; i < 3; i++) {
                notID = notIDCreator(id, i);
                Intent myIntent = new Intent(MainActivity.this, AlertBroadcast.class);
                myIntent.putExtra("alertID", notID);
                PendingIntent pendingIntent = PendingIntent.getBroadcast(MainActivity.this, notID, myIntent, 0);
                AlarmManager alarmManager = (AlarmManager) getSystemService(ALARM_SERVICE);
                try {
                    assert alarmManager != null;
                    alarmManager.cancel(pendingIntent);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        } else { //if its a notification or none(default)
            for (int i = 0; i < 4; i++) {
                notID = notIDCreator(id, i);
                Intent myIntent = new Intent(MainActivity.this, ReminderBroadcast.class);
                myIntent.putExtra(ReminderBroadcast.NOTIFICATION_ID, notID);
                PendingIntent pendingIntent = PendingIntent.getBroadcast(MainActivity.this, notID, myIntent, 0);
                AlarmManager alarmManager = (AlarmManager) getSystemService(ALARM_SERVICE);
                try {
                    assert alarmManager != null;
                    alarmManager.cancel(pendingIntent);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public int getDOW(int year, int month, int day) { //get the day of week
        Calendar c = Calendar.getInstance();
        Date date = new Date(year, month, day);
        c.setTime(date);
        int result = c.get(Calendar.DAY_OF_WEEK);
        result += 4; //calendar's first dow was friday
        result %= 7;
        result++;
        return result;
    }

    public long calNotTime(Event e, int remIndex) { //calculate eventtime-reminder time
        Calendar c = Calendar.getInstance();
        c.set(e.getYear(), e.getMonth(), e.getDay(), e.getStarthr(), e.getStartmin());
        int min = 0;
        switch (e.getReminder(remIndex)) {
            case (1):
                min = 0;
                break;
            case (2):
                min = 5;
                break;
            case (3):
                min = 15;
                break;
            case (4):
                min = 30;
                break;
            case (5):
                min = 60;
                break;
        }
        c.add(Calendar.MINUTE, -1 * min);
        return c.getTimeInMillis();

    }

    public int notIDCreator(int x, int y) { //generate id for notification with the event id and the reminder index
        String a = Integer.toString(y);
        String b = Integer.toString(x);
        String c = b + a;
        return Integer.parseInt(c);
    }

    public String getSound(int index) { //get wanted ringtone's uri as a string
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

    private void openAdd() { //go to add page
        Intent intent = new Intent(this, Add.class);
        intent.putExtra("request", -1);
        intent.putExtra("cDay", cday);
        intent.putExtra("cMonth", cmonth);
        intent.putExtra("cYear", cyear);
        startActivity(intent);
    }

    private void openSettings() { //settings
        Intent intent = new Intent(this, Settings.class);
        intent.putExtra("request", 0);
        startActivity(intent);
    }

    private void openHome() { //go to home page
        Intent intent = new Intent(this, MainActivity.class);
        intent.putExtra("request", 0);
        startActivity(intent);
    }

    public void Toast(String s) { //toast
        Toast.makeText(MainActivity.this, s, Toast.LENGTH_SHORT).show();
    }

}
