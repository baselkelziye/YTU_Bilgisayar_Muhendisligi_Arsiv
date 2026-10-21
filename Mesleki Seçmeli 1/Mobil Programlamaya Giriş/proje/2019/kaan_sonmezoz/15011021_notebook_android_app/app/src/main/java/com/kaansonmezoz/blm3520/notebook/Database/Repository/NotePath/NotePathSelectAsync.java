package com.kaansonmezoz.blm3520.notebook.Database.Repository.NotePath;

import android.os.AsyncTask;

import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteAttachmentDao;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteAttachment;

import java.util.List;

public class NotePathSelectAsync extends AsyncTask<Long, Void, List<NoteAttachment>> {
    private NoteAttachmentDao notePathDao;

    public NotePathSelectAsync(NoteAttachmentDao notePathDao){
        this.notePathDao = notePathDao;
    }

    @Override
    protected List<NoteAttachment> doInBackground(final Long ... params) {
        return notePathDao.getAllNoteAttachments(params[0]);
    }
}
