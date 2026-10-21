package tr.edu.yildiz.altugnumanyildiz;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import java.util.ArrayList;

public class dbOperation extends SQLiteOpenHelper {


    private static final int DATABASE_VERSION = 1;
    private static final String DATABASE_NAME = "ytuDB";

    private static final String TABLE_NAME = "Users";
    private static String USERID = "userID";
    private static String NAME = "name";
    private static String SURNAME = "surName";
    private static String EMAIL = "email";
    private static String PASSWORD = "password";
    private static String PHONENUMBER = "phoneNumber";
    private static String PROFILEPICTURE = "profilePicture";

    private static final String TABLE_NAME2 = "Questions";
    private static String QUESTION_ID = "questionID";
    private static String QUESTION_TEXT = "questionText";
    private static String OPTION_A = "optionA";
    private static String OPTION_B = "optionB";
    private static String OPTION_C = "optionC";
    private static String OPTION_D = "optionD";
    private static String OPTION_E = "optionE";
    private static String CORRECT_ANSWER = "correctAnswer";
    private static String TEACHER_ID = "teacherID";
    private static String QUESTION_IMAGE = "questionImage";
    private static String DATA_TYPE = "dataType"; //image,voice,video,none;


    public dbOperation(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {  // Databesi oluşturuyoruz.Bu methodu biz çağırmıyoruz. Databese de obje oluşturduğumuzda otamatik çağırılıyor.

        String CREATE_TABLE2 = "CREATE TABLE " + TABLE_NAME2 + "("
                + QUESTION_ID + " INTEGER PRIMARY KEY AUTOINCREMENT,"
                + QUESTION_TEXT + " VARCHAR,"
                + OPTION_A + " VARCHAR,"
                + OPTION_B + " VARCHAR,"
                + OPTION_C + " VARCHAR,"
                + OPTION_D + " VARCHAR, "
                + OPTION_E + " VARCHAR, "
                + CORRECT_ANSWER + " VARCHAR, "
                + TEACHER_ID + " INTEGER, "
                + QUESTION_IMAGE + " BLOB, "
                + DATA_TYPE + " VARCHAR " + ")";
        db.execSQL(CREATE_TABLE2);

        String CREATE_TABLE = "CREATE TABLE " + TABLE_NAME + "("
                + USERID + " INTEGER PRIMARY KEY AUTOINCREMENT,"
                + NAME + " VARCHAR,"
                + SURNAME + " VARCHAR,"
                + EMAIL + " VARCHAR UNIQUE,"
                + PASSWORD + " VARCHAR,"
                + PHONENUMBER + " VARCHAR, "
                + PROFILEPICTURE + " BLOB " + ")";
        db.execSQL(CREATE_TABLE);

    }

    public boolean signUpUser(String name, String surName,String email,String password,String phoneNumber,byte[] byteArray) {
        //üstünde Databese veri eklemek için
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put(NAME, name);
        values.put(SURNAME, surName);
        values.put(EMAIL, email);
        values.put(PASSWORD, password);
        values.put(PHONENUMBER, phoneNumber);
        values.put(PROFILEPICTURE, byteArray);

        long result = db.insert(TABLE_NAME, null, values);
        db.close();
        if (result == -1) {
            return false;
        } else {
            return true;
        }


         //Database Bağlantısını kapattık*/
    }

    public boolean questionAdd(Question question,byte[] byteArray) {
        //üstünde Databese veri eklemek için
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put(QUESTION_TEXT, question.getQuestionText());
        values.put(OPTION_A, question.getOptionA());
        values.put(OPTION_B, question.getOptionB());
        values.put(OPTION_C, question.getOptionC());
        values.put(OPTION_D, question.getOptionD());
        values.put(OPTION_E, question.getOptionE());
        values.put(CORRECT_ANSWER, question.getCorrectAnswer());
        values.put(TEACHER_ID, question.getTeacherID());
        values.put(QUESTION_IMAGE,byteArray);
        values.put(DATA_TYPE, question.getDataType());

        long result = db.insert(TABLE_NAME2, null, values);
        db.close();
        if (result == -1) {
            return false;
        } else {
            return true;
        }


        //Database Bağlantısını kapattık*/
    }

    public boolean questionUpdate(Question question){

        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put(QUESTION_TEXT, question.getQuestionText());
        values.put(OPTION_A, question.getOptionA());
        values.put(OPTION_B, question.getOptionB());
        values.put(OPTION_C, question.getOptionC());
        values.put(OPTION_D, question.getOptionD());
        values.put(OPTION_E, question.getOptionE());
        values.put(CORRECT_ANSWER, question.getCorrectAnswer());
        values.put(TEACHER_ID, question.getTeacherID());
        values.put(QUESTION_IMAGE,question.getByteArrays());
        values.put(DATA_TYPE, question.getDataType());


        long result = db.update(TABLE_NAME2,values,"questionID=?",new String[] {String.valueOf(question.getQuestionID())});
        db.close();
        if (result == -1) {
            return false;
        } else {
            return true;
        }
    }

    public ArrayList<Question> takeAllQuestions(int tempTeacherID){
        ArrayList<Question> questions = new ArrayList<>();


        String questionsQuery = "SELECT * FROM Questions WHERE teacherID = '" + tempTeacherID + "'";
        SQLiteDatabase db = this.getReadableDatabase();

        Cursor cursor = db.rawQuery(questionsQuery, null);
        if (cursor.getCount() <= 0) {

            cursor.close();
            return null;
        } else {
            int i=1;
            int count=0;
            cursor.moveToFirst();
            while(count<cursor.getCount()){
                count++;
                questions.add(new Question(cursor.getInt(0),
                        cursor.getString(i),
                        cursor.getString(i+1),
                        cursor.getString(i+2),
                        cursor.getString(i+3),
                        cursor.getString(i+4),
                        cursor.getString(i+5),
                        cursor.getString(i+6),
                        cursor.getInt(i+7),
                        cursor.getBlob(i+8),
                        cursor.getString(i+9)));
                cursor.moveToNext();
            }
        }

        return questions;
    }

    public User login(String email,String password) {
        String loginQuery = "SELECT * FROM Users WHERE email = '" + email + "' and password = '" + password + "'";
        SQLiteDatabase db = this.getReadableDatabase();

        Cursor cursor = db.rawQuery(loginQuery, null);

        User user = new User();

        if (cursor.getCount() <= 0) {
            cursor.close();
            return null;
        } else {
            cursor.moveToFirst();
            user.setName(cursor.getString(1));
            user.setSurName(cursor.getString(2));
            user.setEmail(cursor.getString(3));
            user.setPassword(cursor.getString(4));
            user.setPhoneNumber(cursor.getString(5));

            byte[] bytes = cursor.getBlob(6);
            Bitmap bitmap = BitmapFactory.decodeByteArray(bytes,0,bytes.length);
            user.setImage(bitmap);
            cursor.close();
            return user;
        }


    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {

    }
}
