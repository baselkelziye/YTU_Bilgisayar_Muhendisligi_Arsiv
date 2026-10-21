package com.example.blm3520_hw1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class Mail extends AppCompatActivity {

    EditText mailText;
    EditText titleText;
    EditText contentText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mail);

        mailText = findViewById(R.id.mailText);
        titleText = findViewById(R.id.titleText);
        contentText = findViewById(R.id.contentText);
    }

    public void sendMailClicked(View view) {
        String mailTo = mailText.getText().toString();
        String title = titleText.getText().toString();
        String content = contentText.getText().toString();

        if (mailTo.matches("") || title.matches("")) {
            Toast.makeText(getApplicationContext(),"Please fill mail and title",Toast.LENGTH_SHORT).show();
            return;
        }

        Intent intent = new Intent(Intent.ACTION_SEND);
        intent.setType("plain/text");
        intent.putExtra(Intent.EXTRA_EMAIL, new String[]{mailTo});
        intent.putExtra(Intent.EXTRA_SUBJECT, title);
        intent.putExtra(Intent.EXTRA_TEXT, content);
        startActivity(Intent.createChooser(intent, ""));

    }
}
