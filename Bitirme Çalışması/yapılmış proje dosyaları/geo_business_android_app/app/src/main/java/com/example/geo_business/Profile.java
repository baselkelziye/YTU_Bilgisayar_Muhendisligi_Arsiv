package com.example.geo_business;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.example.api_requests.LoginApiRequest;
import com.example.models.User;
import com.example.shared_data.UserData;

import org.json.JSONException;
import org.json.JSONObject;

public class Profile extends AppCompatActivity {
    private static final String TAG = "ProfileActivity";

    TextView name, surname, email, username, id, role;
    Button back;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_profile);

        name = (TextView) findViewById(R.id.profile_tv_name);
        surname = (TextView) findViewById(R.id.profile_tv_surname);
        email = (TextView) findViewById(R.id.profile_tv_email);
        username = (TextView) findViewById(R.id.profile_tv_username);
        id = (TextView) findViewById(R.id.profile_tv_id);
        role = (TextView) findViewById(R.id.profile_tv_role);

        back = (Button) findViewById(R.id.profile_bt_back);

        back.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Menu.class);
                startActivity(intent);
            }
        });
    }

    @Override
    protected void onStart() {
        super.onStart();
        viewUserInfo();
    }

    public void viewUserInfo() {
        User user = UserData.getInstance().getSharedData();

        name.setText(user.getName());
        surname.setText(user.getSurname());
        email.setText(user.getEmail());
        role.setText(user.getRole());
        id.setText(user.getUserId());
        username.setText(user.getUsername());
    }
}
