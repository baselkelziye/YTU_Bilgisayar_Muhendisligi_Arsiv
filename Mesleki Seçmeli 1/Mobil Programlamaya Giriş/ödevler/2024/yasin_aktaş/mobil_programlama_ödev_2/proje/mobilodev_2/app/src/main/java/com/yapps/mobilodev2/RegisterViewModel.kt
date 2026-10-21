package com.yapps.mobilodev2

import android.app.Application
import android.content.Context
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.launch

class RegisterViewModel(private val userDao: UserDao):ViewModel() {

    private val _registerMessage:MutableLiveData<String> = MutableLiveData()
    val registerMessage:LiveData<String>
        get() = _registerMessage

    private val _registerResult:MutableLiveData<Boolean> = MutableLiveData()
    val registerResult:LiveData<Boolean>
        get() = _registerResult

    fun registerUser(
        name:String,
        surname:String,
        studentNumber:String,
        email:String,
        password:String,
        passwordAgain:String){
        if(name == ""){
            _registerMessage.value = "Name field is empty!"
            return
        }
        if(surname == ""){
            _registerMessage.value = "Surname field is empty!"
            return
        }
        if(studentNumber == ""){
            _registerMessage.value = "Student Number field is empty!"
            return
        }
        if(email == ""){
            _registerMessage.value = "Email field is empty!"
            return
        }
        if(password == "" || passwordAgain == ""){
            _registerMessage.value = "Password field is empty!"
            return
        }
        if(password != passwordAgain){
            _registerMessage.value = "Passwords do not match!"
            return
        }
        val type = controlEmail(email)
        if(type == "error"){
            _registerMessage.value = "YTU email is required!"
            return
        }
        viewModelScope.launch {
            val user:User = User(type=type,name=name,surname=surname, studentId = studentNumber, email = email, password = password)
            userDao.insert(user)
            _registerMessage.value = "Register Successful"
            _registerResult.value = true
        }
    }

    private fun controlEmail(email:String):String{
        if(email.contains("@std.yildiz.edu.tr")) return "student"
        if(email.contains("@yildiz.edu.tr")) return "instructor"
        return "error"
    }

}

class RegisterViewModelFactory(): ViewModelProvider.Factory{
    override fun <T : ViewModel> create(modelClass: Class<T>): T {
        if(modelClass.isAssignableFrom(RegisterViewModel::class.java)){
            return RegisterViewModel(ThisApplication.userDao) as T
        }
        throw IllegalArgumentException("Unknown ViewModel")
    }
}