package com.yapps.mobilodev2

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.launch

class UserViewModel(private val userId:Long,private val userDao: UserDao):ViewModel() {
    private val _user:MutableLiveData<User> = MutableLiveData()
    val user:LiveData<User>
        get() = _user

    init {
        viewModelScope.launch {
            _user.value = userDao.getUserWithId(userId)
        }
    }

    private val _updateMessage:MutableLiveData<String> = MutableLiveData()
    val updateMessage:LiveData<String>
        get() = _updateMessage

    fun updateUser(
        name:String,
        surname:String,
        studentNumber:String,
        email:String,
        password:String,
        social:String,
        imagePath:String,
        education:Int,
        phone:String) {
        if (name == "") {
            _updateMessage.value = "Name field is empty!"
            return
        }
        if (surname == "") {
            _updateMessage.value = "Surname field is empty!"
            return
        }
        if (studentNumber == "") {
            _updateMessage.value = "Student Number field is empty!"
            return
        }
        if (email == "") {
            _updateMessage.value = "Email field is empty!"
            return
        }
        val type = controlEmail(email)
        if (type == "error") {
            _updateMessage.value = "YTU email is required!"
            return
        }
        viewModelScope.launch {
            user.value?.type = type
            user.value?.name = name
            user.value?.surname = surname
            user.value?.studentId = studentNumber
            user.value?.email = email
            user.value?.password = password
            user.value?.instagram = social
            user.value?.education = education
            user.value?.imagePath = imagePath
            user.value?.phone = phone
            userDao.update(user.value!!)
            _updateMessage.value = "Update Successful"
        }
    }

    fun deleteAccount(){
        viewModelScope.launch {
            userDao.delete(_user.value!!)
            _user.value = userDao.getUserWithId(userId)
        }
    }

    private fun controlEmail(email:String):String{
        if(email.contains("@std.yildiz.edu.tr")) return "student"
        if(email.contains("@yildiz.edu.tr")) return "instructor"
        return "error"
    }
}

class UserViewModelFactory(val userID:Long): ViewModelProvider.Factory{
    override fun <T : ViewModel> create(modelClass: Class<T>): T {
        if(modelClass.isAssignableFrom(UserViewModel::class.java)){
            return UserViewModel(userID,ThisApplication.userDao) as T
        }
        throw IllegalArgumentException("Unknown ViewModel")
    }
}