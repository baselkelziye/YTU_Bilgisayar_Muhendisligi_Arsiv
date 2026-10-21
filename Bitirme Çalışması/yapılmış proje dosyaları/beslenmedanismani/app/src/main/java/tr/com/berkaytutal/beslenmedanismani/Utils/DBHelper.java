package tr.com.berkaytutal.beslenmedanismani.Utils;

/**
 * Created by berka on 29.05.2017.
 */

import java.util.ArrayList;
import java.util.HashMap;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.DatabaseUtils;
import android.database.sqlite.SQLiteOpenHelper;
import android.database.sqlite.SQLiteDatabase;

import org.apache.commons.lang3.SerializationUtils;

public class DBHelper extends SQLiteOpenHelper {


    public static final String DATABASE_NAME = "MyDBName.db";
    public static final String USER_TABLE_NAME = "users";
    public static final String USER_COLUMN_ID = "id";
    public static final String USER_COLUMN_EMAIL = "email";
    public static final String USER_COLUMN_PASSWORD = "password";
    public static final String USER_COLUMN_DATA = "data";

    private HashMap hp;

    public DBHelper(Context context) {
        super(context, DATABASE_NAME, null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {

        db.execSQL(
                "create table IF NOT EXISTS " + USER_TABLE_NAME +
                        "(" + USER_COLUMN_ID + " integer primary key, "
                        + USER_COLUMN_EMAIL + " TEXT,"
                        + USER_COLUMN_PASSWORD + " TEXT,"
                        + USER_COLUMN_DATA + " blob)"
        );
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS " + USER_TABLE_NAME);
        onCreate(db);
    }


    public boolean insertUser(UserDataPOJO userDataPOJO, String password) {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        byte[] data = SerializationUtils.serialize(userDataPOJO);

        contentValues.put(USER_COLUMN_ID, userDataPOJO.getUser_ID());
        contentValues.put(USER_COLUMN_EMAIL, userDataPOJO.getEmail());
        contentValues.put(USER_COLUMN_PASSWORD, password);
        contentValues.put(USER_COLUMN_DATA, data);

        db.insert(USER_TABLE_NAME, null, contentValues);
        return true;
    }


    public UserDataPOJO getUser() {

        SQLiteDatabase db = this.getReadableDatabase();
        Cursor res = db.rawQuery("select * from " + USER_TABLE_NAME, null);
        res.moveToFirst();


        byte[] data;
        try {
            data = res.getBlob(res.getColumnIndex(USER_COLUMN_DATA));

        } catch (Exception e) {
            return null;
        }
        UserDataPOJO user = (UserDataPOJO) SerializationUtils.deserialize(data);
        return user;

    }

    public UserDataPOJO getUser(int userID) {

        SQLiteDatabase db = this.getReadableDatabase();
        Cursor res = db.rawQuery("select * from " + USER_TABLE_NAME + " where " + USER_COLUMN_ID + "=" + userID + "", null);
        res.moveToFirst();
        byte[] data;
        try {
            data = res.getBlob(res.getColumnIndex(USER_COLUMN_DATA));

        } catch (Exception e) {
            return null;
        }
        UserDataPOJO user = (UserDataPOJO) SerializationUtils.deserialize(data);
        return user;

    }
    public UserDataPOJO getUser(String email, String password) {

        SQLiteDatabase db = this.getReadableDatabase();
        Cursor res = db.rawQuery("select * from " + USER_TABLE_NAME + " where " + USER_COLUMN_EMAIL + "='" + email + "' and " + USER_COLUMN_PASSWORD + "='" + password + "'", null);
        res.moveToFirst();
        byte[] data;
        try {
            data = res.getBlob(res.getColumnIndex(USER_COLUMN_DATA));

        } catch (Exception e) {
            return null;
        }
        UserDataPOJO user = (UserDataPOJO) SerializationUtils.deserialize(data);
        return user;

    }

    public int numberOfRows() {
        SQLiteDatabase db = this.getReadableDatabase();
        int numRows = (int) DatabaseUtils.queryNumEntries(db, USER_TABLE_NAME);
        return numRows;
    }


    public boolean updateUser(UserDataPOJO userDataPOJO) {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        byte[] data = SerializationUtils.serialize(userDataPOJO);
        contentValues.put(USER_COLUMN_DATA, data);

        db.update(USER_TABLE_NAME, contentValues, USER_COLUMN_ID + " = ? ", new String[]{Integer.toString(userDataPOJO.getUser_ID())});
        return true;
    }


    public Integer deleteUser(Integer userID) {
        SQLiteDatabase db = this.getWritableDatabase();
        return db.delete(USER_TABLE_NAME,
                USER_COLUMN_ID + " = ? ",
                new String[]{Integer.toString(userID)});
    }

}