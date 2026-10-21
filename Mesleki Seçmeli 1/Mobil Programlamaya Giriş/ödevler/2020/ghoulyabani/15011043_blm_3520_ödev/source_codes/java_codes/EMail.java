package com.example.classapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;

import java.io.File;

public class EMail extends AppCompatActivity {
    EditText txtReceiver, txtCC, txtBCC, txtSubject, txtMail;
    ImageButton ibtnAttachment;
    Button btnSend;
    TextView txtAtName;
    final int ACTIVITY_CHOOSE_FILE = 1;
    Uri URI = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_e_mail);

        txtReceiver = findViewById(R.id.txtReceiver);
        txtCC = findViewById(R.id.txtCC);
        txtBCC = findViewById(R.id.txtBCC);
        txtSubject = findViewById(R.id.txtSubject);
        txtMail = findViewById(R.id.txtMail);
        ibtnAttachment = findViewById(R.id.ibtnAttachment);
        btnSend = findViewById(R.id.btnSend);
    }

    public void send(View v){

        String recipientList = txtReceiver.getText().toString();
        String[] recipients = recipientList.split(",");
        String ccList = txtReceiver.getText().toString();
        String[] CC = ccList.split(",");
        String bccList = txtBCC.getText().toString();
        String[] BCC = bccList.split(",");

        Intent intent = new Intent(Intent.ACTION_SEND);
        intent.putExtra(Intent.EXTRA_EMAIL, recipients);
        intent.putExtra(Intent.EXTRA_BCC, ccList);
        intent.putExtra(Intent.EXTRA_BCC, bccList);
        intent.putExtra(Intent.EXTRA_SUBJECT, txtSubject.getText().toString());
        intent.putExtra(Intent.EXTRA_TEXT, txtMail.getText().toString());
        if (URI != null) {
            intent.putExtra(Intent.EXTRA_STREAM, URI);
        }
        intent.setType("message/rfc822");
        startActivity(Intent.createChooser(intent,"Uygulama seçiniz"));
    }

    public void attachment(View v){
        Intent chooseFile;
        Intent intent;
        chooseFile = new Intent(Intent.ACTION_GET_CONTENT);
        chooseFile.setType("*/*");
        intent = Intent.createChooser(chooseFile, "Choose a file");
        startActivityForResult(intent, ACTIVITY_CHOOSE_FILE);
    }

    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        switch(requestCode) {
            case ACTIVITY_CHOOSE_FILE: {
                if (resultCode == RESULT_OK){
                    URI = data.getData();
                    //txtAtName.setText(URI.getLastPathSegment());
                    //txtAtName.setVisibility(View.VISIBLE);
                }
            }
        }
    }
}