package tr.com.berkaytutal.beslenmedanismani;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Color;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.github.mikephil.charting.charts.LineChart;
import com.github.mikephil.charting.data.Entry;
import com.github.mikephil.charting.data.LineData;
import com.github.mikephil.charting.data.LineDataSet;
import com.github.mikephil.charting.interfaces.datasets.ILineDataSet;

import org.json.JSONObject;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

import tr.com.berkaytutal.beslenmedanismani.Adapters.ProgramListingAdapter;
import tr.com.berkaytutal.beslenmedanismani.Utils.BaseDrawerActivity;
import tr.com.berkaytutal.beslenmedanismani.Utils.BodyRatioPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.BodyRatioSender;
import tr.com.berkaytutal.beslenmedanismani.Utils.DBHelper;
import tr.com.berkaytutal.beslenmedanismani.Utils.DataSenderHelper;
import tr.com.berkaytutal.beslenmedanismani.Utils.FunctionUtils;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.PublicVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.UserDataPOJO;

public class ProfileActivity extends BaseDrawerActivity {

    private Activity activity;

    private ProgramListingAdapter adapter;

    private ImageView profileImage;
    private TextView profileName;
    private TextView profileEmail;
    private TextView profileBirthday;
    private ImageView profileGender;
    private UserDataPOJO userDataPOJO;
    private ListView myProgramsListview;
    private ArrayList<ProgramPOJO> myProgramsArrayList;
    private Button editDetails;
    private TextView privateProfileTopBanner;


    private String tall;
    private String weight;
    private String muscleRate;
    private String fatRate;
    private String waterRate;


    private EditText tallEditText;
    private EditText weightEditText;
    private EditText muscleRateEditText;
    private EditText fatRateEditText;
    private EditText waterRateEditText;
    private Button updateButton;

    private Button seeAllMyProgramsButton;


    private JSONObject jsonObject;


    public static Activity profileActivity;


    private ArrayList<Entry> weightDataset = new ArrayList<Entry>();
    private ArrayList<Entry> fatDataset = new ArrayList<Entry>();
    private ArrayList<Entry> muscleDataset = new ArrayList<Entry>();
    private ArrayList<Entry> waterDataset = new ArrayList<Entry>();
    private ArrayList<Entry> tallDataset = new ArrayList<Entry>();

    private ArrayList<ILineDataSet> lines = new ArrayList<ILineDataSet>();

    private LineChart lineChart;
    private Dialog chartDialog;
    private Dialog bodyRatioDialog;

    private Button chartSettingsButton;
    private Button chartAddNewButton;

    private boolean doubleBackToExitPressedOnce = false;
    private boolean nogoback;


    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {
        MenuItem logoutButton = menu.findItem(R.id.appBarLogoutButton);
        logoutButton.setVisible(true);

        MenuItem profileButton = menu.findItem(R.id.appBarProfileButton);
        profileButton.setVisible(false);


        return super.onPrepareOptionsMenu(menu);
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_profile);

        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);
        this.activity = this;

        Intent gelenIntent = getIntent();
        if (gelenIntent != null) {
            if (gelenIntent.hasExtra("nogoback")) {
                nogoback = gelenIntent.getBooleanExtra("nogoback", false);
            }
        }


    }

    @Override
    protected void onResume() {
        super.onResume();

        CheckOnline onlineAsyn = new CheckOnline();
        onlineAsyn.execute("");


        profileActivity = this;

        userDataPOJO = ((GlobalVariables) getApplicationContext()).getUserDataPOJO();

        myProgramsListview = (ListView) findViewById(R.id.myProgramsListviewDetailPage);

        profileImage = (ImageView) findViewById(R.id.userProfileImageDetailPage);
        profileName = (TextView) findViewById(R.id.userProfileNameDetailPage);
        profileEmail = (TextView) findViewById(R.id.userMailDetailPage);
        profileBirthday = (TextView) findViewById(R.id.userBirthdayDetailPage);
        profileGender = (ImageView) findViewById(R.id.userDetailGenderIcon);
        editDetails = (Button) findViewById(R.id.userProfileEditDetails);
        seeAllMyProgramsButton = (Button) findViewById(R.id.seeAllMyProgramsButton);
        privateProfileTopBanner = (TextView) findViewById(R.id.privateProfileTopBanner);


        if (userDataPOJO.isPrivate()) {
            privateProfileTopBanner.setVisibility(View.VISIBLE);
        }

        privateProfileTopBanner.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(
                        view.getContext());

                // set title
                alertDialogBuilder.setTitle(R.string.privateProfile);

                // set progressDialog message
                alertDialogBuilder
                        .setMessage(R.string.infoPrivateProfile)
                        .setCancelable(true)
                        .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                                    public void onClick(DialogInterface dialog, int id) {
                                        dialog.dismiss();
                                    }
                                }
                        );

                // create alert progressDialog
                AlertDialog alertDialog = alertDialogBuilder.create();

                // show it
                alertDialog.show();
            }
        });

        seeAllMyProgramsButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent i = new Intent(view.getContext(), MyProgramsActivity.class);
                startActivity(i);
            }
        });

        editDetails.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent i = new Intent(view.getContext(), EditProfileActivity.class);
                startActivity(i);

            }
        });

        profileImage.setImageBitmap(userDataPOJO.getPhoto());
        profileName.setText(userDataPOJO.getName() + " " + userDataPOJO.getSurname());
        profileEmail.setText(userDataPOJO.getEmail());
        profileBirthday.setText(userDataPOJO.getBirthday());

        if (userDataPOJO.getSex().equals("M")) {
            profileGender.setImageDrawable(getResources().getDrawable(R.drawable.male));
        } else {
            profileGender.setImageDrawable(getResources().getDrawable(R.drawable.female));
        }


        myProgramsArrayList = userDataPOJO.getMyPrograms();
        ArrayList<ProgramPOJO> downloadedPrograms = new ArrayList<>();
        for(ProgramPOJO programPOJO : myProgramsArrayList){
            if(programPOJO.getExercisez()!= null){
                downloadedPrograms.add(programPOJO);
            }
        }

        adapter = new ProgramListingAdapter(this, downloadedPrograms);
        myProgramsListview.setAdapter(adapter);
        View empty = findViewById(R.id.empty);
        myProgramsListview.setEmptyView(empty);
