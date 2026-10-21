package com.taskagitmakas.form;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferByte;
import java.util.Random;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.BevelBorder;
import org.opencv.core.Mat;
import org.opencv.core.Size;
import org.opencv.highgui.Highgui;
import org.opencv.imgproc.Imgproc;

import com.taskagitmakas.hog.CamRecorder;
import com.taskagitmakas.hog.Hog;
import com.taskagitmakas.hog.KNN;
public class GameForm {


	public JFrame frmTaKatMakas;
	private  ImageIcon image,computerImage,userImage;
	private  JLabel imageLabel = new JLabel("image");
	private JLabel computerImageLabel = new JLabel("");
	
	public JLabel lblCurrentGameCount;
	public JLabel lblUserscore;
	public JLabel lblComputerscore;
 	private Boolean SizeCustom;
	private int Height, Width;
	private  BufferedImage imageFromCam;
	static CamRecorder vcam;
	private  Mat frameFromCam;
	public  KNN knn;
	public  Hog hog;
	public int status = 0;
	public boolean startCamLoop=true;
	public Thread camThread;
	public int userScore,computerScore;
	public int gameCount=0;
	/**
	 * Launch the application.
	 */
/*	public static void main(String[] args) {
 
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GameForm window = new GameForm();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});

		
		 
	}*/

