package tr.edu.yildiz.payci.soner.DAL;

import android.annotation.SuppressLint;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.database.sqlite.SQLiteStatement;

import java.io.File;
import java.io.FileOutputStream;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;

import tr.edu.yildiz.payci.soner.model.Exam;
import tr.edu.yildiz.payci.soner.model.Person;
import tr.edu.yildiz.payci.soner.model.Question;
import tr.edu.yildiz.payci.soner.model.QuestionMedia;

public class DbHelper extends SQLiteOpenHelper {

    private static final SqlBuilder _sqlBuilder = new SqlBuilder();

    //<editor-fold desc="Table Names">
    private static final String DATABASE_NAME = "QuestionPool";
    private static final int DATABASE_VERSION = 3;
    //</editor-fold>

    //<editor-fold desc="Table Names">
    private static final String TABLE_USERS = "Users";
    private static final String TABLE_QUESTIONS = "Questions";
    private static final String TABLE_QUESTION_MEDIAS = "QuestionMedias";
    private static final String TABLE_EXAMS = "Exams";
    private static final String TABLE_QUESTIONS_TO_EXAMS = "QuestionsExams";
    //</editor-fold>

    //<editor-fold desc="Users Table Columns">
    private static final String KEY_USER_ID = "id";
    private static final String KEY_FIRST_NAME = "firstName";
    private static final String KEY_LAST_NAME = "lastName";
    private static final String KEY_USERNAME = "username";
    private static final String KEY_PASSWORD = "password";
    private static final String KEY_AVATAR = "avatar";
    private static final String KEY_EMAIL = "email";
    private static final String KEY_PHONE = "phone";
    private static final String KEY_DATE_OF_BIRTH = "birthDate";
    //</editor-fold>

    //<editor-fold desc="Questions Table Columns">
    private static final String KEY_QUESTION_ID = "id";
    private static final String KEY_QUESTION_USER_FK = "userId";
    private static final String KEY_QUESTION_TEXT = "text";
    private static final String KEY_QUESTION_A = "a";
    private static final String KEY_QUESTION_B = "b";
    private static final String KEY_QUESTION_C = "c";
    private static final String KEY_QUESTION_D = "d";
    private static final String KEY_QUESTION_E = "e";
    private static final String KEY_QUESTION_CORRECT_ANSWER = "correctAnswer";
    //</editor-fold>

    //<editor-fold desc="QuestionMedias Table Columns">
    private static final String KEY_QUESTION_MEDIA_ID = "id";
    private static final String KEY_QUESTION_MEDIA_CONTENT = "content";
    private static final String KEY_QUESTION_MEDIA_TYPE = "contentType";
    private static final String KEY_QUESTION_MEDIA_QUESTIONS_FK = "questionId";
    //</editor-fold>

    //<editor-fold desc="Exams Table Columns">
    private static final String KEY_EXAM_ID = "id";
    private static final String KEY_EXAM_USER_ID = "userId";
    private static final String KEY_EXAM_NAME = "name";
    private static final String KEY_EXAM_DIFFICULTY = "difficulty";
    private static final String KEY_EXAM_MIN_DURATION = "minDuration";
    private static final String KEY_EXAM_MAX_DURATION = "maxDuration";
    //</editor-fold>

    //<editor-fold desc="QuestionsExams Table Columns">
    private static final String KEY_QUESTIONS_EXAMS_EXAM_ID = "examId";
    private static final String KEY_QUESTIONS_EXAMS_QUESTION_ID = "questionId";
    private static final String KEY_QUESTIONS_EXAMS_POINT = "questionPoint";
    //</editor-fold>

