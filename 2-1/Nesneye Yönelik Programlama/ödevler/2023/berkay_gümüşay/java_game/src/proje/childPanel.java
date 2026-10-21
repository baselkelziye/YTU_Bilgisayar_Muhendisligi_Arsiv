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
import javax.swing.JTextField;import javax.print.attribute.standard.JobOriginatingUserName;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.time.LocalDateTime;
import java.util.ArrayList;

public class childPanel extends JFrame {
	
	private JPanel contentPane;
	private JTextField answerField;

	/**
	 * Launch the application.
	 */
	private int seconds = 0;
    private int minutes = 0;
    private int tmpSec = 0;
    private int tmpMin = 0;
    private LocalDateTime startDate;
    private int[] params = new int[3];
	private int[] results = new int[4]; 
	private int  printValue=0,submitValue=0;
	private int right=0,wrong=0;
	public childPanel(User child, String A, String B, String N) {
		startDate = LocalDateTime.now();
		System.out.println(startDate.toString());
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 592, 521);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel_1 = new JPanel();
		panel_1.setBounds(511, 14, 10, 10);
		contentPane.add(panel_1);
		
		JPanel contentPane_1 = new JPanel();
		contentPane_1.setBounds(224, 14, 1, 1);
		contentPane_1.setLayout(null);
		contentPane_1.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.add(contentPane_1);
		
		JPanel panel = new JPanel();
		panel.setBounds(331, 11, 10, 10);
		contentPane_1.add(panel);
		
		JLabel lblWelcome = new JLabel("Hoş geldin");
		lblWelcome.setHorizontalAlignment(SwingConstants.CENTER);
		lblWelcome.setFont(new Font("Calibri", Font.BOLD, 55));
		lblWelcome.setBounds(0, 34, 687, 84);
		contentPane_1.add(lblWelcome);
		
		
		  
		
		Component verticalStrut = Box.createVerticalStrut(20);
		verticalStrut.setBounds(555, 117, 1, 20);
		contentPane_1.add(verticalStrut);
		
		Component verticalGlue = Box.createVerticalGlue();
		verticalGlue.setBounds(509, 117, 1, 1);
		contentPane_1.add(verticalGlue);
		
		JLabel lblNewLabel = new JLabel("");
		lblNewLabel.setBounds(182, 167, 46, 14);
		contentPane_1.add(lblNewLabel);
		
		JButton btnChildDifficulty = new JButton("Değer Ayarlama");
		btnChildDifficulty.setFont(new Font("Calibri", Font.BOLD, 16));
		btnChildDifficulty.setBounds(217, 178, 245, 68);
		contentPane_1.add(btnChildDifficulty);
		
		JButton btnChildGraph = new JButton("Çocuk Grafik Gösterme");
		btnChildGraph.setFont(new Font("Calibri", Font.BOLD, 16));
		btnChildGraph.setBounds(217, 293, 245, 68);
		contentPane_1.add(btnChildGraph);
		
		JButton btnBack = new JButton("Geri Dön");
		btnBack.setFont(new Font("Calibri", Font.BOLD, 16));
		btnBack.setBounds(217, 403, 245, 68);
		contentPane_1.add(btnBack);
		
		
		
        
		answerField = new JTextField();
		answerField.setBounds(109, 304, 145, 20);
		contentPane.add(answerField);
		answerField.setColumns(10);
		
		
		
		JLabel lblNewLabel_1 = new JLabel("Cevap :");
		lblNewLabel_1.setFont(new Font("Calibri", Font.BOLD, 16));
		lblNewLabel_1.setBounds(54, 304, 49, 19);
		contentPane.add(lblNewLabel_1);
		
