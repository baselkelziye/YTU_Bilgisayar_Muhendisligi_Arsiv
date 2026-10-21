package com.kaansonmezoz.blm3520.notebook.Database;

import android.arch.persistence.db.SupportSQLiteDatabase;
import android.arch.persistence.room.Database;
import android.arch.persistence.room.Room;
import android.arch.persistence.room.RoomDatabase;
import android.content.Context;
import android.support.annotation.NonNull;

import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteAttachmentDao;
import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteDao;
import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteInfoDao;
import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteToNoteAttachmentDao;
import com.kaansonmezoz.blm3520.notebook.Database.DataAccessObject.NoteToNoteInfoDao;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.Note;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteAttachment;
import com.kaansonmezoz.blm3520.notebook.Database.Entity.NoteInfo;



@Database(entities = {Note.class, NoteAttachment.class, NoteInfo.class}, version = 1)
public abstract class AppDatabase extends RoomDatabase {
    private static volatile  AppDatabase database;

    private static RoomDatabase.Callback initDbCallback = new RoomDatabase.Callback(){
        @Override
        public void onOpen(@NonNull SupportSQLiteDatabase db){
            super.onOpen(db);
            new PopulateDbAsync(database).execute();
        }
    };

    public abstract NoteDao noteDao();
    public abstract NoteInfoDao noteInfoDao();
    public abstract NoteAttachmentDao noteAttachmentDao();
    public abstract NoteToNoteAttachmentDao noteToNoteAttachmentDao();
    public abstract NoteToNoteInfoDao noteToNoteInfoDao();

    public static AppDatabase getDatabase(Context context){
        if(database == null){
            synchronized (AppDatabase.class){
                database = Room.databaseBuilder(context, AppDatabase.class, "notebook-database")
                        .addCallback(initDbCallback).build();
            }
        }

        return database;
    }

}
