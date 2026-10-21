package Proje;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.awt.event.ActionEvent;

public class ParentRegisterPanel extends JFrame {

	private JPanel contentPane;
	private JTextField registerName;
	private JTextField registerSurname;
	private JPasswordField registerPassword_1;
	private JPasswordField registerPassword_2;

	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ParentRegisterPanel frame = new ParentRegisterPanel();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	
	public ParentRegisterPanel() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 645, 674);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(314, 10, 1, 1);
		contentPane.add(panel);
		panel.setLayout(null);
		
		JPanel panel_1 = new JPanel();
		panel_1.setBounds(305, 21, 10, 10);
		contentPane.add(panel_1);
		panel_1.setLayout(null);
		
		JLabel lblParentRegister = new JLabel("Parent Register");
		lblParentRegister.setHorizontalAlignment(SwingConstants.CENTER);
		lblParentRegister.setFont(new Font("Calibri", Font.BOLD, 55));
		lblParentRegister.setBounds(20, 22, 586, 84);
		contentPane.add(lblParentRegister);
		
		registerName = new JTextField();
		registerName.setColumns(10);
		registerName.setBounds(148, 154, 288, 20);
		contentPane.add(registerName);
		
		registerSurname = new JTextField();
		registerSurname.setColumns(10);
		registerSurname.setBounds(148, 222, 288, 20);
		contentPane.add(registerSurname);
		
		registerPassword_1 = new JPasswordField();
		registerPassword_1.setBounds(148, 291, 288, 20);
		contentPane.add(registerPassword_1);
		
		JLabel lblNewLabel_4 = new JLabel("Name");
		lblNewLabel_4.setFont(new Font("Calibri", Font.BOLD, 17));
		lblNewLabel_4.setBounds(148, 132, 89, 20);
		contentPane.add(lblNewLabel_4);
		
		registerPassword_2 = new JPasswordField();
		registerPassword_2.setBounds(148, 359, 288, 20);
		contentPane.add(registerPassword_2);
		
		JLabel lblNewLabel_7 = new JLabel("Password");
		lblNewLabel_7.setFont(new Font("Calibri", Font.BOLD, 17));
		lblNewLabel_7.setBounds(148, 332, 89, 32);
		contentPane.add(lblNewLabel_7);
		
		JButton btnRegister = new JButton("Register");
		btnRegister.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int i =0;
				char[] pwRegister1 = registerPassword_1.getPassword();
                String pwRegister1_String = new String(pwRegister1);
                char[] pwRegister2 = registerPassword_2.getPassword();
                String pwRegister2_String = new String(pwRegister2);
                String nameRegister = registerName.getText();
                String surnameRegister = registerSurname.getText();
                if(!pwRegister1_String.equals(pwRegister2_String)) {
                	final JPanel panel = new JPanel();
                    JOptionPane.showMessageDialog(panel, "Şifre Uyuşmazlığı", "Warning",JOptionPane.WARNING_MESSAGE);
                }
                System.out.println(i);
                User user = new User(nameRegister, surnameRegister, pwRegister1_String,"parent");
                fileOperations fileOps = new fileOperations();
                try {
					fileOps.addNewUser(nameRegister, surnameRegister, pwRegister1_String, "parent");
					EventQueue.invokeLater(new Runnable() {
						public void run() {
							try {
								mainMenu frame = new mainMenu();
								frame.setVisible(true);
							} catch (Exception e) {
								e.printStackTrace();
							}
						}
					});
					dispose();
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});
		btnRegister.setFont(new Font("Calibri", Font.BOLD, 19));
		btnRegister.setBounds(235, 423, 128, 37);
		contentPane.add(btnRegister);
		
		JLabel lblNewLabel_6 = new JLabel("Password");
		lblNewLabel_6.setFont(new Font("Calibri", Font.BOLD, 17));
		lblNewLabel_6.setBounds(148, 264, 89, 32);
		contentPane.add(lblNewLabel_6);
		
		JLabel lblNewLabel_5 = new JLabel("Surname");
		lblNewLabel_5.setFont(new Font("Calibri", Font.BOLD, 17));
		lblNewLabel_5.setBounds(148, 197, 89, 21);
		contentPane.add(lblNewLabel_5);
	}
}
