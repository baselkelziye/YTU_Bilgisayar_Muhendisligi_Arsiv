package com.example.sefagokceoglu.model;

import android.net.Uri;

public class User {

    private String name;

    private String lastname;

    private String phone;

    private String email;

    private String password;

    private String verifyPassword;

    private Uri uri;

    public User(String name, String lastname, String phone, String email, String password, String verifyPassword, Uri uri) {
        this.name = name;
        this.lastname = lastname;
        this.phone = phone;
        this.email = email;
        this.password = password;
        this.verifyPassword = verifyPassword;
        this.uri = uri;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLastname() {
        return lastname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public Uri getUri() {
        return uri;
    }

    public void setUri(Uri uri) {
        this.uri = uri;
    }

    public String getVerifyPassword() {
        return verifyPassword;
    }

    public void setVerifyPassword(String verifyPassword) {
        this.verifyPassword = verifyPassword;
    }
}
