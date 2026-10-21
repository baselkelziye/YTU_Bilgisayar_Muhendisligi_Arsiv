package com.kaansonmezoz.blm3520.homework.Activities.MainActivity.Dialog;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;

import com.kaansonmezoz.blm3520.homework.Activities.MainActivity.MainActivity;
import com.kaansonmezoz.blm3520.homework.Factory.ActionIntentFactory;
import com.kaansonmezoz.blm3520.homework.Manager.PermissionManager;
import com.kaansonmezoz.blm3520.homework.R;
import com.kaansonmezoz.blm3520.homework.Settings.RequestSettings;

public class AddPhotoDialog {
    public AlertDialog createDialog(final MainActivity activity){
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);

        builder.setMessage(R.string.addPhotoDescription)
                .setPositiveButton(R.string.addPhotoExistingPhoto, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        PermissionManager manager = new PermissionManager();

                        if(manager.requestPermissionFor(activity, "ALBUM")){
                            RequestSettings requestSettings = new RequestSettings();
                            int requestCode = requestSettings.getRequestCodeFor("ALBUM");

                            Intent intent = new ActionIntentFactory().createIntent(requestCode);
                            activity.startActivityForResult(intent, requestCode);
                        }
                    }
                })
                .setNegativeButton(R.string.addPhotonNewPhoto, new DialogInterface.OnClickListener(){
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i){
                        PermissionManager manager = new PermissionManager();

                        if(manager.requestPermissionFor(activity, "CAMERA") == true){
                            RequestSettings requestSettings = new RequestSettings();
                            int requestCode = requestSettings.getRequestCodeFor("CAMERA");

                            Intent intent = new ActionIntentFactory().createIntent(requestCode);
                            activity.startActivityForResult(intent, requestCode);
                        }
                    }
                });
        return builder.create();
    }
}
