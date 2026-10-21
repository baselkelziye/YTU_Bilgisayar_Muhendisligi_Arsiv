package org.example;

import javax.xml.crypto.Data;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDate;

public class Movies {
    private int movieID;
    private String title;
    private String genre;
    private LocalDate releaseDate;
    private double rating;

    public Movies(int movieID, String title, String genre, LocalDate releaseDate, double rating) {
        if (movieID < 0) {
            throw new IllegalArgumentException("Movie ID negatif olamaz.");
        }
        if (title == null || title.trim().isEmpty()) {
            throw new IllegalArgumentException("Title boş bırakılamaz.");
        }
        if (genre == null || genre.trim().isEmpty()) {
            throw new IllegalArgumentException("Genre boş bırakılamaz.");
        }
        if (rating < 0 || rating > 5) {
            throw new IllegalArgumentException("Rating 0 ile 10 arasında olmalıdır.");
        }
        this.movieID = movieID;
        this.title = title;
        this.genre = genre;
        this.releaseDate = releaseDate;
        setRating();
    }

    public int getMovieID() {
        return movieID;
    }

    public void setMovieID(int movieID) {
        if (movieID < 0) {
            throw new IllegalArgumentException("Movie ID negatif olamaz.");
        }
        this.movieID = movieID;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        if (title == null || title.trim().isEmpty()) {
            throw new IllegalArgumentException("Title boş bırakılamaz.");
        }
        this.title = title;
    }

    public String getGenre() {
        return genre;
    }

    public void setGenre(String genre) {
        if (genre == null || genre.trim().isEmpty()) {
            throw new IllegalArgumentException("Genre boş bırakılamaz.");
        }
        this.genre = genre;
    }

    public LocalDate getReleaseDate() {
        return releaseDate;
    }

    public void setReleaseDate(LocalDate releaseDate) {
        this.releaseDate = releaseDate;
    }

    public double getRating() {
        return rating;
    }

    public void setRating() {
        String sql = "select rating from vote where movie_id = ?";

        try(Connection connection = DatabaseConfig.connect();
            PreparedStatement statement = connection.prepareStatement(sql);) {

            statement.setInt(1, this.movieID);
            Double rating = 0.;
            int counter = 0;
            ResultSet rs = statement.executeQuery();

            while(rs.next()) {
                rating += rs.getDouble("rating");
                counter++;
            }

            if(counter == 0) {
                rating = 0.;
            } else {
                rating = rating / counter;
            }



            this.rating = rating;

            MoviesDAO moviesDAO = new MoviesDAO();
            moviesDAO.setMovieRating(this.movieID, this.rating);

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
