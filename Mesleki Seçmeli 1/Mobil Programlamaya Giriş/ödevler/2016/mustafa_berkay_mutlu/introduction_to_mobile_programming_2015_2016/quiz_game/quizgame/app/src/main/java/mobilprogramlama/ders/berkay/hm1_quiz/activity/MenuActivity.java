package mobilprogramlama.ders.berkay.hm1_quiz.activity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import mobilprogramlama.ders.berkay.hm1_quiz.R;
import mobilprogramlama.ders.berkay.hm1_quiz.database.DatabaseContract;

public class MenuActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);
    }

    public void btn_menuActivity_play_onClick(View view){
        Intent quizIntent = new Intent(this, QuizActivity.class);
        quizIntent.putExtra(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_NAME,
                getIntent().getStringExtra(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_NAME));
        quizIntent.putExtra(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_BIRTHDAY,
                getIntent().getStringExtra(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_BIRTHDAY));
        startActivity(quizIntent);
    }

    public void btn_menuActivity_scores_onClick(View view){
        Intent scoreBoardIntent = new Intent(this, ScoreboardActivity.class);
        startActivity(scoreBoardIntent);
    }

}
