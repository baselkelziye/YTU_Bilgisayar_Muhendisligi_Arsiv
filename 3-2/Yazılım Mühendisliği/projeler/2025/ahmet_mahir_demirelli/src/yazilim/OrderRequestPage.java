package yazilim;

import javax.swing.*;
import yazilim.classes.Customer;
import yazilim.requests.OrderRequest;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.time.LocalDate;

public class OrderRequestPage {
    private JFrame frame;
    private JComboBox<String> vehicleCombo;
    private Customer customer;
	private static Connection conn;
	    
	    /**
		 * Launch the application.
		 */
		public static void main(String[] args) {
			EventQueue.invokeLater(new Runnable() {
				public void run() {
					try {
						conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
						OrderRequestPage window = new OrderRequestPage(new Customer(), conn);
						window.frame.setVisible(true);
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			});
		}


    public OrderRequestPage(Customer cstmr, Connection conn) {
        this.customer = cstmr;
        this.conn = conn;

        if (!hasAnyPriceOffer()) {
            initializeNoOffersPage();
        } else {
            initialize();
        }
    }

    private boolean hasAnyPriceOffer() {
        String query = "SELECT COUNT(*) AS offer_count FROM price_offers WHERE user_id = ?";
        try {
            PreparedStatement stmt = conn.prepareStatement(query);
            stmt.setInt(1, customer.getCustomerId());
            ResultSet rs = stmt.executeQuery();
            if (rs.next() && rs.getInt("offer_count") > 0) {
                return true;
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(null, "Teklif kontrolü sırasında hata oluştu.");
        }
        return false;
    }

    private void initialize() {
        frame = new JFrame("Sipariş Ver");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setBounds(100, 100, 600, 300);
        frame.setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.Y_AXIS));

        JLabel titleLabel = new JLabel("Sipariş Vermek İstediğiniz Araç:");
        titleLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
        frame.add(Box.createRigidArea(new Dimension(0, 30)));
        frame.add(titleLabel);

        vehicleCombo = new JComboBox<>();
        vehicleCombo.setMaximumSize(new Dimension(500, 30));
        vehicleCombo.setAlignmentX(Component.CENTER_ALIGNMENT);
        frame.add(Box.createRigidArea(new Dimension(0, 10)));
        frame.add(vehicleCombo);
        loadEligibleVehicles();

        JButton orderButton = new JButton("Sipariş Ver");
        orderButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        orderButton.setFocusable(false);
        orderButton.setPreferredSize(new Dimension(160, 40));
        frame.add(Box.createRigidArea(new Dimension(0, 20)));
        frame.add(orderButton);

        orderButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String selectedItem = (String) vehicleCombo.getSelectedItem();
                if (selectedItem != null) {
                    try {
                        String[] parts = selectedItem.split(" - ");
                        int offerId = Integer.parseInt(parts[0].trim()); 

                        String vehicleQuery = "SELECT vehicle_id FROM price_offers WHERE offer_id = ?";
                        PreparedStatement stmt = conn.prepareStatement(vehicleQuery);
                        stmt.setInt(1, offerId);
                        ResultSet rs = stmt.executeQuery();

                        int vehicleId = -1; 
                        if (rs.next()) {
                            vehicleId = rs.getInt("vehicle_id");
                        }

                        if (vehicleId == -1) {
                            JOptionPane.showMessageDialog(frame, "Araç bilgisi bulunamadı.");
                            return;
                        }

                        String offerDateQuery = "SELECT offer_date FROM price_offers WHERE offer_id = ?";
                        PreparedStatement dateStmt = conn.prepareStatement(offerDateQuery);
                        dateStmt.setInt(1, offerId);
                        ResultSet dateRs = dateStmt.executeQuery();

                        if (dateRs.next()) {
                            LocalDate offerDate = dateRs.getDate("offer_date").toLocalDate();
                            if (offerDate.isBefore(LocalDate.now().minusDays(30))) {
                                JOptionPane.showMessageDialog(frame, "Bu teklifin süresi dolmuş. Lütfen yeni teklif isteyin.");
                                return;
                            }
                        }

                        OrderRequest request = new OrderRequest(customer.getCustomerId(), vehicleId, LocalDate.now(), conn, offerId);
                        if (request.processRequest(customer.getCustomerId(), vehicleId, LocalDate.now())) {
                            JOptionPane.showMessageDialog(frame, "Sipariş başarıyla gönderildi.");
                            loadEligibleVehicles();
                        } else {
                            JOptionPane.showMessageDialog(frame, "Sipariş gönderilemedi.");
                        }
                    } catch (NumberFormatException ex) {
                        JOptionPane.showMessageDialog(frame, "Araç bilgisi okunamadı.");
                    } catch (SQLException ex) {
                        ex.printStackTrace();
                        JOptionPane.showMessageDialog(frame, "Sipariş işlemi sırasında hata oluştu.");
                    }
                }
            }
        });



        JButton backButton = new JButton("Geri");
        backButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        backButton.setFocusable(false);
        frame.add(Box.createRigidArea(new Dimension(0, 20)));
        frame.add(backButton);

        backButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                frame.dispose();
                CustomerMainPage mainPage = new CustomerMainPage(customer, conn);
                mainPage.showFrame();
            }
        });
    }

    private void initializeNoOffersPage() {
        frame = new JFrame("Sipariş Ver");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setBounds(100, 100, 450, 200);
        frame.setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.Y_AXIS));

        JLabel noOffersLabel = new JLabel("Hiçbir araç için fiyat teklifiniz bulunmamaktadır.");
        noOffersLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
        frame.add(Box.createRigidArea(new Dimension(0, 40)));
        frame.add(noOffersLabel);

        JButton backButton = new JButton("Geri");
        backButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        backButton.setFocusable(false);
        frame.add(Box.createRigidArea(new Dimension(0, 30)));
        frame.add(backButton);

        backButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                frame.dispose();
            }
        });
    }

    private void loadEligibleVehicles() {
        try {
            String query = """
                SELECT v.vehicle_id, v.brand, v.model, v.year, p.offer_id, p.offered_price, p.offer_date
				FROM vehicle v
				JOIN price_offers p ON v.vehicle_id = p.vehicle_id
				WHERE p.user_id = ? AND 
				v.vehicle_id NOT IN (SELECT vehicle_id FROM requests WHERE user_id = p.user_id AND request_type = 'order' AND status = 'pending');
            """;
            PreparedStatement stmt = conn.prepareStatement(query);
            stmt.setInt(1, customer.getCustomerId()); 
            ResultSet rs = stmt.executeQuery();
            
            vehicleCombo.removeAllItems();

            while (rs.next()) {
                int offerId = rs.getInt("offer_id");
                String brand = rs.getString("brand");
                String model = rs.getString("model");
                int year = rs.getInt("year");
                double price = rs.getDouble("offered_price"); 
                LocalDate offerDate = rs.getDate("offer_date").toLocalDate();

                String formattedPrice = String.format("%.2f", price);
                String baseText = offerId + " - " + brand + " " + model + " (" + year + ")  " + formattedPrice + " TL";

                String displayText = offerDate.isBefore(LocalDate.now().minusDays(30))
                        ? baseText + " [SÜRESİ DOLMUŞ]"
                        : baseText;

                vehicleCombo.addItem(displayText);
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Araç bilgileri yüklenemedi.");
        }
    }



    public void showFrame() {
        if (frame != null) {
            frame.setVisible(true);
        }
    }
}

