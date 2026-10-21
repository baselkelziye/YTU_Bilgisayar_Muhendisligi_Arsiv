package mobilprogramlama.ders.berkay.hm1_quiz.activity;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.ListView;
import android.widget.TextView;

import mobilprogramlama.ders.berkay.hm1_quiz.R;
import mobilprogramlama.ders.berkay.hm1_quiz.adapter.AnswersAdapter;
import mobilprogramlama.ders.berkay.hm1_quiz.database.DatabaseContract;
import mobilprogramlama.ders.berkay.hm1_quiz.database.LocalDatabaseHandler;

public class GameFinishedActivity extends AppCompatActivity {

    private ListView listView_gameFinishedActivity_answers;
    private TextView txtView_gameFinishedActivity_score;
    private long playerID;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_game_finished);

        listView_gameFinishedActivity_answers = (ListView) findViewById(R.id.listView_gameFinishedActivity_answers);
        txtView_gameFinishedActivity_score = (TextView) findViewById(R.id.txtView_gameFinishedActivity_score);

        this.playerID = getIntent().getLongExtra(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_ID, 0);
        AnswersAdapter answersAdapter = new AnswersAdapter(getApplicationContext(), playerID);
        listView_gameFinishedActivity_answers.setAdapter(answersAdapter);

    }

    @Override
    protected void onStart() {
        super.onStart();

        txtView_gameFinishedActivity_score.setText(String.valueOf(LocalDatabaseHandler.
                        getInstance(getApplicationContext()).GetPlayerScore(playerID)));
    }
}
