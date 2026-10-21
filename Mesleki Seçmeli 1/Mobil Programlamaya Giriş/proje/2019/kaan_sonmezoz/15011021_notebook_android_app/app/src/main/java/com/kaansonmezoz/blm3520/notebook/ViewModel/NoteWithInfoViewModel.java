package com.kaansonmezoz.blm3520.notebook.ViewModel;

import com.kaansonmezoz.blm3520.notebook.Database.Entity.Note;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteInfo;

public class NoteWithInfoViewModel {
    private Note note;
    private NoteInfo noteInfo;

    public NoteWithInfoViewModel(Note note) {
        this.note = note;
    }

    public Note getNote() {
        return note;
    }

    public void setNote(Note note) {
        this.note = note;
    }

    public NoteInfo getNoteInfo() {
        return noteInfo;
    }

    public void setNoteInfo(NoteInfo noteInfo) {
        this.noteInfo = noteInfo;
    }
}
