package tr.com.berkaytutal.beslenmedanismani;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.AsyncTask;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import org.json.JSONException;
import org.json.JSONObject;

import tr.com.berkaytutal.beslenmedanismani.Utils.BaseDrawerActivity;
import tr.com.berkaytutal.beslenmedanismani.Utils.DataSenderHelper;
import tr.com.berkaytutal.beslenmedanismani.Utils.FourDigitCardFormatWatcher;
import tr.com.berkaytutal.beslenmedanismani.Utils.FunctionUtils;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.PublicVariables;

public class AddMoneyActivity extends BaseDrawerActivity {

    private EditText cardNumber;
    private EditText cardOwner;
    private EditText expMM;
    private EditText expYY;
    private EditText cvv2;
    private EditText amountEditText;
    private Button payNowButton;
    private Activity activity;
    private int money;

    private ProgressDialog progressDialog;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_money);
        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);

        this.activity = this;

        cardNumber = (EditText) findViewById(R.id.cardNumber);
        cardOwner = (EditText) findViewById(R.id.cardOwner);
        expMM = (EditText) findViewById(R.id.expMM);
        expYY = (EditText) findViewById(R.id.expYY);
        cvv2 = (EditText) findViewById(R.id.cvv2);
        amountEditText = (EditText) findViewById(R.id.amount);
        payNowButton = (Button) findViewById(R.id.payNow);


        cardNumber.addTextChangedListener(new FourDigitCardFormatWatcher());

        payNowButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {


                if (FunctionUtils.checkEmpty(cardNumber) && FunctionUtils.checkEmpty(cardOwner) && FunctionUtils.checkEmpty(expMM) && FunctionUtils.checkEmpty(expYY) && FunctionUtils.checkEmpty(amountEditText) && FunctionUtils.checkEmpty(cvv2)) {
                    AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(
                            activity);

                    // set title
                    // alertDialogBuilder.setTitle("Info");

                    // set progressDialog message
                    alertDialogBuilder
                            .setTitle("Pay Now")
                            .setMessage("Do you want to pay and add " + amountEditText.getText().toString() + " TL ?")
                            .setCancelable(false)
                            .setNegativeButton("NO", new DialogInterface.OnClickListener() {
                                @Override
                                public void onClick(DialogInterface dialogInterface, int i) {
                                    dialogInterface.dismiss();
                                }
                            })
                            .setPositiveButton("YES", new DialogInterface.OnClickListener() {
                                public void onClick(DialogInterface dialog, int id) {


                                    progressDialog = ProgressDialog.show(activity, "",
                                            "Loading...", true);
                                    JSONObject jsonObject = new JSONObject();
                                    try {
                                        money = Integer.valueOf(amountEditText.getText().toString());
                                        jsonObject.accumulate("money", amountEditText.getText().toString());
                                        jsonObject.accumulate("user_ID", ((GlobalVariables) getApplicationContext()).getUserDataPOJO().getUser_ID());
                                    } catch (JSONException e) {
                                        e.printStackTrace();
                                    }

                                    MoneyAsync async = new MoneyAsync();
                                    async.execute(jsonObject);

                                    dialog.dismiss();
                                }
                            });


                    // create alert progressDialog
                    AlertDialog alertDialog = alertDialogBuilder.create();

                    // show it
                    alertDialog.show();
                }
            }
        });

    }

    private class MoneyAsync extends AsyncTask<JSONObject, String, String> {


        @Override
        protected String doInBackground(JSONObject... jsonObjects) {

            return DataSenderHelper.POST(PublicVariables.addMoneyURL, jsonObjects[0]);

        }

        @Override
        protected void onPostExecute(String s) {
            super.onPostExecute(s);

            if (s != null) {
                if (!"false".equals(s)) {
                    ((GlobalVariables) getApplicationContext()).getUserDataPOJO().setMoney(((GlobalVariables) getApplicationContext()).getUserDataPOJO().getMoney() + money);
                    progressDialog.dismiss();


                    AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(
                            activity);

                    // set title
                    // alertDialogBuilder.setTitle("Info");

                    // set progressDialog message
                    alertDialogBuilder
                            .setTitle("Success!")
                            .setMessage("Total money: " + ((GlobalVariables) getApplicationContext()).getUserDataPOJO().getMoney() + " TL")
                            .setCancelable(false)

                            .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                                public void onClick(DialogInterface dialog, int id) {
                                    dialog.dismiss();
                                }
                            });


                    // create alert progressDialog
                    AlertDialog alertDialog = alertDialogBuilder.create();

                    // show it
                    alertDialog.show();


                } else {
                    progressDialog.dismiss();
                    AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(
                            activity);

                    // set title
                    // alertDialogBuilder.setTitle("Info");

                    // set progressDialog message
                    alertDialogBuilder
                            .setTitle("Error!")
                            .setMessage("An error occured, please try again")
                            .setCancelable(false)

                            .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                                public void onClick(DialogInterface dialog, int id) {
                                    dialog.dismiss();
                                }
                            });


                    // create alert progressDialog
                    AlertDialog alertDialog = alertDialogBuilder.create();

                    // show it
                    alertDialog.show();
                }
            } else {
                progressDialog.dismiss();
                AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(
                        activity);

                // set title
                // alertDialogBuilder.setTitle("Info");

                // set progressDialog message
                alertDialogBuilder
                        .setTitle("Error!")
                        .setMessage("An error occured, please try again")
                        .setCancelable(false)

                        .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int id) {
                                dialog.dismiss();
                            }
                        });


                // create alert progressDialog
                AlertDialog alertDialog = alertDialogBuilder.create();

                // show it
                alertDialog.show();
            }
        }
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
    }
}
