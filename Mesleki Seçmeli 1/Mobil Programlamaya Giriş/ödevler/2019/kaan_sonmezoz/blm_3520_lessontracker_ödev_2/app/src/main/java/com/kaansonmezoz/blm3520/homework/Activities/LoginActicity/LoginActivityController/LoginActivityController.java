package com.kaansonmezoz.blm3520.homework.Activities.LoginActicity.LoginActivityController;


import android.content.Intent;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.kaansonmezoz.blm3520.homework.Activities.LoginActicity.LoginActivity;
import com.kaansonmezoz.blm3520.homework.Activities.LoginActicity.LoginActivityView.LoginActivityView;
import com.kaansonmezoz.blm3520.homework.Activities.MainActivity.MainActivity;
import com.kaansonmezoz.blm3520.homework.R;

public class LoginActivityController {
    private LoginActivity activity;
    private LoginActivityView activityView;

    public LoginActivityController(LoginActivity activity){
        this.activity = activity;
    }

    public void attachViews(){
        activityView = new LoginActivityView();

        activityView.setEmail((EditText)activity.findViewById(R.id.login_email));
        activityView.setPassword((EditText) activity.findViewById(R.id.login_password));
        activityView.setSigIn((Button) activity.findViewById(R.id.login_button));

    }

    public void attachEventListeners(){
        if(activityView == null){
            attachViews();
        }


        activityView.getSigIn().setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                if(checkCredentials()){
                    Intent intent = new Intent(activity, MainActivity.class);
                    activity.startActivity(intent);
                }
                else{
                    Toast.makeText(activity, "Wrong email or password !", Toast.LENGTH_LONG).show();
                }
            }
        });
    }

    private boolean checkCredentials(){
        return activityView.getPassword().getText().toString().equals("password") &&
                activityView.getEmail().getText().toString().equals("admin");
    }
}
