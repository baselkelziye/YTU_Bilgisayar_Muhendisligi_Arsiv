package tr.com.berkaytutal.beslenmedanismani;

import android.content.Intent;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.Adapters.ProgramListingAdapter;
import tr.com.berkaytutal.beslenmedanismani.Utils.BaseDrawerActivity;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.UserDataPOJO;

public class MyProgramsActivity extends BaseDrawerActivity {

    private ListView myProgramsListview;
    private ArrayList<ProgramPOJO> myProgramsArrayList;
    private UserDataPOJO userDataPOJO;
    private ProgramListingAdapter adapter;

    private boolean doubleBackToExitPressedOnce = false;
    private boolean nogoback ;



    public boolean onPrepareOptionsMenu(Menu menu) {
        MenuItem logoutButton = menu.findItem(R.id.appBarLogoutButton);
        logoutButton.setVisible(true);




        return super.onPrepareOptionsMenu(menu);
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_my_programs);

        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);

        Intent gelenIntent = getIntent();
        if(gelenIntent!=null){
            if(gelenIntent.hasExtra("nogoback")){
                nogoback = gelenIntent.getBooleanExtra("nogoback",false);
            }
        }

        userDataPOJO = ((GlobalVariables) getApplicationContext()).getUserDataPOJO();
        myProgramsArrayList = userDataPOJO.getMyPrograms();


        myProgramsListview = (ListView) findViewById(R.id.myProgramsListViewActivity);

        adapter = new ProgramListingAdapter(this,myProgramsArrayList);

        myProgramsListview.setAdapter(adapter);
        View empty = findViewById(R.id.empty);
        myProgramsListview.setEmptyView(empty);



    }

    @Override
    protected void onResume() {
        super.onResume();
        adapter.notifyDataSetChanged();
    }

    @Override
    public void onBackPressed() {

        if(nogoback) {
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
        else{
            super.onBackPressed();
            overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);

        }
    }


}
