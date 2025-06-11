package yazilim;

import javax.swing.*;
import yazilim.classes.Customer;
import yazilim.requests.TestDriveRequest;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.time.LocalDate;
import java.time.ZoneId;
import java.util.Date;

public class TestDriveRequestPage {
    private JFrame frame;
    private JComboBox<String> vehicleCombo;
    private Customer customer;
	private static Connection conn;
	private JSpinner dateSpinner;
	    
	    /**
		 * Launch the application.
		 */
		public static void main(String[] args) {
			EventQueue.invokeLater(new Runnable() {
				public void run() {
					try {
						conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
						TestDriveRequestPage window = new TestDriveRequestPage(new Customer(), conn);
						window.frame.setVisible(true);
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			});
		}

    public TestDriveRequestPage(Customer cstmr, Connection conn) {
        this.customer = cstmr;
        this.conn = conn;
        initialize();
    }

    private void initialize() {
        frame = new JFrame("Test Sürüşü Talebi");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setBounds(100, 100, 500, 300);
        frame.setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.Y_AXIS));

        JLabel titleLabel = new JLabel("Test Sürüşü Talep Etmek İstediğiniz Araç:");
        titleLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
        frame.add(Box.createRigidArea(new Dimension(0, 20))); // Üst boşluk
        frame.add(titleLabel);

        vehicleCombo = new JComboBox<>();
        vehicleCombo.setMaximumSize(new Dimension(350, 30));  
        vehicleCombo.setAlignmentX(Component.CENTER_ALIGNMENT);
        frame.add(Box.createRigidArea(new Dimension(0, 10))); 
        frame.add(vehicleCombo);
        loadVehicles();

        JLabel dateLabel = new JLabel("Tarih Seçin:");
        dateLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
        frame.add(Box.createRigidArea(new Dimension(0, 15)));
        frame.add(dateLabel);

        SpinnerDateModel dateModel = new SpinnerDateModel(new Date(), null, null, java.util.Calendar.DAY_OF_MONTH);
        dateSpinner = new JSpinner(dateModel);
        dateSpinner.setEditor(new JSpinner.DateEditor(dateSpinner, "dd-MM-yyyy"));
        dateSpinner.setMaximumSize(new Dimension(150, 30));
        dateSpinner.setAlignmentX(Component.CENTER_ALIGNMENT);
        frame.add(Box.createRigidArea(new Dimension(0, 5)));
        frame.add(dateSpinner);

        JButton submitButton = new JButton("Test Sürüşü Talep Et");
        submitButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        submitButton.setFocusable(false);
        submitButton.setPreferredSize(new Dimension(170, 40));
        frame.add(Box.createRigidArea(new Dimension(0, 20)));
        frame.add(submitButton);

        submitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String selectedVehicle = (String) vehicleCombo.getSelectedItem();
                if (selectedVehicle != null) {
                    try {
                        int vehicleId = Integer.parseInt(selectedVehicle.split("-")[0].trim());
                        Date selectedDate = (Date) dateSpinner.getValue();
                        LocalDate requestDate = selectedDate.toInstant().atZone(ZoneId.systemDefault()).toLocalDate();
                        if (requestDate.isBefore(LocalDate.now())) {
                            JOptionPane.showMessageDialog(frame, "Geçmiş bir tarih seçemezsiniz!", "Geçersiz Tarih", JOptionPane.WARNING_MESSAGE);
                            return;
                        }

                        TestDriveRequest request = new TestDriveRequest(customer.getCustomerId(), vehicleId, requestDate, conn);
                        if (request.processRequest(customer.getCustomerId(), vehicleId, requestDate)) {
                            JOptionPane.showMessageDialog(frame, "Test sürüşü talebi başarıyla gönderildi.");
                        } else {
                            JOptionPane.showMessageDialog(frame, "Test sürüşü talebi gönderilemedi.");
                        }
                    } catch (NumberFormatException ex) {
                        JOptionPane.showMessageDialog(frame, "Araç bilgisi okunamadı.");
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


