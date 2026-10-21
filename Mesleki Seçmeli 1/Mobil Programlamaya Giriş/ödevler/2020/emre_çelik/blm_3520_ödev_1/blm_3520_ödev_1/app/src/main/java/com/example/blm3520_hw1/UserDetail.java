package com.example.blm3520_hw1;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewParent;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import java.util.Random;

public class UserDetail extends AppCompatActivity {

    ActionBar actionBar;
    EditText nameText, descriptionText;
    ImageView imageView;

    Button saveButton, avatarButton, updateButton, deleteButton;

    Boolean isComingFromIntent = false;
    String[] imageArray = new String[]{"batman", "catwoman", "chewbacca", "darth_vader", "joker_dc", "money_heist_dali", "pennywise", "sonic", "super_mario", "venom"};
    User user;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_user_detail);

        actionBar = getSupportActionBar();
        nameText = findViewById(R.id.nameText);
        descriptionText = findViewById(R.id.descriptionText);
        imageView = findViewById(R.id.imageView);
        saveButton = findViewById(R.id.saveButton);
        avatarButton = findViewById(R.id.avatarButton);
        updateButton = findViewById(R.id.updateButton);
        deleteButton = findViewById(R.id.deleteButton);

        checkComingIntent();
    }

    private void checkComingIntent() {
        Intent intent = getIntent();
        Bundle data = getIntent().getExtras();
        if (intent != null && data != null) {

            isComingFromIntent = true;
            int id = intent.getIntExtra("iID", -1);
            String name = intent.getStringExtra("iName");
            String description = intent.getStringExtra("iDescription");

            if (id != -1) {
                user = new User(id,name,description,"");
            }

            byte[] imageBytes = getIntent().getByteArrayExtra("iImage");
            Bitmap bitmap = BitmapFactory.decodeByteArray(imageBytes, 0, imageBytes.length);

            actionBar.setTitle((name));

            nameText.setText(name);
            descriptionText.setText(description);
            imageView.setImageBitmap(bitmap);

            saveButton.setVisibility(View.INVISIBLE);
            avatarButton.setVisibility(View.INVISIBLE);
        }
        else {
            String randomImageName = getRandomImage();
            user = new User(0,"","", randomImageName);
            imageView.setImageResource(getResources().getIdentifier(
                    randomImageName, "drawable", "com.example.blm3520_hw1"));
            ViewGroup layout = (ViewGroup) saveButton.getParent();
            if (layout != null){
                layout.removeView(deleteButton);
                layout.removeView(updateButton);
            }
            actionBar.setTitle(("Add User"));
        }
    }

    public void saveButtonClicked(View view) {
        String name = nameText.getText().toString();
        String description = descriptionText.getText().toString();
        user.setName(name);
        user.setDescription(description);
        addUser(user);
    }

    public void avatarButtonClicked(View view) {
        String randomImageName = getRandomImage();
        System.out.println(randomImageName);
        user.setImage(randomImageName);
        imageView.setImageResource(getResources().getIdentifier(
                randomImageName, "drawable", "com.example.blm3520_hw1"));
    }

    public void updateButtonClicked(View view) {
        String name = nameText.getText().toString();
        String description = descriptionText.getText().toString();
        user.setName(name);
        user.setDescription(description);
        updateSQLUser(user);
    }

    public void deleteButtonClicked(View view) {
        updateButton.setEnabled(false);
        deleteButton.setEnabled(false);
        deleteUser(user);
    }

    private String getRandomImage() {
        int rnd = new Random().nextInt(imageArray.length);
        return imageArray[rnd];
    }


    private void updateSQLUser(User user) {
        try {
            SQLiteDatabase database = this.openOrCreateDatabase("Users", MODE_PRIVATE, null);
            database.execSQL("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name VARCHAR, description VARCHAR, image VARCHAR)");
            database.execSQL("UPDATE users SET name = '" + user.getName() + "', description = '" + user.getDescription() + "' WHERE id = '" + user.getId() + "'");
        }
        catch (Exception e) {
            Toast.makeText(getApplicationContext(),"Something Happened -__-",Toast.LENGTH_SHORT).show();
            e.printStackTrace();
        }
        Toast.makeText(getApplicationContext(),"Updated Successfully",Toast.LENGTH_SHORT).show();
    }

    private void deleteUser(User user) {
        try {
            SQLiteDatabase database = this.openOrCreateDatabase("Users", MODE_PRIVATE, null);
            database.execSQL("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name VARCHAR, description VARCHAR, image VARCHAR)");
            database.execSQL("DELETE FROM users WHERE id = " + user.getId());
        }
        catch (Exception e) {
            Toast.makeText(getApplicationContext(),"Something Happened -__-",Toast.LENGTH_SHORT).show();
            e.printStackTrace();
        }
        Toast.makeText(getApplicationContext(),"Deleted Successfully",Toast.LENGTH_SHORT).show();
    }

    private void addUser(User user) {
        try {
            SQLiteDatabase database = this.openOrCreateDatabase("Users", MODE_PRIVATE, null);
            database.execSQL("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name VARCHAR, description VARCHAR, image VARCHAR)");
            database.execSQL("INSERT INTO users (name, description, image) VALUES ('" + user.getName() + "','" + user.getDescription() + "','" + user.getImage() + "')");
        }
        catch (Exception e) {
            Toast.makeText(getApplicationContext(),"Something Happened -__-",Toast.LENGTH_SHORT).show();
            e.printStackTrace();
        }
        Toast.makeText(getApplicationContext(),"Added Successfully",Toast.LENGTH_SHORT).show();
    }

}