//        myProgramsListview.setMinimumHeight(getResources().getDimensionPixelOffset(R.dimen.homeListingHeight));


//        tall = userDataPOJO.getTall();
//        weight = userDataPOJO.getWeight();
//        muscleRate = userDataPOJO.getMuscleRate();
//        fatRate = userDataPOJO.getFatRate();
//        waterRate = userDataPOJO.getWaterRate();

//        tallEditText = (EditText) findViewById(R.id.bodyRatesTallEditText);
//        weightEditText = (EditText) findViewById(R.id.bodyRatesWeightEditText);
//        muscleRateEditText = (EditText) findViewById(R.id.bodyRatesMuscleRateEditText);
//        fatRateEditText = (EditText) findViewById(R.id.bodyRatesFatRateEditText);
//        waterRateEditText = (EditText) findViewById(R.id.bodyRatesWaterRaEditText);
//        updateButton = (Button) findViewById(R.id.bodyRatesUpdateButton);
//
//        tallEditText.setText(tall);
//        weightEditText.setText(weight);
//        muscleRateEditText.setText(muscleRate);
//        fatRateEditText.setText(fatRate);
//        waterRateEditText.setText(waterRate);
//
//        updateButton.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                tall = tallEditText.getText().toString();
//                weight = weightEditText.getText().toString();
//                muscleRate = muscleRateEditText.getText().toString();
//                fatRate = fatRateEditText.getText().toString();
//                waterRate = waterRateEditText.getText().toString();
//                jsonObject = new JSONObject();
//                try {
//                    jsonObject.accumulate("fatRate", fatRate);
//                    jsonObject.accumulate("muscleRate", muscleRate);
//                    jsonObject.accumulate("tall", tall);
//                    jsonObject.accumulate("user_ID", userDataPOJO.getUser_ID());
//                    jsonObject.accumulate("waterRate", waterRate);
//                    jsonObject.accumulate("weight", weight);
//                } catch (JSONException e) {
//                    e.printStackTrace();
//                }
//                BodyRateUpdateOldAsync async = new BodyRateUpdateOldAsync();
//                async.execute("test");
//
//
//            }
//        });


        /*
        *
        *
        *           LINE CHART BURADA BASLIYOR
        *
        *
         */


        //line chart için özel progressDialog burada

        chartDialog = new Dialog(this);
        chartDialog.setContentView(R.layout.custom_dialog_chart);

        Button saveButton = (Button) chartDialog.findViewById(R.id.dialogChartSaveButton);
        Button cancelButton = (Button) chartDialog.findViewById(R.id.dialogChartCancelButton);

        final CheckBox tallCheck = (CheckBox) chartDialog.findViewById(R.id.checkBoxTall);
        final CheckBox weightCheck = (CheckBox) chartDialog.findViewById(R.id.checkBoxWeight);
        final CheckBox muscleCheck = (CheckBox) chartDialog.findViewById(R.id.checkBoxMuscle);
        final CheckBox fatCheck = (CheckBox) chartDialog.findViewById(R.id.checkBoxFat);
        final CheckBox waterCheck = (CheckBox) chartDialog.findViewById(R.id.checkBoxWater);
        tallCheck.setChecked(userDataPOJO.getChartTall());
        weightCheck.setChecked(userDataPOJO.getChartWeight());
        muscleCheck.setChecked(userDataPOJO.getChartMuscle());
        fatCheck.setChecked(userDataPOJO.getChartFat());
        waterCheck.setChecked(userDataPOJO.getChartWater());

        cancelButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                chartDialog.dismiss();
            }
        });
        saveButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {


                userDataPOJO.setChartPreferences(tallCheck.isChecked(), weightCheck.isChecked(), muscleCheck.isChecked(), fatCheck.isChecked(), waterCheck.isChecked());
                DBHelper dbHelper = new DBHelper(getApplicationContext());
                dbHelper.updateUser(userDataPOJO);
                setLineChart();
                chartDialog.dismiss();
            }
        });


        chartDialog.setCanceledOnTouchOutside(true);


        // add new body ratio için progressDialog burası


        bodyRatioDialog = new Dialog(this);
        bodyRatioDialog.setContentView(R.layout.custom_dialog_bodyrate);

        Button addNewButton = (Button) bodyRatioDialog.findViewById(R.id.bodyRateSaveButton);
        Button bodyRatioDialogCancelButton = (Button) bodyRatioDialog.findViewById(R.id.bodyRateCancelButton);

        final EditText tallEditText = (EditText) bodyRatioDialog.findViewById(R.id.bodyRateTall);
        final EditText weightEditText = (EditText) bodyRatioDialog.findViewById(R.id.bodyRateWeight);
        final EditText muscleEditText = (EditText) bodyRatioDialog.findViewById(R.id.bodyRateMuscle);
        final EditText fatEditText = (EditText) bodyRatioDialog.findViewById(R.id.bodyRateFat);
        final EditText waterEditText = (EditText) bodyRatioDialog.findViewById(R.id.bodyRateWater);

        bodyRatioDialogCancelButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bodyRatioDialog.dismiss();
            }
        });
        addNewButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if (FunctionUtils.checkEmpty(tallEditText) && FunctionUtils.checkEmpty(weightEditText) && FunctionUtils.checkEmpty(muscleEditText) && FunctionUtils.checkEmpty(fatEditText) && FunctionUtils.checkEmpty(waterEditText)) {


                    Calendar mcurrentTime = Calendar.getInstance();

                    int yearM = mcurrentTime.get(Calendar.YEAR);//Güncel Yılı alıyoruz
                    int monthM = mcurrentTime.get(Calendar.MONTH);//Güncel Ayı alıyoruz
                    int dayM = mcurrentTime.get(Calendar.DAY_OF_MONTH);//Güncel Günü alıyoruz

                    String date = yearM + "-" + (monthM + 1) + "-" + dayM;

                    float fatRate = Float.valueOf(fatEditText.getText().toString());
                    float muscleRate = Float.valueOf(muscleEditText.getText().toString());
                    int tall = Integer.parseInt(tallEditText.getText().toString());
                    float waterRate = Float.valueOf(waterEditText.getText().toString());
                    float weight = Float.valueOf(weightEditText.getText().toString());

                    BodyRatioPOJO bodyRatio = new BodyRatioPOJO(date, fatRate, muscleRate, tall, userDataPOJO.getUser_ID(), waterRate, weight);
                    userDataPOJO.getOfflineBodyRatios().add(bodyRatio);

                    DBHelper dbHelper = new DBHelper(getApplicationContext());
                    dbHelper.updateUser(userDataPOJO);
                    setLineChart();
                    bodyRatioDialog.dismiss();
                    //todo online ise yolla hemen hepsini
                    if (((GlobalVariables) getApplicationContext()).isOnline()) {
                        BodyRatioSender async = new BodyRatioSender();
                        async.execute(activity);
                    }

                    //TODO internet varsa direkt yolla yoksa queue ekle her türlü userdatapojo ekle ki chart güncellensin sonra setchart çağır
                }


            }
        });


        bodyRatioDialog.setCanceledOnTouchOutside(true);


        chartSettingsButton = (Button) findViewById(R.id.chartSettingsButton);
        chartAddNewButton = (Button) findViewById(R.id.chartAddNewButton);
        chartAddNewButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bodyRatioDialog.show();
            }
        });

        chartSettingsButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                chartDialog.show();
            }
        });


        setLineChart();


    }

    private void setLineChart() {


        //TODO linechart kısmı burada
        lineChart = (LineChart) findViewById(R.id.bodyRatesChartProfile);


        ArrayList<BodyRatioPOJO> bodyRatiosArrayList = userDataPOJO.getBodyRatios();


        weightDataset.clear();
        fatDataset.clear();
        muscleDataset.clear();
        waterDataset.clear();
        tallDataset.clear();
        if (bodyRatiosArrayList != null) {
            if (bodyRatiosArrayList.size() > 0) {

                String[] xAxis = new String[bodyRatiosArrayList.size()];
                for (int i = 0; i < bodyRatiosArrayList.size(); i++) {
                    BodyRatioPOJO bodyRatio = bodyRatiosArrayList.get(i);


                    weightDataset.add(new Entry(i, bodyRatio.getWeight()));
                    fatDataset.add(new Entry(i, bodyRatio.getFatRate()));
                    muscleDataset.add(new Entry(i, bodyRatio.getMuscleRate()));
                    waterDataset.add(new Entry(i, bodyRatio.getWaterRate()));
                    tallDataset.add(new Entry(i, bodyRatio.getTall()));

                    xAxis[i] = "berkay" + bodyRatio.getDate();
                }


                lines.clear();
                if (userDataPOJO.getChartWeight()) {

                    LineDataSet weightLine = new LineDataSet(weightDataset, "Weight (kg)");
                    weightLine.setColor(Color.RED);
                    weightLine.setCircleColor(Color.RED);
                    lines.add(weightLine);
                }
                if (userDataPOJO.getChartFat()) {
                    LineDataSet fatLine = new LineDataSet(fatDataset, "Fat (%)");
                    fatLine.setColor(Color.YELLOW);
                    fatLine.setCircleColor(Color.YELLOW);
                    lines.add(fatLine);
                }
                if (userDataPOJO.getChartMuscle()) {
                    LineDataSet muscleLine = new LineDataSet(muscleDataset, "Muscle (%)");
                    muscleLine.setColor(Color.GREEN);
                    muscleLine.setCircleColor(Color.GREEN);
                    lines.add(muscleLine);
                }
                if (userDataPOJO.getChartWater()) {
                    LineDataSet waterLine = new LineDataSet(waterDataset, "Water (%)");
                    waterLine.setColor(Color.BLUE);
                    waterLine.setCircleColor(Color.BLUE);
                    lines.add(waterLine);
                }
                if (userDataPOJO.getChartTall()) {
                    LineDataSet tallLine = new LineDataSet(tallDataset, "Tall (cm)");
                    tallLine.setColor(Color.DKGRAY);
                    tallLine.setCircleColor(Color.DKGRAY);
                    lines.add(tallLine);
                }

                LineData lineData = new LineData(lines);
                lineChart.setData(lineData);


                lineChart.notifyDataSetChanged();
                lineChart.invalidate();

            }


        }


    }

    @Override
    public void onBackPressed() {

        if (nogoback) {
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
        } else {
            super.onBackPressed();
            overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);

        }
    }


    private class BodyRateUpdateOldAsync extends AsyncTask<JSONObject, Void, String> {


        @Override
        protected String doInBackground(JSONObject... jsonObjects) {
            Log.i("body", "update isteği yollandı");
//            Toast.makeText(getApplicationContext(), "istek Gönderildi", Toast.LENGTH_SHORT).show();
            return DataSenderHelper.POST(PublicVariables.bodyRateUpdateURL, jsonObjects[0]);
        }

        @Override
        protected void onPostExecute(String result) {
            super.onPostExecute(result);
            if (result.equals("false")) {
                Log.e("body", "sorun oluştu");
//                Toast.makeText(getApplicationContext(), "sorun oluştu", Toast.LENGTH_SHORT).show();
            } else if (result.equals("true")) {
                Log.i("body", "update başarılı");
//                userDataPOJO.setFatRate(fatRate);
//                userDataPOJO.setMuscleRate(muscleRate);
//                userDataPOJO.setTall(tall);
//                userDataPOJO.setWaterRate(waterRate);
//                userDataPOJO.setWeight(weight);
                DBHelper dbHelper = new DBHelper(getApplicationContext());
                dbHelper.updateUser(userDataPOJO);
                ((GlobalVariables) getApplicationContext()).setUserDataPOJO(userDataPOJO);
//                Toast.makeText(getApplicationContext(), "Succesfully sent your ", Toast.LENGTH_SHORT).show();


            }

        }
    }

    private class CheckOnline extends AsyncTask {

        @Override
        protected Object doInBackground(Object[] objects) {
            if (FunctionUtils.isInternetAvailable()) {
                ((GlobalVariables) getApplicationContext()).setOnline(true);
            }
            return null;
        }
    }
}
