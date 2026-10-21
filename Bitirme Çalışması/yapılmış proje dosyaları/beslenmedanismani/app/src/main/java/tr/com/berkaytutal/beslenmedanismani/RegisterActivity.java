package tr.com.berkaytutal.beslenmedanismani;

import android.app.Activity;
import android.app.DatePickerDialog;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.AsyncTask;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.Toast;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.Calendar;

import tr.com.berkaytutal.beslenmedanismani.Utils.DataSenderHelper;
import tr.com.berkaytutal.beslenmedanismani.Utils.FunctionUtils;
import tr.com.berkaytutal.beslenmedanismani.Utils.PasswordHashingMD5;
import tr.com.berkaytutal.beslenmedanismani.Utils.PublicVariables;

public class RegisterActivity extends AppCompatActivity {

    private EditText nameEditText;
    private EditText surnameEditText;
    private EditText emailEditText;
    private EditText passwordEditText;
    private EditText passwordAgainEditText;
    private EditText birthdayEditText;
    private RadioButton maleRadioButton;
    private RadioButton femaleRadioButton;
    private Activity registerActivity;
    private ProgressDialog progressDialog;

    private AlertDialog alertDialog;
    private Button registerButton;

    private int yearM = -1;
    private int monthM = -1;
    private int dayM = -1;

    private JSONObject jsonObject;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);
        registerActivity = this;

        nameEditText = (EditText) findViewById(R.id.nameRegisterScreen);
        surnameEditText = (EditText) findViewById(R.id.surnameRegisterScreen);
        emailEditText = (EditText) findViewById(R.id.emailAddressRegisterScreen);
        passwordEditText = (EditText) findViewById(R.id.passwordRegisterScreen);
        passwordAgainEditText = (EditText) findViewById(R.id.passwordAgainRegisterScreen);
        birthdayEditText = (EditText) findViewById(R.id.birthdayEditTextRegisterScreen);
        registerButton = (Button) findViewById(R.id.registerButtonRegisterScreen);
        maleRadioButton = (RadioButton) findViewById(R.id.registerMaleRadioButton);
        femaleRadioButton = (RadioButton) findViewById(R.id.registerFemaleRadioButton);

        if (getIntent().hasExtra("email")) {
            emailEditText.setText(getIntent().getStringExtra("email").toString());
        }
        if (getIntent().hasExtra("password")) {
            passwordEditText.setText(getIntent().getStringExtra("password"));
        }

        maleRadioButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                maleRadioButton.setChecked(true);
                femaleRadioButton.setChecked(false);
            }
        });
        femaleRadioButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                maleRadioButton.setChecked(false);
                femaleRadioButton.setChecked(true);
            }
        });


        birthdayEditText.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Calendar mcurrentTime = Calendar.getInstance();
                if (yearM == -1 || monthM == -1 || dayM == -1) {
                    yearM = mcurrentTime.get(Calendar.YEAR);//Güncel Yılı alıyoruz
                    monthM = mcurrentTime.get(Calendar.MONTH);//Güncel Ayı alıyoruz
                    dayM = mcurrentTime.get(Calendar.DAY_OF_MONTH);//Güncel Günü alıyoruz
                }


                DatePickerDialog datePicker;//Datepicker objemiz
                datePicker = new DatePickerDialog(view.getContext(), new DatePickerDialog.OnDateSetListener() {

                    @Override
                    public void onDateSet(DatePicker view, int year, int monthOfYear,
                                          int dayOfMonth) {
                        birthdayEditText.setText(year + "-" + (monthOfYear + 1) + "-" + dayOfMonth);//Ayarla butonu tıklandığında textview'a yazdırıyoruz
                        dayM = dayOfMonth;
                        monthM = monthOfYear;
                        yearM = year;

                    }
                }, yearM, monthM, dayM);//başlarken set edilcek değerlerimizi atıyoruz
