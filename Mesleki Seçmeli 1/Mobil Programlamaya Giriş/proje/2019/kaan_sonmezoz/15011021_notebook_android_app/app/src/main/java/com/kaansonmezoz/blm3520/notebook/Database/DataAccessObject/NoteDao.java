package com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject;

import com.kaansonmezoz.blm3520.notebook.Database.Entity.Note;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteInfo;

import android.arch.lifecycle.LiveData;
import android.arch.persistence.room.Dao;
import android.arch.persistence.room.Insert;
import android.arch.persistence.room.OnConflictStrategy;
import android.arch.persistence.room.Query;

import java.util.List;


@Dao
public interface NoteDao {
    @Insert(onConflict = OnConflictStrategy.REPLACE)
    public long insertNote(Note note);

    @Insert(onConflict = OnConflictStrategy.REPLACE)
    public void insertNoteWithNoteInfo(Note note, NoteInfo noteInfo);

    @Query("SELECT * FROM note")
    public LiveData<List<Note>> getAllNotes();

    @Query("DELETE FROM note WHERE id = :noteId")
    public void deleteNoteById(long noteId);

    @Query("DELETE FROM note ")
    public void deleteAll();
}
