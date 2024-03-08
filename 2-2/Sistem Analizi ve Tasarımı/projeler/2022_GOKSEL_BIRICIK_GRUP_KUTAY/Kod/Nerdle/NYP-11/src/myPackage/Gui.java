package myPackage;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Timer;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JTextField;
import java.awt.image.BufferedImage;
import java.util.*;
import javax.swing.ImageIcon;
import javax.swing.JComboBox;
public class Gui extends JFrame{
	
	// Oyun ekranýmdaki JButtonlar
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 6000335185319848898L;

	private JButton[][] txtalan;
	
	//Oyundaki bulunduðum satýr bilgisini tutuyor.
	
	private int konum=0;
	
	//Tüm panellerim burada.
	
	private JPanel contentPane;
	
	//Renkleri bu dizide tutuyorum.
	
	private int[] renkDizisi;
	
	//Kazanma-Kaybetme durumunu buraya yazýyorum
	
	private JLabel ciktitxt;
	
	//Rastgele eþitlik üretecek.
	
	private EquationClass equation;
	
	//Rastgele eþitlik üretecek.
	
	private EquationClass myclass;
	
	//Ana ekrandaki test butonu
	
	private JButton testButton;
	
	//Test ekranýndaki test butonu
	
	private JButton testButton1;
	
	//Ana ekran
	
	private JPanel panel;
	
	//Foroðraf iþlemlerinde kullanýyorum
	
	private JLabel imgLabel;
	
	//Test ekraným
	
	private JPanel testPanel;
	
	//Oyun ekranýndaki buona týklanýnca aktif etmek için
	
	private int globali=0;
	
	//Oyun ekranýndaki buona týklanýnca aktif etmek için
	
	private int globalj=0;
	
	//Oyun ekranýndaki zaman bilgisini tutuyor.
	
	private JLabel timer;
	private JLabel timerText;
	private JLabel loseWinLabel;
	//Test panelindeki geri butonu.
	
	private JButton back;
	
	private int devamaBas;
	//Devam et tuþundan sonra beliren geri butonu
	
	private JButton back1;
	
	//Dosyadan okuduðum tahminler
	
	private String[] sonucDizisi;

	//Oyun ekraný
	
	private JPanel gamePanel;
	
	//Oyun sonu ekraný
	
	private JPanel loseWinPanel;
	
	//Test ekranýndaki rastgele deðerin yazýldýðý üye alan
	
	private JTextField testText;
	
	//Oyun ekranýndaki geri butonu
	
	private JButton gameBack;
	
	//Sil tuþunun düzgün çalýþmasý için
	
	private int silflag=0;
	
	//Oyun ekranýndaki kaydet butonu
	
	private JButton sonraBitirButton;
	
	//Oyun sonu ekranýndaki geri butonu
	
	private JButton winLoseButton;
	
	//Eskiden kayýtlý kalmýþ oyunun üstüne yazýlýrsa yarýda kalan oyun sayýsýný artýrýyor.
	
	private int devammiTamami;
	
	//Ýsim-Numara yazýsý
	
	private JLabel[] footers;
	private String footer = "11 - 20011622 Çaðatay Alptekin - 20011901 Muhammet Kayra Bulut";
	
	//Ýstatistik yazýlarýný tutuyor ana ekranda
	
	private JLabel[] istatistikler;
	
	//Ýstatistik bilgilerini okumak vs. için
	
	private Istatistik istatistik;
	
	//Oyun ekranýndaki yazmakla ilgili butonlar
	
	private JButton[] gameButtons = new JButton[17];
	
	private int istatistikSayisi = 6;
	
	
	
	//Zorluk yazýlarý
	
	private String[] zorluk;
	
	//Oyun ekranýndaki timer
	
	private Timer myTimer;
	
