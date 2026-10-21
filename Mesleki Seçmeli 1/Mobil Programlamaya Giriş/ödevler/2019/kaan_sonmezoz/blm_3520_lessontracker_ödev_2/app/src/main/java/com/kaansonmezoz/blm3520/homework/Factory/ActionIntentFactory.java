package com.kaansonmezoz.blm3520.homework.Factory;

import android.content.Intent;
import android.net.Uri;
import android.provider.MediaStore;
import android.util.Log;

import com.kaansonmezoz.blm3520.homework.Settings.RequestSettings;

public class ActionIntentFactory {
    public Intent createIntent(int intentCode){
        RequestSettings settings = new RequestSettings();
        Intent intent = null;

        if(intentCode == settings.getRequestCodeFor("CAMERA")){
            intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        }
        else if(intentCode == settings.getRequestCodeFor("ALBUM")){
            intent = new Intent();
            intent.setType("image/*");
            intent.setAction(Intent.ACTION_GET_CONTENT);
            intent = Intent.createChooser(intent, "Select Picture");
        }

        return intent;
    }

    public Intent createIntent(int intentCode, String intentData){
        RequestSettings settings = new RequestSettings();
        Intent intent = null;

        if(intentCode == settings.getRequestCodeFor("PHONE_CALL")){
            intent = new Intent(Intent.ACTION_CALL);
            intent.setData(Uri.parse("tel:" + intentData));
        }
        else if(intentCode == settings.getRequestCodeFor("SEND_EMAIL")){
            intent = new Intent(Intent.ACTION_SENDTO);
            intent.setData(Uri.parse("mailto:" + intentData));
            intent = Intent.createChooser(intent, "Send mail...");
        }

        return intent;
    }
}
