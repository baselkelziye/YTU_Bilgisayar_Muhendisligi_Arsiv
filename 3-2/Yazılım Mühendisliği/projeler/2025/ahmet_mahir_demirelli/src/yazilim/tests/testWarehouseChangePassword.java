package yazilim.tests;

import org.junit.jupiter.api.*;
import java.sql.*;

import static org.junit.jupiter.api.Assertions.*;

public class testWarehouseChangePassword {

    private static Connection conn;
    private static final int TEST_ID = 10000;

    @BeforeAll
    static void setupDatabase() throws Exception {
        conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");

        // Eski varsa sil
        PreparedStatement deleteStmt = conn.prepareStatement("DELETE FROM warehouse WHERE id = ?");
        deleteStmt.setInt(1, TEST_ID);
        deleteStmt.executeUpdate();

        // Yeni test kullanıcısı ekle
        PreparedStatement insertStmt = conn.prepareStatement(
            "INSERT INTO warehouse (id, email, password) VALUES (?, ?, ?)");
        insertStmt.setInt(1, TEST_ID);
        insertStmt.setString(2, "test10000@example.com");
        insertStmt.setString(3, "eski123");
        insertStmt.executeUpdate();
    }

    @Test
    void testPasswordChange() throws Exception {
        String oldPassword = "eski123";
        String newPassword = "yeni123";

        boolean success = changePassword(TEST_ID, oldPassword, newPassword);
        assertTrue(success, "Şifre başarıyla değiştirilmelidir.");
        System.out.println("Yeni şifre başarıyla oluşturuldu.");

        // Güncel şifreyi veritabanından kontrol et
        String updatedPassword = getPasswordFromDb(TEST_ID);
        assertEquals(newPassword, updatedPassword, "Yeni şifre veritabanına kaydedilmiş olmalı.");
        System.out.println("Yeni şifre başarıyla doğrulandı.");
    }

    private boolean changePassword(int id, String oldPass, String newPass) throws SQLException {
        PreparedStatement ps = conn.prepareStatement(
            "UPDATE warehouse SET password = ? WHERE id = ? AND password = ?");
        ps.setString(1, newPass);
        ps.setInt(2, id);
        ps.setString(3, oldPass);
        return ps.executeUpdate() > 0;
    }

    private String getPasswordFromDb(int id) throws SQLException {
        PreparedStatement ps = conn.prepareStatement("SELECT password FROM warehouse WHERE id = ?");
        ps.setInt(1, id);
        ResultSet rs = ps.executeQuery();
        if (rs.next()) {
            return rs.getString("password");
        }
        return null;
    }

    @AfterAll
    static void tearDown() throws Exception {
    	  // Test kullanıcı sil
        PreparedStatement deleteUser = conn.prepareStatement(
            "DELETE FROM warehouse WHERE id = ?");
        deleteUser.setInt(1, TEST_ID);
        deleteUser.executeUpdate();
        
        if (conn != null) conn.close();
    }
}
