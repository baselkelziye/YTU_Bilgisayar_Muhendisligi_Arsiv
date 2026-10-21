package com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject;

import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteInfo;

import android.arch.persistence.room.Dao;
import android.arch.persistence.room.Insert;
import android.arch.persistence.room.Query;


@Dao
public interface NoteInfoDao {
    @Insert
    public long insertNoteInfo(NoteInfo noteInfo);

    @Query("SELECT * FROM note_info WHERE  id = :noteId")
    public NoteInfo getNoteInfoById(long noteId);

    @Query("DELETE FROM note_info WHERE id = :noteInfoId")
    public void deleteNoteInfoById(long noteInfoId);
}
