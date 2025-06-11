package yazilim.tests;

import yazilim.requests.OrderRequest;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDate;

import static org.junit.jupiter.api.Assertions.*;

class OrderRequestTest {
    private Connection conn;
    private OrderRequest orderRequest;
    private final int userId = 100;
    private final int vehicleId = 100;
    private final int offerId = 100;
    private final LocalDate requestDate = LocalDate.now();

    @BeforeEach
    void setUp() throws SQLException {
        // Veritabanı bağlantısı ayarları
        String url = "jdbc:postgresql://localhost:5432/YazilimMuhProje";
        String username = "postgres";
        String password = "12345";
        conn = DriverManager.getConnection(url, username, password);

        // Test verilerini ekleme
        String userInsert = "INSERT INTO customer (customer_id, email, password_customer, first_name, last_name) VALUES (?, ?, ?, ?, ?) ON CONFLICT DO NOTHING";
        try (PreparedStatement stmt = conn.prepareStatement(userInsert)) {
            stmt.setInt(1, userId);
            stmt.setString(2, "testuser@example.com");
            stmt.setString(3, "testpassword");  
            stmt.setString(4, "Test");
            stmt.setString(5, "User");
            stmt.executeUpdate();
        }
        String vehicleInsert = "INSERT INTO vehicle (vehicle_id, brand, model) VALUES (?, ?, ?) ON CONFLICT DO NOTHING";
        try (PreparedStatement stmt = conn.prepareStatement(vehicleInsert)) {
            stmt.setInt(1, vehicleId);
            stmt.setString(2, "TestBrand");
            stmt.setString(3, "TestModel");
            stmt.executeUpdate();
        }

     // Test request kaydı ekleme
        String requestInsert = "INSERT INTO requests (user_id, vehicle_id, request_type, request_date, status) VALUES (?, ?, ?, ?, ?) RETURNING request_id";
        int generatedRequestId = -1;
        try (PreparedStatement stmt = conn.prepareStatement(requestInsert)) {
            stmt.setInt(1, userId);
            stmt.setInt(2, vehicleId);
            stmt.setString(3, "order");
            stmt.setDate(4, java.sql.Date.valueOf(requestDate.minusDays(15)));
            stmt.setString(5, "pending");
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                generatedRequestId = rs.getInt("request_id");
            }
        }

        // price_offers kaydı ekleme
        String offerInsert = "INSERT INTO price_offers (offer_id, request_id, user_id, vehicle_id, offer_date, offered_price) VALUES (?, ?, ?, ?, ?, ?) ON CONFLICT DO NOTHING";
        try (PreparedStatement stmt = conn.prepareStatement(offerInsert)) {
            stmt.setInt(1, offerId);
            stmt.setInt(2, generatedRequestId);  
            stmt.setInt(3, userId);
            stmt.setInt(4, vehicleId);
            stmt.setDate(5, java.sql.Date.valueOf(requestDate.minusDays(10)));
            stmt.setBigDecimal(6, new java.math.BigDecimal("50000"));
            stmt.executeUpdate();
        }





        
        orderRequest = new OrderRequest(userId, vehicleId, requestDate, conn, offerId);
    }
    //test kayıtları silinir
    @AfterEach
    void tearDown() throws SQLException {
        // price_offers tablosundan silme
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM price_offers WHERE user_id = ?")) {
            stmt.setInt(1, userId);
            stmt.executeUpdate();
        }

        // requests tablosundan silme
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM requests WHERE user_id = ?")) {
            stmt.setInt(1, userId);
            stmt.executeUpdate();
        }

        // vehicles tablosundan silme
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM vehicle WHERE vehicle_id = ?")) {
            stmt.setInt(1, vehicleId);
            stmt.executeUpdate();
        }

        // customers tablosundan silme
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM customer WHERE customer_id = ?")) {
            stmt.setInt(1, userId);
            stmt.executeUpdate();
        }

        if (conn != null && !conn.isClosed()) {
            conn.close();
        }
    }


    
  
    @Test
    void testProcessRequestValidOffer() throws SQLException {
        System.out.println("\n=== Testing Valid Offer Processing ===");
        System.out.println("User ID: " + userId);
        System.out.println("Vehicle ID: " + vehicleId);
        System.out.println("Request Date: " + requestDate);
        System.out.println("Testing processRequest()...");

        boolean result = orderRequest.processRequest(userId, vehicleId, requestDate);

        if (result) {
            System.out.println("✓ processRequest() returned true - Offer processed successfully.");
        } else {
            System.out.println("✗ processRequest() returned false - Offer processing failed.");
        }
        assertTrue(result, "Request should be processed successfully for a valid offer.");

        // Veritabanında kaydın olup olmadığını kontrol etme
        try (PreparedStatement stmt = conn.prepareStatement("SELECT * FROM requests WHERE user_id = ? AND vehicle_id = ? AND request_type = 'order'")) {
            stmt.setInt(1, userId);
            stmt.setInt(2, vehicleId);
            ResultSet rs = stmt.executeQuery();
            
            if (rs.next()) {
                System.out.println("✓ Request successfully found in the database:");
                System.out.println("Request ID: " + rs.getInt("request_id"));
                System.out.println("Request Type: " + rs.getString("request_type"));
                System.out.println("Request Date: " + rs.getDate("request_date"));
                System.out.println("Status: " + rs.getString("status"));
            } else {
                System.out.println("✗ No matching request found in the database.");
            }

            assertTrue(rs.next(), "The order request should be recorded in the database.");
        }
    }



    @Test
    void testProcessRequestExpiredOffer() throws SQLException {
        System.out.println("\n=== Testing Expired Offer Processing ===");
        System.out.println("User ID: " + userId);
        System.out.println("Vehicle ID: " + vehicleId);
        System.out.println("Current Request Date: " + requestDate);

        LocalDate expiredOfferDate = requestDate.minusDays(40);
        System.out.println("Setting offer date to: " + expiredOfferDate);

        try (PreparedStatement stmt = conn.prepareStatement("UPDATE price_offers SET offer_date = ? WHERE offer_id = ?")) {
            stmt.setDate(1, java.sql.Date.valueOf(expiredOfferDate));
            stmt.setInt(2, offerId);
            int rowsUpdated = stmt.executeUpdate();

            if (rowsUpdated > 0) {
                System.out.println("✓ Offer date updated successfully in the database.");
            } else {
                System.out.println("✗ Offer date update failed. No matching offer found.");
            }
        }

        // Teklifin süresi dolmuş mu kontrolü
        boolean result = orderRequest.processRequest(userId, vehicleId, requestDate);

        if (!result) {
            System.out.println("✓ processRequest() returned false - Offer is correctly detected as expired.");
        } else {
            System.out.println("✗ processRequest() returned true - Expired offer should not be processed.");
        }

        

        assertFalse(result, "Request should not be processed for an expired offer.");
    }


    
}
