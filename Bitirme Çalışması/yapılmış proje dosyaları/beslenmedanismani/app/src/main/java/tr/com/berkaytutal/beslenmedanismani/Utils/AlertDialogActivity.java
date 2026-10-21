package tr.com.berkaytutal.beslenmedanismani.Utils;

import android.content.DialogInterface;
import android.content.Intent;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import tr.com.berkaytutal.beslenmedanismani.SplashScreen;

public class AlertDialogActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        boolean fromOffline = getIntent().getBooleanExtra("fromOffline", false);

        if (fromOffline) {

            AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(
                    this);

            // set title
            // alertDialogBuilder.setTitle("Info");

            // set progressDialog message
            alertDialogBuilder
                    .setMessage("You have internet connection, switching to online mode.")
                    .setCancelable(false)
                    .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int id) {
                            ((GlobalVariables)getApplicationContext()).setShowingOnlineOfflineDialog(false);

                            // if this button is clicked, close
                            // current activity
                            dialog.dismiss();
                            Intent i = new Intent(getApplicationContext(), SplashScreen.class);
                            i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);
                            startActivity(i);
                            finish();
                        }
                    });


            // create alert progressDialog
            AlertDialog alertDialog = alertDialogBuilder.create();

            // show it
            alertDialog.show();
        } else {
            AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(
                    this);

            // set title
            // alertDialogBuilder.setTitle("Info");

            // set progressDialog message
            alertDialogBuilder
                    .setMessage("You have no internet, switching to offline mode.")
                    .setCancelable(false)
                    .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int id) {
                            ((GlobalVariables)getApplicationContext()).setShowingOnlineOfflineDialog(false);
                            // if this button is clicked, close
                            // current activity
                            dialog.dismiss();
                            Intent i = new Intent(getApplicationContext(), SplashScreen.class);
                            i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);
                            startActivity(i);
                            finish();
                        }
                    });


            // create alert progressDialog
            AlertDialog alertDialog = alertDialogBuilder.create();

            // show it
            alertDialog.show();
        }

    }
}