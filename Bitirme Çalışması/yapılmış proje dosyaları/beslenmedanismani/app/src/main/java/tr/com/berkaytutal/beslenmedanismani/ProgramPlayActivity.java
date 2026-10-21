package tr.com.berkaytutal.beslenmedanismani;

import android.content.Intent;
import android.graphics.Bitmap;
import android.media.MediaPlayer;
import android.media.Ringtone;
import android.media.RingtoneManager;
import android.net.Uri;
import android.os.CountDownTimer;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.MediaController;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.VideoView;

import java.util.HashMap;

import tr.com.berkaytutal.beslenmedanismani.Utils.ChestPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.ExercisePOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.CardioPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.PublicVariables;

import static android.view.View.GONE;

public class ProgramPlayActivity extends AppCompatActivity {

    private boolean doubleBackToExitPressedOnce = false;

    private boolean isFinished = false;

    private CountDownTimer cdt;
    private CountDownTimer cdt2;
    private CountDownTimer cdt3;

    private Button startButton;
    private Button finishButton;


    private ImageView photo1ImageView;
    private ImageView photo2ImageView;
    private VideoView videoView;
    private Button prevButton;
    private Button nextButton;
    private Button pauseButton;
    private TextView name;
    private TextView title;

    private TextView description;
    private TextView restTime;

    private LinearLayout notChestLayout;
    private TextView exerciseTime;

    private LinearLayout chestLayout;
    private TextView weightTextView;
    private TextView setTextView;
    private TextView repeatTextView;

    private int programID;
    private int currentExerciseIndex;

    private ProgramPOJO program;
    private ExercisePOJO exercise;

    private int prevExerciseIndex = -1;
    private int nextExerciseIndex;
    private HashMap<Integer, Integer> circleCountHolder;

    private int maxExerciseIndex;


    private LinearLayout remainingTimeLinearLayout;
    private TextView remainingTimeTextView;

    @Override

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_program_play);

        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);


        circleCountHolder = ((GlobalVariables) getApplicationContext()).circleCountHolder;
        if (circleCountHolder == null) {
            circleCountHolder = new HashMap<>();
            ((GlobalVariables) getApplicationContext()).circleCountHolder = circleCountHolder;
        }


        photo1ImageView = (ImageView) findViewById(R.id.circlePhoto1);
