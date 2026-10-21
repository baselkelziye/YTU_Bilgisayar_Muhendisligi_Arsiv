package com.ohk.calendar101;

import  androidx.room.Database;
import  androidx.room.Room;
import  androidx.room.RoomDatabase;
import android.content.Context;

@Database(entities = {Event.class}, version = 1, exportSchema = false)
public abstract class RepoDatabase extends RoomDatabase {
    private static final String DB_NAME = "b.db";
    private static volatile  RepoDatabase instance;

    static synchronized RepoDatabase getInstance(Context context){
        if(instance == null){
            instance = create(context);
        }
        System.out.println(instance);
        return instance;
    }

    private static RepoDatabase create(final Context context){
        return Room.databaseBuilder(
                context,
                RepoDatabase.class,
                DB_NAME).allowMainThreadQueries().build();
    }

    public abstract EventDao EventDao();
}
