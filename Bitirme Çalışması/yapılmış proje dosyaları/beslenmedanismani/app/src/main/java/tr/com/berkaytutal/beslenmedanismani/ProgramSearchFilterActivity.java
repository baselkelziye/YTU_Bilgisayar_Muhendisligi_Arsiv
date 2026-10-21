package tr.com.berkaytutal.beslenmedanismani;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.Intent;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.SearchView;
import android.util.Base64;
import android.util.Log;
import android.view.ActionMode;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.Utils.DataSenderHelper;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramCategoryPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramDifficultyPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.PublicVariables;

public class ProgramSearchFilterActivity extends AppCompatActivity {

    private Button cancelButton;
    private Button applyButton;

    private EditText searchQueryEditText;
    private EditText trainerQueryEditText;
    private Spinner categorySpinner;
    private Spinner hardnessSpinner;
    private Spinner sortBySpinner;


    // private ArrayList<String> categories = new ArrayList<>();
    private ArrayList<ProgramDifficultyPOJO> difficulties;
    private ArrayList<ProgramCategoryPOJO> categories;


    private String searchQueryString = "";
    private String trainerQueryString = "";


    private int catPos = 0;
    private int diffPos = 0;
    private int sortPos = 0;

    private String catName;
    private String diffName;
    private String sortName;

    private JSONObject jsonObject;
    private ProgressDialog progressDialog;
    private Activity activity;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_search_filter);

        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);
        activity = this;

        categories = ((GlobalVariables) getApplicationContext()).getProgramCategories();
        difficulties = ((GlobalVariables) getApplicationContext()).getProgramDifficulties();


        //categories.add(getResources().getString(R.string.all));


        applyButton = (Button) findViewById(R.id.buttonFilterApply);
        cancelButton = (Button) findViewById(R.id.buttonFilterCancel);

        searchQueryEditText = (EditText) findViewById(R.id.filterSearchQueryEditText);
        trainerQueryEditText = (EditText) findViewById(R.id.filterTrainerQueryEditText);
        categorySpinner = (Spinner) findViewById(R.id.filterCategoriesSpinner);
        hardnessSpinner = (Spinner) findViewById(R.id.filterHardnessSpinner);
        sortBySpinner = (Spinner) findViewById(R.id.filterSortBySpinner);

        ArrayAdapter<CharSequence> sortBySpinnerAdapter = ArrayAdapter.createFromResource(
                this, R.array.sortBy, android.R.layout.simple_spinner_item);
        sortBySpinnerAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        sortBySpinner.setAdapter(sortBySpinnerAdapter);


        ArrayAdapter<ProgramDifficultyPOJO> hardnessAdapter = new ArrayAdapter<>(this,
                android.R.layout.simple_spinner_item, difficulties);
        hardnessAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        hardnessSpinner.setAdapter(hardnessAdapter);

//        hardnessSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
//            @Override
//            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
//                Toast.makeText(getApplicationContext(), difficulties.get(i).getId() + "", Toast.LENGTH_SHORT).show();
//            }
//
//            @Override
//            public void onNothingSelected(AdapterView<?> adapterView) {
//
//            }
//        });

        //hardnessSpinner.setSelection(1);


        final ArrayAdapter<ProgramCategoryPOJO> categoriesAdapter = new ArrayAdapter<>(this,
                android.R.layout.simple_spinner_item, categories);
        categoriesAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        categorySpinner.setAdapter(categoriesAdapter);

//        categorySpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
//            @Override
//            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
//                Toast.makeText(getApplicationContext(), categories.get(i).getId() + "", Toast.LENGTH_SHORT).show();
//            }
//
//            @Override
//            public void onNothingSelected(AdapterView<?> adapterView) {
//
//            }
//        });


        Intent resultIntent = getIntent();
        if (resultIntent != null) {
            searchQueryString = resultIntent.getStringExtra("searchQueryString");
            trainerQueryString = resultIntent.getStringExtra("trainerQueryString");
            catPos = resultIntent.getIntExtra("catPos", 0);
            diffPos = resultIntent.getIntExtra("diffPos", 0);
            sortPos = resultIntent.getIntExtra("sortPos", 0);
        }

        searchQueryEditText.setText(searchQueryString);
        trainerQueryEditText.setText(trainerQueryString);
        categorySpinner.setSelection(catPos);
        hardnessSpinner.setSelection(diffPos);
        sortBySpinner.setSelection(sortPos);

        applyButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //buraya settings kısmını koyup burayı finish edip önceki activity'ye intent ile göndericez

                progressDialog = ProgressDialog.show(activity, "",
                        "Loading...", true);

                searchQueryString = searchQueryEditText.getText().toString();

                trainerQueryString = trainerQueryEditText.getText().toString();

                catName = ((ProgramCategoryPOJO) categorySpinner.getSelectedItem()).getName();
                catPos = categorySpinner.getSelectedItemPosition();


                diffName = ((ProgramDifficultyPOJO) hardnessSpinner.getSelectedItem()).getName();
                diffPos = hardnessSpinner.getSelectedItemPosition();

                sortPos = sortBySpinner.getSelectedItemPosition();
                sortName = sortBySpinner.getSelectedItem().toString();

                jsonObject = new JSONObject();

                if (!searchQueryString.replaceAll("\\s+", "").equals("")) {
                    try {
                        jsonObject.accumulate("searchQuery", searchQueryString);
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                } else {
                    try {
                        jsonObject.accumulate("searchQuery", "");
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                }
                if (!trainerQueryString.replaceAll("\\s+", "").equals("")) {
                    try {
                        jsonObject.accumulate("trainerQuery", trainerQueryString);
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                } else {
                    try {
                        jsonObject.accumulate("trainerQuery", "");
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }

                }

                try {
                    if (catPos != PublicVariables.ALL_ID) {
                        jsonObject.accumulate("category", catName);
                    } else {
                        jsonObject.accumulate("category", "");
                    }
                    if (diffPos != PublicVariables.ALL_ID) {
                        jsonObject.accumulate("hardness", diffName);
                    } else {
                        jsonObject.accumulate("hardness", "");
                    }

                    jsonObject.accumulate("sortBy", sortName);
                } catch (JSONException e) {
                    e.printStackTrace();
                }


                ProgramASYNC async = new ProgramASYNC();
                async.execute("test");

                //Toast.makeText(view.getContext(), searchQueryString + " " + trainerQueryString, Toast.LENGTH_SHORT).show();
                //finish();


            }
        });


        cancelButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
            }
        });
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
    }

    private class ProgramASYNC extends AsyncTask<String, Void, String> {

        @Override
        protected String doInBackground(String[] objects) {
            Log.i("searchRequest", jsonObject.toString());
            return DataSenderHelper.POST(PublicVariables.searchFilterURL, jsonObject);
        }

        @Override
        protected void onPostExecute(String result) {
            super.onPostExecute(result);
            Log.i("searchResults", result);
            JSONArray jsonArray = new JSONArray();
            try {
                jsonArray = new JSONArray(result);
            } catch (JSONException e) {
                e.printStackTrace();
            }

            ArrayList<ProgramPOJO> allPrograms = new ArrayList<>();

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

            Intent intent = new Intent(getApplicationContext(), AllListingsActivity.class);
            intent.putExtra("filterResults", allPrograms);
            intent.putExtra("searchQueryString", searchQueryString);
            intent.putExtra("trainerQueryString", trainerQueryString);
            intent.putExtra("catPos", catPos);
            intent.putExtra("diffPos", diffPos);
            intent.putExtra("sortPos", sortPos);

            progressDialog.cancel();


            startActivity(intent);
            finish();


        }
    }

}
