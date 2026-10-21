package com.yapps.mobilodev2

import android.app.Application
import android.content.Context
import androidx.room.Room

class ThisApplication:Application() {

    companion object{
        lateinit var userDao:UserDao
        lateinit var sharedPrefs: SharedPrefs
    }

    override fun onCreate() {
        super.onCreate()

        val db = Room.databaseBuilder(applicationContext,UserDatabase::class.java,"user_database").build()
        userDao = db.userDao()

        sharedPrefs = SharedPrefs(this)
    }

}