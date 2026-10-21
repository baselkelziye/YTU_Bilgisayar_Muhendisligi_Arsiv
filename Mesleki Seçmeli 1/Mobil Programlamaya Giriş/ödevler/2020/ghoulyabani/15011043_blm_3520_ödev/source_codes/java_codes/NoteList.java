package com.example.classapp;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.HashSet;

public class NoteList extends AppCompatActivity {

    static ArrayList<String> notes = new ArrayList<>();
    static ArrayAdapter arrayAdapter;
    SharedPreferences pref;
    SharedPreferences.Editor editor;
    String currentUser;

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater menuInflater = getMenuInflater();
        menuInflater.inflate(R.menu.add_note_menu, menu);

        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        super.onOptionsItemSelected(item);

        if (item.getItemId() == R.id.add_note){
            Intent intent = new Intent(getApplicationContext(), Note.class);
            startActivity(intent);

            return true;
        }
        return  false;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_note_list);

        ListView noteList = findViewById(R.id.listNotes);
        pref = getApplicationContext().getSharedPreferences("MyPref", 0);
        editor = pref.edit();

        currentUser = pref.getString("current_user", null);

        HashSet<String> set = (HashSet) pref.getStringSet(currentUser+"_notes", null);
        if (set != null){
            notes = new ArrayList(set);
        }
        else {
            notes = new ArrayList<>();
        }

        arrayAdapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, notes);
        noteList.setAdapter(arrayAdapter);
        noteList.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Intent note = new Intent(getApplicationContext(), Note.class);
                note.putExtra("noteId", position);
                startActivity(note);
            }
        });

        noteList.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, View view, final int position, long id) {
                new AlertDialog.Builder(NoteList.this)
                        .setIcon(android.R.drawable.ic_dialog_alert)
                        .setTitle("Seçili notu sil?")
                        .setMessage("Bu notu silmek istediğinize emin misiniz?")
                        .setPositiveButton("Evet", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                notes.remove(position);
                                arrayAdapter.notifyDataSetChanged();

                                HashSet<String> set = new HashSet(NoteList.notes);

                                pref.edit().putStringSet(currentUser+"_notes", set).apply();
                            }
                        })
                        .setNegativeButton("Hayır", null)
                        .show();

                return true;
            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();

        arrayAdapter.notifyDataSetChanged();
    }
}
