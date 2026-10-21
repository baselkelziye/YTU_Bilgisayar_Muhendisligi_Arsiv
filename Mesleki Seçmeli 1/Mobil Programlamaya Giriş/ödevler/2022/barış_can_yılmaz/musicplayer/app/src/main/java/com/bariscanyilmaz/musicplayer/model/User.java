package com.bariscanyilmaz.musicplayer.model;

import androidx.room.ColumnInfo;
import androidx.room.Entity;
import androidx.room.PrimaryKey;

@Entity
public class User {

    @PrimaryKey(autoGenerate = true)
    public int id;

    @ColumnInfo(name = "email")
    public String email;

    @ColumnInfo(name = "password")
    public String password;

    @ColumnInfo(name = "fullname")
    public String fullname;


    public User(String email,String password,String fullname){
        this.email=email;
        this.password=password;
        this.fullname=fullname;
    }

    public boolean checkPassword(String password){
        return this.password.equals(password);
    }
}
