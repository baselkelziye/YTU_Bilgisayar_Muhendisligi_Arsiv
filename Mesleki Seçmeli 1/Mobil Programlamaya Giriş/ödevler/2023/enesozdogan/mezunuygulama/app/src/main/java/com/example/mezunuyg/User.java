package com.example.mezunuyg;

public class User {
    private String id;
    private String username;
    private String imageURL;

    private String year;

    private String phone;
    private String Company;
    private String Education;
    private String   city;
    // Constructors;
    public User() {
    }

    public User(String id, String username, String imageURL, String year, String phoneNo, String company, String education, String city) {
        this.id = id;
        this.username = username;
        this.imageURL = imageURL;
        this.year = year;
        this.phone = phoneNo;
        this.Company = company;
        this.Education = education;
        this.city = city;
    }

    public String getYear() {
        return year;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String getCompany() {
        return Company;
    }

    public void setCompany(String company) {
        this.Company = company;
    }

    public String getEducation() {
        return Education;
    }

    public void setEducation(String education) {
        this.Education = education;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public void setYear(String year) {
        this.year = year;
    }
// Getters and Setters

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


}
