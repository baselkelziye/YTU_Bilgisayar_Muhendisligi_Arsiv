package tr.edu.yildiz.altugnumanyildiz;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class QuestionsActivity extends AppCompatActivity {
    ArrayList<Question> questionList;

    private RecyclerView mRecyclerView;
    private QuestionsAdapter mAdapter;
    private RecyclerView.LayoutManager mLayoutManager;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_questions);

        createQuestionList();
        buildRecyclerView();



    }

    public void createQuestionList(){
        questionList = new ArrayList<>();
        dbOperation db = new dbOperation(getApplicationContext());
        questionList = db.takeAllQuestions(1);
    }

    public void buildRecyclerView() {
        mRecyclerView = findViewById(R.id.recyclerView);
        mRecyclerView.setHasFixedSize(true);
        mLayoutManager = new LinearLayoutManager(this);
        mAdapter = new QuestionsAdapter(questionList);

        mRecyclerView.setLayoutManager(mLayoutManager);
        mRecyclerView.setAdapter(mAdapter);

        mAdapter.setOnItemClickListener(new QuestionsAdapter.OnItemClickListener() {
            @Override
            public void onItemClick(int position) {
                int tempQuestionID = questionList.get(position).getQuestionID();
                Toast.makeText(getApplicationContext(),"Question ID " + tempQuestionID,Toast.LENGTH_LONG).show();

                Intent intent = new Intent(getApplicationContext(),EditQuestionActivity.class);
                intent.putExtra("questionIDPass",tempQuestionID);
                intent.putExtra("questionPass",questionList.get(position));
                startActivity(intent);
            }
        });
    }
}