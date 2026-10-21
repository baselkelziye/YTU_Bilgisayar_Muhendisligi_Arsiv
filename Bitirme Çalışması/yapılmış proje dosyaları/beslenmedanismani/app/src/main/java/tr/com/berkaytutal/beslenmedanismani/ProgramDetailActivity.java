package tr.com.berkaytutal.beslenmedanismani;

import android.app.Activity;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AlertDialog;
import android.util.Base64;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;


import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URL;
import java.net.URLConnection;
import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.Utils.BaseDrawerActivity;
import tr.com.berkaytutal.beslenmedanismani.Utils.ChestPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.DBHelper;
import tr.com.berkaytutal.beslenmedanismani.Utils.DataSenderHelper;
import tr.com.berkaytutal.beslenmedanismani.Utils.ExercisePOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.FunctionUtils;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.JSONParser;
import tr.com.berkaytutal.beslenmedanismani.Utils.CardioPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.PublicVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.TrainerPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.UserDataPOJO;

public class ProgramDetailActivity extends BaseDrawerActivity {
    //
//    // Progress Dialog
//    private ProgressDialog pDialog;
//    public static final int progress_bar_type = 0;
    private ProgressDialog progressDialog;

    private ImageView programImageView;
    private Button downloadButton;
    private Button startButton;
    private TextView programTitle;
    private TextView programCategory;
    private TextView programHardness;
    private TextView programDescription;
    private ImageView trainerImage;
    private TextView trainerName;
    private Button trainerSeeMore;
    private LinearLayout trainerLayout;

    private LinearLayout boughtProgramLinearLayout;
    private Button buyThisProgramButton;
    private Button deleteProgramButton;


    private int programID;
    private ProgramPOJO program;
    private TrainerPOJO trainer;
    private UserDataPOJO user;

    private MenuItem reportButton;
    private boolean reportButtonVisibility = false;

    private View.OnClickListener downloadOnClickListener;

    protected boolean isWorkoutButton = false;
    private LinearLayout commentsLinearLayout;
    private TextView commentCountTextView;
    private TextView ratingTextView;

    private Activity activity;


    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.appBarReportButton) {
//            Toast.makeText(getApplicationContext(), "report", Toast.LENGTH_SHORT).show();
            if (((GlobalVariables) getApplicationContext()).isOnline()) {

                final Dialog dialog = new Dialog(this);
                dialog.setContentView(R.layout.custom_dialog_report);

                Button cancelButton = (Button) dialog.findViewById(R.id.dialogReportCancelButton);
                Button reportButton = (Button) dialog.findViewById(R.id.dialogReportYesButton);
                final EditText reasonEditText = (EditText) dialog.findViewById(R.id.dialogReportEditText);

                cancelButton.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        dialog.dismiss();
                    }
                });
                reportButton.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        String reason = reasonEditText.getText().toString();

                        Toast.makeText(view.getContext(), reason, Toast.LENGTH_SHORT).show();

                        ReportAsyncClass async = new ReportAsyncClass();
                        async.execute(reason);

                        //TODO buraya async yazılacak rapor atması için
                        dialog.dismiss();
                    }
                });
                dialog.setCanceledOnTouchOutside(true);

                dialog.show();

            } else {
                AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(
                        activity);

                // set title
                // alertDialogBuilder.setTitle("Info");

                // set progressDialog message
                alertDialogBuilder
                        .setMessage("You need internet to report this program.")
                        .setCancelable(false)
                        .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int id) {
                                // if this button is clicked, close
                                // current activity
                                dialog.dismiss();
                            }
                        });


                // create alert progressDialog
                AlertDialog alertDialog = alertDialogBuilder.create();

                // show it
                alertDialog.show();
            }
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {
        reportButton = menu.findItem(R.id.appBarReportButton);
        reportButton.setVisible(reportButtonVisibility);


        return super.onPrepareOptionsMenu(menu);
    }
