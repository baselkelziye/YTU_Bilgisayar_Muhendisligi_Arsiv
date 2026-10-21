package com.kaansonmezoz.blm3520.notebook.Activities.AddNoteActivity.AlertBox;

import android.app.Activity;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.support.v4.content.FileProvider;
import android.support.v7.app.AlertDialog;
import android.util.Log;

import com.kaansonmezoz.blm3520.notebook.Activities.AddNoteActivity.ViewModel.FileAttachment;
import com.kaansonmezoz.blm3520.notebook.BuildConfig;

import java.io.File;
import java.util.ArrayList;

public class FileAttachmentsAlertDialog {
    private ArrayList<FileAttachment> filePathsList;
    private ArrayList<FileAttachment> selectedItems;

    public FileAttachmentsAlertDialog(ArrayList<FileAttachment> filePathsList){
        this.filePathsList = filePathsList;
    }

    public void showDialog(Activity activity){
        onCreateDialog(activity).show();
    }

    private Dialog onCreateDialog(final Activity activity) {
        final String[] filePaths = new String[filePathsList.size()];

        for(int i = 0; i < filePathsList.size(); i++){
            filePaths[i] = filePathsList.get(i).getFileName();
        }

        selectedItems = new ArrayList<>();  // Where we track the selected items
        // Use the Builder class for convenient dialog construction
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);

        builder.setTitle("Files")
               .setMultiChoiceItems(filePaths, null, new DialogInterface.OnMultiChoiceClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which,  boolean isChecked) {
                        if (isChecked) {
                            // If the user checked the item, add it to the selected items
                            selectedItems.add(filePathsList.get(which));
                        }
                        else if (selectedItems.contains(filePathsList.get(which))) {
                            // Else, if the item is already in the array, remove it
                            selectedItems.remove(filePathsList.get(which));
                        }
                    }
               })
                .setPositiveButton("OPEN", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        /*
                        for(FileAttachment selected: selectedItems){
                            Log.d("Deneme", activity.getFilesDir().getPath());
                            Uri uri = Uri.parse(activity.getFilesDir().getPath() + selected.getFilePath());
                            String mime = activity.getContentResolver().getType(uri);

                            File file = new File(selected.getFilePath());
                            Intent intent = new Intent(Intent.ACTION_VIEW);
                            intent.setDataAndType(Build.VERSION.SDK_INT >= Build.VERSION_CODES.N ?
                                    FileProvider.getUriForFile(activity, BuildConfig.APPLICATION_ID + ".fileprovider", file) :
                                            Uri.fromFile(file), "image/*");
                            intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
                            activity.startActivity(intent);
                        }
                        */
                    }
                })
                .setNegativeButton("DELETE", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        for(FileAttachment selected: selectedItems){
                            if(filePathsList.contains(selected)){
                                filePathsList.remove(selected);
                            }
                        }
                    }
                });

        return builder.create();
    }
}
