package com.example.models;

public class Plan {
    private String id;
    private String employeeUsername;
    private String travelDate;
    private String endLocation;
    private Coordinates coordinates;
    private String accountantUsername;

    public Plan(String id, String employeeUsername, String travelDate, String endLocation, Coordinates coordinates, String accountantUsername) {
        this.id = id;
        this.employeeUsername = employeeUsername;
        this.travelDate = travelDate;
        this.endLocation = endLocation;
        this.coordinates = coordinates;
        this.accountantUsername = accountantUsername;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getEmployeeUsername() {
        return employeeUsername;
    }

    public void setEmployeeUsername(String employeeUsername) {
        this.employeeUsername = employeeUsername;
    }

    public String getTravelDate() {
        return travelDate;
    }

    public void setTravelDate(String travelDate) {
        this.travelDate = travelDate;
    }

    public String getEndLocation() {
        return endLocation;
    }

    public void setEndLocation(String endLocation) {
        this.endLocation = endLocation;
    }

    public Coordinates getCoordinates() {
        return coordinates;
    }

    public void setCoordinates(Coordinates coordinates) {
        this.coordinates = coordinates;
    }

    public String getAccountantUsername() {
        return accountantUsername;
    }

    public void setAccountantUsername(String accountantUsername) {
        this.accountantUsername = accountantUsername;
    }

    public static class Coordinates {
        private String latitude;
        private String longtitude;

        public Coordinates(String latitude, String longtitude) {
            this.latitude = latitude;
            this.longtitude = longtitude;
        }

        public String getLatitude() {
            return latitude;
        }

        public void setLatitude(String latitude) {
            this.latitude = latitude;
        }

        public String getLongtitude() {
            return longtitude;
        }

        public void setLongtitude(String longtitude) {
            this.longtitude = longtitude;
        }
    }

    @Override
    public String toString() {
        return "Plan{" +
                "id='" + id + '\'' +
                "employeeUsername='" + employeeUsername + '\'' +
                ", travelDate='" + travelDate + '\'' +
                ", endLocation='" + endLocation + '\'' +
                ", coordinates=" + coordinates +
                ", accountantUsername='" + accountantUsername + '\'' +
                '}';
    }
}

