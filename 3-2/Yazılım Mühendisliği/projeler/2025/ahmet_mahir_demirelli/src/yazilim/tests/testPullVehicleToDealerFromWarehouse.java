package yazilim.tests;

import org.junit.jupiter.api.*;
import yazilim.PullCarFromStockPage;
import yazilim.classes.Vehicle;
import yazilim.classes.Dealer;
import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Timestamp;
import static org.junit.jupiter.api.Assertions.*;

public class testPullVehicleToDealerFromWarehouse {
    private static Connection conn;
    private PullCarFromStockPage page;
    private final static Dealer dealer = new Dealer(340, "dealer@example.com");
    private final static Vehicle vehicle_1 = new Vehicle(124, "Volkswagen", "Tiguan", 2021, "Full", BigDecimal.valueOf(1500000.00));
    private final static Vehicle vehicle_2 = new Vehicle(125, "Ford", "Focus", 2021, "Full", BigDecimal.valueOf(1500000.00));
    private static int stockId = 100;
    
    
    @BeforeAll
    public static void setUp() throws SQLException {
    	System.out.println("\n=== Testing Pull Vehicle To Dealer From Warehouse ===");
        conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");

        try (PreparedStatement stmt = conn.prepareStatement(
         "INSERT INTO dealer (id, email, password) VALUES (?, ?, ?) ON CONFLICT DO NOTHING")) {
            stmt.setInt(1, dealer.getId());
            stmt.setString(2, dealer.getEmail());
            stmt.setString(3, "testpassword");
            stmt.executeUpdate();
        }

        // Araç 1 ekle
        try (PreparedStatement stmt = conn.prepareStatement(
                "INSERT INTO vehicle (vehicle_id, brand, model, year, package, price) VALUES (?, ?, ?, ?, ? ,?) ON CONFLICT DO NOTHING")) {
            stmt.setInt(1, vehicle_1.getVehicleId());
            stmt.setString(2, vehicle_1.getBrand());
            stmt.setString(3, vehicle_1.getModel());
            stmt.setInt(4, vehicle_1.getYear());
            stmt.setString(5, vehicle_1.getPckg());
            stmt.setBigDecimal(6, vehicle_1.getPrice());
            stmt.executeUpdate();
        }

        // Araç 1 stoğa ekle
        try (PreparedStatement stmt = conn.prepareStatement(
                "INSERT INTO stock (stock_id, vehicle_id, location_type, quantity, updated_at) VALUES (?, ?, ?, ?, ?) ON CONFLICT DO NOTHING")) {
            stmt.setInt(1, stockId);
            stmt.setInt(2, vehicle_1.getVehicleId());
            stmt.setString(3, "warehouse");
            stmt.setInt(4, 5);
            stmt.setTimestamp(5, new Timestamp(System.currentTimeMillis()));
            stmt.executeUpdate();
        }
        
     // Araç 2 ekle
        try (PreparedStatement stmt = conn.prepareStatement(
                "INSERT INTO vehicle (vehicle_id, brand, model, year, package, price) VALUES (?, ?, ?, ?, ? ,?) ON CONFLICT DO NOTHING")) {
            stmt.setInt(1, vehicle_2.getVehicleId());
            stmt.setString(2, vehicle_2.getBrand());
            stmt.setString(3, vehicle_2.getModel());
            stmt.setInt(4, vehicle_2.getYear());
            stmt.setString(5, vehicle_2.getPckg());
            stmt.setBigDecimal(6, vehicle_2.getPrice());
            stmt.executeUpdate();
        }

        // Araç 2 stoğa ekle
        try (PreparedStatement stmt = conn.prepareStatement(
                "INSERT INTO stock (stock_id, vehicle_id, location_type, quantity, updated_at) VALUES (?, ?, ?, ?, ?) ON CONFLICT DO NOTHING")) {
            stmt.setInt(1, stockId + 1);
            stmt.setInt(2, vehicle_2.getVehicleId());
            stmt.setString(3, "dealer");
            stmt.setInt(4, 2);
            stmt.setTimestamp(5, new Timestamp(System.currentTimeMillis()));
            stmt.executeUpdate();
        }
    }
    
    @BeforeEach
    public void init() {
    	page = new PullCarFromStockPage(dealer, conn);
    }
    
