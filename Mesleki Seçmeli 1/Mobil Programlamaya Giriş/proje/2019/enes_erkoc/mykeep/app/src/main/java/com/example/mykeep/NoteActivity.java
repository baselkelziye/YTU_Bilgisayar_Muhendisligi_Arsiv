package com.example.mykeep;

import android.app.Activity;
import android.app.AlarmManager;
import android.app.DatePickerDialog;
import android.app.PendingIntent;
import android.app.TimePickerDialog;
import android.content.Context;
import android.content.Intent;
import android.graphics.Paint;
import android.provider.CalendarContract;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.DialogFragment;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;

import android.widget.TextView;

import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ServerValue;
import com.google.firebase.database.ValueEventListener;


import java.util.HashMap;
import java.util.Map;



public class NoteActivity extends AppCompatActivity {

    //private Button btnCreate;
    private EditText etTitle, etContent;
    private TextView etReminder;
    private ImageView deleteReminderImage;

    private FirebaseAuth fAuth;
    private DatabaseReference fNotesDatabase;

    private String noteID;

    private boolean isExist;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_note);

        try {
            noteID = getIntent().getStringExtra("noteId");

            //Toast.makeText(this, noteID, Toast.LENGTH_SHORT).show();

            if (!noteID.trim().equals("")) {
                isExist = true;
            } else {
                isExist = false;
            }

        } catch (Exception e) {
            e.printStackTrace();
        }


        etTitle = (EditText) findViewById(R.id.new_note_title);
        etContent = (EditText) findViewById(R.id.new_note_content);
        etReminder = findViewById(R.id.txt_note_reminder);
        deleteReminderImage = findViewById(R.id.delete_reminder);

        deleteReminderImage.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                if(!TextUtils.isEmpty(etReminder.getText().toString())){
                    AlertDialog.Builder mBuilder = new AlertDialog.Builder(NoteActivity.this);
                    final View mView = getLayoutInflater().inflate(R.layout.dialog_reminder, null);

                    mBuilder.setView(mView);

                    final AlertDialog dialog = mBuilder.create();
                    dialog.show();


                    Button btnDeleteReminder = mView.findViewById(R.id.delete_reminder);
                    Button btnCancelDialog = mView.findViewById(R.id.cancel_dialog);

                    TextView txtDateTime = mView.findViewById(R.id.txt_date_time);
                    txtDateTime.setText(etReminder.getText().toString());

                    btnDeleteReminder.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            AlarmManager alarmManager = (AlarmManager) getSystemService(Context.ALARM_SERVICE);
                            Intent intent = new Intent(NoteActivity.this, AlertReceiver.class);
                            PendingIntent pendingIntent = PendingIntent.getBroadcast(NoteActivity.this, 1, intent, 0);

                            alarmManager.cancel(pendingIntent);

                            etReminder.setText("");

                            dialog.dismiss();

                            Toast.makeText(getApplicationContext(), "Reminder deleted", Toast.LENGTH_LONG).show();
                        }
                    });

                    btnCancelDialog.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            dialog.dismiss();
                        }
                    });
                }else{
                    Toast.makeText(getApplicationContext(), "No Reminders Added", Toast.LENGTH_SHORT).show();
                }


            }
        });


        etReminder.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                if(!TextUtils.isEmpty(etReminder.getText().toString())){
                    AlertDialog.Builder mBuilder = new AlertDialog.Builder(NoteActivity.this);
                    final View mView = getLayoutInflater().inflate(R.layout.dialog_reminder, null);

                    mBuilder.setView(mView);

                    final AlertDialog dialog = mBuilder.create();
                    dialog.show();

                    Button btnDeleteReminder = mView.findViewById(R.id.delete_reminder);
                    Button btnCancelDialog = mView.findViewById(R.id.cancel_dialog);
                    TextView txtDateTime = mView.findViewById(R.id.txt_date_time);

                    txtDateTime.setText(etReminder.getText().toString());

                    btnDeleteReminder.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            AlarmManager alarmManager = (AlarmManager) getSystemService(Context.ALARM_SERVICE);
                            Intent intent = new Intent(NoteActivity.this, AlertReceiver.class);
                            PendingIntent pendingIntent = PendingIntent.getBroadcast(NoteActivity.this, 1, intent, 0);

                            alarmManager.cancel(pendingIntent);

                            etReminder.setText("");

                            dialog.dismiss();

                            Toast.makeText(getApplicationContext(), "Reminder deleted", Toast.LENGTH_LONG).show();
                        }
                    });

                    btnCancelDialog.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            dialog.dismiss();
                        }
                    });
                }else{
                    Toast.makeText(getApplicationContext(), "No Reminders Added", Toast.LENGTH_SHORT).show();
                }


            }
        });

        getSupportActionBar().setDisplayShowHomeEnabled(true);
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);


        fAuth = FirebaseAuth.getInstance();
        fNotesDatabase = FirebaseDatabase.getInstance().getReference().child("notes").child(fAuth.getCurrentUser().getUid());

        putData();
    }

   /* @Override
    protected void onStart() {
        super.onStart();
        if(checkDatePassed(etReminder.getText().toString()) < 0 ){
            etReminder.setPaintFlags(etReminder.getPaintFlags() | Paint.STRIKE_THRU_TEXT_FLAG);
        }
    }*/

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {

        if (requestCode == 1) {
            if(resultCode == Activity.RESULT_OK){
                String result=data.getStringExtra("result");

                etReminder.setText(result);

            }
        }
    }


  /*  private int checkDatePassed(String date){


        SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy HH:mm", Locale.getDefault());

        try {
            Date reminderDate = sdf.parse(date);
            Date nowDate = Calendar.getInstance().getTime();
            reminderDate.compareTo(nowDate); // false / current time has not passed currentTime.

        } catch (ParseException ignored) {

        }


    }*/

    private void putData() {

        if (isExist) {
            fNotesDatabase.child(noteID).addValueEventListener(new ValueEventListener() {
                @Override
                public void onDataChange(DataSnapshot dataSnapshot) {
                    if (dataSnapshot.hasChild("title") && dataSnapshot.hasChild("content")) {
                        String title = dataSnapshot.child("title").getValue().toString();
                        String content = dataSnapshot.child("content").getValue().toString();
                        String reminder = dataSnapshot.child("reminder").getValue().toString();

                        etTitle.setText(title);
                        etContent.setText(content);
                        etReminder.setText(reminder);
                    }
                }

                @Override
                public void onCancelled(DatabaseError databaseError) {

                }
            });
        }
    }

    private void createNote(String title, String content, String reminder, boolean isReminderSetted) {

        if (fAuth.getCurrentUser() != null) {

            if (isExist) {
                // UPDATE A NOTE
                Map updateMap = new HashMap();
                updateMap.put("title", etTitle.getText().toString().trim());
                updateMap.put("content", etContent.getText().toString().trim());
                updateMap.put("timestamp", ServerValue.TIMESTAMP);
                updateMap.put("reminder", etReminder.getText().toString().replace(":", "-"));
                updateMap.put("isReminderSetted", !TextUtils.isEmpty(etReminder.getText().toString()));

                fNotesDatabase.child(noteID).updateChildren(updateMap);
                Log.d("id", noteID);

                Toast.makeText(this, "Note Saved", Toast.LENGTH_SHORT).show();
            } else {
                // CREATE A NEW NOTE
                final DatabaseReference newNoteRef = fNotesDatabase.push();

                final Map noteMap = new HashMap();
                noteMap.put("title", title);
                noteMap.put("content", content);
                noteMap.put("timestamp", ServerValue.TIMESTAMP);
                noteMap.put("reminder", reminder);
                noteMap.put("isReminderSetted", isReminderSetted);

                Thread mainThread = new Thread(new Runnable() {
                    @Override
                    public void run() {
                        newNoteRef.setValue(noteMap).addOnCompleteListener(new OnCompleteListener<Void>() {
                            @Override
                            public void onComplete(@NonNull Task<Void> task) {
                                if (task.isSuccessful()) {
                                    Toast.makeText(NoteActivity.this, "Note Saved", Toast.LENGTH_SHORT).show();
                                } else {
                                    Toast.makeText(NoteActivity.this, "ERROR: " + task.getException().getMessage(), Toast.LENGTH_SHORT).show();
                                }

                            }
                        });
                    }
                });
                mainThread.start();
            }



        } else {
            Toast.makeText(this, "User is not signed in.", Toast.LENGTH_SHORT).show();
        }

    }

    private void deleteNote() {

        fNotesDatabase.child(noteID).removeValue().addOnCompleteListener(new OnCompleteListener<Void>() {
            @Override
            public void onComplete(@NonNull Task<Void> task) {
                if (task.isSuccessful()) {
                    Toast.makeText(NoteActivity.this, "Note Deleted", Toast.LENGTH_SHORT).show();
                    noteID = "no";
                    finish();
                } else {
                    Log.e("NewNoteActivity", task.getException().toString());
                    Toast.makeText(NoteActivity.this, "ERROR: " + task.getException().getMessage(), Toast.LENGTH_SHORT).show();
                }
            }
        });

    }

    private void addReminder(){

        Intent intent = new Intent(NoteActivity.this, ReminderActivity.class);
        intent.putExtra("reminderTitle", etTitle.getText().toString());
        intent.putExtra("reminderContent", etContent.getText().toString());


        startActivityForResult(intent, 1);


    }

    private void shareNote(){
        String shareBody = "\""+etTitle.getText().toString()+"\" - "+ etContent.getText().toString();
        Intent sharingIntent = new Intent(android.content.Intent.ACTION_SEND);
        sharingIntent.setType("text/plain");
        sharingIntent.putExtra(android.content.Intent.EXTRA_SUBJECT, "Subject Here");
        sharingIntent.putExtra(android.content.Intent.EXTRA_TEXT, shareBody);
        startActivity(Intent.createChooser(sharingIntent, getResources().getString(R.string.share_using)));
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        getMenuInflater().inflate(R.menu.new_note_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        super.onOptionsItemSelected(item);

        switch (item.getItemId()) {
            case android.R.id.home:
                String title = etTitle.getText().toString().trim();
                String content = etContent.getText().toString().trim();
                String reminder = etReminder.getText().toString().replace(":", "-");
                if (!TextUtils.isEmpty(title) || !TextUtils.isEmpty(content)) {
                    createNote(title, content, reminder, !TextUtils.isEmpty(etReminder.getText().toString()));

                } else {
                    Toast.makeText(getApplicationContext(), "Empty Note Discarded", Toast.LENGTH_SHORT).show();
                }
                finish();
                break;
            case R.id.new_note_delete_btn:
                if (isExist) {
                    deleteNote();
                } else {
                    Toast.makeText(this, "Nothing to delete", Toast.LENGTH_SHORT).show();
                }
                break;
            case R.id.add_reminder_btn:
                addReminder();

                break;
            case R.id.share_btn:
                shareNote();

                break;

        }

        return true;
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();

        String title = etTitle.getText().toString().trim();
        String content = etContent.getText().toString().trim();
        String reminder = etReminder.getText().toString().replace(":", "-");
        if (!TextUtils.isEmpty(title) || !TextUtils.isEmpty(content)) {
            createNote(title, content, reminder, !TextUtils.isEmpty(etReminder.getText().toString()));

        } else {
            Toast.makeText(getApplicationContext(), "Empty Note Discarded", Toast.LENGTH_SHORT).show();
        }
        finish();
    }
}
