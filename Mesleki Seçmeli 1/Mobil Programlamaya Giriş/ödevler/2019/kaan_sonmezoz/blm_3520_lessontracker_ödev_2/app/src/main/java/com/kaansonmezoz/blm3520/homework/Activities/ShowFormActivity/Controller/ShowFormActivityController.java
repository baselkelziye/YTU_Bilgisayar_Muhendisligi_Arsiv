package com.kaansonmezoz.blm3520.homework.Activities.ShowFormActivity.Controller;

import android.content.Intent;
import android.support.v4.view.ViewCompat;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;

import com.kaansonmezoz.blm3520.homework.Activities.MainActivity.Model.FormEntity;
import com.kaansonmezoz.blm3520.homework.Activities.ShowFormActivity.ShowFormActivity;
import com.kaansonmezoz.blm3520.homework.Activities.ShowFormActivity.View.ShowFormActivityView;
import com.kaansonmezoz.blm3520.homework.Factory.ActionIntentFactory;
import com.kaansonmezoz.blm3520.homework.Interface.ControllerInterface;
import com.kaansonmezoz.blm3520.homework.Manager.PermissionManager;
import com.kaansonmezoz.blm3520.homework.R;
import com.kaansonmezoz.blm3520.homework.Settings.RequestSettings;
import com.kaansonmezoz.blm3520.homework.StorageOperations.StorageOperations;

import java.io.IOException;


public class ShowFormActivityController implements ControllerInterface {
    private ShowFormActivity activity;
    private ShowFormActivityView activityView;

    public ShowFormActivityController(ShowFormActivity activity){
        this.activity = activity;
    }

    public ShowFormActivityView getActivityView(){
        return activityView;
    }

    public void attachViews(){
        activityView = new ShowFormActivityView();

        activityView.setBirthDate((EditText) activity.findViewById(R.id.birthDate));
        activityView.setBirthPlace((EditText) activity.findViewById(R.id.birthPlace));
        activityView.setIdNumber((EditText) activity.findViewById(R.id.idNumber));
        activityView.setName((EditText) activity.findViewById(R.id.name));
        activityView.setPhoneNumber((EditText) activity.findViewById(R.id.phoneNumber));
        activityView.setSurname((EditText) activity.findViewById(R.id.surname));
        activityView.setProfilePhoto((ImageView) activity.findViewById(R.id.profilePhoto));
        activityView.setPhoneCallImage(activity.findViewById(R.id.phoneCall));
        activityView.setEmailAddress((EditText) activity.findViewById(R.id.email_address));
        activityView.setSendEmail((ImageView) activity.findViewById(R.id.email_send));
    }

    public void attachEventListeners(){
        if(activityView == null){
            attachViews();
        }

        //TODO: geri donmek icin bir buton bun attach edilmeli
        addPhoneImageClickListener();
        addEmailImageClickListener();
    }

    public void setViewDatas(){
        if(activityView == null){
            attachViews();
        }

        StorageOperations storageOperations = new StorageOperations();
        FormEntity form = null;

        try{
            form = storageOperations.loadForm(activity);
        }catch(IOException exception){
            Log.d("Exception", exception.getMessage());
            Log.d("Exception", Log.getStackTraceString(exception));
        }

        if(form == null){
            return;
        }

        ViewCompat.setBackground(activityView.getProfilePhoto(), form.getImage());

        activityView.getName().setText(form.getName());
        activityView.getSurname().setText(form.getSurname());
        activityView.getIdNumber().setText(form.getIdNo());
        activityView.getBirthDate().setText(form.getBirthDate());
        activityView.getBirthPlace().setText(form.getBirthPlace());
        activityView.getPhoneNumber().setText(form.getPhoneNumber());
        activityView.getEmailAddress().setText(form.getEmail());
    }

    private void addPhoneImageClickListener(){
        activityView.getPhoneCallImage().setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view){
                PermissionManager manager = new PermissionManager();

                if(manager.requestPermissionFor(activity, "PHONE_CALL")){
                    int intentCode = new RequestSettings().getRequestCodeFor("PHONE_CALL");
                    Intent intent = new ActionIntentFactory().createIntent(intentCode, activityView.getPhoneNumber().getText().toString());

                    activity.startActivity(intent);
                }
            }
        });
    }

    private void addEmailImageClickListener(){
        activityView.getSendEmail().setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view){
                int intentCode = new RequestSettings().getRequestCodeFor("SEND_EMAIL");
                Intent intent = new ActionIntentFactory().createIntent(intentCode, activityView.getEmailAddress().getText().toString());

                if(intent == null){
                    Log.d("Email", "intent nul geldi");
                }
                else{
                    activity.startActivity(intent);
                }
            }
        });
    }
}
