package com.bariscanyilmaz.musicplayer.roomdb;

import androidx.room.Dao;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import com.bariscanyilmaz.musicplayer.model.PlayList;

import java.util.List;

@Dao
public interface PlayListDao {

    @Insert
    void insert(PlayList list);

    @Query("SELECT * FROM PlayList")
    List<PlayList> getAll();

    @Query("SELECT * FROM PlayList WHERE PlayList.id=:id")
    PlayList getById(int id);

    @Update
    void update(PlayList entity);

}
