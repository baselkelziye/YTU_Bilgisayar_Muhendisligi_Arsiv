package mobil.prog.music_app;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.SeekBar;
import android.widget.TextView;

import java.io.IOException;
import java.util.ArrayList;

import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.widget.Toast;


public class MusicActivity extends AppCompatActivity implements SensorEventListener{

    private Sensor mySensor;
    private SensorManager SM;
    private AudioManager myAudioManager;
    private Sensor lightSensor;
    private SensorManager lightSensorManager;

    // initialize işlemleri

    TextView title, activeTime, totalTime;
    SeekBar bar;
    ImageView nextBtn, previousBtn, musicIcon, pausePlayBtn, arrowDown, deleteBtn;

    ArrayList<AudioModel> songsList;
    AudioModel currentSong;

    MediaPlayer mediaPlayer = MyMediaPlayer.getInstance();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_music);
        //---------------------------------------
        title = findViewById(R.id.song_title);
        activeTime = findViewById(R.id.timeNow);
        totalTime = findViewById(R.id.timeTotal);

        bar = findViewById(R.id.bar);

        nextBtn = findViewById(R.id.next);
        previousBtn = findViewById(R.id.previous);
        musicIcon = findViewById(R.id.icon_asset);
        pausePlayBtn = findViewById(R.id.pause_play);
        arrowDown = findViewById(R.id.arrow_down);
        deleteBtn = findViewById(R.id.delete_button);


        myAudioManager= (AudioManager) getSystemService(Context.AUDIO_SERVICE);

        title.setSelected(true);

        // put ile eklenen listenin alımı
        songsList = (ArrayList<AudioModel>) getIntent().getSerializableExtra("LIST");

        setMusic();

        //liste ekranına dönüş
        arrowDown.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent_back = new Intent(MusicActivity.this, SongslistActivity.class);
                startActivity(intent_back);
            }
        });


        SM = (SensorManager) getSystemService(SENSOR_SERVICE);
        // İvmeölçer
        mySensor = SM.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        SM.registerListener(this, mySensor, SensorManager.SENSOR_DELAY_NORMAL);


        // Işık sensörü
        lightSensorManager = (SensorManager) getSystemService(Service.SENSOR_SERVICE);
        lightSensor = lightSensorManager.getDefaultSensor(Sensor.TYPE_LIGHT);
        lightSensorManager.registerListener(this, lightSensor, SensorManager.SENSOR_DELAY_NORMAL); //eklendi

    }

    protected void onResume() {
        super.onResume();
        SM.registerListener(this, mySensor, SensorManager.SENSOR_DELAY_FASTEST);
        myAudioManager.setMode(AudioManager.MODE_IN_CALL);

        lightSensorManager.registerListener(this, lightSensor, SensorManager.SENSOR_DELAY_NORMAL);

    }

    double accCurrent, accPrevious;

    int i = 0;
    int flagLight, flagMove;

    @Override
    public void onSensorChanged(SensorEvent sensorEvent) {


        if(sensorEvent.sensor.getType() == Sensor.TYPE_LIGHT){
            if(sensorEvent.values[0] > 50){
                // hareketsiz, masada ve düz
                Log.e("Lux: ", String.valueOf(sensorEvent.values[0]));
                flagLight = 1;
            }
            else{
                flagLight = 0;
            }
            Log.e("Flag: ", String.valueOf(flagLight));
        }

    if(sensorEvent.sensor.getType() == Sensor.TYPE_ACCELEROMETER){

        accCurrent = sensorEvent.values[0];
        double changeInAcc = Math.abs(accCurrent - accPrevious);
        accPrevious = accCurrent;


        if(changeInAcc == 0){
            i++;
        }
        else{
            i = 0;
            myAudioManager.setStreamVolume(AudioManager.STREAM_MUSIC, 14, AudioManager.FLAG_SHOW_UI);
        }

        if(i > 75){
            flagMove = 1;
        }
        else{
            flagMove = 0;
        }

        if(flagLight==1 && flagMove==1){
            Toast.makeText(MusicActivity.this, "Music is muted.", Toast.LENGTH_SHORT).show();
            myAudioManager.adjustStreamVolume(AudioManager.STREAM_MUSIC, AudioManager.ADJUST_LOWER, AudioManager.FLAG_SHOW_UI);
        }
        else{
            myAudioManager.setStreamVolume(AudioManager.STREAM_MUSIC, 14, AudioManager.FLAG_SHOW_UI);
        }

    }

    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int i) {
        // no using
    }

    void setMusic(){
        currentSong = songsList.get(MyMediaPlayer.activeIndex);

        title.setText(currentSong.getTitle());

        int minutes = Integer.parseInt(currentSong.getDuration())/60000;
        int seconds = (Integer.parseInt(currentSong.getDuration())%60000)/1000;
        if(seconds < 10){
            String template = "0" + seconds;
            totalTime.setText(minutes + ":" + template);
        }
        else
            totalTime.setText(minutes + ":" + seconds);

        pausePlayBtn.setOnClickListener(v -> pausePlayMusic());
        nextBtn.setOnClickListener(v -> nextMusic());
        previousBtn.setOnClickListener(v -> previousMusic());

        playMusic();

        MusicActivity.this.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if(mediaPlayer != null){
                    bar.setProgress(mediaPlayer.getCurrentPosition());
                    int minutes = Integer.parseInt(String.valueOf(mediaPlayer.getCurrentPosition()))/60000;
                    int seconds = (Integer.parseInt(String.valueOf(mediaPlayer.getCurrentPosition()))%60000)/1000;
                    if(seconds < 10){
                        String template = "0" + seconds;
                        activeTime.setText(minutes + ":" + template);
                    }
                    else
                        activeTime.setText(minutes + ":" + seconds);

                    if(mediaPlayer.isPlaying()){
                        pausePlayBtn.setImageResource(R.drawable.pause_button);
                    }
                    else{
                        pausePlayBtn.setImageResource(R.drawable.play_button);
                    }

                }
                new Handler().postDelayed(this, 100);
            }
        });

        bar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int i, boolean b) {
                if(mediaPlayer != null && b){
                    mediaPlayer.seekTo(i);
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });


    }


    private void playMusic(){
        mediaPlayer.reset();
        try {
            mediaPlayer.setDataSource(currentSong.getPath());
            mediaPlayer.prepare();
            mediaPlayer.start();
            bar.setProgress(0);
            bar.setMax(mediaPlayer.getDuration());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void nextMusic(){

        // son şarkı ise return
        if(MyMediaPlayer.activeIndex == songsList.size() -1){
            return;
        }

        MyMediaPlayer.activeIndex += 1;
        mediaPlayer.reset();
        setMusic();
    }

    private void previousMusic(){

        // ilk şarkı ise return
        if(MyMediaPlayer.activeIndex == 0){
            return;
        }

        MyMediaPlayer.activeIndex -= 1;
        mediaPlayer.reset();
        setMusic();
    }

    private void pausePlayMusic(){

        //çalıyorsa durdur
        if(mediaPlayer.isPlaying()){
            mediaPlayer.pause();
        }
        //çalmıyorsa oynat
        else{
            mediaPlayer.start();
        }

    }


}