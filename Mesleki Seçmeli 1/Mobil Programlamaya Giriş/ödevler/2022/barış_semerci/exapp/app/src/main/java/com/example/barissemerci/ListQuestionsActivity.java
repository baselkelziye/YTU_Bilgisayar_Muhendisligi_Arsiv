package com.example.barissemerci;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.app.AlertDialog;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.MenuItem;


import com.google.android.material.snackbar.Snackbar;


import java.io.File;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import java.io.ObjectOutputStream;


public class ListQuestionsActivity extends AppCompatActivity {


    ListQuestionRecyclerAdapter listQuestionRecyclerAdapter;
    int personNo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_list_questions);
        Intent intent = getIntent();


        personNo = intent.getIntExtra("personNo", 0);


        RecyclerView recyclerView = findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        listQuestionRecyclerAdapter = new ListQuestionRecyclerAdapter(MainActivity.persons.get(personNo).getQuestions(), getApplicationContext());
        recyclerView.setAdapter(listQuestionRecyclerAdapter);

        listQuestionRecyclerAdapter.notifyDataSetChanged();
    }

    @Override
    public boolean onContextItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()) {
            case 121:
                new AlertDialog.Builder(ListQuestionsActivity.this)
                        .setIcon(R.drawable.ic_baseline_delete_24)
                        .setTitle("Delete?")
                        .setMessage("Are you sure you want to delete this question?")
                        .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                listQuestionRecyclerAdapter.deleteQuestion(item.getGroupId(), personNo);
                                displayMessage("Deleted");
                            }
                        }).setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                }).show();


                return true;
            case 122:
                Intent intent = new Intent(this, UpdateQuestionActivity.class);
                intent.putExtra("personPosition", personNo);
                intent.putExtra("questionPosition", item.getGroupId());

                startActivity(intent);
                finish();

                return true;
            default:
                return super.onContextItemSelected(item);
        }


    }


    private void displayMessage(String message) {
        Snackbar.make(findViewById(R.id.listLayout), message, Snackbar.LENGTH_LONG).show();
    }


    @Override
    protected void onStop() {
        super.onStop();
        File f = new File(getFilesDir() + "/userlist.dat");
        f.delete();
        FileOutputStream outStream = null;
        try {

            f = new File(getFilesDir() + "/userlist.dat");

            outStream = new FileOutputStream(f, true);
            ObjectOutputStream objectOutStream = new ObjectOutputStream(outStream);

            for (Person i : MainActivity.persons) {
                objectOutStream.writeObject(i);
            }

            objectOutStream.close();
        } catch (FileNotFoundException e1) {
            e1.printStackTrace();
        } catch (IOException e1) {
            e1.printStackTrace();
        }
    }


}