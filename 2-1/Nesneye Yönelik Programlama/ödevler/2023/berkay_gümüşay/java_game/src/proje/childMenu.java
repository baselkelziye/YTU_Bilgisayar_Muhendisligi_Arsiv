package Proje;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class childMenu extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	

	/**
	 * Create the frame.
	 */
	public childMenu(User child) {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 556, 595);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(269, 10, 1, 1);
		contentPane.add(panel);
		panel.setLayout(null);
		// GİRİŞ YAPMIŞ OLAN ÇOCUĞUN İSMİNİ EKRANA YAZDIRIYORUM
		JLabel lblHoGeldin = new JLabel("Hoş geldin "+child.getName());
		lblHoGeldin.setHorizontalAlignment(SwingConstants.CENTER);
		lblHoGeldin.setFont(new Font("Calibri", Font.BOLD, 55));
		lblHoGeldin.setBounds(0, 22, 540, 84);
		contentPane.add(lblHoGeldin);
		
		JButton btnOyunaBala = new JButton("Oyuna Başla");
		btnOyunaBala.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				EventQueue.invokeLater(new Runnable() {
        			public void run() {
        				try {
        					// OYUNU BAŞLATIYORUM
        					chooseTest frame = new chooseTest(child, child.getName(), child.getSurname(), 2);
        					//childPanel frame = new childPanel(child);
        					frame.setVisible(true);
        				} catch (Exception e) {
        					e.printStackTrace();
        				}
        			}
        		});
			}
		});
		btnOyunaBala.setFont(new Font("Calibri", Font.BOLD, 16));
		btnOyunaBala.setBounds(139, 191, 245, 68);
		contentPane.add(btnOyunaBala);
		
		JButton btnSralamalarGr = new JButton("Sıralamaları Gör");
		btnSralamalarGr.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							// YÜKSEK SKOR TABLOSUNU ÇOCUĞA GÖSTERİYORUM
							chooseTest frame = new chooseTest(child, child.getName(), child.getSurname(), 1);
						//	HighScorePanel frame = new HighScorePanel(child);
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		btnSralamalarGr.setFont(new Font("Calibri", Font.BOLD, 16));
		btnSralamalarGr.setBounds(139, 305, 245, 68);
		contentPane.add(btnSralamalarGr);
		
		JButton btnkYap = new JButton("Çıkış Yap");
		btnkYap.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							// ÇIKIŞ YAPMA İŞLEMİ
							mainMenu frame = new mainMenu();
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		btnkYap.setFont(new Font("Calibri", Font.BOLD, 16));
		btnkYap.setBounds(139, 427, 245, 68);
		contentPane.add(btnkYap);
	}
}