//TODO degistiyse tekrar yapilacak


    @Override
    protected void onResume() {
        super.onResume();

    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_program_detail);
        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);
        programID = getIntent().getIntExtra("programID", 0);
        this.activity = this;
        setTheRest();

    }

    private void setTheRest() {

        buyThisProgramButton = (Button) findViewById(R.id.programBuyButton);
        boughtProgramLinearLayout = (LinearLayout) findViewById(R.id.boughtProgramLinearLayout);
        deleteProgramButton = (Button) findViewById(R.id.programDetailDelete);
        commentsLinearLayout = (LinearLayout) findViewById(R.id.programDetailCommentLinearLayout);
        commentCountTextView = (TextView) findViewById(R.id.programDetailCommentCountTextView);
        ratingTextView = (TextView) findViewById(R.id.programDetailRatingTextView);


        commentsLinearLayout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent i = new Intent(view.getContext(), ProgramCommentsActivity.class);
                i.putExtra("programID", programID);
                startActivity(i);
            }
        });


        user = ((GlobalVariables) getApplicationContext()).getUserDataPOJO();
        if (user != null) {
            program = user.getProgramByID(programID);

        }


        if (program == null) {
            buyThisProgramButton.setVisibility(View.VISIBLE);
            program = ((GlobalVariables) getApplicationContext()).getProgramByID(programID);
            if(program.getPrice()==0){
                buyThisProgramButton.setText("BUY THIS FOR FREE");
            }
            else{
                buyThisProgramButton.setText("BUY THIS FOR " + program.getPrice() + " TL");
            }
        } else {
            boughtProgramLinearLayout.setVisibility(View.VISIBLE);
            if (!isTrainer) {
                reportButtonVisibility = true;

            }

        }

        try {
            trainer = ((GlobalVariables) getApplicationContext()).getUserByID(program.getTrainerID());
        } catch (Exception e) {
            e.printStackTrace();
        }
        downloadButton = (Button) findViewById(R.id.programDetailDownload);
        startButton = (Button) findViewById(R.id.programDetailStart);

        downloadOnClickListener = new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                isWorkoutButton = false;
                Toast.makeText(getApplicationContext(), "indirme başladı", Toast.LENGTH_SHORT).show();
                downloadProgram();


            }
        };

        startButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // program = ((GlobalVariables) getApplicationContext()).getProgramByID(programID);

                if (program.getExercisez() == null) {
                    isWorkoutButton = true;

                    Toast.makeText(getApplicationContext(), "indirme başladı", Toast.LENGTH_SHORT).show();
                    downloadProgram();
                } else {
                    isWorkoutButton = false;
                    startWorkout();
                }


            }
        });

        downloadButton.setOnClickListener(downloadOnClickListener);

        deleteProgramButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                user.deleteProgramExercisez(program);
                ((GlobalVariables) getApplicationContext()).setUserDataPOJO(user);
                DBHelper dbHelper = new DBHelper(getApplicationContext());
                dbHelper.updateUser(user);
                activateDownloadButton();


                Toast.makeText(getApplicationContext(), "silindi", Toast.LENGTH_SHORT).show();
            }
        });


        if (program.getExercisez() != null) {
            disableDownloadButton();
        }

        buyThisProgramButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(
                        activity);

                // set title
                // alertDialogBuilder.setTitle("Info");

                // set progressDialog message
                alertDialogBuilder
                        .setTitle("Buy Program")
                        .setMessage("Do you want to buy this program for " + program.getPrice() + " TL ?")
                        .setCancelable(false)
                        .setNegativeButton("NO", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                dialogInterface.dismiss();
                            }
                        })
                        .setPositiveButton("YES", new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int id) {

                                if (user == null) {
                                    Intent intent = new Intent(getApplicationContext(), LoginActivity.class);
                                    startActivity(intent);
                                    dialog.dismiss();
                                } else {
                                    progressDialog = ProgressDialog.show(activity, "",
                                            "Loading...", true);
                                    JSONObject jsonObject = new JSONObject();
                                    try {
                                        jsonObject.accumulate("user_ID", user.getUser_ID());
                                        jsonObject.accumulate("program_ID", programID);
                                    } catch (JSONException e) {
                                        e.printStackTrace();
                                    }

                                    BuyAsyncClass async = new BuyAsyncClass();
                                    async.execute(jsonObject);
                                }
                                dialog.dismiss();
                            }
                        });


                // create alert progressDialog
                AlertDialog alertDialog = alertDialogBuilder.create();

                // show it
                alertDialog.show();




            }
        });


        programImageView = (ImageView) findViewById(R.id.programDetailImage);

        programTitle = (TextView) findViewById(R.id.programDetailTitle);
        programCategory = (TextView) findViewById(R.id.programDetailCategory);
        programHardness = (TextView) findViewById(R.id.programDetailHardness);
        programDescription = (TextView) findViewById(R.id.programDetailDescription);

        trainerLayout = (LinearLayout) findViewById(R.id.programDetailTrainerLayout);
        trainerImage = (ImageView) findViewById(R.id.programDetailTrainerImage);
        trainerName = (TextView) findViewById(R.id.programDetailTrainerName);
        trainerSeeMore = (Button) findViewById(R.id.programDetailTrainerMore);

        programImageView.setImageBitmap(program.getProgramPhoto());
        programTitle.setText(program.getProgramTitle());
        programCategory.setText(program.getProgramSpec());
        programHardness.setText(program.getDifficulty());
        programDescription.setText(program.getProgramDescription());
        try {
            trainerImage.setImageBitmap(trainer.getPhoto());
            trainerName.setText(trainer.getName() + " " + trainer.getSurname());
        } catch (Exception e) {
            trainerName.setText(program.getTrainerName() + " " + program.getTrainerSurname());
            trainerImage.setImageDrawable(getResources().getDrawable(R.drawable.nonetwork));
        }

        if (program.isTrainerBanned()) {
            findViewById(R.id.trainerBannedTextView).setVisibility(View.VISIBLE);
        }
        if (program.isBanned()) {

            TextView programBanned = (TextView) findViewById(R.id.programIsBanned);

            programBanned.setVisibility(View.VISIBLE);
            String reason = null;
            if (program.getBannedReasonForProgram() != null) {
                reason = program.getBannedReasonForProgram();
            }

            final String finalReason = reason;
            programBanned.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    android.app.AlertDialog.Builder alertDialogBuilder = new android.app.AlertDialog.Builder(
                            view.getContext());

                    // set title
                    alertDialogBuilder.setTitle(R.string.bannedProgram);
                    String message = "If you still want to use this program be aware of its banned";
                    message += " for \"" + finalReason + "\"";
                    // set progressDialog message
                    alertDialogBuilder
                            .setMessage(message)
                            .setCancelable(true)
                            .setPositiveButton("I'm aware", new DialogInterface.OnClickListener() {
                                        public void onClick(DialogInterface dialog, int id) {
                                            dialog.dismiss();
                                        }
                                    }
                            );

                    // create alert progressDialog
                    android.app.AlertDialog alertDialog = alertDialogBuilder.create();

                    // show it
                    alertDialog.show();
                }
            });
        }

        trainerSeeMore.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                goTrainerPage();
            }
        });

        trainerLayout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                goTrainerPage();
            }
        });

        commentCountTextView.setText(program.getCommentCount() + "");
        ratingTextView.setText(program.getRating() + "/5");
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
    }


    private void goTrainerPage() {
        Intent i = new Intent(this, TrainerDetailPage.class);
        i.putExtra("trainerID", program.getTrainerID());
        startActivity(i);

    }

    private void downloadProgram() {
        MyAsyncClass async = new MyAsyncClass();
        async.execute("test");


    }

    protected void startWorkout() {
        Intent i = new Intent(getApplicationContext(), ProgramOverviewActivity.class);
        i.putExtra("programID", programID);
        startActivity(i);
    }

    private void activateDownloadButton() {
        downloadButton.setClickable(true);
        downloadButton.setText(getResources().getString(R.string.indir));
        downloadButton.setBackgroundColor(getResources().getColor(R.color.accent));
        downloadButton.setCompoundDrawablesWithIntrinsicBounds(getResources().getDrawable(R.drawable.download), null, null, null);
        downloadButton.setOnClickListener(downloadOnClickListener);
        deleteProgramButton.setVisibility(View.GONE);

    }

    private void disableDownloadButton() {
        downloadButton.setClickable(false);
        downloadButton.setText(getResources().getString(R.string.indirildi));
        downloadButton.setBackgroundColor(getResources().getColor(R.color.colorGreen));
        downloadButton.setCompoundDrawablesWithIntrinsicBounds(getResources().getDrawable(R.drawable.check), null, null, null);
        downloadButton.setOnClickListener(null);
        deleteProgramButton.setVisibility(View.VISIBLE);

    }

    private class BuyAsyncClass extends AsyncTask<JSONObject, String, String> {


        @Override
        protected String doInBackground(JSONObject... jsonObjects) {

            return DataSenderHelper.POST(PublicVariables.buyProgramURL, jsonObjects[0]);

        }

        @Override
        protected void onPostExecute(String s) {
            if ("false".equals(s)) {
                Toast.makeText(getApplicationContext(), "Satın Alamadık", Toast.LENGTH_SHORT).show();
            } else {
                int kalanPara = Integer.parseInt(s);
                moneyText.setText(kalanPara + " TL");

                // Toast.makeText(getApplicationContext(), kalanPara + " kadar para kaldı", Toast.LENGTH_SHORT).show();
                Toast.makeText(getApplicationContext(), "Başarıyla satın aldık", Toast.LENGTH_SHORT).show();
                buyThisProgramButton.setVisibility(View.GONE);
                boughtProgramLinearLayout.setVisibility(View.VISIBLE);
                user.getMyPrograms().add(program);
                user.setMoney(kalanPara);
                DBHelper dbHelper = new DBHelper(getApplicationContext());
                dbHelper.updateUser(user);
            }
            progressDialog.cancel();
            super.onPostExecute(s);
        }
    }

    private class ReportAsyncClass extends AsyncTask<String, String, String> {


        @Override
        protected String doInBackground(String... strings) {
            JSONObject reportJson = new JSONObject();
            try {
                reportJson.accumulate("user_ID", user.getUser_ID());
                reportJson.accumulate("program_ID", programID);
                reportJson.accumulate("comment", strings[0]);
            } catch (JSONException e) {
                e.printStackTrace();
            }

            return DataSenderHelper.POST(PublicVariables.reportURL, reportJson);


        }

        @Override
        protected void onPostExecute(String s) {
            if ("true".equals(s)) {
                Toast.makeText(getApplicationContext(), "Successfully sent your report", Toast.LENGTH_SHORT).show();
            } else if ("false".equals(s)) {
                Toast.makeText(getApplicationContext(), "Already reported", Toast.LENGTH_SHORT).show();
            } else {
                Toast.makeText(getApplicationContext(), "An error occured", Toast.LENGTH_SHORT).show();

            }
            super.onPostExecute(s);
        }
    }

    private class MyAsyncClass extends AsyncTask {

        ArrayList<ExercisePOJO> exercisePOJOs = new ArrayList<>();
        JSONArray jsonArray;


        @Override
        protected Object doInBackground(Object[] objects) {

            JSONParser jsonParser = new JSONParser();
            jsonArray = jsonParser.getJSONArrayFromUrl(PublicVariables.getProgramDetailsURL + program.getProgramID());
            for (int i = 0; i < jsonArray.length(); i++) {
                JSONObject json = new JSONObject();
                try {
                    json = (JSONObject) jsonArray.get(i);
                } catch (JSONException e) {
                    e.printStackTrace();
                }


                String description = null;
                String exerciseType = null;
                int exercises_ID = 0;
                String name = null;
                int orderExercise = 0;
                byte[] photo1 = null;
                byte[] photo2 = null;
                int restTime = 0;
                String title = null;
                String video = null;
                Integer circleID = null;
                Integer circleCount = null;


                try {
                    exerciseType = json.getString("exerciseType");
                    description = json.getString("description");
                    exercises_ID = json.getInt("exercises_ID");
                    name = json.getString("name");
                    orderExercise = json.getInt("orderExercise");
                    restTime = json.getInt("restTime");
                    title = json.getString("tittle");
                    video = json.getString("video");
                    video = FunctionUtils.takeLastPartOfURL(video);


                } catch (JSONException e) {
                    e.printStackTrace();
                }
                downloadVideoFunction(video);

                try {
                    circleID = json.getInt("circleExercise_ID");
                } catch (JSONException e) {
                    e.printStackTrace();
                }
                try {
                    circleCount = json.getInt("circleExercise_Repeat");
                } catch (JSONException e) {
                    e.printStackTrace();
                }


                try {
                    photo1 = Base64.decode(json.getString("photo1"), Base64.DEFAULT);
//                    byte[] imageByte = Base64.decode(json.getString("photo1"), Base64.DEFAULT);
//                    photo1 = BitmapFactory.decodeByteArray(imageByte, 0, imageByte.length);
                } catch (JSONException e) {
                    e.printStackTrace();
                }
                try {
                    photo2 = Base64.decode(json.getString("photo2"), Base64.DEFAULT);
//                    byte[] imageByte = Base64.decode(json.getString("photo2"), Base64.DEFAULT);
//                    photo2 = BitmapFactory.decodeByteArray(imageByte, 0, imageByte.length);
                } catch (JSONException e) {
                    e.printStackTrace();
                }


                if (!PublicVariables.CARDIO.equals(exerciseType)) {

                    int agirlik = 0;
                    int setSayisi = 0;
                    int tekrarSayisi = 0;

                    try {
                        agirlik = json.getInt("agirlik");
                        setSayisi = json.getInt("setSayisi");
                        tekrarSayisi = json.getInt("tekrarSayisi");
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                    ChestPOJO chestPOJO = new ChestPOJO(description, exerciseType, exercises_ID, name, orderExercise, photo1, photo2, restTime, title, video, agirlik, setSayisi, tekrarSayisi, circleID, circleCount);
                    exercisePOJOs.add(chestPOJO);


                } else {

                    int exerciseTime = 0;


                    try {

                        exerciseTime = json.getInt("exerciseTime");
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                    CardioPOJO cardioPOJO = new CardioPOJO(description, exerciseType, exercises_ID, name, orderExercise, photo1, photo2, restTime, title, video, exerciseTime, circleID, circleCount);
                    exercisePOJOs.add(cardioPOJO);


                }


            }


            return null;
        }

        @Override
        protected void onPostExecute(Object o) {
            Toast.makeText(getApplicationContext(), "indirme tamamlandı", Toast.LENGTH_SHORT).show();
            program.setExercisez(exercisePOJOs);
            user.setProgramByID(program);
            ((GlobalVariables) getApplicationContext()).setUserDataPOJO(user);
            DBHelper dbhelper = new DBHelper(getApplicationContext());
            dbhelper.updateUser(user);
            disableDownloadButton();


            if (isWorkoutButton) {
                startWorkout();
            }


            super.onPostExecute(o);
        }
    }

//    /**
//     * Showing Dialog
//     */
//
//    @Override
//    protected Dialog onCreateDialog(int id) {
//        switch (id) {
//            case progress_bar_type: // we set this to 0
//                pDialog = new ProgressDialog(this);
//                pDialog.setMessage("Downloading file. Please wait...");
//                pDialog.setIndeterminate(false);
//                pDialog.setMax(100);
//                pDialog.setProgressStyle(ProgressDialog.STYLE_HORIZONTAL);
//                pDialog.setCancelable(true);
//                pDialog.show();
//                return pDialog;
//            default:
//                return null;
//        }
//    }


    private boolean downloadVideoFunction(String videoName) {


        //TODO / kısımlarını alma, sadece filename al, video yoksa indir, return olanlar da string filename dönsün

        try {
            FileInputStream fis = openFileInput(videoName);
            Log.i("download", "video varmış: " + videoName);


            return false;

        } catch (FileNotFoundException e) {
            e.printStackTrace();
            Log.i("download", "video yok inmemiş: " + videoName);

        }


        int count = 0;
        try {
            URL url = new URL(PublicVariables.videoBaseURL + videoName);
            URLConnection conection = url.openConnection();
            conection.connect();

            // this will be useful so that you can show a tipical 0-100%
            // progress bar
            int lenghtOfFile = conection.getContentLength();

            // download the file
            InputStream input = new BufferedInputStream(url.openStream(),
                    8192);

            // Output stream
            OutputStream output = openFileOutput(videoName, Context.MODE_PRIVATE);

            byte data[] = new byte[1024];

            long total = 0;

            while ((count = input.read(data)) != -1) {
                total += count;
                // publishing the progress....
                // After this onProgressUpdate will be called
//                    publishProgress("" + (int) ((total * 100) / lenghtOfFile));

                // writing data to file
                output.write(data, 0, count);
            }

            // flushing output
            output.flush();

            // closing streams
            output.close();
            input.close();

        } catch (Exception e) {
            Log.e("Error: ", e.getMessage());
            return false;
        }
        Log.i("download", "video indi: " + videoName);
        return true;
    }

    private class DownloadAllVideos extends AsyncTask {

        @Override
        protected Object doInBackground(Object[] objects) {
            Log.i("download", "indirme başladı");
            downloadVideoFunction("http://bitirmeprojesi.azurewebsites.net/videos/20170613153014vlc-record-2017-04-23-20h15m09s-3snMOV_0026-.mp4");
            Log.i("download", "indirme tamamlandı");
            return null;
        }
    }

    /**
     * Background Async Task to download file
     */
    class DownloadFileFromURL extends AsyncTask<String, String, String> {


        /**
         * Before starting background thread Show Progress Bar Dialog
         */
        @Override
        protected void onPreExecute() {
            super.onPreExecute();
//            showDialog(progress_bar_type);
        }

        /**
         * Downloading file in background thread
         */
        @Override
        protected String doInBackground(String... f_url) {
            int count;
            try {
                URL url = new URL(f_url[0]);
                URLConnection conection = url.openConnection();
                conection.connect();

                // this will be useful so that you can show a tipical 0-100%
                // progress bar
                int lenghtOfFile = conection.getContentLength();

                // download the file
                InputStream input = new BufferedInputStream(url.openStream(),
                        8192);

                // Output stream
                OutputStream output = new FileOutputStream(Environment
                        .getExternalStorageDirectory().toString()
                        + "/2011.kml");

                byte data[] = new byte[1024];

                long total = 0;

                while ((count = input.read(data)) != -1) {
                    total += count;
                    // publishing the progress....
                    // After this onProgressUpdate will be called
//                    publishProgress("" + (int) ((total * 100) / lenghtOfFile));

                    // writing data to file
                    output.write(data, 0, count);
                }

                // flushing output
                output.flush();

                // closing streams
                output.close();
                input.close();

            } catch (Exception e) {
                Log.e("Error: ", e.getMessage());
            }

            return null;
        }

        /**
         * Updating progress bar
         */
        protected void onProgressUpdate(String... progress) {
            // setting progress percentage
//            pDialog.setProgress(Integer.parseInt(progress[0]));
        }

        /**
         * After completing background task Dismiss the progress progressDialog
         **/
        @Override
        protected void onPostExecute(String file_url) {
            // dismiss the progressDialog after the file was downloaded
//            dismissDialog(progress_bar_type);

        }

    }


}
