package com.kaansonmezoz.blm3520.homework.StorageOperations;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.drawable.BitmapDrawable;

import com.kaansonmezoz.blm3520.homework.Activities.MainActivity.Model.FormEntity;
import com.kaansonmezoz.blm3520.homework.R;

import java.io.IOException;

public class StorageOperations {
    public void saveForm(FormEntity form, Context context) throws IOException {
        String fileName = context.getResources().getString(R.string.PROFILE_PHOTO_NAME);

        SharedPreferencesHelper sharedPreferencesHelper = new SharedPreferencesHelper();
        sharedPreferencesHelper.saveForm(form, context);

        Bitmap image = ((BitmapDrawable)form.getImage()).getBitmap();

        InternalStorageOperations internalOperations = new InternalStorageOperations();
        internalOperations.saveImageFile(fileName, image, context);
    }

    public FormEntity loadForm(Context context) throws IOException{
        String fileName = context.getResources().getString(R.string.PROFILE_PHOTO_NAME);

        SharedPreferencesHelper helper = new SharedPreferencesHelper();
        FormEntity form = helper.getForm(context);

        InternalStorageOperations internalOpertions = new InternalStorageOperations();
        Bitmap imageBitmap = internalOpertions.loadImageFile(fileName, context);

        if(imageBitmap != null){
            form.setImage(new BitmapDrawable(context.getResources(), imageBitmap));
        }
        else{
            form.setImage(null);
        }

        return form;
    }
}
