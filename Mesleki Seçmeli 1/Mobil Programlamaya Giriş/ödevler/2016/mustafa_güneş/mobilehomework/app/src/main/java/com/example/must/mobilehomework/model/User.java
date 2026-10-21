package com.example.must.mobilehomework.model;

/**
 * Created by must on 30.04.2016.
 */

//Kullanıcıları Modelleyen Sınıf
public class User {
    private String name;
    private String surname;
    private String userName;
    private String password;

    //constructor metotları
    public User(){

    }

    public User(String name, String surname, String userName, String password){
        this.name = name;
        this.surname = surname;
        this.password = password;
        this.userName = userName;
    }

    //getter-setter metotları
    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }
}
