package ce.yildiz.android.ui.notes;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import java.io.File;
import java.io.OutputStreamWriter;

import ce.yildiz.android.R;
import ce.yildiz.android.databinding.ActivityNoteEditBinding;
import ce.yildiz.android.models.Note;
import ce.yildiz.android.util.Constants;
import ce.yildiz.android.util.SharedPreferencesUtil;

public class NoteEditActivity extends AppCompatActivity {
    private ActivityNoteEditBinding binding;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        if (SharedPreferencesUtil.getTheme().equals(Constants.AppThemes.DARK)) {
            setTheme(R.style.DarkTheme);
        } else {
            setTheme(R.style.AppTheme);
        }

        super.onCreate(savedInstanceState);
        binding = ActivityNoteEditBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        Intent intent = getIntent();

        if (intent == null) return;

        String noteName = intent.getStringExtra("noteName");
        String noteContent = intent.getStringExtra("noteContent");

        if (noteName != null && noteContent != null) {
            // Edit note
            binding.noteEditNoteName.setText(noteName);
            binding.noteEditNoteEditText.setText(noteContent);
        }

        binding.noteEditSaveButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String name = binding.noteEditNoteName.getText().toString();
                String content = binding.noteEditNoteEditText.getText().toString();
                Note note = new Note(name, content);
                save(note);
            }
        });

        binding.noteEditDeleteButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (delete(binding.noteEditNoteName.getText().toString())) {
                    Toast.makeText(NoteEditActivity.this,
                            R.string.note_delete_ok_message, Toast.LENGTH_SHORT).show();
                } else {
                    Toast.makeText(NoteEditActivity.this,
                            R.string.unknown_error_message, Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    private void save(Note note) {
        if (note.getNoteName().isEmpty()) {
            Toast.makeText(this,
                    R.string.note_save_empty_error_message, Toast.LENGTH_SHORT).show();
            return;
        }

        try {
            String fileName = note.getNoteName();

            if (!note.getNoteName().endsWith(".txt")) {
                fileName = note.getNoteName() + ".txt";
            }

            OutputStreamWriter out = new OutputStreamWriter(openFileOutput(fileName, 0));
            out.write(note.getContent());
            out.close();
            Toast.makeText(this,
                    R.string.note_saved_ok_message, Toast.LENGTH_SHORT).show();
        } catch (Throwable t) {
            Toast.makeText(this,
                    R.string.unknown_error_message, Toast.LENGTH_SHORT).show();
        }
    }

    private boolean delete(String fileName) {
        if (fileExists(fileName)) {
            return (new File(getFilesDir().getAbsolutePath(), "/" + fileName)).delete();
        }

        return false;
    }

    private boolean fileExists(String fileName){
        return getBaseContext().getFileStreamPath(fileName).exists();
    }
}
