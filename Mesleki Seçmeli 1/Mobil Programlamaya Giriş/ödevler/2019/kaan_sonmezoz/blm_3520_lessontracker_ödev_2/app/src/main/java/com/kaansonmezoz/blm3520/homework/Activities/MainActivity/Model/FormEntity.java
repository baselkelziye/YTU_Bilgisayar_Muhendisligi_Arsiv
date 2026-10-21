package com.kaansonmezoz.blm3520.homework.Activities.MainActivity.Model;

import android.graphics.drawable.Drawable;

public class FormEntity {
    private String birthDate;
    private String birthPlace;
    private String idNo;
    private String name;
    private String surname;
    private String phoneNumber;
    private Drawable image;
    private String imagePath;
    private String email;

    public FormEntity(){}

    public String getEmail(){
        return email;
    }

    public void setEmail(String email){
        this.email = email;
    }

    public String getImagePath(){
        return imagePath;
    }

    public void setImagePath(String imagePath){
        this.imagePath = imagePath;
    }

    public String getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(String birthDate) {
        this.birthDate = birthDate;
    }

    public String getBirthPlace() {
        return birthPlace;
    }

    public void setBirthPlace(String birthPlace) {
        this.birthPlace = birthPlace;
    }

    public String getIdNo() {
        return idNo;
    }

    public void setIdNo(String idNo) {
        this.idNo = idNo;
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

    public String getPhoneNumber(){
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber){
        this.phoneNumber = phoneNumber;
    }

    public Drawable getImage(){
        return image;
    }

    public void setImage(Drawable image){
        this.image = image;
    }
}
