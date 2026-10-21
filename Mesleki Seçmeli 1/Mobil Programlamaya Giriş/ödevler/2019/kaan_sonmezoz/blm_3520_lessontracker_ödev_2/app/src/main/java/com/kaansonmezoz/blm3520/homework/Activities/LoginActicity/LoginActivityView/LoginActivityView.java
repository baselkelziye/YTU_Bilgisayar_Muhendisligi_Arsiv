package com.kaansonmezoz.blm3520.homework.Activities.LoginActicity.LoginActivityView;

import android.widget.Button;
import android.widget.EditText;

public class LoginActivityView {
    private EditText email;
    private EditText password;
    private Button sigIn;

    public EditText getEmail() {
        return email;
    }

    public void setEmail(EditText email) {
        this.email = email;
    }

    public EditText getPassword() {
        return password;
    }

    public void setPassword(EditText password) {
        this.password = password;
    }

    public Button getSigIn() {
        return sigIn;
    }

    public void setSigIn(Button sigIn) {
        this.sigIn = sigIn;
    }
}
