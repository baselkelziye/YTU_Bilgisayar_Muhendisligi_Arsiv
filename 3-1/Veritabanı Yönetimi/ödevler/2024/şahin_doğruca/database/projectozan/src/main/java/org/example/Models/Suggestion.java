package org.example;

import java.sql.Timestamp;

public class Suggestion {
    private int suggestionID;
    private int eventID;
    private int userID;
    private int movieID;

    public Suggestion(int suggestionID, int eventID, int userID, int movieID) {
        this.suggestionID = suggestionID;
        this.eventID = eventID;
        this.userID = userID;
        this.movieID = movieID;
    }

    public int getSuggestionID() {
        return suggestionID;
    }

    public void setSuggestionID(int suggestionID) {
        this.suggestionID = suggestionID;
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

    public int getMovieID() {
        return movieID;
    }

    public void setMovieID(int movieID) {
        this.movieID = movieID;
    }


    @Override
    public String toString() {
        return "Suggestion{" +
                "suggestionID=" + suggestionID +
                ", eventID=" + eventID +
                ", userID=" + userID +
                ", movieTitle='" + movieID + '\'' +
                '}';
    }
}
