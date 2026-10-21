package com.kaansonmezoz.blm3520.notebook.Database.Repository.NoteToNoteInfo;

import android.app.Application;
import android.arch.lifecycle.LiveData;

import com.kaansonmezoz.blm3520.notebook.Database.AppDatabase;
import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteToNoteInfoDao;
import com.kaansonmezoz.blm3520.notebook.Database.RelationEntity.NoteToNoteInfo;
import com.kaansonmezoz.blm3520.notebook.Database.Repository.NoteToNoteInfo.AsyncTask.NoteToNoteInfoAsyncSelect;

import java.util.List;
import java.util.concurrent.ExecutionException;

public class NoteToNoteInfoRepository {
    private NoteToNoteInfoDao dao;

    public NoteToNoteInfoRepository(Application application) {
        AppDatabase database = AppDatabase.getDatabase(application);
        dao = database.noteToNoteInfoDao();
    }

    public NoteToNoteInfo getNoteWithInfo(long noteId) throws ExecutionException, InterruptedException {
        return new NoteToNoteInfoAsyncSelect(dao).execute(noteId).get();
    }

    public LiveData<List<NoteToNoteInfo>> getAllNotesWithNoteInfo(){
        return dao.getAllNotesWithNoteInfo();
    }
}
