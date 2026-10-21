package com.example.androidodev;

import java.util.ArrayList;

public class User {

    private String username;
    private String password;
    private int imageID;


    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public int getImageID() { return imageID; }

    public void setImageID(int imageID) {
        this.imageID = imageID;
    }

    public static ArrayList<User> getData() {
        ArrayList<User> userList = new ArrayList<User>();
        String userNameArray[] = {"amacguvensan","huseynvaliyev","alvinmammadli","natigaghayev","khaganikhankishiyev"};
        String passwordArray[] = {"amacguvensan123","huseynvaliyev123","alvinmammadli123","natigaghayev123","khaganikhankishiyev123"};
        int imageArray[] ={R.drawable.random,R.drawable.random,R.drawable.random,R.drawable.random,R.drawable.random};

        for(int i=0;i<userNameArray.length;i++){
            User tempUser = new User();
            tempUser.setUsername(userNameArray[i]);
            tempUser.setPassword(passwordArray[i]);
            tempUser.setImageID(imageArray[i]);
            userList.add(tempUser);
        }

        return userList;
    }

}
