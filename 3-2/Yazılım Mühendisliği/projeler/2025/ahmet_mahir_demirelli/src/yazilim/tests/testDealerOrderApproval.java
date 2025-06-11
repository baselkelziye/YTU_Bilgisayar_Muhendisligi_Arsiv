package yazilim.tests;

import org.junit.jupiter.api.*;
import java.sql.*;
import static org.junit.jupiter.api.Assertions.*;

public class testDealerOrderApproval {
    private static Connection conn;
    private static final int testUserId = 999;
    private static final int testVehicleId = 888;

 
    @BeforeAll
    public static void setup() throws SQLException {
        System.out.println("\n=== Dummy veriler ekleniyor (DealerOrderApproval Test) ===");

        conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");

        
        PreparedStatement insertCustomer = conn.prepareStatement("""
            INSERT INTO customer (customer_id, email, password_customer, first_name, last_name, phone_number, gender, age, profession, income_level, city, first_visit_date)
            VALUES (999, 'testuser@example.com', 'testpass', 'Test', 'User', '1234567890', 'male', 30, 'Engineer', 'medium', 'TestCity', CURRENT_DATE)
            ON CONFLICT DO NOTHING
        """);
        insertCustomer.executeUpdate();

        
        PreparedStatement insertVehicle = conn.prepareStatement("""
            INSERT INTO vehicle (vehicle_id, brand, model, year, package, price)
            VALUES (888, 'Toyota', 'Corolla', 2023, 'Premium', 480000)
            ON CONFLICT DO NOTHING
        """);
        insertVehicle.executeUpdate();

        
        PreparedStatement insertRequest = conn.prepareStatement("""
            INSERT INTO requests (request_id, user_id, vehicle_id, request_type, request_date, status)
            VALUES (8000, 999, 888, 'order', CURRENT_DATE, 'pending')
            ON CONFLICT DO NOTHING
        """);
        insertRequest.executeUpdate();

        
        PreparedStatement insertPriceOffer = conn.prepareStatement("""
            INSERT INTO price_offers (offer_id, request_id, user_id, vehicle_id, offer_date, offered_price)
            VALUES (9000, 8000, 999, 888, CURRENT_DATE, 480000)
            ON CONFLICT DO NOTHING
        """);
        insertPriceOffer.executeUpdate();

        
        PreparedStatement insertStock = conn.prepareStatement("""
            INSERT INTO stock (vehicle_id, location_type, quantity, updated_at)
            VALUES (888, 'dealer', 1, CURRENT_TIMESTAMP)
            ON CONFLICT DO NOTHING
        """);
        insertStock.executeUpdate();

        System.out.println("Dummy veriler başarıyla eklendi.");
    }



    @Test
    public void testOrderApprovalFlow() throws SQLException {
        System.out.println("\n=== Satış Onaylama Testi Başladı ===");

       
        PreparedStatement updateStockStmt = conn.prepareStatement("""
            UPDATE stock SET quantity = quantity - 1
            WHERE vehicle_id = ? AND location_type = 'dealer' AND quantity > 0
        """);
        updateStockStmt.setInt(1, testVehicleId);
        int affected = updateStockStmt.executeUpdate();
        assertEquals(1, affected, "Stoktan 1 araç düşülmeliydi");
        System.out.println("Stoktan 1 araç başarıyla düşüldü.");

     
        PreparedStatement insertSale = conn.prepareStatement("""
            INSERT INTO sales (user_id, vehicle_id, sale_date, sale_price)
            VALUES (?, ?, CURRENT_DATE, ?)
        """);
        insertSale.setInt(1, testUserId);
        insertSale.setInt(2, testVehicleId);
        insertSale.setDouble(3, 480000);
        int rows = insertSale.executeUpdate();
        assertEquals(1, rows, "Satış kaydı başarılı olmalı");
        System.out.println("Satış kaydı 'sales' tablosuna başarıyla eklendi.");

     
        PreparedStatement deleteOffer = conn.prepareStatement("""
            DELETE FROM price_offers WHERE user_id = ? AND vehicle_id = ?
        """);
        deleteOffer.setInt(1, testUserId);
        deleteOffer.setInt(2, testVehicleId);
        int deleted = deleteOffer.executeUpdate();
        assertEquals(1, deleted, "Fiyat teklifi silinmiş olmalı");
        System.out.println("Fiyat teklifi başarıyla silindi.");

        System.out.println("=== Satış Onaylama Testi Başarıyla Tamamlandı ===\n");
    }

    @AfterAll
    public static void cleanup() throws SQLException {
        System.out.println("\n=== Cleanup başlatıldı ===");

   
     try (PreparedStatement ps = conn.prepareStatement("DELETE FROM price_offers WHERE request_id = ?")) {
         ps.setInt(1, 8000);
         ps.executeUpdate();
     }


     try (PreparedStatement ps = conn.prepareStatement("DELETE FROM sales WHERE user_id = ? AND vehicle_id = ?")) {
         ps.setInt(1, 999);
         ps.setInt(2, 888);
         ps.executeUpdate();
     }

  
     try (PreparedStatement ps = conn.prepareStatement("DELETE FROM requests WHERE user_id = ?")) {
         ps.setInt(1, 999);
         ps.executeUpdate();
     }

   
     try (PreparedStatement ps = conn.prepareStatement("DELETE FROM stock WHERE vehicle_id = ?")) {
         ps.setInt(1, 888);
         ps.executeUpdate();
     }

   
     try (PreparedStatement ps = conn.prepareStatement("DELETE FROM vehicle WHERE vehicle_id = ?")) {
         ps.setInt(1, 888);
         ps.executeUpdate();
     }

    
     try (PreparedStatement ps = conn.prepareStatement("DELETE FROM customer WHERE customer_id = ?")) {
         ps.setInt(1, 999);
         ps.executeUpdate();
     }

        if (conn != null && !conn.isClosed()) {
            conn.close();
        }

        System.out.println("Cleanup tamamlandı.");
    }



}
