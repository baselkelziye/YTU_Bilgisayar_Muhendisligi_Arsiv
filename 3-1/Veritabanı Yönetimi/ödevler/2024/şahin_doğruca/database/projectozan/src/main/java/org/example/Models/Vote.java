package org.example;

import java.sql.Timestamp;

public class Vote {
    private int voteID;
    private int movieID;
    private int userID;
    private int rating;
    private Timestamp createdAt;

    public Vote(int voteID, int movieID, int userID, int rating, Timestamp createdAt) {
        this.voteID = voteID;
        this.movieID = movieID;
        this.userID = userID;
        this.rating = rating;
        this.createdAt = createdAt;
    }

    public int getVoteID() {
        return voteID;
    }

    public void setVoteID(int voteID) {
        this.voteID = voteID;
    }

    public int getMovieID() {
        return movieID;
    }

    public void setMovieID(int movieID) {
        this.movieID = movieID;
    }

    public int getUserID() {
        return userID;
    }

    public void setUserID(int userID) {
        this.userID = userID;
    }

    public int getRating() {
        return rating;
    }

    public void setRating(int rating) {
        this.rating = rating;
    }

    public Timestamp getCreatedAt() {
        return createdAt;
    }

    public void setCreatedAt(Timestamp createdAt) {
        this.createdAt = createdAt;
    }

    @Override
    public String toString() {
        return "Vote{" +
                "voteID=" + voteID +
                ", movieID=" + movieID +
                ", userID=" + userID +
                ", rating=" + rating +
                ", createdAt=" + createdAt +
                '}';
    }
}
