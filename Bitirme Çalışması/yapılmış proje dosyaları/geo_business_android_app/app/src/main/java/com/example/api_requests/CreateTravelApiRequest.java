package com.example.api_requests;

import android.os.AsyncTask;
import android.util.Log;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;

public class CreateTravelApiRequest extends AsyncTask<String, Void, String> {

    private static final String TAG = "CreateTravelApiRequest";
    private ApiCallback callback;

    public interface ApiCallback {
        void onTaskComplete(String result);
    }

    public CreateTravelApiRequest(ApiCallback callback) {
        this.callback = callback;
    }

    @Override
    protected String doInBackground(String... params) {
        String apiUrl = params[0];
        String requestBody = params[1];
        String accessToken = params[2];

        try {
            URL url = new URL(apiUrl);
            HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();

            // İstek methodunu ayarla
            urlConnection.setRequestMethod("POST");

            // Headers ayarla
            urlConnection.setRequestProperty("Content-Type", "application/json");
            urlConnection.setRequestProperty("Authorization", accessToken);

            // POST isteği için request bodysini ayarla
            urlConnection.setDoOutput(true);
            try (DataOutputStream wr = new DataOutputStream(urlConnection.getOutputStream())) {
                wr.write(requestBody.getBytes(StandardCharsets.UTF_8));
            }

            // Sunucudan gelen cevabı al
            int responseCode = urlConnection.getResponseCode();
            if (responseCode == HttpURLConnection.HTTP_OK) {
                BufferedReader in = new BufferedReader(new InputStreamReader(urlConnection.getInputStream()));
                StringBuilder response = new StringBuilder();
                String inputLine;
                while ((inputLine = in.readLine()) != null) {
                    response.append(inputLine);
                }
                in.close();
                return response.toString();
            } else {
                Log.e(TAG, "HTTP Error Code: " + responseCode);
            }

        } catch (IOException e) {
            e.printStackTrace();
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