	/**
	 * Create the application.
	 */
	public GameForm() {
		vcam = new CamRecorder();

		initialize();

	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmTaKatMakas = new JFrame();
		frmTaKatMakas.setTitle("TAŞ KAĞIT MAKAS OYUNU");
		frmTaKatMakas.addWindowListener(new WindowAdapter() {
			@Override
			public void windowOpened(WindowEvent arg0) {
			 
				userScore=0;
				computerScore=0;
				knn=new KNN();
				hog=new Hog();
				
				
				
				camThread=new Thread(new Runnable() {
				      public void run() {				
						while(startCamLoop){
							while (status==0) {
								frameFromCam= vcam.startRecord();
								 imageFromCam=toBufferedImage(frameFromCam);
								
								if (imageFromCam != null) {
									image.setImage(imageFromCam);
									imageLabel.setIcon(image);
									imageLabel.updateUI();
								}
								 
								
									System.out.println("calibrasyon");
								
							}
							 
				
							while (status==1) {
								frameFromCam= vcam.train();
								 imageFromCam=toBufferedImage(frameFromCam);
								if (imageFromCam != null) {
									image.setImage(imageFromCam);
									imageLabel.setIcon(image);
									imageLabel.updateUI();
								}
				
							}
							System.out.println("filter");

							 
						}
						System.out.println("loop");

					 
				      }
				    });
					System.out.println("cıktı");

				 camThread.start();
			
				
			}
			@Override
			public void windowClosed(WindowEvent e) {
				
				
				
				System.out.println("Kapatılıyor");
				status=2;
				startCamLoop=false;
				vcam.closeCam();
				LoginForm.selectForm.getFrame().setVisible(true);
				
				
			}
		});
	 

		frmTaKatMakas.setBounds(100, 100, 1010, 787);
		frmTaKatMakas.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		frmTaKatMakas.getContentPane().setLayout(null);

		JPanel userScreen = new JPanel();
		userScreen.setBounds(12, 48, 640, 480);
		userScreen.setToolTipText("");
		userScreen.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		userScreen.setLayout(null);
		frmTaKatMakas.getContentPane().add(userScreen);

		JPanel computerScreen = new JPanel();
		computerScreen.setBounds(664, 48, 330, 480);
		computerScreen.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		frmTaKatMakas.getContentPane().add(computerScreen);
		computerScreen.setLayout(null);
		
		computerImageLabel.setBounds(0, 0, 330, 480);
		computerScreen.add(computerImageLabel);

		image = new ImageIcon();
		Height = userScreen.getHeight();
		Width = userScreen.getWidth();

		computerImage = new ImageIcon();
		Height = computerScreen.getHeight();
		Width = computerScreen.getWidth();
		
		userImage = new ImageIcon();
		Height = 100;
		Width = 100;
		
		
		imageLabel.setBounds(0, 0, 640, 480);
		imageLabel.setText("");
		userScreen.add(imageLabel);
		
		JPanel panel = new JPanel();
		panel.setBounds(22, 540, 960, 188);
		frmTaKatMakas.getContentPane().add(panel);
		panel.setLayout(null);
		
		JLabel lblUserscoreLabel = new JLabel("Skor :");
		lblUserscoreLabel.setBounds(180, 35, 49, 15);
		panel.add(lblUserscoreLabel);
		
		lblUserscore = new JLabel("0");
		lblUserscore.setBounds(264, 35, 8, 15);
		panel.add(lblUserscore);
		
		JButton btnNewButton = new JButton("Oyna");
		
		btnNewButton.setBounds(449, 30, 117, 25);
		panel.add(btnNewButton);
		
		JLabel lblComputerScoreLabel = new JLabel("Skor :");
		lblComputerScoreLabel.setBounds(748, 35, 49, 15);
		panel.add(lblComputerScoreLabel);
		
		lblComputerscore=new JLabel("0");
		lblComputerscore.setBounds(802, 35, 8, 15);
		panel.add(lblComputerscore);
		
		JButton btnKalibreEt = new JButton("Kalibre Et");
		btnKalibreEt.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				status = 1;
			 
				 
			}
		});
		btnKalibreEt.setBounds(449, 82, 117, 25);
		panel.add(btnKalibreEt);
		
		JButton btnSfrla = new JButton("Sıfırla");
		btnSfrla.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				
				status = 0;
				
			}
		});
		btnSfrla.setBounds(449, 119, 117, 25);
		panel.add(btnSfrla);
		
		JButton btnYeniOyun = new JButton("Yeni Oyun");
		btnYeniOyun.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				
			resetGame();
				
				
			}
		});
		btnYeniOyun.setBounds(155, 119, 117, 25);
		panel.add(btnYeniOyun);
		
		JLabel lblUserClass = new JLabel(".");
		lblUserClass.setBounds(22, 76, 100, 100);
		panel.add(lblUserClass);
		
		JLabel lblUserGameStatus = new JLabel("..");
		lblUserGameStatus.setBounds(244, 12, 120, 15);
		panel.add(lblUserGameStatus);
		
		JLabel lblComputerGameStatus = new JLabel("..");
		lblComputerGameStatus.setBounds(758, 8, 120, 15);
		panel.add(lblComputerGameStatus);
		
		lblCurrentGameCount = new JLabel("10/1");
		lblCurrentGameCount.setBounds(0, 35, 70, 15);
		panel.add(lblCurrentGameCount);
		
		JLabel lblUser = new JLabel("KULLANICI");
		lblUser.setBounds(269, 21, 97, 15);
		frmTaKatMakas.getContentPane().add(lblUser);
		
		JLabel lblComputer = new JLabel("BİLGİSAYAR");
		lblComputer.setBounds(779, 21, 105, 15);
		
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				if(gameCount<10){
				
						Random rand = new Random();
						int  computerClass = ((rand.nextInt(53) + 1)%3)+1;
						int userClass=1;
					 	userClass=Integer.parseInt(knn.testFromDescription(hog.getDescriptionFromMat(vcam.saveImage())).replace(" ",""));
		 				
						Mat shape=new Mat();
						shape=Highgui.imread("assets/"+computerClass+".png");
						System.out.println("assets/"+computerClass+".png"+" "+shape.size());
						
						BufferedImage imageFromRandom=toBufferedImage(shape);
						computerImage.setImage(imageFromRandom);
						computerImageLabel.setIcon(computerImage);
						computerImageLabel.updateUI();
						
						 
						//1-tas
						//2-kagıt
						//3-makas
						
						if(userClass==1 && computerClass==3){
							
							userScore++;
							lblComputerGameStatus.setText("Kaybetti...");
							lblUserGameStatus.setText("Kazandı...");					 
		
						}else if(userClass==2 && computerClass==1){
							
							userScore++;
							lblComputerGameStatus.setText("Kaybetti...");
							lblUserGameStatus.setText("Kazandı...");
						}else if(userClass==3 && computerClass==2){
							
							userScore++;
							lblComputerGameStatus.setText("Kaybetti...");
							lblUserGameStatus.setText("Kazandı...");
		
						}else if(userClass==computerClass){
							
							lblComputerGameStatus.setText("Berabere...");
							lblUserGameStatus.setText("Berabere...");
							
							
						}else {
							
							lblComputerGameStatus.setText("Kazandı...");
							lblUserGameStatus.setText("Kaybetti...");
		
							computerScore++; 
							
						}
					 
						lblUserscore.setText(Integer.toString(userScore));
						lblComputerscore.setText(Integer.toString(computerScore));
						
						Mat userShape=new Mat();
					
						if(userClass==1){
							
							userShape=Highgui.imread("assets/1.png");
							Imgproc.resize(userShape, userShape, new Size(100, 100));

							BufferedImage imageFromUser=toBufferedImage(userShape);
							userImage.setImage(imageFromUser);
							lblUserClass.setIcon(userImage);
							lblUserClass.updateUI();
						 
							
						}else if(userClass==2){
							
							userShape=Highgui.imread("assets/2.png");	
							Imgproc.resize(userShape, userShape, new Size(100, 100));
							BufferedImage imageFromUser=toBufferedImage(userShape);
							userImage.setImage(imageFromUser);
							lblUserClass.setIcon(userImage);
							lblUserClass.updateUI();		
						}else {
							
							userShape=Highgui.imread("assets/3.png");	
							Imgproc.resize(userShape, userShape, new Size(100, 100));
							BufferedImage imageFromUser=toBufferedImage(userShape);
							userImage.setImage(imageFromUser);
							lblUserClass.setIcon(userImage);
							lblUserClass.updateUI();
		
						}
		

						gameCount++;
						lblCurrentGameCount.setText("10/"+gameCount);
				}else {
					
					if(userScore>computerScore){
						
						JOptionPane.showMessageDialog(new JFrame(), LoginForm.selectedUser.getName()+" "+LoginForm.selectedUser.getSurname()+" Kazandı.");

						
					}else if(userScore==computerScore){
						
						JOptionPane.showMessageDialog(new JFrame(),"Berabere Bitti.");

						
					}
					
					else {
						
						JOptionPane.showMessageDialog(new JFrame()," Bilgisayar Kazandı.");

						
					}

						resetGame();
						
						
						
					}
				
						
				
			}
			
		});
		
		
		frmTaKatMakas.getContentPane().add(lblComputer);
		frmTaKatMakas.setVisible(true);
	}

	public void showImage(Mat img) {
		if (SizeCustom) {
			// Imgproc.resize(img, img, new Size(Height, Width));
		}
		// Highgui.imencode(".jpg", img, matOfByte);
		// byte[] byteArray = matOfByte.toArray();
		BufferedImage bufImage = null;
		try {
			// InputStream in = new ByteArrayInputStream(byteArray);
			// bufImage = ImageIO.read(in);
			bufImage = toBufferedImage(img);

			image.setImage(bufImage);
			imageLabel.setIcon(image);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	// CREDITS TO DANIEL: http://danielbaggio.blogspot.com.br/ for the improved
	// version !

	public BufferedImage toBufferedImage(Mat m) {
		int type = BufferedImage.TYPE_BYTE_GRAY;
		if (m.channels() > 1) {
			type = BufferedImage.TYPE_3BYTE_BGR;
		}

 		int bufferSize = m.channels() * m.cols() * m.rows();
		byte[] b = new byte[bufferSize];
		m.get(0, 0, b); // get all the pixels
		BufferedImage image = new BufferedImage(m.cols(), m.rows(), type);
		final byte[] targetPixels = ((DataBufferByte) image.getRaster().getDataBuffer()).getData();

		System.arraycopy(b, 0, targetPixels, 0, b.length);

		return image;

	}
	
	public void resetGame(){
		gameCount=0;
		userScore=0;
		computerScore=0;
		lblUserscore.setText("0");
		lblComputerscore.setText("0");
		lblCurrentGameCount.setText("10/1");
	}
}
