package com.taskagitmakas.form;

import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferByte;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import javax.swing.border.BevelBorder;
import org.opencv.core.Mat;

import com.taskagitmakas.dao.ImageDao;
import com.taskagitmakas.dao.ImageImp;
import com.taskagitmakas.hog.CamRecorder;
import com.taskagitmakas.hog.Hog;
import javax.swing.JRadioButton;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JCheckBox;
public class TrainForm {
 

		public JFrame frmEitim;
		private static ImageIcon image;
		private static JLabel imageLabel = new JLabel("image");
		private Boolean SizeCustom;
		private int Height, Width;
		private static BufferedImage imageFromCam;
		static CamRecorder vcam;
		private static Mat frameFromCam;
		public int status = 0;
		public boolean startCamLoop=true;
		public Thread camThread;
		public JLabel lblTascount;		
		public JLabel lblKagitcount;
		public JLabel lblMakascount;
		public ImageDao imageService; 
		JCheckBox chckbxisTest;
		/**
		 * Launch the application.
		 */
	 
		/*public static void main(String[] args) {
	 
			EventQueue.invokeLater(new Runnable() {
				public void run() {
					try {
						TrainForm window = new TrainForm();
						window.frame.setVisible(true);
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			});

			
			 
		} */

		/**
		 * Create the application.
		 */
		public TrainForm() {
			vcam = new CamRecorder();
			initialize();

		}

		/**
		 * Initialize the contents of the frame.
		 */
		private void initialize() {
			frmEitim = new JFrame();
			frmEitim.setTitle("EĞİTİM");
			frmEitim.addWindowListener(new WindowAdapter() {
				@Override
				public void windowOpened(WindowEvent arg0) {
				 
					imageService=new ImageImp();
					getSampleCountByClassType();

					
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
		 

			frmEitim.setBounds(100, 100, 900, 650);
			frmEitim.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
			frmEitim.getContentPane().setLayout(null);

			JPanel panel = new JPanel();
			panel.setBounds(0, 0, 678, 591);
			panel.setToolTipText("");
			panel.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
			panel.setLayout(null);
			frmEitim.getContentPane().add(panel);

			JPanel panel_1 = new JPanel();
			panel_1.setBounds(690, 0, 196, 591);
			panel_1.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
			frmEitim.getContentPane().add(panel_1);
			panel_1.setLayout(null);
			
			JRadioButton classTypeRadioTas = new JRadioButton("Taş");
			classTypeRadioTas.setBounds(59, 23, 50, 23);
			panel_1.add(classTypeRadioTas);
			
			JRadioButton classTypeRadioKagit = new JRadioButton("Kağıt");
			classTypeRadioKagit.setBounds(59, 51, 62, 23);
			panel_1.add(classTypeRadioKagit);
			
			JRadioButton classTypeRadioMakas = new JRadioButton("Makas");
			classTypeRadioMakas.setBounds(59, 79, 71, 23);
			panel_1.add(classTypeRadioMakas);

			JMenuBar menuBar = new JMenuBar();
			frmEitim.setJMenuBar(menuBar);

			image = new ImageIcon();
			Height = panel.getHeight();
			Width = panel.getWidth();

			imageLabel.setBounds(12, 0, 666, 591);
			imageLabel.setText("");
			panel.add(imageLabel);
			
			ButtonGroup radioButtonGroup=new ButtonGroup();
			radioButtonGroup.add(classTypeRadioTas);
			radioButtonGroup.add(classTypeRadioKagit);
			radioButtonGroup.add(classTypeRadioMakas);
			
			JButton startCalibrationButton = new JButton("Kalibrasyon Sıfırla");
			startCalibrationButton.setBounds(12, 185, 172, 25);
			startCalibrationButton.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					
					
					status = 0;
				}
			});
			
			JButton saveButton = new JButton("Kayıt Et");
			saveButton.setBounds(12, 222, 172, 25);
			saveButton.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					
					 
					Hog hog=new Hog();
					int classType = 0;
					if(classTypeRadioTas.isSelected()){
						
						classType=1;
					}
					if(classTypeRadioKagit.isSelected()){
											
						classType=2;
										}
					if(classTypeRadioMakas.isSelected()){
						
						classType=3;
					}
					
					boolean isTest=false;
					if(chckbxisTest.isSelected()){
						
						isTest=true;
					}
							
 					hog.addFromMat(vcam.saveImage(), classType,isTest);
 					getSampleCountByClassType();
					
				}
			});
			saveButton.setVisible(false);
			panel_1.add(saveButton);
			panel_1.add(startCalibrationButton);
			
			JButton isTestData = new JButton("Kalibre Et");
			isTestData.setBounds(12, 148, 172, 25);
			isTestData.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {
					
					status = 1;
					saveButton.setVisible(true);
					startCalibrationButton.setVisible(true);
				}
			});
			panel_1.add(isTestData);
			
			JLabel lblDatabaseBilgisi = new JLabel("Veritabanı Bilgisi");
			lblDatabaseBilgisi.setBounds(12, 302, 172, 15);
			panel_1.add(lblDatabaseBilgisi);
			
			JLabel lblTa = new JLabel("Taş:");
			lblTa.setBounds(12, 330, 70, 15);
			panel_1.add(lblTa);
			
			lblTascount = new JLabel("tasCount");
			lblTascount.setBounds(71, 330, 70, 15);
			panel_1.add(lblTascount);
			
			JLabel lblKagit = new JLabel("Kağıt:");
			lblKagit.setBounds(12, 357, 70, 15);
			panel_1.add(lblKagit);
			
			lblKagitcount = new JLabel("kagitCount");
			lblKagitcount.setBounds(71, 357, 70, 15);
			panel_1.add(lblKagitcount);
			
			JLabel lblMakas = new JLabel("Makas:");
			lblMakas.setBounds(12, 384, 70, 15);
			panel_1.add(lblMakas);
			
			lblMakascount = new JLabel("makasCount");
			lblMakascount.setBounds(71, 384, 71, 15);
			panel_1.add(lblMakascount);
			
			chckbxisTest = new JCheckBox("Test Olarak İşaretle");
			chckbxisTest.setBounds(8, 117, 167, 23);
			panel_1.add(chckbxisTest);
			
			
			
			startCalibrationButton.setVisible(false);
			frmEitim.setVisible(true);
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

		public static BufferedImage toBufferedImage(Mat m) {
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
		public void getSampleCountByClassType(){
			lblTascount.setText(imageService.getCountByClassType(1).toString());
			lblKagitcount.setText(imageService.getCountByClassType(2).toString());
			lblMakascount.setText(imageService.getCountByClassType(3).toString());
			
			
		}
}