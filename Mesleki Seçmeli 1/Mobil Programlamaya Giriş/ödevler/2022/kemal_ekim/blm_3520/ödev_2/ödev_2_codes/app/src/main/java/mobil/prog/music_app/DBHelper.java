package mobil.prog.music_app;


import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DBHelper extends SQLiteOpenHelper {



    public static final String DBNAME = "Login.db";

    public DBHelper(Context context) {
        super(context, "Login.db", null, 1);
    }


    // username and password columns
    @Override
    public void onCreate(SQLiteDatabase MyDB) {
        MyDB.execSQL("create Table users(username TEXT primary key, password TEXT)");
    }


    @Override
    public void onUpgrade(SQLiteDatabase MyDB, int i, int i1) {
        MyDB.execSQL("drop Table if exists users");
    }


    public Boolean insertData(String username, String password) {
        SQLiteDatabase MyDB = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put("username", username);
        contentValues.put("password", password);
        long result = MyDB.insert("users", null, contentValues);
        if (result == -1) {
            return false;
        }
        else {
            return true;
        }
    }


    // kullanıcı adı alınmamışsa ekle
    public Boolean checkusername(String username){
        SQLiteDatabase MyDB = this.getWritableDatabase();
            Cursor cursor = MyDB.rawQuery("SELECT * FROM users WHERE username = ?", new String[] {username});
            if (cursor.getCount()>0){
                return true;
            }
            else {
                return false;
            }
    }


    public Boolean checkusernamepassword(String username, String password){
        SQLiteDatabase MyDB = this.getWritableDatabase();
        Cursor cursor = MyDB.rawQuery("SELECT * FROM users WHERE username = ? and password = ?",new String[] {username, password});
        if (cursor.getCount()>0){
            return true;
        }
        else{
            return false;
        }
    }

}