//        photo2ImageView = (ImageView) findViewById(R.id.circlePhoto2);
        videoView = (VideoView) findViewById(R.id.circleVideo);
        prevButton = (Button) findViewById(R.id.circleButtonPrev);
        pauseButton = (Button) findViewById(R.id.circleButtonPause);
        nextButton = (Button) findViewById(R.id.circleButtonNext);
        name = (TextView) findViewById(R.id.circleExerciseName);
        title = (TextView) findViewById(R.id.circleExerciseTitle);
        description = (TextView) findViewById(R.id.circleExerciseDescription);
        restTime = (TextView) findViewById(R.id.circleExerciseRestTime);

        chestLayout = (LinearLayout) findViewById(R.id.circleExerciseChestLayout);
        weightTextView = (TextView) findViewById(R.id.circleExerciseWeight);
        setTextView = (TextView) findViewById(R.id.circleExerciseSet);
        repeatTextView = (TextView) findViewById(R.id.circleExerciseRepeat);

        notChestLayout = (LinearLayout) findViewById(R.id.circleExerciseNotChestLayout);
        exerciseTime = (TextView) findViewById(R.id.circleExerciseTime);

        remainingTimeLinearLayout = (LinearLayout) findViewById(R.id.remainingTimeLinearLayout);
        remainingTimeTextView = (TextView) findViewById(R.id.remainingTimeTextView);

        startButton = (Button) findViewById(R.id.circleButtonStart);


        programID = getIntent().getIntExtra("programID", 0);
        currentExerciseIndex = getIntent().getIntExtra("currentExerciseIndex", 0);
        prevExerciseIndex = getIntent().getIntExtra("prevExerciseIndex", 0);

        program = ((GlobalVariables) getApplicationContext()).getUserDataPOJO().getProgramByID(programID);
        exercise = program.getExercisez().get(currentExerciseIndex);
        if (exercise.getVideo() != null) {

            //Video ile ilgili kısımlar
            videoView.setOnPreparedListener(new MediaPlayer.OnPreparedListener() {
                @Override
                public void onPrepared(MediaPlayer mp) {
                    mp.setLooping(true);
                }
            });

            //video görünmeme hatasını giderir
            videoView.setZOrderOnTop(true);

            //Creating MediaController
            MediaController mediaController = new MediaController(this);
            mediaController.setAnchorView(videoView);


            //specify the location of media file
            Uri uri = Uri.parse(getFilesDir() + "/" + exercise.getVideo());

            //Setting MediaController and URI, then starting the videoView
            videoView.setMediaController(mediaController);
            videoView.setVideoURI(uri);
            videoView.requestFocus();
            videoView.start();

        } else {
            photo1ImageView.setVisibility(View.VISIBLE);
            videoView.setVisibility(GONE);

            photo1ImageView.setImageBitmap(exercise.getPhoto1());
            Bitmap photo2 = exercise.getPhoto2();
            if (photo2 != null) {
//            photo2ImageView.setImageBitmap(photo2);


                final Bitmap[] imageArray = new Bitmap[2];
                imageArray[0] = exercise.getPhoto1();
                imageArray[1] = exercise.getPhoto2();
                final Handler handler = new Handler();
                Runnable runnable = new Runnable() {
                    int i = 0;

                    public void run() {
                        photo1ImageView.setImageBitmap(imageArray[i]);
                        i++;
                        if (i > imageArray.length - 1) {
                            i = 0;
                        }
                        handler.postDelayed(this, 500);  //for interval...
                    }
                };
                handler.postDelayed(runnable, 500); //for initial delay..
            }

        }
        maxExerciseIndex = program.getExercisez().size() - 1;

        if (exercise.getCircleID() == null) {
            if (currentExerciseIndex != maxExerciseIndex) {
                nextExerciseIndex = currentExerciseIndex + 1;
            } else {
                nextButton.setVisibility(GONE);
                isFinished = true;

            }
        } else {
            int circleID = exercise.getCircleID();
            if (circleCountHolder.get(exercise.getOrder()) == null) {
                circleCountHolder.put(exercise.getOrder(), exercise.getCircleCount() - 1);
                nextExerciseIndex = program.getExercisez().indexOf(program.getExerciseByOrderNumber(circleID));
            } else if (circleCountHolder.get(exercise.getOrder()) > 1) {
                circleCountHolder.put(exercise.getOrder(), circleCountHolder.get(exercise.getOrder()) - 1);

                nextExerciseIndex = program.getExercisez().indexOf(program.getExerciseByOrderNumber(circleID));
            } else if (circleCountHolder.get(exercise.getOrder()) == 1) {
                circleCountHolder.put(exercise.getOrder(), exercise.getCircleCount() - 1);

                if (currentExerciseIndex != maxExerciseIndex) {
                    nextExerciseIndex = currentExerciseIndex + 1;
                } else {
                    isFinished = true;
                }
            } else if (currentExerciseIndex != maxExerciseIndex) {
                nextExerciseIndex = currentExerciseIndex + 1;
            } else {
                isFinished = true;

            }


        }


