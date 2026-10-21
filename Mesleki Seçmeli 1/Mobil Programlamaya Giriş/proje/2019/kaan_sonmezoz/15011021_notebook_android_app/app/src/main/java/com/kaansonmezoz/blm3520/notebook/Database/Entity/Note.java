package com.kaansonmezoz.blm3520.notebook.Database.Entity;

import android.arch.persistence.room.ColumnInfo;
import android.arch.persistence.room.Entity;
import android.arch.persistence.room.Ignore;
import android.arch.persistence.room.PrimaryKey;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;

@Entity(tableName = "note")
public class Note {
    @ColumnInfo(name = "id")
    @PrimaryKey(autoGenerate = true)
    public long id;

    @ColumnInfo(name = "title")
    @NonNull
    public String title;

    @ColumnInfo(name = "note_file_path")
    @Nullable
    public String notePath;

    @ColumnInfo(name = "priority")
    public String priority = "MEDIUM";

    @ColumnInfo(name = "note_info_id")
    public long noteInfoId;

    public Note(String title, String priority, long noteInfoId){
        this.title = title;
        this.priority = priority;
        this.noteInfoId = noteInfoId;
    }

    @Ignore
    public Note(String title, String priority){
        this.title = title;
        this.priority = priority;
    }
}
