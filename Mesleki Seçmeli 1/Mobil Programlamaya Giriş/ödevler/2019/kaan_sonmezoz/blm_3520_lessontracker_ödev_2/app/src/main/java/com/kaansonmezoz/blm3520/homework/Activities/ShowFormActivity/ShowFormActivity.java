package com.kaansonmezoz.blm3520.homework.Activities.ShowFormActivity;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.kaansonmezoz.blm3520.homework.Activities.ShowFormActivity.Controller.ShowFormActivityController;
import com.kaansonmezoz.blm3520.homework.Factory.ActionIntentFactory;
import com.kaansonmezoz.blm3520.homework.R;
import com.kaansonmezoz.blm3520.homework.Settings.RequestSettings;

public class ShowFormActivity extends AppCompatActivity {
    private ShowFormActivityController controller;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_show_form);

        controller = new ShowFormActivityController(ShowFormActivity.this);
        controller.attachViews();
        controller.attachEventListeners();
        controller.setViewDatas();
    }


    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults){
        RequestSettings settings = new RequestSettings();

        if(requestCode == settings.getRequestCodeFor("PHONE_CALL"))
            if(grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED){
                String intentData = controller.getActivityView().getPhoneNumber()
                        .getText().toString();
                Intent intent = new ActionIntentFactory().createIntent(requestCode, intentData);
                startActivity(intent);
            }
    }

}
