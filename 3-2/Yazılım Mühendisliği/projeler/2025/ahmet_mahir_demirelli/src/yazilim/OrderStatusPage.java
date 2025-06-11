package yazilim;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import yazilim.classes.Customer;
import java.awt.*;
import java.sql.*;

public class OrderStatusPage {
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
						OrderStatusPage window = new OrderStatusPage(new Customer(), conn);
						window.frame.setVisible(true);
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			});
		}

    public OrderStatusPage(Customer cstmr, Connection conn) {
        this.customer = cstmr;
        this.conn = conn;
        initialize();
        loadOrderRequests();
    }

    private void initialize() {
        frame = new JFrame("Sipariş Taleplerim");
        frame.setBounds(100, 100, 600, 400);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.getContentPane().setLayout(new BorderLayout());

        String[] columnNames = {"Araç", "Tarih", "Durum"};
        DefaultTableModel model = new DefaultTableModel(columnNames, 0);
        table = new JTable(model);
        JScrollPane scrollPane = new JScrollPane(table);
        frame.getContentPane().add(scrollPane, BorderLayout.CENTER);

        JButton backButton = new JButton("Geri");
        backButton.setFocusable(false);
        backButton.addActionListener(e -> {
            frame.dispose();
        });

        javax.swing.JPanel bottomPanel = new javax.swing.JPanel();
        bottomPanel.add(backButton); 
        frame.getContentPane().add(bottomPanel, BorderLayout.SOUTH);
    }

    private void loadOrderRequests() {
        String query = """
            SELECT r.request_date, r.status, v.brand, v.model, v.year
            FROM requests r
            JOIN vehicle v ON r.vehicle_id = v.vehicle_id
            WHERE r.user_id = ? AND r.request_type = 'order'
            ORDER BY r.request_date DESC
        """;

        try {
            PreparedStatement stmt = conn.prepareStatement(query);
            stmt.setInt(1, customer.getCustomerId());
            ResultSet rs = stmt.executeQuery();
            DefaultTableModel model = (DefaultTableModel) table.getModel();

            while (rs.next()) {
                String vehicleInfo = rs.getString("brand") + " " + rs.getString("model") + " (" + rs.getInt("year") + ")";
                Date date = rs.getDate("request_date");
                String status = translateStatus(rs.getString("status"));
                model.addRow(new Object[]{vehicleInfo, date.toString(), status});
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Veriler alınırken hata oluştu.");
        }
    }

    private String translateStatus(String status) {
        return switch (status) {
            case "pending"  -> "<html><span style='color:orange;'>Beklemede</span></html>";
            case "accepted" -> "<html><span style='color:green;'>Sipariş Onaylandı</span></html>";
            case "rejected" -> "<html><span style='color:red;'>Stokta Yok</span></html>";
            default         -> status;
        };
    }

    public void showFrame() {
        frame.setVisible(true);
    }
}

