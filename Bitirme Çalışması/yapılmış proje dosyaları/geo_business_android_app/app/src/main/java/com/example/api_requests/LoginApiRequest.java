package com.example.api_requests;

import android.os.AsyncTask;
import android.util.Log;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class LoginApiRequest extends AsyncTask<String, Void, String> {
    private static final String TAG = "LoginApiRequest";
    private ApiCallback callback;

    public LoginApiRequest(ApiCallback callback) {
        this.callback = callback;
    }

    @Override
    protected String doInBackground(String... params) {
        String urlString = params[0];
        String jsonData = params[1];
        String result = "";

        try {
            URL url = new URL(urlString);
            HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();
            urlConnection.setRequestMethod("POST");
            urlConnection.setRequestProperty("Content-Type", "application/json");
            urlConnection.setDoOutput(true);

            // send POST request
            DataOutputStream wr = new DataOutputStream(urlConnection.getOutputStream());
            wr.writeBytes(jsonData);
            wr.flush();
            wr.close();

            // get server's response
            BufferedReader reader = new BufferedReader(new InputStreamReader(urlConnection.getInputStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                result += line;
            }
            reader.close();
            urlConnection.disconnect();
        } catch (Exception e) {
            Log.e(TAG, "HTTP Request Error: " + e.getMessage());
            result = "Error";
        }

        return result;
    }

    @Override
    protected void onPostExecute(String result) {
        callback.onTaskComplete(result);
    }

    public interface ApiCallback {
        void onTaskComplete(String result);
    }
}