    public DbHelper(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    // Called when the database connection is being configured.
    // Configure database settings for things like foreign key support, write-ahead logging, etc.
    @Override
    public void onConfigure(SQLiteDatabase db) {
        super.onConfigure(db);
        db.setForeignKeyConstraintsEnabled(true);
    }

    // Called when the database is created for the FIRST time.
    // If a database already exists on disk with the same DATABASE_NAME, this method will NOT be called.
    @Override
    public void onCreate(SQLiteDatabase db) {
        HashMap<String, String> createUserTableHashMap = new HashMap<String, String>() {{
            put(KEY_USER_ID, "INTEGER PRIMARY KEY");
            put(KEY_FIRST_NAME, "TEXT");
            put(KEY_LAST_NAME, "TEXT");
            put(KEY_USERNAME, "TEXT");
            put(KEY_PASSWORD, "TEXT");
            put(KEY_AVATAR, "BLOB");
            put(KEY_EMAIL, "TEXT");
            put(KEY_PHONE, "TEXT");
            put(KEY_DATE_OF_BIRTH, "TEXT");
        }};

        HashMap<String, String> createQuestionTableHashMap = new HashMap<String, String>() {{
            put(KEY_QUESTION_ID, "INTEGER PRIMARY KEY");
            put(KEY_QUESTION_USER_FK, "INTEGER REFERENCES " + TABLE_USERS);
            put(KEY_QUESTION_TEXT, "TEXT");
            put(KEY_QUESTION_A, "TEXT");
            put(KEY_QUESTION_B, "TEXT");
            put(KEY_QUESTION_C, "TEXT");
            put(KEY_QUESTION_D, "TEXT");
            put(KEY_QUESTION_E, "TEXT");
            put(KEY_QUESTION_CORRECT_ANSWER, "TEXT");
        }};

        HashMap<String, String> createQuestionMediasTableHashMap = new HashMap<String, String>() {{
            put(KEY_QUESTION_MEDIA_ID, "INTEGER PRIMARY KEY");
            put(KEY_QUESTION_MEDIA_QUESTIONS_FK, "INTEGER REFERENCES " + TABLE_QUESTIONS);
            put(KEY_QUESTION_MEDIA_CONTENT, "BLOB");
            put(KEY_QUESTION_MEDIA_TYPE, "TEXT");
        }};

        HashMap<String, String> createExamsTableHashMap = new HashMap<String, String>() {{
            put(KEY_EXAM_ID, "INTEGER PRIMARY KEY");
            put(KEY_EXAM_USER_ID, "INTEGER REFERENCES " + TABLE_USERS);
            put(KEY_EXAM_NAME, "TEXT");
            put(KEY_EXAM_DIFFICULTY, "INT");
            put(KEY_EXAM_MIN_DURATION, "INT");
            put(KEY_EXAM_MAX_DURATION, "INT");
        }};

        HashMap<String, String> createExamsQuestionsTableHashMap = new HashMap<String, String>() {{
            put(KEY_QUESTIONS_EXAMS_EXAM_ID, "INTEGER REFERENCES " + TABLE_EXAMS);
            put(KEY_QUESTIONS_EXAMS_QUESTION_ID, "INTEGER REFERENCES " + TABLE_QUESTIONS);
            put(KEY_QUESTIONS_EXAMS_POINT, "REAL");
        }};


        String CREATE_USERS_TABLE_SQL = _sqlBuilder.BuildCreateTableCommand(TABLE_USERS, createUserTableHashMap);
        String CREATE_QUESTIONS_TABLE_SQL = _sqlBuilder.BuildCreateTableCommand(TABLE_QUESTIONS, createQuestionTableHashMap);
        String CREATE_QUESTION_MEDIAS_TABLE_SQL = _sqlBuilder.BuildCreateTableCommand(TABLE_QUESTION_MEDIAS, createQuestionMediasTableHashMap);
        String CREATE_EXAMS_TABLE_SQL = _sqlBuilder.BuildCreateTableCommand(TABLE_EXAMS, createExamsTableHashMap);
        String CREATE_QUESTIONS_TO_EXAMS_TABLE_SQL = _sqlBuilder.BuildCreateTableCommand(TABLE_QUESTIONS_TO_EXAMS, createExamsQuestionsTableHashMap);

        db.execSQL(CREATE_USERS_TABLE_SQL);
        db.execSQL(CREATE_QUESTIONS_TABLE_SQL);
        db.execSQL(CREATE_QUESTION_MEDIAS_TABLE_SQL);
        db.execSQL(CREATE_EXAMS_TABLE_SQL);
        db.execSQL(CREATE_QUESTIONS_TO_EXAMS_TABLE_SQL);
    }

    // Called when the database needs to be upgraded.
    // This method will only be called if a database already exists on disk with the same DATABASE_NAME,
    // but the DATABASE_VERSION is different than the version of the database that exists on disk.
    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        if (oldVersion != newVersion) {
            // Simplest implementation is to drop all old tables and recreate them
            db.execSQL("DROP TABLE IF EXISTS " + TABLE_QUESTIONS_TO_EXAMS);
            //db.execSQL("DROP TABLE IF EXISTS " + TABLE_QUESTION_MEDIAS);
            //db.execSQL("DROP TABLE IF EXISTS " + TABLE_QUESTIONS);
            //db.execSQL("DROP TABLE IF EXISTS " + TABLE_EXAMS);
            //db.execSQL("DROP TABLE IF EXISTS " + TABLE_USERS);

            onCreate(db);
        }
    }

