package com.kaansonmezoz.blm3520.notebook.ViewModel;

import android.app.Application;
import android.arch.lifecycle.AndroidViewModel;
import android.arch.lifecycle.LiveData;

import com.kaansonmezoz.blm3520.notebook.Database.Entity.Note;
import com.kaansonmezoz.blm3520.notebook.Database.Repository.Note.NoteRepository;

import java.util.List;
import java.util.concurrent.ExecutionException;

public class NoteViewModel extends AndroidViewModel {
    private NoteRepository noteRepository;
    private LiveData<List<Note>> notes;

    public NoteViewModel(Application application){
        super(application);
        noteRepository = new NoteRepository(application);
        notes = noteRepository.getAllNotes();
    }

    public LiveData<List<Note>> getAllNotes(){
        return notes;
    }

    public Long insertNote(Note note) throws ExecutionException, InterruptedException{
        return noteRepository.insertNote(note);
    }
}
