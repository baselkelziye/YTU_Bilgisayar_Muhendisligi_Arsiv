package com.example.geo_business;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.example.api_requests.LoginApiRequest;
import com.example.config.ApiConfig;
import com.example.models.User;

import org.json.JSONException;
import org.json.JSONObject;

public class Register extends AppCompatActivity {
    private static final String TAG = "RegisterActivity";
    EditText name, surname, username, email, password, repassword;
    Button register, cancel;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        name = (EditText) findViewById(R.id.register_et_name);
        surname = (EditText) findViewById(R.id.register_et_surname);
        username = (EditText) findViewById(R.id.register_et_username);
        email = (EditText) findViewById(R.id.register_et_email);
        password = (EditText) findViewById(R.id.register_et_password);
        repassword = (EditText) findViewById(R.id.register_et_repassword);

        register = (Button) findViewById(R.id.register_bt_register);
        cancel = (Button) findViewById(R.id.register_bt_cancel);

        register.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                registerFunc();
            }
        });

        cancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(Register.this, "LOGIN SAYFA", Toast.LENGTH_SHORT).show();
            }
        });
    }

    public void registerFunc() {
        if (!TextUtils.isEmpty(name.getText().toString()) && !TextUtils.isEmpty(surname.getText().toString())
                && !TextUtils.isEmpty(username.getText().toString()) && !TextUtils.isEmpty(email.getText().toString())
                && !TextUtils.isEmpty(password.getText().toString()) && !TextUtils.isEmpty(repassword.getText().toString())) {

            if (password.getText().toString().equals(repassword.getText().toString())) {

                // create JSON Object
                JSONObject jsonParams = new JSONObject();
                try {
                    jsonParams.put("name", name.getText().toString());
                    jsonParams.put("surname", surname.getText().toString());
                    jsonParams.put("username", username.getText().toString());
                    jsonParams.put("email", email.getText().toString());
                    jsonParams.put("password", password.getText().toString());
                    jsonParams.put("role", "employee");
                } catch (JSONException e) {
                    e.printStackTrace();
                }

                // API request
                String apiUrl = ApiConfig.BASE_API_URL + "/auth/register";
                LoginApiRequest loginApiRequest = new LoginApiRequest(new LoginApiRequest.ApiCallback() {
                    @Override
                    public void onTaskComplete(String result) {

                        Log.d(TAG, "API Response: " + result);

                        try {
                            // Transform JSON response to JSON Object
                            JSONObject jsonResponse = new JSONObject(result);

                            // validations
                            if (jsonResponse.has("error")) {
                                // Login error
                                Toast.makeText(Register.this, "Username or password incorrect!", Toast.LENGTH_SHORT).show();
                            } else {
                                // Login successfully
                                String role = jsonResponse.getJSONObject("user").getString("role");

                                if (!"accountant".equals(role)) {
                                    // get "accessToken" and "refreshToken"
                                    String accessToken = jsonResponse.getString("accessToken");
                                    String refreshToken = jsonResponse.getString("refreshToken");

                                    // get "user" object
                                    JSONObject userObject = jsonResponse.getJSONObject("user");

                                    // create User object
                                    User user = new User(
                                            userObject.getString("_id"),
                                            userObject.getString("username"),
                                            userObject.getString("name"),
                                            userObject.getString("surname"),
                                            userObject.getString("email"),
                                            userObject.getString("role")
                                    );

                                    Toast.makeText(Register.this, "Welcome "+user.getName()+" "+user.getSurname(), Toast.LENGTH_SHORT).show();

                                    Intent intent = new Intent(getApplicationContext(), Login.class);
                                    startActivity(intent);
                                } else {
                                    Toast.makeText(Register.this, "Accountants cannot log in to the Employees' Mobile App!", Toast.LENGTH_SHORT).show();
                                }
                            }
                        } catch (JSONException e) {
                            e.printStackTrace();
                            Log.e(TAG, "JSON Parsing Error: " + e.getMessage());
                            Toast.makeText(Register.this, "Error!", Toast.LENGTH_SHORT).show();
                        }
                    }
                });
                loginApiRequest.execute(apiUrl, jsonParams.toString(), "POST");
            }
            else {
                Toast.makeText(Register.this, "Şifreler uyuşmuyor!", Toast.LENGTH_SHORT).show();
            }

        } else {
            Toast.makeText(Register.this, "Form entries cannot be blank!", Toast.LENGTH_SHORT).show();
        }
    }
}
