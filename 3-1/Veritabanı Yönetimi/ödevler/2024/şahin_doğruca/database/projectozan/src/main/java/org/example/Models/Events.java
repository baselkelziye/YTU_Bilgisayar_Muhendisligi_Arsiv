package org.example;

import java.time.LocalDate;

public class Events {
    private int eventID;
    private int userID;
    private String eventName;
    private LocalDate eventDate;  // LocalDate olarak değiştir
    private LocalDate createdDate;  // createdDate de LocalDate olarak değiştir

    public Events(int eventID, int userID, String eventName, LocalDate eventDate) {
        if (eventName == null || eventName.trim().isEmpty()) {
            throw new IllegalArgumentException("Event name cannot be null or empty.");
        }
        if (eventDate == null) {
            throw new IllegalArgumentException("Event date cannot be null.");
        }

        this.eventID = eventID;
        this.userID = userID;
        this.eventName = eventName;
        this.eventDate = eventDate;
        this.createdDate = LocalDate.now();  // Timestamp yerine LocalDate.now() kullan
    }

    public int getEventID() {
        return eventID;
    }

    public void setEventID(int eventID) {
        this.eventID = eventID;
    }

    public int getUserID() {
        return userID;
    }

    public void setUserID(int userID) {
        this.userID = userID;
    }

    public String getEventName() {
        return eventName;
    }

    public void setEventName(String eventName) {
        if (eventName == null || eventName.trim().isEmpty()) {
            throw new IllegalArgumentException("Event name cannot be null or empty.");
        }
        this.eventName = eventName;
    }

    public LocalDate getEventDate() {
        return eventDate;
    }

    public void setEventDate(LocalDate eventDate) {
        if (eventDate == null) {
            throw new IllegalArgumentException("Event date cannot be null.");
        }
        this.eventDate = eventDate;
    }

    public LocalDate getCreatedDate() {
        return createdDate;
    }

    public void setCreatedDate(LocalDate createdDate) {
        if (createdDate == null) {
            throw new IllegalArgumentException("Created date cannot be null.");
        }
        this.createdDate = createdDate;
    }

    @Override
    public String toString() {
        return "Events{" +
                "eventID=" + eventID +
                ", userID=" + userID +
                ", eventName='" + eventName + '\'' +
                ", eventDate=" + eventDate +
                ", createdDate=" + createdDate +
                '}';
    }
}
