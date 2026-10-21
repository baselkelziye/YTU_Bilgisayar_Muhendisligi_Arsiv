package tr.com.berkaytutal.beslenmedanismani;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.support.design.widget.NavigationView;
import android.support.v4.widget.DrawerLayout;
import android.support.v4.widget.SwipeRefreshLayout;
import android.support.v7.app.AlertDialog;
import android.util.Base64;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.Adapters.ProgramListingAdapter;
import tr.com.berkaytutal.beslenmedanismani.Adapters.UserListingAdapter;
import tr.com.berkaytutal.beslenmedanismani.Utils.BaseDrawerActivity;
import tr.com.berkaytutal.beslenmedanismani.Utils.FunctionUtils;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.JSONParser;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramCategoryPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramDifficultyPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.PublicVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.TrainerPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.UserDataPOJO;

public class HomepageActivity extends BaseDrawerActivity {

    private SwipeRefreshLayout swipeHome;
    private Activity activity;

    private Button seeAllListings;
    private Button seeAllTrainers;
    private TextView textViewUserName;
    private boolean doubleBackToExitPressedOnce = false;
    private ProgramListingAdapter pla;
    private UserListingAdapter ula;


    @Override
    protected void onResume() {
        super.onResume();
        pla.notifyDataSetChanged();
        ula.notifyDataSetChanged();
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_homepage);
        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);

        activity = this;

        swipeHome = (SwipeRefreshLayout) findViewById(R.id.homeSwipe);
        swipeHome.setOnRefreshListener(new SwipeRefreshLayout.OnRefreshListener() {
            @Override
            public void onRefresh() {
                swipeHome.setRefreshing(false);
                ProgressDialog progressDialog = ProgressDialog.show(activity, "",
                        "Refreshing all data, be patient.", true);
                CheckInternetAsync async = new CheckInternetAsync();
                async.execute("");

            }
        });

        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.getMenu().findItem(R.id.icon_home).setVisible(false);

//
//        Intent rates = new Intent(this,BodyRates.class);
//        startActivity(rates);


        UserDataPOJO user = ((GlobalVariables) getApplicationContext()).getUserDataPOJO();

        ArrayList<TrainerPOJO> allUsers = ((GlobalVariables) getApplicationContext()).getAllUsers();
        ArrayList<ProgramPOJO> allPrograms = ((GlobalVariables) getApplicationContext()).getAllPrograms();

        ArrayList<TrainerPOJO> nUsers = new ArrayList<>();
        ArrayList<ProgramPOJO> nPrograms = new ArrayList<>();

        for (int i = 0; i < PublicVariables.homepageListingCount && (i < allUsers.size()); i++) {
            nUsers.add(allUsers.get(i));

        }
        for (int i = 0; i < PublicVariables.homepageListingCount && (i < allPrograms.size()); i++) {

            nPrograms.add(allPrograms.get(i));
        }

        seeAllListings = (Button) findViewById(R.id.homepageSeeAllListingsButton);
        seeAllTrainers = (Button) findViewById(R.id.homepageSeeAllTrainersButton);

        seeAllTrainers.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent i = new Intent(view.getContext(), AllUsersActivity.class);
                startActivity(i);

            }
        });
        seeAllListings.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent i = new Intent(view.getContext(), AllListingsActivity.class);
                startActivity(i);

            }
        });


//


