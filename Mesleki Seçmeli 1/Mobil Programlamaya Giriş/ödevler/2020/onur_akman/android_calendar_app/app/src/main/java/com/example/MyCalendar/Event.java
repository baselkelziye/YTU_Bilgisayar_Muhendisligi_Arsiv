package com.example.MyCalendar;

public class Event {

    private static int index = -1;
    //for generating unique id
    private int id;
    private String name;
    private String detail;
    private int day;
    private int month;
    private int year;
    private int starthr;
    private int startmin;
    private int endhr;
    private int endmin;
    private int repeat;
    // 0=never, 1=daily, 2=weekly, 3=monthly, 4=yearly
    private String address;
    private boolean notWithTone;
    private boolean notWithAlarm;
    // 0=notification 1=alert
    private int rem1;
    //0=none 1=oneventtime 2=5min 3=15min 4=30min 5=1hr
    private int rem2;
    private int rem3;
    private int dofweek;
    //which dayofweek is it

    public Event(String name, String detail, int day, int month, int year, int starthr, int startmin, int endhr, int endmin, int repeat, String address, boolean notWithTone, boolean notWithAlarm, int rem1, int rem2, int rem3, int dofweek) {
        index++;
        id = index;
        this.name = name;
        this.detail = detail;
        this.day = day;
        this.month = month;
        this.year = year;
        this.starthr = starthr;
        this.startmin = startmin;
        this.endhr = endhr;
        this.endmin = endmin;
        this.repeat = repeat;
        this.address = address;
        this.notWithTone = notWithTone;
        this.notWithAlarm = notWithAlarm;
        this.rem1 = rem1;
        this.rem2 = rem2;
        this.rem3 = rem3;
        this.dofweek = dofweek;
    }

    public void setId(int id) {
        if (id >= index) {
            index = id;
        }
        this.id = id;
    }

    public int getRepeat() {
        return repeat;
    }

    public int getDay() {
        return day;
    }

    public int getYear() {
        return year;
    }

    public int getMonth() {
        return month;
    }

    public String getName() {
        return name;
    }

    public String getDetail() {
        return detail;
    }

    public int getStarthr() {
        return starthr;
    }

    public int getStartmin() {
        return startmin;
    }

    public int getEndhr() {
        return endhr;
    }

    public int getEndmin() {
        return endmin;
    }

    public int getID() {
        return id;
    }

    public boolean getIsNotWithTone() {
        return notWithTone;
    }

    public boolean getIsNotWithAlarm() {
        return notWithAlarm;
    }

    public int getReminder(int index) {
        //index=which reminder is it
        switch (index) {
            case (0):
                return rem1;
            case (1):
                return rem2;
            case (2):
                return rem3;
        }
        return 0;
    }

    public String getAddress() {
        return address;
    }

    public int getDofweek() {
        return dofweek;
    }

}
