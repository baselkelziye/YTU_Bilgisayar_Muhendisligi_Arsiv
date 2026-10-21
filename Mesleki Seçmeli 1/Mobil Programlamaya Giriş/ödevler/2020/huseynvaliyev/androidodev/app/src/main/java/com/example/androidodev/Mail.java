package com.example.androidodev;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

public class Mail extends AppCompatActivity {

    EditText Email;
    EditText Subject;
    EditText Message;
    Button Send;
    Button attachment;
    TextView attachmentName;
    String email;
    String subject;
    String message;
    Uri URI = null;
    private static final int PICK_FROM_GALLERY = 101;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.send_mail);
        Email = findViewById(R.id.receiver);
        Subject = findViewById(R.id.subject);
        Message = findViewById(R.id.context);
        attachment = findViewById(R.id.attachmentButton);
        attachmentName = findViewById(R.id.attachmentName);
        Send = findViewById(R.id.sendButton);
        Send.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    email = Email.getText().toString();
                    subject = Subject.getText().toString();
                    message = Message.getText().toString();
                    final Intent emailIntent = new Intent(android.content.Intent.ACTION_SEND);
                    emailIntent.setType("plain/text");
                    emailIntent.putExtra(android.content.Intent.EXTRA_EMAIL, new String[]{email});
                    emailIntent.putExtra(android.content.Intent.EXTRA_SUBJECT, subject);
                    if (URI != null) {
                        emailIntent.putExtra(Intent.EXTRA_STREAM, URI);
                    }
                    emailIntent.putExtra(android.content.Intent.EXTRA_TEXT, message);
                    startActivity(Intent.createChooser(emailIntent, "Choose your app"));
                } catch (Throwable t) {
                    Toast.makeText(Mail.this, "Request failed try again: "+ t.toString(), Toast.LENGTH_LONG).show();
                }
            }
        });
        attachment.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.setType("image/*");
                intent.setAction(Intent.ACTION_GET_CONTENT);
                intent.putExtra("return-data", true);
                startActivityForResult(Intent.createChooser(intent, "Complete action"), PICK_FROM_GALLERY);
            }
        });


}

    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == PICK_FROM_GALLERY && resultCode == RESULT_OK) {
            URI = data.getData();
        }
        String attachmentLabel = String.valueOf(URI.getLastPathSegment());
        attachmentName.setText("Attachment:"+attachmentLabel);
    }


}