    public List<Person> getUsers() {
        List<Person> users = new ArrayList<Person>();

        try {
            ArrayList<String> selectColumns = new ArrayList<String>() {{ add("*"); }};

            SQLiteDatabase db = this.getReadableDatabase();
            String myFormat = "dd/MM/yyyy"; //In which you need put here
            SimpleDateFormat sdf = new SimpleDateFormat(myFormat, Locale.US);

            String sql = _sqlBuilder.BuildSelectCommand(TABLE_USERS, selectColumns, null);
            Cursor c = db.rawQuery(sql, null);

            if (c.moveToFirst()){
                do {
                    int userId = c.getInt(0);
                    String userFirstName = c.getString(1);
                    String userLastName = c.getString(2);
                    String userUsername = c.getString(3);
                    String userPassword = c.getString(4);
                    byte[] userAvatar = c.getBlob(5);
                    String userEmail = c.getString(6);
                    String userPhone = c.getString(7);
                    Date userDateOfBirth = new SimpleDateFormat("dd/MM/yyyy", Locale.US).parse(c.getString(8));

                    /*String avatarPath = userUsername+"_avatar.jpg";
                    File file = new File(avatarPath);
                    FileOutputStream avatarFile = new FileOutputStream(file);
                    avatarFile.write(userAvatar);*/
                    users.add(new Person(userId, userFirstName, userLastName, userEmail, userPassword, userAvatar, userPhone, userDateOfBirth));
                } while(c.moveToNext());
            }
            c.close();

            return users;
        } catch (Exception e) {
            e.printStackTrace();
            return users;
        }
    }

    public ArrayList<Question> getQuestionsByUserId(long userId) {
        ArrayList<Question> questions = new ArrayList<Question>();

        try {
            ArrayList<String> selectColumns = new ArrayList<String>() {{ add("*"); }};
            SQLiteDatabase db = this.getReadableDatabase();
            String sql = String.format(_sqlBuilder.BuildSelectQuestionsCommand(), userId);


            Cursor c = db.rawQuery(sql, null);

            if (c.moveToFirst()){
                do {
                    String questionOpt_A = c.getString(0);
                    String questionOpt_B = c.getString(1);
                    String questionOpt_C = c.getString(2);
                    String questionOpt_D = c.getString(3);
                    String questionOpt_E = c.getString(4);
                    long questionId = c.getLong(5);
                    String questionText = c.getString(6);
                    String correctAnswer = c.getString(7);


                    Question question;
                    if(!c.isNull(c.getColumnIndex("contentType"))) {
                        long mediaId = c.getLong(10);
                        String mediaContentType = c.getString(11);
                        byte[] mediaContent = c.getBlob(12);
                        QuestionMedia questionMedia = new QuestionMedia(mediaId, questionId, mediaContentType, mediaContent);
                        question = new Question(questionId, userId, questionText, questionOpt_A, questionOpt_B, questionOpt_C, questionOpt_D, questionOpt_E, correctAnswer, questionMedia);
                    } else {
                        question = new Question(questionId, userId, questionText, questionOpt_A, questionOpt_B, questionOpt_C, questionOpt_D, questionOpt_E, correctAnswer);
                    }

                    questions.add(question);
                } while(c.moveToNext());
            }
            c.close();

            return questions;
        } catch (Exception e) {
            e.printStackTrace();
            return questions;
        }
    }

