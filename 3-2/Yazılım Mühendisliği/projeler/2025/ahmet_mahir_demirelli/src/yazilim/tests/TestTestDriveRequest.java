package yazilim.tests;

import static org.junit.jupiter.api.Assertions.*;

import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Timestamp;
import java.time.LocalDate;
import org.junit.jupiter.api.*;
import yazilim.classes.Customer;
import yazilim.classes.Vehicle;
import yazilim.requests.TestDriveRequest;

class TestTestDriveRequest {
    private static Connection conn;
    private static final int TEST_USER_ID = 9000000;
    private static final int TEST_VEHICLE_ID = 9000000;

    private static Customer testCustomer;
    private static Vehicle testVehicle;

    @BeforeAll
    static void setUpBeforeClass() throws Exception {
        conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");

        testCustomer = new Customer(TEST_USER_ID, "testuser@example.com", "Test", "User", "555555555", "male", 20, "tester", "high", "Istanbul", new Timestamp(System.currentTimeMillis()));
        testVehicle = new Vehicle(TEST_VEHICLE_ID, "MarkaX", "ModelY", 2024, "Basic", new BigDecimal("25000.00"));

        PreparedStatement insertCustomer = conn.prepareStatement(
            "INSERT INTO customer (customer_id, email, password_customer, first_name, last_name, phone_number, gender, age, profession, income_level, city, first_visit_date) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?) ON CONFLICT (customer_id) DO NOTHING");
        insertCustomer.setInt(1, testCustomer.getCustomerId());
        insertCustomer.setString(2, testCustomer.getEmail());
        insertCustomer.setString(3, "test_password");
        insertCustomer.setString(4, testCustomer.getFirstName());
        insertCustomer.setString(5, testCustomer.getLastName());
        insertCustomer.setString(6, testCustomer.getPhoneNumber());
        insertCustomer.setString(7, testCustomer.getGender());
        insertCustomer.setInt(8, testCustomer.getAge());
        insertCustomer.setString(9, testCustomer.getProfession());
        insertCustomer.setString(10, testCustomer.getIncomeLevel());
        insertCustomer.setString(11, testCustomer.getCity());
        insertCustomer.setTimestamp(12, testCustomer.getFirstVisitDate());
        insertCustomer.executeUpdate();


        PreparedStatement insertVehicle = conn.prepareStatement(
        		"INSERT INTO vehicle (vehicle_id, brand, model, year, package, price) VALUES (?, ?, ?, ?, ?, ?) ON CONFLICT (vehicle_id) DO NOTHING");
        insertVehicle.setInt(1, testVehicle.getVehicleId());
        insertVehicle.setString(2, testVehicle.getBrand());
        insertVehicle.setString(3, testVehicle.getModel());
        insertVehicle.setInt(4, testVehicle.getYear());
        insertVehicle.setString(5, testVehicle.getPckg());
        insertVehicle.setBigDecimal(6, testVehicle.getPrice());
        insertVehicle.executeUpdate();

        PreparedStatement deleteStmt = conn.prepareStatement(
        		"DELETE FROM requests WHERE user_id = ? AND vehicle_id = ? AND request_type = ?");
        deleteStmt.setInt(1, TEST_USER_ID);
        deleteStmt.setInt(2, TEST_VEHICLE_ID);
        deleteStmt.setString(3, "test_drive");
        deleteStmt.executeUpdate();

    }

    @Test
    void testSuccessRequest() throws Exception {
        LocalDate today = LocalDate.now();
        TestDriveRequest request = new TestDriveRequest(testCustomer.getCustomerId(), testVehicle.getVehicleId(), today, conn);

        boolean result = request.processRequest(testCustomer.getCustomerId(), testVehicle.getVehicleId(), today);
        assertTrue(result, "Geçerli kullanıcı ve araç id'si ile istek başarılı olmalı");
    }

    @Test
    void testInvalidUserIdRequest() throws Exception {
        LocalDate today = LocalDate.now();
        int invalidUserId = -1;  // Geçersiz kullanıcı id'si

        TestDriveRequest request = new TestDriveRequest(invalidUserId, testVehicle.getVehicleId(), today, conn);

        boolean result = request.processRequest(invalidUserId, testVehicle.getVehicleId(), today);
        assertFalse(result, "Geçersiz kullanıcı id'si ile istek başarısız olmalı");
    }

    @Test
    void testInvalidVehicleIdRequest() throws Exception {
        LocalDate today = LocalDate.now();
        int invalidVehicleId = -123;  // Geçersiz araç id'si

        TestDriveRequest request = new TestDriveRequest(testCustomer.getCustomerId(), invalidVehicleId, today, conn);

        boolean result = request.processRequest(testCustomer.getCustomerId(), invalidVehicleId, today);
        assertFalse(result, "Geçersiz araç id'si ile istek başarısız olmalı");
    }

    @Test
    void testSuccessRequestDatabaseCorrectness() throws Exception {
        LocalDate today = LocalDate.now();

        TestDriveRequest request = new TestDriveRequest(testCustomer.getCustomerId(), testVehicle.getVehicleId(), today, conn);
        boolean result = request.processRequest(testCustomer.getCustomerId(), testVehicle.getVehicleId(), today);
        assertTrue(result, "İstek başarılı olmalı");

        // Gönderilen istek ile veritabanındaki kayıt aynı olmalı
        PreparedStatement stmt = conn.prepareStatement(
            "SELECT user_id, vehicle_id, request_type, request_date, status FROM requests " +
            "WHERE user_id = ? AND vehicle_id = ? AND request_type = ?");
        stmt.setInt(1, testCustomer.getCustomerId());
        stmt.setInt(2, testVehicle.getVehicleId());
        stmt.setString(3, "test_drive");

        ResultSet rs = stmt.executeQuery();

        assertTrue(rs.next(), "Veritabanında kayıt bulunmalı");

        assertEquals(testCustomer.getCustomerId(), rs.getInt("user_id"), "Kullanıcı id'si doğru olmalı");
        assertEquals(testVehicle.getVehicleId(), rs.getInt("vehicle_id"), "Araç id'si doğru olmalı");
        assertEquals("test_drive", rs.getString("request_type"), "İstek tipi doğru olmalı");
        assertEquals(today, rs.getDate("request_date").toLocalDate(), "Tarih doğru olmalı");
        assertEquals("pending", rs.getString("status"), "Durum doğru olmalı");
    }

    @AfterAll
    static void tearDownAfterClass() throws Exception {
        if (conn != null && !conn.isClosed()) {
            PreparedStatement deleteRequests = conn.prepareStatement(
                "DELETE FROM requests WHERE user_id = ? OR vehicle_id = ?");
            deleteRequests.setInt(1, TEST_USER_ID);
            deleteRequests.setInt(2, TEST_VEHICLE_ID);
            deleteRequests.executeUpdate();

            PreparedStatement deleteVehicle = conn.prepareStatement(
                "DELETE FROM vehicle WHERE vehicle_id = ?");
            deleteVehicle.setInt(1, TEST_VEHICLE_ID);
            deleteVehicle.executeUpdate();

            PreparedStatement deleteCustomer = conn.prepareStatement(
                "DELETE FROM customer WHERE customer_id = ?");
            deleteCustomer.setInt(1, TEST_USER_ID);
            deleteCustomer.executeUpdate();

            conn.close();
        }
    }
}
