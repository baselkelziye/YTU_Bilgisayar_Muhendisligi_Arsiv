package tr.com.berkaytutal.beslenmedanismani.Utils;

import android.app.Activity;
import android.os.AsyncTask;
import android.util.Log;
import android.widget.Toast;

import org.json.JSONObject;

import java.util.ArrayList;

/**
 * Created by berka on 4.07.2017.
 */

public class BodyRatioSender extends AsyncTask<Activity,String,String> {

    private Activity activity;
    private GlobalVariables globalVariables;
    private UserDataPOJO user;

    @Override
    protected String doInBackground(Activity... activities) {

        Log.i("bodyRatio","Updating body ratios");

        this.activity = activities[0];
        globalVariables = (GlobalVariables)activity.getApplicationContext();
        user = globalVariables.getUserDataPOJO();

        ArrayList<BodyRatioPOJO> offlineBodyRatios = user.getOfflineBodyRatios();

        for(int i = 0;i<offlineBodyRatios.size();i++){
            BodyRatioPOJO bodyRatio = offlineBodyRatios.get(i);
            JSONObject jsonObject = new JSONObject();

            try{
                jsonObject.accumulate("date",bodyRatio.getDate());
                jsonObject.accumulate("fatRate",bodyRatio.getFatRate());
                jsonObject.accumulate("muscleRate",bodyRatio.getMuscleRate());
                jsonObject.accumulate("user_ID",bodyRatio.getUserID());
                jsonObject.accumulate("waterRate",bodyRatio.getWaterRate());
                jsonObject.accumulate("weight",bodyRatio.getWeight());
                jsonObject.accumulate("tall",bodyRatio.getTall());
            }
            catch (Exception e){
                e.printStackTrace();
            }

            DataSenderHelper.POST(PublicVariables.insertBodyRatioURL,jsonObject);

            user.getBodyRatiosArrayList().add(bodyRatio);


        }
        user.getOfflineBodyRatios().clear();

        DBHelper dbhelper = new DBHelper(activity);
        dbhelper.updateUser(user);
        return null;
    }

    @Override
    protected void onPostExecute(String s) {
        super.onPostExecute(s);
        Toast.makeText(activity,"Body ratios synced",Toast.LENGTH_SHORT);
    }
}
