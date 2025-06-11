package yazilim;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public class DealerVehiclePage {
	private JFrame frame;
    private JTable table;
    private static Connection conn;

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            try {
                conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
                DealerVehiclePage window = new DealerVehiclePage(conn);
                window.frame.setVisible(true);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    public DealerVehiclePage(Connection conn) {
        this.conn = conn;
        initialize();
        loadAllVehicles();
    }

    private void initialize() {
        frame = new JFrame("Bayiye Ait Tüm Araçlar");
        frame.setBounds(100, 100, 600, 400);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.getContentPane().setLayout(new BorderLayout());

        String[] columnNames = {"Marka", "Model", "Yıl", "Paket"};
        DefaultTableModel model = new DefaultTableModel(columnNames, 0);
        table = new JTable(model);
        JScrollPane scrollPane = new JScrollPane(table);
        frame.getContentPane().add(scrollPane, BorderLayout.CENTER);

        JButton backButton = new JButton("Geri");
        backButton.setFocusable(false);
        backButton.addActionListener(e -> frame.dispose());

        JPanel bottomPanel = new JPanel();
        bottomPanel.add(backButton);
        frame.getContentPane().add(bottomPanel, BorderLayout.SOUTH);
    }

    private void loadAllVehicles() {
        String query = """
            SELECT brand, model, year, package
            FROM vehicle
            ORDER BY year DESC
        """;

        try {
            PreparedStatement stmt = conn.prepareStatement(query);
            ResultSet rs = stmt.executeQuery();
            DefaultTableModel model = (DefaultTableModel) table.getModel();

            while (rs.next()) {
                String brand = rs.getString("brand");
                String modelName = rs.getString("model");
                int year = rs.getInt("year");
                String pkg = rs.getString("package");

                model.addRow(new Object[]{brand, modelName, year, pkg});
            }

            if (model.getRowCount() == 0) {
                model.addRow(new Object[]{"Kayıtlı araç bulunmamaktadır.", "", "", ""});
            }

        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Araçlar yüklenirken hata oluştu.");
        }
    }

    public void showFrame() {
        frame.setVisible(true);
    }

}
