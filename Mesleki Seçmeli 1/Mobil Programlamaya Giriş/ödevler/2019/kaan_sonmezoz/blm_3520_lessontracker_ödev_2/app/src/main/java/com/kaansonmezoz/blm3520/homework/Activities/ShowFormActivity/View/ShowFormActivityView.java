package com.kaansonmezoz.blm3520.homework.Activities.ShowFormActivity.View;

import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;

public class ShowFormActivityView {
    private ImageView profilePhoto;
    private EditText name;
    private EditText surname;
    private EditText idNumber;
    private EditText phoneNumber;
    private EditText birthDate;
    private EditText birthPlace;
    private ImageView phoneCallImage;
    private EditText emailAddress;
    private ImageView sendEmail;

    public ShowFormActivityView(){}

    public ImageView getSendEmail(){
        return sendEmail;
    }

    public void setSendEmail(ImageView sendEmail){
        this.sendEmail = sendEmail;
    }

    public EditText getEmailAddress(){
        return emailAddress;
    }

    public void setEmailAddress(EditText emailAddress){
        this.emailAddress = emailAddress;
    }

    public ImageView getPhoneCallImage(){
        return phoneCallImage;
    }

    public void setPhoneCallImage(View phoneCallImage){
        this.phoneCallImage = (ImageView) phoneCallImage;
    }

    public ImageView getProfilePhoto() {
        return profilePhoto;
    }

    public void setProfilePhoto(ImageView profilePhoto) {
        this.profilePhoto = profilePhoto;
    }

    public EditText getName() {
        return name;
    }

    public void setName(EditText name) {
        this.name = name;
    }

    public EditText getSurname() {
        return surname;
    }

    public void setSurname(EditText surname) {
        this.surname = surname;
    }

    public EditText getIdNumber() {
        return idNumber;
    }

    public void setIdNumber(EditText idNumber) {
        this.idNumber = idNumber;
    }

    public EditText getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(EditText phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public EditText getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(EditText birthDate) {
        this.birthDate = birthDate;
    }

    public EditText getBirthPlace() {
        return birthPlace;
    }

    public void setBirthPlace(EditText birthPlace) {
        this.birthPlace = birthPlace;
    }
}