    public ArrayList<Question> getQuestionsByExamId(long userId, long examId) {
        ArrayList<Question> questions = new ArrayList<Question>();

        try {
            ArrayList<String> selectColumns = new ArrayList<String>() {{ add("*"); }};
            SQLiteDatabase db = this.getReadableDatabase();
            String sql = String.format(_sqlBuilder.BuildSelectQuestionsByExamIdCommand(), examId);


            Cursor c = db.rawQuery(sql, null);

            if (c.moveToFirst()){
                do {
                    String questionOpt_A = c.getString(0);
                    String questionOpt_B = c.getString(1);
                    String questionOpt_C = c.getString(2);
                    String questionOpt_D = c.getString(3);
                    String questionOpt_E = c.getString(4);
                    long questionId = c.getLong(5);
                    String questionText = c.getString(6);
                    String correctAnswer = c.getString(7);


                    Question question;
                    if(!c.isNull(c.getColumnIndex("contentType"))) {
                        long mediaId = c.getLong(10);
                        String mediaContentType = c.getString(11);
                        byte[] mediaContent = c.getBlob(12);
                        QuestionMedia questionMedia = new QuestionMedia(mediaId, questionId, mediaContentType, mediaContent);
                        question = new Question(questionId, userId, questionText, questionOpt_A, questionOpt_B, questionOpt_C, questionOpt_D, questionOpt_E, correctAnswer, questionMedia);
                    } else {
                        question = new Question(questionId, userId, questionText, questionOpt_A, questionOpt_B, questionOpt_C, questionOpt_D, questionOpt_E, correctAnswer);
                    }

                    questions.add(question);
                } while(c.moveToNext());
            }
            c.close();

            return questions;
        } catch (Exception e) {
            e.printStackTrace();
            return questions;
        }
    }

    public ArrayList<Exam> getExamsByUserId(long userId) {
        ArrayList<Exam> exams = new ArrayList<Exam>();

        try {
            ArrayList<String> selectColumns = new ArrayList<String>() {{ add("*"); }};
            SQLiteDatabase db = this.getReadableDatabase();
            String sql = String.format(_sqlBuilder.BuildSelectExamsCommand(), userId);
            Cursor c = db.rawQuery(sql, null);
            if (c.moveToFirst()){
                do {
                    long examDifficulty = c.getLong(0);
                    long examMinDuration = c.getLong(1);
                    String examName = c.getString(2);
                    long examId = c.getLong(3);
                    long examMaxDuration = c.getLong(5);

                    Exam exam = new Exam(examId, userId, examName, examDifficulty, examMinDuration, examMaxDuration);
                    exams.add(exam);
                } while(c.moveToNext());
            }
            c.close();


            for (Exam exam: exams) {
                ArrayList<Question> questions = getQuestionsByExamId(userId, exam.getId());

                exam.setQuestions(questions);


            }



            return exams;
        } catch (Exception e) {
            e.printStackTrace();
            return exams;
        }
    }

    public Person insertUser(Person person) {
        try {
            SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy", Locale.US);

            ArrayList<String> insertUserKeys = new ArrayList<String>() {{
                add(KEY_FIRST_NAME);
                add(KEY_LAST_NAME);
                add(KEY_USERNAME);
                add(KEY_PASSWORD);
                add(KEY_EMAIL);
                add(KEY_PHONE);
                add(KEY_DATE_OF_BIRTH);
                add(KEY_AVATAR);
            }};

            String insertUserSql = _sqlBuilder.BuildInsertCommand(TABLE_USERS, insertUserKeys);

            SQLiteDatabase db = this.getWritableDatabase();
            db.beginTransaction();
            SQLiteStatement insertStmt = db.compileStatement(insertUserSql);

            insertStmt.clearBindings();

            insertStmt.bindString(1, person.getFirstName());
            insertStmt.bindString(2, person.getLastName());
            insertStmt.bindString(3, person.getUsername());
            insertStmt.bindString(4, person.getPassword());
            insertStmt.bindString(5, person.getEmail());
            insertStmt.bindString(6, person.getPhone());
            insertStmt.bindString(7, sdf.format(person.getBirthDate()));
            insertStmt.bindBlob(8, person.getAvatar());

            long userId = insertStmt.executeInsert();
            db.setTransactionSuccessful();
            db.endTransaction();

            person.setId(userId);

            return person;
        } catch (Exception e) {
            e.printStackTrace();
            return person;
        }
    }