	private JComboBox<String> Zorluk;
	/**
	 * Launch the application.
	 */		
	int counter;
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Gui frame = new Gui();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	/*
	 * JComboFrame'imin yazýlarýný düzenlemek için.
	 */
	private String[] setZorluk(){
		String [] zorluk = new String[4];
		zorluk[0]="Çok kolay";
		zorluk[1]="Kolay";
		zorluk[2]="Orta";
		zorluk[3]="Zor";
		return zorluk;
	}
	public Gui() {
		timer = new JLabel();
		timerText= new JLabel();
		back1= new JButton("Geri");
		back1.setLocation(125, 265);
		back1.setSize(100, 50);
		back1.setToolTipText("Uyanýklýk yapýp, kaydetmeden geri dönmeye çalýþýrsan kayýt silinir ona göre");;
		back1.setBackground(Color.blue);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 932, 552);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		zorluk = new String[4];
		zorluk= setZorluk();
		Zorluk = new JComboBox<>(zorluk);
		Zorluk.setBounds(338, 101, 126, 78);
		contentPane.setLayout(null);
		JButton tahminButton = new JButton("Tahmin Et");
		tahminButton.setToolTipText("E\u011Fer ge\u00E7erli bir denklem girdiyseniz, yap\u0131lan kontrollere g\u00F6re ilgili sat\u0131r\u0131 boyar ve e\u011Fer varsa bir sonraki sat\u0131ra yazmak i\u00E7in imkan verir.E\u011Fer son sat\u0131rda yanl\u0131\u015F tahmin yaparsan kaybedersin, aman dikkat!!!");
		panel = new JPanel();
		panel.setBackground(Color.LIGHT_GRAY);
		panel.add(Zorluk);
		testPanel = new JPanel();
		testPanel.setBackground(Color.YELLOW);
		gamePanel = new JPanel();
		gamePanel.setBackground(Color.DARK_GRAY);
		gamePanel.setSize(916, 513);
		gamePanel.setLocation(0, 0);
		gamePanel.setVisible(false);
		testPanel.setVisible(false);
		testPanel.setToolTipText("Burasý sadece test için. Çok kurcalamaa...");
		loseWinPanel=new JPanel();
		gamePanel.setLayout(null);
		gamePanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		loseWinPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		loseWinPanel.setBounds(0,0,916,513);
		panel.setBorder(new EmptyBorder(5, 5, 5, 5));
		testPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		panel.setBounds(0, 0, 916, 513);
		timer.setBounds(800,0,100,100);
		timerText.setBounds(800, 0, 100, 60);
		timerText.setText("Süre");
		timerText.setFont(new Font("Serif", Font.PLAIN, 14));
		timerText.setForeground(Color.white);
		timer.setText("0");
		timer.setFont(new Font("Serif", Font.PLAIN, 14));
		timer.setForeground(Color.white);
		timer.setHorizontalAlignment(JTextField.CENTER);
		timerText.setHorizontalAlignment(JTextField.CENTER);
		gamePanel.add(timerText);
		contentPane.add(panel);
		contentPane.add(loseWinPanel);
		loseWinPanel.setVisible(false);
		contentPane.add(testPanel);
		contentPane.add(gamePanel);
		gamePanel.add(timer);
		loseWinLabel=new JLabel();
		loseWinPanel.add(loseWinLabel);
		loseWinLabel.setBounds(694,0,206,100);
		loseWinPanel.setLayout(null);
		winLoseButton= new JButton("Ana Sayfa");
		winLoseButton.setToolTipText("Ana ekrana d\u00F6ner.");
		loseWinPanel.add(winLoseButton);
		winLoseButton.setBounds(350, 170, 200, 100);
		panel.setLayout(null);
		int buttonArraySize=55;
		int buttonDistance=20;
		int buttonY=550;
		int buttonX=135;
		for(int i=0;i<16;i++) {
			gameButtons[i]=new JButton();
			gamePanel.add(gameButtons[i]);
			gameButtons[i].setFont(new Font("Arial", Font.PLAIN, 35));
		}
		gameButtons[16]=new JButton();
		for(int i=0;i<2;i++) {
			for(int j=0;j<5;j++) {
						gameButtons[5*i+j].setBounds(buttonY+j*(buttonArraySize+buttonDistance), buttonX+i*(buttonArraySize+buttonDistance), buttonArraySize, buttonArraySize);
						int s=5*i+j;
						gameButtons[5*i+j].setText(s+"");
						gameButtons[5*i+j].setBackground(Color.lightGray);
			}
		}
		
