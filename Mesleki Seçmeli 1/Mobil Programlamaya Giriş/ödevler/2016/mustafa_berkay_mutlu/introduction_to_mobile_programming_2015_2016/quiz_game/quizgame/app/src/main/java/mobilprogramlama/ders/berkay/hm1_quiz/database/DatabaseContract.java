package mobilprogramlama.ders.berkay.hm1_quiz.database;

import android.provider.BaseColumns;

/**
 * Created by mberk on 18.11.2015.
 */
public final class DatabaseContract {
    // To prevent someone from accidentally instantiating the contract class,
    // give it an empty constructor.
    public DatabaseContract() {}

    /* Inner class that defines the table contents */
    public static abstract class PlayersContract implements BaseColumns {
        public static final String TABLE_NAME = "players";
        public static final String COLUMN_NAME_PLAYER_ID = "player_id";
        public static final String COLUMN_NAME_PLAYER_NAME = "player_name";
        public static final String COLUMN_NAME_PLAYER_BIRTHDAY = "player_birthday";
    }

    public static abstract class QuestionsContract implements BaseColumns {
        public static final String TABLE_NAME = "questions";
        public static final String COLUMN_NAME_QUESTION_ID = "question_id";
        public static final String COLUMN_NAME_QUESTION = "question";
        public static final String COLUMN_NAME_QUESTION_ANSWER = "question_answer";
    }

    public static abstract class PlayerAnswersContract implements BaseColumns {
        public static final String TABLE_NAME = "player_answers";
        public static final String COLUMN_NAME_PLAYER_ANSWER_ID = "player_answer_id";
        public static final String COLUMN_NAME_QUESTION_ID = "question_id";
        public static final String COLUMN_NAME_PLAYER_ID = "player_id";
        public static final String COLUMN_NAME_PLAYER_ANSWER = "player_answer";
    }

}