    public Question insertQuestion(Question question) {
        try {
            ArrayList<String> insertQuestionKeys = new ArrayList<String>() {{
                add(KEY_QUESTION_USER_FK);
                add(KEY_QUESTION_TEXT);
                add(KEY_QUESTION_A);
                add(KEY_QUESTION_B);
                add(KEY_QUESTION_C);
                add(KEY_QUESTION_D);
                add(KEY_QUESTION_E);
                add(KEY_QUESTION_CORRECT_ANSWER);
            }};

            String insertQuestionSql = _sqlBuilder.BuildInsertCommand(TABLE_QUESTIONS, insertQuestionKeys);

            SQLiteDatabase db = this.getWritableDatabase();
            db.beginTransaction();
            SQLiteStatement insertquestionsStmt = db.compileStatement(insertQuestionSql);

            insertquestionsStmt.clearBindings();

            insertquestionsStmt.bindLong(1, question.getUserId());
            insertquestionsStmt.bindString(2, question.getText());
            insertquestionsStmt.bindString(3, question.getA());
            insertquestionsStmt.bindString(4, question.getB());
            insertquestionsStmt.bindString(5, question.getC());
            insertquestionsStmt.bindString(6, question.getD());
            insertquestionsStmt.bindString(7, question.getE());
            insertquestionsStmt.bindString(8, question.getCorrectAnswer());

            long questionId = insertquestionsStmt.executeInsert();
            db.setTransactionSuccessful();
            db.endTransaction();

            question.setId(questionId);

            if (question.getQuestionMedia() != null) {
                ArrayList<String> insertQuestionMediaKeys = new ArrayList<String>() {{
                    add(KEY_QUESTION_MEDIA_QUESTIONS_FK);
                    add(KEY_QUESTION_MEDIA_TYPE);
                    add(KEY_QUESTION_MEDIA_CONTENT);
                }};
                String insertQuestionMediaSql = _sqlBuilder.BuildInsertCommand(TABLE_QUESTION_MEDIAS, insertQuestionMediaKeys);
                db.beginTransaction();
                SQLiteStatement insertquestionMediasStmt = db.compileStatement(insertQuestionMediaSql);

                insertquestionMediasStmt.clearBindings();

                insertquestionMediasStmt.bindLong(1, question.getId());
                insertquestionMediasStmt.bindString(2, question.getQuestionMedia().getContentType());
                insertquestionMediasStmt.bindBlob(3, question.getQuestionMedia().getContent());

                long questionMediaId = insertquestionMediasStmt.executeInsert();
                db.setTransactionSuccessful();
                db.endTransaction();
                question.getQuestionMedia().setId(questionMediaId);
                question.getQuestionMedia().setQuestionId(question.getId());

            }
            return question;
        } catch (Exception e) {
            e.printStackTrace();
            return question;
        }
    }

