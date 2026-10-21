package com.kaansonmezoz.blm3520.homework.Activities.MainActivity;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v4.view.GravityCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MenuItem;

import com.kaansonmezoz.blm3520.homework.Activities.MainActivity.Controller.MainActivityController;
import com.kaansonmezoz.blm3520.homework.Factory.ActionIntentFactory;
import com.kaansonmezoz.blm3520.homework.R;
import com.kaansonmezoz.blm3520.homework.Settings.RequestSettings;

import java.io.IOException;
import java.io.InputStream;

public class MainActivity extends AppCompatActivity  {
    private MainActivityController controller;
    //TODO: landscape degisiklikleri ile ilgili islemler de burada yer almali
    //TODO: landscape degisiklikleri onemli oralarda kaydetme islemleri yapilmali


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        controller = new MainActivityController(this);
        controller.attachViews();
        controller.attachEventListeners();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data){
        RequestSettings settings = new RequestSettings();

        if(requestCode == settings.getRequestCodeFor("CAMERA")){
            if(resultCode == RESULT_OK){
                Bitmap image = (Bitmap) data.getExtras().get("data");
                controller.addImage(image);
            }
        }
        else if(requestCode == settings.getRequestCodeFor("ALBUM")){
            if(resultCode == RESULT_OK){
                try{
                    InputStream inputStream = getContentResolver().openInputStream(data.getData());
                    Bitmap image = BitmapFactory.decodeStream(inputStream);
                    inputStream.close();
                    controller.addImage(image);
                }catch(IOException exception){
                    exception.printStackTrace();
                }
            }
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults){
        RequestSettings settings = new RequestSettings();

        if(requestCode == settings.getRequestCodeFor("CAMERA")){
            if(grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED){
                Intent intent = new ActionIntentFactory().createIntent(requestCode);
                startActivityForResult(intent, requestCode);
            }
        }
        else if(requestCode == settings.getRequestCodeFor("ALBUM")){
            if(grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED){
                Intent intent = new ActionIntentFactory().createIntent(requestCode);
                startActivityForResult(intent, requestCode);
            }
        }
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case android.R.id.home:
                controller.getActivityView().getDrawerLayout().openDrawer(GravityCompat.START);
                return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
