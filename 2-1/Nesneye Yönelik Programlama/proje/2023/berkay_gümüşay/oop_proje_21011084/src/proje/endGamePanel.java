package Proje;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.awt.Font;
import java.io.IOException;

import javax.swing.SwingConstants;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class endGamePanel extends JFrame {

	private JPanel contentPane;

	
	public endGamePanel(Results childResults) {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 704, 535);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		fileOperations fileOps = new fileOperations();
		try {
			// SONUÇ EKRANINDA KULLANICI SONUCUNU VE SKORUNU DOSYALARA EKLEDİM
			fileOps.addResultToFile(childResults);
			fileOps.addScore(childResults);
			fileOps.addHighScoresCSV(childResults);
			int params[] = fileOps.getParameters();
			fileOps.addScoreToAllScores(childResults.getScore(),params);
		} catch (IOException e) {
			e.printStackTrace();
		}
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(319, 10, 10, 10);
		contentPane.add(panel);
		//ÇOCUĞUN İSİM SOYİSMİNİ YAZDIRDIM
		JLabel lblWelcome = new JLabel(childResults.getChild().getName()+" "+childResults.getChild().getSurname());
		lblWelcome.setHorizontalAlignment(SwingConstants.CENTER);
		lblWelcome.setFont(new Font("Calibri", Font.BOLD, 55));
		lblWelcome.setBounds(0, 11, 687, 84);
		contentPane.add(lblWelcome);
		//ÇOCUĞUN DOĞRU SAYISINI YAZDIRDIM
		JLabel lblDoruSays = new JLabel("Doğru Sayısı : "+childResults.getResults()[1]);
		lblDoruSays.setHorizontalAlignment(SwingConstants.LEFT);
		lblDoruSays.setFont(new Font("Calibri", Font.BOLD, 36));
		lblDoruSays.setBounds(10, 78, 632, 84);
		contentPane.add(lblDoruSays);
		//ÇOCUĞUN YANLIŞ SAYISINI YAZDIRDIM
		JLabel lblYanlSays = new JLabel("Yanlış Sayısı : "+childResults.getResults()[2]);
		lblYanlSays.setHorizontalAlignment(SwingConstants.LEFT);
		lblYanlSays.setFont(new Font("Calibri", Font.BOLD, 36));
		lblYanlSays.setBounds(10, 140, 632, 84);
		contentPane.add(lblYanlSays);
		//ÇOCUĞUN TAMAMLAMA SÜRESİNİ YAZDIRDIM
		JLabel lblTamamlamaSresi = new JLabel("Tamamlama Süresi : "+childResults.getResults()[3]/60+" dk "+(childResults.getResults()[3]%60)+" sn");
		lblTamamlamaSresi.setHorizontalAlignment(SwingConstants.LEFT);
		lblTamamlamaSresi.setFont(new Font("Calibri", Font.BOLD, 36));
		lblTamamlamaSresi.setBounds(10, 203, 632, 84);
		contentPane.add(lblTamamlamaSresi);
		//ÇIKIŞ YAPMA İŞLEMİ
		JButton btnkYap = new JButton("Çıkış Yap");
		btnkYap.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
        		EventQueue.invokeLater(new Runnable() {
        			public void run() {
        				try {
        					childMenu frame = new childMenu(childResults.getChild());
        					frame.setVisible(true);
        				} catch (Exception e) {
        					e.printStackTrace();
        				}
        			}
        		});
			}
		});
		btnkYap.setFont(new Font("Calibri", Font.BOLD, 25));
		btnkYap.setBounds(10, 403, 216, 68);
		contentPane.add(btnkYap);
		//ÇOCUĞUN SKORUNU YAZDIRDIM
		JLabel lblSkor = new JLabel("Skor : " + childResults.getScore());
		lblSkor.setHorizontalAlignment(SwingConstants.LEFT);
		lblSkor.setFont(new Font("Calibri", Font.BOLD, 36));
		lblSkor.setBounds(10, 277, 632, 84);
		contentPane.add(lblSkor);
		
		
	}
}
