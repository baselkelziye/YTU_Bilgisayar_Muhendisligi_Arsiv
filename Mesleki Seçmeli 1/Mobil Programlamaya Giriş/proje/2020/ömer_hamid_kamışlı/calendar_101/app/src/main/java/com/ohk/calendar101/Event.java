package com.ohk.calendar101;

import androidx.room.Entity;
import androidx.room.PrimaryKey;

import java.text.SimpleDateFormat;
import java.util.Date;

@Entity(tableName = "event")
public class Event {
    @PrimaryKey(autoGenerate = true)
    int id;
    String title;
    int type;
    String location;
    String details;
    Long calendarStart;
    Long calendarFinish;
    Long alarm1;
    Long alarm2;
    Long alarm3;

    @Override
    public String toString() {
        return "Event{" +
                "id=" + id +
                ", title='" + title + '\'' +
                ", type=" + type +
                ", location='" + location + '\'' +
                ", details='" + details + '\'' +
                ", calendarStart=" + calendarStart +
                ", calendarFinish=" + calendarFinish +
                ", alarm1=" + alarm1 +
                ", alarm2=" + alarm2 +
                ", alarm3=" + alarm3 +
                '}';
    }

    public String ShareToString() {
        return "Hi check my Event, title='" + title +
                "\ndetails='" + details +
                "\nlocation='" + location +
                "\nstart=" + convertDateString(calendarStart) +
                "\nfinish=" + convertDateString(calendarFinish);
    }

    public String convertDateString(long val){
        Date date=new Date(val);
        SimpleDateFormat df2 = new SimpleDateFormat("dd-MM-yyyy HH:mm");;
        String dateText = df2.format(date);
        return dateText;
    }
}
