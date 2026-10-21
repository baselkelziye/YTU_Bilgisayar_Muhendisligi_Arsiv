package com.yapps.mobilodev2

import android.content.Context
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.launch

class MainViewModel(private val userDao:UserDao,private val sharedPrefs: SharedPrefs):ViewModel() {
    private val _user:MutableLiveData<User> = MutableLiveData()
    val user:LiveData<User>
        get() = _user

    private val _forwardUserActivity:MutableLiveData<Long> = MutableLiveData()
    val forwardUserActivity:LiveData<Long>
        get() = _forwardUserActivity

    private val _forwardAdminActivity:MutableLiveData<Boolean> = MutableLiveData()
    val forwardAdminActivity:LiveData<Boolean>
        get() = _forwardAdminActivity

    private val _forwardRegisterActivity:MutableLiveData<Boolean> = MutableLiveData()
    val forwardRegisterActivity:LiveData<Boolean>
        get() = _forwardRegisterActivity

    private val _loginMessage:MutableLiveData<String> = MutableLiveData()
    val loginMessage:LiveData<String>
        get() = _loginMessage

    init {
       if(sharedPrefs.getRemember()){
           _forwardUserActivity.value = sharedPrefs.getRememberedUserId()
       }
    }

    fun login(email:String,password:String){
        if(email == "admin" && password == "admin"){
            forwardAdminActivity()
        }else{
            viewModelScope.launch {
                _user.value = userDao.getUser(email,password)
            }
        }
    }


    private fun forwardAdminActivity(){
        _loginMessage.value = "Admin Login"
        _forwardAdminActivity.value = true
    }

    fun forwardUserActivity(userId:Long,isRemember: Boolean){
        _loginMessage.value = "Successful Login"
        sharedPrefs.setRemember(isRemember)
        sharedPrefs.setRememberedUser(userId)
        _forwardUserActivity.value = userId
    }

    fun forwardUserError(){
        _loginMessage.value = "Login Error"
    }

    fun forwardRegisterActivity(){
        _forwardRegisterActivity.value = true
    }

}

class MainViewModelFactory(val context: Context):ViewModelProvider.Factory{
    override fun <T : ViewModel> create(modelClass: Class<T>): T {
        if(modelClass.isAssignableFrom(MainViewModel::class.java)){
            return MainViewModel(ThisApplication.userDao,ThisApplication.sharedPrefs) as T
        }
        throw IllegalArgumentException("Unknown ViewModel")
    }
}