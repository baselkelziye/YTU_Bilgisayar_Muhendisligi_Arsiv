package com.airline.models;

public class Flight {
    private String flightNum;
    private Route route;
    private String date;
    private String hour;
    private String duration;
    private Plane plane;
    private String pilotName;

    public Flight(String flightNum, Route route, String date, String hour, String duration, Plane plane, String pilotName) {
        this.flightNum = flightNum;
        this.route = route;
        this.date = date;
        this.hour = hour;
        this.plane = plane;
        this.pilotName = pilotName;
        this.duration = duration;
    }

    public String getFlightNum() {
        return flightNum;
    }

    public Route getRoute() {
        return route;
    }

    public String getDate() {
        return date;
    }

    public String getHour() {
        return hour;
    }

    public String getDuration() {
        return duration;
    }

    public Plane getPlane() {
        return plane;
    }

    public String getPilotName() {
        return pilotName;
    }

    public void setDuration(String duration) {
        this.duration = duration;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public void setFlightNum(String flightNum) {
        this.flightNum = flightNum;
    }

    public void setHour(String hour) {
        this.hour = hour;
    }

    public void setRoute(Route route) {
        this.route = route;
    }

    public void setPilotName(String pilotName) {
        this.pilotName = pilotName;
    }

    @Override
    public String toString() {
        return flightNum + " | " + route + " | " + date + " " + hour + " | Pilot: " + pilotName;
    }
}
