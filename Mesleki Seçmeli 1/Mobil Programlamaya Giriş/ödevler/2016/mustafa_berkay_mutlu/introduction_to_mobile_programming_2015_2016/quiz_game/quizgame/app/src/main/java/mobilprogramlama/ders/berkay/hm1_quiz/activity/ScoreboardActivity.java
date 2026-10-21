package mobilprogramlama.ders.berkay.hm1_quiz.activity;

import android.app.Activity;
import android.os.Bundle;
import android.widget.ListView;

import mobilprogramlama.ders.berkay.hm1_quiz.R;
import mobilprogramlama.ders.berkay.hm1_quiz.adapter.ScoreBoardAdapter;

public class ScoreboardActivity extends Activity {

    private ListView mScoreBoard;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scoreboard);

        mScoreBoard = (ListView) findViewById(R.id.listView_scoreboardActivity_scoreboard);
        mScoreBoard.setAdapter(new ScoreBoardAdapter(getApplicationContext()));
        mScoreBoard.addHeaderView(getLayoutInflater().inflate(R.layout.list_view_header_scoreboard, null));
    }

}
