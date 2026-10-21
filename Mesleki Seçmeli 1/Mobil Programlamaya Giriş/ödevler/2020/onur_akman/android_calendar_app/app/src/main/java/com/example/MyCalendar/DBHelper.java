package com.example.MyCalendar;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

import java.util.ArrayList;

public class DBHelper extends SQLiteOpenHelper {
    private static final String DATABASE_NAME = "calendarDB";
    private static final String TABLE_EVENTS = "events";

    public DBHelper(Context context) {
        super(context, DATABASE_NAME, null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String sql = "CREATE TABLE " + TABLE_EVENTS +
                "(id INTEGER PRIMARY KEY, name TEXT, detail TEXT, day INTEGER, month INTEGER, year INTEGER, " +
                "starthr INTEGER, startmin INTEGER, endhr INTEGER, endmin INTEGER, repeat INTEGER, address TEXT," +
                " notWithTone INTEGER, notWithAlarm INTEGER, rem1 INTEGER, rem2 INTEGER, rem3 INTEGER, dofweek INTEGER)";
        Log.d("DBHelper", "SQL : " + sql);
        db.execSQL(sql);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_EVENTS);
        onCreate(db);
    }

    public void insertEvent(Event event) {
        SQLiteDatabase db = this.getWritableDatabase();

        ContentValues values = new ContentValues();
        values.put("id", event.getID());
        values.put("name", event.getName());
        values.put("detail", event.getDetail());
        values.put("day", event.getDay());
        values.put("month", event.getMonth());
        values.put("year", event.getYear());
        values.put("starthr", event.getStarthr());
        values.put("startmin", event.getStartmin());
        values.put("endhr", event.getEndhr());
        values.put("endmin", event.getEndmin());
        values.put("repeat", event.getRepeat());
        values.put("address", event.getAddress());
        int val = (event.getIsNotWithTone()) ? 1 : 0;
        values.put("notWithTone", val);
        val = (event.getIsNotWithAlarm()) ? 1 : 0;
        values.put("notWithAlarm", val);
        values.put("rem1", event.getReminder(0));
        values.put("rem2", event.getReminder(1));
        values.put("rem3", event.getReminder(2));
        values.put("dofweek", event.getDofweek());

        db.insert(TABLE_EVENTS, null, values);
        db.close();
    } //add event to the db

    public void deleteEvent(int ID) {
        SQLiteDatabase db = this.getWritableDatabase();
        db.delete(TABLE_EVENTS, "ID=" + Integer.toString(ID), null);
    } //delete from the db

    public ArrayList<Event> getAllEvents() {
        ArrayList<Event> storedEvents = new ArrayList<Event>();
        SQLiteDatabase db = this.getWritableDatabase();
        int index = -1;

        Cursor cursor = db.query(TABLE_EVENTS, new String[]{"id", "name", "detail", "day", "month", "year", "starthr", "startmin",
                "endhr", "endmin", "repeat", "address", "notWithTone", "notWithAlarm", "rem1", "rem2", "rem3", "dofweek"}, null, null, null, null, null);

        while (cursor.moveToNext()) {
            Event e = new Event(cursor.getString(1), cursor.getString(2), cursor.getInt(3),
                    cursor.getInt(4), cursor.getInt(5), cursor.getInt(6),
                    cursor.getInt(7), cursor.getInt(8), cursor.getInt(9),
                    cursor.getInt(10), cursor.getString(11), cursor.getInt(12) > 0, cursor.getInt(13) > 0,
                    cursor.getInt(14), cursor.getInt(15), cursor.getInt(16), cursor.getInt(17));
            e.setId(cursor.getInt(0));
            index++;
            storedEvents.add(index, e);
        }
        return storedEvents;
    } //get every event from the db

}
