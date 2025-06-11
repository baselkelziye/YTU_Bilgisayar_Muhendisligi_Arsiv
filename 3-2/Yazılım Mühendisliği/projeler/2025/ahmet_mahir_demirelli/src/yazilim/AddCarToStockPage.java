package yazilim;

import java.awt.EventQueue;
import java.awt.Font;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.SpinnerNumberModel;
import yazilim.classes.Warehouse;
import java.awt.event.ActionListener;
import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDate;
import java.awt.event.ActionEvent;

public class AddCarToStockPage {
	private JFrame frame;
	private static Connection conn;
	private Warehouse warehouse;
	private JTextField brandField;
	private JTextField modelField;
	private JTextField packageField;
	private JSpinner yearSpinner;
	private JSpinner priceSpinner;
	private JSpinner quantitySpinner;
	
	private JLabel tipLabel;
	private JLabel brandLabel;
	private JLabel modelLabel;
	private JLabel yearLabel;
	private JLabel packageLabel;
	private JLabel priceLabel;
	private JLabel quantityLabel;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
					AddCarToStockPage window = new AddCarToStockPage(new Warehouse(), conn);
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	public AddCarToStockPage() throws SQLException {
		conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
		initialize();
	}

	/**
	 * Create the application.
	 */
	public AddCarToStockPage(Warehouse wrhs, Connection parent_conn) {
		conn = parent_conn;
		warehouse = wrhs;
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setTitle("Stoğa Araç Ekleme Sayfası");
		frame.setBounds(100, 100, 390, 350);
		frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		tipLabel = new JLabel("Not: Metin alanları max 50 karakter. Fiyat alanı .xy");
		tipLabel.setFont(new Font("Tahoma", Font.ITALIC, 11));
		tipLabel.setBounds(10, 10, 360, 30);
		frame.getContentPane().add(tipLabel);
		
		brandField = new JTextField();
		brandField.setColumns(10);
		brandField.setBounds(30, 70, 125, 25);
		frame.getContentPane().add(brandField);
		brandLabel = new JLabel("Marka:");
		brandLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		brandLabel.setBounds(30, 50, 100, 15);
		frame.getContentPane().add(brandLabel);
		
		modelField = new JTextField();
		modelField.setColumns(10);
		modelField.setBounds(230, 70, 125, 25);
		frame.getContentPane().add(modelField);
		modelLabel = new JLabel("Model:");
		modelLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		modelLabel.setBounds(230, 50, 100, 15);
		frame.getContentPane().add(modelLabel);
		
		LocalDate now = LocalDate.now();
		SpinnerNumberModel yearModel = new SpinnerNumberModel(now.getYear(), 1900, now.getYear() + 1, 1);
		yearSpinner = new JSpinner(yearModel);
		JSpinner.NumberEditor editor = new JSpinner.NumberEditor(yearSpinner, "#");
		yearSpinner.setEditor(editor);
		yearSpinner.setBounds(30, 130, 125, 25);
		frame.getContentPane().add(yearSpinner);
		yearLabel = new JLabel("Yıl:");
		yearLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		yearLabel.setBounds(30, 110, 100, 15);
		frame.getContentPane().add(yearLabel);
		
		packageField = new JTextField();
		packageField.setColumns(10);
		packageField.setBounds(230, 130, 125, 25);
		frame.getContentPane().add(packageField);
		packageLabel = new JLabel("Paket:");
		packageLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		packageLabel.setBounds(230, 110, 100, 15);
		frame.getContentPane().add(packageLabel);

		SpinnerNumberModel priceModel = new SpinnerNumberModel(1000000.00, 0.01, 100000000.00, 1000);
		priceSpinner = new JSpinner(priceModel);
		JSpinner.NumberEditor priceEditor = new JSpinner.NumberEditor(priceSpinner, "0.00");
		priceSpinner.setEditor(priceEditor);
		priceSpinner.setBounds(30, 190, 125, 25);
		frame.getContentPane().add(priceSpinner);
		priceLabel = new JLabel("Fiyat:");
		priceLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		priceLabel.setBounds(30, 170, 100, 15);
		frame.getContentPane().add(priceLabel);
		
		SpinnerNumberModel quantityModel = new SpinnerNumberModel(1, 1, 100, 1);
		quantitySpinner = new JSpinner(quantityModel);
		quantitySpinner.setBounds(230, 190, 125, 25);
		frame.getContentPane().add(quantitySpinner);
		quantityLabel = new JLabel("Adet:");
		quantityLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		quantityLabel.setBounds(230, 170, 100, 15);
		frame.getContentPane().add(quantityLabel);

		JButton addButton = new JButton("Ekle");
		addButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BigDecimal price = BigDecimal.valueOf((double) priceSpinner.getValue());
				int result = addCarToStock(brandField.getText(), modelField.getText(), (int) yearSpinner.getValue(), packageField.getText(), price, (int) quantitySpinner.getValue());
                if (result == 1) {
                    JOptionPane.showMessageDialog(null, "Araç ekleme başarılı.");
                } 
                else if(result == 0){
                    JOptionPane.showMessageDialog(null, "Araç zaten ekli.");
                }
                else if(result == -1){
                	JOptionPane.showMessageDialog(null, "50 karakterden uzun veri girilemez.");
                }
                else {
                	JOptionPane.showMessageDialog(null, "Beklenmeyen bir hata oluştu");
                }
			}
		});
		addButton.setFont(new Font("Tahoma", Font.BOLD, 18));
		addButton.setBounds(30, 250, 125, 25);
		frame.getContentPane().add(addButton);
		addButton.setFocusable(false);

		JButton returnButton = new JButton("Geri Dön");
		returnButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				WarehouseMainPage warehouseMainPage = new WarehouseMainPage(warehouse, conn);
				warehouseMainPage.showFrame();
				frame.setVisible(false);
			}
		});
		returnButton.setFont(new Font("Tahoma", Font.BOLD, 18));
		returnButton.setBounds(230, 250, 125, 25);
		frame.getContentPane().add(returnButton);
		returnButton.setFocusable(false);
	}
	
	public int addCarToStock(String brand, String model, int year, String pckg, BigDecimal price, int quantity) {
		String query = "SELECT add_vehicle(?,?,?,?,?,?);";
		PreparedStatement statement;
		try {
			if (brandField.getText().length() <= 50 && modelField.getText().length() <= 50 && packageField.getText().length() <= 50) {
				statement = conn.prepareStatement(query);
				statement.setString(1, brand);
				statement.setString(2, model);
				statement.setInt(3, year);
				statement.setString(4, pckg);
				statement.setBigDecimal(5, price);
				statement.setInt(6, quantity);
				
				ResultSet r = statement.executeQuery();
				r.next();
				if (r.getBoolean(1)) {
					return 1;
				} 
				else {
					return 0;
				}
			} else {
				return -1;
			}
		} catch (SQLException e1) {
			e1.printStackTrace();
			return -2;
		}
	}

	public void showFrame() {
		frame.setVisible(true);
	}
}