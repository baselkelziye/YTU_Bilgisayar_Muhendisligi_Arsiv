package com.yapps.mobilodev2

import androidx.room.ColumnInfo
import androidx.room.Entity
import androidx.room.PrimaryKey

@Entity(tableName = "user_table")
data class User(
    @PrimaryKey(autoGenerate = true)
    val id:Long = 0L,
    @ColumnInfo(name = "type")
    var type:String,
    @ColumnInfo(name = "name")
    var name:String,
    @ColumnInfo(name = "surname")
    var surname:String,
    @ColumnInfo(name = "email")
    var email:String,
    @ColumnInfo(name = "studentId")
    var studentId:String,
    @ColumnInfo(name = "password")
    var password:String,
    @ColumnInfo(name = "image")
    var imagePath:String = "",
    @ColumnInfo(name = "phone")
    var phone:String = "",
    @ColumnInfo(name = "education")
    var education:Int = 0,
    @ColumnInfo(name = "instagram")
    var instagram:String = ""
)