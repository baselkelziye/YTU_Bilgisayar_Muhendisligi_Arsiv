package com.kaansonmezoz.blm3520.homework.Settings;


import android.Manifest;

public class PermissionSettings {
    public PermissionSettings(){}

    public String getPermissionStringFor(String permissionAskedFor){
        if(permissionAskedFor.equals("CAMERA")){
            return Manifest.permission.CAMERA;
        }
        else if(permissionAskedFor.equals("ALBUM")){
            return Manifest.permission.READ_EXTERNAL_STORAGE;
        }
        else if(permissionAskedFor.equals("PHONE_CALL")){
            return Manifest.permission.CALL_PHONE;
        }

        return null;
    }
}
