package tr.com.berkaytutal.beslenmedanismani;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v4.widget.SwipeRefreshLayout;
import android.support.v7.app.AlertDialog;
import android.util.Base64;
import android.view.View;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.Adapters.CertificatesAdapter;
import tr.com.berkaytutal.beslenmedanismani.Adapters.ProgramListingAdapter;
import tr.com.berkaytutal.beslenmedanismani.Utils.BaseDrawerActivity;
import tr.com.berkaytutal.beslenmedanismani.Utils.CertificatePOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.FunctionUtils;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.JSONParser;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.PublicVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.TrainerPOJO;

public class TrainerDetailPage extends BaseDrawerActivity implements SwipeRefreshLayout.OnRefreshListener {

    private ImageView profileImage;
    private TextView profileName;
    private ListView trainerProgramsListView;
    private ListView trainerCertificatesListView;
    private TextView ratingTextView;
    private TextView bioTextView;
    private TextView introTextView;
    private int trainerID;
    private TrainerPOJO trainer;

    private Activity activity;
    private ProgressDialog progressDialog;
    private SwipeRefreshLayout swipeRefreshLayout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_trainer_detail_page);

        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);

        this.activity = this;


        progressDialog = ProgressDialog.show(activity, "",
                "Loading...", true);

        swipeRefreshLayout = (SwipeRefreshLayout) findViewById(R.id.swipeRefreshLayoutTrainer);

        swipeRefreshLayout.setOnRefreshListener(this);
        swipeRefreshLayout.setColorSchemeColors(getResources().getColor(android.R.color.holo_blue_bright),
                getResources().getColor(android.R.color.holo_green_light),
                getResources().getColor(android.R.color.holo_orange_light),
                getResources().getColor(android.R.color.holo_red_light));
        trainerID = getIntent().getIntExtra("trainerID", -1);


        try {
            trainer = ((GlobalVariables) getApplicationContext()).getUserByID(trainerID);
            if (trainer.getCertificates() == null) {
                TrainerCheckAsync asy = new TrainerCheckAsync();
                asy.execute("test");
            } else {
                setTheRest();
            }

        } catch (Exception e) {
            e.printStackTrace();
            TrainerCheckAsync asy = new TrainerCheckAsync();
            asy.execute("test");

        }


    }

    @Override
    public void onRefresh() {
        progressDialog.show();
        TrainerCheckAsync asy = new TrainerCheckAsync();
        asy.execute("test");

    }

    private class TrainerCheckAsync extends AsyncTask {


        @Override
        protected Object doInBackground(Object[] objects) {

            if (((GlobalVariables) getApplicationContext()).isOnline()) {
                TrainerPOJO user;
                JSONParser jsonParser = new JSONParser();
                JSONObject jobj = null;
                try {
                    jobj = jsonParser.getJSONObjectFromUrl(PublicVariables.getTrainerDetailsURL + trainerID);
                } catch (Exception e) {
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
                    int userID = jobj.getInt("trainer_ID");
                    String name = jobj.getString("name");
                    String surname = jobj.getString("surname");
                    JSONArray certificatesJsonArr = jobj.getJSONArray("certificates");
                    ArrayList<CertificatePOJO> certificatePOJOs = new ArrayList<>();
                    for (int j = 0; j < certificatesJsonArr.length(); j++) {

                        JSONObject jsonObject = (JSONObject) certificatesJsonArr.get(j);
                        String certificateInstution = jsonObject.getString("certificateInstution");
                        String certificateName = jsonObject.getString("certificateName");
                        int certificateID = jsonObject.getInt("id");

                        CertificatePOJO certificate = new CertificatePOJO(certificateInstution, certificateName, certificateID);
                        certificatePOJOs.add(certificate);

                    }

                    boolean isBanned = jobj.getBoolean("isBanned");


                    user = new TrainerPOJO(name, surname, sex, photo, userID, birthday, bio, intro, certificatePOJOs, isBanned);
                    ((GlobalVariables) getApplicationContext()).updateUser(user);

                } catch (JSONException e) {
                    e.printStackTrace();
                    return "";
                }
                return "OK";
            } else {

                return "nointernet";

            }

        }

        @Override
        protected void onPostExecute(Object o) {
            if ("OK".equals(o.toString())) {
                setTheRest();
            } else {
                AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(
                        activity);

                // set title
                // alertDialogBuilder.setTitle("Info");

                // set progressDialog message
                alertDialogBuilder
                        .setMessage(R.string.needInternet)
                        .setCancelable(false)
                        .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int id) {
                                // if this button is clicked, close
                                // current activity
                                activity.finish();
                                overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
                            }
                        });


                // create alert progressDialog
                AlertDialog alertDialog = alertDialogBuilder.create();

                // show it
                alertDialog.show();

            }
            super.onPostExecute(o);

        }
    }

    private void setTheRest() {
        profileImage = (ImageView) findViewById(R.id.trainerProfileImage);
        profileName = (TextView) findViewById(R.id.trainerProfileName);
        trainerProgramsListView = (ListView) findViewById(R.id.trainerDetailProgramsListView);
        bioTextView = (TextView) findViewById(R.id.trainerProfileBio);
        introTextView = (TextView) findViewById(R.id.trainerProfileIntro);
        ratingTextView = (TextView) findViewById(R.id.trainerProfileRating);
        trainerCertificatesListView = (ListView) findViewById(R.id.trainerDetailCertificatesListView);

        trainer = ((GlobalVariables) getApplicationContext()).getUserByID(trainerID);


        profileImage.setImageBitmap(trainer.getPhoto());
        profileName.setText(trainer.getName() + " " + trainer.getSurname());

        String bioText = trainer.getBio();

        try {
            if (!bioText.equals("")) {
                bioTextView.setText(bioText);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
        String introText = trainer.getIntro();

        try {
            if (!introText.equals("")) {
                introTextView.setText(introText);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }

        //TODO rating

        ArrayList<CertificatePOJO> certificates = trainer.getCertificates();
        CertificatesAdapter certAdapter = new CertificatesAdapter(this, certificates);
        trainerCertificatesListView.setAdapter(certAdapter);

        View empty = findViewById(R.id.empty);
        trainerCertificatesListView.setEmptyView(empty);

        FunctionUtils.setListViewHeightBasedOnItems(trainerCertificatesListView);


        ArrayList<ProgramPOJO> trainerPrograms = ((GlobalVariables) getApplicationContext()).getProgramsByTrainerID(trainerID);


        ProgramListingAdapter adapter = new ProgramListingAdapter(this, trainerPrograms);
        trainerProgramsListView.setAdapter(adapter);

        View emptyPrograms = findViewById(R.id.emptyPrograms);
        trainerProgramsListView.setEmptyView(emptyPrograms);

        FunctionUtils.setListViewHeightBasedOnItems(trainerProgramsListView);
        progressDialog.cancel();
        swipeRefreshLayout.setRefreshing(false);
    }

    @Override
    protected void onResume() {
        super.onResume();

    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
    }


}
