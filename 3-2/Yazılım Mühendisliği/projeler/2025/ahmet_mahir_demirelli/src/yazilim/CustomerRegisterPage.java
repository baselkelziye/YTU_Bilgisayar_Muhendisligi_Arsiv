package yazilim;

import java.awt.EventQueue;
import java.awt.Font;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.SpinnerNumberModel;
import yazilim.classes.Customer;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.awt.event.ActionEvent;

public class CustomerRegisterPage {
	private static Connection conn;
	private JFrame frame;
	private JTextField nameField;
	private JTextField surnameField;
	private JTextField phoneField;
	private JTextField emailField;
	private JTextField passwordField;
	private JTextField cityField;
	private JTextField professionField;
	
	private JLabel nameLabel;
	private JLabel surnameLabel;
	private JLabel phoneLabel;
	private JLabel emailLabel;
	private JLabel passwordLabel;
	private JLabel cityLabel;
	private JLabel tipLabel;
	private JLabel genderLabel;
	private JLabel ageLabel;
	private JLabel professionLabel;
	private JLabel incomeLevelLabel;
	private int newId;
	
	private JComboBox<String> genderComboBox;
    private JSpinner ageSpinner;
    private JComboBox<String> incomeLevelComboBox;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
					CustomerRegisterPage window = new CustomerRegisterPage(conn);
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	public CustomerRegisterPage() throws SQLException {
		conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
		initialize();
	}

