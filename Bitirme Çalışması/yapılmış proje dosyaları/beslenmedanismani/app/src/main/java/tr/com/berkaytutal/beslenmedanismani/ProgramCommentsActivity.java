package tr.com.berkaytutal.beslenmedanismani;

import android.app.Activity;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.support.design.widget.FloatingActionButton;
import android.support.v4.widget.SwipeRefreshLayout;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Base64;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Spinner;
import android.widget.Toast;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.Adapters.ProgramCommentsAdapter;
import tr.com.berkaytutal.beslenmedanismani.Utils.CommentPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.DBHelper;
import tr.com.berkaytutal.beslenmedanismani.Utils.DataSenderHelper;
import tr.com.berkaytutal.beslenmedanismani.Utils.FunctionUtils;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.JSONParser;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.PublicVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.UserDataPOJO;

import static android.view.View.GONE;

public class ProgramCommentsActivity extends AppCompatActivity implements SwipeRefreshLayout.OnRefreshListener {

    private int programID;
    private ListView programCommentsListView;
    private Context context;
    private Activity activity;
    private FloatingActionButton commentFAB;
    private boolean isBought = false;
    private ProgramPOJO myProgram;

    private ArrayList<CommentPOJO> comments;

    private GlobalVariables globalVariables;

    private ProgressDialog progressDialog;

    private SwipeRefreshLayout swipeRefreshLayout;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_program_comments);
        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);

        globalVariables = ((GlobalVariables) getApplicationContext());

        activity = this;
        context = this;

        programID = getIntent().getIntExtra("programID", 0);
