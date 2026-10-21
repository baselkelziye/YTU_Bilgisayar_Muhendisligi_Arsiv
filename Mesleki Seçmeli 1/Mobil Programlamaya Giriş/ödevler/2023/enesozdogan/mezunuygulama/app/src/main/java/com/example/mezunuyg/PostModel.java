package com.example.mezunuyg;


import com.google.firebase.Timestamp;

public class PostModel {
    private String title;
    private String duyuru;
    private String imgUrl;

    private String userId;

    private String userName;

    public PostModel() {

    }

    public PostModel(String title, String duyuru, String imgUrl, String userId, String userName) {
        this.title = title;
        this.duyuru = duyuru;
        this.imgUrl = imgUrl;
        this.userId = userId;

        this.userName = userName;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDuyuru() {
        return duyuru;
    }

    public void setDuyuru(String duyuru) {
        this.duyuru = duyuru;
    }

    public String getImgUrl() {
        return imgUrl;
    }

    public void setImgUrl(String imgUrl) {
        this.imgUrl = imgUrl;
    }

    public String getUserId() {
        return userId;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }



    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }
}
