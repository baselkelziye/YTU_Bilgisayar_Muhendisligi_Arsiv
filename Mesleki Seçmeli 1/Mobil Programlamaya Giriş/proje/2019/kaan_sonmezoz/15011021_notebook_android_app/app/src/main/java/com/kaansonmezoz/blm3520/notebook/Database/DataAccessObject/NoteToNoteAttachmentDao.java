package com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject;

import com.kaansonmezoz.blm3520.notebook.Database.RelationEntity.NoteToNoteAttachments;

import android.arch.persistence.room.Dao;
import android.arch.persistence.room.Query;


@Dao
public interface NoteToNoteAttachmentDao {
    @Query("SELECT * FROM note WHERE id = :noteId")
    public NoteToNoteAttachments getNoteAndAllAttachments(int noteId);
}
