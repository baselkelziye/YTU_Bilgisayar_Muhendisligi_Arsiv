package com.taskagitmakas.hog;

/*
 * Author: ATUL
 * Thanks to Daniel Baggio , Jan Monterrubio and sutr90 for improvements
 * This code can be used as an alternative to imshow of OpenCV for JAVA-OpenCv 
 * Make sure OpenCV Java is in your Build Path
 * Usage :
 * -------
 * Imshow ims = new Imshow("Title");
 * ims.showImage(Mat image);
 * Check Example for usage with Webcam Live Video Feed
 */

import java.awt.Dimension;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferByte;

//import java.io.ByteArrayInputStream;
//import java.io.InputStream;
//import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
//import javax.swing.plaf.ButtonUI;
import javax.swing.WindowConstants;

import org.opencv.core.Mat;
import org.opencv.core.Size;
import org.opencv.imgproc.Imgproc;

public class Imshow {

	public JFrame Window;
	private ImageIcon image;
	private JLabel label;
	// private MatOfByte matOfByte;
	private Boolean SizeCustom;
	private int Height, Width;

	public Imshow(String title) {
		Window = new JFrame();
		image = new ImageIcon();
		label = new JLabel();
		// matOfByte = new MatOfByte();
		label.setIcon(image);
		Window.getContentPane().add(label);
		Window.setResizable(false);
		Window.setTitle(title);
		SizeCustom = false;
		setCloseOption(0);
	}

	public Imshow(String title, int height, int width) {
		SizeCustom = true;
		Height = height;
		Width = width;

		Window = new JFrame();
		image = new ImageIcon();
		label = new JLabel();
		// matOfByte = new MatOfByte();
		label.setIcon(image);
		Window.getContentPane().add(label);
		Window.setResizable(false);
		Window.setTitle(title);
		setCloseOption(0);

	}

	public void showImage(Mat img) {
		if (SizeCustom) {
			Imgproc.resize(img, img, new Size(Height, Width));
		}
		// Highgui.imencode(".jpg", img, matOfByte);
		// byte[] byteArray = matOfByte.toArray();
		BufferedImage bufImage = null;
		try {
			// InputStream in = new ByteArrayInputStream(byteArray);
			// bufImage = ImageIO.read(in);
			bufImage = toBufferedImage(img);
			image.setImage(bufImage);
			Window.pack();
			label.updateUI();
			Window.setVisible(true);
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
		final byte[] targetPixels = ((DataBufferByte) image.getRaster()
				.getDataBuffer()).getData();
		System.arraycopy(b, 0, targetPixels, 0, b.length);
		return image;

	}

	// Thanks to sutr90 for reporting the issue : https://github.com/sutr90

	public void setCloseOption(int option) {

		switch (option) {
		case 0:
			Window.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
			break;
		case 1:
			Window.setDefaultCloseOperation(WindowConstants.HIDE_ON_CLOSE);
			break;
		default:
			Window.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		}

	}

	/**
	 * Sets whether this window should be resizable or not, by default it is not
	 * resizable
	 * 
	 * @param resizable
	 *            <code>true</code> if the window should be resizable,
	 *            <code>false</code> otherwise
	 */
	public void setResizable(boolean resizable) {
		Window.setResizable(resizable);
	}


	// Thanks to Jan Monterrubio for additional static methods for viewing images. 


	/**
	 * Displays the given {@link Mat} in a new instance of {@link Imshow}
	 * 
	 * @param mat
	 *            the {@link Mat} to display
	 */
	public static void show(Mat mat) {
		show(mat, new Dimension(mat.rows(), mat.cols()), "", false,
				WindowConstants.EXIT_ON_CLOSE);
	}

	/**
	 * Displays the given {@link Mat} in a new instance of {@link Imshow} with
	 * the given title as the title for the window
	 * 
	 * @param mat
	 *            the {@link Mat} to display
	 * @param frameTitle
	 *            the title for the frame
	 */
	public static void show(Mat mat, String frameTitle) {
		show(mat, new Dimension(mat.rows(), mat.cols()), frameTitle, false,
				WindowConstants.EXIT_ON_CLOSE);
	}

	/**
	 * Displays the given {@link Mat} in a new instance of {@link Imshow} with
	 * the given title as the title for the window and determines whether the
	 * frame is resizable or not
	 * 
	 * @param mat
	 *            the {@link Mat} to display
	 * @param frameTitle
	 *            the title for the frame
	 * @param resizable
	 *            whether the frame should be resizable or not
	 */
	public static void show(Mat mat, String frameTitle, boolean resizable) {
		show(mat, new Dimension(mat.rows(), mat.cols()), frameTitle, resizable,
				WindowConstants.EXIT_ON_CLOSE);
	}

	/**
	 * Displays the given {@link Mat} in a new instance of {@link Imshow} with a
	 * set size
	 * 
	 * @param mat
	 *            the {@link Mat} to display
	 * @param frameSize
	 *            the size for the frame
	 */
	public static void show(Mat mat, Dimension frameSize) {
		show(mat, frameSize, "", false, WindowConstants.EXIT_ON_CLOSE);
	}

	/**
	 * Displays the given {@link Mat} in a new instance of {@link Imshow} with a
	 * set size and given title
	 * 
	 * @param mat
	 *            the {@link Mat} to display
	 * @param frameSize
	 *            the size for the frame
	 * @param frameTitle
	 *            the title for the frame
	 */
	public static void show(Mat mat, Dimension frameSize, String frameTitle) {
		show(mat, frameSize, frameTitle, false, WindowConstants.EXIT_ON_CLOSE);
	}

	/**
	 * Displays the given {@link Mat} in a new instance of {@link Imshow} with a
	 * set size and given title and whether it is resizable or not
	 * 
	 * @param mat
	 *            the {@link Mat} to display
	 * @param frameSize
	 *            the size for the frame
	 * @param frameTitle
	 *            the title for the frame
	 */
	public static void show(Mat mat, Dimension frameSize, String frameTitle,
			boolean resizable) {
		show(mat, frameSize, frameTitle, resizable,
				WindowConstants.EXIT_ON_CLOSE);
	}

	/**
	 * Displays the given {@link Mat} in a new instance of {@link Imshow} with a
	 * set size and given title and whether it is resizable or not, and with the
	 * close operation set
	 * 
	 * @param mat
	 *            the {@link Mat} to display
	 * @param frameSize
	 *            the size for the frame
	 * @param frameTitle
	 *            the title for the frame
	 * @param resizable
	 *            wether the frame is resizable or not
	 * @param closeOperation
	 *            the constant for the default close operation of the frame
	 */
	public static void show(Mat mat, Dimension frameSize, String frameTitle,
			boolean resizable, int closeOperation) {
		Imshow frame = new Imshow(frameTitle, frameSize.height, frameSize.width);
		frame.setResizable(resizable);

		/*
		 * This is a bad way to access the window, but due to legacy stuff I
		 * won't change the access patterns
		 */
		frame.Window.setDefaultCloseOperation(closeOperation);
		frame.showImage(mat);
	}

}
