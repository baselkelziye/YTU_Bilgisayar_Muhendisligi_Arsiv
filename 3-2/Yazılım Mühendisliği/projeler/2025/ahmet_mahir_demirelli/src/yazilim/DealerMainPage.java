package yazilim;

import java.awt.EventQueue;
import java.awt.Font;
import javax.swing.JButton;
import javax.swing.JFrame;
import yazilim.classes.Dealer;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.awt.event.ActionEvent;

public class DealerMainPage {
	private JFrame frame;
	private static Connection conn;
	private Dealer dealer;
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
					DealerMainPage window = new DealerMainPage(new Dealer(), conn);
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	public DealerMainPage() throws SQLException {
		conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
		dealer = new Dealer();
		initialize();
	}

	/**
	 * Create the application.
	 */
	public DealerMainPage(Dealer dlr, Connection parent_conn) {
		dealer = dlr;
		conn = parent_conn;
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
	    frame = new JFrame();
	    frame.setTitle("Bayi Ana Sayfası");
	    frame.setBounds(100, 100, 500, 560);
	    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    frame.getContentPane().setLayout(null);

	    int buttonWidth = 220;
	    int buttonHeight = 40;
	    int buttonX = (frame.getWidth() - buttonWidth) / 2 - 8;
	    int y = 30;

	    JButton showRequestsButton = new JButton("Talepleri Göster");
	    showRequestsButton.setFont(new Font("Tahoma", Font.BOLD, 16));
	    showRequestsButton.setBounds(buttonX, y, buttonWidth, buttonHeight);
	    showRequestsButton.setFocusable(false);
	    showRequestsButton.addActionListener(e -> new DealerRequestPage(conn, dealer));
	    frame.getContentPane().add(showRequestsButton);

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

	    JButton getFromStockButton = new JButton("Stoktan Araç Çek");
	    getFromStockButton.setBounds(buttonX, y, buttonWidth, buttonHeight);
	    getFromStockButton.setFont(new Font("Tahoma", Font.BOLD, 16));
	    getFromStockButton.setFocusable(false);
	    getFromStockButton.addActionListener(e -> {
	        PullCarFromStockPage pullCarFromStockPage = new PullCarFromStockPage(dealer, conn);
	        pullCarFromStockPage.showFrame();
	    });
	    frame.getContentPane().add(getFromStockButton);

	    y += 60;

	    JButton changePasswordButton = new JButton("Şifre Değiştir");
	    changePasswordButton.setBounds(buttonX, y, buttonWidth, buttonHeight);
	    changePasswordButton.setFont(new Font("Tahoma", Font.BOLD, 16));
	    changePasswordButton.setFocusable(false);
	    changePasswordButton.addActionListener(e -> new DealerChangePassword(conn, dealer));
	    frame.getContentPane().add(changePasswordButton);

	    y += 60;

	    JButton approveOrdersButton = new JButton("Satış Onayı");
	    approveOrdersButton.setBounds(buttonX, y, buttonWidth, buttonHeight);
	    approveOrdersButton.setFont(new Font("Tahoma", Font.BOLD, 16));
	    approveOrdersButton.setFocusable(false);
	    approveOrdersButton.addActionListener(e -> new DealerOrderApprovalPage(conn, dealer));
	    frame.getContentPane().add(approveOrdersButton);

	    y += 60;
	    
	    JButton reportButton = new JButton("Rapor Sayfası");
	    reportButton.setBounds(buttonX, y, buttonWidth, buttonHeight);
	    reportButton.setFont(new Font("Tahoma", Font.BOLD, 16));
	    reportButton.setFocusable(false);
	    reportButton.addActionListener(e -> new ReportPage(dealer, conn));
	    frame.getContentPane().add(reportButton);
	    
	    y += 60;
	    
	    JButton customerReportButton = new JButton("Müşteri Rapor Sayfası");
	    customerReportButton.setBounds(buttonX, y, buttonWidth, buttonHeight);
	    customerReportButton.setFont(new Font("Tahoma", Font.BOLD, 16));
	    customerReportButton.setFocusable(false);
	    customerReportButton.addActionListener(e -> new CustomerReportPage(dealer, conn));
	    frame.getContentPane().add(customerReportButton);

	    y += 60;

	    JButton returnButton = new JButton("Çıkış Yap");
	    returnButton.setBounds(buttonX, y, buttonWidth, buttonHeight);
	    returnButton.setFont(new Font("Tahoma", Font.BOLD, 16));
	    returnButton.setFocusable(false);
	    returnButton.addActionListener(e -> {
	        StartPage start_page = new StartPage(conn);
	        start_page.showFrame();
	        frame.setVisible(false);
	    });
	    frame.getContentPane().add(returnButton);
	}

	public void showFrame() {
		frame.setVisible(true);
	}
}
