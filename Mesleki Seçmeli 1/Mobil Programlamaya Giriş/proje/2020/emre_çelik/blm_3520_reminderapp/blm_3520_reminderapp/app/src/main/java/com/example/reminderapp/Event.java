package com.example.reminderapp;

public class Event {
    private int id;
    private String title, description, startDay, startHour, endDay, endHour;
    private String frequence;
    private double latitude, longitude;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getStartDay() {
        return startDay;
    }

    public void setStartDay(String startDay) {
        this.startDay = startDay;
    }

    public String getStartHour() {
        return startHour;
    }

    public void setStartHour(String startHour) {
        this.startHour = startHour;
    }

    public String getEndDay() {
        return endDay;
    }

    public void setEndDay(String endDay) {
        this.endDay = endDay;
    }

    public String getEndHour() {
        return endHour;
    }

    public void setEndHour(String endHour) {
        this.endHour = endHour;
    }

    public String getFrequence() {
        return frequence;
    }

    public void setFrequence(String frequence) {
        this.frequence = frequence;
    }

    public double getLatitude() {
        return latitude;
    }

    public void setLatitude(double latitude) {
        this.latitude = latitude;
    }

    public double getLongitude() {
        return longitude;
    }

    public void setLongitude(double longitude) {
        this.longitude = longitude;
    }

    public Event() {

    }

    public Event(int id, String title, String description, String startDay, String startHour, String endDay, String endHour, String frequence, double latitude, double longitude) {
        this.id = id;
        this.title = title;
        this.description = description;
        this.startDay = startDay;
        this.startHour = startHour;
        this.endDay = endDay;
        this.endHour = endHour;
        this.frequence = frequence;
        this.latitude = latitude;
        this.longitude = longitude;
    }

    public String print() {
        return this.getId() + " " + this.getTitle() + " " + this.getDescription() + " " + this.getStartDay() + " " + this.getStartHour() + " " + this.getEndDay() + " " + this.getEndHour() + " " + this.getFrequence() + " " + this.getLatitude() + " " + this.getLongitude();
    }
}