//                datePicker.setTitle("Tarih Seçiniz");
//                datePicker.setButton(DatePickerDialog.BUTTON_POSITIVE, "Ayarla", datePicker);
//                datePicker.setButton(DatePickerDialog.BUTTON_NEGATIVE, "İptal", datePicker);

                datePicker.getDatePicker().setMaxDate(mcurrentTime.getTimeInMillis());

                datePicker.show();
            }
        });

        registerButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (FunctionUtils.checkEmpty(nameEditText) && FunctionUtils.checkEmpty(surnameEditText) && FunctionUtils.checkEmpty(emailEditText) && FunctionUtils.checkEmpty(passwordEditText) && FunctionUtils.checkEmpty(passwordAgainEditText) && FunctionUtils.checkEmpty(birthdayEditText)) {
                    if (!passwordEditText.getText().toString().equals(passwordAgainEditText.getText().toString())) {

                        android.app.AlertDialog.Builder alertDialogBuilder = new android.app.AlertDialog.Builder(
                                registerActivity);

                        // set title
                        // alertDialogBuilder.setTitle(R.string.privateProfile);

                        // set progressDialog message
                        alertDialogBuilder
                                .setMessage(R.string.passwordsMustbeSame)
                                .setCancelable(true)
                                .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                                            public void onClick(DialogInterface dialog, int id) {
                                                dialog.dismiss();
                                            }
                                        }
                                );

                        // create alert progressDialog
                        android.app.AlertDialog alertDialog = alertDialogBuilder.create();

                        // show it
                        alertDialog.show();
                    } else {

                        progressDialog = ProgressDialog.show(registerActivity, "",
                                "Registering...", true);
                        JSONObject json = new JSONObject();
                        String sex = "M";
                        if (maleRadioButton.isChecked()) {
                            sex = "M";
                        } else if (femaleRadioButton.isChecked()) {
                            sex = "F";
                        }
                        try {
                            json.accumulate("birthday", yearM + "-" + (monthM + 1) + "-" + dayM);
                            json.accumulate("email", emailEditText.getText());
                            json.accumulate("name", nameEditText.getText());
                            json.accumulate("password", PasswordHashingMD5.md5(passwordEditText.getText().toString()));
                            json.accumulate("sex", sex);
                            json.accumulate("surname", surnameEditText.getText());


                        } catch (JSONException e) {
                            e.printStackTrace();
                        }
                        Log.i("register", json.toString());
                        jsonObject = json;
                        MyRegisterAsync registerAsync = new MyRegisterAsync();
                        registerAsync.execute("test");
                    }

                }

            }
        });
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
    }


    private class MyRegisterAsync extends AsyncTask<String, Void, String> {


        @Override
        protected String doInBackground(String... strings) {
            return DataSenderHelper.POST(PublicVariables.registerURL, jsonObject);

        }

        @Override
        protected void onPostExecute(String result) {
            if (result.equals("false")) {
                progressDialog.cancel();
                android.app.AlertDialog.Builder alertDialogBuilder = new android.app.AlertDialog.Builder(
                        registerActivity);

                // set title
                // alertDialogBuilder.setTitle(R.string.privateProfile);

                // set progressDialog message
                alertDialogBuilder
                        .setMessage("This email is already registered!")
                        .setCancelable(true)
                        .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                                    public void onClick(DialogInterface dialog, int id) {
                                        dialog.dismiss();
                                    }
                                }
                        );

                // create alert progressDialog
                android.app.AlertDialog alertDialog = alertDialogBuilder.create();

                // show it
                alertDialog.show();
            } else if (result.equals("true")) {

                SharedPreferences userDetails = getApplicationContext().getSharedPreferences("userdetails", MODE_PRIVATE);
                SharedPreferences.Editor edit = userDetails.edit();
                edit.clear();
                edit.putString("userEmail", emailEditText.getText().toString());
                edit.putString("userPass", passwordEditText.getText().toString());
                edit.commit();
                Toast.makeText(getApplicationContext(), "Login details are saved..", Toast.LENGTH_LONG).show();


                LoginActivity.loginActivity.finish();
                Intent i = new Intent(getApplicationContext(), LoginActivity.class);
                i.putExtra("isMainLogin", true);
                startActivity(i);

                finish();
            }
        }
    }
}
