package com.kaansonmezoz.blm3520.notebook.Database.Repository.NoteInfo.AsyncTask;

import android.os.AsyncTask;

import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteInfoDao;
import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteToNoteInfoDao;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteInfo;
import com.kaansonmezoz.blm3520.notebook.Database.RelationEntity.NoteToNoteInfo;

public class NoteInfoAsyncSelect extends AsyncTask<Long,Void, NoteInfo> {
    private NoteInfoDao noteInfoDao;

    public NoteInfoAsyncSelect(NoteInfoDao noteInfoDao){
        this.noteInfoDao = noteInfoDao;
    }

    @Override
    protected NoteInfo doInBackground(final Long ... params) {
        return noteInfoDao.getNoteInfoById(params[0]);
    }
}
