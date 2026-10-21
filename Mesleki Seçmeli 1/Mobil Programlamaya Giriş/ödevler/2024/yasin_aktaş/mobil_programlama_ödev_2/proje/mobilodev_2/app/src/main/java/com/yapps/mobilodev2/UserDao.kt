package com.yapps.mobilodev2

import androidx.lifecycle.LiveData
import androidx.room.Dao
import androidx.room.Delete
import androidx.room.Insert
import androidx.room.Query
import androidx.room.Update

@Dao
interface UserDao {
    @Insert
    suspend fun insert(user:User)

    @Update
    suspend fun update(user:User)

    @Delete
    suspend fun delete(user:User)

    @Query("SELECT * FROM user_table WHERE email =:email AND password =:password")
    suspend fun getUser(email:String,password:String):User

    @Query("SELECT * FROM user_table WHERE id =:id")
    suspend fun getUserWithId(id:Long):User

}