package com.kaansonmezoz.blm3520.notebook.Database.Repository.NoteInfo.AsyncTask;

import android.os.AsyncTask;

import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteInfoDao;

public class NoteInfoDeleteAsync extends AsyncTask<Long,Void,Void> {
    private NoteInfoDao noteInfoDao;

    public NoteInfoDeleteAsync(NoteInfoDao noteInfoDao){
        this.noteInfoDao = noteInfoDao;
    }

    @Override
    protected Void doInBackground(final Long ... params) {
        noteInfoDao.deleteNoteInfoById(params[0]);
        return null;
    }
}