		gameButtons[10].setBounds(buttonY,buttonX+(buttonArraySize+buttonDistance)*2,buttonArraySize+buttonDistance,buttonArraySize+buttonDistance);
		gameButtons[11].setBounds(buttonY+(buttonArraySize+buttonDistance*2),buttonX+(buttonArraySize+buttonDistance)*2,buttonArraySize+buttonDistance,buttonArraySize+buttonDistance);
		gameButtons[12].setBounds(buttonY+(buttonArraySize+buttonDistance*2)*2,buttonX+(buttonArraySize+buttonDistance)*2,buttonArraySize+buttonDistance,buttonArraySize+buttonDistance);
		gameButtons[13].setBounds(buttonY+(buttonArraySize+buttonDistance*2)*3,buttonX+(buttonArraySize+buttonDistance)*2,buttonArraySize+buttonDistance,buttonArraySize+buttonDistance);
		gameButtons[14].setBounds(buttonY,(buttonArraySize+buttonDistance*2)*4,(buttonArraySize+buttonDistance)*2+25,buttonArraySize+buttonDistance);
		gameButtons[15].setBounds(735,(buttonArraySize+buttonDistance*2)*4,(buttonArraySize+buttonDistance)*2+25,buttonArraySize+buttonDistance);
		gameButtons[15].setBackground(Color.RED);
		gameButtons[10].setText("+");
		gameButtons[11].setText("-");
		gameButtons[12].setText("/");
		gameButtons[13].setText("*");
		gameButtons[14].setText("=");
		gameButtons[14].setFont(new Font("Arial", Font.PLAIN, 45));
		gameButtons[15].setFont(new Font("Arial", Font.PLAIN, 45));
		gameButtons[14].setBackground(Color.green);
		gameButtons[15].setText("Sil");
		gameButtons[16].addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
				if(globalj<equation.getEsitlik().length()-1) 
					globalj++;
			}
		});
		for(int i=0;i<15;i++) {
			gameButtons[i].setToolTipText("Bu butona týklarsan seçtiðin/sýradaki kutucuða \"" + gameButtons[i].getText() +"\" yazacaktýr.");
		}
		gameButtons[15].setToolTipText("Bu butona týklarsan seçtiðin/sýradaki kutucuðun içini boþaltacaktýr." );
		gameButtons[0].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("0");
				gameButtons[16].doClick();
			}});
		gameButtons[1].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("1");
				gameButtons[16].doClick();
			}});
		gameButtons[2].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("2");
				gameButtons[16].doClick();
			}});
		gameButtons[3].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("3");
				gameButtons[16].doClick();
			}});
		gameButtons[4].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("4");
				gameButtons[16].doClick();
			}});
		gameButtons[5].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("5");
				gameButtons[16].doClick();
			}});
		gameButtons[6].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("6");
				gameButtons[16].doClick();
			}});
		gameButtons[7].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("7");
				gameButtons[16].doClick();
			}});
		gameButtons[8].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("8");
				gameButtons[16].doClick();
			}});
		gameButtons[9].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("9");
				gameButtons[16].doClick();
			}});
		gameButtons[10].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("+");
				gameButtons[16].doClick();
			}});
		gameButtons[11].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("-");
				gameButtons[16].doClick();
			}});
		gameButtons[12].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("/");
				gameButtons[16].doClick();
			}});
		gameButtons[13].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("*");
				gameButtons[16].doClick();
			}});
		gameButtons[14].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(silflag==1)
				{
					globalj++;
					silflag=0;
				}
				txtalan[globali][globalj].setText("=");
				gameButtons[16].doClick();
			}});
		gameButtons[15].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				while(globalj!=0 && txtalan[globali][globalj].getText().length()==0) {
						globalj--;
				}
				if(globalj==equation.getEsitlik().length()-1) {
					
					txtalan[globali][globalj].setText("");
					globalj--;
					silflag=1;
				}
					
				else {
					if(globalj!=0) {
						globalj--;
						silflag=1;
						txtalan[globali][globalj+1].setText("");
					}
					else {
						silflag=0;
						txtalan[globali][globalj].setText("");
					}
						
				}

				
			}});
		
			
		int [] istatistiks = new int[5];
		try {
		      File myObj = new File("istatistik.txt");
		      Scanner myReader = new Scanner(myObj);
		      for (int i=0;i<5;i++) {
		    	  if(myReader.hasNextLine())
		    		  istatistiks[i] = Integer.parseInt(myReader.nextLine());
		    	  else
		    		  istatistiks[i]=0;
		      }
		      
		      myReader.close();
				istatistik = new Istatistik(istatistiks[0],istatistiks[1],istatistiks[2],istatistiks[3],istatistiks[4]);
		    } catch (FileNotFoundException e) {
				istatistik = new Istatistik(0,0,0,0,0);
		      e.printStackTrace();
		    }

		panel.setLayout(null);
		JButton yeniOyunButton = new JButton("Yeni Oyun");
		yeniOyunButton.setToolTipText("Haydi yeni oyuna ba\u015Flayal\u0131m.");
		yeniOyunButton.setBounds(343, 239, 195, 164);
		yeniOyunButton.setBackground(Color.GREEN);
		panel.add(yeniOyunButton);
		footers = new JLabel[4];
		for(int i=0;i<4;i++) {
			footers[i]= new JLabel();
			footers[i].setText(footer);
			footers[i].setToolTipText("Bu oyunu hazýrlamak sandýðýn kadar kolay olmadý, e býrak da biraz hava atalým.");
			footers[i].setBounds(0, 0, 400, 35);
			footers[i].setForeground(Color.black);
		}
		footers[2].setForeground(Color.cyan);
		istatistikler = new JLabel[6];
		istatistikler[0]= new JLabel();
		istatistikler[0].setFont(new Font("Serif", Font.PLAIN, 14));
		panel.setToolTipText("Buraya bakma burada bir þey yok.");
		gamePanel.setToolTipText("Oyuna odaklaan");
		for(int i=0;i<istatistikSayisi;i++) {
			if(i!=0)
			istatistikler[i]= new JLabel();
			istatistikler[i].setBounds(0, 200+40*i, 350, 35);
			istatistikler[i].setToolTipText("Sen de merak ettin deðil mi?");
			istatistikler[i].setFont(new Font("Serif", Font.ITALIC, 20));
			istatistikler[i].setForeground(Color.MAGENTA);
			panel.add(istatistikler[i]);
		}
		for(int i=0;i<istatistikSayisi;i++) {
			istatistikler[i].setText(istatistik.getIstatistik()[i]);
		}
		sonraBitirButton=new JButton("Sonra Bitir");
		sonraBitirButton.setToolTipText("Ana ekrana d\u00F6ner ve kay\u0131t al\u0131r. E\u011Fer varsa bir \u00F6nceki kay\u0131t silinir.");
		sonraBitirButton.setBounds(53, 435, 100, 50);
		sonraBitirButton.setFont(new Font("Arial", Font.PLAIN, 14));
		sonraBitirButton.setBackground(Color.cyan);
		gamePanel.add(sonraBitirButton);
		testPanel.add(footers[0]);
		loseWinPanel.add(footers[1]);
		gamePanel.add(footers[2]);
		panel.add(footers[3]);
		JButton devamButton = new JButton("Devam Et");
		devamButton.setToolTipText("E\u011Fer varsa, en son kaydetti\u011Fin oyundan devam etmeni sa\u011Flar.");
		devamButton.setBounds(603, 37, 195, 159);
		back = new JButton("Geri");
		back.setToolTipText("Ana ekrana d\u00F6ner.");
		
		back.setBounds(200, 215, 200, 100);
		gameBack = new JButton("Geri");
		gameBack.setFont(new Font("Arial", Font.PLAIN, 14));
		gameBack.setToolTipText("Ana ekrana d\u00F6ner ve hi\u00E7bir \u015Feyi kay\u0131t etmez.");
		gameBack.setBackground(Color.RED);
		gameBack.setBounds(421, 435, 100, 50);
		sonraBitirButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				myTimer.cancel();
				File myObj = new File("eskiOyun.txt");
				try {
				if(myObj.exists()) {
				      Scanner myReader = new Scanner(myObj);
				     if(Integer.parseInt(myReader.nextLine())!=0 && devamaBas!=1) {
				    		 istatistik.setYaridaBirakilanOyun(istatistik.getYaridaBirakilanOyun()+1);
				    		 istatistik.istatistikYaz();
				    		 for(int i=0;i<istatistikSayisi;i++) {
									istatistikler[i].setText(istatistik.getIstatistik()[i]);
								}
				    		 
				    	 }
				     myReader.close();
				     }}
				catch(IOException ed){
					ed.printStackTrace();
				}
				
				for(int i=0;i<6;i++) {
					sonucDizisi[i]="";
					for(int j=0;j<equation.getEsitlik().length();j++) {
						gamePanel.remove(txtalan[i][j]);
						sonucDizisi[i]=sonucDizisi[i]+txtalan[i][j].getText();
					}
				}
				gamePanel.repaint();
				panel.setVisible(true);
				testPanel.setVisible(false);
				gamePanel.setVisible(false);
				try {
				      myObj.createNewFile();
				     
				    } catch (IOException c) {
				      c.printStackTrace();
				    }
				try {
				      FileWriter myWriter = new FileWriter("eskiOyun.txt");
				      myWriter.write(konum + "");
				      myWriter.write("\n"+timer.getText());
				      for(int i=0;i<konum;i++) {
				    	  myWriter.write("\n" +sonucDizisi[i]);
				      }
				      	myWriter.write("\n"+equation.getEsitlik());
				      myWriter.close();
				    } catch (IOException c) {
				      c.printStackTrace();
				    }
			}
		});
		sonucDizisi = new String[6];

		devamButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent c) {
				      File myObj = new File("eskiOyun.txt");
				      devammiTamami=1;
				      
				      if(myObj.exists()) {
				      Scanner myReader;
					try {
						myReader = new Scanner(myObj);
					    konum =Integer.parseInt(myReader.nextLine());
					    if(konum !=0) {
						    timer.setText(myReader.nextLine());
					    	String[] data = new String[konum];
					    	globali=konum;
					    	globalj=0;
					    for (int i=0;i<konum;i++) {
					        data[i] = myReader.nextLine();
					        
					      }
					    devamaBas=1;
					    gamePanel.add(back1);
					    back1.setLocation(421, 435);;
					    gamePanel.remove(gameBack);
						gamePanel.setVisible(true);
						panel.setVisible(false);
					    equation= new EquationClass();
					    equation.setEsitlik(myReader.nextLine());
					    txtalan = new JButton[6][equation.getEsitlik().length()];
					    for(int i=0;i<6;i++) {
							txtalan[i] = new JButton[equation.getEsitlik().length()];
							for(int j=0;j<equation.getEsitlik().length();j++) {
								txtalan[i][j] = new JButton();	
								txtalan[i][j].setBounds(25+530/equation.getEsitlik().length()*j,60*i+50,50,50);
								txtalan[i][j].setEnabled(false);
								txtalan[i][j].setToolTipText("Burasý " +(i+1)+". hakkýn. Bu kutucuksa tahmininin "+
										(j+1)+ ". basamaðý.");
								if(i==4 || i==5)
									txtalan[i][j].setToolTipText(txtalan[i][j].getToolTipText() + " Burasý kaybetmeye çook yakýn aman dikkat!!!");
								else
									if(i==3 || i==2)
									txtalan[i][j].setToolTipText(txtalan[i][j].getToolTipText() + " Ýþler yavaþ yavaþ kýzýþýyor.");
									else
										txtalan[i][j].setToolTipText(txtalan[i][j].getToolTipText() + " Henüz daha yolun baþýndasýn, rahat ol.");
								txtalan[i][j].setForeground(Color.black);
								gamePanel.add(txtalan[i][j]);
								gamePanel.repaint();
							}
						}
						myTimer= new Timer();
						myTimer.schedule(new TimerTask() {
							public void run() {
								timer.setText(Integer.parseInt(timer.getText())+1+"");
							}
						}, 1000,1000);
						for(int i=0;i<6;i++) {
							txtalan[i][1].addActionListener(new ActionListener(){
							public void actionPerformed(ActionEvent es) {
								globalj=1;
								silflag=0;
							}});}
						for(int i=0;i<6;i++) {
							txtalan[i][2].addActionListener(new ActionListener(){
							public void actionPerformed(ActionEvent es) {
								globalj=2;
								silflag=0;
							}});}
						for(int i=0;i<6;i++) {
							txtalan[i][3].addActionListener(new ActionListener(){
							public void actionPerformed(ActionEvent es) {
								globalj=3;
								silflag=0;
							}});}
						for(int i=0;i<6;i++) {
							txtalan[i][4].addActionListener(new ActionListener(){
							public void actionPerformed(ActionEvent es) {
								globalj=4;
								silflag=0;
							}});}
						for(int i=0;i<6;i++) {
							txtalan[i][5].addActionListener(new ActionListener(){
							public void actionPerformed(ActionEvent es) {
								silflag=0;
								globalj=5;
							}});}
						for(int i=0;i<6;i++) {
							txtalan[i][6].addActionListener(new ActionListener(){
							public void actionPerformed(ActionEvent es) {
								globalj=6;
								silflag=0;
							}});}
						for(int i=0;i<6;i++) {
							txtalan[i][0].addActionListener(new ActionListener(){
							public void actionPerformed(ActionEvent es) {
								globalj=0;
								silflag=0;
							}});}
					
							if(equation.getEsitlik().length()>=8)
								for(int i=0;i<6;i++) {
									txtalan[i][7].addActionListener(new ActionListener(){
										public void actionPerformed(ActionEvent es) {
											globalj=7;
											silflag=0;
								}});}
							
							if(equation.getEsitlik().length()>=9)
								for(int i=0;i<6;i++) {
									txtalan[i][8].addActionListener(new ActionListener(){
										public void actionPerformed(ActionEvent es) {
											globalj=8;
											silflag=0;
								}});}
					    String tahmin="";
						for(int i=0;i<equation.getEsitlik().length();i++) {
							txtalan[0][i].setEnabled(true);
						}
						for(int i=0;i<6;i++) {
							for(int j=0;j<equation.getEsitlik().length();j++) {
								if(i!=konum)
									txtalan[i][j].setEnabled(false);
								else
									txtalan[konum][j].setEnabled(true);
									txtalan[i][j].setForeground(Color.black);
							}
						}
					    for(int i=0; i<konum;i++) {
					    	for(int j=0;j<equation.getEsitlik().length();j++) {
					    		txtalan[i][j].setText(Character.toString(data[i].charAt(j)));
					    		tahmin=tahmin+Character.toString(data[i].charAt(j));
					    	}
						    renkDizisi=equation.colors(tahmin);
						    for(int k=0;k<equation.getEsitlik().length();k++) {
								if(renkDizisi[k]==0) {
									txtalan[i][k].setBackground(Color.green);
								}
								else if(renkDizisi[k]==1) {
									txtalan[i][k].setBackground(Color.yellow);
								}
								else {
									txtalan[i][k].setBackground(Color.red);
								}
							}
						    tahmin="";
					    }
						
					    }
					    else {
					    	String message = "KAYIT BULUNAMADI";
							    JOptionPane.showMessageDialog(new JFrame(), message, "UYARI!!!",
							        JOptionPane.WARNING_MESSAGE);
					    }
					      myReader.close();
					} catch (FileNotFoundException e) {
						e.printStackTrace();
					}
}
				else {
					String message = "KAYIT BULUNAMADI";
				    JOptionPane.showMessageDialog(new JFrame(), message, "UYARI!!!",
				        JOptionPane.WARNING_MESSAGE);
				}
			}
		});
		panel.add(devamButton);
		
		back1.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				myTimer.cancel();
			for(int i=0;i<6;i++) {
				for(int j=0;j<equation.getEsitlik().length();j++) {
					gamePanel.remove(txtalan[i][j]);
				}
			}
			istatistik.setYaridaBirakilanOyun(istatistik.getYaridaBirakilanOyun()+1);
			for(int i=0;i<istatistikSayisi;i++) {
				istatistikler[i].setText(istatistik.getIstatistik()[i]);
			}
			File myObj = new File("eskiOyun.txt");
		      if(myObj.exists()) {
		    	  FileWriter myWriter;
				try {
					myWriter = new FileWriter("eskiOyun.txt");
					 myWriter.write(0+"");
					 myWriter.close();
					 konum=0;
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			     
		      }
			istatistik.istatistikYaz();
			gamePanel.repaint();
			panel.setVisible(true);
			testPanel.setVisible(false);
			gamePanel.setVisible(false);}
			
		});
		gameBack.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			myTimer.cancel();
			for(int i=0;i<6;i++) {
				for(int j=0;j<equation.getEsitlik().length();j++) {
					gamePanel.remove(txtalan[i][j]);
				}
			}
			istatistik.setYaridaBirakilanOyun(istatistik.getYaridaBirakilanOyun()+1);
			istatistik.istatistikYaz();
			for(int i=0;i<istatistikSayisi;i++) {
				istatistikler[i].setText(istatistik.getIstatistik()[i]);
			}
			gamePanel.repaint();
			panel.setVisible(true);
			testPanel.setVisible(false);
			gamePanel.setVisible(false);
			loseWinPanel.setVisible(false);
			}
			
		});
		
		back.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
			panel.setVisible(true);
			loseWinPanel.setVisible(false);
			testPanel.setVisible(false);
			gamePanel.setVisible(false);}
			
		});
		testPanel.setBounds(0, 0, 916, 513);
		testButton = new JButton("Test");
		testButton.setToolTipText("Rastgele denklem \u00FCretme kabiliyetimi s\u0131namaya ne dersin?");
		testButton.setBounds(23, 32, 195, 164);
		testButton1 = new JButton("Test");
		testButton1.setToolTipText("Rastgele bir denklem \u00FCretir ve bunu \u00FCstteki kutucu\u011Fa yazar.");
		testButton1.setBounds(460, 215, 200, 100);
		testButton1.setBackground(Color.RED);
		testButton.setBackground(Color.RED);
		testButton1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				myclass=new EquationClass();
				testText.setText(myclass.getEsitlik());
				
			}
		});
		testText= new JTextField();
		testText.setToolTipText("Buradaysa rastgele denklem var.");
		testText.setDisabledTextColor(Color.black);
		testPanel.setLayout(null);
		testPanel.add(testButton1);
		testPanel.add(back);
		testText.setBounds(378, 150, 100, 50);
		testText.setEditable(false);
		testText.setHorizontalAlignment(JTextField.CENTER);
		testButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				panel.setVisible(false);
				myclass = new EquationClass();
				testText.setText(myclass.getEsitlik());
				testPanel.add(testText);
				testPanel.setVisible(true);
				testPanel.repaint();
				
			}
		});
		tahminButton.setBounds(579, 27, 172, 97);
		tahminButton.setFont(new Font("Arial Black", Font.PLAIN, 24));
		tahminButton.setBackground(Color.GREEN);
		gamePanel.add(tahminButton);
		gamePanel.add(gameBack);
		winLoseButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			gameBack.doClick();
			}
		});
		panel.add(testButton);
		loseWinLabel.setToolTipText("Zaman hýzlý geçiyor");
		yeniOyunButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				timer.setText(0+"");
				devammiTamami=0;
				konum=0;
				globali=0;
				devamaBas=0;
				myTimer= new Timer();
				myTimer.schedule(new TimerTask() {
					public void run() {
						timer.setText(Integer.parseInt(timer.getText())+1+"");
					}
				}, 1000,1000);
		    	globalj=0;
				gamePanel.add(gameBack);
				gamePanel.remove(back1);
				equation = new EquationClass();
				int switchim=Zorluk.getSelectedIndex();
				switch(switchim) {
				case 0:
					equation.setVeryEasyEquation();
					break;
				case 1:
					equation.setEasyEquation();
					break;
				case 2:
					equation.setNormalEquation();
					break;
				}

				
					
				
				txtalan = new JButton[6][equation.getEsitlik().length()];
				for(int i=0;i<6;i++) {
					txtalan[i] = new JButton[equation.getEsitlik().length()];
					for(int j=0;j<equation.getEsitlik().length();j++) {
						txtalan[i][j] = new JButton();	
						txtalan[i][j].setBounds(25+530/equation.getEsitlik().length()*j,60*i+50,50,50);
						txtalan[i][j].setEnabled(false);

						txtalan[i][j].setHorizontalAlignment(JButton.CENTER);
						txtalan[i][j].setFont(new Font("Arial", Font.PLAIN, 14));
						txtalan[i][j].setToolTipText("Burasý " +(i+1)+". hakkýn. Bu kutucuksa tahmininin "+
								(j+1)+ ". basamaðý.");
						if(i==4 || i==5)
							txtalan[i][j].setToolTipText(txtalan[i][j].getToolTipText() + " Burasý kaybetmeye çook yakýn aman dikkat!!!");
						else
							if(i==3 || i==2)
							txtalan[i][j].setToolTipText(txtalan[i][j].getToolTipText() + " Ýþler yavaþ yavaþ kýzýþýyor.");
							else
								txtalan[i][j].setToolTipText(txtalan[i][j].getToolTipText() + " Henüz daha yolun baþýndasýn, rahat ol.");
						txtalan[i][j].setForeground(Color.black);
						gamePanel.add(txtalan[i][j]);
						txtalan[i][j].setHorizontalAlignment(JTextField.CENTER);
						
					}
				}
				for(int i=0;i<6;i++) {
					txtalan[i][1].addActionListener(new ActionListener(){
					public void actionPerformed(ActionEvent es) {
						globalj=1;
						silflag=0;
					}});}
				for(int i=0;i<6;i++) {
					txtalan[i][2].addActionListener(new ActionListener(){
					public void actionPerformed(ActionEvent es) {
						globalj=2;
						silflag=0;
					}});}
				for(int i=0;i<6;i++) {
					txtalan[i][3].addActionListener(new ActionListener(){
					public void actionPerformed(ActionEvent es) {
						globalj=3;
						silflag=0;
					}});}
				for(int i=0;i<6;i++) {
					txtalan[i][4].addActionListener(new ActionListener(){
					public void actionPerformed(ActionEvent es) {
						globalj=4;
						silflag=0;
					}});}
				for(int i=0;i<6;i++) {
					txtalan[i][5].addActionListener(new ActionListener(){
					public void actionPerformed(ActionEvent es) {
						silflag=0;
						globalj=5;
					}});}
				for(int i=0;i<6;i++) {
					txtalan[i][6].addActionListener(new ActionListener(){
					public void actionPerformed(ActionEvent es) {
						globalj=6;
						silflag=0;
					}});}
				for(int i=0;i<6;i++) {
					txtalan[i][0].addActionListener(new ActionListener(){
					public void actionPerformed(ActionEvent es) {
						globalj=0;
						silflag=0;
					}});}
			
					if(equation.getEsitlik().length()>=8)
						for(int i=0;i<6;i++) {
							txtalan[i][7].addActionListener(new ActionListener(){
								public void actionPerformed(ActionEvent es) {
									globalj=7;
									silflag=0;
						}});}
					
					if(equation.getEsitlik().length()>=9)
						for(int i=0;i<6;i++) {
							txtalan[i][8].addActionListener(new ActionListener(){
								public void actionPerformed(ActionEvent es) {
									globalj=8;
									silflag=0;
						}});}
				
				for(int i=0;i<equation.getEsitlik().length();i++) {
					txtalan[0][i].setEnabled(true);
				}
				gamePanel.setVisible(true);
				gamePanel.repaint();
				panel.setVisible(false);
			}
		});
		ciktitxt= new JLabel();

		ciktitxt.setSize(450, 100);
		ciktitxt.setLocation(250, 50);
		ciktitxt.setText("E\u011Fer kazand\u0131ysan ye\u015Fil, kaybettiysen k\u0131rm\u0131z\u0131.");
		ciktitxt.setHorizontalAlignment(SwingConstants.CENTER);
		
		loseWinPanel.add(ciktitxt);
		ciktitxt.setFont(new Font("Verdana", Font.PLAIN, 25));
		tahminButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e) {
				
				String tahmin="";
				int k=0;
				for(int i=0;i<equation.getEsitlik().length();i++) {
					if(txtalan[konum][i].getText().length()!=1) {
						tahmin="1+2=5";
						k=-1;
						break;
					}
					tahmin+=txtalan[konum][i].getText();
				}
				DenklemKontrol denklem= new DenklemKontrol(tahmin);
				if(denklem.isCorrect()) {
					int random_int;
					String pname;
					BufferedImage myPicture = null;
					globalj=0;
					globali++;
					renkDizisi=new int[equation.getEsitlik().length()];
					renkDizisi=equation.colors(tahmin);
					counter=0;
					for(int i=0;i<equation.getEsitlik().length();i++) {
						if(renkDizisi[i]==0) {
							counter++;
							txtalan[konum][i].setBackground(Color.green);
						}
						else if(renkDizisi[i]==1) {
							txtalan[konum][i].setBackground(Color.yellow);
						}
						else {
							txtalan[konum][i].setBackground(Color.red);
						}
					}
					if(counter == equation.getEsitlik().length() || konum==5) {
						for(int i=0;i<6;i++) {
							for(int j=0;j<equation.getEsitlik().length();j++) {
								gamePanel.remove(txtalan[i][j]);
							}
						}

						
						
						
						gamePanel.setVisible(false);
						loseWinPanel.setVisible(true);
						if(counter!=equation.getEsitlik().length()) {
							random_int = (int)Math.floor(Math.random()*(30-15+1)+15);
							 pname=random_int+".jpg";
							try {
							myPicture = ImageIO.read(new File(pname));
							imgLabel = new JLabel(new ImageIcon(myPicture));
							imgLabel.setBounds(350, 270, 200, 200);
							loseWinPanel.add(imgLabel);
						} catch (IOException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						}
							myTimer.cancel();
							loseWinLabel.setText("");
							ciktitxt.setForeground(Color.red);
							ciktitxt.setText("Kaybettiniz! Denklem->"+ equation.getEsitlik());
							ciktitxt.setToolTipText("Hangi renk? Biraz üzgün gibisin sanýrým kýrmýzý.");
							loseWinPanel.setToolTipText("Hadi amaa, bir dahaki sefere kazanacaksýn.");
							ciktitxt.setBackground(Color.red);
							istatistik.setBasarisizOyun(istatistik.getBasarisizOyun()+1);
							istatistik.setYaridaBirakilanOyun(istatistik.getYaridaBirakilanOyun()-1);
							istatistik.istatistikYaz();
							for(int i=0;i<istatistikSayisi;i++) {
								istatistikler[i].setText(istatistik.getIstatistik()[i]);
							}
							if(devammiTamami==1) {
								File myObj = new File("eskiOyun.txt");
							      if(myObj.exists()) {
							    	  FileWriter myWriter;
									try {
										myWriter = new FileWriter("eskiOyun.txt");
										 myWriter.write(0+"");
										 myWriter.close();
										 konum=0;
									} catch (IOException e1) {
										// TODO Auto-generated catch block
										e1.printStackTrace();
									}}
							}

						}
						else {
							myTimer.cancel();
							ciktitxt.setText("Tebrikler!!!");
							loseWinLabel.setText("Geçen Toplam Süre--->" + timer.getText());
							ciktitxt.setForeground(Color.green);
							ciktitxt.setToolTipText("Hangi renk? Mutlu gördüm seni sanki yeþil gibi.");
							loseWinPanel.setToolTipText("Evet, evet sen kazandýn");
							 random_int = (int)Math.floor(Math.random()*(15-1+1)+1);
							 pname=random_int+".jpg";
							 
							try {
								myPicture = ImageIO.read(new File(pname));
								imgLabel = new JLabel(new ImageIcon(myPicture));
								imgLabel.setBounds(350, 270, 200, 200);
								loseWinPanel.add(imgLabel);
							} catch (IOException e1) {
								// TODO Auto-generated catch block
								e1.printStackTrace();
							}
							File myObj = new File("eskiOyun.txt");
						      if(myObj.exists()) {
						    	  FileWriter myWriter;
								try {
									myWriter = new FileWriter("eskiOyun.txt");
									 myWriter.write(0+"");
									 myWriter.close();
								} catch (IOException e1) {
									// TODO Auto-generated catch block
									e1.printStackTrace();
								}}
							
							
							istatistik.setBasariliOyun(istatistik.getBasariliOyun()+1);
							istatistik.setYaridaBirakilanOyun(istatistik.getYaridaBirakilanOyun()-1);
							istatistik.setSatirSayisi(istatistik.getSatirSayisi()+konum+1);
							istatistik.setToplamSure(istatistik.getToplamSure()+Integer.parseInt(timer.getText()));
							konum=0;
							istatistik.istatistikYaz();
							for(int i=0;i<istatistikSayisi;i++) {
								istatistikler[i].setText(istatistik.getIstatistik()[i]);
							}
							ciktitxt.setBackground(Color.green);
							

						}
						
					}
					else {
						for(int i=0;i<equation.getEsitlik().length();i++) {
							txtalan[konum][i].setEnabled(false);
							txtalan[konum+1][i].setEnabled(true);
						}
					}
					sonucDizisi[konum] = tahmin;
					konum++;
				}
				else {
					if(k==0) {
					String message = "GÝRDÝÐÝNÝZ DEÐERLER\n"
					        + "DENKLEM ÞARTLARINI\n"
					        + "SAÐLAMIYOR";
					    JOptionPane.showMessageDialog(new JFrame(), message, "UYARI!!!",
					        JOptionPane.WARNING_MESSAGE);}
					else {
						k=1;
						String message = "GÝRDÝÐÝNÝZ DEÐERLER\n"
						        + "EKSÝK!!!"
						        ;
						    JOptionPane.showMessageDialog(new JFrame(), message, "UYARI!!!",
						        JOptionPane.WARNING_MESSAGE);
					}
					
				    	  
				}
				tahmin="";
				
			}
		});
		
		

	}
}
