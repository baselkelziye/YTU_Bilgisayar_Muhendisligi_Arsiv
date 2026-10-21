package Proje;

import java.awt.EventQueue;
import java.io.IOException;
import java.util.ArrayList;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Color;

public class showChild extends JFrame {

	private JPanel contentPane;

	private JButton[] buttons = new JButton[10];
	public showChild(User parent) {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 703, 624);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		fileOperations fileOps = new fileOperations();
		try {
			int i = 100;
			int j = 0;
			// ÇOCUKLARIN LİSTESİNİ DOSYADAN ALMA
			ArrayList<User> childList = fileOps.getChildList();
			if(childList.isEmpty()) {
				JLabel lblNewLabel = new JLabel("Sistemde Hiç Çocuk Yok");
				lblNewLabel.setForeground(new Color(255, 0, 0));
				lblNewLabel.setFont(new Font("Calibri", Font.BOLD, 28));
				lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
				lblNewLabel.setBounds(172, 169, 348, 84);
				contentPane.add(lblNewLabel);
			}
			else {
				for(User user : childList) {
					// BİR BUTON DİZİSİ OLUŞTURARAK OCUKLARIN İSİMLERİNİ EKRANA YAZDIRMA
					buttons[j] = new JButton(user.getName()+" "+user.getSurname());
					buttons[j].setFont(new Font("Calibri", Font.BOLD, 16));
					buttons[j].setBounds(235, i, 228, 55);
					contentPane.add(buttons[j]);
					buttons[j].addActionListener(new ActionListener() {
						public void actionPerformed(ActionEvent e) {
							EventQueue.invokeLater(new Runnable() {
								public void run() {
									try {
										chooseTest frame = new chooseTest(parent,user.getName(),user.getSurname(),0);
										frame.setVisible(true);
									} catch (Exception e) {
										e.printStackTrace();
									}
								}
							});
							/*EventQueue.invokeLater(new Runnable() {
								public void run() {
									try {
										// HER ÇOCUĞUN BİLGİLERİNİ AÇMAK İÇİN KENDİ İSİM, SOYİSMİNDE BİR BUTON OLUŞTURMA
										
										childInfo frame = new childInfo(parent,user.getName(),user.getSurname());
										frame.setVisible(true);
									} catch (Exception e) {
										e.printStackTrace();
									}
								}
							});*/
							dispose();
						}
					});
					i=i+80;
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(254, 11, 10, 10);
		contentPane.add(panel);
		
		JLabel lblChildList = new JLabel("Child List");
		lblChildList.setHorizontalAlignment(SwingConstants.CENTER);
		lblChildList.setFont(new Font("Calibri", Font.BOLD, 55));
		lblChildList.setBounds(0, 21, 687, 84);
		contentPane.add(lblChildList);
		
		JButton btnBack = new JButton("Geri Dön");
		btnBack.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
        			public void run() {
        				try {
        					// ÇIKIŞ YAPMA İŞLEMİ
        					parentPanel frame = new parentPanel(parent);
        					frame.setVisible(true);
        				} catch (Exception e) {
        					e.printStackTrace();
        				}
        			}
        		});
				dispose();
			}
		});
		btnBack.setFont(new Font("Calibri", Font.BOLD, 16));
		btnBack.setBounds(525, 516, 152, 58);
		contentPane.add(btnBack);
		
		
		
		
		
		
		
		
		
	}
}
