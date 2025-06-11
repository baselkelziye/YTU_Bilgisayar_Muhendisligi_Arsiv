package yazilim.tests;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import yazilim.CustomerCarPage;
import yazilim.classes.Customer;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.time.LocalDate;
import java.util.Date;

import static org.junit.jupiter.api.Assertions.*;

public class CustomerCarPageTest {
    private Connection conn;
    private CustomerCarPage customerCarPage;
    private final Customer customer = new Customer(100, "testuser@example.com", "Test", "User", "555555555", "male", 20, "tester", "high", "Istanbul", new Timestamp(System.currentTimeMillis()));

    @BeforeEach
    void setUp() throws SQLException {
        // Veritabanı bağlantısını açma
        String url = "jdbc:postgresql://localhost:5432/YazilimMuhProje";
        String username = "postgres";
        String password = "12345";
        conn = DriverManager.getConnection(url, username, password);

        // Test kullanıcı verisi ekleme
        try (PreparedStatement stmt = conn.prepareStatement(
                "INSERT INTO customer (customer_id, email, password_customer, first_name, last_name) VALUES (?, ?, ?, ?, ?) ON CONFLICT DO NOTHING")) {
            stmt.setInt(1, customer.getCustomerId());
            stmt.setString(2, customer.getEmail());
            stmt.setString(3, "testpassword");
            stmt.setString(4, customer.getFirstName());
            stmt.setString(5, customer.getLastName());
            stmt.executeUpdate();
        }

        // Test araç verisi ekleme (100 ID)
        try (PreparedStatement stmt = conn.prepareStatement(
                "INSERT INTO vehicle (vehicle_id, brand, model, year) VALUES (?, ?, ?, ?) ON CONFLICT DO NOTHING")) {
            stmt.setInt(1, 100);  // Vehicle ID 100 olarak ayarlandı
            stmt.setString(2, "Toyota");
            stmt.setString(3, "Corolla");
            stmt.setInt(4, 2020);
            stmt.executeUpdate();
        }

        // Test satış verisi ekleme (Vehicle ID 100 kullanarak)
        try (PreparedStatement stmt = conn.prepareStatement(
                "INSERT INTO sales (sale_id, user_id, vehicle_id, sale_date, sale_price) VALUES (?, ?, ?, ?, ?) ON CONFLICT DO NOTHING")) {
            stmt.setInt(1, 100);
            stmt.setInt(2, customer.getCustomerId());
            stmt.setInt(3, 100); 
            stmt.setDate(4, java.sql.Date.valueOf("2023-05-01"));
            stmt.setDouble(5, 300000);
            stmt.executeUpdate();
        }
        
        try (PreparedStatement stmt = conn.prepareStatement(
                "INSERT INTO vehicle (vehicle_id, brand, model, year) VALUES (?, ?, ?, ?) ON CONFLICT DO NOTHING")) {
            stmt.setInt(1, 101);
            stmt.setString(2, "Honda");
            stmt.setString(3, "Civic");
            stmt.setInt(4, 2022);
            stmt.executeUpdate();
        }

        try (PreparedStatement stmt = conn.prepareStatement(
                "INSERT INTO sales (sale_id, user_id, vehicle_id, sale_date, sale_price) VALUES (?, ?, ?, ?, ?) ON CONFLICT DO NOTHING")) {
            stmt.setInt(1, 101);
            stmt.setInt(2, customer.getCustomerId());
            stmt.setInt(3, 101);
            stmt.setDate(4, java.sql.Date.valueOf("2023-06-01"));
            stmt.setDouble(5, 500000);
            stmt.executeUpdate();
        }

        
        customerCarPage = new CustomerCarPage(customer, conn);
    }
    
  //test verilerini silme
    @AfterEach
    void tearDown() throws SQLException {
        // stock tablosundan silme
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM stock WHERE vehicle_id IN (?, ?)")) {
            stmt.setInt(1, 100);
            stmt.setInt(2, 101);
            stmt.executeUpdate();
        }

