package org.example;

import java.sql.*;
import java.util.ArrayList;
import java.util.Vector;

public class UsersDAO {

    public boolean addUser(Users user) {
        if (isNullOrEmpty(user.getUserName(), "Hata: Kullanıcı adı boş bırakılamaz.") ||
            isNullOrEmpty(user.getEmail(), "Hata: Email adresi boş bırakılamaz.") ||
            isNullOrEmpty(user.getPassword(), "Hata: Şifre boş bırakılamaz.") ||
            user.getPassword().length() < 6) {
            System.out.println("Hata: Şifre en az 6 karakter olmalıdır.");
            return false;
        }

        String sql = "INSERT INTO users (username, email, password) VALUES (?, ?, ?)";

        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setString(1, user.getUserName());
            statement.setString(2, user.getEmail());
            statement.setString(3, user.getPassword()); // Şifre hashlenmeli

            int rowsInserted = statement.executeUpdate();
            if (rowsInserted > 0) {
                System.out.println("Kullanıcı başarıyla eklendi!");
                return true;
            }
        } catch (SQLException e) {
            handleSQLException(e, "Kullanıcı ekleme hatası.");
        }

        return false;
    }

    public ArrayList<Users> getAllUsers() throws SQLException {
        String sql = "SELECT * FROM users";

        ArrayList<Users> users = new ArrayList<>();

        try(Connection connection = DatabaseConfig.connect();
            PreparedStatement statement = connection.prepareStatement(sql)) {



            try (ResultSet resultSet = statement.executeQuery()) {
                while (resultSet.next()) {
                    Users user;
                    user = new Users(resultSet.getString("username"), resultSet.getString("email"), resultSet.getString("password"));
                    user.setUserID(resultSet.getInt("user_id"));

                    users.add(user);
                }
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }

        return users;
    }

    public boolean deleteUserByName(String name) {


        String sql = "DELETE FROM users WHERE username = ?";

        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setString(1, name);


            int rowsDeleted = statement.executeUpdate();
            if (rowsDeleted > 0) {
                System.out.println("Kullanıcı başarıyla silindi!");
                return true;
            } else {
                System.out.println("Hata: Kullanıcı bulunamadı.");
            }

        } catch (SQLException e) {
            handleSQLException(e, "Kullanıcı silme hatası.");
        }

        return false;
    }

    public boolean deleteUser(String username, String password) {
        if (isNullOrEmpty(username, "Hata: Kullanıcı adı boş bırakılamaz.") ||
            isNullOrEmpty(password, "Hata: Şifre boş bırakılamaz.")) {
            return false;
        }

        String sql = "DELETE FROM users WHERE username = ? AND password = ?";

        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setString(1, username);
            statement.setString(2, password);

            int rowsDeleted = statement.executeUpdate();
            if (rowsDeleted > 0) {
                System.out.println("Kullanıcı başarıyla silindi!");
                return true;
            } else {
                System.out.println("Hata: Kullanıcı bulunamadı.");
            }

        } catch (SQLException e) {
            handleSQLException(e, "Kullanıcı silme hatası.");
        }

        return false;
    }

    public boolean updateUserPassword(String username, String currentPassword, String newPassword) {
        if (isNullOrEmpty(username, "Hata: Kullanıcı adı boş bırakılamaz.") ||
            isNullOrEmpty(currentPassword, "Hata: Mevcut şifre boş bırakılamaz.") ||
            isNullOrEmpty(newPassword, "Hata: Yeni şifre boş bırakılamaz.") ||
            newPassword.length() < 6) {
            System.out.println("Hata: Yeni şifre en az 6 karakter olmalıdır.");
            return false;
        }

        String sql = "UPDATE users SET password = ? WHERE username = ? AND password = ?";

        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setString(1, newPassword); // Şifre hashlenmeli
            statement.setString(2, username);
            statement.setString(3, currentPassword);

            int rowsUpdated = statement.executeUpdate();
            if (rowsUpdated > 0) {
                System.out.println("Şifre başarıyla güncellendi!");
                return true;
            } else {
                System.out.println("Hata: Şifre güncellenemedi.");
            }

        } catch (SQLException e) {
            handleSQLException(e, "Şifre güncelleme hatası.");
        }

        return false;
    }

    public Integer getUserIdByUsernameAndPassword(String username, String password) {
        if (isNullOrEmpty(username, "Hata: Kullanıcı adı boş bırakılamaz.") ||
            isNullOrEmpty(password, "Hata: Şifre boş bırakılamaz.")) {
            return null;
        }

        String sql = "SELECT user_id FROM users WHERE username = ? AND password = ?";
        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setString(1, username);
            statement.setString(2, password);

            try (ResultSet resultSet = statement.executeQuery()) {
                if (resultSet.next()) {
                    return resultSet.getInt("user_id");
                }
            }
        } catch (SQLException e) {
            handleSQLException(e, "Kullanıcı ID alma hatası.");
        }

        return null; // Kullanıcı bulunamadıysa veya hata varsa null dön.
    }

    // Yardımcı metotlar
    private boolean isNullOrEmpty(String value, String errorMessage) {
        if (value == null || value.trim().isEmpty()) {
            System.out.println(errorMessage);
            return true;
        }
        return false;
    }

    private void handleSQLException(SQLException e, String defaultMessage) {
        if (e.getMessage().contains("unique constraint")) {
            System.out.println("Hata: Kullanıcı adı veya email zaten kullanılıyor.");
        } else {
            System.out.println(defaultMessage + " " + e.getMessage());
        }
    }
    public int getUserIDByUsername(String username) {
        String sql = "SELECT user_id FROM users WHERE username = ?";
        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setString(1, username);
            ResultSet resultSet = statement.executeQuery();

            if (resultSet.next()) {
                return resultSet.getInt("user_id");
            } else {
                System.out.println("Hata: Kullanıcı bulunamadı.");
                return -1; // Kullanıcı bulunamazsa -1
            }
        } catch (SQLException e) {
            System.out.println("Kullanıcı ID alma hatası: " + e.getMessage());
            return -1;
        }
    }
    public Users getUserById(int user_id) {
        String sql = "SELECT * FROM users WHERE user_id = ?";
        System.out.println("user_id : " + user_id);
        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setInt(1, user_id);
            ResultSet resultSet = statement.executeQuery();

            if (resultSet.next()) {
                return new Users(resultSet.getString("username"), resultSet.getString("email"), resultSet.getString("password"));
            } else {
                System.out.println("Hata: Kullanıcı bulunamadı.");
                return null; // Kullanıcı bulunamazsa -1
            }
        } catch (SQLException e) {
            System.out.println("Kullanıcı ID alma hatası: " + e.getMessage());
            return null;
        }
    }
    public boolean authenticateUser(String username, String password) {
        String sql = "SELECT * FROM users WHERE username = ? AND password = ?";
        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setString(1, username);
            statement.setString(2, password);

            try (ResultSet resultSet = statement.executeQuery()) {
                if (resultSet.next()) {

                    int userId = resultSet.getInt("user_id");
                    Users user = new Users(resultSet.getString("username"), resultSet.getString("email"), resultSet.getString("password"));

                    UserSession.setSession(userId, user, false);
                    return true;
                } else {
                    System.out.println("Hata: Kullanıcı adı veya şifre yanlış.");
                }
            }
        } catch (SQLException e) {
            System.out.println("Kullanıcı doğrulama hatası: " + e.getMessage());
        }
        return false;
    }
}
