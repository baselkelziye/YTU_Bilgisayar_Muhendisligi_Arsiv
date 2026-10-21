package com.bariscanyilmaz.musicplayer.roomdb;

import androidx.room.Dao;
import androidx.room.Insert;
import androidx.room.Query;

import com.bariscanyilmaz.musicplayer.model.User;

@Dao
public interface UserDao {

    @Insert
    void insert(User user);

    @Query("SELECT * FROM  User where user.email=:email")
    User getUserByEmail(String email);

}
