package com.kaansonmezoz.blm3520.notebook.Database.Repository.NoteToNoteInfo.AsyncTask;

import android.os.AsyncTask;

import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteToNoteInfoDao;
import com.kaansonmezoz.blm3520.notebook.Database.RelationEntity.NoteToNoteInfo;

public class NoteToNoteInfoAsyncSelect extends AsyncTask<Long,Void, NoteToNoteInfo> {
    private NoteToNoteInfoDao noteToNoteInfoDao;

    public NoteToNoteInfoAsyncSelect (NoteToNoteInfoDao noteToNoteInfoDao){
        this.noteToNoteInfoDao = noteToNoteInfoDao;
    }

    @Override
    protected NoteToNoteInfo doInBackground(final Long ... params) {
        return noteToNoteInfoDao.getNoteWithInfoByNoteId(params[0]);
    }
}
