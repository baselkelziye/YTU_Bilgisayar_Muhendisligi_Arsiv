package tr.com.berkaytutal.beslenmedanismani;

import android.app.Activity;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.util.Base64;
import android.util.Log;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.Utils.FunctionUtils;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.JSONParser;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramCategoryPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramDifficultyPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.PublicVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.TrainerPOJO;

public class SplashScreenYEDEKBEFOREHIZLANDIRMA extends AppCompatActivity {
    private Activity activity;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash_screen);
        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);
        this.activity = this;


        //TODO adaptörlerdeki type'lar gereksiz

        MyAsyncClass asy = new MyAsyncClass();
        asy.execute("test");


    }


    private class MyAsyncClass extends AsyncTask {
        JSONArray jsonArray;

        @Override
        protected Object doInBackground(Object[] objects) {

            if (!FunctionUtils.isInternetAvailable()) {
                SharedPreferences userDetails = activity.getSharedPreferences("userdetails", MODE_PRIVATE);
                String userEmail = userDetails.getString("userEmail", "");
                String userPass = userDetails.getString("userPass", "");

                if (userEmail.equals("") || userPass.equals("")) {
                   return "nousernointernet";

                }
                return "";
            }


            ArrayList<ProgramPOJO> allPrograms = new ArrayList<>();
            JSONParser jsonParser = new JSONParser();

            ArrayList<TrainerPOJO> allUsers = new ArrayList<>();

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


//                    program = new ProgramPOJO(diff, photo, programSpec, programTitle, programDescription, programID, trainerID, trainerName, trainerSurname, rating, commentCount);
//                    program.setPublished(true);
//                    allPrograms.add(program);
                } catch (JSONException e) {
                    e.printStackTrace();
                }

            }

            ((GlobalVariables) getApplicationContext()).setAllPrograms(allPrograms);

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


//                    user = new TrainerPOJO(name, surname, sex, photo, userID, birthday, bio, intro, null);
//                    allUsers.add(user);

                } catch (JSONException e) {
                    e.printStackTrace();
                }

            }

            ((GlobalVariables) getApplicationContext()).setAllUsers(allUsers);

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

            if("nousernointernet".equals(o.toString())){
                AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(
                        activity);

                // set title
                // alertDialogBuilder.setTitle("Info");

                // set progressDialog message
                alertDialogBuilder
                        .setMessage("You need to have an internet connection or an account already logged in to use this app!")
                        .setCancelable(false)
                        .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int id) {
                                // if this button is clicked, close
                                // current activity
                                activity.finish();
                            }
                        });


                // create alert progressDialog
                AlertDialog alertDialog = alertDialogBuilder.create();

                // show it
                alertDialog.show();
            }
            else{
                Intent i = new Intent(getApplication(), LoginActivity.class);
                i.putExtra("isMainLogin", true);
                startActivity(i);

                finish();
            }

        }
    }


}