    public Exam insertExam(Exam exam, ArrayList<Question> questions) {
        try {
            ArrayList<String> insertExamKeys = new ArrayList<String>() {{
                add(KEY_EXAM_NAME);
                add(KEY_EXAM_USER_ID);
                add(KEY_EXAM_DIFFICULTY);
                add(KEY_EXAM_MIN_DURATION);
                add(KEY_EXAM_MAX_DURATION);
            }};

            String insertExamSql = _sqlBuilder.BuildInsertCommand(TABLE_EXAMS, insertExamKeys);

            SQLiteDatabase db = this.getWritableDatabase();
            db.beginTransaction();
            SQLiteStatement insertExamStmt = db.compileStatement(insertExamSql);

            insertExamStmt.clearBindings();

            insertExamStmt.bindString(1, exam.getExamName());
            insertExamStmt.bindLong(2, exam.getUserId());
            insertExamStmt.bindLong(3, exam.getDifficulty());
            insertExamStmt.bindLong(4, exam.getMinDuration());
            insertExamStmt.bindLong(5, exam.getMaxDuration());

            long examId = insertExamStmt.executeInsert();
            db.setTransactionSuccessful();
            db.endTransaction();

            exam.setId(examId);
            ArrayList<Question> examQuestions = new ArrayList<>();
            if (questions != null && questions.size() != 0) {
                int questionCount = 0;
                for (Question question: questions ) {
                    if (question.getIsSelected()) {
                        examQuestions.add(question);
                    }
                }
                for (Question question: examQuestions ) {
                    if (question.getIsSelected()) {
                        ArrayList<String> insertExamQuestionKeys = new ArrayList<String>() {{
                            add(KEY_QUESTIONS_EXAMS_QUESTION_ID);
                            add(KEY_QUESTIONS_EXAMS_EXAM_ID);
                            add(KEY_QUESTIONS_EXAMS_POINT);
                        }};

                        String insertExamQuestionSql = _sqlBuilder.BuildInsertCommand(TABLE_QUESTIONS_TO_EXAMS, insertExamQuestionKeys);


                        db.beginTransaction();
                        SQLiteStatement insertExamQuestionStmt = db.compileStatement(insertExamQuestionSql);

                        insertExamQuestionStmt.clearBindings();

                        double maxPoint = 100;

                        insertExamQuestionStmt.bindLong(1, question.getId());
                        insertExamQuestionStmt.bindLong(2, exam.getId());
                        insertExamQuestionStmt.bindDouble(3, maxPoint / examQuestions.size());


                        long row = insertExamQuestionStmt.executeInsert();
                        db.setTransactionSuccessful();
                        db.endTransaction();
                    }

                }
            }
            exam.setQuestions(examQuestions);
            return exam;
        } catch (Exception e) {
            e.printStackTrace();
            return exam;
        }
    }

    public void deleteQuestion(Question question) {
        long rowCount = 0;
        SQLiteDatabase db = this.getWritableDatabase();
        @SuppressLint("DefaultLocale")
        String deleteQuestionMediaSql = "DELETE FROM " + TABLE_QUESTION_MEDIAS + " WHERE questionId=?;";
        db.beginTransaction();
        SQLiteStatement deleteQuestionMediaStmt = db.compileStatement(deleteQuestionMediaSql);
        deleteQuestionMediaStmt.clearBindings();
        deleteQuestionMediaStmt.bindLong(1, question.getId());
        rowCount = deleteQuestionMediaStmt.executeUpdateDelete();
        db.setTransactionSuccessful();
        db.endTransaction();


        @SuppressLint("DefaultLocale")
        String deleteExamQuestionsSql = "DELETE FROM " + TABLE_QUESTIONS_TO_EXAMS + " WHERE " + KEY_QUESTIONS_EXAMS_QUESTION_ID+ "=?;";
        db.beginTransaction();
        SQLiteStatement deleteExamQuestionStmt = db.compileStatement(deleteExamQuestionsSql);
        deleteExamQuestionStmt.clearBindings();
        deleteExamQuestionStmt.bindLong(1, question.getId());
        rowCount = deleteExamQuestionStmt.executeUpdateDelete();
        db.setTransactionSuccessful();
        db.endTransaction();


        String deleteQuestionSql = "DELETE FROM " + TABLE_QUESTIONS + " WHERE id=?;";
        db.beginTransaction();
        SQLiteStatement deleteQuestionStmt = db.compileStatement(deleteQuestionSql);
        deleteQuestionStmt.clearBindings();
        deleteQuestionStmt.bindLong(1, question.getId());
        rowCount = deleteQuestionStmt.executeUpdateDelete();
        db.setTransactionSuccessful();
        db.endTransaction();

    }

