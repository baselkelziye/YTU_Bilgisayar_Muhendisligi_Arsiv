package com.kaansonmezoz.blm3520.homework.StorageOperations;

import android.content.Context;
import android.content.SharedPreferences;
import android.content.res.Resources;

import com.kaansonmezoz.blm3520.homework.Activities.MainActivity.Model.FormEntity;
import com.kaansonmezoz.blm3520.homework.R;


public class SharedPreferencesHelper {
    public SharedPreferencesHelper() {}

    public void saveForm(FormEntity form, Context context) {
        String value;
        String key;

        SharedPreferences sharedPreferences = context.getSharedPreferences("FORM_PREFERENCES", Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sharedPreferences.edit();

        key = context.getResources().getString(R.string.PARAM_FORM_BIRTH_DATE);
        value = form.getBirthDate();
        editor.putString(key, value);

        key = context.getResources().getString(R.string.PARAM_FORM_BIRTH_PLACE);
        value = form.getBirthPlace();
        editor.putString(key, value);

        key = context.getResources().getString(R.string.PARAM_FORM_ID_NO);
        value = form.getIdNo();
        editor.putString(key, value);

        key = context.getResources().getString(R.string.PARAM_FORM_NAME);
        value = form.getName();
        editor.putString(key, value);

        key = context.getResources().getString(R.string.PARAM_FORM_SURNAME);
        value = form.getSurname();
        editor.putString(key, value);

        key = context.getResources().getString(R.string.PARAM_FORM_PHONE_NUMBER);
        value = form.getPhoneNumber();
        editor.putString(key, value);

        key = context.getResources().getString(R.string.PARAM_FORM_IMAGE_PATH);
        value = form.getImagePath();
        editor.putString(key, value);

        key = context.getResources().getString(R.string.PARAM_FORM_EMAIL_ADDRESS);
        value = form.getEmail();
        editor.putString(key, value);

        editor.commit();
    }


    public FormEntity getForm(Context context){
        FormEntity entity = new FormEntity();
        Resources resources = context.getResources();
        SharedPreferences sharedPreferences = context.getSharedPreferences("FORM_PREFERENCES", Context.MODE_PRIVATE);

        entity.setBirthPlace(sharedPreferences.getString(resources.getString(R.string.PARAM_FORM_BIRTH_PLACE), null));
        entity.setBirthDate(sharedPreferences.getString(resources.getString(R.string.PARAM_FORM_BIRTH_DATE), null));
        entity.setIdNo(sharedPreferences.getString(resources.getString(R.string.PARAM_FORM_ID_NO), null));
        entity.setName(sharedPreferences.getString(resources.getString(R.string.PARAM_FORM_NAME), null));
        entity.setSurname(sharedPreferences.getString(resources.getString(R.string.PARAM_FORM_SURNAME), null));
        entity.setImagePath(sharedPreferences.getString(resources.getString(R.string.PARAM_FORM_IMAGE_PATH), null));
        entity.setPhoneNumber(sharedPreferences.getString(resources.getString(R.string.PARAM_FORM_PHONE_NUMBER), null));
        entity.setEmail(sharedPreferences.getString(resources.getString(R.string.PARAM_FORM_EMAIL_ADDRESS), null));

        return entity;
    }
}

