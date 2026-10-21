package Proje;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.SwingConstants;
import java.awt.Component;
import javax.swing.Box;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class parentPanel extends JFrame {

	private JPanel contentPane;

	
	public parentPanel(User parent) {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 703, 624);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(331, 11, 10, 10);
		contentPane.add(panel);
		// EBEVEYNİN İSMİNİ EKRANA YAZDIRMA
		JLabel lblWelcome = new JLabel("Hoş geldin "+parent.getName()+" "+parent.getSurname());
		lblWelcome.setHorizontalAlignment(SwingConstants.CENTER);
		lblWelcome.setFont(new Font("Calibri", Font.BOLD, 55));
		lblWelcome.setBounds(0, 34, 687, 84);
		contentPane.add(lblWelcome);
		
		Component verticalStrut = Box.createVerticalStrut(20);
		verticalStrut.setBounds(555, 117, 1, 20);
		contentPane.add(verticalStrut);
		
		Component verticalGlue = Box.createVerticalGlue();
		verticalGlue.setBounds(509, 117, 1, 1);
		contentPane.add(verticalGlue);
		
		JLabel lblNewLabel = new JLabel("");
		lblNewLabel.setBounds(182, 167, 46, 14);
		contentPane.add(lblNewLabel);
		// AYAR YAPMA SEÇENEĞİ
		JButton btnChildDifficulty = new JButton("Alıştırma Ekleme");
		btnChildDifficulty.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							changeParametersPanel frame = new changeParametersPanel(parent);
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		btnChildDifficulty.setFont(new Font("Calibri", Font.BOLD, 16));
		btnChildDifficulty.setBounds(217, 155, 245, 68);
		contentPane.add(btnChildDifficulty);
		// ÇOCUKLARIN BİLGİLERİNE ERİŞME SEÇENEĞİ
		JButton btnChildGraph = new JButton("Çocuk Grafik Gösterme");
		btnChildGraph.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							showChild frame = new showChild(parent);
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
				dispose();
			}
		});
		btnChildGraph.setFont(new Font("Calibri", Font.BOLD, 16));
		btnChildGraph.setBounds(217, 258, 245, 68);
		contentPane.add(btnChildGraph);
		// ÇIKIŞ YAPMA İŞLEMİ
		JButton btnBack = new JButton("Çıkış Yap");
		btnBack.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
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
			}
		});
		btnBack.setFont(new Font("Calibri", Font.BOLD, 16));
		btnBack.setBounds(217, 466, 245, 68);
		contentPane.add(btnBack);
		// YÜKSEK SKORLARI GÖSTERME İŞLEMİ
		JButton btnHighScore = new JButton("Yüksek Skor Sıralaması");
		btnHighScore.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							chooseTest frame = new chooseTest(parent, "", "",7);
							//HighScorePanel frame = new HighScorePanel(parent);
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		btnHighScore.setFont(new Font("Calibri", Font.BOLD, 16));
		btnHighScore.setBounds(217, 363, 245, 68);
		contentPane.add(btnHighScore);
	}
}
