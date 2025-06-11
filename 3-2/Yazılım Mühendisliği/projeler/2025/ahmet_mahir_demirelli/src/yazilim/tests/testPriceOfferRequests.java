package yazilim.tests;

import org.junit.jupiter.api.*;
import java.sql.*;
import java.time.LocalDate;

import yazilim.requests.PriceOfferRequest;

import static org.junit.jupiter.api.Assertions.*;

public class testPriceOfferRequests {

    private static Connection conn;
    private static final int TEST_USER_ID = 100000;
    private static final int TEST_VEHICLE_ID = 999;

    @BeforeAll
    static void setup() throws Exception {
        conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");

        // Test aracını ekle
        PreparedStatement vehicleStmt = conn.prepareStatement(
            "INSERT INTO vehicle (vehicle_id, brand, model, year) VALUES (?, ?, ?, ?) ON CONFLICT (vehicle_id) DO NOTHING");
        vehicleStmt.setInt(1, TEST_VEHICLE_ID);
        vehicleStmt.setString(2, "TestBrand");
        vehicleStmt.setString(3, "TestModel");
        vehicleStmt.setInt(4, 2024);
        vehicleStmt.executeUpdate();
   
     // Test müşterisi ekle
        PreparedStatement insertCustomer = conn.prepareStatement(
            "INSERT INTO customer (customer_id, email, password_customer, first_name , last_name) VALUES (?, ?, ?,?,?) ON CONFLICT (customer_id) DO NOTHING");
        insertCustomer.setInt(1, TEST_USER_ID);
        insertCustomer.setString(2, "testuser@example.com");
        insertCustomer.setString(3, "testpass");
        insertCustomer.setString(4, "testname");
        insertCustomer.setString(5, "testlname");
        insertCustomer.executeUpdate();


        // Aynı kullanıcı+araç+tarih+tip varsa sil
        PreparedStatement deleteReq = conn.prepareStatement(
            "DELETE FROM requests WHERE user_id = ? AND vehicle_id = ? AND request_type = ? AND request_date = ?");
        deleteReq.setInt(1, TEST_USER_ID);
        deleteReq.setInt(2, TEST_VEHICLE_ID);
        deleteReq.setString(3, "price_offer");
        deleteReq.setDate(4, java.sql.Date.valueOf(LocalDate.now()));
        deleteReq.executeUpdate();
    }

    @Test
    void testPriceOfferRequestInsertion() throws Exception {
        PriceOfferRequest request = new PriceOfferRequest(TEST_USER_ID, TEST_VEHICLE_ID, LocalDate.now(), conn);
        boolean result = request.processRequest(TEST_USER_ID, TEST_VEHICLE_ID, LocalDate.now());
        assertTrue(result, "Teklif isteği başarılı olmalı");

        // Doğrula: kayıt eklendi mi?
        PreparedStatement check = conn.prepareStatement(
            "SELECT COUNT(*) FROM requests WHERE user_id = ? AND vehicle_id = ? AND request_type = ?");
        check.setInt(1, TEST_USER_ID);
        check.setInt(2, TEST_VEHICLE_ID);
        check.setString(3, "price_offer");
        ResultSet rs = check.executeQuery();
        rs.next();
        int count = rs.getInt(1);
        assertEquals(1, count, "Teklif kaydı veritabanına eklenmiş olmalı");
        
        System.out.println("Kayıt veritabanına eklenmiş mi?: " + result);

        PreparedStatement debug = conn.prepareStatement(
            "SELECT * FROM requests WHERE user_id = ? AND vehicle_id = ? AND request_type = ?");
        debug.setInt(1, TEST_USER_ID);
        debug.setInt(2, TEST_VEHICLE_ID);
        debug.setString(3, "price_offer");

        ResultSet debugRs = debug.executeQuery();
        while (debugRs.next()) {
            System.out.println("BULUNDU: Request ID=" + debugRs.getInt("request_id")
                + ", date=" + debugRs.getDate("request_date")
                + ", status=" + debugRs.getString("status"));
        }

    }

    @AfterAll
    static void cleanup() throws Exception {
    	 // Test request sil
        PreparedStatement delete = conn.prepareStatement(
            "DELETE FROM requests WHERE user_id = ? AND vehicle_id = ? AND request_type = ?");
        delete.setInt(1, TEST_USER_ID);
        delete.setInt(2, TEST_VEHICLE_ID);
        delete.setString(3, "price_offer");
        delete.executeUpdate();
        
        // Test aracını sil
        PreparedStatement deleteVehicle = conn.prepareStatement(
            "DELETE FROM vehicle WHERE vehicle_id = ?");
        deleteVehicle.setInt(1, TEST_VEHICLE_ID);
        deleteVehicle.executeUpdate();

        // Test kullanıcısını sil
        PreparedStatement deleteCustomer = conn.prepareStatement(
            "DELETE FROM customer WHERE customer_id = ?");
        deleteCustomer.setInt(1, TEST_USER_ID);
        deleteCustomer.executeUpdate();

        conn.close();
    }
}
