package com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject;

import com.kaansonmezoz.blm3520.notebook.Database.RelationEntity.NoteToNoteInfo;

import android.arch.lifecycle.LiveData;
import android.arch.persistence.room.Dao;
import android.arch.persistence.room.Query;

import java.util.List;

@Dao
public interface NoteToNoteInfoDao {
    @Query("SELECT * FROM NOTE WHERE id = :id")
    public NoteToNoteInfo getNoteWithInfoByNoteId(long id);

    @Query("SELECT * FROM NOTE N, NOTE_INFO NI WHERE NI.id = N.note_info_id ORDER BY NI.last_updated_date DESC")
    public LiveData<List<NoteToNoteInfo>> getAllNotesWithNoteInfo();
}
