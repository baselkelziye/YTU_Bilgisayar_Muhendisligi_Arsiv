package yazilim;

import java.awt.EventQueue;
import java.awt.Font;
import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.awt.event.ActionEvent;

public class StartPage {
	private JFrame frame;
	private static Connection conn;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
					StartPage window = new StartPage(conn);
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	public StartPage() throws SQLException {
		conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
		initialize();
	}

	/**
	 * Create the application.
	 */
	public StartPage(Connection parent_conn) {
		conn = parent_conn;
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setTitle("Başlangıç Sayfası");
		frame.setBounds(100, 100, 450, 230);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);

		JButton btnUserLogin = new JButton("Müşteri Girişi");
		btnUserLogin.setFocusable(false);
		btnUserLogin.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				frame.setVisible(false);
				CustomerLoginPage login = new CustomerLoginPage(conn);
				login.showFrame();
			}
		});
		btnUserLogin.setFont(new Font("Tahoma", Font.BOLD, 18));
		btnUserLogin.setBounds(35, 30, 180, 35);
		frame.getContentPane().add(btnUserLogin);
		
		JButton btnDealerLogin = new JButton("Bayi Girişi");
		btnDealerLogin.setFocusable(false);
		btnDealerLogin.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				frame.setVisible(false);
				DealerLoginPage login = new DealerLoginPage(conn);
				login.showFrame();
			}
		});
		btnDealerLogin.setFont(new Font("Tahoma", Font.BOLD, 18));
		btnDealerLogin.setBounds(220, 30, 180, 35);
		frame.getContentPane().add(btnDealerLogin);

		JButton btnRegister = new JButton("Kullanıcı Kayıt");
		btnRegister.setFocusable(false);
		btnRegister.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				frame.setVisible(false);
				CustomerRegisterPage register = new CustomerRegisterPage(conn);
				register.showFrame();
			}
		});
		btnRegister.setFont(new Font("Tahoma", Font.BOLD, 18));
		btnRegister.setBounds(35, 85, 180, 35);
		frame.getContentPane().add(btnRegister);
		
		JButton btnWarehouseLogin = new JButton("Depo Girişi");
		btnWarehouseLogin.setFocusable(false);
		btnWarehouseLogin.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				frame.setVisible(false);
				WarehouseLoginPage login = new WarehouseLoginPage(conn);
				login.showFrame();
			}
		});
		btnWarehouseLogin.setFont(new Font("Tahoma", Font.BOLD, 18));
		btnWarehouseLogin.setBounds(220, 85, 180, 35);
		frame.getContentPane().add(btnWarehouseLogin);
		
		JButton btnQuit = new JButton("Çık");
		btnQuit.setFocusable(false);
		btnQuit.addActionListener(new ActionListener() {
		    public void actionPerformed(ActionEvent e) {
		        try {
		            if (conn != null && !conn.isClosed()) {
		                conn.close();
		            }
		        } catch (SQLException e1) {
		            e1.printStackTrace();
		        }
		        frame.dispose();
		        System.exit(0); // Ensure the application exits
		    }
		});
		btnQuit.setFont(new Font("Tahoma", Font.BOLD, 18));
		btnQuit.setFocusable(false);
		btnQuit.setBounds(130, 135, 156, 35);
		frame.getContentPane().add(btnQuit);
	}

	public void showFrame() {
		frame.setVisible(true);
	}
}