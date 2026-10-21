package com.example.homework2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class EmailActivity extends AppCompatActivity {
    EditText et_to, et_subject, et_content;
    String to_str, content_str, subject_str;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_email);

        Button send_btn = findViewById(R.id.btn_send);
        send_btn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                et_to = (EditText) findViewById(R.id.et_to);
                et_subject = (EditText) findViewById(R.id.et_subject);
                et_content = (EditText) findViewById(R.id.et_content);

                to_str = et_to.getText().toString();
                subject_str = et_subject.getText().toString();
                content_str = et_content.getText().toString();

                Intent emailIntent = new Intent(Intent.ACTION_SENDTO, Uri.fromParts(
                        "mailto",to_str, null));
                emailIntent.putExtra(Intent.EXTRA_SUBJECT, subject_str);
                emailIntent.putExtra(Intent.EXTRA_TEXT,  content_str);
                startActivity(Intent.createChooser(emailIntent, "Send email..."));
            }
        });
    }
}
