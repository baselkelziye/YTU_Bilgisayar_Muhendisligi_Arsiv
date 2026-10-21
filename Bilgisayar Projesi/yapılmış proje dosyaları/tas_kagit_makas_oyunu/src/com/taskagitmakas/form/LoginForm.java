package com.taskagitmakas.form;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import com.taskagitmakas.dao.UserDao;
import com.taskagitmakas.dao.UserImp;
import com.taskagitmakas.entity.User;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import javax.swing.JComboBox;
import java.awt.Insets;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.List;
import java.util.Vector;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class LoginForm {

	public JFrame frmKullancGirii;
	JComboBox userListCB;
	private JButton btnGiriYap;
	private JButton btnYeniKullanc;
	List<User> userList;
	public static LoginForm loginForm;
	public static User selectedUser;
	public static SelectForm selectForm;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					LoginForm window = new LoginForm();
					loginForm=window;
					window.frmKullancGirii.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public LoginForm() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmKullancGirii = new JFrame();
		frmKullancGirii.setTitle("KULLANICI GİRİŞİ");
		frmKullancGirii.addWindowListener(new WindowAdapter() {
		 
			@Override
			public void windowActivated(WindowEvent e) {
				UserDao userService=new UserImp();
				userList=userService.all();

		        Vector model = new Vector();
		        userListCB.removeAllItems();
		        userListCB.addItem("Seçiniz");
				 for (User user : userList) {
					
					 userListCB.addItem(user);
					 
				}
				
			}
		});
		frmKullancGirii.setBounds(100, 100, 450, 300);
		frmKullancGirii.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		GridBagLayout gridBagLayout = new GridBagLayout();
		gridBagLayout.columnWidths = new int[]{60, 113, 96, 0, 0};
		gridBagLayout.rowHeights = new int[]{90, 24, 25, 0};
		gridBagLayout.columnWeights = new double[]{0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
		gridBagLayout.rowWeights = new double[]{0.0, 0.0, 0.0, Double.MIN_VALUE};
		frmKullancGirii.getContentPane().setLayout(gridBagLayout);
		 
		 JLabel lblKullancSeiniz = new JLabel("Kullanıcı Seçiniz:");
		 GridBagConstraints gbc_lblKullancSeiniz = new GridBagConstraints();
		 gbc_lblKullancSeiniz.anchor = GridBagConstraints.EAST;
		 gbc_lblKullancSeiniz.insets = new Insets(0, 0, 5, 5);
		 gbc_lblKullancSeiniz.gridx = 1;
		 gbc_lblKullancSeiniz.gridy = 1;
		 frmKullancGirii.getContentPane().add(lblKullancSeiniz, gbc_lblKullancSeiniz);
		 
		  userListCB = new JComboBox();
		  GridBagConstraints gbc_userListCB = new GridBagConstraints();
		  gbc_userListCB.gridwidth = 2;
		  gbc_userListCB.fill = GridBagConstraints.HORIZONTAL;
		  gbc_userListCB.insets = new Insets(0, 0, 5, 0);
		  gbc_userListCB.gridx = 2;
		  gbc_userListCB.gridy = 1;
		  frmKullancGirii.getContentPane().add(userListCB, gbc_userListCB);
		 
		 btnGiriYap = new JButton("Giriş Yap");
		 btnGiriYap.addActionListener(new ActionListener() {
		 	public void actionPerformed(ActionEvent e) {
		 		
		 		int i=0;
		 		while(i<userList.size() && !userListCB.getSelectedItem().equals(userList.get(i))){	
		 			i++;
		 		}
		 		
		 		if(i+1>userList.size()){
		 			
					JOptionPane.showMessageDialog(new JFrame(), "Kullanici Bulunamadı");

		 			
		 		}else {
			 

			 		selectedUser=userList.get(i);
		 			System.out.println(selectedUser.toString()+" Kullanıcısı Seçildi.");
		 			selectForm=new SelectForm();
		  
 		 			selectForm.getFrame().setVisible(true);
 		 			frmKullancGirii.dispose();
		 		}
		 		 
		 		
		 	}
		 });
		 GridBagConstraints gbc_btnGiriYap = new GridBagConstraints();
		 gbc_btnGiriYap.insets = new Insets(0, 0, 0, 5);
		 gbc_btnGiriYap.anchor = GridBagConstraints.WEST;
		 gbc_btnGiriYap.gridx = 2;
		 gbc_btnGiriYap.gridy = 2;
		 frmKullancGirii.getContentPane().add(btnGiriYap, gbc_btnGiriYap);
		 
		 btnYeniKullanc = new JButton("Yeni Kullanıcı");
		 btnYeniKullanc.addActionListener(new ActionListener() {
		 	public void actionPerformed(ActionEvent e) {
		 		
		 		
		 		new NewUserForm();
		 		frmKullancGirii.dispose();
		 		System.out.println("yeni kullanıcı");
		 		
		 	}
		 });
		 GridBagConstraints gbc_btnYeniKullanc = new GridBagConstraints();
		 gbc_btnYeniKullanc.gridx = 3;
		 gbc_btnYeniKullanc.gridy = 2;
		 frmKullancGirii.getContentPane().add(btnYeniKullanc, gbc_btnYeniKullanc);
	}
}
