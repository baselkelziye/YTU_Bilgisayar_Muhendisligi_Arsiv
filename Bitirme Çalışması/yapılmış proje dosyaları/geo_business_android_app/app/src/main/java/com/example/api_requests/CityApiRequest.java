package com.example.api_requests;

import android.os.AsyncTask;
import android.util.Log;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.HashMap;
import java.util.Map;

public class CityApiRequest extends AsyncTask<String, Void, String> {

    private static final String TAG = "CityApiRequest";
    private CityApiRequest.ApiCallback callback;

    public interface ApiCallback {
        void onTaskComplete(String result);
    }

    public CityApiRequest(CityApiRequest.ApiCallback callback) {
        this.callback = callback;
    }

    @Override
    protected String doInBackground(String... params) {
        String apiUrl = params[0];
        String requestMethod = params[1];

        // Parameters ve Headers için Map nesnelerini oluştur
        Map<String, String> requestParams = new HashMap<>();
        requestParams.put("city", params[2]);

        Map<String, String> requestHeaders = new HashMap<>();
        requestHeaders.put("Authorization", params[3]);

        try {
            URL url = new URL(apiUrl);
            HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();

            // İstek methodunu ayarla
            urlConnection.setRequestMethod(requestMethod);

            // Başlıkları ayarla
            for (Map.Entry<String, String> entry : requestHeaders.entrySet()) {
                urlConnection.setRequestProperty(entry.getKey(), entry.getValue());
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