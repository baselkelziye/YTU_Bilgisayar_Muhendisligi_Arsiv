package com.kaansonmezoz.blm3520.notebook.Database.RelationEntity;

import android.arch.persistence.room.Embedded;
import android.arch.persistence.room.Relation;

import com.kaansonmezoz.blm3520.notebook.Database.Entity.Note;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteAttachment;

import java.util.List;

public class NoteToNoteAttachments {
    @Embedded
    public Note note;

    @Relation(parentColumn = "id", entityColumn = "note_id", entity = NoteAttachment.class)
    public List<NoteAttachment> attachments;
}
