package org.example.forms;

import org.example.Models.Users;

public class UserSession {
    private static int userId;
    private static Users user;
    private static boolean isAdmin;


    public static void setSession(int userId, Users user, boolean isAdmin) {
        UserSession.userId = userId;
        UserSession.user = user;
        UserSession.isAdmin = isAdmin;
    }

    public static boolean isLoggedIn() {
        return user != null;
    }

    public static void logout() {
        user = null;
        isAdmin = false;
    }

    public static int getUserID() {
        return userId;
    }

    public static String getUserName() {
        return user.getUserName();
    }

    public static String getEmail() {
        return user.getEmail();
    }

    public static String getPassword() {
        return user.getPassword();
    }

    public static boolean isAdmin() {
        return isAdmin;
    }

    public static void setAdmin(boolean isAdmin) {
        UserSession.isAdmin = isAdmin;
    }

    public static void setUserName(String userName) {
        UserSession.user.setUserName(userName);
    }

    public static void setEmail(String email) {
        UserSession.user.setEmail(email);
    }

    public static void setPassword(String password) {
        UserSession.user.setPassword(password);
    }

    public static void setUserID(int userId) {
        UserSession.userId = userId;
    }


}
