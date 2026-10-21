package NYO_proje_19011076;

import java.awt.*;
import NYO_proje_19011076.GenerateEquation;
import java.awt.event.*;
import java.io.File;
import java.util.*;
import javax.swing.*;

public class menu implements ActionListener{
	private JFrame frame = new JFrame();
	private JLabel label_1 = new JLabel("Ana Menu");
	private JLabel label_2 = new JLabel("yeni oyun:");
	private JLabel label_3 = new JLabel("Devam et:");
	private JLabel label_4 = new JLabel("Test:");
	private JLabel label_5 = new JLabel("istatistikler:");
	private JTextField textField_1 = new JTextField();
	private JButton btn1 = new JButton();
	private JButton btn2 = new JButton();
	private JButton btn3 = new JButton();
	private JButton btn4 = new JButton();
	ArrayList<Ifade> ifadeler = new ArrayList<Ifade>();
	String equation;
	
	public menu() {
		frame.setTitle("Nerdle Oyunu");
		
		label_1.setBounds(170, 5, 75, 20);
		label_2.setBounds(90, 70, 100, 20);
		label_3.setBounds(90, 130, 100, 20);
		label_4.setBounds(90, 190, 100, 20);
		label_5.setBounds(90, 250, 100, 20);
		
		btn1.setBounds(170, 70, 50, 20);
		btn2.setBounds(170, 130, 50, 20);
		btn3.setBounds(170, 190, 50, 20);
		btn4.setBounds(170, 250, 50, 20);
		btn1.addActionListener(this);
		btn2.addActionListener(this);
		btn3.addActionListener(this);
		btn4.addActionListener(this);
		
		frame.add(label_1);
		frame.add(label_2);
		frame.add(label_3);
		frame.add(label_4);
		frame.add(label_5);
		frame.add(btn1);
		frame.add(btn2);
		File f = new File("oyun_kayit.dat");
		if(!f.exists()) {
			btn2.setEnabled(false);
		}
		f = new File("istatistik.txt");
		frame.add(btn3);
		if(!f.exists()) {
			btn3.setEnabled(false);
			istatistik var = new istatistik("0", "0", "0", "0", "0", "0");
			var.write();
		}
		
		
		frame.add(btn4);
		frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
		frame.setSize(400, 400);
		frame.setLayout(null);
		frame.setVisible(true);
		
	}
	
	
	public static void main(String[] args) {
		menu arayuz = new menu();
	}
	
	


	@SuppressWarnings("static-access")
	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource()==btn1) {
	        int j=GenerateEquation.randomGenerator.nextInt(2)+1;
	        equation = GenerateEquation.createEquation(j);
	        for(int i=0;i<6;i++) {
				Ifade obje = new Ifade(equation);
				ifadeler.add(obje);
			}
	        frame.dispose();
			oyun oyn1 = new oyun(ifadeler);
		}
		
		if(e.getSource()==btn2) {
			IfadeYazdir objeler = new IfadeYazdir(ifadeler);
			
			objeler.oku();
			//frame.dispose();
			
			currentRowKayit var = new currentRowKayit();
			objeler.getIfadeler().get(0).setCurrentRow(var.oku());
			saniyeKaydet var2 = new saniyeKaydet();
			
			System.out.println("menudeki currentrow:"+objeler.getIfadeler().get(0).getCurrentRow());
			
			oyun oyn1 = new oyun(objeler.getIfadeler());
			oyn1.guncelle(objeler.getIfadeler(), var.oku()-1);
			oyn1.setSaniyeKayit(var2.oku());
			
			File f = new File("oyun_kayit.dat");
			f.delete();
			
		}
		
		if(e.getSource()==btn3) {
			int j=GenerateEquation.randomGenerator.nextInt(2)+1;
	        equation = GenerateEquation.createEquation(j);
	        QDialog dialog = new QDialog(equation, "tekrar uret");
		}
		
		if(e.getSource()==btn4) {
			show_statics var = new show_statics();
		}
	}

}
