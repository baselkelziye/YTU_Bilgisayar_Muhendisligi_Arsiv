package yazilim.tests;

import org.junit.jupiter.api.*;
import yazilim.AddCarToStockPage;
import yazilim.classes.Vehicle;
import yazilim.classes.Warehouse;
import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import static org.junit.jupiter.api.Assertions.*;

public class testAddCarToStock {
    private static Connection conn;
    private AddCarToStockPage page;
    private static Warehouse warehouse = new Warehouse(2, "warehouse@example.com");
    private final static Vehicle vehicle = new Vehicle(126, "Lamborghini", "Huracan", 2021, "Full", BigDecimal.valueOf(15000000.00));

    @BeforeAll
    public static void setUp() throws SQLException {
    	System.out.println("\n===== Testing Add Vehicle To Stock =====");
        conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");

        try (PreparedStatement stmt = conn.prepareStatement(
         "INSERT INTO warehouse (id, email, password) VALUES (?, ?, ?) ON CONFLICT DO NOTHING")) {
            stmt.setInt(1, warehouse.getId());
            stmt.setString(2, warehouse.getEmail());
            stmt.setString(3, "testpassword");
            stmt.executeUpdate();
        }
    }

    @BeforeEach
    public void init() {
        page = new AddCarToStockPage(warehouse, conn);
    }
    
    // Yeni araç ekleme
    @Test
    public void testAddVehicle_1() {
    	System.out.println("\n=== testAddVehicle_1 Started ===");
        int result = page.addCarToStock(vehicle.getBrand(), vehicle.getModel(), vehicle.getYear(), vehicle.getPckg(), vehicle.getPrice(), 5);
        assertTrue(result == 1, "Volkswagen Polo 2021 Full paket ekleme başarılı olmalı.");
        System.out.println("Volkswagen Polo 2021 Full paket eklemesi beklendiği gibi başarılı oldu.");
        int expectedStock = 5;
        int actualStock = getWarehouseStockForVehicle(getVehicleIdFromFeatures(vehicle.getBrand(), vehicle.getModel(), vehicle.getYear(), vehicle.getPckg()));
        assertEquals(expectedStock, actualStock, "Depodaki stok 5 olmalı.");
        System.out.println("Volkswagen Polo 2021 Full için depodaki stok=5 doğrulandı.");
    }

    // Zaten olan bir aracı eklemeye çalışma
    @Test
    public void testAddVehicle_2() {
    	System.out.println("\n=== testAddVehicle_2 Started ===");
    	int result = page.addCarToStock(vehicle.getBrand(), vehicle.getModel(), vehicle.getYear(), vehicle.getPckg(), vehicle.getPrice(), 5);
        assertTrue(result == 0, "Volkswagen Polo 2021 Full paket ekleme başarısız olmalı.");
        System.out.println("Volkswagen Polo 2021 Full paket eklemesi zaten kayıtlı araç olduğu için beklendiği gibi başarısız oldu.");
    }

    @AfterAll
    public static void closeConnection() throws Exception {
    	vehicle.setVehicleId(getVehicleIdFromFeatures(vehicle.getBrand(), vehicle.getModel(), vehicle.getYear(), vehicle.getPckg()));
    	try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM stock WHERE vehicle_id = ?")) {
            stmt.setInt(1, vehicle.getVehicleId());
            stmt.executeUpdate();
        }
        
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM vehicle WHERE vehicle_id = ?")) {
            stmt.setInt(1, vehicle.getVehicleId());
            stmt.executeUpdate();
        }

        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM warehouse WHERE id = ?")) {
            stmt.setInt(1, warehouse.getId());
            stmt.executeUpdate();
        }
    	
        if (conn != null && !conn.isClosed()) {
            conn.close();
        }
    }
    
    private static int getVehicleIdFromFeatures(String brand, String model, int year, String pckg) {
        int vehicle_id = 0;
        String query = "SELECT vehicle_id FROM vehicle WHERE brand = ? AND model = ? AND year = ? AND package = ?;";
        PreparedStatement stmt;
		try {
			stmt = conn.prepareStatement(query);
			stmt.setString(1, brand);
	        stmt.setString(2, model);
	        stmt.setInt(3, year);
	        stmt.setString(4, pckg);
	        ResultSet rs = stmt.executeQuery();
	        if (rs.next()) {
	        	vehicle_id = rs.getInt("vehicle_id");
	        }
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

        return vehicle_id;
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
}