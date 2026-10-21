package tr.com.berkaytutal.beslenmedanismani;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ListView;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.Adapters.ProgramOverviewAdapter;
import tr.com.berkaytutal.beslenmedanismani.Utils.AlertDialogActivity;
import tr.com.berkaytutal.beslenmedanismani.Utils.BaseDrawerActivity;
import tr.com.berkaytutal.beslenmedanismani.Utils.CircleMakerHelper;
import tr.com.berkaytutal.beslenmedanismani.Utils.CircleTekrarAbsPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.ExercisePOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.UserDataPOJO;

public class ProgramOverviewActivity extends BaseDrawerActivity {

    public int programID;
    private ProgramPOJO program;
    private UserDataPOJO user;
    private ArrayList<ExercisePOJO> exercisePOJOs;

    private ListView listview;

    private Button programStartButton;


    @Override
    protected void onResume() {
        super.onResume();
        if (((GlobalVariables) getApplicationContext()).isSwitchOnlineOffline()) {
            if (((GlobalVariables) getApplicationContext()).isSwitchFromOffline()) {
                Intent i = new Intent(this, AlertDialogActivity.class);
                i.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                i.putExtra("fromOffline", true);
                startActivity(i);
            } else {
                Intent i = new Intent(this, AlertDialogActivity.class);
                i.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                i.putExtra("fromOffline", false);
                startActivity(i);
            }
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_program_overview);

        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);

        listview = (ListView) findViewById(R.id.workoutIntroListview);
        programStartButton = (Button) findViewById(R.id.programOverviewStart);

        programID = getIntent().getIntExtra("programID", 0);
        user = ((GlobalVariables) getApplicationContext()).getUserDataPOJO();
        program = user.getProgramByID(programID);

        exercisePOJOs = program.getExercisez();

        CircleMakerHelper test = new CircleMakerHelper();
        ArrayList<CircleTekrarAbsPOJO> deneme = test.makeCircleWithThis(exercisePOJOs);

//        ArrayList<CircleTekrarAbsPOJO> denemeCircles = test.handleCircles(deneme);
//        ArrayList<CircleTekrarAbsPOJO> denemeCircles = test.handleCircles(deneme);

        ProgramOverviewAdapter adapter = new ProgramOverviewAdapter(this, deneme);
        listview.setAdapter(adapter);


        programStartButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), ProgramPlayActivity.class);
                intent.putExtra("programID", programID);
                startActivity(intent);
            }
        });

    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
    }

}
