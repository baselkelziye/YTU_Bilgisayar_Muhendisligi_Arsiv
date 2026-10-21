package com.kaansonmezoz.blm3520.notebook.ViewModel;

import android.app.Application;
import android.arch.lifecycle.AndroidViewModel;

import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteInfo;
import com.kaansonmezoz.blm3520.notebook.Database.Repository.NoteInfo.NoteInfoRepository;

import java.util.concurrent.ExecutionException;

public class NoteInfoViewModel extends AndroidViewModel {
    private NoteInfoRepository noteInfoRepository;

    public NoteInfoViewModel(Application application){
        super(application);
        noteInfoRepository = new NoteInfoRepository(application);
    }

    public NoteInfo getNoteInfoById(long id) throws ExecutionException, InterruptedException {
        return noteInfoRepository.getNoteInfoById(id);
    }

    public Long insertNote(NoteInfo noteInfo) throws ExecutionException, InterruptedException{
        return noteInfoRepository.insertNote(noteInfo);
    }
}
