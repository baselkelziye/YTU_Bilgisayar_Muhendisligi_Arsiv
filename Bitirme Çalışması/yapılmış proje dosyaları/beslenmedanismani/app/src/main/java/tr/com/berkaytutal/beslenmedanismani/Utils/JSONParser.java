package tr.com.berkaytutal.beslenmedanismani.Utils;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.URL;
import java.net.URLConnection;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.util.Log;

import static android.content.ContentValues.TAG;

public class JSONParser {

    static InputStream is = null;
    static JSONArray jObj = null;
    static JSONObject jsonObject=null;
    static String json = "";

    // constructor
    public JSONParser() {

    }

    public JSONObject getJSONObjectFromUrl(String ul){
        jsonObject=null;
        try {

            Log.i("url",ul);
            URL url = new URL(ul);
            URLConnection connection = url.openConnection();
            //connection.addRequestProperty("Referer", "https://ajax.googleapis.com/ajax/services/search/images?v=1.0&q=%22mixorg.com%22&rsz=8");

            String line;
            StringBuilder builder = new StringBuilder();
            BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
            while ((line = reader.readLine()) != null) {
                builder.append(line);
                System.out.println(builder.toString());
            }
            json = builder.toString();

        } catch (Exception e) {
            Log.e(TAG, "Error converting result " + e.toString());
        }

        // try parse the string to a JSON object
        try {
            jsonObject = new JSONObject(json);
        } catch (JSONException e) {
            Log.e(TAG, "Error parsing json data " + e.toString());
        } catch (Exception e) {

        }
        // return JSON String
        return jsonObject;

    }
    public JSONArray getJSONArrayFromUrl(String url) {

        // Making HTTP request
        try {
            // defaultHttpClient

            DefaultHttpClient httpClient = new DefaultHttpClient();
            HttpGet httpPost = new HttpGet(url);

            HttpResponse httpResponse = httpClient.execute(httpPost);
            HttpEntity httpEntity = httpResponse.getEntity();
            is = httpEntity.getContent();

        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        } catch (ClientProtocolException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(
                    is, "iso-8859-1"), 8);
            StringBuilder sb = new StringBuilder();
            String line = null;
            while ((line = reader.readLine()) != null) {
                sb.append(line + "n");
            }
            is.close();
            json = sb.toString();
        } catch (Exception e) {
            Log.e("Buffer Error", "Error converting result " + e.toString());
        }

        // try parse the string to a JSON object
        try {
            jObj = new JSONArray(json);
        } catch (JSONException e) {
            Log.e("JSON Parser", "Error parsing data " + e.toString());
        }

        // return JSON String
        return jObj;

    }
}