//        Toast.makeText(this,exercise.getName(),Toast.LENGTH_SHORT).show();

        name.setText(exercise.getName());
        try {
            title.setText(exercise.getTitle());
        } catch (Exception e) {
            e.printStackTrace();
        }
        description.setText(exercise.getDescription());
        restTime.setText(exercise.getRestTime() + "s");


        nextButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                callExercise(true);
            }
        });

        cdt2 = new CountDownTimer(exercise.getRestTime() * 1000, 1000) { //Sets 10 second remaining

            public void onTick(long millisUntilFinished) {
                remainingTimeTextView.setText("Remaining Rest Time: " + millisUntilFinished / 1000 + "s");
            }

            public void onFinish() {

                //todo sound
                //nextButton.callOnClick();
                try {
                    Uri notification = RingtoneManager.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION);
                    Ringtone r = RingtoneManager.getRingtone(getApplicationContext(), notification);
                    r.play();
                    r.play();
                } catch (Exception e) {
                    e.printStackTrace();
                }
                remainingTimeTextView.setText("DONE!");
            }
        };

        if (!PublicVariables.CARDIO.equals(exercise.getExerciseType())) {
            ChestPOJO chest = (ChestPOJO) exercise;
            chestLayout.setVisibility(View.VISIBLE);
            weightTextView.setText(chest.getAgirlik() + "kg");
            setTextView.setText(chest.getSetSayisi() + "");
            repeatTextView.setText(chest.getTekrarSayisi() + "");
            //pauseButton.setVisibility(GONE);

        } else {
            final CardioPOJO notChest = (CardioPOJO) exercise;
            notChestLayout.setVisibility(View.VISIBLE);
            exerciseTime.setText(notChest.getExerciseTime() + "s");

            remainingTimeLinearLayout.setVisibility(View.VISIBLE);
            remainingTimeTextView.setText("Press start");


            cdt = new CountDownTimer(notChest.getExerciseTime() * 1000, 1000) { //Sets 10 second remaining

                public void onTick(long millisUntilFinished) {
                    remainingTimeTextView.setText("Remaining Time: " + millisUntilFinished / 1000 + "s");
                }

                public void onFinish() {
                    //todo sound
                    try {
                        Uri notification = RingtoneManager.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION);
                        Ringtone r = RingtoneManager.getRingtone(getApplicationContext(), notification);
                        r.play();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    cdt2.start();


                }
            };
            nextButton.setVisibility(GONE);
            startButton.setVisibility(View.VISIBLE);
            startButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    view.setVisibility(GONE);
                    nextButton.setVisibility(View.VISIBLE);

                    try {
                        Uri notification = RingtoneManager.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION);
                        Ringtone r = RingtoneManager.getRingtone(getApplicationContext(), notification);
                        r.play();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }

                    cdt3 = new CountDownTimer(3000, 1000) {

                        @Override
                        public void onTick(long l) {
                            remainingTimeTextView.setText("Starting in " + l / 1000 + "s");
                        }

                        @Override
                        public void onFinish() {
                            try {
                                Uri notification = RingtoneManager.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION);
                                Ringtone r = RingtoneManager.getRingtone(getApplicationContext(), notification);
                                r.play();
                            } catch (Exception e) {
                                e.printStackTrace();
                            }


                            cdt.start();

                        }
                    }.start();
                }
            });


        }


        if (currentExerciseIndex == 0 && circleCountHolder.isEmpty()) {
            prevButton.setVisibility(GONE);
        } else {
            prevButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {

                    callExercise(false);

                }
            });
        }

        finishButton = (Button) findViewById(R.id.circleButtonFinish);
        finishButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
                overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
            }
        });
        if (isFinished) {
            finishButton.setVisibility(View.VISIBLE);
        }
    }

    @Override
    public void onBackPressed() {
        if (doubleBackToExitPressedOnce) {
            super.onBackPressed();
            overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
        }

        this.doubleBackToExitPressedOnce = true;
        Toast.makeText(this, "Please click BACK again to exit", Toast.LENGTH_SHORT).show();

        new Handler().postDelayed(new Runnable() {

            @Override
            public void run() {
                doubleBackToExitPressedOnce = false;
            }
        }, 1500);
    }

    @Override
    protected void onPause() {
        videoView.pause();
        super.onPause();
        overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
        try {
            cdt.cancel();
        } catch (Exception e) {
            e.printStackTrace();
        }

        try {
            cdt2.cancel();
        } catch (Exception e) {
            e.printStackTrace();
        }
        try {
            cdt3.cancel();
        } catch (Exception e) {
            e.printStackTrace();
        }


    }

    private void callExercise(boolean isNext) {
        Intent intent = new Intent(getApplicationContext(), ProgramPlayActivity.class);
        intent.putExtra("programID", programID);
        if (isNext) {
            intent.putExtra("currentExerciseIndex", nextExerciseIndex);
        } else {
            intent.putExtra("currentExerciseIndex", prevExerciseIndex);
        }

        intent.putExtra("prevExerciseIndex", currentExerciseIndex);
        startActivity(intent);
        finish();
    }

}
