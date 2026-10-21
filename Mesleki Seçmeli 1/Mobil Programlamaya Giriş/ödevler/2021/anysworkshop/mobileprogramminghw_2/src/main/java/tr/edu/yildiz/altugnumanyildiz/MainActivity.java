package tr.edu.yildiz.altugnumanyildiz;

import android.content.Intent;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import android.widget.VideoView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private VideoView videoBG;
    MediaPlayer mMediaPlayer;
    int mCurrentVideoPosition;
    Button loginButton;
    Button signUpButton;
    EditText editTextEmail;
    EditText editTextPassword;
    int attempt = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        editTextEmail = (EditText) findViewById(R.id.loginEmail);
        editTextPassword = (EditText) findViewById(R.id.loginPassword);

        loginButton = (Button) findViewById(R.id.login);
        loginButton.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View view) {
                String email = editTextEmail.getText().toString();
                String password = editTextPassword.getText().toString();
                dbOperation db = new dbOperation(getApplicationContext());
                User user = db.login(email,password);
                if (user != null) {
                    openMenu(user);
                    Toast.makeText(getApplicationContext(),"You have successfully logged in",Toast.LENGTH_LONG).show();
                } else {
                    attempt++;
                    Toast.makeText(getApplicationContext(),"Email and Password do not match!",Toast.LENGTH_LONG).show();
                    if(attempt >= 3){
                        attempt = 0;
                        openDialog();
                    }
                }

            }
        });

        signUpButton = (Button) findViewById(R.id.register);
        signUpButton.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View view) {
                openRegistration();
            }
        });
        // Hook up the VideoView to our UI.
        videoBG = (VideoView) findViewById(R.id.videoView);


        // Build your video Uri
        Uri uri = Uri.parse("android.resource://" // First start with this,
                + getPackageName() // then retrieve your package name,
                + "/" // add a slash,
                + R.raw.log_bg_v1); // and then finally add your video resource. Make sure it is stored
        // in the raw folder.
        // Set the new Uri to our VideoView
        videoBG.setVideoURI(uri);
        // Start the VideoView

        videoBG.start();

        // Set an OnPreparedListener for our VideoView. For more information about VideoViews,
        // check out the Android Docs: https://developer.android.com/reference/android/widget/VideoView.html
        videoBG.setOnPreparedListener(new MediaPlayer.OnPreparedListener() {
            @Override
            public void onPrepared(MediaPlayer mediaPlayer) {
                mMediaPlayer = mediaPlayer;

                // We want our video to play over and over so we set looping to true.
                mMediaPlayer.setLooping(true);
                // We then seek to the current posistion if it has been set and play the video.
                if (mCurrentVideoPosition != 0) {
                    mMediaPlayer.seekTo(mCurrentVideoPosition);
                    mMediaPlayer.start();
                }
            }
        });
    }

    public void openDialog(){
        Dialogue dialogue = new Dialogue();
        dialogue.show(getSupportFragmentManager(),"Dialogue Example");
    }

    public void openRegistration(){
        Intent intent = new Intent(this,RegistrationActivity.class);
        startActivity(intent);
    }

    public void openMenu(User user){
        Intent intent = new Intent(this,MenuActivity.class);
        intent.putExtra("Logged in User",user);

        startActivity(intent);
    }

    @Override
    protected void onPause() {
        super.onPause();
        // Capture the current video position and pause the video.
        mCurrentVideoPosition = mMediaPlayer.getCurrentPosition();
        videoBG.pause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        // Restart the video when resuming the Activity
        videoBG.start();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        // When the Activity is destroyed, release our MediaPlayer and set it to null.
        mMediaPlayer.release();
        mMediaPlayer = null;
    }
}