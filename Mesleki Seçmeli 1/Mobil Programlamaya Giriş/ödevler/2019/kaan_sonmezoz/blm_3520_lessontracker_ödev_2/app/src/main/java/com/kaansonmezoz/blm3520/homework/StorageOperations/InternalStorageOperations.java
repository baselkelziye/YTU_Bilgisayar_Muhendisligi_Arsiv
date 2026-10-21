package com.kaansonmezoz.blm3520.homework.StorageOperations;

import android.app.Activity;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import com.kaansonmezoz.blm3520.homework.R;

import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class InternalStorageOperations {

    public void saveImageFile(String fileName, Bitmap image, Context context) throws IOException{

        FileOutputStream imageFile;
        imageFile = context.openFileOutput(fileName, Context.MODE_PRIVATE);

        ByteArrayOutputStream imageOutputStream = new ByteArrayOutputStream();
        image.compress(Bitmap.CompressFormat.PNG, 100, imageOutputStream);

        imageFile.write(imageOutputStream.toByteArray());

        imageOutputStream.close();
        imageFile.close();
    }

    public Bitmap loadImageFile(String fileName, Context context) throws IOException{
        FileInputStream imageFile;
        imageFile = context.openFileInput(fileName);

        if(imageFile.available() == 0){
            return null;
        }

        //byte[] imageFileBytes = new byte[imageFile.available()];
        //imageFile.read(imageFileBytes);

        Bitmap imageBitmap = BitmapFactory.decodeStream(imageFile);
        imageFile.close();

        return imageBitmap;
    }
}
