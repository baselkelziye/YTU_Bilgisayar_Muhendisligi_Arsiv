package com.example.classapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.widget.EditText;

import java.util.HashSet;

public class Note extends AppCompatActivity {

    int noteId;
    SharedPreferences pref;
    SharedPreferences.Editor editor;
    String currentUser;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_note);

        pref = getApplicationContext().getSharedPreferences("MyPref", 0);
        editor = pref.edit();

        currentUser = pref.getString("current_user", null);

        EditText edtNote = findViewById(R.id.edtNote);
        Intent noteContent = getIntent();
        noteId = noteContent.getIntExtra("noteId", -1);

        if (noteId != -1){
            edtNote.setText(NoteList.notes.get(noteId));
        }
        else{
            NoteList.notes.add("");
            noteId = NoteList.notes.size() - 1;
            NoteList.arrayAdapter.notifyDataSetChanged();
        }

        edtNote.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                NoteList.notes.set(noteId, s.toString());
                NoteList.arrayAdapter.notifyDataSetChanged();

                HashSet<String> set = new HashSet(NoteList.notes);

                pref.edit().putStringSet(currentUser+"_notes", set).apply();
            }

            @Override
            public void afterTextChanged(Editable s) {

            }
        });
    }
}