//        Intent i = new Intent(this,AllUsersActivity.class);
//        startActivity(i);


        ListView programsListView = (ListView) findViewById(R.id.homeProgramsList);
        ListView trainersListView = (ListView) findViewById(R.id.homeTrainersList);


        pla = new ProgramListingAdapter(this, nPrograms);
        programsListView.setAdapter(pla);

        ula = new UserListingAdapter(this, nUsers);

        trainersListView.setAdapter(ula);


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
    protected void onDestroy() {
        super.onDestroy();
        overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);

    }
    private class CheckInternetAsync extends AsyncTask {

        @Override
        protected Object doInBackground(Object[] objects) {

            if (!FunctionUtils.isInternetAvailable()) {

                return "nointernet";
            }


            return "yesinternet";
        }

        @Override
        protected void onPostExecute(Object o) {
            super.onPostExecute(o);

            if ("yesinternet".equals(o.toString())) {

                AllProgramsAsync allProgramsAsync = new AllProgramsAsync();
                allProgramsAsync.execute("");
                AllTrainersAsync allTrainersAsync = new AllTrainersAsync();
                allTrainersAsync.execute("");
                AllCategoriesAsync allCategoriesAsync = new AllCategoriesAsync();
                allCategoriesAsync.execute("");

            } else if ("nointernet".equals(o.toString())) {
                Toast.makeText(activity, "No internet connection", Toast.LENGTH_SHORT).show();
            }

        }
    }
    private boolean allProgramsSet;
    private boolean allTrainersSet;
    private boolean allCategoriesSet;


    private class AllCategoriesAsync extends AsyncTask {
        JSONArray jsonArray;

        @Override
        protected Object doInBackground(Object[] objects) {
            JSONParser jsonParser = new JSONParser();
            ArrayList<ProgramCategoryPOJO> allCategories = new ArrayList<>();
            allCategories.add(new ProgramCategoryPOJO(PublicVariables.ALL_ID, "All"));

            jsonArray = jsonParser.getJSONArrayFromUrl(PublicVariables.programCategoriesURL);
            Log.i("programcategories", jsonArray.toString());
            for (int i = 0; i < jsonArray.length(); i++) {


                ProgramCategoryPOJO category;
                try {
                    JSONObject jobj = (JSONObject) jsonArray.get(i);


                    String name = jobj.getString("programSpec_Name");
                    int id = jobj.getInt("programSpec_ID");

                    category = new ProgramCategoryPOJO(id, name);
                    allCategories.add(category);

                } catch (JSONException e) {
                    e.printStackTrace();
                }

            }

            ((GlobalVariables) getApplicationContext()).setProgramCategories(allCategories);

            ArrayList<ProgramDifficultyPOJO> allDifficulties = new ArrayList<>();
            allDifficulties.add(new ProgramDifficultyPOJO(PublicVariables.ALL_ID, "All"));

            jsonArray = jsonParser.getJSONArrayFromUrl(PublicVariables.programDiffURL);
            Log.i("alldifficulties", jsonArray.toString());
            for (int i = 0; i < jsonArray.length(); i++) {


                ProgramDifficultyPOJO diff;
                try {
                    JSONObject jobj = (JSONObject) jsonArray.get(i);


                    String name = jobj.getString("programDiff_Name");
                    int id = jobj.getInt("programDiff_ID");

                    diff = new ProgramDifficultyPOJO(id, name);
                    allDifficulties.add(diff);

                } catch (JSONException e) {
                    e.printStackTrace();
                }

            }

            ((GlobalVariables) getApplicationContext()).setProgramDifficulties(allDifficulties);

            return "";
        }

        @Override
        protected void onPostExecute(Object o) {
            super.onPostExecute(o);
            allCategoriesSet = true;
            if (allCategoriesSet && allProgramsSet && allTrainersSet) {
                Intent i = new Intent(getApplication(), HomepageActivity.class);

                startActivity(i);
                overridePendingTransition(0, 0);
                finish();
                overridePendingTransition(0, 0);
            }
        }
    }

    private class AllTrainersAsync extends AsyncTask {
        JSONArray jsonArray;

        @Override
        protected Object doInBackground(Object[] objects) {

            JSONParser jsonParser = new JSONParser();

            ArrayList<TrainerPOJO> allUsers = new ArrayList<>();

            jsonArray = jsonParser.getJSONArrayFromUrl(PublicVariables.allUsersURL);
            Log.i("alltrainers", jsonArray.toString());
            for (int i = 0; i < jsonArray.length(); i++) {


                TrainerPOJO user;
                JSONObject jobj = null;
                try {
                    jobj = (JSONObject) jsonArray.get(i);
                } catch (JSONException e) {
                    e.printStackTrace();
                }

                String sex = null;
                try {
                    sex = jobj.getString("sex");
                } catch (JSONException e) {
                    e.printStackTrace();
                }
                byte[] imageByte = null;
                try {
                    imageByte = Base64.decode(jobj.getString("photo"), Base64.DEFAULT);


                } catch (JSONException e) {
                    e.printStackTrace();
                }
                Bitmap photo = null;
                if (imageByte != null) {
                    photo = BitmapFactory.decodeByteArray(imageByte, 0, imageByte.length);
                } else {
                    if ("M".equals(sex)) {
                        photo = BitmapFactory.decodeResource(getApplicationContext().getResources(), R.drawable.profile_man);
                    } else {
                        photo = BitmapFactory.decodeResource(getApplicationContext().getResources(), R.drawable.profile_woman);

                    }
                }
                String bio = null;
                String intro = null;

                try {
                    bio = jobj.getString("bio");
                } catch (JSONException e) {
                    e.printStackTrace();
                }
                try {
                    intro = jobj.getString("intro");
                } catch (JSONException e) {
                    e.printStackTrace();
                }

                try {


                    String birthday = jobj.getString("birthday");
                    int userID = jobj.getInt("id");
                    String name = jobj.getString("name");
                    String surname = jobj.getString("surname");
//                    JSONArray certificatesJsonArr = jobj.getJSONArray("certificates");
//                    ArrayList<CertificatePOJO> certificatePOJOs = new ArrayList<>();
//                    for (int j = 0; j < certificatesJsonArr.length(); j++) {
//
//                        JSONObject jsonObject = (JSONObject) certificatesJsonArr.get(j);
//                        String certificateInstution = jsonObject.getString("certificateInstution");
//                        String certificateName = jsonObject.getString("certificateName");
//                        int certificateID = jsonObject.getInt("id");
//
//                        CertificatePOJO certificate = new CertificatePOJO(certificateInstution, certificateName, certificateID);
//                        certificatePOJOs.add(certificate);
//
//                    }
                    boolean isBanned = false;
                    try {
                        isBanned = jobj.getBoolean("isBanned");
                    } catch (Exception e) {
                        e.printStackTrace();
                    }

                    user = new TrainerPOJO(name, surname, sex, photo, userID, birthday, bio, intro, null, isBanned);
                    allUsers.add(user);

                } catch (JSONException e) {
                    e.printStackTrace();
                }

            }

            ((GlobalVariables) getApplicationContext()).setAllUsers(allUsers);

            return null;
        }

        @Override
        protected void onPostExecute(Object o) {
            super.onPostExecute(o);
            allTrainersSet = true;
            if (allCategoriesSet && allProgramsSet && allTrainersSet) {
                Intent i = new Intent(getApplication(), HomepageActivity.class);
                startActivity(i);
                overridePendingTransition(0, 0);
                finish();
                overridePendingTransition(0, 0);
            }
        }
    }

    private class AllProgramsAsync extends AsyncTask {
        JSONArray jsonArray;


        @Override
        protected Object doInBackground(Object[] objects) {
            ArrayList<ProgramPOJO> allPrograms = new ArrayList<>();
            JSONParser jsonParser = new JSONParser();


            jsonArray = jsonParser.getJSONArrayFromUrl(PublicVariables.allProgramsURL);
            Log.i("allprograms", jsonArray.toString());
            for (int i = 0; i < jsonArray.length(); i++) {


                ProgramPOJO program;
                try {
                    JSONObject jobj = (JSONObject) jsonArray.get(i);
                    String diff = jobj.getString("programDiffName");

                    byte[] photo = Base64.decode(jobj.getString("programPhoto"), Base64.DEFAULT);
//                    byte[] imageByte = Base64.decode(jobj.getString("programPhoto"), Base64.DEFAULT);
//                    Bitmap photo = BitmapFactory.decodeByteArray(imageByte, 0, imageByte.length);

                    String programDescription = jobj.getString("programDescription");
                    String programSpec = jobj.getString("programSpecName");
                    String programTitle = jobj.getString("programTittle");
                    int programID = jobj.getInt("program_ID");
                    int trainerID = jobj.getInt("trainer_ID");
                    String trainerName = jobj.getString("trainerName");
                    String trainerSurname = jobj.getString("trainerSurname");
                    float rating = jobj.getLong("ratingAvg");
                    int commentCount = jobj.getInt("commentCount");


                    boolean isProgramBanned = false;
                    boolean isTrainerBanned = false;
                    String reason = null;
                    try {
                        isProgramBanned = jobj.getBoolean("programIsBanned");
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    try {
                        isTrainerBanned = jobj.getBoolean("trainerIsBanned");
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    try {
                        reason = jobj.getString("programBannedReason");
                    } catch (Exception e) {
                        e.printStackTrace();
                    }

                    int price = 0;
                    try {
                        price = jobj.getInt("programPrice");
                    } catch (Exception e) {
                        e.printStackTrace();
                    }


                    program = new ProgramPOJO(diff, photo, programSpec, programTitle, programDescription, programID, trainerID, trainerName, trainerSurname, rating, commentCount, isProgramBanned, isTrainerBanned, reason, price);
                    program.setPublished(true);
                    allPrograms.add(program);
                } catch (JSONException e) {
                    e.printStackTrace();
                }

            }

            ((GlobalVariables) getApplicationContext()).setAllPrograms(allPrograms);
            return null;
        }

        @Override
        protected void onPostExecute(Object o) {
            super.onPostExecute(o);
            allProgramsSet = true;
            if (allCategoriesSet && allProgramsSet && allTrainersSet) {
                Intent i = new Intent(getApplication(), HomepageActivity.class);

                startActivity(i);
                overridePendingTransition(0, 0);
                finish();
                overridePendingTransition(0, 0);
            }
        }
    }
}
