package Proje;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.awt.event.ActionEvent;

public class changeParametersPanel extends JFrame {
	
	// MENÜ İÇİN GEREKEN GUİ ÖGELERİ
	private JPanel contentPane;
	private JTextField textA;
	private JTextField textB;
	private JTextField textN;

	
	public changeParametersPanel(User parent) {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 641, 350);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(304, 11, 10, 10);
		contentPane.add(panel);
		
		textA = new JTextField();
		textA.setBounds(59, 118, 86, 20);
		contentPane.add(textA);
		textA.setColumns(10);
		
		textB = new JTextField();
		textB.setColumns(10);
		textB.setBounds(257, 118, 86, 20);
		contentPane.add(textB);
		
		textN = new JTextField();
		textN.setColumns(10);
		textN.setBounds(484, 118, 86, 20);
		contentPane.add(textN);
		
		JLabel lblB = new JLabel("B:");
		lblB.setFont(new Font("Calibri", Font.BOLD, 17));
		lblB.setBounds(227, 120, 49, 18);
		contentPane.add(lblB);
		
		JLabel lblN = new JLabel("N:");
		lblN.setFont(new Font("Calibri", Font.BOLD, 17));
		lblN.setBounds(454, 121, 49, 17);
		contentPane.add(lblN);
		
		JLabel lblNewLabel_1_1 = new JLabel("A:");
		lblNewLabel_1_1.setFont(new Font("Calibri", Font.BOLD, 17));
		lblNewLabel_1_1.setBounds(29, 121, 49, 18);
		contentPane.add(lblNewLabel_1_1);
		
		JLabel lblParametreleriAyarlama = new JLabel("Yeni Alıştırma Ekle");
		lblParametreleriAyarlama.setHorizontalAlignment(SwingConstants.CENTER);
		lblParametreleriAyarlama.setFont(new Font("Calibri", Font.BOLD, 55));
		lblParametreleriAyarlama.setBounds(-45, 23, 687, 84);
		contentPane.add(lblParametreleriAyarlama);
		
		JButton submitButton = new JButton("Ekle");
		submitButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				
				fileOperations fileOps = new fileOperations();
				int A = Integer.parseInt(textA.getText());
				int B = Integer.parseInt(textB.getText());
				int N = Integer.parseInt(textN.getText());
				
				//KULLANICININ GİRDİĞİ A,B VE N DEĞERLERİNİ ALIYORUM
				
				try {
					// A,B VE N DEĞERLERİNİ DEĞİŞTİRİYORUM
				
					fileOps.changeParameters(A, B, N);
					final JPanel panel = new JPanel();
                    JOptionPane.showMessageDialog(panel, "Alıştırma Başarılı Bir Şekilde Eklendi", "Warning",JOptionPane.WARNING_MESSAGE);
					// ESKİ OYUNLARIN DETAYLARINI SİLİYORUM , SKORLARI TUTUYORUM
				//	fileOps.resetResults();
					//----------
				} catch (IOException e1) {
					e1.printStackTrace();
				}
				dispose();
				EventQueue.invokeLater(new Runnable() {
        			public void run() {
        				try {
        					// TEKRARDAN ÖNCEKİ MENÜYE DÖNÜŞ İŞLEMİNİ YAPIYORUM
        					parentPanel frame = new parentPanel(parent);
        					frame.setVisible(true);
        				} catch (Exception e) {
        					e.printStackTrace();
        				}
        			}
        		});
			}
		});
		submitButton.setFont(new Font("Calibri", Font.BOLD, 22));
		submitButton.setBounds(63, 198, 195, 59);
		contentPane.add(submitButton);
		
		JButton btnGeriDn = new JButton("Geri Dön");
		btnGeriDn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
        			public void run() {
        				try {
        					// ÖNCEKİ MENÜYE DÖNÜŞ İŞLEMİNİ YAPIYORUM
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
		btnGeriDn.setFont(new Font("Calibri", Font.BOLD, 22));
		btnGeriDn.setBounds(375, 198, 195, 59);
		contentPane.add(btnGeriDn);
		
		
		
		
	}
}
