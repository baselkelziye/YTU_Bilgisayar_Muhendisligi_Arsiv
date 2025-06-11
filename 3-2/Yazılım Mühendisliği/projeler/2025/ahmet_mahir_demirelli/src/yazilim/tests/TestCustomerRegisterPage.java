package yazilim.tests;

import static org.junit.jupiter.api.Assertions.*;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import yazilim.CustomerRegisterPage;
import yazilim.classes.Customer;

class TestCustomerRegisterPage {
	private static Connection conn;
	private static CustomerRegisterPage registerPage1;
    private static CustomerRegisterPage registerPage2;
    private static int newId;
    
	@BeforeAll
	static void setUpBeforeClass() throws Exception {
		conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
		//CustomerRegisterPage nesneleri
		registerPage1 = new CustomerRegisterPage(conn); 
        registerPage2 = new CustomerRegisterPage(conn);
	}

	@AfterEach
	void tearDownAfterClass() throws Exception {
		if (conn != null && !conn.isClosed() && newId > 0) {
            PreparedStatement deleteCustomer = conn.prepareStatement("DELETE FROM customer WHERE customer_id = ?");
            deleteCustomer.setInt(1, newId);
            deleteCustomer.executeUpdate();
        }
	}

	
	@Test
    void SuccessfulRegistration() throws SQLException {
        // İlk kullanıcı için geçerli verilerle kayıt işlemi
		registerPage1.getNameField().setText("Ali");
	    registerPage1.getSurnameField().setText("Veli");
	    registerPage1.getPhoneField().setText("5012345678");
	    registerPage1.getEmailField().setText("ali.veli@example.com");
	    registerPage1.getPasswordField().setText("securepass");
	    registerPage1.getCityField().setText("Ankara");
	    registerPage1.getProfessionField().setText("Mühendis");
	    registerPage1.getGenderComboBox().setSelectedIndex(0);  
	    registerPage1.getAgeSpinner().setValue(28);
	    registerPage1.getIncomeLevelComboBox().setSelectedIndex(1); 

	    Customer customer = registerPage1.registerCustomerIfValid();
	    newId = customer.getCustomerId();

	    assertNotNull(customer);
	    assertEquals("Ali", customer.getFirstName());
	    assertEquals("ali.veli@example.com", customer.getEmail());
	    assertEquals("Veli", customer.getLastName()); 
	    assertEquals("5012345678", customer.getPhoneNumber()); 
	    assertEquals("ali.veli@example.com", customer.getEmail());  
	    assertEquals("Ankara", customer.getCity()); 
	    assertEquals("Mühendis", customer.getProfession());  
	    assertEquals("male", customer.getGender()); 
	    assertEquals(28, customer.getAge());  
	    assertEquals("medium", customer.getIncomeLevel());  
    }
	
	@Test
    void testMissingName() throws SQLException {
        // name boş
        registerPage1.getNameField().setText("");
        registerPage1.getSurnameField().setText("Veli");
        registerPage1.getPhoneField().setText("5012345678");
        registerPage1.getEmailField().setText("ali.veli@example.com");
        registerPage1.getPasswordField().setText("securepass");
        registerPage1.getCityField().setText("Ankara");
        registerPage1.getProfessionField().setText("Mühendis");
        registerPage1.getGenderComboBox().setSelectedIndex(0);  
        registerPage1.getAgeSpinner().setValue(28);
        registerPage1.getIncomeLevelComboBox().setSelectedIndex(1); 

        Customer customer = registerPage1.registerCustomerIfValid();

        assertNull(customer);
    }
	
	@Test
    void testInvalidPhoneNumber() throws SQLException {
        // telefon numarası 10 rakamdan oluşmuyor
        registerPage1.getNameField().setText("Ali");
        registerPage1.getSurnameField().setText("Veli");
        registerPage1.getPhoneField().setText("12345"); 
        registerPage1.getEmailField().setText("ali.veli@example.com");
        registerPage1.getPasswordField().setText("securepass");
        registerPage1.getCityField().setText("Ankara");
        registerPage1.getProfessionField().setText("Mühendis");
        registerPage1.getGenderComboBox().setSelectedIndex(0);  
        registerPage1.getAgeSpinner().setValue(28);
        registerPage1.getIncomeLevelComboBox().setSelectedIndex(1); 

        Customer customer = registerPage1.registerCustomerIfValid();

        assertNull(customer);
    }

	@Test
    void testEmailAlreadyRegistered() throws SQLException {
        // daha önce aynı email kayıt edilmiş
        registerPage1.getNameField().setText("Ali");
        registerPage1.getSurnameField().setText("Veli");
        registerPage1.getPhoneField().setText("5012345678");
        registerPage1.getEmailField().setText("ali.veli@example.com");
        registerPage1.getPasswordField().setText("securepass");
        registerPage1.getCityField().setText("Ankara");
        registerPage1.getProfessionField().setText("Mühendis");
        registerPage1.getGenderComboBox().setSelectedIndex(0);  
        registerPage1.getAgeSpinner().setValue(28);
        registerPage1.getIncomeLevelComboBox().setSelectedIndex(1); 

        Customer customer1 = registerPage1.registerCustomerIfValid();
        newId = customer1.getCustomerId();

        registerPage2.getNameField().setText("Ali Veli");
        registerPage2.getSurnameField().setText("Toprak");
        registerPage2.getPhoneField().setText("5076543210");
        registerPage2.getEmailField().setText("ali.veli@example.com"); 
        registerPage2.getPasswordField().setText("newpass");
        registerPage2.getCityField().setText("Istanbul");
        registerPage2.getProfessionField().setText("Doktor");
        registerPage2.getGenderComboBox().setSelectedIndex(0);  
        registerPage2.getAgeSpinner().setValue(30);
        registerPage2.getIncomeLevelComboBox().setSelectedIndex(2); 

        Customer customer2 = registerPage2.registerCustomerIfValid();

        assertNull(customer2);
    }
	

}
