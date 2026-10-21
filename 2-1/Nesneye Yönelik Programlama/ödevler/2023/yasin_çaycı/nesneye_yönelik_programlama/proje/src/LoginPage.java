package a;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
 
public class LoginPage extends JFrame implements ActionListener, ItemListener {

	private static final long serialVersionUID = 1L;
	
	private Container container = getContentPane();
	private JLabel userLabel = new JLabel("USERNAME");
	private JLabel passwordLabel = new JLabel("PASSWORD");
	private JTextField userTextField = new JTextField();
	private JPasswordField passwordField = new JPasswordField();
	private JButton loginButton = new JButton("LOGIN");
	private JButton signupButton = new JButton("SIGN UP");
	private JCheckBox showPassword = new JCheckBox("Show Password");
    private final JCheckBox chckbxAdmin = new JCheckBox("Admin");
    private final JCheckBox chckbxUser = new JCheckBox("User");
    private ArrayList<User> userList;
	private ArrayList<Admin> adminList; 
	public static User trueUser;
 
    public LoginPage() {
        setLayoutManager();
        setLocationAndSize();
        addComponentsToContainer();
        addActionEvent();
        userList = new ArrayList<>();
    	adminList = new ArrayList<>();
    }
 
    public void setLayoutManager() {
        container.setLayout(null);
    }
 
    public void setLocationAndSize() {
        userLabel.setBounds(50, 150, 100, 30);
        passwordLabel.setBounds(50, 220, 100, 30);
        userTextField.setBounds(150, 150, 150, 30);
        passwordField.setBounds(150, 220, 150, 30);
        showPassword.setBounds(150, 250, 150, 30);
        loginButton.setBounds(66, 300, 100, 30);
        signupButton.setBounds(221, 300, 100, 30);
    }
 
    public void addComponentsToContainer() {
        container.add(userLabel);
        container.add(passwordLabel);
        container.add(userTextField);
        container.add(passwordField);
        container.add(showPassword);
        container.add(loginButton);
        container.add(signupButton);
        chckbxAdmin.setBounds(155, 102, 71, 21);
        getContentPane().add(chckbxAdmin);   
        chckbxUser.setBounds(245, 102, 55, 21);
        getContentPane().add(chckbxUser);
    }
 
    public void addActionEvent() {
        loginButton.addActionListener(this);
        signupButton.addActionListener(this);
        showPassword.addActionListener(this);
        chckbxAdmin.addActionListener(this);
        chckbxUser.addActionListener(this);
        chckbxAdmin.addItemListener(this);
        chckbxUser.addItemListener(this);
    }
    
    public void itemStateChanged(ItemEvent e) {
        if (e.getSource() == chckbxAdmin && chckbxAdmin.isSelected()) {
        	chckbxUser.setSelected(false);
        } else if (e.getSource() == chckbxUser && chckbxUser.isSelected()) {
        	chckbxAdmin.setSelected(false);
        }
    }
 
    @SuppressWarnings("deprecation")
	@Override
    public void actionPerformed(ActionEvent e) {
        //login button
        if (e.getSource() == loginButton) {
            String userText = userTextField.getText();
            String pwdText = passwordField.getText();
            if (authenticate(userText, pwdText,1)) {
                JOptionPane.showMessageDialog(this, "Login Successful");
                AdminPage frame = new AdminPage();
                jumpToAdmin(frame);
            } 
            else if (authenticate(userText, pwdText,0)) {
                JOptionPane.showMessageDialog(this, "Login Successful");
                StartPage frame = new StartPage();
                jumpToStart(frame);
            }
            else {
                JOptionPane.showMessageDialog(this, "Invalid Username or Password");
            }
 
        }
        //sign up button
        if (e.getSource() == signupButton) {
        	SignupPage frame = new SignupPage();
        	jumpToSignUp(frame);
        }	
       //showPassword 	
        if (e.getSource() == showPassword) {
            if (showPassword.isSelected()) {
                passwordField.setEchoChar((char) 0);
            } else {
                passwordField.setEchoChar('*');
            }
        }
    }
    
    public void setSelectedRole(String role) {
        if (role.equalsIgnoreCase("admin")) {
            chckbxAdmin.setSelected(true);
        } else if (role.equalsIgnoreCase("user")) {
            chckbxUser.setSelected(true);
        }
    }
 
    private void jumpToSignUp(SignupPage frame) {
    	frame.setTitle("Sign Up Page");
        frame.setVisible(true);
        this.setVisible(false);
        frame.setBounds(10, 10, 400, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
    }
    
    private void jumpToStart(StartPage frame) {
        frame.setVisible(true);
        this.setVisible(false);
        frame.setBounds(10, 10, 400, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
    }
    
    private void jumpToAdmin(AdminPage frame) {
        frame.setTitle("Admin Page");
        frame.setVisible(true);
        this.setVisible(false);
        frame.setBounds(10, 10, 400, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
    }
    
    @SuppressWarnings("unchecked")
	private boolean authenticate(String username, String password, int select) {
    	String path;
    	if(select == 0)
    		path = "users.dat";
    	else
    		path = "admins.dat";
    	try {
    		 try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(path))) {
    			 if(select == 0)
    				userList = (ArrayList<User>) ois.readObject();
    		    else
    		    	adminList = (ArrayList<Admin>) ois.readObject();	 
    	       } catch (IOException e) {
    	           e.printStackTrace();
    	           return false;
    	       }
    	}
    	catch(Exception e) {
    		e.printStackTrace();
    		return false;
    	}
    	
    	if(select == 0) { 
	    	for (User user : userList) 
	            if (user.getUsername().equals(username) && user.getPassword().equals(password)) {
	            	trueUser = user;
	                return true; // Kullanıcı adı ve şifre eşleşir
	            }
    	}
    	else {
    		for (Admin admin : adminList) 
	            if (admin.getUsername().equals(username) && admin.getPassword().equals(password))
	                return true;
    	}
        return false; // Eşleşme bulunamadı
    }
}
 