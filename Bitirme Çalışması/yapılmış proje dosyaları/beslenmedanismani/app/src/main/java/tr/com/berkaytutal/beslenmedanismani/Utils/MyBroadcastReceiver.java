package tr.com.berkaytutal.beslenmedanismani.Utils;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.AsyncTask;
import android.support.v7.app.AlertDialog;
import android.util.Log;
import android.widget.Toast;

import java.util.List;

import tr.com.berkaytutal.beslenmedanismani.ProgramPlayActivity;
import tr.com.berkaytutal.beslenmedanismani.SplashScreen;

import static android.content.Context.ACTIVITY_SERVICE;

/**
 * Created by berka on 5.07.2017.
 */


public class MyBroadcastReceiver extends BroadcastReceiver {
    private Context context;
    private GlobalVariables globalVariables;

    @Override
    public void onReceive(Context context, Intent ıntent) {
        if (isAppForground(context)) {
            this.context = context;
            globalVariables = ((GlobalVariables) context.getApplicationContext());

            if (!globalVariables.isShowingOnlineOfflineDialog()) {
                globalVariables.setShowingOnlineOfflineDialog(true);
                NetworkCheckAsyncClass asyncCalss = new NetworkCheckAsyncClass();
                asyncCalss.execute("");
            }


//
//
//
//            ConnectivityManager connectivityManager = (ConnectivityManager) context.getSystemService(Context.CONNECTIVITY_SERVICE);
//            NetworkInfo activeNetworkInfo = connectivityManager.getActiveNetworkInfo();
//
//            if(activeNetworkInfo == null){
//                //no network
//            } else {
//                NetworkInfo.State state = activeNetworkInfo.getState();
//                if(state == NetworkInfo.State.CONNECTED){
//                    globalVariables.setShowingOnlineOfflineDialog(true);
//                    NetworkCheckAsyncClass asyncCalss = new NetworkCheckAsyncClass();
//                    asyncCalss.execute("");
//                }
//
//                switch (state){
//                    case CONNECTED:
//
//                        break;
//                    case CONNECTING:
//                        break;
//                    case DISCONNECTED:
//                        break;
//                    case DISCONNECTING:
//                        break;
//                    case SUSPENDED:
//                        break;
//                    case UNKNOWN:
//                        break;
//                }
//            }
////
////            if(!globalVariables.isShowingOnlineOfflineDialog()){
////                globalVariables.setShowingOnlineOfflineDialog(true);
////                NetworkCheckAsyncClass asyncCalss = new NetworkCheckAsyncClass();
////                asyncCalss.execute("");
////            }


        } else {
            // App is in Background

        }
    }

    public boolean isAppForground(Context mContext) {

        ActivityManager am = (ActivityManager) mContext.getSystemService(ACTIVITY_SERVICE);
        List<ActivityManager.RunningTaskInfo> tasks = am.getRunningTasks(1);
        if (!tasks.isEmpty()) {
            ComponentName topActivity = tasks.get(0).topActivity;
            if (!topActivity.getPackageName().equals(mContext.getPackageName())) {
                return false;
            }
        }

        return true;
    }

    private class NetworkCheckAsyncClass extends AsyncTask {
        @Override
        protected Object doInBackground(Object[] objects) {

            if (FunctionUtils.isInternetAvailable()) {
                return "yesinternet";
            } else {
                return "nointernet";
            }


        }

        @Override
        protected void onPostExecute(Object o) {
            super.onPostExecute(o);


            ActivityManager am = (ActivityManager) context.getSystemService(ACTIVITY_SERVICE);
            List<ActivityManager.RunningTaskInfo> taskInfo = am.getRunningTasks(1);
            ComponentName componentInfo = taskInfo.get(0).topActivity;
            Log.d("CURRENTACTIVITY", "CURRENT Activity ::" + taskInfo.get(0).topActivity.getClassName() + "   Package Name :  " + componentInfo.getPackageName());


            if (o.toString().equals("yesinternet")) {
                //Toast.makeText(context, "internet geldi", Toast.LENGTH_SHORT).show();

                if (taskInfo.get(0).topActivity.getClassName().equals("tr.com.berkaytutal.beslenmedanismani.ProgramPlayActivity")) {
                    if (globalVariables.isOnline()) {
                        globalVariables.setSwitchOnlineOffline(true);
                        globalVariables.setSwitchFromOffline(true);
                    }
                } else {

                    //offline to online
                    Intent i = new Intent(context, AlertDialogActivity.class);
                    i.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                    i.putExtra("fromOffline", true);
                    context.startActivity(i);
                }

                //yesinternet sonu
            } else {
                //Toast.makeText(context, "internet gitti", Toast.LENGTH_SHORT).show();
                if (taskInfo.get(0).topActivity.getClassName().equals("tr.com.berkaytutal.beslenmedanismani.ProgramPlayActivity")) {
                    if (globalVariables.isOnline()) {
                        globalVariables.setSwitchOnlineOffline(true);
                        globalVariables.setSwitchFromOffline(false);
                    }
                } else {

                    //online to offline
                    Intent i = new Intent(context, AlertDialogActivity.class);
                    i.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                    i.putExtra("fromOffline", false);
                    context.startActivity(i);

                }


            }


        }
    }
}