		JLabel timerLabel = new JLabel("00:00");
		timerLabel.setFont(new Font("Calibri", Font.BOLD, 30));
		timerLabel.setHorizontalAlignment(SwingConstants.CENTER);
		timerLabel.setBounds(66, 54, 228, 57);
		contentPane.add(timerLabel);
		// TİMER'I OLUŞTURDUM
		Timer timer = new Timer(1000, new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                seconds++;
                if (seconds == 60) {
                    seconds = 0;
                    minutes++;
                }
                String time = String.format("%02d:%02d", minutes, seconds);
                timerLabel.setText(time);
            }
        });
        timer.start();
		
		// HER SORUDA ÇOCUĞUN MEVCUT DOĞRU/YANLIŞ SAYISINI EKRANA YAZDIRDIM
        JLabel rightAndWrong = new JLabel("Doğru: "+right+" | Yanlış: "+wrong);
		rightAndWrong.setHorizontalAlignment(SwingConstants.CENTER);
		rightAndWrong.setFont(new Font("Calibri", Font.BOLD, 22));
		rightAndWrong.setBounds(269, 111, 196, 182);
		fileOperations fileOps = new fileOperations();
		try {
		//	fileOps.prepareQuestions(child);
			params[0] = Integer.parseInt(A);
			params[1] = Integer.parseInt(B);
			params[2] = Integer.parseInt(N);
			ArrayList<Question> qList = fileOps.prepareQuestions(child, A, B, N);
			String answers[] = new String[qList.size()];
			int time[] = new int[qList.size()];
			results[0] = qList.size();
			JLabel questionLabel = new JLabel(qList.size()+"/1.)  "+qList.get(0).getNum1()+" x "+qList.get(0).getNum2() + " = ?");
			questionLabel.setFont(new Font("Calibri", Font.BOLD, 22));
			questionLabel.setHorizontalAlignment(SwingConstants.CENTER);
			questionLabel.setBounds(76, 111, 196, 182);
			contentPane.add(questionLabel);
			JButton submitButton = new JButton("Onayla");
			// ÇOCUK CEVABI ONAYLARSA DEVAMINDA GEREKEN İŞLEMLERİ YAPTIM
			submitButton.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					// SORULARIN BİTİP BİTMEDİĞİNİ KONTROL ETTİM 
					if((wrong+right) != qList.size()) {
						// KULLANICININ CEVABINI ALDIM
						String answerText = answerField.getText();
						if(!answerText.isBlank()) {
							answers[wrong+right] = answerText;
							int answerInt = Integer.parseInt(answerText);
							
							// CEVABIN DOĞRULUĞUNU KONTROL ETTİM
							if((qList.get(submitValue).getNum1() * qList.get(submitValue).getNum2() ) == answerInt) {
								answerField.setText("");
								//---------------------------------------------------------------------------------------------------------
								// SORU BAŞINA GEÇEN SÜREYİ TUTTUM
								time[wrong+right] = ((minutes-tmpMin)*60)+(seconds-tmpSec);
								tmpMin = minutes;
								tmpSec = seconds;
								//---------------------------------------------------------------------------------------------------------
								// DOĞRU SAYISINI ARTTIRDIM
								right++;
								results[1] = right;
								submitValue++;
								printValue++;
								if(printValue != qList.size() ) {
									questionLabel.setText( qList.size()+"/"+ (printValue+1)+".)  "+qList.get(printValue).getNum1()+" x "+qList.get(printValue).getNum2() + " = ?");
								}
								rightAndWrong.setText("Doğru: "+right+" | Yanlış: "+wrong);
								if(printValue == qList.size()) {
									// SON SORUYA GELDİYSEK CEVAPTAN SONRA OYUNU BİTİRDİM
									dispose();
									results[3] = (minutes*60) + seconds;
									System.out.println(answers[0]+" "+answers[1]+" "+answers[2]);
									// KULLANICI SKORUNU OLUŞTURDUM
									int score = (right*100) - (((minutes*60)+seconds) - 20);
									Results childResults = new Results(child, qList, results, answers, score, params, time,startDate.toString());
									EventQueue.invokeLater(new Runnable() {
										public void run() {
											try {
												// SONUÇ EKRANINI AÇTIM
												endGamePanel frame = new endGamePanel(childResults);
												frame.setVisible(true);
											} catch (Exception e) {
												e.printStackTrace();
											}
										}
									});
									
								}
							}
							else if((qList.get(submitValue).getNum1() * qList.get(submitValue).getNum2() ) != answerInt) {
								answerField.setText("");
								//---------------------------------------------------------------------------------------------------------
								// SORU BAŞINA GEÇEN SÜREYİ TUTTUM
								time[wrong+right] = ((minutes-tmpMin)*60)+(seconds-tmpSec);
								tmpMin = minutes;
								tmpSec = seconds;
								//---------------------------------------------------------------------------------------------------------
								// YANLIŞ SAYISINI ARTTIRDIM
								wrong++;
								results[2] = wrong;
								submitValue++;
								printValue++;
								
								
								if(printValue != qList.size() ) {
									answerField.setText("");
									questionLabel.setText( qList.size()+"/"+ (printValue+1)+".)  "+qList.get(printValue).getNum1()+" x "+qList.get(printValue).getNum2() + " = ?");
								}
								rightAndWrong.setText("Doğru: "+right+" | Yanlış: "+wrong);
								if(printValue == qList.size()) {
									// SON SORUYA GELDİYSEK CEVAPTAN SONRA OYUNU BİTİRDİM
									results[3] = (minutes*60) + seconds;
									System.out.println(answers[0]+" "+answers[1]+" "+answers[2]);
									// KULLANICI SKORUNU OLUŞTURDUM
									int score = (right*100) - (((minutes*60)+seconds) - 20);
									System.out.println("score: "+score);
									Results childResults = new Results(child, qList, results, answers, score, params, time,startDate.toString());
									dispose();
									// SONUÇ EKRANINI AÇTIM
									EventQueue.invokeLater(new Runnable() {
										public void run() {
											try {
												endGamePanel frame = new endGamePanel(childResults);
												frame.setVisible(true);
											} catch (Exception e) {
												e.printStackTrace();
											}
										}
									});
									
								}
							}
						}
							
					}
				}
			});
			
			submitButton.setFont(new Font("Calibri", Font.BOLD, 16));
			submitButton.setBounds(109, 334, 145, 42);
			contentPane.add(submitButton);
			contentPane.add(rightAndWrong);
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
	}
}