        // sales tablosundan silme
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM sales WHERE user_id = ?")) {
            stmt.setInt(1, customer.getCustomerId());
            stmt.executeUpdate();
        }

        // vehicle tablosundan silme
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM vehicle WHERE vehicle_id IN (?, ?)")) {
            stmt.setInt(1, 100);
            stmt.setInt(2, 101);
            stmt.executeUpdate();
        }

        // customer tablosundan silme
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM customer WHERE customer_id = ?")) {
            stmt.setInt(1, customer.getCustomerId());
            stmt.executeUpdate();
        }

        if (conn != null && !conn.isClosed()) {
            conn.close();
        }
    }


    @Test
    void testLoadPurchasedCars() {
    	System.out.println("\n=== Testing Purchased Cars ===");
    	JTable table = customerCarPage.table;
        DefaultTableModel model = (DefaultTableModel) table.getModel();
        int rowCount = model.getRowCount();
        System.out.println("Row count: " + rowCount);

        // Tablodaki tüm verileri yazdırma
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < model.getColumnCount(); j++) {
                System.out.print("Cell (" + i + "," + j + "): " + model.getValueAt(i, j) + "\t");
            }
            System.out.println();
        }

        assertEquals(2, rowCount, "Table should contain two purchased cars.");

        // İlk satırın doğru olduğunu kontrol etme
        String vehicleName1 = (String) model.getValueAt(0, 0);
        String saleDate1 = (String) model.getValueAt(0, 1);
        String salePrice1 = (String) model.getValueAt(0, 2);

        System.out.println("Expected: Honda Civic (2022)");
        System.out.println("Actual: " + vehicleName1);
        System.out.println("Expected price: 500000,00 TL");
        System.out.println("Actual price: " + salePrice1);

        assertEquals("Honda Civic (2022)", vehicleName1);
        assertEquals("2023-06-01", saleDate1);
        assertEquals("500000,00 TL", salePrice1);

        // İkinci satırın doğru olduğunu kontrol etme
        String vehicleName2 = (String) model.getValueAt(1, 0);
        String saleDate2 = (String) model.getValueAt(1, 1);
        String salePrice2 = (String) model.getValueAt(1, 2);

        System.out.println("Expected: Toyota Corolla (2020)");
        System.out.println("Actual: " + vehicleName2);
        System.out.println("Expected price: 300000,00 TL");
        System.out.println("Actual price: " + salePrice2);

        assertEquals("Toyota Corolla (2020)", vehicleName2);
        assertEquals("2023-05-01", saleDate2);
        assertEquals("300000,00 TL", salePrice2);
    }



    @Test
    void testEmptyPurchasedCars() throws SQLException {
        System.out.println("\n=== Testing Empty Purchased Cars ===");
        System.out.println("Clearing all sales for user ID: " + customer.getCustomerId());

        // Tüm satışları temizle
        try (PreparedStatement stmt = conn.prepareStatement("DELETE FROM sales WHERE user_id = ?")) {
            stmt.setInt(1, customer.getCustomerId());
            int rowsDeleted = stmt.executeUpdate();
            System.out.println("Deleted " + rowsDeleted + " sales records for user ID: " + customer.getCustomerId());
        }

        // Test edilen sınıfı yeniden başlatma
        customerCarPage = new CustomerCarPage(customer, conn);

       
        JTable table = customerCarPage.table;
        DefaultTableModel model = (DefaultTableModel) table.getModel();
        int rowCount = model.getRowCount();
        System.out.println("Row count after clearing sales: " + rowCount);

        // Tablodaki tüm verileri yazdırma
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < model.getColumnCount(); j++) {
                System.out.print("Cell (" + i + "," + j + "): " + model.getValueAt(i, j) + "\t");
            }
            System.out.println();
        }

        // Boş tablo mesajını kontrol etme
        assertEquals(1, rowCount, "Table should show a message if no cars have been purchased.");
        String message = (String) model.getValueAt(0, 0);
        System.out.println("Expected message: Henüz araç satın alınmamış.");
        System.out.println("Actual message: " + message);
        assertEquals("Henüz araç satın alınmamış.", message);
    }

}

