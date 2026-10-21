package org.example;

public class Users {
    private int userID;
    private String userName;
    private String email;
    private String password;

    public Users(String userName, String email, String password) {
        if (userName == null || userName.trim().isEmpty()) {
            throw new IllegalArgumentException("Kullanıcı adı boş bırakılamaz.");
        }
        if (email == null || !isValidEmail(email)) {
            throw new IllegalArgumentException("Geçerli bir email adresi girilmelidir.");
        }
        if (password == null || password.length() < 6) {
            throw new IllegalArgumentException("Şifre en az 6 karakter olmalıdır.");
        }
        this.userName = userName;
        this.email = email;
        this.password = password;
    }

    public int getUserID() {
        return userID;
    }

    public void setUserID(int userID) {
        this.userID = userID;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        if (userName == null || userName.trim().isEmpty()) {
            throw new IllegalArgumentException("Kullanıcı adı boş bırakılamaz.");
        }
        this.userName = userName;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        if (email == null || !isValidEmail(email)) {
            throw new IllegalArgumentException("Geçerli bir email adresi girilmelidir.");
        }
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        if (password == null || password.length() < 6) {
            throw new IllegalArgumentException("Şifre en az 6 karakter olmalıdır.");
        }
        this.password = password;
    }

    private boolean isValidEmail(String email) {
        return email.matches("^[A-Za-z0-9+_.-]+@(.+)$");
    }
}
