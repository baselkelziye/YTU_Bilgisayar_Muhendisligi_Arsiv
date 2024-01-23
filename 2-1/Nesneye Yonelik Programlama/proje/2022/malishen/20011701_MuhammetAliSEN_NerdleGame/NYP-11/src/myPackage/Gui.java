package myPackage;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Timer;
import javax.swing.JFrame;
import javax.swing.JLabel;
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
public class Gui extends JFrame{
	
	
	private static final long serialVersionUID = 6000335185319848898L;

	private JButton[][] txtalan;
	
	
	private int konum=0;
	
	
	
	private JPanel contentPane;
	
	
	private int[] renkDizisi;
	
	
	
	private EquationClass equation;
	
	
	
	private EquationClass myclass;
	

	
	private JButton testButton;
	

	
	private JButton testButton1;
	

	
	private JPanel panel;
	
	
	
	private JLabel imgLabel;
	
	
	private JPanel testPanel;
	

	
	private int globali=0;
	
	
	
	private int globalj=0;
	
	
	
	private JLabel timer;
	private JLabel timerText;

	
	private JButton back;
	
	private int devamaBas;
	
	
	private JButton back1;
	
	
	
	private String[] sonucDizisi;

	
	
	private JPanel gamePanel;
	
	
	
	private JTextField testText;
	
	
	
	private JButton gameBack;
	

	
	private int silflag=0;
	
	
	private JButton sonraBitirButton;
	
	
	private int devammiTamami;
	
	
	private JLabel[] footers;
	private String footer = "20011701 Muhammet Ali SEN";
	
	
	private JLabel[] istatistikler;
	
	
	private Istatistik istatistik;
	
	
	private JButton[] gameButtons = new JButton[17];
	
