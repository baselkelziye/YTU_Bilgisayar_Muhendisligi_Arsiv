package com.kaansonmezoz.blm3520.homework.Manager;

import android.app.Activity;

import android.content.pm.PackageManager;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.util.Log;

import com.kaansonmezoz.blm3520.homework.Settings.PermissionSettings;
import com.kaansonmezoz.blm3520.homework.Settings.RequestSettings;

public class PermissionManager {
    public PermissionManager(){}

    public boolean requestPermissionFor(Activity activity, String askedPermissionFor){
        PermissionSettings permissionSettings = new PermissionSettings();
        String permissionString = permissionSettings.getPermissionStringFor(askedPermissionFor);

        RequestSettings requestSettings = new RequestSettings();
        int requestCode = requestSettings.getRequestCodeFor(askedPermissionFor);

        if(permissionString == null || requestCode == 0){
            Log.d("PermissionManager", "Camera ile ilgili deger bulunamadi");
            return false;
        }
        else if (ContextCompat.checkSelfPermission(activity, permissionString) == PackageManager.PERMISSION_DENIED){
            Log.d("PermissionManager", "İzin istendi");
            ActivityCompat.requestPermissions(activity, new String[]{permissionString}, requestCode);

            return false;
        }
        else{
            return true;
        }
    }
}
