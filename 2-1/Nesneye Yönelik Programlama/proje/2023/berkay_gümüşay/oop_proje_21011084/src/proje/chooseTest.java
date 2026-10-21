package Proje;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JLabel;
import java.awt.Font;
import java.io.IOException;

import javax.swing.SwingConstants;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class chooseTest extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
/*	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					chooseTest frame = new chooseTest();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}*/

	/**
	 * Create the frame.
	 */
	public chooseTest(User user,String name,String surname,int parameter) {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 518, 550);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		fileOperations fileOps = new fileOperations();
		String[][] allExercises;
		
		
		
		try {
			allExercises = fileOps.getAllExercises();
			int j = 146;
			for(String[] params : allExercises) {
				JButton btnNewButton = new JButton("A: "+params[0]+"  B: "+params[1]+"  N: "+params[2]);
				btnNewButton.setBounds(177, j, 134, 47);
				contentPane.add(btnNewButton);
				btnNewButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						EventQueue.invokeLater(new Runnable() {
							public void run() {
								try {
									// HER ÇOCUĞUN BİLGİLERİNİ AÇMAK İÇİN KENDİ İSİM, SOYİSMİNDE BİR BUTON OLUŞTURMA
									if(parameter == 0) {
										childInfo frame = new childInfo(user,name,surname,params[0],params[1],params[2]);
										frame.setVisible(true);
									}
									else if(parameter == 1 || parameter == 7) {
										HighScorePanel frame = new HighScorePanel(user,params[0],params[1],params[2]);
										frame.setVisible(true);
									}
									else if(parameter == 2) {
										childPanel frame = new childPanel(user,params[0],params[1],params[2]);
										frame.setVisible(true);
									}
								} catch (Exception e) {
									e.printStackTrace();
								}
							}
						});
						dispose();
					}
				});
				j += 70;
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(201, 11, 10, 10);
		contentPane.add(panel);
		JLabel lblAltrmaSe = new JLabel("Alıştırma Seç");
		lblAltrmaSe.setHorizontalAlignment(SwingConstants.CENTER);
		lblAltrmaSe.setFont(new Font("Calibri", Font.BOLD, 55));
		lblAltrmaSe.setBounds(0, 11, 502, 84);
		contentPane.add(lblAltrmaSe);
		
		JButton btnGeriDn = new JButton("Geri Dön");
		btnGeriDn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
                    public void run() {
                        try {
                        	// ÖNCEKİ MENÜYE DÖNME İŞLEMİ
                        	if (parameter == 0) {
                        		showChild frame = new showChild(user);
                        		frame.setVisible(true);
                        	}
                        	else if (parameter == 1) {
                        		childMenu frame = new childMenu(user);
                        		frame.setVisible(true);
                        	}
                        	else if (parameter == 7) {
                        		parentPanel frame = new parentPanel(user);
                        		frame.setVisible(true);
                        	}
                        	else if (parameter == 2) {
                        		childMenu frame = new childMenu(user);
                        		frame.setVisible(true);
                        	}
                        	
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                });
				dispose();
			}
		});
		btnGeriDn.setFont(new Font("Calibri", Font.BOLD, 16));
		btnGeriDn.setBounds(330, 451, 162, 49);
		contentPane.add(btnGeriDn);
	}
}
