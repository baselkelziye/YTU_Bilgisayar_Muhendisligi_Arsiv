package com.example.roommateproject;

public class User {

    private String id;
    private String username;
    private String imageURL;
    private String phone;
    private String grade;
    private String department;
    private String duration;
    private String mail;
    private String status;
    private String distance;
    public User(){

    }

    public User(String id, String username, String imageURL, String phone, String grade, String department, String duration, String mail,String status,String distance) {
        this.id = id;
        this.username = username;
        this.imageURL = imageURL;
        this.phone = phone;
        this.grade = grade;
        this.department = department;
        this.duration = duration;
        this.mail = mail;
        this.status=status;
        this.distance=distance;
    }

    public String getDuration() {
        return duration;
    }

    public void setDuration(String duration) {
        this.duration = duration;
    }

    public String getDistance() {
        return distance;
    }

    public void setDistance(String distance) {
        this.distance = distance;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getImageURL() {
        return imageURL;
    }

    public void setImageURL(String imageURL) {
        this.imageURL = imageURL;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String getGrade() {
        return grade;
    }

    public void setGrade(String grade) {
        this.grade = grade;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }



    public String getMail() {
        return mail;
    }

    public void setMail(String mail) {
        this.mail = mail;
    }
}
