package com.taskagitmakas.form;

import javax.swing.JFrame;
import javax.swing.JPanel;
import com.taskagitmakas.dao.UserDao;
import com.taskagitmakas.dao.UserImp;
import com.taskagitmakas.entity.User;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class NewUserForm {

	private JFrame frmKullancKayt;
	private JTextField nameTF;
	private JTextField surnameTF;
	
	
	/**
	 * Create the application.
	 */
	public NewUserForm() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmKullancKayt = new JFrame();
		frmKullancKayt.setTitle("KULLANICI KAYIT");
		frmKullancKayt.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosed(WindowEvent e) {
				
				LoginForm.loginForm.frmKullancGirii.setVisible(true);
			}
		});
		frmKullancKayt.setBounds(100, 100, 450, 300);
		frmKullancKayt.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		frmKullancKayt.getContentPane().setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(12, 12, 426, 249);
		frmKullancKayt.getContentPane().add(panel);
		GridBagLayout gbl_panel = new GridBagLayout();
		gbl_panel.columnWidths = new int[]{0, 0, 0, 0, 0, 0};
		gbl_panel.rowHeights = new int[]{0, 0, 0, 0, 0};
		gbl_panel.columnWeights = new double[]{0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
		gbl_panel.rowWeights = new double[]{0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
		panel.setLayout(gbl_panel);
		
		JLabel lblName = new JLabel("Ad:");
		GridBagConstraints gbc_lblName = new GridBagConstraints();
		gbc_lblName.insets = new Insets(0, 0, 5, 5);
		gbc_lblName.gridx = 2;
		gbc_lblName.gridy = 1;
		panel.add(lblName, gbc_lblName);
		
		nameTF = new JTextField();
		GridBagConstraints gbc_nameTF = new GridBagConstraints();
		gbc_nameTF.fill = GridBagConstraints.VERTICAL;
		gbc_nameTF.anchor = GridBagConstraints.WEST;
		gbc_nameTF.insets = new Insets(0, 0, 5, 0);
		gbc_nameTF.gridx = 4;
		gbc_nameTF.gridy = 1;
		panel.add(nameTF, gbc_nameTF);
		nameTF.setColumns(10);
		
		JLabel lblSurname = new JLabel("Soyad:");
		GridBagConstraints gbc_lblSurname = new GridBagConstraints();
		gbc_lblSurname.insets = new Insets(0, 0, 5, 5);
		gbc_lblSurname.gridx = 2;
		gbc_lblSurname.gridy = 2;
		panel.add(lblSurname, gbc_lblSurname);
		
		surnameTF = new JTextField();
		GridBagConstraints gbc_surnameTF = new GridBagConstraints();
		gbc_surnameTF.insets = new Insets(0, 0, 5, 0);
		gbc_surnameTF.anchor = GridBagConstraints.WEST;
		gbc_surnameTF.gridx = 4;
		gbc_surnameTF.gridy = 2;
		panel.add(surnameTF, gbc_surnameTF);
		surnameTF.setColumns(10);
		
		JButton btnKayitEt = new JButton("Kayıt Et");
		btnKayitEt.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				if(nameTF.getText().length()>0){
					UserDao userService=new UserImp();
					User user=new User();
					user.setName(nameTF.getText());
					user.setSurname(surnameTF.getText());
					userService.insert(user);
					nameTF.setText("");
					surnameTF.setText("");
					JOptionPane.showMessageDialog(new JFrame(), "Kullanici Eklendi");
				}
				
			}
		});
		GridBagConstraints gbc_btnKayitEt = new GridBagConstraints();
		gbc_btnKayitEt.gridx = 4;
		gbc_btnKayitEt.gridy = 3;
		panel.add(btnKayitEt, gbc_btnKayitEt);
		frmKullancKayt.setVisible(true);
	}
}
