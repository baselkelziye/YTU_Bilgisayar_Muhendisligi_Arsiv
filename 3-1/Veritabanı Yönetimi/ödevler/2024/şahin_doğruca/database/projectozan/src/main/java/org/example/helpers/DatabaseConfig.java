package org.example;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DatabaseConfig {
    // Veritabanı bağlantı bilgileri
    private static final String URL = "jdbc:postgresql://localhost:5432/movie_night";
    private static final String USER = "postgres";
    private static final String PASSWORD = "sahker123";

    public static Connection connect() {
        try {
            // Bağlantı
            Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
            System.out.println("Veritabanına başarıyla bağlanıldı!");
            return connection;
        } catch (SQLException e) {
            System.out.println("Veritabanına bağlanılamadı: " + e.getMessage());
            throw new RuntimeException("Veritabanı bağlantısı başarısız.", e);
        }
    }
}
