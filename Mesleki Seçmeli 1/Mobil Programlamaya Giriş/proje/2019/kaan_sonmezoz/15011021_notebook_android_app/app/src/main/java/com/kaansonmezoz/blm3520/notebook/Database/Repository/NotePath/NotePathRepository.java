package com.kaansonmezoz.blm3520.notebook.Database.Repository.NotePath;

import android.app.Application;
import android.arch.lifecycle.LiveData;

import com.kaansonmezoz.blm3520.notebook.Database.AppDatabase;
import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteAttachmentDao;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.Note;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteAttachment;

import java.util.List;
import java.util.concurrent.ExecutionException;

public class NotePathRepository {
    private NoteAttachmentDao noteDao;

    public NotePathRepository(Application application){
        AppDatabase database = AppDatabase.getDatabase(application);
        noteDao = database.noteAttachmentDao();
    }

    public Long insertNote(NoteAttachment note) throws ExecutionException, InterruptedException {
        return new NotePathInsertAsync(noteDao).execute(note).get();
    }

    public List<NoteAttachment> getAllNoteAttachments(long noteId) throws ExecutionException, InterruptedException {
        return new NotePathSelectAsync(noteDao).execute(noteId).get();
    }

}
