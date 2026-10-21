package com.example.geo_business;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.api_requests.LoginApiRequest;
import com.example.config.ApiConfig;
import com.example.models.User;
import com.example.shared_data.TokenData;
import com.example.shared_data.UserData;

import org.json.JSONException;
import org.json.JSONObject;

public class Login extends AppCompatActivity {
    private static final String TAG = "LoginActivity";
    EditText username, password;
    Button login;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        username = (EditText) findViewById(R.id.login_et_username);
        password = (EditText) findViewById(R.id.login_et_password);

        login = (Button) findViewById(R.id.login_bt_login);

        login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                loginFunc();
            }
        });
    }

    public void loginFunc() {
        if (!TextUtils.isEmpty(username.getText().toString()) && !TextUtils.isEmpty(password.getText().toString())) {

            // create JSON Object with username and password
            JSONObject jsonParams = new JSONObject();
            try {
                jsonParams.put("username", username.getText().toString());
                jsonParams.put("password", password.getText().toString());
            } catch (JSONException e) {
                e.printStackTrace();
            }

            // API request
            String apiUrl = ApiConfig.BASE_API_URL + "/auth/login";
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
                            Toast.makeText(Login.this, "Username or password incorrect!", Toast.LENGTH_SHORT).show();
                        } else {
                            // Login successfully
                            String role = jsonResponse.getJSONObject("user").getString("role");

                            if (!"accountant".equals(role)) {
                                // get "accessToken" and "refreshToken"
                                String accessToken = jsonResponse.getString("accessToken");
                                String refreshToken = jsonResponse.getString("refreshToken");

                                String[] tokens = {accessToken, refreshToken};

                                TokenData.getInstance().setSharedData(tokens);

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

                                Toast.makeText(Login.this, "Welcome "+user.getName()+" "+user.getSurname(), Toast.LENGTH_SHORT).show();
                                UserData.getInstance().setSharedData(user);

                                Intent intent = new Intent(getApplicationContext(), Menu.class);
                                startActivity(intent);
                            } else {
                                Toast.makeText(Login.this, "Accountants cannot log in to the Employees' Mobile App!", Toast.LENGTH_SHORT).show();
                            }
                        }
                    } catch (JSONException e) {
                        e.printStackTrace();
                        Log.e(TAG, "JSON Parsing Error: " + e.getMessage());
                        Toast.makeText(Login.this, "Username or password incorrect!", Toast.LENGTH_SHORT).show();
                    }
                }
            });
            loginApiRequest.execute(apiUrl, jsonParams.toString(), "POST");
        } else {
            Toast.makeText(Login.this, "Form entries cannot be blank!", Toast.LENGTH_SHORT).show();
        }
    }
}