	/**
	 * Create the application.
	 */
	public CustomerRegisterPage(Connection parent_conn) {
		conn = parent_conn;
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setTitle("Kullanıcı Kayıt  Sayfası");
		frame.setBounds(100, 100, 390, 440);
		frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		tipLabel = new JLabel("Not: Her alan en az 3 karakter olmalı (Telefon numarası 10 karakter olmalı)");
		tipLabel.setFont(new Font("Tahoma", Font.ITALIC, 11));
		tipLabel.setBounds(10, 10, 360, 30);
		frame.getContentPane().add(tipLabel);

		nameField = new JTextField();
		nameField.setColumns(10);
		nameField.setBounds(30, 70, 125, 25);
		frame.getContentPane().add(nameField);
		nameLabel = new JLabel("Ad:");
		nameLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		nameLabel.setBounds(30, 50, 100, 15);
		frame.getContentPane().add(nameLabel);
		
		surnameField = new JTextField();
		surnameField.setColumns(10);
		surnameField.setBounds(230, 70, 125, 25);
		frame.getContentPane().add(surnameField);
		surnameLabel = new JLabel("Soyad:");
		surnameLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		surnameLabel.setBounds(230, 50, 100, 15);
		frame.getContentPane().add(surnameLabel);
		
		phoneField = new JTextField();
		phoneField.setColumns(10);
		phoneField.setBounds(30, 130, 125, 25);
		frame.getContentPane().add(phoneField);
		phoneLabel = new JLabel("Telefon:");
		phoneLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		phoneLabel.setBounds(30, 110, 100, 15);
		frame.getContentPane().add(phoneLabel);
		
		cityField = new JTextField();
		cityField.setColumns(10);
		cityField.setBounds(230, 130, 125, 25);
		frame.getContentPane().add(cityField);
		cityLabel = new JLabel("Şehir:");
		cityLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		cityLabel.setBounds(230, 110, 100, 15);
		frame.getContentPane().add(cityLabel);
		
		emailField = new JTextField();
		emailField.setColumns(10);
		emailField.setBounds(30, 190, 125, 25);
		frame.getContentPane().add(emailField);
		emailLabel = new JLabel("E-Posta:");
		emailLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		emailLabel.setBounds(30, 170, 100, 15);
		frame.getContentPane().add(emailLabel);
		
		passwordField = new JTextField();
		passwordField.setColumns(10);
		passwordField.setBounds(230, 190, 125, 25);
		frame.getContentPane().add(passwordField);
		passwordLabel = new JLabel("Şifre:");
		passwordLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		passwordLabel.setBounds(230, 170, 104, 14);
		frame.getContentPane().add(passwordLabel);
		
		String[] genders = {"Erkek", "Kadın", "Belirtmek İstemiyorum"};
		genderComboBox = new JComboBox<>(genders);
		genderComboBox.setBounds(30, 250, 125, 25);
		frame.getContentPane().add(genderComboBox);
		genderLabel = new JLabel("Cinsiyet:");
		genderLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		genderLabel.setBounds(30, 230, 100, 15);
		frame.getContentPane().add(genderLabel);
		
		SpinnerNumberModel ageModel = new SpinnerNumberModel(18, 0, 120, 1);
		ageSpinner = new JSpinner(ageModel);
		ageSpinner.setBounds(230, 250, 125, 25);
		frame.getContentPane().add(ageSpinner);
		ageLabel = new JLabel("Yaş:");
		ageLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		ageLabel.setBounds(230, 230, 100, 15);
		frame.getContentPane().add(ageLabel);
		
		professionField = new JTextField();
		professionField.setColumns(10);
		professionField.setBounds(30, 310, 125, 25);
		frame.getContentPane().add(professionField);
		professionLabel = new JLabel("Meslek:");
		professionLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		professionLabel.setBounds(30, 290, 100, 15);
		frame.getContentPane().add(professionLabel);
		
		String[] incomeLevels = {"Düşük", "Orta", "Yüksek"};
		incomeLevelComboBox = new JComboBox<>(incomeLevels);
		incomeLevelComboBox.setBounds(230, 310, 125, 25);
		frame.getContentPane().add(incomeLevelComboBox);
		incomeLevelLabel = new JLabel("Gelir Düzeyi:");
		incomeLevelLabel.setFont(new Font("Tahoma", Font.BOLD, 16));
		incomeLevelLabel.setBounds(230, 290, 120, 15);
		frame.getContentPane().add(incomeLevelLabel);
		
		JButton registerButton = new JButton("Kayıt Ol");
		registerButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					Customer customer = registerCustomerIfValid();
					if (customer != null) {
						System.out.println(customer.toString());
						CustomerMainPage pg = new CustomerMainPage(customer, conn);
						pg.showFrame();
						frame.setVisible(false);
					}
				} catch (SQLException ex) {
					ex.printStackTrace();
				}
			}
		});
		registerButton.setFont(new Font("Tahoma", Font.BOLD, 18));
		registerButton.setBounds(30, 350, 125, 35);
		frame.getContentPane().add(registerButton);
		registerButton.setFocusable(false);

		JButton returnButton = new JButton("Geri Dön");
		returnButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				StartPage startPage = new StartPage(conn);
				startPage.showFrame();
				frame.setVisible(false);
			}
		});
		returnButton.setFont(new Font("Tahoma", Font.BOLD, 18));
		returnButton.setBounds(230, 350, 125, 35);
		frame.getContentPane().add(returnButton);
		returnButton.setFocusable(false);
	}
	
	public Customer registerCustomerIfValid() throws SQLException {
	    String query = "SELECT register_customer(?,?,?,?,?,?,?,?,?,?)";

	    if (nameField.getText().length() >= 3 && surnameField.getText().length() >= 3 &&
	        cityField.getText().length() >= 3 && phoneField.getText().length() >= 3 &&
	        passwordField.getText().length() >= 3 && emailField.getText().length() >= 3 && 
	        professionField.getText().length() >= 3) {

	        if (phoneField.getText().length() != 10) {
	            JOptionPane.showMessageDialog(null, "Telefon numarası uzunluğu 10 olmalı.");
	            return null;
	        }

	        
	        String email = emailField.getText();

	        if (isEmailAlreadyRegistered(email)) {
	            JOptionPane.showMessageDialog(null, "Bu e-posta adresi ile zaten kayıt olunmuş.");
	            return null;
	        } 

	        PreparedStatement statement = conn.prepareStatement(query);
	        statement.setString(1, email);
	        statement.setString(2, passwordField.getText());
	        statement.setString(3, nameField.getText());
	        statement.setString(4, surnameField.getText());
	        statement.setString(5, phoneField.getText());

	        String selectedGender = (String) genderComboBox.getSelectedItem();
	        switch (selectedGender) {
	            case "Erkek":
	                statement.setString(6, "male");
	                break;
	            case "Kadın":
	                statement.setString(6, "female");
	                break;
	            case "Belirtmek İstemiyorum":
	                statement.setString(6, "other");
	                break;
	            default:
	                statement.setString(6, "other");
	                break;
	        }

	        statement.setInt(7, (int) ageSpinner.getValue());

	        statement.setString(8, professionField.getText());

	        String selectedIncome = (String) incomeLevelComboBox.getSelectedItem();
	        switch (selectedIncome) {
	            case "Düşük":
	                statement.setString(9, "low");
	                break;
	            case "Orta":
	                statement.setString(9, "medium");
	                break;
	            case "Yüksek":
	                statement.setString(9, "high");
	                break;
	            default:
	                statement.setString(9, "low");
	                break;
	        }

	        statement.setString(10, cityField.getText());

	        ResultSet r = statement.executeQuery();
	        if (r.next()) {
	            newId = r.getInt(1);
	            JOptionPane.showMessageDialog(null, "Your new id is : " + newId);

	            query = "SELECT customer_id, email, first_name, last_name, phone_number, gender, age, profession, income_level, city, first_visit_date FROM customer WHERE customer_id = ?";
	            PreparedStatement p = conn.prepareStatement(query);
	            p.setInt(1, newId);
	            r = p.executeQuery();

	            if (r.next()) {
	                return new Customer(
	                    r.getInt("customer_id"),
	                    r.getString("email"),
	                    r.getString("first_name"),
	                    r.getString("last_name"),
	                    r.getString("phone_number"),
	                    r.getString("gender"),
	                    r.getInt("age"),
	                    r.getString("profession"),
	                    r.getString("income_level"),
	                    r.getString("city"),
	                    r.getTimestamp("first_visit_date")
	                );
	            }
	        }
	    } else {
	        JOptionPane.showMessageDialog(null, "3 karakterden kısa bir veri girilemez.");
	    }

	    return null;
	}
	
	public boolean isEmailAlreadyRegistered(String email) throws SQLException {
	    String query = "SELECT COUNT(*) FROM customer WHERE email = ?";
	    try (PreparedStatement checkEmailStmt = conn.prepareStatement(query)) {
	        checkEmailStmt.setString(1, email);
	        try (ResultSet emailResult = checkEmailStmt.executeQuery()) {
	            return emailResult.next() && emailResult.getInt(1) > 0;
	        }
	    }
	}
	
	//test sınıfı için
	public JTextField getNameField() {
	    return nameField;
	}
	
	public JTextField getSurnameField() {
	    return surnameField;
	}

	public JTextField getEmailField() {
	    return emailField;
	}

	public JTextField getPhoneField() {
	    return phoneField;
	}

	public JTextField getCityField() {
	    return cityField;
	}

	public JTextField getPasswordField() {
	    return passwordField;
	}
	
	public JTextField getProfessionField() {
	    return professionField;
	}

	public JComboBox<String> getGenderComboBox() {
	    return genderComboBox;
	}

	public JSpinner getAgeSpinner() {
	    return ageSpinner;
	}

	public JComboBox<String> getIncomeLevelComboBox() {
	    return incomeLevelComboBox;
	}


	public void showFrame() {
		frame.setVisible(true);
	}
}