package com.kaansonmezoz.blm3520.notebook.Database.Repository.Note.AsyncTask;

import android.os.AsyncTask;
import android.util.Log;

import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteDao;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.Note;

public class NoteAsyncInsert extends AsyncTask<Note, Void, Long> {
    private NoteDao noteDao;

    public NoteAsyncInsert(NoteDao noteDao){
        this.noteDao = noteDao;
    }

    @Override
    protected Long doInBackground(final Note... params) {
        return noteDao.insertNote(params[0]);
    }

    /*  UI threadin'den farkli bir thread de run ediliyor dolayısıyla buradaki itemInserted'taki degisiklik yapilmasi
        UI threadindeki nesnede bir degisiklige neden olmuyor
    @Override
    protected void onPostExecute(Long id){
        Log.d("Insert", "onPostExecute id: " + id);
        itemInserted.id = id;
        Log.d("Insert", "onPostExecute id: " + itemInserted.id);
    }
    */
}
