package com.kaansonmezoz.blm3520.homework.Activities.MainActivity.Controller;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.drawable.BitmapDrawable;
import android.support.design.widget.NavigationView;
import android.support.v7.app.ActionBar;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.MenuItem;
import android.view.View;

import com.kaansonmezoz.blm3520.homework.Activities.MainActivity.Dialog.AddPhotoDialog;
import com.kaansonmezoz.blm3520.homework.Activities.MainActivity.Dialog.BirthdateDialog;
import com.kaansonmezoz.blm3520.homework.Activities.MainActivity.MainActivity;
import com.kaansonmezoz.blm3520.homework.Activities.ShowFormActivity.ShowFormActivity;
import com.kaansonmezoz.blm3520.homework.Activities.MainActivity.Model.FormEntity;
import com.kaansonmezoz.blm3520.homework.Activities.ShowLessonsActivity.ShowLessonsActivity;
import com.kaansonmezoz.blm3520.homework.Interface.ControllerInterface;
import com.kaansonmezoz.blm3520.homework.R;
import com.kaansonmezoz.blm3520.homework.Activities.MainActivity.View.MainActivityView;
import com.kaansonmezoz.blm3520.homework.StorageOperations.StorageOperations;

import java.io.IOException;

public class MainActivityController implements ControllerInterface {
    private MainActivityView activityView;
    private MainActivity activity;

    public MainActivityController(MainActivity activity){
        this.activity = activity;
    }

    public MainActivityView getActivityView(){
        return activityView;
    }

    public void attachViews(){
        activityView = new MainActivityView();

        activityView.setAddImageView(activity.findViewById(R.id.addImage));
        activityView.setNameText(activity.findViewById(R.id.name));
        activityView.setSurnameText(activity.findViewById(R.id.surname));
        activityView.setIdText(activity.findViewById(R.id.idNumber));
        activityView.setBirthPlaceText(activity.findViewById(R.id.birthPlace));
        activityView.setBirthDateText(activity.findViewById(R.id.birthDate));
        activityView.setClearAllButton(activity.findViewById(R.id.clearButton));
        activityView.setSubmitButton(activity.findViewById(R.id.submitButton));
        activityView.setPhoneNumberText(activity.findViewById(R.id.phoneNumber));
        activityView.setNavigationView(activity.findViewById(R.id.nav_view));
        activityView.setDrawerLayout(activity.findViewById(R.id.drawer_layout));
        activityView.setEmailAddress(activity.findViewById(R.id.emailAddress));

        Toolbar toolbar = activity.findViewById(R.id.toolbar);
        activity.setSupportActionBar(toolbar);
        ActionBar actionbar = activity.getSupportActionBar();
        actionbar.setDisplayHomeAsUpEnabled(true);
        actionbar.setHomeAsUpIndicator(R.drawable.ic_menu_black_24dp);

        setInitialViewValues();
    }

    public void attachEventListeners(){
        if(activityView == null){
            attachViews();
        }

        addSubmitButtonListener();
        addClearAllButtonListener();
        addImageClickListener();
        addDatePicker();
        addNavigationClickEvents();
    }

    private void addSubmitButtonListener(){
        activityView.getSubmitButton().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                FormEntity form = new FormEntity();

                form.setBirthDate(activityView.getBirthDateText().getText().toString());
                form.setBirthPlace(activityView.getBirthPlaceText().getText().toString());
                form.setIdNo(activityView.getIdText().getText().toString());
                form.setName(activityView.getNameText().getText().toString());
                form.setSurname(activityView.getSurnameText().getText().toString());
                form.setPhoneNumber(activityView.getPhoneNumberText().getText().toString());
                form.setImage(activityView.getAddImageView().getBackground());
                form.setEmail(activityView.getEmailAddress().getText().toString());

                try{
                    StorageOperations storageOperations = new StorageOperations();
                    storageOperations.saveForm(form, activity.getApplicationContext());
                }catch(IOException exception){
                    Log.d("Exception", exception.getMessage());
                    Log.d("Exception", Log.getStackTraceString(exception));
                }

                Intent intent = new Intent(activity, ShowFormActivity.class);
                activity.startActivity(intent);
            }
        });
    }

    private void addClearAllButtonListener(){
        activityView.getClearAllButton().setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view){
                activityView.getAddImageView().setBackgroundResource(R.drawable.add_your_image);
                activityView.getBirthDateText().setText("");
                activityView.getBirthPlaceText().setText("");
                activityView.getIdText().setText("");
                activityView.getNameText().setText("");
                activityView.getSurnameText().setText("");
                activityView.getPhoneNumberText().setText("");
                activityView.getEmailAddress().setText("");
            }
        });
    }

    private void addImageClickListener(){
        activityView.getAddImageView().setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view){
                AddPhotoDialog photoDialog = new AddPhotoDialog();
                photoDialog.createDialog(activity).show();
            }
        });
    }

    public void addImage(Bitmap image){
        activityView.getAddImageView().setBackgroundDrawable(new BitmapDrawable(image));
    }

    private void addDatePicker(){
        BirthdateDialog birthdateDialog = new BirthdateDialog();
        birthdateDialog.createDatePicker(activity, activityView.getBirthDateText());
    }

    private void addNavigationClickEvents(){
        activityView.getNavigationView().setNavigationItemSelectedListener(
                new NavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(MenuItem menuItem) {
                menuItem.setCheckable(true);
                activityView.getDrawerLayout().closeDrawers();

                if(menuItem.getTitle().toString().equals(activity.getResources().getString(R.string.navbar_lessons))){
                    Intent intent = new Intent(activity, ShowLessonsActivity.class);
                    activity.startActivity(intent);
                }

                return true;
            }
        });

        activityView.getNavigationView().setCheckedItem(R.id.navbar_information);
    }

    private void setInitialViewValues(){
        StorageOperations operations = new StorageOperations();
        FormEntity form = null;

        try{
            form = operations.loadForm(activity);
        }catch(IOException exception){
            Log.d("Exception", exception.getMessage());
            Log.d("Exception", Log.getStackTraceString(exception));
        }

        if(form == null){
            return;
        }

        if(form.getBirthDate() != null){
            activityView.getBirthDateText().setText(form.getBirthDate());
        }

        if(form.getBirthPlace() != null){
            activityView.getBirthPlaceText().setText(form.getBirthPlace());
        }

        if(form.getIdNo() != null){
            activityView.getIdText().setText(form.getIdNo());
        }

        if(form.getImage() != null){
            activityView.getAddImageView().setBackgroundDrawable(form.getImage());
        }

        if(form.getName() != null){
            activityView.getNameText().setText(form.getName());
        }

        if(form.getSurname() != null){
            activityView.getSurnameText().setText(form.getSurname());
        }

        if(form.getPhoneNumber() != null){
            activityView.getPhoneNumberText().setText(form.getPhoneNumber());
        }

        Log.d("Email", form.getEmail());

        if(form.getEmail() !=  null){
            activityView.getEmailAddress().setText(form.getEmail());
        }

    }
}
