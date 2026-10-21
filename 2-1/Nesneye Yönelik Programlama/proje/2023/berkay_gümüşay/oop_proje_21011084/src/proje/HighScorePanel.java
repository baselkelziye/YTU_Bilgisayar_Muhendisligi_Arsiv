package Proje;

import java.awt.EventQueue;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

import javax.swing.JTextArea;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.border.EmptyBorder;
import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class HighScorePanel extends JFrame {

	private JPanel contentPane;
	private JTextArea textArea;
	
	// YÜKSEK SKORLARI GÖSTEREN EKRAN
	public HighScorePanel(User parent, String A, String B, String N) {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 701, 627);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		JLabel lblChild = new JLabel("High Score List");
        lblChild.setHorizontalAlignment(SwingConstants.CENTER);
        lblChild.setFont(new Font("Calibri", Font.BOLD, 55));
        lblChild.setBounds(0, 10, 687, 84);
        contentPane.add(lblChild);
		fileOperations fileOps = new fileOperations();
		try {
			JPanel panel_1 = new JPanel();
            panel_1.setLayout(null);
       
            String[][] filteredMatris = fileOps.highScores(A,B,N);
		
			JScrollPane scrollPane = new JScrollPane(panel_1);
            scrollPane.setBounds(29, 102, 627, 286);
            contentPane.add(scrollPane);
            textArea = new JTextArea();
            textArea.setFont(new Font("Calibri", Font.BOLD, 20));
            textArea.append("\n");
            int i = 1;
            scrollPane.setViewportView(textArea);
            // YÜKSEK SKOR ALAN ÖĞRENCİLERİN İSİM, SOYİSİM, SKOR, SÜRE DEĞERLERİNİ EKRANA YAZDIRMA
            for (String[] strings : filteredMatris) {
            	textArea.append(" "+i+".) "+" İsim Soyisim: "+strings[0]+" "+strings[1]+" | Skor : "+strings[2]+" | Bitirilen Süre : "+strings[3]+" Saniye "+"\n");
            	i++;
			}
            if(i == 1) {
            	textArea.append("\n     Bu Alıştırmada Henüz Oyun Oynanmadı ");
            }
            
			textArea.setEditable(false);
			
			
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(342, 10, 1, 1);
		contentPane.add(panel);
		panel.setLayout(null);
		
		JPanel panel_1 = new JPanel();
		panel_1.setBounds(355, 10, 10, 10);
		contentPane.add(panel_1);
		panel_1.setLayout(null);
		
		JButton btnGeriDn = new JButton("Geri Dön");
		btnGeriDn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				if(parent.getUserType().equalsIgnoreCase("parent")) {
					EventQueue.invokeLater(new Runnable() {
	        			public void run() {
	        				try {
	        					// BU EKRANI EBEVEYN AÇTIYSA EBEVEYN EKRANINA GERİ DÖNME
	        			//		chooseTest frame = new chooseTest(parent, "", "", 1);
	        					parentPanel frame = new parentPanel(parent);
	        					frame.setVisible(true);
	        				} catch (Exception e) {
	        					e.printStackTrace();
	        				}
	        			}
	        		});
				}
				else {
					EventQueue.invokeLater(new Runnable() {
            			public void run() {
            				try {
            				//	System.out.println("sa");
            					// BU EKRANI ÇOCUK AÇTIYSA EBEVEYN EKRANINA GERİ DÖNME
            					childMenu frame = new childMenu(parent);
            					frame.setVisible(true);
            				} catch (Exception e) {
            					e.printStackTrace();
            				}
            			}
            		});
				}
			}
		});
		btnGeriDn.setFont(new Font("Calibri", Font.BOLD, 22));
		btnGeriDn.setBounds(480, 518, 195, 59);
		contentPane.add(btnGeriDn);
		
		
	}
}
