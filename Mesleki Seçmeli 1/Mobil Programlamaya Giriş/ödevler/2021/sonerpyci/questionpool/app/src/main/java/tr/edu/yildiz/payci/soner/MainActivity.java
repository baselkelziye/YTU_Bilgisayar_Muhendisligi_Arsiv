package tr.edu.yildiz.payci.soner;

import android.content.Intent;
import android.content.SharedPreferences;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import tr.edu.yildiz.payci.soner.model.UserBase;
import tr.edu.yildiz.payci.soner.DAL.DbHelper;

public class MainActivity extends AppCompatActivity
{
    public static final String MY_PREFS_NAME = "Question_Pool_SP";
    DbHelper dbHelper;
    EditText username;
    EditText password;
    Button btnSignIn;
    Button btnSignUp;
    Integer attempt;

    private void cleanTextBoxes()
    {
        username.setText("");
        password.setText("");
    }

    private long checkPerson()
    {
        return dbHelper.checkUsernameAndPassword(username.getText().toString(), UserBase.convertStringToSHA256(password.getText().toString()));
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ActionBar actionBar = getSupportActionBar();
        actionBar.hide();

        createSharedPreferences();
        defineVariables();
        defineListeners();
    }

    public void createSharedPreferences() {
        //MY_PREFS_NAME - a static String variable like:
        //public static final String MY_PREFS_NAME = "MyPrefsFile";
        SharedPreferences.Editor editor = getSharedPreferences(MY_PREFS_NAME, MODE_PRIVATE).edit();
        editor.putInt("examDifficulty", 3);
        editor.putInt("examMinDuration", 15);
        editor.putInt("examMaxDuration", 90);
        editor.apply();
    }

    public void defineVariables() {
        attempt = 0;
        dbHelper = new DbHelper(this);
        username = (EditText) findViewById(R.id.usernameTxt);
        password = (EditText) findViewById(R.id.passwordTxt);
        btnSignIn = (Button) findViewById(R.id.btnSignIn);
        btnSignUp = (Button) findViewById(R.id.btnSignUp);
    }

    public void defineListeners() {
        btnSignIn.setOnClickListener((v -> {
            long userId = checkPerson();
            if (userId != -1) {
                attempt = 0;
                Toast.makeText(MainActivity.this, String.format( "Logged In Successfully!" , 3-attempt), Toast.LENGTH_SHORT).show();
                Intent intent = new Intent(MainActivity.this, ScreenSlideFragmentPage.class);
                intent.putExtra("userId", userId);
                this.startActivity(intent);
            } else {
                attempt += 1;
                Toast.makeText(MainActivity.this, String.format( "Wrong username/password. You have {%d} Attempts." , 3-attempt), Toast.LENGTH_SHORT).show();
                if (attempt >= 3) {
                    btnSignIn.setEnabled(false);
                    Toast.makeText(MainActivity.this, "Wrong Credentials passed three times in a row. Please Sign-Up First..", Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent(MainActivity.this, SignUpActivity.class);
                    this.startActivity(intent);
                }
            }
        }));
        btnSignUp.setOnClickListener((v -> {
            Intent intent = new Intent(MainActivity.this, SignUpActivity.class);
            this.startActivity(intent);
        }));
    }
}