package yazilim;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.sql.*;

public class ShowCarStockPage {
    private JFrame frame;
    private JTable warehouseTable;
    private JTable dealerTable;
    private Connection conn;

    public ShowCarStockPage(Connection conn) {
        this.conn = conn;
        initialize();
    }

    private void initialize() {
        frame = new JFrame("Depo ve Bayi Araç Stokları");
        frame.setSize(850, 600);
        frame.setLocationRelativeTo(null); // ekran ortasına yerleştir
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
        mainPanel.setBackground(new Color(245, 245, 245)); // açık gri arka plan

        // Ortak font
        Font titleFont = new Font("Segoe UI", Font.BOLD, 18);

        // Depo başlık
        JLabel warehouseLabel = new JLabel("Depo Stokları", SwingConstants.LEFT);
        warehouseLabel.setFont(titleFont);
        warehouseLabel.setBorder(BorderFactory.createEmptyBorder(10, 10, 5, 10));

        // Depo tablo modeli ve tablo
        DefaultTableModel warehouseModel = new DefaultTableModel(new Object[]{"Marka", "Model", "Yıl", "Paket", "Fiyat", "Adet"}, 0);
        warehouseTable = new JTable(warehouseModel);
        JScrollPane warehouseScrollPane = new JScrollPane(warehouseTable);
        warehouseScrollPane.setBorder(BorderFactory.createLineBorder(Color.GRAY));
        warehouseScrollPane.setPreferredSize(new Dimension(800, 180));

        // Bayi başlık
        JLabel dealerLabel = new JLabel("Bayi Stokları", SwingConstants.LEFT);
        dealerLabel.setFont(titleFont);
        dealerLabel.setBorder(BorderFactory.createEmptyBorder(20, 10, 5, 10));

        // Bayi tablo modeli ve tablo
        DefaultTableModel dealerModel = new DefaultTableModel(new Object[]{"Marka", "Model", "Yıl", "Paket", "Fiyat", "Adet"}, 0);
        dealerTable = new JTable(dealerModel);
        JScrollPane dealerScrollPane = new JScrollPane(dealerTable);
        dealerScrollPane.setBorder(BorderFactory.createLineBorder(Color.GRAY));
        dealerScrollPane.setPreferredSize(new Dimension(800, 180));

        // Verileri yükle
        loadStockData("warehouse", warehouseModel);
        loadStockData("dealer", dealerModel);

        // Panelleri sırayla ekle
        mainPanel.add(warehouseLabel);
        mainPanel.add(warehouseScrollPane);
        mainPanel.add(dealerLabel);
        mainPanel.add(dealerScrollPane);

        frame.add(mainPanel);
        frame.setVisible(true);
    }


    private void loadStockData(String locationType, DefaultTableModel model) {
        try {
            String query = "SELECT v.brand, v.model, v.year, v.package, v.price, s.quantity " +
                           "FROM stock s JOIN vehicle v ON s.vehicle_id = v.vehicle_id " +
                           "WHERE s.location_type = ?";
            PreparedStatement ps = conn.prepareStatement(query);
            ps.setString(1, locationType);
            ResultSet rs = ps.executeQuery();

            while (rs.next()) {
                String brand = rs.getString("brand");
                String modelStr = rs.getString("model");
                int year = rs.getInt("year");
                String pckg = rs.getString("package");
                double price = rs.getDouble("price");
                int quantity = rs.getInt("quantity");

                model.addRow(new Object[]{brand, modelStr, year, pckg, price, quantity});
            }

            rs.close();
            ps.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}