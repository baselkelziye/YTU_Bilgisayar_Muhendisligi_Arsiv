package tr.edu.yildiz.altugnumanyildiz;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;
import android.widget.ImageView;

import androidx.appcompat.app.AppCompatActivity;
public class MenuActivity extends AppCompatActivity {

    /*
    TextView textViewName;
    TextView textViewSurName;
    TextView textViewEmail;
    TextView textViewPassword;
    TextView textViewPhoneNumber;*/
    ImageButton imageButtonQuestions;
    ImageView testImage;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

      /*  textViewName = (TextView) findViewById(R.id.testtextView);
        textViewSurName = (TextView) findViewById(R.id.testtextView2);
        textViewEmail = (TextView) findViewById(R.id.testtextView3);
        textViewPassword = (TextView) findViewById(R.id.testtextView4);
        textViewPhoneNumber = (TextView) findViewById(R.id.testtextView5);*/

        Intent intent = getIntent();
        User user = intent.getParcelableExtra("Logged in User");

/*
        testImage = (ImageView) findViewById(R.id.testImage);
        testImage.setImageBitmap(user.getImage());*/

/*
        imageButtonQuestions = (ImageButton) findViewById(R.id.imgButtonAddQuestions);
        imageButtonQuestions.setOnContextClickListener(new View.OnContextClickListener() {


            @Override
            public boolean onContextClick(View view) {

                return false;
            }
        });*/

        /*
        textViewName.setText(user.getName());
        textViewSurName.setText(user.getSurName());
        textViewEmail.setText(user.getEmail());
        textViewPassword.setText(user.getPassword());
        textViewPhoneNumber.setText(user.getPhoneNumber());*/

    }


    public void openAddQuestionPage(View view){
        Intent intent = new Intent(this,AddQuestionActivity.class);
        startActivity(intent);
    }

    public void openQuestionsPage(View view){
        Intent intent = new Intent(this,QuestionsActivity.class);
        startActivity(intent);
    }

    public void openExamSettingsPage(View view){
        Intent intent = new Intent(this,ExamSettingsActivity.class);
        startActivity(intent);
    }
}