package yazilim;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.sql.Connection;
import java.sql.Date;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import yazilim.classes.Customer;

public class PriceOfferStatusPage {
    private JFrame frame;
    private JTable table;
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
						PriceOfferStatusPage window = new PriceOfferStatusPage(new Customer(), conn);
						window.frame.setVisible(true);
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			});
		}

    public PriceOfferStatusPage(Customer cstmr, Connection conn) {
        this.customer = cstmr;
        this.conn = conn;
        initialize();
        loadPriceOffers();
    }

    private void initialize() {
        frame = new JFrame("Teklif Durumlarım");
        frame.setBounds(100, 100, 600, 400);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.getContentPane().setLayout(new BorderLayout());

        String[] columns = {"Araç", "Teklif Tarihi", "Teklif Fiyatı", "Durum"};
        DefaultTableModel model = new DefaultTableModel(columns, 0);
        table = new JTable(model);
        frame.getContentPane().add(new JScrollPane(table), BorderLayout.CENTER);

        JButton backButton = new JButton("Geri");
        backButton.setFocusable(false);
        backButton.addActionListener(e -> {
            frame.dispose();
        });

        javax.swing.JPanel bottomPanel = new javax.swing.JPanel();
        bottomPanel.add(backButton); 
        frame.getContentPane().add(bottomPanel, BorderLayout.SOUTH);
    }

    private void loadPriceOffers() {
        String sql = """
            SELECT 
			    v.brand, v.model, v.year, 
			    p.offer_date AS offer_date, 
			    p.offered_price AS price,  
			    r.status 
			FROM price_offers p
			JOIN vehicle v ON p.vehicle_id = v.vehicle_id
			JOIN requests r ON p.request_id = r.request_id
			WHERE p.user_id = ? AND r.request_type = 'price_offer' AND r.status = 'accepted'
			
			UNION ALL
			
			SELECT 
			    v.brand, v.model, v.year, 
			    r.request_date AS offer_date, 
			    NULL AS price,  
			    r.status 
			FROM requests r
			JOIN vehicle v ON r.vehicle_id = v.vehicle_id
			WHERE r.user_id = ? AND r.request_type = 'price_offer' AND (r.status = 'pending' OR r.status = 'rejected')
			ORDER BY offer_date DESC;
            """;

        try (PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setInt(1, customer.getCustomerId());
            stmt.setInt(2, customer.getCustomerId());
            ResultSet rs = stmt.executeQuery();

            DefaultTableModel m = (DefaultTableModel) table.getModel();
            while (rs.next()) {
                String vehicle = rs.getString("brand")
                               + " " + rs.getString("model")
                               + " (" + rs.getInt("year") + ")";
                Date date = rs.getDate("offer_date");
                Double price = rs.getObject("price") != null ? rs.getDouble("price") : null;
                String status = translateStatus(rs.getString("status"), price);

                m.addRow(new Object[]{
                    vehicle,
                    date.toString(),
                    price != null ? String.format("%.2f", price) : "-",
                    status
                });
                
                System.out.println("Vehicle: " + vehicle + ", Date: " + date + ", Price: " + price + ", Status: " + status);
            }
            
            if (m.getRowCount() == 0) {
                JOptionPane.showMessageDialog(frame, "Hiç teklif bulunamadı.");
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Teklifler yüklenemedi.");
        }
    }

    private String translateStatus(String status, Double price) {
        return switch (status) {
            case "pending"  -> "<html><span style='color:orange;'>Teklif Bekleniyor</span></html>";
            case "accepted" -> String.format("<html><span style='color:green;'>Teklif Verildi</span></html>");
            case "rejected" -> "<html><span style='color:red;'>Reddedildi / Stokta Yok</span></html>";
            default         -> status;
        };
    }


    public void showFrame() {
        frame.setVisible(true);
    }
}

