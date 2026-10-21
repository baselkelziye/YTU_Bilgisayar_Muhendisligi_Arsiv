package com.kaansonmezoz.blm3520.notebook.Database.Entity;

import java.util.Date;

import android.arch.persistence.room.ColumnInfo;
import android.arch.persistence.room.Entity;
import android.arch.persistence.room.PrimaryKey;
import android.arch.persistence.room.TypeConverters;
import android.support.annotation.NonNull;

import com.kaansonmezoz.blm3520.notebook.Database.Converter.DateConverter;

@Entity(tableName = "note_info")
@TypeConverters(DateConverter.class)
public class NoteInfo {
    @ColumnInfo(name = "id")
    @PrimaryKey(autoGenerate = true)
    public long id;

    @ColumnInfo(name = "creation_time")
    @NonNull
    public Date creationTime;

    @ColumnInfo(name = "last_updated_date")
    @NonNull
    public Date lastUpdatedDate;

    @ColumnInfo(name = "color")
    @NonNull
    public String color = "#FFFF33";

    public NoteInfo(Date creationTime, Date lastUpdatedDate, String color){
        this.creationTime = creationTime;
        this.lastUpdatedDate = lastUpdatedDate;

        if(color != null){
            this.color = color;
        }
    }
}
