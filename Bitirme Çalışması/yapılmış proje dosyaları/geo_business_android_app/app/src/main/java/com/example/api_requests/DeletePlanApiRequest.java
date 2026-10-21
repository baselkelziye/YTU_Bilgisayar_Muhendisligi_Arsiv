package com.example.api_requests;

import android.os.AsyncTask;
import android.util.Log;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class DeletePlanApiRequest extends AsyncTask<String, Void, String> {

    private static final String TAG = "DeletePlanApiRequest";
    private ApiCallback callback;

    public interface ApiCallback {
        void onTaskComplete(String result);
    }

    public DeletePlanApiRequest(ApiCallback callback) {
        this.callback = callback;
    }

    @Override
    protected String doInBackground(String... params) {
        String apiUrl = params[0];
        String planId = params[1];
        String access_token = params[2];

        try {
            URL url = new URL(apiUrl + "/plan/" + planId);
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestMethod("DELETE");
            connection.setRequestProperty("Content-Type", "application/json");
            connection.setRequestProperty("Authorization", access_token);

            int responseCode = connection.getResponseCode();

            if (responseCode == HttpURLConnection.HTTP_OK) {
                BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                StringBuilder response = new StringBuilder();
                String line;

                while ((line = reader.readLine()) != null) {
                    response.append(line);
                }

                reader.close();
                return response.toString();
            } else {
                Log.e(TAG, "HTTP Error Code: " + responseCode);
            }
        } catch (IOException e) {
            Log.e(TAG, "IOException: " + e.getMessage());
        }

        return null;
    }

    @Override
    protected void onPostExecute(String result) {
        if (callback != null) {
            callback.onTaskComplete(result);
        }
    }
}
