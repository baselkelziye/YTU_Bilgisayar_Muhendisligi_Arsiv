package yazilim;

import javax.swing.*;
import yazilim.classes.Dealer;
import java.awt.*;
import java.awt.event.*;
import java.math.BigDecimal;
import java.sql.*;
import java.util.ArrayList;

public class DealerRequestPage {
    private JFrame frame;
    private Connection conn;
    private Dealer dealer;
    private DefaultListModel<String> priceModel = new DefaultListModel<>();
    private DefaultListModel<String> testDriveModel = new DefaultListModel<>();
    private JList<String> priceList;
    private JList<String> testDriveList;
    private ArrayList<Integer> priceRequestIds = new ArrayList<>();
    private ArrayList<Integer> testDriveRequestIds = new ArrayList<>();

    public DealerRequestPage(Connection conn, Dealer dealer) {
        this.conn = conn;
        this.dealer = dealer;
        initialize();
    }

    private void initialize() {
        frame = new JFrame("Talepleri Göster");
        frame.setBounds(100, 100, 900, 450);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setLayout(new GridLayout(1, 2, 20, 0));
        frame.getContentPane().setBackground(Color.WHITE);

        Font defaultFont = new Font("SansSerif", Font.PLAIN, 14);
        Color buttonColor = new Color(230, 230, 230);

        // Price Offer Panel
        JPanel pricePanel = new JPanel(new BorderLayout(10, 10));
        pricePanel.setBackground(Color.WHITE);
        JLabel priceLabel = new JLabel("Fiyat Teklif Talepleri", SwingConstants.CENTER);
        priceLabel.setFont(defaultFont);
        pricePanel.add(priceLabel, BorderLayout.NORTH);

        priceList = new JList<>(priceModel);
        priceList.setFont(defaultFont);
        priceList.setVisibleRowCount(10);
        JScrollPane priceScroll = new JScrollPane(priceList);
        pricePanel.add(priceScroll, BorderLayout.CENTER);

        JPanel priceBottom = new JPanel(new FlowLayout(FlowLayout.LEFT));
        priceBottom.setBackground(Color.WHITE);
        JTextField priceField = new JTextField(10);
        priceField.setFont(defaultFont);
        JButton approvePriceBtn = new JButton("✅ Onayla");
        styleButton(approvePriceBtn, buttonColor);
        priceBottom.add(new JLabel("Fiyat: ")).setFont(defaultFont);
        priceBottom.add(priceField);
        priceBottom.add(approvePriceBtn);
        pricePanel.add(priceBottom, BorderLayout.SOUTH);

        // Test Drive Panel
        JPanel testPanel = new JPanel(new BorderLayout(10, 10));
        testPanel.setBackground(Color.WHITE);
        JLabel testLabel = new JLabel("Test Sürüş Talepleri", SwingConstants.CENTER);
        testLabel.setFont(defaultFont);
        testPanel.add(testLabel, BorderLayout.NORTH);

        testDriveList = new JList<>(testDriveModel);
        testDriveList.setFont(defaultFont);
        testDriveList.setVisibleRowCount(10);
        JScrollPane testScroll = new JScrollPane(testDriveList);
        testPanel.add(testScroll, BorderLayout.CENTER);

        JPanel testBottom = new JPanel(new FlowLayout(FlowLayout.CENTER));
        testBottom.setBackground(Color.WHITE);
        JButton approveTestBtn = new JButton("✅ Onayla");
        JButton rejectTestBtn = new JButton("❌ Reddet");
        styleButton(approveTestBtn, buttonColor);
        styleButton(rejectTestBtn, buttonColor);
        testBottom.add(approveTestBtn);
        testBottom.add(rejectTestBtn);
        testPanel.add(testBottom, BorderLayout.SOUTH);

        frame.add(pricePanel);
        frame.add(testPanel);

        loadRequests();
/*
        approvePriceBtn.addActionListener(e -> {
            int index = priceList.getSelectedIndex();
            if (index != -1 && !priceField.getText().isEmpty()) {
                try {
                    int requestId = priceRequestIds.get(index);
                    double price = Double.parseDouble(priceField.getText());
                    PreparedStatement ps = conn.prepareStatement(
                        "UPDATE requests SET status = 'accepted' WHERE request_id = ?"
                    );
                    ps.setDouble(1, price);
                    ps.setInt(2, requestId);
                    ps.executeUpdate();
                    JOptionPane.showMessageDialog(frame, "Fiyat teklifi onaylandı.");
                    loadRequests();
                } catch (Exception ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(frame, "Hata oluştu.");
                }
            }
        });
*/
        
        approvePriceBtn.addActionListener(e -> {
            int index = priceList.getSelectedIndex();
            if (index != -1 && !priceField.getText().isEmpty()) {
                try {
                    int requestId = priceRequestIds.get(index);
                    double price = Double.parseDouble(priceField.getText());

                    // 1. user_id ve vehicle_id'yi requests tablosundan al
                    PreparedStatement psSelect = conn.prepareStatement(
                        "SELECT user_id, vehicle_id FROM requests WHERE request_id = ?"
                    );
                    psSelect.setInt(1, requestId);
                    ResultSet rs = psSelect.executeQuery();

                    if (rs.next()) {
                        int userId = rs.getInt("user_id");
                        int vehicleId = rs.getInt("vehicle_id");

                        // 2. requests tablosunu güncelle
                        PreparedStatement psUpdate = conn.prepareStatement(
                            "UPDATE requests SET status = 'accepted' WHERE request_id = ?"
                        );
                        psUpdate.setInt(1, requestId);
                        psUpdate.executeUpdate();

                        // 3. price_offers tablosuna insert yap
                        PreparedStatement psInsert = conn.prepareStatement(
                            "INSERT INTO price_offers (request_id, user_id, vehicle_id, offer_date, offered_price) VALUES (?, ?, ?, CURRENT_DATE, ?)"
                        );
                        psInsert.setInt(1, requestId);
                        psInsert.setInt(2, userId);
                        psInsert.setInt(3, vehicleId);
                        psInsert.setBigDecimal(4, new BigDecimal(price));

                        psInsert.executeUpdate();

                        JOptionPane.showMessageDialog(frame, "Fiyat teklifi onaylandı.");
                        loadRequests();
                    } else {
                        JOptionPane.showMessageDialog(frame, "İlgili talep bulunamadı.");
                    }

                } catch (Exception ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(frame, "Hata oluştu.");
                }
            }
        });

        approveTestBtn.addActionListener(e -> {
            int index = testDriveList.getSelectedIndex();
            if (index != -1) {
                try {
                    int requestId = testDriveRequestIds.get(index);
                    
                    // 1. vehicle_id'yi al
                    PreparedStatement psSelect = conn.prepareStatement(
                        "SELECT vehicle_id FROM requests WHERE request_id = ?"
                    );
                    psSelect.setInt(1, requestId);
                    ResultSet rs = psSelect.executeQuery();

                    if (rs.next()) {
                        int vehicleId = rs.getInt("vehicle_id");

                        // 2. Stok kontrolü yap
                        PreparedStatement psCheckStock = conn.prepareStatement(
                            "SELECT SUM(quantity) AS total_stock FROM stock WHERE vehicle_id = ? and location_type='dealer' "
                        );
                        psCheckStock.setInt(1, vehicleId);
                        ResultSet rsStock = psCheckStock.executeQuery();

                        if (rsStock.next()) {
                            int totalStock = rsStock.getInt("total_stock");
                            
                            if (totalStock > 0) {
                                // 3. Talebi onayla
                                PreparedStatement psUpdate = conn.prepareStatement(
                                    "UPDATE requests SET status = 'accepted' WHERE request_id = ?"
                                );
                                psUpdate.setInt(1, requestId);
                                psUpdate.executeUpdate();

                                JOptionPane.showMessageDialog(frame, "Test sürüşü onaylandı.");
                                loadRequests();
                            } else {
                                JOptionPane.showMessageDialog(frame, "Bu araç için stok bulunmamaktadır.");
                            }
                        } else {
                            JOptionPane.showMessageDialog(frame, "Bu araç için stok bilgisi bulunamadı.");
                        }
                    } else {
                        JOptionPane.showMessageDialog(frame, "İlgili talep bulunamadı.");
                    }

                } catch (Exception ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(frame, "Hata oluştu.");
                }
            }
        });


        rejectTestBtn.addActionListener(e -> {
            int index = testDriveList.getSelectedIndex();
            if (index != -1) {
                try {
                    int requestId = testDriveRequestIds.get(index);
                    PreparedStatement ps = conn.prepareStatement(
                        "UPDATE requests SET status = 'rejected' WHERE request_id = ?"
                    );
                    ps.setInt(1, requestId);
                    ps.executeUpdate();
                    JOptionPane.showMessageDialog(frame, "Test sürüşü reddedildi.");
                    loadRequests();
                } catch (Exception ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(frame, "Hata oluştu.");
                }
            }
        });

        frame.setVisible(true);
    }

