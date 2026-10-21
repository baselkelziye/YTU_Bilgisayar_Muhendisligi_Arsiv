package com.kaansonmezoz.blm3520.notebook.Activities.AddNoteActivity;

import android.content.Intent;
import android.database.Cursor;
import android.graphics.Color;
import android.graphics.PorterDuff;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.provider.OpenableColumns;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.kaansonmezoz.blm3520.notebook.Activities.AddNoteActivity.AlertBox.FileAttachmentsAlertDialog;
import com.kaansonmezoz.blm3520.notebook.Activities.AddNoteActivity.ViewModel.FileAttachment;
import com.kaansonmezoz.blm3520.notebook.Activities.MainActivity.MainActivity;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.Note;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteAttachment;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteInfo;
import com.kaansonmezoz.blm3520.notebook.Database.Repository.Note.NoteRepository;
import com.kaansonmezoz.blm3520.notebook.Database.Repository.NoteInfo.NoteInfoRepository;
import com.kaansonmezoz.blm3520.notebook.Database.Repository.NotePath.NotePathRepository;
import com.kaansonmezoz.blm3520.notebook.Manager.RequestCodeManager;
import com.kaansonmezoz.blm3520.notebook.R;

import java.util.ArrayList;
import java.util.Date;
import java.util.concurrent.ExecutionException;

public class AddNoteActivity extends AppCompatActivity {
    private Button saveButton;
    private EditText noteText;
    private Toolbar mTopToolbar;
    private EditText noteTitle;
    private ArrayList<FileAttachment> attachmentPaths;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_note);


        //TODO: burası aslinda aynı aktivite olacak eger ki bundle icerisinden ya da intent ile iste bize bir obje gelmemisse
        //TODO: bu demek olacak ki yeni bir not yaratılıyor degil ise yeni bir not degil bu

        attachmentPaths = new ArrayList<FileAttachment>();

        saveButton = findViewById(R.id.saveButton);
        noteText = findViewById(R.id.noteText);
        noteTitle = findViewById(R.id.note_title);

        mTopToolbar = (Toolbar) findViewById(R.id.add_note_toolbar);
        setSupportActionBar(mTopToolbar);

        saveButton.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view){
                NoteInfoRepository repositoryNoteInfo = new NoteInfoRepository(getApplication());
                NoteRepository repositoryNote = new NoteRepository(getApplication());
                NotePathRepository notePathRepository = new NotePathRepository(getApplication());

                String title = noteTitle.getText().toString();

                NoteAttachment attachment;

                long noteId = 0;

                try {
                    NoteInfo noteInfo = new NoteInfo(new Date(), new Date(), null);
                    long noteInfoId = repositoryNoteInfo.insertNote(noteInfo);

                    Note note = new Note(title, "medium");
                    note.noteInfoId = noteInfoId;
                    repositoryNote.insertNote(note);

                    if(attachmentPaths.size() != 0){ //TODO: ancak bu zaman dosya eklenmis demek db'ye o sekilde eklenecek
                        for(FileAttachment fileAttachment: attachmentPaths){
                            attachment = new NoteAttachment();
                            attachment.filePath = fileAttachment.getFilePath();
                            attachment.note_id = noteId;
                            attachment.fileName = fileAttachment.getFileName();
                            notePathRepository.insertNote(attachment);
                        }
                    }

                } catch (ExecutionException e) {
                    e.printStackTrace();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                Intent intent = new Intent(AddNoteActivity.this, MainActivity.class);
                startActivity(intent);

            }
        });

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.add_note_menu, menu);


        for(int i = 0; i < menu.size(); i++){   // bunu ayrıca color degistirmek icin de kullanmamiz gerekecek
            MenuItem item = menu.getItem(i);
            if(item.getTitle().toString().equals("Note Color")){
                Drawable drawable = item.getIcon();
                if(drawable != null) {
                    drawable.mutate();
                    drawable.setColorFilter(Color.parseColor("#ffffff"), PorterDuff.Mode.SRC_ATOP);
                }
            }

        }

        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.attachment) {
            FileAttachmentsAlertDialog dialog = new FileAttachmentsAlertDialog(attachmentPaths);
            dialog.showDialog(this);
            return true;
        }
        else if(id == R.id.add_attachment){
            RequestCodeManager manager = new RequestCodeManager();
            int requestCode = manager.getRequestCodeFor("FILE_EXPLORER");
            Intent intent = new Intent(Intent.ACTION_GET_CONTENT);
            intent.setType("*/*");
            startActivityForResult(intent, requestCode);
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data){
        switch(requestCode){
            case 1:
                if(resultCode == RESULT_OK){
                    Uri uri = data.getData();
                    //File file = new File(uri.getPath());
                    //String filePath = file.getAbsolutePath();
                    String filePath = uri.getPath();
                    String fileName = getFileName(uri);

                    attachmentPaths.add(new FileAttachment(fileName, filePath));
                }
        }
    }

    public String getFileName(Uri uri) {
        String result = null;
        if (uri.getScheme().equals("content")) {
            Cursor cursor = getContentResolver().query(uri, null, null, null, null);
            try {
                if (cursor != null && cursor.moveToFirst()) {
                    result = cursor.getString(cursor.getColumnIndex(OpenableColumns.DISPLAY_NAME));
                }
            } finally {
                cursor.close();
            }
        }
        if (result == null) {
            result = uri.getPath();
            int cut = result.lastIndexOf('/');
            if (cut != -1) {
                result = result.substring(cut + 1);
            }
        }
        return result;
    }
}