    public Question editQuestion(Question oldQuestion, Question newQuestion) {
        try {
            /*ArrayList<String> editQuestionKeys = new ArrayList<String>() {{
                add(KEY_QUESTION_USER_FK);
                add(KEY_QUESTION_TEXT);
                add(KEY_QUESTION_A);
                add(KEY_QUESTION_B);
                add(KEY_QUESTION_C);
                add(KEY_QUESTION_D);
                add(KEY_QUESTION_E);
                add(KEY_QUESTION_CORRECT_ANSWER);
            }};*/

            SQLiteDatabase db = this.getWritableDatabase();

            if (oldQuestion.getQuestionMedia() != null && newQuestion.getQuestionMedia() == null) {
                // Delete old media.
                db.beginTransaction();
                String sql = String.format("DELETE FROM " + TABLE_QUESTION_MEDIAS + " WHERE id=%d;", oldQuestion.getQuestionMedia().getId());
                Cursor c = db.rawQuery(sql, null);
                db.setTransactionSuccessful();
                db.endTransaction();

            }

            if (oldQuestion.getQuestionMedia() == null && newQuestion.getQuestionMedia() != null) {
                // Add new media.
                ArrayList<String> insertQuestionMediaKeys = new ArrayList<String>() {{
                    add(KEY_QUESTION_MEDIA_QUESTIONS_FK);
                    add(KEY_QUESTION_MEDIA_TYPE);
                    add(KEY_QUESTION_MEDIA_CONTENT);
                }};
                String insertQuestionMediaSql = _sqlBuilder.BuildInsertCommand(TABLE_QUESTION_MEDIAS, insertQuestionMediaKeys);
                db.beginTransaction();
                SQLiteStatement insertquestionMediasStmt = db.compileStatement(insertQuestionMediaSql);

                insertquestionMediasStmt.clearBindings();

                insertquestionMediasStmt.bindLong(1, newQuestion.getId());
                insertquestionMediasStmt.bindString(2, newQuestion.getQuestionMedia().getContentType());
                insertquestionMediasStmt.bindBlob(3, newQuestion.getQuestionMedia().getContent());

                long questionMediaId = insertquestionMediasStmt.executeInsert();
                db.setTransactionSuccessful();
                db.endTransaction();
                newQuestion.getQuestionMedia().setId(questionMediaId);
                newQuestion.getQuestionMedia().setQuestionId(newQuestion.getId());
            }

            if (oldQuestion.getQuestionMedia() != null && newQuestion.getQuestionMedia() != null) {
                if (oldQuestion.getQuestionMedia().getContent() != newQuestion.getQuestionMedia().getContent()) {
                    // content changed. update it.
                    db.beginTransaction();

                    String updateQuestionMediaSql = "UPDATE QuestionMedias SET "
                            + KEY_QUESTION_MEDIA_TYPE + " = ?, "
                            + KEY_QUESTION_MEDIA_CONTENT + " = ? "
                            + "WHERE id = ?";

                    SQLiteStatement updateQuestionMediaStmt = db.compileStatement(updateQuestionMediaSql);
                    updateQuestionMediaStmt.clearBindings();

                    updateQuestionMediaStmt.bindString(1, newQuestion.getQuestionMedia().getContentType());
                    updateQuestionMediaStmt.bindBlob(2, newQuestion.getQuestionMedia().getContent());
                    updateQuestionMediaStmt.bindLong(3, oldQuestion.getQuestionMedia().getId());


                    long rowCount = updateQuestionMediaStmt.executeUpdateDelete();

                    db.setTransactionSuccessful();
                    db.endTransaction();
                }
            }


            db.beginTransaction();

            String updateQuestionSql = "UPDATE Questions SET "
                    + KEY_QUESTION_TEXT + " = ?, "
                    + KEY_QUESTION_A + " = ?, "
                    + KEY_QUESTION_B + " = ?, "
                    + KEY_QUESTION_C + " = ?, "
                    + KEY_QUESTION_D + " = ?, "
                    + KEY_QUESTION_E + " = ?, "
                    + KEY_QUESTION_CORRECT_ANSWER + " = ? "
                    + "WHERE id = ?";


            SQLiteStatement editQuestionStmt = db.compileStatement(updateQuestionSql);

            editQuestionStmt.clearBindings();

            editQuestionStmt.bindString(1, newQuestion.getText());
            editQuestionStmt.bindString(2, newQuestion.getA());
            editQuestionStmt.bindString(3, newQuestion.getB());
            editQuestionStmt.bindString(4, newQuestion.getC());
            editQuestionStmt.bindString(5, newQuestion.getD());
            editQuestionStmt.bindString(6, newQuestion.getE());
            editQuestionStmt.bindString(7, newQuestion.getCorrectAnswer());
            editQuestionStmt.bindLong(8, newQuestion.getId());

            long rowCount = editQuestionStmt.executeUpdateDelete();
            db.setTransactionSuccessful();
            db.endTransaction();

            return newQuestion;
        } catch (Exception e) {
            e.printStackTrace();
            return oldQuestion;
        }
    }