    private void styleButton(JButton button, Color baseColor) {
        button.setFont(new Font("SansSerif", Font.PLAIN, 14));
        button.setBackground(baseColor);
        button.setFocusPainted(false);
        button.setBorderPainted(false);
        button.setMargin(new Insets(8, 12, 8, 12));
        button.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                button.setBackground(baseColor.darker());
            }
            @Override
            public void mouseExited(MouseEvent e) {
                button.setBackground(baseColor);
            }
        });
    }

    private void loadRequests() {
        priceModel.clear();
        testDriveModel.clear();
        priceRequestIds.clear();
        testDriveRequestIds.clear();

        try {
            String query = "SELECT r.request_id, r.user_id, r.vehicle_id, r.request_date, r.request_type, v.brand, v.model " +
                           "FROM requests r JOIN vehicle v ON r.vehicle_id = v.vehicle_id " +
                           "WHERE r.status = 'pending'";
            PreparedStatement ps = conn.prepareStatement(query);
            ResultSet rs = ps.executeQuery();

            while (rs.next()) {
                int id = rs.getInt("request_id");
                int userId = rs.getInt("user_id");
                String brand = rs.getString("brand");
                String model = rs.getString("model");
                String type = rs.getString("request_type");
                Date date = rs.getDate("request_date");

                String line = "Kullanıcı: " + userId + ", Araç: " + brand + " " + model + ", Tarih: " + date;

                if (type.equals("price_offer")) {
                    priceModel.addElement(line);
                    priceRequestIds.add(id);
                } else if (type.equals("test_drive")) {
                    testDriveModel.addElement(line);
                    testDriveRequestIds.add(id);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
