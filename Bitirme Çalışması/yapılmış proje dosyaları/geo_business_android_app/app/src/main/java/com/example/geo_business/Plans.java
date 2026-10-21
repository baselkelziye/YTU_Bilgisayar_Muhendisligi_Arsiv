package com.example.geo_business;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.DefaultItemAnimator;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.example.adapters.PlanAdapter;
import com.example.api_requests.PlanListApiRequest;
import com.example.config.ApiConfig;
import com.example.models.Plan;
import com.example.shared_data.PlanData;
import com.example.shared_data.TokenData;
import com.example.shared_data.UserData;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

public class Plans extends AppCompatActivity implements PlanAdapter.OnItemClickListener {

    public static ArrayList<Plan> planList = new ArrayList<>();
    private static final String TAG = "PlansActivity";
    private static final String page = "1";
    private String id, employeeUsername, travelDate, endLocation, accountantUsername;
    private Float latitude, longitude;



    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_plans);

        PlanAdapter adapter = new PlanAdapter(planList, this);
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(this, RecyclerView.VERTICAL, false);
        RecyclerView recyclerView = (RecyclerView) findViewById(R.id.plan_recycler_view);

        recyclerView.setLayoutManager(linearLayoutManager);
        recyclerView.setItemAnimator(new DefaultItemAnimator());
        recyclerView.setAdapter(adapter);

        adapter.setOnItemClickListener(this);

        viewPlans(adapter);
    }



    public void viewPlans(PlanAdapter adapter) {
        // create JSON Object with username and password
        JSONObject jsonParams = new JSONObject();

        String[] tokens = TokenData.getInstance().getSharedData();
        String accessToken = tokens[0];

        String apiUrl = ApiConfig.BASE_API_URL + "/plan/?page=1";  // Update the base URL accordingly

        // Assuming jsonResponse is a JSONArray
        PlanListApiRequest planListApiRequest = new PlanListApiRequest(new PlanListApiRequest.ApiCallback() {
            @Override
            public void onTaskComplete(String result) {

                Log.d(TAG, "Plan Listesi API Response: " + result);

                try {
                    JSONArray jsonResponse = new JSONArray(result);

                    Log.d(TAG, "jsonResponse: " + jsonResponse);
                    Log.d(TAG, "jsonResponseLength: " + jsonResponse.length());

                    planList.clear();

                    for (int i = 0; i < jsonResponse.length(); i++) {
                        try {
                            JSONObject jsonObject = jsonResponse.getJSONObject(i);

                            // Accessing the fields in the JSON object and assigning them to the class properties
                            id = jsonObject.getString("_id");
                            employeeUsername = jsonObject.getString("employeeUsername");
                            travelDate = jsonObject.getString("travelDate");
                            endLocation = jsonObject.getString("endLocation");
                            accountantUsername = jsonObject.getString("accountantUsername");

                            // Accessing coordinates object
                            JSONObject coordinatesObject = jsonObject.getJSONObject("coordinates");
                            latitude = (float) coordinatesObject.getDouble("lat");
                            longitude = (float) coordinatesObject.getDouble("lng");

                            String coordinates = String.valueOf(latitude) + ", " + String.valueOf(longitude);

                            planList.add(new Plan(id, employeeUsername, travelDate, endLocation, new Plan.Coordinates(String.valueOf(latitude), String.valueOf(longitude)), accountantUsername));
                            if(planList.size() == 0) {
                                Log.d("plan list", "boş");
                            }
                            else {
                                Log.d("plan list", "dolu");
                                Log.d("plan list", planList.toString());
                            }
                        } catch (JSONException e) {
                            e.printStackTrace();
                        }
                    }

                    // Notify the adapter that the data has changed
                    runOnUiThread(new Runnable() {

                        @Override
                        public void run() {
                            Log.d("plan deneme", "adapter notify"); adapter.notifyDataSetChanged();
                        }
                    });

                } catch (JSONException e) {
                    e.printStackTrace();
                    Log.e(TAG, "JSON Parsing Error: " + e.getMessage());
                    Toast.makeText(Plans.this, "HATA!", Toast.LENGTH_SHORT).show();
                }
            }
        });

        // Make the API request
        planListApiRequest.execute(apiUrl, page, accessToken);
    }

    @Override
    public void onItemClick(Plan plan) {
        // Tıklanan öğenin değerlerini burada günlüğe kaydet
        Log.d("Tıklanan Plan", plan.toString());

        // Şu anki tarihi al
        Date date = new Date();

        // Tarih biçimleyici oluştur
        SimpleDateFormat sdf = new SimpleDateFormat("dd.MM.yyyy");

        // Biçimlendirilmiş tarihi al
        String formattedDate = sdf.format(date);

        // Sonucu yazdır
        System.out.println("Biçimlendirilmiş Tarih: " + formattedDate);
        Log.d("tarih: ", formattedDate);
        Log.d("tarih: ", plan.getTravelDate());

        PlanData.getInstance().setSharedData(plan);

        if(formattedDate.equals(plan.getTravelDate())) {
            Intent intent = new Intent(getApplicationContext(), PlanMap.class);
            startActivity(intent);
        }
        else {
            Toast.makeText(this, "Bu işlem yalnızca uygun tarihte gerçekleştirilebilir.", Toast.LENGTH_SHORT).show();
        }

    }

}
