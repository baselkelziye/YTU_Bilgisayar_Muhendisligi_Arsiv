package com.example.sefagokceoglu.model;

import java.util.ArrayList;
import java.util.List;

public class Users {

    public static List<User> userList = new ArrayList<>();

    public static List<User>  getUsers() {
        userList.add(new User("Sefa","Gokce","05378128783","sefa@gmail.com","123456","123456",null));

        return userList;
    }

    public static String register(User registedUser) {
        Boolean sameEmail = false;
        for(User user :userList) {
            if(user.getEmail().equals(user.getEmail())) {
                sameEmail = true;
            }
        }
        if(sameEmail) {
            return "Email Taken";
        }
        if(!registedUser.getPassword().equals(registedUser.getVerifyPassword())) {
            return "Passwords does not match";
        }
        if(!registedUser.getEmail().contains("@")) {
            return "Email Invalid";
        }
        userList.add(registedUser);
        return "Registered";
    }

    public static String login(String email,String password) {
        User foundUser = null;
        for(User user :getUsers()) {
            if(user.getEmail().equals(user.getEmail())) {
                foundUser = user;
            }
        }
        if(foundUser == null) {
            return "User Not Found";
        }
        if(!foundUser.getPassword().equals(password)) {
            return "Password Wrong";
        }

        return "Success";
    }


}
