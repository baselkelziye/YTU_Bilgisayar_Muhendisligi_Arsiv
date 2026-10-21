package com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject;

import android.arch.persistence.room.Dao;
import android.arch.persistence.room.Insert;
import android.arch.persistence.room.Query;

import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteAttachment;

import java.util.List;

@Dao
public interface NoteAttachmentDao {
    @Insert
    public long insertNoteAttachment(NoteAttachment attachment);

    @Query("SELECT * FROM note_attachment WHERE note_id = :noteId")
    public List<NoteAttachment> getAllNoteAttachments(long noteId);
}
