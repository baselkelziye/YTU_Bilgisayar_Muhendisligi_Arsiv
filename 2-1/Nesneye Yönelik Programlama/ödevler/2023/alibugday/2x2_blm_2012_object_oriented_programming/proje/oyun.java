package NYO_proje_19011076;

import java.awt.*;
import NYO_proje_19011076.GenerateEquation;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;

public class oyun implements ActionListener{
	private JFrame frame = new JFrame();
	private JPanel ustPanel = new JPanel();
	private JPanel footer = new JPanel();
	private JPanel altPanel = new JPanel();
	//private JPanel onbes_panel = new JPanel();
	private JPanel numara_panel = new JPanel();
	private JPanel button_panel = new JPanel();
	private JLabel textfield = new JLabel("buraya timer gelecek");
	private JLabel ogrNumarasi = new JLabel("19011076-Ali_Bugday");
	private JButton btn1 = new JButton("Enter");
	private JButton btn2 = new JButton("Sonra bitir");
	private JTextField userText;
	private JButton[] buttons;
	//private JButton[] onbes;
	private int rowColumn;
	ArrayList<Ifade> ifadeler;
	istatistik statics;
	private long elapsedSeconds;
    private long saniyeKayit;
	
	public oyun(ArrayList<Ifade> ifadeler) {
		
		statics = new istatistik();
		statics.read();
		this.ifadeler = ifadeler;
		this.rowColumn = ifadeler.get(1).getColumnCount();
		buttons = new JButton[rowColumn*6];
		//onbes = new JButton[15];
		userText = new JTextField(rowColumn);
		
		frame.addWindowListener((WindowListener) new WindowAdapter() {
	         public void windowClosing(WindowEvent windowEvent){
	        	statics.setYaridaKalan(Integer.parseInt(statics.getYaridaKalan())+1+""); 
	        	statics.write();
	            System.exit(0);
	         }        
	    });  
		
		frame.setSize(800,800);
		//frame.getContentPane().setBackground(new Color(50,50,50));
		frame.setLayout(new BorderLayout());
		
		footer.setLayout(new BorderLayout());
		
		textfield.setBackground(new Color(25,25,25));
		textfield.setForeground(new Color(25,255,0));
		textfield.setFont(new Font("Ink Free",Font.BOLD,25));
		textfield.setHorizontalAlignment(JLabel.RIGHT);
		textfield.setText("Buraya timer gelecek");
		textfield.setOpaque(true);
		
		ustPanel.setLayout(new BorderLayout());
		ustPanel.setBounds(0,0,800,100);
		
		//btn1.setBackground(new Color(255,0,0));
		btn1.setFont(new Font("Ink Free",Font.BOLD,25));
		btn1.setHorizontalAlignment(JLabel.CENTER);
		btn1.addActionListener(this);
		btn2.setFont(new Font("Ink Free",Font.BOLD,25));
		btn2.setHorizontalAlignment(JLabel.LEFT);
		btn2.addActionListener(this);
		userText.setHorizontalAlignment(JTextField.RIGHT);
		userText.setFont(new Font(Font.SERIF, Font.PLAIN,25));
		
		
		
		//altPanel.setBounds(0,0,800,100);
		
		button_panel.setLayout(new GridLayout(6,rowColumn));
		button_panel.setBackground(new Color(150,150,150));
		
		for(int i=0;i<rowColumn*6;i++) {
			buttons[i] = new JButton();
			button_panel.add(buttons[i]);
			buttons[i].setFont(new Font("MV Boli",Font.BOLD,120));
			buttons[i].setFocusable(false);
			//buttons[i].addActionListener(this);
		}
		
		
		altPanel.setLayout(new GridLayout(1,3));
		numara_panel.setLayout(new BorderLayout());
		numara_panel.setBounds(0,0,800,100);
		/*onbes_panel.setLayout(new GridLayout(5,3));
		String[] dizi = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "-", "*", "/", "="};
		for(int i=0;i<15;i++) {
			onbes[i] = new JButton();
			onbes_panel.add(onbes[i]);
			onbes[i].setFont(new Font("MV Boli",Font.BOLD,8));
			System.out.println(dizi[i]);
			onbes[i].setText(dizi[i]);
			onbes[i].setFocusable(false);
		}*/
		
		ogrNumarasi.setBackground(new Color(25,25,25));
		ogrNumarasi.setForeground(new Color(25,255,0));
		ogrNumarasi.setFont(new Font("Ink Free",Font.BOLD,25));
		ogrNumarasi.setHorizontalAlignment(JLabel.CENTER);
		ogrNumarasi.setOpaque(true);
		
		
		
		altPanel.add(userText);//alt panel sonra bitir ve enter tuslarýný iceren panel
		altPanel.add(btn1);
		altPanel.add(btn2);
		numara_panel.add(ogrNumarasi);//numara panel: ogrenci numarasini iceren footer 
		footer.add(altPanel, BorderLayout.NORTH);
		//footer.add(onbes_panel);
		footer.add(numara_panel, BorderLayout.SOUTH);
		ustPanel.add(textfield);
		
		frame.add(ustPanel, BorderLayout.NORTH);
		frame.add(button_panel);
		frame.add(footer, BorderLayout.SOUTH);
		frame.setVisible(true);
		
		Thread thread = new Thread()
        {
        	long startTime = System.currentTimeMillis();
            public void run()
            {
                int x = 0;
                while(true)
                {
                	long elapsedTime = System.currentTimeMillis() - startTime;
                	elapsedSeconds = elapsedTime / 1000 + saniyeKayit;
                	long secondsDisplay = elapsedSeconds % 60;
                	long elapsedMinutes = elapsedSeconds / 60;
                	textfield.setText(elapsedMinutes + ":" + secondsDisplay);
                    try { Thread.sleep(1000); }
                    catch (Exception e) { e.printStackTrace(); }
                    
                }
            }
        };
        thread.start();
		
		
	}
	

