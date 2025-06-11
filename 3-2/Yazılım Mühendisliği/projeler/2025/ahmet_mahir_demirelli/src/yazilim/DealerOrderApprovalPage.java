package yazilim;

import javax.swing.*;
import yazilim.classes.Dealer;
import java.awt.*;
import java.math.BigDecimal;
import java.sql.*;
import java.util.ArrayList;

public class DealerOrderApprovalPage {
    private JFrame frame;
    private Connection conn;
    private DefaultListModel<String> orderModel = new DefaultListModel<>();
    private JList<String> orderList;
    private ArrayList<Integer> orderRequestIds = new ArrayList<>();
    private Dealer dealer;

    public DealerOrderApprovalPage(Connection conn, Dealer dealer) {
        this.conn = conn;
        this.dealer = dealer;
        initialize();
    }

    private void initialize() {
        frame = new JFrame("Satış Onayı");
        frame.setBounds(100, 100, 600, 400);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setLayout(new BorderLayout(10, 10));
        frame.getContentPane().setBackground(Color.WHITE);

        JLabel titleLabel = new JLabel("Bekleyen Sipariş Talepleri", SwingConstants.CENTER);
        titleLabel.setFont(new Font("SansSerif", Font.BOLD, 16));
        frame.add(titleLabel, BorderLayout.NORTH);

        orderList = new JList<>(orderModel);
        orderList.setFont(new Font("SansSerif", Font.PLAIN, 14));
        orderList.setVisibleRowCount(10);
        frame.add(new JScrollPane(orderList), BorderLayout.CENTER);

        JPanel bottomPanel = new JPanel(new FlowLayout());
        bottomPanel.setBackground(Color.WHITE);
        JButton approveBtn = new JButton("✅ Onayla");
        JButton rejectBtn = new JButton("❌ Reddet");
        styleButton(approveBtn);
        styleButton(rejectBtn);
        bottomPanel.add(approveBtn);
        bottomPanel.add(rejectBtn);
        frame.add(bottomPanel, BorderLayout.SOUTH);

        loadOrders();

        approveBtn.addActionListener(e -> {
            int index = orderList.getSelectedIndex();
            if (index != -1) {
                try {
                    int requestId = orderRequestIds.get(index);

                    // Get user_id and vehicle_id from requests
                    PreparedStatement selectStmt = conn.prepareStatement(
                        "SELECT user_id, vehicle_id FROM requests WHERE request_id = ?"
                    );
                    selectStmt.setInt(1, requestId);
                    ResultSet rs = selectStmt.executeQuery();

                    if (rs.next()) {
                        int userId = rs.getInt("user_id");
                        int vehicleId = rs.getInt("vehicle_id");

                        // Get price from price_offers
                        PreparedStatement priceStmt = conn.prepareStatement(
                            "SELECT offered_price FROM price_offers WHERE user_id = ? AND vehicle_id = ?"
                        );
                        priceStmt.setInt(1, userId);
                        priceStmt.setInt(2, vehicleId);
                        ResultSet priceRs = priceStmt.executeQuery();

                        double price = 0.0;
                        if (priceRs.next()) {
                            price = priceRs.getDouble("offered_price");
                        }

                        // First, reduce stock
                        PreparedStatement updateStockStmt = conn.prepareStatement(
                            "UPDATE stock SET quantity = quantity - 1, updated_at = CURRENT_TIMESTAMP " +
                            "WHERE vehicle_id = ? AND location_type = 'dealer' AND quantity > 0"
                        );
                        updateStockStmt.setInt(1, vehicleId);
                        int updatedRows = updateStockStmt.executeUpdate();

                        if (updatedRows == 0) {
                            JOptionPane.showMessageDialog(frame, "Stokta yeterli araç bulunamadı!", "Stok Hatası", JOptionPane.ERROR_MESSAGE);
                            return;
                        }

                        // Update request status to accepted
                        PreparedStatement ps = conn.prepareStatement(
                            "UPDATE requests SET status = 'accepted' WHERE request_id = ?"
                        );
                        ps.setInt(1, requestId);
                        ps.executeUpdate();

                        // Insert into sales
                        PreparedStatement insertStmt = conn.prepareStatement(
                            "INSERT INTO sales (user_id, vehicle_id, sale_date, sale_price) VALUES (?, ?, CURRENT_DATE, ?)"
                        );
                        insertStmt.setInt(1, userId);
                        insertStmt.setInt(2, vehicleId);
                        insertStmt.setDouble(3, price);
                        insertStmt.executeUpdate();

                        // Delete from price_offers
                        PreparedStatement deletePrice = conn.prepareStatement(
                            "DELETE FROM price_offers WHERE user_id = ? AND vehicle_id = ?"
                        );
                        deletePrice.setInt(1, userId);
                        deletePrice.setInt(2, vehicleId);
                        deletePrice.executeUpdate();
                    }

                    JOptionPane.showMessageDialog(frame, "Sipariş onaylandı, satış kaydedildi ve teklif silindi.");
                    loadOrders();
                } catch (Exception ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(frame, "Hata oluştu.");
                }
            }
        });

        rejectBtn.addActionListener(e -> {
            int index = orderList.getSelectedIndex();
            if (index != -1) {
                try {
                    int requestId = orderRequestIds.get(index);
                    PreparedStatement ps = conn.prepareStatement(
                        "UPDATE requests SET status = 'rejected' WHERE request_id = ?"
                    );
                    ps.setInt(1, requestId);
                    ps.executeUpdate();
                    JOptionPane.showMessageDialog(frame, "Sipariş reddedildi.");
                    loadOrders();
                } catch (Exception ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(frame, "Hata oluştu.");
                }
            }
        });

        frame.setVisible(true);
    }

