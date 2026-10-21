package com.yapps.mobilodev2

interface Repository {
    suspend fun getUser(email:String):User
}