	@SuppressWarnings("static-access")
	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource()==btn1) {
			int currentrow;
			String denklem = userText.getText();
			
			if(kontrol(denklem)) {
				Ifade ifade , ifade2 = new Ifade(denklem);
				ifade = new Ifade((ifadeler.get(ifadeler.get(0).getCurrentRow()).getKelime()));//sorulan denklemi dondurup yeni bir ýfade objesi olustur.
				System.out.println("sorulan:" + ifade);
				ifadeler.set(ifadeler.get(0).getCurrentRow(), ifade2);//arraylistimize kulanýcýnýn girdigi denleklem ile olusan ifade objesini ata 
				//ifade2 = ifadeler.get(ifadeler.get(0).getCurrentRow());//gereksiz 
				System.out.println("girilen:" + ifadeler.get(ifadeler.get(0).getCurrentRow()));
				ifadeler.get(ifadeler.get(0).getCurrentRow()).compareto(ifade);
				ifade.compareto(ifadeler.get(ifadeler.get(0).getCurrentRow()));
				guncelle(ifadeler, ifadeler.get(0).getCurrentRow());
				if(ifade2.isWin()) {
					statics.setN(Integer.parseInt(statics.getN())+1+"");
					statics.setBasarili(Integer.parseInt(statics.getBasarili())+1+"");
					statics.setOrtSatir(Integer.parseInt(statics.getOrtSatir()) + ifadeler.get(0).getCurrentRow() + 1 + "");
					statics.setZaman(Integer.parseInt(statics.getZaman()) + elapsedSeconds + "");
					statics.write();
					frame.dispose();
					QDialog dialog = new QDialog("Kazandiniz!");
					//System.out.println("kazandýnýz");
				}
				else if(ifadeler.get(0).getCurrentRow()==5) {//looseing game
					statics.setBasarisiz(Integer.parseInt(statics.getBasarisiz())+1+"");
					statics.write();
					//System.out.println("oyun bitti");
					QDialog dialog = new QDialog("kaybettiniz dogru cevap:" + ifade.getKelime());
				}
				ifadeler.get(0).setCurrentRow(ifadeler.get(0).getCurrentRow()+1);
				
			}else {
				QDialog dialog = new QDialog("denklem gecersiz");
				//System.out.println("gecersiz denklem");
			}
			userText.setText("");
			
		}
		if(e.getSource()==btn2) {
			currentRowKayit var = new currentRowKayit();
			saniyeKaydet var2 = new saniyeKaydet();
			var.kayit(ifadeler.get(0).getCurrentRow());
			var2.kayit(getElapsedSeconds());
			System.out.println("currentrow:"+ifadeler.get(0).getCurrentRow());
			
			ifadeler.get(0).setCurrentRow(ifadeler.get(0).getCurrentRow());
			IfadeYazdir objeler = new IfadeYazdir(ifadeler);
			objeler.yaz(objeler);
			frame.dispose();
		}
		
	}
	
	public boolean kontrol(String equation) {
		if (equation.contains("[a-zA-Z]+")){
			   return false;
		}
		if(equation.contains("=")==false) {
			return false;
		}
		if(equation.length() < 7 || equation.length() > 9){
			return false;
		}
		String[] dizi = equation.split("=");
		System.out.println(dizi[1]);
		double gecici = Double.parseDouble(GenerateEquation.evaluate(dizi[0]));
		if(gecici != Double.parseDouble(dizi[1])) {
			return false;
		}
		
		return true;
		
	}
	
	public void guncelle(ArrayList<Ifade> ifadeler, int k) {
		Ifade ifade = ifadeler.get(0);
		int n = ifade.getColumnCount();
		int currentrow = k;
		int m;
		
		for(int i=0;i<6*rowColumn;i++) {
			if((i/ifade.getColumnCount())<=currentrow) {
				m = i/ifade.getColumnCount();
				
				ifade = ifadeler.get(m);
				String renk = ifade.getRenkler()[i%ifade.getColumnCount()];
				String deger = ifade.getHarfler()[i%ifade.getColumnCount()];

				if(renk.equals("green")) {
					buttons[i].setBackground(new Color(0,255,0));
					buttons[i].setText(deger);
				}
				else if(renk.equals("yellow")) {
					buttons[i].setBackground(new Color(255,255,0));
					buttons[i].setText(deger);
				}
				else {
					buttons[i].setBackground(new Color(128,128,128));
					buttons[i].setText(deger);
				}
				
			}
		}
		
		
	}
	
	
	
	public long getElapsedSeconds() {
		return elapsedSeconds;
	}


	public void setSaniyeKayit(long saniyeKayit) {
		this.saniyeKayit = saniyeKayit;
	}


	public static void main(String[] args) {
		ArrayList<Ifade> ifadeler = new ArrayList<Ifade>();
		for(int i=0;i<6;i++) {
			Ifade obje = new Ifade("5*5-4=21");
			ifadeler.add(obje);
		}
		
		Ifade ifade = new Ifade("5*4+3=23");
		Ifade ifade2 = new Ifade("5*5-4=21");
		
		ifadeler.set(1, ifade);
		ifadeler.get(1).compareto(ifade2);
		
		System.out.println(ifadeler.get(1));
		
		ifadeler.get(1).setCurrentRow(2);
		
		oyun oyn1 = new oyun(ifadeler);
		//oyn1.frame.dispose();
		
		oyn1.guncelle(ifadeler, ifadeler.get(0).getCurrentRow());
		
		//System.out.println(oyn1.kontrol("5*6-1=29"));
	}
}
