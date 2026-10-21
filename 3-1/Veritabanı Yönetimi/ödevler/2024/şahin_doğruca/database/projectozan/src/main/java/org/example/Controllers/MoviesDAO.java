package org.example;

import javax.xml.crypto.Data;
import java.sql.*;
import java.time.LocalDate;
import java.util.ArrayList;

public class MoviesDAO {

    public boolean addMovie(Movies movie) {
        if (isNullOrEmpty(movie.getTitle(), "Hata: Film adı boş bırakılamaz.") ||
            isNullOrEmpty(movie.getGenre(), "Hata: Film türü boş bırakılamaz.") ||
            movie.getReleaseDate() == null) {
            System.out.println("Hata: Vizyon tarihi boş bırakılamaz.");
            return false;
        }

        String sql = "INSERT INTO movies (title, genre, release_date, rating) VALUES (?, ?, ?, ?)";
        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setString(1, movie.getTitle());
            statement.setString(2, movie.getGenre());
            statement.setDate(3, java.sql.Date.valueOf(movie.getReleaseDate()));
            statement.setDouble(4, movie.getRating());

            int rowsInserted = statement.executeUpdate();
            if (rowsInserted > 0) {
                System.out.println("Film başarıyla eklendi!");
                return true;
            }
        } catch (SQLException e) {
            handleSQLException(e, "Film ekleme hatası.");
        }
        return false;
    }

    public boolean deleteMovie(String movieTitle) {
        if (isNullOrEmpty(movieTitle, "Hata: Film adı boş bırakılamaz.")) {
            return false;
        }

        String sql = "DELETE FROM movies WHERE title = ?";
        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setString(1, movieTitle);

            int rowsDeleted = statement.executeUpdate();
            if (rowsDeleted > 0) {
                System.out.println("Film başarıyla silindi!");
                return true;
            } else {
                System.out.println("Hata: Film bulunamadı.");
            }

        } catch (SQLException e) {
            handleSQLException(e, "Film silme hatası.");
        }
        return false;
    }

    public boolean updateMovieGenre(String currentTitle, String newGenre) {
        if (isNullOrEmpty(currentTitle, "Hata: Mevcut film adı boş bırakılamaz.") ||
            isNullOrEmpty(newGenre, "Hata: Yeni film türü boş bırakılamaz.")) {
            return false;
        }

        String sql = "UPDATE movies SET genre = ? WHERE title = ?";
        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setString(1, newGenre);
            statement.setString(2, currentTitle);

            int rowsUpdated = statement.executeUpdate();
            if (rowsUpdated > 0) {
                System.out.println("Film türü başarıyla güncellendi!");
                return true;
            } else {
                System.out.println("Hata: Film bulunamadı.");
            }

        } catch (SQLException e) {
            handleSQLException(e, "Film türü güncelleme hatası.");
        }
        return false;
    }



    public boolean updateMovieReleaseDate(String currentTitle, LocalDate newReleaseDate) {
        if (isNullOrEmpty(currentTitle, "Hata: Mevcut film adı boş bırakılamaz.") || 
            newReleaseDate == null) {
            System.out.println("Hata: Yeni vizyon tarihi boş bırakılamaz.");
            return false;
        }

        String sql = "UPDATE movies SET release_date = ? WHERE title = ?";
        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setDate(1, java.sql.Date.valueOf(newReleaseDate));
            statement.setString(2, currentTitle);

            int rowsUpdated = statement.executeUpdate();
            if (rowsUpdated > 0) {
                System.out.println("Film vizyon tarihi başarıyla güncellendi!");
                return true;
            } else {
                System.out.println("Hata: Film bulunamadı.");
            }

        } catch (SQLException e) {
            handleSQLException(e, "Film vizyon tarihi güncelleme hatası.");
        }
        return false;
    }


    public int getMovieByTitle(String movie_title) {


        String sql = "SELECT * FROM movies WHERE title = ?";
        Movies movie = null;

        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement preparedStatement = connection.prepareStatement(sql);) {

            preparedStatement.setString(1, movie_title);

            try (ResultSet resultSet = preparedStatement.executeQuery()) {
                if (resultSet.next()) {
                    return resultSet.getInt("movie_id");
                }
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return 0;
    }


    public Movies getMovieByID(int movie_id) {


        String sql = "SELECT * FROM movies WHERE movie_id = ?";
        Movies movie = null;

        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement preparedStatement = connection.prepareStatement(sql);) {

            preparedStatement.setInt(1, movie_id);

            try (ResultSet resultSet = preparedStatement.executeQuery()) {
                if (resultSet.next()) {
                    movie = new Movies(
                            movie_id,
                            resultSet.getString("title"),
                            resultSet.getString("genre"),
                            Date.valueOf(resultSet.getString("release_date")).toLocalDate(),
                            resultSet.getDouble("rating")
                    );

                    return movie;
                }
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return null;
    }

    public ArrayList<Movies> getAllMovies() {
        ArrayList<Movies> movies = new ArrayList<>();
        String sql = "SELECT * FROM movies";

        try(Connection connection = DatabaseConfig.connect();
            PreparedStatement statement = connection.prepareStatement(sql);) {

            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {

                Movies movie = new Movies(resultSet.getInt("movie_id"), resultSet.getString("title"),
                                        resultSet.getString("genre"), resultSet.getDate("release_date").toLocalDate(),
                                            resultSet.getDouble("rating"));

                movies.add(movie);

            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return movies;
    }

    public void setMovieRating(int movie_id, double rating) {
        String sql = "UPDATE movies SET rating = ? WHERE movie_id = ?";

        try(Connection connection = DatabaseConfig.connect();
            PreparedStatement statement = connection.prepareStatement(sql);) {

            statement.setDouble(1, rating);
            statement.setInt(2, movie_id);

            int rowsUpdated = statement.executeUpdate();
            if (rowsUpdated > 0) {
                System.out.println("Updated Movie Rating");
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    // Yardımcı metodlar
    private boolean isNullOrEmpty(String value, String errorMessage) {
        if (value == null || value.trim().isEmpty()) {
            System.out.println(errorMessage);
            return true;
        }
        return false;
    }

    private void handleSQLException(SQLException e, String defaultMessage) {
        System.out.println(defaultMessage + " " + e.getMessage());
    }
}
