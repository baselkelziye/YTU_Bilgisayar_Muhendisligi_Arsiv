package berkay.ders.mobilprogramlama.semesterproject.database;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract.CallsContract;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract.ContactsContract;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract.MessagesContract;

/**
 * Created by mberk on 14.12.2015.
 */
public class UserDatabaseHelper extends SQLiteOpenHelper {

    public static final int DATABASE_VERSION = 1;
    public static final String DATABASE_NAME = "SmartPhonebookDatabase.db";

    private static final String SQL_CREATE_CONTACTS_TABLE =
            "CREATE TABLE " + ContactsContract.TABLE_NAME + " (" +
                    ContactsContract.COLUMN_NAME_CONTACT_ID + " INTEGER PRIMARY KEY AUTOINCREMENT," +
                    ContactsContract.COLUMN_NAME_CONTACT_FIRST_NAME + " TEXT," +
                    ContactsContract.COLUMN_NAME_CONTACT_SURNAME + " TEXT," +
                    ContactsContract.COLUMN_NAME_CONTACT_PHONE_NUMBER + " TEXT," +
                    ContactsContract.COLUMN_NAME_CONTACT_EMAIL + " TEXT," +
                    ContactsContract.COLUMN_NAME_CONTACT_LONGITUDE + " DOUBLE," +
                    ContactsContract.COLUMN_NAME_CONTACT_LATITUDE + " DOUBLE," +
                    ContactsContract.COLUMN_NAME_CONTACT_TOTAL_INCOMING_DURATION + " INTEGER," +
                    ContactsContract.COLUMN_NAME_CONTACT_TOTAL_OUTGOING_DURATION + " INTEGER," +
                    ContactsContract.COLUMN_NAME_CONTACT_MISSING_CALLS + " INTEGER," +
                    ContactsContract.COLUMN_NAME_CONTACT_SENT_MESSAGES + " INTEGER," +
                    ContactsContract.COLUMN_NAME_CONTACT_RECEIVED_MESSAGES + " INTEGER," +
                    ContactsContract.COLUMN_NAME_CONTACT_IS_IN_SPEED_DIAL + " INTEGER" +
                    " )";

    private static final String SQL_CREATE_MESSAGES_TABLE =
            "CREATE TABLE " + MessagesContract.TABLE_NAME + " (" +
                    MessagesContract.COLUMN_NAME_MESSAGE_ID + " INTEGER PRIMARY KEY AUTOINCREMENT," +
                    MessagesContract.COLUMN_NAME_REMOTE_PHONE_NUMBER + " TEXT," +
                    MessagesContract.COLUMN_NAME_IS_FROM_ME + " BOOLEAN," +
                    MessagesContract.COLUMN_NAME_MESSAGE_TEXT + " TEXT," +
                    MessagesContract.COLUMN_NAME_MESSAGE_DATE + " INTEGER," +
                    "FOREIGN KEY (" + MessagesContract.COLUMN_NAME_REMOTE_PHONE_NUMBER + ") REFERENCES " + ContactsContract.TABLE_NAME + "(" + ContactsContract.COLUMN_NAME_CONTACT_ID + ")" +
                    " )";

    private static final String SQL_CREATE_CALLS_TABLE =
            "CREATE TABLE " + CallsContract.TABLE_NAME + " (" +
                    CallsContract.COLUMN_NAME_CALL_ID + " INTEGER PRIMARY KEY AUTOINCREMENT," +
                    CallsContract.COLUMN_NAME_REMOTE_PHONE_NUMBER + " TEXT," +
                    CallsContract.COLUMN_NAME_IS_FROM_ME + " BOOLEAN," +
                    CallsContract.COLUMN_NAME_IS_ANSWERED + " BOOLEAN," +
                    CallsContract.COLUMN_NAME_CALL_DATE + " INTEGER," +
                    CallsContract.COLUMN_NAME_CALL_DURATION + " INTEGER" +
                    " )";

    private static final String SQL_DELETE_CONTACTS = "DROP TABLE IF EXISTS " + ContactsContract.TABLE_NAME;
    private static final String SQL_DELETE_MESSAGES = "DROP TABLE IF EXISTS " + MessagesContract.TABLE_NAME;
    private static final String SQL_DELETE_CALLS = "DROP TABLE IF EXISTS " + CallsContract.TABLE_NAME;

    public UserDatabaseHelper(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    public void onCreate(SQLiteDatabase db) {
        db.execSQL(SQL_CREATE_CONTACTS_TABLE);
        db.execSQL(SQL_CREATE_MESSAGES_TABLE);
        db.execSQL(SQL_CREATE_CALLS_TABLE);
    }

    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL(SQL_DELETE_MESSAGES);
        db.execSQL(SQL_DELETE_CONTACTS);
        db.execSQL(SQL_DELETE_CALLS);

        onCreate(db);
    }

    public void onDowngrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        onUpgrade(db, oldVersion, newVersion);
    }

}
