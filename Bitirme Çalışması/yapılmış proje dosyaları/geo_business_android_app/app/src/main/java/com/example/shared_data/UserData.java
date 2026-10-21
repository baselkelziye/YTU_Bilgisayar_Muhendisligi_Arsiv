package com.example.shared_data;

import com.example.models.User;

public class UserData {
    private static UserData instance;
    private User userData;

    private UserData() {}

    public static UserData getInstance() {
        if (instance == null) {
            instance = new UserData();
        }
        return instance;
    }

    public User getSharedData() {
        return userData;
    }

    public void setSharedData(User userData) {
        this.userData = userData;
    }
}
