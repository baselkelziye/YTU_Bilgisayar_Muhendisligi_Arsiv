package mobilprogramlama.ders.berkay.hm1_quiz.activity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import java.util.ArrayList;

import mobilprogramlama.ders.berkay.hm1_quiz.R;
import mobilprogramlama.ders.berkay.hm1_quiz.database.DatabaseContract;
import mobilprogramlama.ders.berkay.hm1_quiz.database.LocalDatabaseHandler;
import mobilprogramlama.ders.berkay.hm1_quiz.model.Player;
import mobilprogramlama.ders.berkay.hm1_quiz.model.PlayerAnswer;
import mobilprogramlama.ders.berkay.hm1_quiz.model.Question;

public class QuizActivity extends Activity {

    private final String CURRENT_INDEX = "current_index";

    private int mCurrentIndex = 0;

    private ArrayList<Question> mQuestionBank; // List of questions gathered from database.
    private LocalDatabaseHandler mLocalDatabaseHandler; // DatabaseHandler object.
    private Player mPlayer; // Current Player.

    private TextView txtView_quizActivity_question;
    private TextView txtView_quizActivity_playerName;
    private TextView txtView_quizActivity_currentQuestionNumber;
    private TextView txtView_quizActivity_totalQuestionNumber;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_quiz);

        txtView_quizActivity_question = (TextView) findViewById(R.id.txtView_quizActivity_question);
        txtView_quizActivity_playerName = (TextView) findViewById(R.id.txtView_quizActivity_playerName);
        txtView_quizActivity_currentQuestionNumber = (TextView) findViewById(R.id.txtView_quizActivity_currentQuestionNumber);
        txtView_quizActivity_totalQuestionNumber = (TextView) findViewById(R.id.txtView_quizActivity_totalQuestionNumber);

        mLocalDatabaseHandler = LocalDatabaseHandler.getInstance(this);
        mQuestionBank = mLocalDatabaseHandler.GetAllQuestions();

        if(savedInstanceState != null){
            mCurrentIndex = savedInstanceState.getInt(CURRENT_INDEX);

            mPlayer = mLocalDatabaseHandler.GetPlayer(savedInstanceState.getLong(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_ID));
        }
        else{
            String playerName = getIntent().getStringExtra(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_NAME);
            String playerBirthday = getIntent().getStringExtra(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_BIRTHDAY);

            long playerID = mLocalDatabaseHandler.AddPlayer(new Player(playerName, playerBirthday));
            mPlayer = mLocalDatabaseHandler.GetPlayer(playerID);
        }

    }

    @Override
    protected void onStart() {
        super.onStart();

        txtView_quizActivity_question.setText(mQuestionBank.get(mCurrentIndex).getQuestion());
        txtView_quizActivity_playerName.setText(mPlayer.getName());
        txtView_quizActivity_currentQuestionNumber.setText(String.valueOf(mCurrentIndex + 1));
        txtView_quizActivity_totalQuestionNumber.setText(String.valueOf(mQuestionBank.size()));
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);

        outState.putInt(CURRENT_INDEX, mCurrentIndex);
        outState.putLong(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_ID, mPlayer.getPlayerID());
    }

    public void btn_quizAcitivty_answerTrue_onClick(View view){
        CheckAnswer(true);
        SetNextQuestion();
    }

    public void btn_quizAcitivty_answerFalse_onClick(View view){
        CheckAnswer(false);
        SetNextQuestion();
    }

    public void btn_quizAcitivty_next_onClick(View view){
        SetNextQuestion();
    }

    private void CheckAnswer(boolean playerAnswer){
//        int messageResId;

        // Add player's answer to database.
        mLocalDatabaseHandler.AddPlayerAnswer(
            new PlayerAnswer(mQuestionBank.get(mCurrentIndex).getQuestionID(),
            mPlayer.getPlayerID(),
            playerAnswer));

        // Show a Toast according to player's answer is corrent or not.
//        if(playerAnswer == mQuestionBank.get(mCurrentIndex).getAnswer()){
//            messageResId = R.string.toast_correct;
//        }
//        else{
//            messageResId = R.string.toast_incorrect;
//        }
//
//        Toast.makeText(this, messageResId, Toast.LENGTH_SHORT).show();
    }

    /**
     * Sets the next question in  the {@link QuizActivity#mQuestionBank}.
     */
    private void SetNextQuestion(){
        mCurrentIndex = (mCurrentIndex+1) % mQuestionBank.size();

        // If the last question is answered:
        if(mCurrentIndex == 0){
            Intent gameFinishedIntent = new Intent(this, GameFinishedActivity.class);
            // Put the playerID to intent for GameFinishedActivity.
            gameFinishedIntent.putExtra(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_ID, mPlayer.getPlayerID());
            // Clear the Activity from the Activity stack:
            gameFinishedIntent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_NEW_TASK);
            startActivity(gameFinishedIntent);
            QuizActivity.this.finish();
        }
        else { // If the last is question is not answered yet:
            Question question = mQuestionBank.get(mCurrentIndex);
            txtView_quizActivity_question.setText(question.getQuestion());
            txtView_quizActivity_currentQuestionNumber.setText(String.valueOf(mCurrentIndex+1));
        }
    }


}