    private void styleButton(JButton button) {
        button.setFont(new Font("SansSerif", Font.PLAIN, 14));
        button.setFocusPainted(false);
        button.setBackground(new Color(230, 230, 230));
    }

    private void loadOrders() {
        orderModel.clear();
        orderRequestIds.clear();
        try {
            String query = """
                SELECT request_id, user_id, vehicle_id, request_date
                FROM requests r
                WHERE request_type = 'order' AND status = 'pending'
            """;

            PreparedStatement ps = conn.prepareStatement(query);
            ResultSet rs = ps.executeQuery();

            while (rs.next()) {
                int orderRequestId = rs.getInt("request_id");
                int userId = rs.getInt("user_id");
                int vehicleId = rs.getInt("vehicle_id");
                Date date = rs.getDate("request_date");
                
                query = "SELECT brand, model, year, package FROM vehicle WHERE vehicle_id = ?;";
                PreparedStatement ps1 = conn.prepareStatement(query);
                ps1.setInt(1, vehicleId);
                ResultSet rs1 = ps1.executeQuery();
                String brand = "";
                String model = "";
                int year = 0;
                String pckg = "";
                while(rs1.next()) {
                	brand = rs1.getString("brand");
                	model = rs1.getString("model");
                	year = rs1.getInt("year");
                	pckg = rs1.getString("package");
                }
                
                query = "SELECT request_id FROM requests WHERE request_id < ? AND user_id = ? AND vehicle_id = ? AND request_type = 'price_offer' AND status = 'accepted' ORDER BY request_id DESC LIMIT 1;";
                PreparedStatement ps2 = conn.prepareStatement(query);
                ps2.setInt(1, orderRequestId);
                ps2.setInt(2, userId);
                ps2.setInt(3, vehicleId);
                ResultSet rs2 = ps2.executeQuery();
                int priceOfferRequestId = 0;
                while(rs2.next()) {
                	priceOfferRequestId = rs2.getInt("request_id");
                }
                
                query = "SELECT offered_price FROM price_offers WHERE request_id = ?;";
                PreparedStatement ps3 = conn.prepareStatement(query);
                ps3.setInt(1, priceOfferRequestId);
                ResultSet rs3 = ps3.executeQuery();
                BigDecimal price = new BigDecimal(0.00);
                while(rs3.next()) {
                	price = rs3.getBigDecimal("offered_price");
                }
                
                String line = "Kullanıcı: " + userId + ", Araç: " + brand + " " + model + " (" + year + ") " + pckg + ", Fiyat: " + String.format("%.2f TL", price) + ", Tarih: " + date;
                orderModel.addElement(line);
                orderRequestIds.add(orderRequestId);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
