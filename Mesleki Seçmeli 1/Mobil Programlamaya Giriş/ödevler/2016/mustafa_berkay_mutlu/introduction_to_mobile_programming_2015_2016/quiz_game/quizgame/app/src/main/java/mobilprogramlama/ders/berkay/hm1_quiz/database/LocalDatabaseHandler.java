package mobilprogramlama.ders.berkay.hm1_quiz.database;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import java.util.ArrayList;

import mobilprogramlama.ders.berkay.hm1_quiz.database.DatabaseContract.PlayerAnswersContract;
import mobilprogramlama.ders.berkay.hm1_quiz.database.DatabaseContract.PlayersContract;
import mobilprogramlama.ders.berkay.hm1_quiz.database.DatabaseContract.QuestionsContract;
import mobilprogramlama.ders.berkay.hm1_quiz.model.Player;
import mobilprogramlama.ders.berkay.hm1_quiz.model.PlayerAnswer;
import mobilprogramlama.ders.berkay.hm1_quiz.model.Question;

/**
 * Created by mberk on 18.11.2015.
 */
public class LocalDatabaseHandler extends SQLiteOpenHelper {

    private static LocalDatabaseHandler sInstance;
    public static final int DATABASE_VERSION = 1;
    public static final String DATABASE_NAME = "QuizDatabase.db";

    private static final String SQL_CREATE_PLAYERS_TABLE =
            "CREATE TABLE " + PlayersContract.TABLE_NAME + " (" +
                    PlayersContract.COLUMN_NAME_PLAYER_ID + " INTEGER PRIMARY KEY," +
                    PlayersContract.COLUMN_NAME_PLAYER_NAME + " TEXT," +
                    PlayersContract.COLUMN_NAME_PLAYER_BIRTHDAY + " TEXT" +
            " )";

    private static final String SQL_CREATE_QUESTIONS_TABLE =
            "CREATE TABLE " + QuestionsContract.TABLE_NAME + " (" +
                    QuestionsContract.COLUMN_NAME_QUESTION_ID + " INTEGER PRIMARY KEY," +
                    QuestionsContract.COLUMN_NAME_QUESTION + " TEXT," +
                    QuestionsContract.COLUMN_NAME_QUESTION_ANSWER + " INTEGER DEFAULT 0" +
                    " )";

    private static final String SQL_CREATE_USER_ANSWERS_TABLE =
            "CREATE TABLE " + PlayerAnswersContract.TABLE_NAME + " (" +
                    PlayerAnswersContract.COLUMN_NAME_PLAYER_ANSWER_ID + " INTEGER PRIMARY KEY," +
                    PlayerAnswersContract.COLUMN_NAME_QUESTION_ID + " INTEGER NOT NULL," +
                    PlayerAnswersContract.COLUMN_NAME_PLAYER_ID + " INTEGER NOT NULL," +
                    PlayerAnswersContract.COLUMN_NAME_PLAYER_ANSWER + " INTEGER DEFAULT 0," +
                    " FOREIGN KEY (" + PlayerAnswersContract.COLUMN_NAME_QUESTION_ID + ") REFERENCES " + QuestionsContract.TABLE_NAME + "(" + QuestionsContract.COLUMN_NAME_QUESTION_ID + ")," +
                    " FOREIGN KEY (" + PlayerAnswersContract.COLUMN_NAME_PLAYER_ID + ") REFERENCES " + PlayersContract.TABLE_NAME + "(" + PlayersContract.COLUMN_NAME_PLAYER_ID+ ")" +
                    " )";

    private static final String SQL_DELETE_PLAYERS = "DROP TABLE IF EXISTS " + PlayersContract.TABLE_NAME;
    private static final String SQL_DELETE_QUESTIONS = "DROP TABLE IF EXISTS " + QuestionsContract.TABLE_NAME;
    private static final String SQL_DELETE_USER_ANSWERS = "DROP TABLE IF EXISTS " + PlayerAnswersContract.TABLE_NAME;

    public static synchronized LocalDatabaseHandler getInstance(Context context) {
        if (sInstance == null) {
            sInstance = new LocalDatabaseHandler(context);
        }
        return sInstance;
    }

