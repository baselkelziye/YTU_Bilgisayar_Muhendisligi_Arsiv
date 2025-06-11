package yazilim;

import javax.swing.*;
import yazilim.classes.Dealer;
import java.awt.event.*;
import java.sql.*;

public class DealerChangePassword {
    private JFrame frame;
    private Connection conn;
    private Dealer dealer;

    public DealerChangePassword(Connection conn, Dealer dealer) {
        this.conn = conn;
        this.dealer = dealer;
        initialize();
    }

    private void initialize() {
        frame = new JFrame("Şifre Değiştir");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setLayout(null);
        frame.setLocationRelativeTo(null);

        JLabel eskiLabel = new JLabel("Eski Şifre:");
        eskiLabel.setBounds(30, 30, 120, 25);
        frame.add(eskiLabel);

        JPasswordField eskiField = new JPasswordField();
        eskiField.setBounds(160, 30, 180, 25);
        frame.add(eskiField);

        JLabel yeniLabel = new JLabel("Yeni Şifre:");
        yeniLabel.setBounds(30, 70, 120, 25);
        frame.add(yeniLabel);

        JPasswordField yeniField = new JPasswordField();
        yeniField.setBounds(160, 70, 180, 25);
        frame.add(yeniField);

        JLabel tekrarLabel = new JLabel("Yeni Şifre (Tekrar):");
        tekrarLabel.setBounds(30, 110, 150, 25);
        frame.add(tekrarLabel);

        JPasswordField tekrarField = new JPasswordField();
        tekrarField.setBounds(160, 110, 180, 25);
        frame.add(tekrarField);

        JButton guncelleBtn = new JButton("Güncelle");
        guncelleBtn.setBounds(130, 170, 120, 30);
        frame.add(guncelleBtn);

        guncelleBtn.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String eski = new String(eskiField.getPassword());
                String yeni = new String(yeniField.getPassword());
                String tekrar = new String(tekrarField.getPassword());

                if (eski.isEmpty() || yeni.isEmpty() || tekrar.isEmpty()) {
                    JOptionPane.showMessageDialog(frame, "Alanlar boş olamaz.", "Uyarı", JOptionPane.WARNING_MESSAGE);
                    return;
                }

                if (!yeni.equals(tekrar)) {
                    JOptionPane.showMessageDialog(frame, "Yeni şifreler uyuşmuyor!", "Uyarı", JOptionPane.WARNING_MESSAGE);
                    return;
                }

                try {
                    PreparedStatement ps = conn.prepareStatement(
                        "UPDATE dealer SET password = ? WHERE id = ? AND password = ?"
                    );
                    ps.setString(1, yeni);
                    ps.setInt(2, dealer.getId());
                    ps.setString(3, eski);

                    int result = ps.executeUpdate();

                    if (result > 0) {
                        JOptionPane.showMessageDialog(frame, "Şifre başarıyla değiştirildi!");
                        frame.dispose();
                    } else {
                        JOptionPane.showMessageDialog(frame, "Eski şifre hatalı!", "Hata", JOptionPane.ERROR_MESSAGE);
                    }
                } catch (SQLException ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(frame, "Bir hata oluştu.", "Hata", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        frame.setVisible(true);
    }
}
