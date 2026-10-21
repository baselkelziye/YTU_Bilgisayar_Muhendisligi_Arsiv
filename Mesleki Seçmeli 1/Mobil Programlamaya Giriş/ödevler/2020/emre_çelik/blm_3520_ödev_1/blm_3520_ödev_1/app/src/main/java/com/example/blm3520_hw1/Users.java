package com.example.blm3520_hw1;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.view.MenuItemCompat;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.SearchView;

import java.util.ArrayList;
import java.util.Collections;

public class Users extends AppCompatActivity {

    RecyclerView recyclerView;
    RecycleAdapter adapter;

    SharedPreferences preferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_users);

        recyclerView = findViewById(R.id.recyclerView);
        preferences = this.getSharedPreferences("User_Sort", MODE_PRIVATE);

        getUserList();
    }

    private ArrayList<User> getAllSQLUser() {
        ArrayList<User> users = new ArrayList<>();
        try {
            SQLiteDatabase database = this.openOrCreateDatabase("Users", MODE_PRIVATE, null);
            database.execSQL("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name VARCHAR, description VARCHAR, image VARCHAR)");

            Cursor cursor = database.rawQuery("SELECT * FROM users", null);

            int idIx = cursor.getColumnIndex("id");
            int nameIx = cursor.getColumnIndex("name");
            int descriptionIx = cursor.getColumnIndex("description");
            int imageIx = cursor.getColumnIndex("image");

            while (cursor.moveToNext()) {
                int id = cursor.getInt(idIx);
                String name = cursor.getString(nameIx);
                String description = cursor.getString(descriptionIx);
                String image = cursor.getString(imageIx);
                users.add(new User(id, name, description, image));
            }
            cursor.close();

        }
        catch (Exception e) {
            e.printStackTrace();
        }
        return users;
    }

    private void getUserList() {
        ArrayList<User> users = getAllSQLUser();

        String sortSetting = preferences.getString("Sort", "ascending");

        if (sortSetting.equals("ascending")) {
            Collections.sort(users, User.BY_NAME_ASCENDING);
        }
        else if (sortSetting.equals("descending")) {
            Collections.sort(users, User.BY_NAME_DESCENDING);
        }

        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        adapter = new RecycleAdapter(this, users);
        recyclerView.setAdapter(adapter);
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater menuInflater = getMenuInflater();
        menuInflater.inflate(R.menu.menu, menu);

        MenuItem item = menu.findItem(R.id.search);

        SearchView searchView = (SearchView) MenuItemCompat.getActionView(item);

        searchView.setOnQueryTextListener(new SearchView.OnQueryTextListener() {
            @Override
            public boolean onQueryTextSubmit(String query) {
                adapter.getFilter().filter(query);
                return false;
            }

            @Override
            public boolean onQueryTextChange(String newText) {
                adapter.getFilter().filter(newText);
                return false;
            }
        });

        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {

        int id = item.getItemId();

        if (id == R.id.sorting) {
            sortDialog();
            return true;
        }
        else if (id == R.id.add) {
            goToAddActivity();
        }

        return super.onOptionsItemSelected(item);
    }

    private void goToAddActivity() {
        Intent intent = new Intent(Users.this, UserDetail.class);
        startActivity(intent);
    }


    private void sortDialog() {
        String[] options = {"Ascending", "Descending"};
        AlertDialog.Builder builder = new AlertDialog.Builder(this);

        builder.setTitle("Sort by");
        builder.setIcon(R.drawable.ic_action_sort);

        builder.setItems(options, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

                if (which == 0) {
                    SharedPreferences.Editor editor = preferences.edit();
                    editor.putString("Sort", "ascending");
                    editor.apply();
                    getUserList();
                }
                else if (which == 1) {
                    SharedPreferences.Editor editor = preferences.edit();
                    editor.putString("Sort", "descending");
                    editor.apply();
                    getUserList();
                }

            }
        });

        builder.create().show();

    }

}


