//        Toast.makeText(this, programID + " ", Toast.LENGTH_SHORT).show();

        UserDataPOJO user = globalVariables.getUserDataPOJO();
        if (user != null) {
            myProgram = globalVariables.getUserDataPOJO().getProgramByID(programID);
            if (myProgram != null) {
                isBought = true;
            } else {
                myProgram = globalVariables.getProgramByID(programID);
            }
        } else {
            myProgram = globalVariables.getProgramByID(programID);
        }


        programCommentsListView = (ListView) findViewById(R.id.programCommentsListView);
        commentFAB = (FloatingActionButton) findViewById(R.id.programCommentsFAB);


        if (isBought == false) {
            commentFAB.setVisibility(GONE);
        }

        if (globalVariables.isOnline()) {
            progressDialog = ProgressDialog.show(activity, "",
                    "Loading...", true);
            MyAsyncClass async = new MyAsyncClass();
            async.execute("test");

//            if (myProgram.getComments().size() == 0) {
//                progressDialog = ProgressDialog.show(activity, "",
//                        "Loading...", true);
//                MyAsyncClass async = new MyAsyncClass();
//                async.execute("test");
//            } else {
//                comments = myProgram.getComments();
//                setTheRest();
//            }

        } else {
            if (false) {
//            if (myProgram.getComments().size() > 0) {
                comments = myProgram.getComments();
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
        }


        swipeRefreshLayout = (SwipeRefreshLayout) findViewById(R.id.swipeRefreshLayoutComments);

        swipeRefreshLayout.setOnRefreshListener(this);
        swipeRefreshLayout.setColorSchemeColors(getResources().getColor(android.R.color.holo_blue_bright),
                getResources().getColor(android.R.color.holo_green_light),
                getResources().getColor(android.R.color.holo_orange_light),
                getResources().getColor(android.R.color.holo_red_light));


    }

    private void setTheRest() {


        final Dialog commentDialog = new Dialog(this);
        commentDialog.setContentView(R.layout.custom_dialog_comment);
        final Spinner ratingSpinner = (Spinner) commentDialog.findViewById(R.id.commentRatingSpinner);
        final ArrayAdapter<CharSequence> commentRatingAdapter = ArrayAdapter.createFromResource(
                this, R.array.ratings, android.R.layout.simple_spinner_item);
        commentRatingAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);

        ratingSpinner.setAdapter(commentRatingAdapter);


        final EditText commentEditText = (EditText) commentDialog.findViewById(R.id.dialogCommentEditText);
        Button cancelButton = (Button) commentDialog.findViewById(R.id.dialogCommentCancelButton);
        Button commentButton = (Button) commentDialog.findViewById(R.id.dialogCommentYesButton);

        cancelButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                commentDialog.dismiss();
            }
        });
        if (isBought) {
            commentButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    int rating = Integer.parseInt(ratingSpinner.getSelectedItem().toString().replaceAll("[\\D]", ""));
                    String comment = commentEditText.getText().toString();
                    Toast.makeText(view.getContext(), "Your comment is sending", Toast.LENGTH_SHORT).show();
                    commentDialog.dismiss();

                    JSONObject jsonComment = new JSONObject();
                    try {
                        jsonComment.accumulate("program_ID", programID);
                        jsonComment.accumulate("user_ID", ((GlobalVariables) getApplicationContext()).getUserDataPOJO().getUser_ID());
                        jsonComment.accumulate("rating", rating);
                        jsonComment.accumulate("comment", comment);
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }

                    MakeCommentAsync makeCommentAsync = new MakeCommentAsync();
                    makeCommentAsync.execute(jsonComment);

                }
            });
        }
        commentDialog.setCanceledOnTouchOutside(true);


        commentFAB.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {


                commentDialog.show();

            }
        });

        //comments = myProgram.getComments();

        ProgramCommentsAdapter adapter = new ProgramCommentsAdapter(activity, comments);
        programCommentsListView.setAdapter(adapter);
        View empty = findViewById(R.id.empty);
        programCommentsListView.setEmptyView(empty);
        if (comments.size() == 0) {
            empty.setVisibility(View.VISIBLE);
            programCommentsListView.setVisibility(GONE);
        }
        if (progressDialog != null) {
            progressDialog.cancel();
        }
        swipeRefreshLayout.setRefreshing(false);

    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
    }

    @Override
    public void onRefresh() {
        progressDialog = ProgressDialog.show(activity, "",
                "Loading...", true);
        MyAsyncClass async = new MyAsyncClass();
        async.execute("test");
    }

    private class MakeCommentAsync extends AsyncTask<JSONObject, String, String> {

        @Override
        protected String doInBackground(JSONObject... jsonObjects) {

            return DataSenderHelper.POST(PublicVariables.commentURL, jsonObjects[0]);

        }

        @Override
        protected void onPostExecute(String s) {

            if ("true".equals(s)) {
                Toast.makeText(context, "Your comment sent succesfully", Toast.LENGTH_SHORT).show();
            } else if ("false".equals(s)) {
                Toast.makeText(context, "You've already commented", Toast.LENGTH_SHORT).show();
            } else {
                Toast.makeText(context, "A problem occured while sending", Toast.LENGTH_SHORT).show();

            }
            super.onPostExecute(s);
        }
    }


    private class MyAsyncClass extends AsyncTask<String, String, String> {


        @Override
        protected String doInBackground(String... strings) {

            //TODO loading progressDialog

            JSONParser jsonParser = new JSONParser();

            JSONArray jsonArray = jsonParser.getJSONArrayFromUrl(PublicVariables.getCommentsURL + myProgram.getProgramID());

            comments = new ArrayList<>();
            for (int i = 0; i < jsonArray.length(); i++) {
                try {

                    JSONObject json = (JSONObject) jsonArray.get(i);
                    String comment = json.getString("comment");
                    String name = json.getString("name");
                    String surname = json.getString("surname");
                    int rating = json.getInt("rating");
                    byte[] photo = null;
                    try {
                        photo = Base64.decode(json.getString("photo"), Base64.DEFAULT);
                    } catch (Exception e) {
                        e.printStackTrace();
                        photo = FunctionUtils.bitmapToByte(BitmapFactory.decodeResource(getApplicationContext().getResources(), R.drawable.profile_man));
                    }
                    comments.add(new CommentPOJO(photo, name + " " + surname, comment, rating));

                } catch (JSONException e) {
                    e.printStackTrace();
                }
            }
            myProgram.setComments(comments);
            return null;
        }

        @Override
        protected void onPostExecute(String s) {
            // Toast.makeText(context, "postExecute", Toast.LENGTH_SHORT).show();

            setTheRest();
            super.onPostExecute(s);
        }
    }
}
