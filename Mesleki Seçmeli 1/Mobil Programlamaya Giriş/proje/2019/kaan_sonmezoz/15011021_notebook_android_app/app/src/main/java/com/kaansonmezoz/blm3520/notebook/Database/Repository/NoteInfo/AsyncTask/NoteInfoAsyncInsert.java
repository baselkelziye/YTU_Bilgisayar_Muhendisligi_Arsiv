package com.kaansonmezoz.blm3520.notebook.Database.Repository.NoteInfo.AsyncTask;

import android.os.AsyncTask;

import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteInfoDao;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteInfo;

public class NoteInfoAsyncInsert extends AsyncTask<NoteInfo, Void, Long> {
    private NoteInfoDao noteInfoDao;

    public NoteInfoAsyncInsert(NoteInfoDao noteInfoDao){
        this.noteInfoDao = noteInfoDao;
    }

    @Override
    protected Long doInBackground(final NoteInfo... params) {
        return noteInfoDao.insertNoteInfo(params[0]);
    }
}
