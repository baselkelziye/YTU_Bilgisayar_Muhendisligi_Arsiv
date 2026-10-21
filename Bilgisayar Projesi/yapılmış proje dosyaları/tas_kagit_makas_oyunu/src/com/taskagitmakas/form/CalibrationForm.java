package com.taskagitmakas.form;

import java.awt.EventQueue;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JSplitPane;
import java.awt.GridBagLayout;
import javax.swing.JPanel;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferByte;
import javax.swing.JLabel;
import javax.swing.JSpinner;
import javax.swing.SpinnerNumberModel;
import javax.swing.SwingUtilities;
import javax.swing.border.BevelBorder;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.JMenuBar;
import org.opencv.core.Core;
import org.opencv.core.Mat;

import com.taskagitmakas.hog.CamRecorder;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeEvent;
import javax.swing.JButton;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class CalibrationForm {

	public JFrame frmEitim;
	private static ImageIcon image;
	private static JLabel imageLabel = new JLabel("image");
	private Boolean SizeCustom;
	private int Height, Width;
	private static BufferedImage imageFromCam;
	static CamRecorder vcam;
	static boolean isKeyPress = true;
	private static Mat frameFromCam;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
 
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CalibrationForm window = new CalibrationForm();
					window.frmEitim.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});

		vcam = new CamRecorder();

		while (isKeyPress) {
			frameFromCam= vcam.startRecord();
			 imageFromCam=toBufferedImage(frameFromCam);
			
			
			if (imageFromCam != null) {
				image.setImage(imageFromCam);
				imageLabel.setIcon(image);
				imageLabel.updateUI();
			}

		}
		 

		while (true) {
			frameFromCam= vcam.train();
			 imageFromCam=toBufferedImage(frameFromCam);
			if (imageFromCam != null) {
				image.setImage(imageFromCam);
				imageLabel.setIcon(image);
				imageLabel.updateUI();
			}

		}
		 
	}

	/**
	 * Create the application.
	 */
	public CalibrationForm() {

		initialize();

	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmEitim = new JFrame();
		frmEitim.setTitle("KALİBRASYON");

		frmEitim.setBounds(100, 100, 900, 650);
		frmEitim.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
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
		GridBagLayout gbl_panel_1 = new GridBagLayout();
		gbl_panel_1.columnWidths = new int[] { 78, 0, 0 };
		gbl_panel_1.rowHeights = new int[] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		gbl_panel_1.columnWeights = new double[] { 0.0, 0.0, Double.MIN_VALUE };
		gbl_panel_1.rowWeights = new double[] { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE };
		panel_1.setLayout(gbl_panel_1);
 
		JButton btnFiltrele = new JButton("Kalibre Et");
		btnFiltrele.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				
				isKeyPress = false;
			}
		});
	 
		GridBagConstraints gbc_btnFiltrele = new GridBagConstraints();
		gbc_btnFiltrele.insets = new Insets(0, 0, 5, 5);
		gbc_btnFiltrele.gridx = 0;
		gbc_btnFiltrele.gridy = 8;
		panel_1.add(btnFiltrele, gbc_btnFiltrele);

		JMenuBar menuBar = new JMenuBar();
		frmEitim.setJMenuBar(menuBar);

		image = new ImageIcon();
		Height = panel.getHeight();
		Width = panel.getWidth();

		imageLabel.setBounds(12, 0, 666, 591);
		imageLabel.setText("");

		panel.add(imageLabel);
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

}
