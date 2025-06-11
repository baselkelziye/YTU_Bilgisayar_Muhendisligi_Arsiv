package yazilim;

import java.awt.EventQueue;
import java.awt.Font;
import javax.swing.JButton;
import javax.swing.JFrame;
import yazilim.classes.Warehouse;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.awt.event.ActionEvent;

public class WarehouseMainPage {
	private JFrame frame;
	private static Connection conn;
	private Warehouse warehouse;
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
					WarehouseMainPage window = new WarehouseMainPage(new Warehouse(), conn);
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	public WarehouseMainPage() throws SQLException {
		conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
		warehouse = new Warehouse();
		initialize();
	}

	/**
	 * Create the application.
	 */
	public WarehouseMainPage(Warehouse wrhs, Connection parent_conn) {
		warehouse = wrhs;
		conn = parent_conn;
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
	    frame = new JFrame();
	    frame.setTitle("Depo Ana Sayfası");
	    frame.setBounds(100, 100, 500, 300);
	    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    frame.getContentPane().setLayout(null);

	    int buttonWidth = 220;
	    int buttonHeight = 40;
	    int buttonX = (frame.getWidth() - buttonWidth) / 2 - 8;
	    int y = 30;

	    JButton newCarButton = new JButton("Yeni Araç Ekle");
	    newCarButton.setBounds(buttonX, y, buttonWidth, buttonHeight);
	    newCarButton.setFont(new Font("Tahoma", Font.BOLD, 16));
	    newCarButton.setFocusable(false);
	    newCarButton.addActionListener(new ActionListener() {
	        public void actionPerformed(ActionEvent e) {
	            AddCarToStockPage addCarToStockPage = new AddCarToStockPage(warehouse, conn);
	            addCarToStockPage.showFrame();
	            frame.setVisible(false);
	        }
	    });
	    frame.getContentPane().add(newCarButton);
	    
	    y += 60;
	    
	    JButton updateStockButton = new JButton("Stokları Güncelle");
	    updateStockButton.setFont(new Font("Tahoma", Font.BOLD, 16));
	    updateStockButton.setBounds(buttonX, y, buttonWidth, buttonHeight);
        frame.getContentPane().add(updateStockButton);
        updateStockButton.setFocusable(false);

        updateStockButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new UpdateStockPage(warehouse, conn);
            }
        });

	    y += 60;
	    
	    JButton viewStockButton = new JButton("Stokları Görüntüle");
        viewStockButton.setFont(new Font("Tahoma", Font.BOLD, 16));
        viewStockButton.setBounds(buttonX, y, buttonWidth, buttonHeight);
        frame.getContentPane().add(viewStockButton);
        viewStockButton.setFocusable(false);

        viewStockButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new ShowCarStockPage(conn); // yeni sayfayı aç
            }
        });
        
        y += 60;
        
	    JButton changePasswordButton = new JButton("Şifre Değiştir");
	    changePasswordButton.setBounds(buttonX, y, buttonWidth, buttonHeight);
	    changePasswordButton.setFont(new Font("Tahoma", Font.BOLD, 16));
	    changePasswordButton.setFocusable(false);
	    changePasswordButton.addActionListener(new ActionListener() {
	        public void actionPerformed(ActionEvent e) {
	            new WarehouseChangePassword(conn, warehouse);
	        }
	    });
	    frame.getContentPane().add(changePasswordButton);

	    y += 60;

	    JButton returnButton = new JButton("Çıkış Yap");
	    returnButton.setBounds(buttonX, y, buttonWidth, buttonHeight);
	    returnButton.setFont(new Font("Tahoma", Font.BOLD, 16));
	    returnButton.setFocusable(false);
	    returnButton.addActionListener(new ActionListener() {
	        public void actionPerformed(ActionEvent e) {
	            StartPage start_page = new StartPage(conn);
	            start_page.showFrame();
	            frame.setVisible(false);
	        }
	    });
	    frame.getContentPane().add(returnButton);
	}

	public void showFrame() {
		frame.setVisible(true);
	}
}