	private int istatistikSayisi = 6;
	
	
	
	
	private Timer myTimer;
	
	
		
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

	
	public Gui() {
		timer = new JLabel();
		timerText= new JLabel();
		back1= new JButton("Return");
		back1.setLocation(125, 265);
		back1.setSize(100, 50);
		back1.setToolTipText("Do Not Return Until Save");;
		back1.setBackground(Color.blue);
		back1.setOpaque(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 932, 552);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		contentPane.setLayout(null);
		JButton tahminButton = new JButton("Guess?");
		tahminButton.setBackground(Color.GREEN);
		tahminButton.setOpaque(true);
		tahminButton.setToolTipText("Careful!!!");
		panel = new JPanel();
		panel.setBackground(Color.LIGHT_GRAY);
		panel.setOpaque(true);
		testPanel = new JPanel();
		testPanel.setBackground(Color.YELLOW);
		testPanel.setOpaque(true);
		gamePanel = new JPanel();
		gamePanel.setBackground(Color.DARK_GRAY);
		gamePanel.setOpaque(true);
		gamePanel.setSize(916, 513);
		gamePanel.setLocation(0, 0);
		gamePanel.setVisible(false);
		testPanel.setVisible(false);
		testPanel.setToolTipText("Only For Tests");
		gamePanel.setLayout(null);
		gamePanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		panel.setBorder(new EmptyBorder(5, 5, 5, 5));
		testPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		panel.setBounds(0, 0, 916, 513);
		timer.setBounds(800,0,100,100);
		timerText.setBounds(800, 0, 100, 60);
		timerText.setText("Time");
		timerText.setFont(new Font("Serif", Font.PLAIN, 14));
		timerText.setForeground(Color.white);
		timer.setText("0");
		timer.setFont(new Font("Serif", Font.PLAIN, 14));
		timer.setForeground(Color.white);
		timer.setHorizontalAlignment(JTextField.CENTER);
		timerText.setHorizontalAlignment(JTextField.CENTER);
		gamePanel.add(timerText);
		contentPane.add(panel);
		contentPane.add(testPanel);
		contentPane.add(gamePanel);
		gamePanel.add(timer);
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
						gameButtons[5*i+j].setOpaque(true);
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
		gameButtons[15].setText("DEL");
		gameButtons[16].addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
				if(globalj<equation.getEsitlik().length()-1) 
					globalj++;
			}
		});
		for(int i=0;i<15;i++) {
			gameButtons[i].setToolTipText("If you clicked the button" + gameButtons[i].getText() +"\" will write");
		}
		gameButtons[15].setToolTipText("if you clicked the button next line will empty" );
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
				istatistik = new Istatistik(istatistiks[0],istatistiks[1],istatistiks[2],istatistiks[3]);
		    } catch (FileNotFoundException e) {
				istatistik = new Istatistik(0,0,0,0);
		      e.printStackTrace();
		    }

		panel.setLayout(null);
		JButton yeniOyunButton = new JButton("New Game");
		yeniOyunButton.setToolTipText("Lets Start New Game");
		yeniOyunButton.setBounds(343, 239, 195, 164);
		yeniOyunButton.setBackground(Color.green);
		panel.add(yeniOyunButton);
		footers = new JLabel[4];
		for(int i=0;i<4;i++) {
			footers[i]= new JLabel();
			footers[i].setText(footer);
			footers[i].setToolTipText("It s not Easy !!");
			footers[i].setBounds(0, 0, 400, 35);
			footers[i].setForeground(Color.black);
		}
		footers[2].setForeground(Color.cyan);
		istatistikler = new JLabel[6];
		istatistikler[0]= new JLabel();
		istatistikler[0].setFont(new Font("Serif", Font.PLAIN, 14));
		panel.setToolTipText("Nothing");
		gamePanel.setToolTipText("Focus the game");
		for(int i=0;i<istatistikSayisi;i++) {
			if(i!=0)
			istatistikler[i]= new JLabel();
			istatistikler[i].setBounds(0, 25+40*i, 150, 35);
			istatistikler[i].setToolTipText("interesting??");
			istatistikler[i].setFont(new Font("Serif", Font.BOLD, 20));
			istatistikler[i].setForeground(Color.YELLOW);
			panel.add(istatistikler[i]);
		}
		for(int i=0;i<istatistikSayisi;i++) {
			istatistikler[i].setText(istatistik.getIstatistik()[i]);
		}
		sonraBitirButton=new JButton("Later?");
		sonraBitirButton.setToolTipText("Return Home");
		sonraBitirButton.setBounds(53, 435, 100, 50);
		sonraBitirButton.setFont(new Font("Arial", Font.PLAIN, 14));
		sonraBitirButton.setBackground(Color.CYAN);
		sonraBitirButton.setOpaque(true);
		gamePanel.add(sonraBitirButton);
		testPanel.add(footers[0]);
		gamePanel.add(footers[2]);
		panel.add(footers[3]);
		JButton devamButton = new JButton("Go on");
		devamButton.setToolTipText("if there is a game you recorded go on");
		devamButton.setBounds(600, 242, 195, 159);
		back = new JButton("Back");
		back.setToolTipText("Return Home");
		
		back.setBounds(200, 215, 200, 100);
		gameBack = new JButton("Back");
		gameBack.setFont(new Font("Arial", Font.PLAIN, 14));
		gameBack.setToolTipText("Return Home. And there is no REC");
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
								
								if(i==4 || i==5)
									txtalan[i][j].setToolTipText(txtalan[i][j].getToolTipText() + " Careful!!!");
								else
									if(i==3 || i==2)
									txtalan[i][j].setToolTipText(txtalan[i][j].getToolTipText());
									else
										txtalan[i][j].setToolTipText(txtalan[i][j].getToolTipText() + " It`s Easy");
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
									txtalan[i][k].setBackground(Color.GREEN);
								}
								else if(renkDizisi[k]==1) {
									txtalan[i][k].setBackground(Color.YELLOW);
								}
								else {
									txtalan[i][k].setBackground(Color.red);
								}
							}
						    tahmin="";
					    }
						
					    }
					    else {
					    	String message = "NO REC";
							    JOptionPane.showMessageDialog(new JFrame(), message, "CAREFULL!!!",
							        JOptionPane.WARNING_MESSAGE);
					    }
					      myReader.close();
					} catch (FileNotFoundException e) {
						e.printStackTrace();
					}
}
				else {
					String message = "NO REC";
				    JOptionPane.showMessageDialog(new JFrame(), message, "CAREFULL!!!",
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

			}
			
		});
		
		back.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
			panel.setVisible(true);
			
			testPanel.setVisible(false);
			gamePanel.setVisible(false);}
			
		});
		testPanel.setBounds(0, 0, 916, 513);
		testButton = new JButton("Test");
		testButton.setToolTipText("Random Equation ?");
		testButton.setBounds(28, 239, 195, 164);
		testButton1 = new JButton("Test");
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
		testText.setToolTipText("Random Equations");
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
		tahminButton.setBackground(Color.BLUE);
		gamePanel.add(tahminButton);
		gamePanel.add(gameBack);
		panel.add(testButton);
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
			

				equation.setNormalEquation();
					
				
				txtalan = new JButton[6][equation.getEsitlik().length()];
				for(int i=0;i<6;i++) {
					txtalan[i] = new JButton[equation.getEsitlik().length()];
					for(int j=0;j<equation.getEsitlik().length();j++) {
						txtalan[i][j] = new JButton();	
						txtalan[i][j].setBounds(25+530/equation.getEsitlik().length()*j,60*i+50,50,50);
						txtalan[i][j].setEnabled(false);

						txtalan[i][j].setHorizontalAlignment(JButton.CENTER);
						txtalan[i][j].setFont(new Font("Arial", Font.PLAIN, 14));
						if(i==4 || i==5)
							txtalan[i][j].setToolTipText(txtalan[i][j].getToolTipText() + " Careful!!");
						else
							if(i==3 || i==2)
							txtalan[i][j].setToolTipText(txtalan[i][j].getToolTipText() + " It`s Not Easy");
							else
								txtalan[i][j].setToolTipText(txtalan[i][j].getToolTipText() + " It`s Easy");
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
						
						if(counter!=equation.getEsitlik().length()) {
							random_int = (int)Math.floor(Math.random()*(30-15+1)+15);
							 pname=random_int+".jpg";
							try {
							myPicture = ImageIO.read(new File(pname));
							imgLabel = new JLabel(new ImageIcon(myPicture));
							imgLabel.setBounds(350, 270, 200, 200);

						} catch (IOException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						}
							myTimer.cancel();
						
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
							
							 random_int = (int)Math.floor(Math.random()*(15-1+1)+1);
							 pname=random_int+".jpg";
							 
							try {
								myPicture = ImageIO.read(new File(pname));
								imgLabel = new JLabel(new ImageIcon(myPicture));
								imgLabel.setBounds(350, 270, 200, 200);
								
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
							konum=5;
							istatistik.istatistikYaz();
							for(int i=0;i<istatistikSayisi;i++) {
								istatistikler[i].setText(istatistik.getIstatistik()[i]);
							}
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
					String message = "It`s Not True \n";
					    JOptionPane.showMessageDialog(new JFrame(), message, "CAREFULL!!!",
					        JOptionPane.WARNING_MESSAGE);}
					else {
						k=1;
						String message = "We need More \n"
						        + "INCOMPLETE!!!"
						        ;
						    JOptionPane.showMessageDialog(new JFrame(), message, "CAREFULL!!!",
						        JOptionPane.WARNING_MESSAGE);
					}
					
				    	  
				}
				tahmin="";
				
			}
		});
		
		

	}
}
