package com.taskagitmakas.form;

import javax.swing.JFrame;

import com.taskagitmakas.entity.User;

import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JLabel;

public class SelectForm {

	private JFrame frmAnaSayfa;
	private JLabel lblUsername ;
	public static TrainForm trainForm;
	/**
	 * Create the application.
	 */
	public SelectForm() {
		initialize();
		
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmAnaSayfa = new JFrame();
		frmAnaSayfa.setTitle("ANA SAYFA");
		frmAnaSayfa.addWindowListener(new WindowAdapter() {
		 
			@Override
			public void windowActivated(WindowEvent e) {
				
				lblUsername.setText(LoginForm.selectedUser.toString());
				System.out.println(LoginForm.selectedUser.toString()+" in selectForm");
			}
			@Override
			public void windowClosed(WindowEvent e) {
				
				LoginForm.loginForm.frmKullancGirii.setVisible(true);
			}
		});
		frmAnaSayfa.setBounds(100, 100, 399, 245);
		frmAnaSayfa.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		JButton btnGame = new JButton("OYUN");
		btnGame.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				new GameForm();
				frmAnaSayfa.setVisible(false);
				
				
			}
		});
		
		JButton btnTrain = new JButton("EĞİTİM");
		btnTrain.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				
				trainForm=new TrainForm();
				frmAnaSayfa.setVisible(false);
			}
});
		
		JLabel lblHoGeldin = new JLabel("Hoş Geldin:");
		
		 lblUsername = new JLabel("userNa");
		GroupLayout groupLayout = new GroupLayout(frmAnaSayfa.getContentPane());
		groupLayout.setHorizontalGroup(
			groupLayout.createParallelGroup(Alignment.LEADING)
				.addGroup(groupLayout.createSequentialGroup()
					.addGap(102)
					.addGroup(groupLayout.createParallelGroup(Alignment.TRAILING)
						.addComponent(lblHoGeldin)
						.addComponent(btnGame, GroupLayout.PREFERRED_SIZE, 86, GroupLayout.PREFERRED_SIZE))
					.addGap(18)
					.addGroup(groupLayout.createParallelGroup(Alignment.LEADING)
						.addComponent(btnTrain)
						.addComponent(lblUsername))
					.addContainerGap(113, Short.MAX_VALUE))
		);
		groupLayout.setVerticalGroup(
			groupLayout.createParallelGroup(Alignment.LEADING)
				.addGroup(groupLayout.createSequentialGroup()
					.addGap(21)
					.addGroup(groupLayout.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblHoGeldin)
						.addComponent(lblUsername))
					.addGap(26)
					.addGroup(groupLayout.createParallelGroup(Alignment.TRAILING, false)
						.addComponent(btnTrain, Alignment.LEADING, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
						.addComponent(btnGame, Alignment.LEADING, GroupLayout.PREFERRED_SIZE, 61, GroupLayout.PREFERRED_SIZE))
					.addContainerGap(95, Short.MAX_VALUE))
		);
		frmAnaSayfa.getContentPane().setLayout(groupLayout);
	}
	
	 

	public JFrame getFrame() {
		return frmAnaSayfa;
	}

	public void setFrame(JFrame frame) {
		this.frmAnaSayfa = frame;
	}
}