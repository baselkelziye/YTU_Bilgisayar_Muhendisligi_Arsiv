package com.kaansonmezoz.blm3520.notebook.Database.Repository.NotePath;

import android.os.AsyncTask;

import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteAttachmentDao;
import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteInfoDao;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteAttachment;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteInfo;

public class NotePathInsertAsync extends AsyncTask<NoteAttachment, Void, Long> {
    private NoteAttachmentDao notePathDao;

    public NotePathInsertAsync(NoteAttachmentDao notePathDao){
        this.notePathDao = notePathDao;
    }

    @Override
    protected Long doInBackground(final NoteAttachment... params) {
        return notePathDao.insertNoteAttachment(params[0]);
    }}
