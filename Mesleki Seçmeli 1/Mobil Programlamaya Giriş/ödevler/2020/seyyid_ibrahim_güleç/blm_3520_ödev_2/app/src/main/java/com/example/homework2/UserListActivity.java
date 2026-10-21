package com.example.homework2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.app.AlertDialog;

import java.util.ArrayList;
import java.util.Map;

public class UserListActivity extends AppCompatActivity {
    private SharedPreferences preferences;
    private String current_key;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_user_list);

        final ArrayList<String> keys = new ArrayList<>();
        final ImageView imgView = (ImageView)findViewById(R.id.dialog_imageview);

        imgView.setVisibility(View.INVISIBLE);
        preferences = PreferenceManager.getDefaultSharedPreferences(getApplicationContext());
        Map<String, ?> allEntries = preferences.getAll();
        for (Map.Entry<String, ?> entry : allEntries.entrySet()) {
            current_key = entry.getKey();
            if(!current_key.equals("reply") && !current_key.equals("sync"))
                keys.add(entry.getKey());

        }

        ListView list = (ListView) findViewById(R.id.listView1);

        ArrayAdapter<String> dataAdaptor=new ArrayAdapter<String>
                (this, android.R.layout.simple_list_item_1, android.R.id.text1, keys);

        list.setAdapter(dataAdaptor);

        list.setOnItemClickListener(new AdapterView.OnItemClickListener() {

            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position,
                                    long id) {
                AlertDialog.Builder alertadd = new AlertDialog.Builder(UserListActivity.this);
                LayoutInflater factory = LayoutInflater.from(UserListActivity.this);
                final View view1 = factory.inflate(R.layout.activity_user_list, null);
                alertadd.setView(view1);
                alertadd.setMessage("Username :" + keys.get(position) + "\n" + "Password :" + preferences.getString(keys.get(position), null));
                alertadd.show();
            }
        });

    }
}