    public boolean saveBytes(byte[] bytes, int id){

        boolean ret = false;
        SQLiteDatabase db = getWritableDatabase();


        try{

            String sql   =   "INSERT INTO IMAGES "
                    + " ( IMAGE_ID"
                    + ", IMAGE_BLOB"
                    + " ) VALUES(?,?)";

            SQLiteStatement insertStmt      =   db.compileStatement(sql);
            insertStmt.clearBindings();
            insertStmt.bindLong(1, id);
            insertStmt.bindBlob(2, bytes);
            insertStmt.executeInsert();

            db.setTransactionSuccessful();
            db.endTransaction();

            ret = true;
        }catch(Exception e){
            e.printStackTrace();
            ret = false;
        }

        return ret;
    }

    /*public byte[] getBytes( int id) throws Exception {

        byte[] ret = null;

        try {

            String selectQuery = "SELECT  I.IMAGE_BLOB "
                    + "         FROM IMAGES I WHERE I.IMAGE_ID = ?";

            SQLiteDatabase db = this.getReadableDatabase();
            Cursor c = db.rawQuery(selectQuery,new String[]{String.valueOf(id)});


            if (!c.isClosed() && c.moveToFirst() && c.getCount() > 0) {

                if (c.getBlob(c.getColumnIndex("IMAGE_BLOB")) != null)
                {
                    ret = c.getBlob(c.getColumnIndex("IMAGE_BLOB"));

                }
                c.close();
                if (db != null && db.isOpen())
                    db.close();
            }
            System.gc();
        } catch (Exception e) {
            System.gc();
            throw e;

        }
    }*/


    public boolean checkIfUserExists(String email) {
        try {
            ArrayList<String> selectColumns = new ArrayList<String>() {{ add(KEY_EMAIL); }};
            HashMap<String, String> whereParams = new HashMap<String, String>() {{
                put(KEY_EMAIL, email);
            }};

            SQLiteDatabase db = this.getReadableDatabase();

            String sql = _sqlBuilder.BuildSelectCommand(TABLE_USERS, selectColumns, whereParams);
            Cursor c = db.rawQuery(sql, null);

            if (!(c.moveToFirst()) || c.getCount() == 0){
                c.close();
                return false; // user not exists
            }
            c.close();
            return true; // user exists
        } catch (Exception e) {
            e.printStackTrace();
            // maybe any undhandled exception with email etc...
            // return true to prevent signup operation with non-clear data.
            return true;
        }
    }

    public long checkUsernameAndPassword(String username, String password) {
        List<Person> users = new ArrayList<Person>();
        try {
            ArrayList<String> selectColumns = new ArrayList<String>() {{ add("id"); }};
            HashMap<String, String> whereParams = new HashMap<String, String>() {{
                put(KEY_USERNAME, username);
                put(KEY_PASSWORD, password);
            }};

            SQLiteDatabase db = this.getReadableDatabase();
            String myFormat = "dd/MM/yyyy"; //In which you need put here


            String sql = _sqlBuilder.BuildSelectCommand(TABLE_USERS, selectColumns, whereParams);
            Cursor c = db.rawQuery(sql, null);


            if (!(c.moveToFirst()) || c.getCount() == 0){
                c.close();
                return -1; // user not exists
            }
            long userId = c.getLong(0);
            c.close(); // user exists
            return userId;
        } catch (Exception e) {
            e.printStackTrace();
            return -1; // user not exists
        }
    }

}