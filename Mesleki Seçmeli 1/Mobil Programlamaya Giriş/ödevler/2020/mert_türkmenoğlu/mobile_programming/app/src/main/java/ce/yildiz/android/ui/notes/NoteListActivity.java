package ce.yildiz.android.ui.notes;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.io.BufferedReader;
import java.io.File;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import ce.yildiz.android.R;
import ce.yildiz.android.databinding.ActivityNoteListBinding;
import ce.yildiz.android.interfaces.RecyclerViewClickListener;
import ce.yildiz.android.models.Note;
import ce.yildiz.android.ui.notes.adapters.NoteListAdapter;
import ce.yildiz.android.util.Constants;
import ce.yildiz.android.util.SharedPreferencesUtil;

public class NoteListActivity extends AppCompatActivity {
    private ActivityNoteListBinding binding;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        if (SharedPreferencesUtil.getTheme().equals(Constants.AppThemes.DARK)) {
            setTheme(R.style.DarkTheme);
        } else {
            setTheme(R.style.AppTheme);
        }

        super.onCreate(savedInstanceState);
        binding = ActivityNoteListBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        final List<Note> notes = getNotesFromInternalStorage();
        RecyclerView.LayoutManager layoutManager = new LinearLayoutManager(this);
        binding.noteListRecyclerView.setLayoutManager(layoutManager);

        RecyclerViewClickListener listener = new RecyclerViewClickListener() {
            @Override
            public void onClick(View view, int position) {
                TextView noteNameTextView = view.findViewById(R.id.note_list_item_note_name);
                String noteName = noteNameTextView.getText().toString();

                String noteContent = "";

                for (Note note : notes) {
                    if (note.getNoteName().equals(noteName)) {
                        noteContent = note.getContent();
                        break;
                    }
                }

                Intent noteEditIntent = new Intent(NoteListActivity.this,
                        NoteEditActivity.class);

                noteEditIntent.putExtra("noteName", noteName);
                noteEditIntent.putExtra("noteContent", noteContent);

                startActivity(noteEditIntent);
            }
        };

        NoteListAdapter adapter = new NoteListAdapter(notes, listener);
        binding.noteListRecyclerView.setAdapter(adapter);

        binding.noteListNewNoteButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent newNoteIntent = new Intent(NoteListActivity.this,
                        NoteEditActivity.class);

                startActivity(newNoteIntent);
            }
        });
    }

    private List<Note> getNotesFromInternalStorage() {
        File filesDirectory = getFilesDir();
        File[] files = filesDirectory.listFiles();
        List<Note> noteList = new ArrayList<>();

        if (files == null) return new ArrayList<>();

        for (File file : files) {
            String noteName = file.getName();
            noteList.add(new Note(noteName, open(noteName)));
        }

        return noteList;
    }

    public String open(String fileName) {
        String content = "";

        if (fileExists(fileName)) {
            try {
                InputStream inputStream = openFileInput(fileName);

                if (inputStream != null) {
                    InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
                    BufferedReader reader = new BufferedReader(inputStreamReader);

                    String str;
                    StringBuilder sb = new StringBuilder();

                    while ((str = reader.readLine()) != null) {
                        sb.append(str).append("\n");
                    }

                    inputStream .close();
                    content = sb.toString();
                }
            } catch (Throwable t) {
                Toast.makeText(this,
                        R.string.unknown_error_message, Toast.LENGTH_SHORT).show();
            }
        }

        return content;
    }

    private boolean fileExists(String fileName){
        return getBaseContext().getFileStreamPath(fileName).exists();
    }
}
