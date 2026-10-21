package com.yapps.mobilodev2

import android.content.Context
import android.content.SharedPreferences

class SharedPrefs(private val context: Context) {

    private var sharedPreferences: SharedPreferences = context.getSharedPreferences("PREFERENCES",Context.MODE_PRIVATE)
    private var editor = sharedPreferences.edit()

    fun getRememberedUserId():Long{
        return sharedPreferences.getLong("rememberedID",-1)
    }


    fun setRememberedUser(userId:Long){
        editor.putLong("rememberedID",userId)
        editor.commit()
    }

    fun getRemember():Boolean{
        return sharedPreferences.getBoolean("remember",false)
    }

    fun setRemember(value: Boolean){
        editor.putBoolean("remember",value)
        editor.commit()
    }

}