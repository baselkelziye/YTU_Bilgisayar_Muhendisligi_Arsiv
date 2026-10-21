package ce.yildiz.android.models;

import androidx.annotation.NonNull;

@SuppressWarnings("unused")
public class User {
    private String username;
    private String email;
    private String password;
    private String imageURL;

    public User() {

    }

    public User(String username, String email, String password, String imageURL) {
        this.username = username;
        this.email = email;
        this.password = password;
        this.imageURL = imageURL;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
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

    public String getImageURL() {
        return imageURL;
    }

    public void setImageURL(String imageURL) {
        this.imageURL = imageURL;
    }

    @NonNull
    @Override
    public String toString() {
        return "User = { username: " + username + "\nemail: " + email
                + "\npassword: " + password + "\nimageURL: " + imageURL + " }";
    }
}