    // Depodan araç çekiyor
    @Test
    public void testPullVehicle_1() {
    	System.out.println("\n=== testPullVehicle_1 Started ===");
        int result = page.pullVehicleToDealerFromWarehouse(vehicle_1.getVehicleId(), 2);
        assertTrue(result == 1, "Araç çekme işlemi başarılı olmalı. (AraÇ ID: " + vehicle_1.getVehicleId() + ")");
        System.out.println(vehicle_1.getVehicleId() + " Id'li aracı bayiye çekme işlemi beklendiği gibi başarılı oldu.");
        int expectedStock = 3;
        int actualStock = getWarehouseStockForVehicle(vehicle_1.getVehicleId());
        assertEquals(expectedStock, actualStock, "Depodaki stok 3 olmalı.");
        System.out.println(vehicle_1.getVehicleId() + " Id'li araç için stock=3 kaldığı doğrulandı.");
    }
    
    // Zaten bayide olan aracı çekmeye çalışıyor
    @Test
    public void testPullVehicle_2() {
    	System.out.println("\n=== testPullVehicle_2 Started ===");
        int result = page.pullVehicleToDealerFromWarehouse(vehicle_2.getVehicleId(), 1);
        assertFalse(result == 0, "Araç çekme işlemi başarısız olmalı. (AraÇ ID: "+ vehicle_2.getVehicleId() + ")");
        System.out.println(vehicle_2.getVehicleId() + " Id'li araç zaten bayide olduğu için çekme işlemi beklendiği gibi başarısız oldu.");
    }
    
    // Stoktan daha fazla talep ediyor
    @Test
    public void testPullVehicle_3() {
    	System.out.println("\n=== testPullVehicle_3 Started ===");
        int result = page.pullVehicleToDealerFromWarehouse(vehicle_1.getVehicleId(), 5);
        assertTrue(result == -1, "Araç çekme işlemi stok yetersizliği sebebi ile beklendiği gibi başarısız oldu.");
        System.out.println(vehicle_1.getVehicleId() + " Id'li aracı bayiye çekme işlemi stok yetersizliği sebebi ile beklendiği gibi başarısız oldu.");
    }
    
    // Depoda araç kalmayacak şekilde çekiyor
    @Test
    public void testPullVehicle_4() {
    	System.out.println("\n=== testPullVehicle_4 Started ===");
        int result = page.pullVehicleToDealerFromWarehouse(vehicle_1.getVehicleId(), 3);
        assertTrue(result == 1, "Araç çekme işlemi başarılı olmalı (AraÇ ID: " + vehicle_1.getVehicleId() + ")");
        System.out.println(vehicle_1.getVehicleId() + " Id'li aracı bayiye çekme işlemi beklendiği gibi başarılı oldu.");
        int remainingRows = getWarehouseStockRowCount(vehicle_1.getVehicleId());
        assertEquals(0, remainingRows, "Depoda bu araçtan kayıt kalmamalı (Araç ID: " + vehicle_1.getVehicleId() + ")");
        System.out.println(vehicle_1.getVehicleId() + " Id'li araçtan depoda kalmadığı doğrulandı.");
    }
    
    
    @AfterAll
    public static void tearDown() throws SQLException {
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM stock WHERE vehicle_id = ?")) {
            stmt.setInt(1, vehicle_1.getVehicleId());
            stmt.executeUpdate();
        }
        
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM stock WHERE vehicle_id = ?")) {
            stmt.setInt(1, vehicle_2.getVehicleId());
            stmt.executeUpdate();
        }
        
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM vehicle WHERE vehicle_id = ?")) {
            stmt.setInt(1, vehicle_1.getVehicleId());
            stmt.executeUpdate();
        }
        
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM vehicle WHERE vehicle_id = ?")) {
            stmt.setInt(1, vehicle_2.getVehicleId());
            stmt.executeUpdate();
        }

        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM warehouse WHERE id = ?")) {
            stmt.setInt(1, dealer.getId());
            stmt.executeUpdate();
        }

        if (conn != null && !conn.isClosed()) {
            conn.close();
        }
    }
    
    
    private int getWarehouseStockForVehicle(int vehicleId) {
        int stock = -1;
        try (PreparedStatement stmt = conn.prepareStatement(
                "SELECT quantity FROM stock WHERE vehicle_id = ? AND location_type = 'warehouse'")) {
            stmt.setInt(1, vehicleId);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                stock = rs.getInt("quantity");
            }
        } catch (SQLException e) {
            e.printStackTrace();
            fail("Veritabanı hatası: " + e.getMessage());
        }
        return stock;
    }
    
    private int getWarehouseStockRowCount(int vehicleId) {
        int count = -1;
        try (PreparedStatement stmt = conn.prepareStatement(
                "SELECT COUNT(*) FROM stock WHERE vehicle_id = ? AND location_type = 'warehouse'")) {
            stmt.setInt(1, vehicleId);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                count = rs.getInt(1);
            }
        } catch (SQLException e) {
            e.printStackTrace();
            fail("Veritabanı hatası: " + e.getMessage());
        }
        return count;
    }
}