    private LocalDatabaseHandler(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    public void onCreate(SQLiteDatabase db) {
        db.execSQL(SQL_CREATE_PLAYERS_TABLE);
        db.execSQL(SQL_CREATE_QUESTIONS_TABLE);
        db.execSQL(SQL_CREATE_USER_ANSWERS_TABLE);

        InitializeDatabase(db);
    }

    /**
     * Adds the required questions to database after creation.
     * @param db {@link SQLiteDatabase} object for connecting to database. We can not call getWritableDatabase() in this method because
     *                                 it causes an infinite loop.
     */
    private void InitializeDatabase(SQLiteDatabase db){
        AddQuestion(db, new Question("The Dude's wardrobe in 'The Big Lebowski' were Jeff Bridges' own clothes.", true));
        AddQuestion(db, new Question("Heath Ledger locked himself in a hotel room for a month to prepare for his role as The Joker in 'The Dark Knight'.", true));
        AddQuestion(db, new Question("Jim Carrey’s chipped tooth in 'Dumb & Dumber' is real.", true));
        AddQuestion(db, new Question("None of the James Bond films were ever approved by Chinese censors.", false));
        AddQuestion(db, new Question("Robin Williams often called Steven Spielberg during the filming of 'Schindler's List' to cheer him up with various jokes.", true));
        AddQuestion(db, new Question("In the German release of 'Indiana Jones and the Last Crusade' (1989) it was re-dubbed so that Indiana Jones and his father are fighting French industrialists.", false));
        AddQuestion(db, new Question("Nicolas Cage makes all his film role choices based on the position of the stars that week.", false));
        AddQuestion(db, new Question("Michael Keaton's real name is Michael Douglas.", true));
        AddQuestion(db, new Question("In 'Men in Black' the 'MiB' originally stood for 'Men in Blue' but Will Smith had it changed stating that he looked better in a black suit.", false));
        AddQuestion(db, new Question("James Woods was originally cast as Mr. Orange in Reservoir Dogs, but was fired after a fistfight with Quentin Tarantino.", false));
        AddQuestion(db, new Question(" The Titanic movie featured the song 'My Heart Will Go On' ?", true));
        AddQuestion(db, new Question("The Teenage Mutant Ninja Turtles are named after famous artists?", true));
        AddQuestion(db, new Question("Jim Carrey played God in the movie Bruce Almighty?", false));
        AddQuestion(db, new Question("Robert Downey Jr. played the leading role in 'The Iron Man Trilogy' ?", true));
        AddQuestion(db, new Question("Johnny Depp starred in all of the following movies: The Tourist, Alice in Wonderland and The Rum Diary?", true));
    }

    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL(SQL_DELETE_PLAYERS);
        db.execSQL(SQL_DELETE_QUESTIONS);
        db.execSQL(SQL_DELETE_USER_ANSWERS);

        onCreate(db);
    }

