package com.kaansonmezoz.blm3520.notebook.Database.Repository.NoteInfo;

import android.app.Application;

import com.kaansonmezoz.blm3520.notebook.Database.AppDatabase;
import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteInfoDao;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteInfo;
import com.kaansonmezoz.blm3520.notebook.Database.Repository.NoteInfo.AsyncTask.NoteInfoAsyncInsert;
import com.kaansonmezoz.blm3520.notebook.Database.Repository.NoteInfo.AsyncTask.NoteInfoAsyncSelect;
import com.kaansonmezoz.blm3520.notebook.Database.Repository.NoteInfo.AsyncTask.NoteInfoDeleteAsync;

import java.util.concurrent.ExecutionException;

public class NoteInfoRepository {
    private NoteInfoDao noteInfoDao;

    public NoteInfoRepository(Application application){
        AppDatabase database = AppDatabase.getDatabase(application);
        noteInfoDao = database.noteInfoDao();
    }

    public Long insertNote(NoteInfo noteInfo) throws ExecutionException, InterruptedException {
        return new NoteInfoAsyncInsert(noteInfoDao).execute(noteInfo).get();
    }

    public NoteInfo getNoteInfoById(long id) throws ExecutionException, InterruptedException {
        return new NoteInfoAsyncSelect(noteInfoDao).execute(id).get();
    }

    public void deleteNoteInfoById(long id) throws ExecutionException, InterruptedException {
        new NoteInfoDeleteAsync(noteInfoDao).execute(id).get();
        return;
    }
}
