package NYO_proje_19011076;

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

import javax.swing.*;

public class show_statics {
	private JFrame anaFrame = new JFrame();
	private JLabel label_1 = new JLabel("basarili:");
	private JLabel label_2 = new JLabel("basarisiz:");
	private JLabel label_3 = new JLabel("yarida kalan:");
	private JLabel label_4 = new JLabel("ortalama satir:");
	private JLabel label_5 = new JLabel("ortalama süre:");
	
	private JLabel label_6 = new JLabel("");
	private JLabel label_7 = new JLabel("");
	private JLabel label_8 = new JLabel("");
	private JLabel label_9 = new JLabel("");
	private JLabel label_10 = new JLabel("");
	long secondsDisplay;// % 60;
	long elapsedMinutes;// / 60;
	
	public show_statics() {
		anaFrame.setLayout(null);
		
		istatistik var = new istatistik();
		var.read();
		
		label_6.setText(var.getBasarili());
		label_7.setText(var.getBasarisiz());
		label_8.setText(var.getYaridaKalan());
		secondsDisplay = (Integer.parseInt(var.getZaman()) / Integer.parseInt(var.getBasarili()))%60;
		elapsedMinutes = (Integer.parseInt(var.getZaman()) / Integer.parseInt(var.getBasarili()))/60;
		label_10.setText(elapsedMinutes + ":" + secondsDisplay);
		label_9.setText(Integer.parseInt(var.getOrtSatir()) / Integer.parseInt(var.getBasarili()) + "");
		
		label_1.setBounds(90, 70, 100, 20);
		label_2.setBounds(90, 130, 100, 20);
		label_3.setBounds(90, 190, 100, 20);
		label_4.setBounds(90, 250, 100, 20);
		label_5.setBounds(90, 310, 100, 20);
		
		label_6.setBounds(170, 70, 50, 20);
		label_7.setBounds(170, 130, 50, 20);
		label_8.setBounds(170, 190, 50, 20);
		label_9.setBounds(170, 250, 50, 20);
		label_10.setBounds(170, 310, 50, 20);
		
		
		anaFrame.add(label_1);
		anaFrame.add(label_6);
		anaFrame.add(label_2);
		anaFrame.add(label_7);
		anaFrame.add(label_3);
		anaFrame.add(label_8);
		anaFrame.add(label_4);
		anaFrame.add(label_9);
		anaFrame.add(label_5);
		anaFrame.add(label_10);
		
		anaFrame.addWindowListener((WindowListener) new WindowAdapter() {
	         public void windowClosing(WindowEvent windowEvent){
	        	anaFrame.dispose();
	         }        
	    }); 
		anaFrame.setSize(400, 400);
		anaFrame.setVisible(true);
	}
	
	
	public static void main(String[] args) {
		show_statics var = new show_statics();

	}

}
