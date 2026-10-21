package com.kaansonmezoz.blm3520.homework.Activities.MainActivity.View;

import android.support.design.widget.NavigationView;
import android.support.v4.widget.DrawerLayout;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;

public class MainActivityView {
    private ImageView addImageView;
    private Button submitButton;
    private Button clearAllButton;
    private EditText nameText;
    private EditText surnameText;
    private EditText idText;
    private EditText birthDateText;
    private EditText birthPlaceText;
    private EditText phoneNumberText;
    private NavigationView navigationView;
    private DrawerLayout drawerLayout;
    private EditText emailAddress;

    public MainActivityView(){

    }

    public EditText getEmailAddress(){
        return emailAddress;
    }

    public EditText getBirthDateText() {
        return birthDateText;
    }

    public ImageView getAddImageView() {
        return addImageView;
    }

    public Button getSubmitButton() {
        return submitButton;
    }

    public Button getClearAllButton() {
        return clearAllButton;
    }


    public EditText getNameText() {
        return nameText;
    }

    public EditText getSurnameText() {
        return surnameText;
    }

    public EditText getIdText() {
        return idText;
    }

    public EditText getBirthPlaceText() {
        return birthPlaceText;
    }

    public EditText getPhoneNumberText(){
        return phoneNumberText;
    }

    public NavigationView getNavigationView(){
        return  navigationView;
    }

    public DrawerLayout getDrawerLayout(){
        return drawerLayout;
    }

    public void setClearAllButton(View clearAllButton) {
        this.clearAllButton = (Button) clearAllButton;
    }

    public void setSurnameText(View surnameText) {
        this.surnameText = (EditText) surnameText;
    }

    public void setIdText(View idText) {
        this.idText = (EditText) idText;
    }


    public void setBirthDateText(View birthDateText) {
        this.birthDateText = (EditText) birthDateText;
    }

    public void setNameText(View nameText) {
        this.nameText = (EditText) nameText;
    }

    public void setBirthPlaceText(View birthPlaceText) {
        this.birthPlaceText = (EditText) birthPlaceText;
    }
    public void setAddImageView(View addImageView) {
        this.addImageView = (ImageView) addImageView;
    }

    public void setSubmitButton(View submitButton){
        this.submitButton = (Button) submitButton;
    }

    public void setPhoneNumberText(View phoneNumberText){
        this.phoneNumberText = (EditText) phoneNumberText;
    }

    public void setNavigationView(View navigationView){
        this.navigationView = (NavigationView) navigationView;
    }

    public void setDrawerLayout(View drawerLayout){
        this.drawerLayout = (DrawerLayout) drawerLayout;
    }

    public void setEmailAddress(View emailAddress){
        this.emailAddress = (EditText) emailAddress;
    }
}
