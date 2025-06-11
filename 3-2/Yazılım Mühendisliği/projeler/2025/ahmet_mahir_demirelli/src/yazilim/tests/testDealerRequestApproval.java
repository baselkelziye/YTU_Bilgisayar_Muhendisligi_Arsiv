package yazilim.tests;

import org.junit.jupiter.api.*;
import java.sql.*;
import static org.junit.jupiter.api.Assertions.*;

public class testDealerRequestApproval {
    private static Connection conn;
    private static final int testUserId = 999;
    private static final int testVehicleId = 888;
    private static final int testRequestId = 8001;

    @BeforeAll
    public static void setup() throws SQLException {
        System.out.println("\n=== Dummy veriler ekleniyor (DealerRequestPage Test) ===");

        conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");

        conn.prepareStatement("""
            INSERT INTO customer (customer_id, email, password_customer, first_name, last_name, phone_number, gender, age, profession, income_level, city, first_visit_date)
            VALUES (999, 'testuser@example.com', 'testpass', 'Test', 'User', '1234567890', 'male', 30, 'Engineer', 'medium', 'TestCity', CURRENT_DATE)
            ON CONFLICT DO NOTHING
        """).executeUpdate();

        conn.prepareStatement("""
            INSERT INTO vehicle (vehicle_id, brand, model, year, package, price)
            VALUES (888, 'Honda', 'Civic', 2023, 'Sport', 450000)
            ON CONFLICT DO NOTHING
        """).executeUpdate();

        PreparedStatement insertRequest = conn.prepareStatement("""
        	    INSERT INTO requests (request_id, user_id, vehicle_id, request_type, request_date, status)
        	    VALUES (?, ?, ?, 'price_offer', CURRENT_DATE, 'pending')
        	    ON CONFLICT DO NOTHING
        	""");
        	insertRequest.setInt(1, testRequestId);
        	insertRequest.setInt(2, testUserId);
        	insertRequest.setInt(3, testVehicleId);
        	insertRequest.executeUpdate();

        System.out.println("Dummy veriler başarıyla eklendi.");
    }

    @Test
    public void testApprovePriceOffer() throws SQLException {
        System.out.println("\n=== Fiyat Teklifi Onaylama Testi Başladı ===");

     
        PreparedStatement updateReq = conn.prepareStatement(
            "UPDATE requests SET status = 'accepted' WHERE request_id = ?"
        );
        updateReq.setInt(1, testRequestId);
        int updateCount = updateReq.executeUpdate();
        assertEquals(1, updateCount, "Request durumu güncellenmiş olmalı");

      
        PreparedStatement insertOffer = conn.prepareStatement("""
            INSERT INTO price_offers (offer_id, request_id, user_id, vehicle_id, offer_date, offered_price)
            VALUES (9001, ?, ?, ?, CURRENT_DATE, ?)
        """);
        insertOffer.setInt(1, testRequestId);
        insertOffer.setInt(2, testUserId);
        insertOffer.setInt(3, testVehicleId);
        insertOffer.setDouble(4, 450000);
        int insertCount = insertOffer.executeUpdate();
        assertEquals(1, insertCount, "Fiyat teklifi başarıyla eklenmiş olmalı");

        System.out.println(" Fiyat teklifi başarıyla onaylandı ve sisteme kaydedildi.");
    }

    @AfterAll
    public static void cleanup() throws SQLException {
        System.out.println("\n=== Cleanup başlatıldı ===");

        conn.prepareStatement("DELETE FROM price_offers WHERE request_id = 8001").executeUpdate();
        conn.prepareStatement("DELETE FROM requests WHERE request_id = 8001").executeUpdate();
        conn.prepareStatement("DELETE FROM vehicle WHERE vehicle_id = 888").executeUpdate();
        conn.prepareStatement("DELETE FROM customer WHERE customer_id = 999").executeUpdate();

        if (conn != null && !conn.isClosed()) {
            conn.close();
        }

        System.out.println("Cleanup tamamlandı.");
    }
}