    public void onDowngrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        onUpgrade(db, oldVersion, newVersion);
    }

    /**
     * Adds a player to the datase.
     * @param player {@link Player} object to add the database.
     * @return New row ID.
     */
    public long AddPlayer(Player player) {
        // Gets the data repository in write mode
        SQLiteDatabase db = this.getWritableDatabase();

        // Create a new map of values, where column names are the keys
        ContentValues values = new ContentValues();
        values.put(PlayersContract.COLUMN_NAME_PLAYER_NAME, player.getName());
        values.put(PlayersContract.COLUMN_NAME_PLAYER_BIRTHDAY, player.getBirthday());

        // Insert the new row, returning the primary key value of the new row
        return db.insert(PlayersContract.TABLE_NAME, null, values);
    }

    /**
     * Adds a question to the datase.
     * @param db SQLiteDatabase object.
     * @param question Question object to add the database.
     * @return New row ID.
     */
    public long AddQuestion(SQLiteDatabase db, Question question){
        // Gets the data repository in write mode
        //SQLiteDatabase db = this.getWritableDatabase();

        // Create a new map of values, where column names are the keys
        ContentValues values = new ContentValues();
        values.put(QuestionsContract.COLUMN_NAME_QUESTION, question.getQuestion());
        values.put(QuestionsContract.COLUMN_NAME_QUESTION_ANSWER, question.getAnswer());

        // Insert the new row, returning the primary key value of the new row
        return db.insert(QuestionsContract.TABLE_NAME, null, values);
    }

    /**
     * Inserts player's answer to the database.
     * @param playerAnswer PlayerAnswer object that holds the info.
     * @return New row ID.
     */
    public long AddPlayerAnswer(PlayerAnswer playerAnswer){
        // Gets the data repository in write mode
        SQLiteDatabase db = this.getWritableDatabase();

        // Create a new map of values, where column names are the keys
        ContentValues values = new ContentValues();
        values.put(PlayerAnswersContract.COLUMN_NAME_QUESTION_ID, playerAnswer.getQuestionID());
        values.put(PlayerAnswersContract.COLUMN_NAME_PLAYER_ID, playerAnswer.getPlayerID());
        values.put(PlayerAnswersContract.COLUMN_NAME_PLAYER_ANSWER, playerAnswer.getPlayerAnswer());

        // Insert the new row, returning the primary key value of the new row
        return db.insert(PlayerAnswersContract.TABLE_NAME, null, values);
    }

    /**
     * Selects all players from the players table.
     * @return List of all players.
     */
    public ArrayList<Player> GetAllPlayers(){
        ArrayList<Player> playerList = new ArrayList<>();
        SQLiteDatabase db = this.getReadableDatabase();

        // Define a projection that specifies which columns from the database
        // you will actually use after this query.
        String[] projection = {
                PlayersContract.COLUMN_NAME_PLAYER_ID,
                PlayersContract.COLUMN_NAME_PLAYER_NAME,
                PlayersContract.COLUMN_NAME_PLAYER_BIRTHDAY
        };

        // How you want the results sorted in the resulting Cursor
        String sortOrder = PlayersContract.COLUMN_NAME_PLAYER_ID + " ASC";

        Cursor cursor = db.query(
                PlayersContract.TABLE_NAME,   // The table to query
                projection,             // The columns to return
                null,                   // The columns for the WHERE clause
                null,                   // The values for the WHERE clause
                null,                   // don't group the rows
                null,                   // don't filter by row groups
                sortOrder               // The sort order
        );

        if (cursor.moveToFirst()) {
            do {
                Player player = new Player(cursor.getInt(0), cursor.getString(1), cursor.getString(2));

                // Adding player to list
                playerList.add(player);
            } while (cursor.moveToNext());
        }

        cursor.close();

        return playerList;
    }

    /**
     * Selects all the questions in the database.
     * @return A list that includes all questions in the database.
     */
    public ArrayList<Question> GetAllQuestions(){
        ArrayList<Question> questionList = new ArrayList<>();
        SQLiteDatabase db = this.getReadableDatabase();

        // Define a projection that specifies which columns from the database
        // you will actually use after this query.
        String[] projection = {
                QuestionsContract.COLUMN_NAME_QUESTION_ID,
                QuestionsContract.COLUMN_NAME_QUESTION,
                QuestionsContract.COLUMN_NAME_QUESTION_ANSWER
        };

        // How you want the results sorted in the resulting Cursor
        String sortOrder = QuestionsContract.COLUMN_NAME_QUESTION_ID + " ASC";

        Cursor cursor = db.query(
                QuestionsContract.TABLE_NAME,   // The table to query
                projection,             // The columns to return
                null,                   // The columns for the WHERE clause
                null,                   // The values for the WHERE clause
                null,                   // don't group the rows
                null,                   // don't filter by row groups
                sortOrder               // The sort order
        );

        if (cursor.moveToFirst()) {
            do {
                Question question = new Question(cursor.getInt(0), cursor.getString(1), cursor.getInt(2) != 0);

                // Adding player to list
                questionList.add(question);
            } while (cursor.moveToNext());
        }

        cursor.close();

        return questionList;
    }

    /**
     * Selects the player by playerID.
     * @param playerID The ID of player you want to retrieve.
     * @return A player object correspounding to the playerID given.
     */
    public Player GetPlayer(long playerID){
        SQLiteDatabase db = this.getReadableDatabase();

        // Define a projection that specifies which columns from the database
        // you will actually use after this query.
        String[] projection = {
                PlayersContract.COLUMN_NAME_PLAYER_ID,
                PlayersContract.COLUMN_NAME_PLAYER_NAME,
                PlayersContract.COLUMN_NAME_PLAYER_BIRTHDAY
        };

        String selection = PlayersContract.COLUMN_NAME_PLAYER_ID + " = ?";
        String[] selectionArgs = { String.valueOf(playerID) };
        String sortOrder = PlayersContract.COLUMN_NAME_PLAYER_ID + " ASC";

        Cursor cursor = db.query(
                PlayersContract.TABLE_NAME, // The table to query
                projection,                 // The columns to return
                selection,                  // The columns for the WHERE clause
                selectionArgs,              // The values for the WHERE clause
                null,                       // don't group the rows
                null,                       // don't filter by row groups
                sortOrder                   // The sort order
        );

        if (cursor != null)
            cursor.moveToFirst();

        Player player = new Player(cursor.getInt(0), cursor.getString(1), cursor.getString(2));

        cursor.close();

        return player;
    }

    /**
     * Selects the questions by questionID.
     * @param questionID The ID of question you want to retrieve.
     * @return A question object correspounding to the questionID given.
     */
    public Question GetQuestion(long questionID){
        SQLiteDatabase db = this.getReadableDatabase();

        // Define a projection that specifies which columns from the database
        // you will actually use after this query.
        String[] projection = {
                QuestionsContract.COLUMN_NAME_QUESTION_ID,
                QuestionsContract.COLUMN_NAME_QUESTION,
                QuestionsContract.COLUMN_NAME_QUESTION_ANSWER
        };

        String selection = QuestionsContract.COLUMN_NAME_QUESTION_ID + " = ?";
        String[] selectionArgs = { String.valueOf(questionID) };
        String sortOrder = QuestionsContract.COLUMN_NAME_QUESTION_ID + " ASC";

        Cursor cursor = db.query(
                QuestionsContract.TABLE_NAME, // The table to query
                projection,                 // The columns to return
                selection,                  // The columns for the WHERE clause
                selectionArgs,              // The values for the WHERE clause
                null,                       // don't group the rows
                null,                       // don't filter by row groups
                sortOrder                   // The sort order
        );

        if (cursor != null)
            cursor.moveToFirst();

        Question question = new Question(cursor.getInt(0), cursor.getString(1), cursor.getInt(2) != 0);

        cursor.close();

        return question;
    }

    /**
     * Selects all answers given by a specific player only.
     * @param playerID The ID of player you want to retrieve his/her answers.
     * @return PlayerAnswers belong to the specific player.
     */
    public ArrayList<PlayerAnswer> GetPlayerAnswers(long playerID){
        ArrayList<PlayerAnswer> playerAnswerList = new ArrayList<>();
        SQLiteDatabase db = this.getReadableDatabase();

        // Define a projection that specifies which columns from the database
        // you will actually use after this query.
        String[] projection = {
                PlayerAnswersContract.COLUMN_NAME_PLAYER_ANSWER_ID,
                PlayerAnswersContract.COLUMN_NAME_QUESTION_ID,
                PlayerAnswersContract.COLUMN_NAME_PLAYER_ANSWER
        };

        String selection = PlayerAnswersContract.COLUMN_NAME_PLAYER_ID + " = ?";
        String[] selectionArgs = { String.valueOf(playerID) };
        String sortOrder = PlayerAnswersContract.COLUMN_NAME_PLAYER_ANSWER_ID + " ASC";

        Cursor cursor = db.query(
                PlayerAnswersContract.TABLE_NAME, // The table to query
                projection,                 // The columns to return
                selection,                  // The columns for the WHERE clause
                selectionArgs,              // The values for the WHERE clause
                null,                       // don't group the rows
                null,                       // don't filter by row groups
                sortOrder                   // The sort order
        );

        if (cursor.moveToFirst()) {
            do {
                playerAnswerList.add(new PlayerAnswer(cursor.getInt(0), cursor.getInt(1), playerID, cursor.getInt(2) != 0));
            } while (cursor.moveToNext());
        }

        cursor.close();

        return playerAnswerList;
    }

    /**
     * Calculates the player's score.
     * @param playerID The ID of the player you want to calculate his/her score.
     * @return Integer game score.
     */
    public int GetPlayerScore(long playerID){
        int score = 0;
        ArrayList<PlayerAnswer> playerAnswerList = GetPlayerAnswers(playerID);

        for(PlayerAnswer playerAnswer : playerAnswerList){
            if(playerAnswer.getPlayerAnswer() == GetQuestion(playerAnswer.getQuestionID()).getAnswer()){
                score += 10;
            }
        }

        return score;
    }
}
