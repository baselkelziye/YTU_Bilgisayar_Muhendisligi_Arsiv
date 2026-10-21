package com.example.MyCalendar;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.text.method.ScrollingMovementMethod;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.PopupMenu;
import android.widget.TextView;
import android.widget.Toast;


public class ViewEvent extends AppCompatActivity implements PopupMenu.OnMenuItemClickListener {

    private int id;
    private String name;
    private String detail;
    private int day;
    int dofweek;
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

    private Button HomeButton;
    private Button SettingsButton;
    private Button AddButton;
    private Button UpdateButton;
    private Button DeleteButton;
    private Button ShareButton;
    private Button findLocationButton;
    private Menu m;
    private PopupMenu popup;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_view_event);

        getRequest(); //get the event data that will be viewed
        getXmlItems(); //place data on xml elements

        UpdateButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendRequest('a', 3);
            }
        });
        DeleteButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendRequest('h', 2);
            }
        });

        ShareButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) { //show options on click
                popup = new PopupMenu(getApplicationContext(), v);
                popup.setOnMenuItemClickListener(ViewEvent.this);
                m = popup.getMenu();
                MenuInflater inflater = popup.getMenuInflater();
                inflater.inflate(R.menu.share_menu, popup.getMenu());
                popup.show();
            }
        });

        findLocationButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) { //go to google maps
                Toast("Directing");
                findOnMaps();
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
                int request = intent.getExtras().getInt("request");
                if (request == 4) {
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
                } else
                    Toast.makeText(getApplicationContext(), "This request cannot be handled.", Toast.LENGTH_SHORT).show();
            }
        } catch (Exception e) {
            Toast.makeText(getApplicationContext(), "Error occurred.", Toast.LENGTH_SHORT).show();
            e.printStackTrace();
        }
    }

    private void getXmlItems() {
        String tmp;
        String[] repArray = {"Never", "Daily", "Weekly", "Monthly", "Every year"};
        String[] remArray = {"None", "event time", "5 minutes before.", "15 minutes before.", "30 minutes before.", "1 hour before."};
        TextView header = findViewById(R.id.eventNameHeader);
        header.setText(name);
        TextView nameInfo = findViewById(R.id.NameInfo);
        nameInfo.setText(name);
        TextView detailInfo = findViewById(R.id.DetailInfo);
        detailInfo.setText(detail);
        TextView dateInfo = findViewById(R.id.DatelInfo);
        String str = Integer.toString(day) + "/" + Integer.toString(month + 1) + "/" + Integer.toString(year);
        dateInfo.setText(str);
        TextView startingTimeInfo = findViewById(R.id.StartingTimeInfo);
        str = Integer.toString(starthr) + "." + Integer.toString(startmin);
        startingTimeInfo.setText(str);
        TextView endingTimeInfo = findViewById(R.id.EndingTimeInfo);
        str = Integer.toString(endhr) + "." + Integer.toString(endmin);
        endingTimeInfo.setText(str);
        TextView repeatInfo = findViewById(R.id.RepeatInfo);
        repeatInfo.setText(repArray[repeat]);
        TextView addressInfo = findViewById(R.id.AddressInfo);
        addressInfo.setText(address);
        addressInfo.setMovementMethod(new ScrollingMovementMethod());
        findLocationButton = findViewById(R.id.FindLocationButton);
        if (address.compareTo("") == 0) findLocationButton.setEnabled(false);
        TextView remonoff = findViewById(R.id.ReminderOnOff);
        TextView notTypeInfo = findViewById(R.id.NotTypeInfo);
        TextView toneInfo = findViewById(R.id.ToneInfo);
        TextView rem1Info = findViewById(R.id.Rem1Info);
        TextView rem2Info = findViewById(R.id.Rem2Info);
        TextView rem3Info = findViewById(R.id.Rem3Info);

        if (rem1 != 0) {
            ((ViewGroup) remonoff.getParent()).removeView(remonoff);
            if (notWithAlarm) tmp = "Alert";
            else tmp = "Notification";
            notTypeInfo.setText(tmp);
            if (notWithTone) tmp = "Sound on";
            else tmp = "Sound off";
            toneInfo.setText(tmp);

            tmp = "Reminder set for " + remArray[rem1];
            rem1Info.setText(tmp);

            if (rem2 > 0) {
                tmp = "Reminder set for " + remArray[rem2];
                rem2Info.setText(tmp);
            }

            if (rem3 > 0) {
                tmp = "Reminder set for " + remArray[rem3];
                rem3Info.setText(tmp);
            }
        } else remonoff.setText("No Reminder Set");


        UpdateButton = findViewById(R.id.updateButton);
        DeleteButton = findViewById(R.id.deleteButton);
        ShareButton = findViewById(R.id.shareButton);

        HomeButton = findViewById(R.id.HomeButton);
        AddButton = findViewById(R.id.AddButton);
        SettingsButton = findViewById(R.id.SettingsButton);
    }

    private void sendRequest(char dest, int request) {
        Intent intent;
        if (dest == 'h') intent = new Intent(this, MainActivity.class); //going home for DELETING
        else intent = new Intent(this, Add.class); //going add for UPDATING
        intent.putExtra("request", request);
        intent.putExtra("id", id);
        intent.putExtra("name", name);
        intent.putExtra("detail", detail);
        intent.putExtra("day", day);
        intent.putExtra("dofweek", day);
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

    @Override
    public boolean onMenuItemClick(MenuItem item) {
        switch (item.getItemId()) {
            case (R.id.email):
                sendEmail();
                return true;
            case (R.id.whatsapp):
                whatsApp();
                return true;
            case (R.id.twitter):
                tweet();
                return true;
        }
        return true;
    }

    public void sendEmail() {
        String message = "Hello,\nI hope you are having a nice day. I wanted to remind you about the event " +
                name + ". It is scheduled for " + Integer.toString(day) + "/" + Integer.toString(month + 1) + "/" + Integer.toString(year);
        if (address.compareTo("") != 0) message = message + ". It is going to be at " + address;
        message = message + ". I hope you will join me.\nHave a wonderful day.";

        Intent mailIntent = new Intent(Intent.ACTION_SENDTO, Uri.fromParts(
                "mailto", "", null));
        mailIntent.putExtra(Intent.EXTRA_SUBJECT, "About Event " + name);
        mailIntent.putExtra(Intent.EXTRA_TEXT, message);
        startActivity(Intent.createChooser(mailIntent, "Choose an E-mail app:"));
    }

    public void tweet() {
        String title = "";
        String message = "Hello, I hope you are all having a nice day. I wanted to tell you about the big day. " + name +
                " is scheduled for " + Integer.toString(day) + "/" + Integer.toString(month + 1) + "/" + Integer.toString(year) + "!";
        if (address.compareTo("") != 0) message = message + " It is going to be at " + address;
        message = message + ". You can send me a direct message if you have any questions. Looking forward to seeing you all then!";

        Uri.Builder b = Uri.parse(message).buildUpon();
        b.build();
        String url = b.build().toString();
        String tweetUrl = "https://twitter.com/intent/tweet?text=" + title + "&url=" + url;
        Uri tweetUri = Uri.parse(tweetUrl);
        startActivity(new Intent(Intent.ACTION_VIEW, tweetUri));
    }

    public void whatsApp() {
        String message = "Hi, I hope you are having a nice day. I wanted to remind you about the event " +
                name + ". It is scheduled for " + Integer.toString(day) + "/" + Integer.toString(month + 1) + "/" + Integer.toString(year);
        if (address.compareTo("") != 0) message = message + " It is going to be at " + address;
        message = message + ". I hope you will join me. Have a wonderful day.";
        Intent wpIntent = new Intent(Intent.ACTION_SEND);
        wpIntent.setType("text/plain");
        wpIntent.setPackage("com.whatsapp");
        wpIntent.putExtra(Intent.EXTRA_TEXT, message);
        try {
            ViewEvent.this.startActivity(wpIntent);
        } catch (android.content.ActivityNotFoundException e) {
            Toast("You must download WhatsApp for this action.");
        }
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

    public void Toast(String s) {
        Toast.makeText(ViewEvent.this, s, Toast.LENGTH_SHORT).show();
    }

    public void findOnMaps() {
        char[] tmpAddress = address.toCharArray();
        for (int i = 0; i < address.length(); i++) {
            if (tmpAddress[i] == ' ') tmpAddress[i] = '+';
        }
        String tmpAddress2 = String.valueOf(tmpAddress);
        String mapsUrl = "https://www.google.com/maps/search/" + tmpAddress2;
        Uri mapsUri = Uri.parse(mapsUrl);
        startActivity(new Intent(Intent.ACTION_VIEW, mapsUri));
    }
}
