package org.example;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class AdminDAO {

    public boolean addAdmin(Admin admin) {
        if (isNullOrEmpty(admin.getName(), "Hata: Admin adı boş bırakılamaz.") ||
            isNullOrEmpty(admin.getEmail(), "Hata: Email adresi boş bırakılamaz.") ||
            !admin.getEmail().matches("^[A-Za-z0-9+_.-]+@(.+)$")) {
            System.out.println("Hata: Geçersiz bir email adresi.");
            return false;
        }
        if (admin.getPassword() == null || admin.getPassword().length() < 6) {
            System.out.println("Hata: Şifre en az 6 karakter olmalı.");
            return false;
        }

        String sql = "INSERT INTO admin (name, email, password) VALUES (?, ?, ?)";
        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setString(1, admin.getName());
            statement.setString(2, admin.getEmail());
            statement.setString(3, admin.getPassword());

            int rowsInserted = statement.executeUpdate();
            if (rowsInserted > 0) {
                System.out.println("Admin başarıyla eklendi!");
                return true;
            }
        } catch (SQLException e) {
            handleSQLException(e, "Admin ekleme hatası!");
        }
        return false;
    }

    public boolean deleteAdminByNameAndPassword(String name, String password) {
        if (isNullOrEmpty(name, "Hata: Geçersiz admin adı.") || 
            isNullOrEmpty(password, "Hata: Geçersiz şifre.")) {
            return false;
        }

        String sql = "DELETE FROM admin WHERE name = ? AND password = ?";
        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setString(1, name);
            statement.setString(2, password);

            int rowsDeleted = statement.executeUpdate();
            if (rowsDeleted > 0) {
                System.out.println("Admin başarıyla silindi!");
                return true;
            } else {
                System.out.println("Hata: Girilen kullanıcı adı veya şifre hatalı.");
            }
        } catch (SQLException e) {
            handleSQLException(e, "Admin silme hatası.");
        }
        return false;
    }

    public boolean updateAdminPassword(String name, String currentPassword, String newPassword) {
        if (isNullOrEmpty(name, "Hata: Admin adı boş bırakılamaz.") || 
            isNullOrEmpty(currentPassword, "Hata: Geçersiz mevcut şifre.") ||
            isNullOrEmpty(newPassword, "Hata: Yeni şifre boş bırakılamaz.") || 
            newPassword.length() < 6) {
            System.out.println("Hata: Yeni şifre en az 6 karakter olmalı.");
            return false;
        }

        String selectSQL = "SELECT * FROM admin WHERE name = ? AND password = ?";
        String updateSQL = "UPDATE admin SET password = ? WHERE name = ? AND password = ?";

        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement selectStatement = connection.prepareStatement(selectSQL)) {

            selectStatement.setString(1, name);
            selectStatement.setString(2, currentPassword);

            ResultSet resultSet = selectStatement.executeQuery();

            if (resultSet.next()) {
                try (PreparedStatement updateStatement = connection.prepareStatement(updateSQL)) {
                    updateStatement.setString(1, newPassword);
                    updateStatement.setString(2, name);
                    updateStatement.setString(3, currentPassword);

                    int rowsUpdated = updateStatement.executeUpdate();
                    if (rowsUpdated > 0) {
                        System.out.println("Şifre başarıyla güncellendi!");
                        return true;
                    } else {
                        System.out.println("Güncelleme sırasında hata oluştu.");
                    }
                }
            } else {
                System.out.println("Kullanıcı adı veya mevcut şifre hatalı.");
            }
        } catch (SQLException e) {
            handleSQLException(e, "Şifre güncelleme hatası.");
        }
        return false;
    }

    public boolean updateAdminEmail(String name, String currentPassword, String newEmail) {
        if (isNullOrEmpty(name, "Hata: Admin adı boş bırakılamaz.") || 
            isNullOrEmpty(currentPassword, "Hata: Geçersiz mevcut şifre.") || 
            isNullOrEmpty(newEmail, "Hata: Yeni email adresi boş bırakılamaz.") ||
            !newEmail.matches("^[A-Za-z0-9+_.-]+@(.+)$")) {
            System.out.println("Hata: Geçersiz bir email adresi.");
            return false;
        }

        String selectSQL = "SELECT * FROM admin WHERE name = ? AND password = ?";
        String updateSQL = "UPDATE admin SET email = ? WHERE name = ? AND password = ?";

        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement selectStatement = connection.prepareStatement(selectSQL)) {

            selectStatement.setString(1, name);
            selectStatement.setString(2, currentPassword);

            ResultSet resultSet = selectStatement.executeQuery();

            if (resultSet.next()) {
                try (PreparedStatement updateStatement = connection.prepareStatement(updateSQL)) {
                    updateStatement.setString(1, newEmail);
                    updateStatement.setString(2, name);
                    updateStatement.setString(3, currentPassword);

                    int rowsUpdated = updateStatement.executeUpdate();
                    if (rowsUpdated > 0) {
                        System.out.println("Mail adresi başarıyla güncellendi!");
                        return true;
                    } else {
                        System.out.println("Güncelleme sırasında hata oluştu.");
                    }
                }
            } else {
                System.out.println("Kullanıcı adı veya mevcut şifre hatalı.");
            }
        } catch (SQLException e) {
            handleSQLException(e, "Email güncelleme hatası.");
        }
        return false;
    }


    public boolean authenticateUser(String name, String password) {
        String sql = "SELECT * FROM admin WHERE name = ? AND password = ?";
        try (Connection connection = DatabaseConfig.connect();
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setString(1, name);
            statement.setString(2, password);

            try (ResultSet resultSet = statement.executeQuery()) {
                if (resultSet.next()) {

                    int adminId = resultSet.getInt("admin_id");
                    Users user = new Users(resultSet.getString("name"), resultSet.getString("email"), resultSet.getString("password"));

                    UserSession.setSession(adminId, user, true);
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
