package tr.com.berkaytutal.beslenmedanismani;

import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import org.json.JSONException;
import org.json.JSONObject;

import tr.com.berkaytutal.beslenmedanismani.Utils.BaseDrawerActivity;
import tr.com.berkaytutal.beslenmedanismani.Utils.DBHelper;
import tr.com.berkaytutal.beslenmedanismani.Utils.DataSenderHelper;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.PublicVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.UserDataPOJO;

public class BodyRates extends BaseDrawerActivity {


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

    private UserDataPOJO user;
    private JSONObject jsonObject;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_body_rates);

        user = ((GlobalVariables) getApplicationContext()).getUserDataPOJO();

        tallEditText = (EditText) findViewById(R.id.bodyRatesTallEditText);
        weightEditText = (EditText) findViewById(R.id.bodyRatesWeightEditText);
        muscleRateEditText = (EditText) findViewById(R.id.bodyRatesMuscleRateEditText);
        fatRateEditText = (EditText) findViewById(R.id.bodyRatesFatRateEditText);
        waterRateEditText = (EditText) findViewById(R.id.bodyRatesWaterRaEditText);
        updateButton = (Button) findViewById(R.id.bodyRatesUpdateButton);

        tallEditText.setText(tall);
        weightEditText.setText(weight);
        muscleRateEditText.setText(muscleRate);
        fatRateEditText.setText(fatRate);
        waterRateEditText.setText(waterRate);

        updateButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                tall = tallEditText.getText().toString();
                weight = weightEditText.getText().toString();
                muscleRate = muscleRateEditText.getText().toString();
                fatRate = fatRateEditText.getText().toString();
                waterRate = waterRateEditText.getText().toString();
                jsonObject = new JSONObject();
                try {
                    jsonObject.accumulate("fatRate", fatRate);
                    jsonObject.accumulate("muscleRate", muscleRate);
                    jsonObject.accumulate("tall", tall);
                    jsonObject.accumulate("user_ID", user.getUser_ID());
                    jsonObject.accumulate("waterRate", waterRate);
                    jsonObject.accumulate("weight", weight);
                } catch (JSONException e) {
                    e.printStackTrace();
                }
                MyAsyncClass2 async = new MyAsyncClass2();
                async.execute("test");


            }
        });


    }

    private class MyAsyncClass2 extends AsyncTask<String, Void, String> {


        @Override
        protected String doInBackground(String... strings) {
            Log.i("body","update isteği yollandı");
//            Toast.makeText(getApplicationContext(), "istek Gönderildi", Toast.LENGTH_SHORT).show();
            return DataSenderHelper.POST(PublicVariables.bodyRateUpdateURL, jsonObject);
        }

        @Override
        protected void onPostExecute(String result) {
            super.onPostExecute(result);
            if (result.equals("false")) {
                Log.e("body","sorun oluştu");
                //Toast.makeText(getApplicationContext(), "sorun oluştu", Toast.LENGTH_SHORT).show();
            } else if (result.equals("true")) {
                Log.i("body","update başarılı");
//                user.setFatRate(fatRate);
//                user.setMuscleRate(muscleRate);
//                user.setTall(tall);
//                user.setWaterRate(waterRate);
//                user.setWeight(weight);
                DBHelper dbHelper = new DBHelper(getApplicationContext());
                dbHelper.updateUser(user);
                ((GlobalVariables)getApplicationContext()).setUserDataPOJO(user);
                //Toast.makeText(getApplicationContext(), "Başarılı", Toast.LENGTH_SHORT).show();



            }

        }
    }
}
