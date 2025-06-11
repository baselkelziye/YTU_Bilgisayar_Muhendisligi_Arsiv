package yazilim;

import javax.swing.*;
import yazilim.classes.Customer;
import yazilim.requests.PriceOfferRequest;
import java.awt.*;
import java.sql.*;
import java.time.LocalDate;


public class PriceOfferRequestPage {
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
						PriceOfferRequestPage window = new PriceOfferRequestPage(new Customer(), conn);
						window.frame.setVisible(true);
					} catch (Exception e) {
						e.printStackTrace(); 
					}
				}
			});
		}

    public PriceOfferRequestPage(Customer cstmr, Connection conn) {
        this.customer = cstmr;
        this.conn = conn;
        initialize();
    }

    private void initialize() {
        frame = new JFrame("Fiyat Teklifi İste");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setBounds(100, 100, 500, 250);
        frame.setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.Y_AXIS));

        JLabel titleLabel = new JLabel("Fiyat Teklifi Almak İstediğiniz Araç:");
        titleLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
        frame.add(Box.createRigidArea(new Dimension(0, 30)));
        frame.add(titleLabel);

        vehicleCombo = new JComboBox<>();
        vehicleCombo.setMaximumSize(new Dimension(350, 30));  
        vehicleCombo.setAlignmentX(Component.CENTER_ALIGNMENT);
        frame.add(Box.createRigidArea(new Dimension(0, 10))); 
        frame.add(vehicleCombo);
        loadVehicles();  
      
        JButton submitButton = new JButton("Fiyat Teklifi Al");
        submitButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        submitButton.setFocusable(false);
        submitButton.setPreferredSize(new Dimension(160, 40));
        frame.add(Box.createRigidArea(new Dimension(0, 20)));
        frame.add(submitButton);

        submitButton.addActionListener(e -> {
            String selectedVehicle = (String) vehicleCombo.getSelectedItem();
            if (selectedVehicle != null) {
                try {
                    int vehicleId = Integer.parseInt(selectedVehicle.split("-")[0].trim());

                    // 1. Önce, reddedilmemiş ve beklemede olan son istek var mı?
                    String requestQuery = """
                        SELECT r.request_id, r.status, 
					        (SELECT po.offer_date 
					         FROM price_offers po 
					         WHERE po.request_id = r.request_id 
					         ORDER BY po.offer_date DESC 
					         LIMIT 1) AS offer_date
					    FROM requests r
					    WHERE r.user_id = ? AND r.vehicle_id = ? AND r.request_type = 'price_offer'
					    ORDER BY r.request_date DESC
					    LIMIT 1
                    """;

                    PreparedStatement reqStmt = conn.prepareStatement(requestQuery);
                    reqStmt.setInt(1, customer.getCustomerId());
                    reqStmt.setInt(2, vehicleId);
                    ResultSet rs = reqStmt.executeQuery();

                    if (rs.next()) {
                        String status = rs.getString("status");
                        Date offerDateSql = rs.getDate("offer_date");

                        if ("pending".equalsIgnoreCase(status)) {
                            JOptionPane.showMessageDialog(frame,"Daha önce teklif isteği gönderildi, lütfen teklif verilmesini bekleyin.");
                            return;
                        }

                        if (!"rejected".equalsIgnoreCase(status) && offerDateSql != null) {
                            LocalDate offerDate = offerDateSql.toLocalDate();
                            if (!offerDate.isBefore(LocalDate.now().minusDays(30))) {
                                JOptionPane.showMessageDialog(frame,"Bu araç için zaten geçerli bir teklif bulunmaktadır.");
                                return;
                            }
                        }
                    }

                    PriceOfferRequest request = new PriceOfferRequest(customer.getCustomerId(), vehicleId, LocalDate.now(), conn);
                    if (request.processRequest(customer.getCustomerId(), vehicleId, LocalDate.now())) {
                        JOptionPane.showMessageDialog(frame, "Teklif isteği başarıyla gönderildi.");
                    } else {
                        JOptionPane.showMessageDialog(frame, "İstek gönderilemedi.");
                    }

                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(frame, "Araç bilgisi okunamadı.");
                } catch (SQLException ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(frame, "Teklif kontrolü sırasında hata oluştu.");
                }
            }
        });
    }

    private void loadVehicles() {
        try {
            String query = "SELECT vehicle_id, brand, model, year FROM vehicle";
            PreparedStatement stmt = conn.prepareStatement(query);
            ResultSet rs = stmt.executeQuery();
            while (rs.next()) {
                int id = rs.getInt("vehicle_id");
                String brand = rs.getString("brand");
                String model = rs.getString("model");
                int year = rs.getInt("year");
                vehicleCombo.addItem(id + " - " + brand + " " + model + " (" + year + ")");
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Araç bilgileri yüklenemedi. Lütfen tekrar deneyin.");
        }
    }

    public void showFrame() {
        frame.setVisible(true);
    }
}


