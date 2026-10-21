package com.kaansonmezoz.blm3520.notebook.Database.Repository.Note.AsyncTask;

import android.os.AsyncTask;

import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteDao;

public class NoteDeleteAsync extends AsyncTask<Long,Void, Void> {
    private NoteDao noteInfoDao;

    public NoteDeleteAsync(NoteDao noteInfoDao){
        this.noteInfoDao = noteInfoDao;
    }

    @Override
    protected Void doInBackground(final Long ... params) {
        noteInfoDao.deleteNoteById(params[0]);
        return null;
    }
}
