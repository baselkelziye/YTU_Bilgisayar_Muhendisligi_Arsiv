package Proje;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.ArrayList;
import java.awt.event.ActionEvent;
import javax.swing.JPasswordField;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JCheckBox;
import javax.swing.JRadioButton;
public class mainMenu extends JFrame {
	
	// ANA MENÜDE GEREKEN GUİ YAPILARI
	private JPanel contentPane;
	private JTextField loginName;
	private JTextField loginSurname;
	private JTextField registerSurname;
	private JTextField registerName;
	private JLabel lblNewLabel_3;
	private JLabel lblNewLabel_2;
	private JLabel lblNewLabel_1;
	private JLabel lblNewLabel_4;
	private JLabel lblNewLabel_5;
	private JLabel lblNewLabel_6;
	private JLabel lblNewLabel_7;
	private JPasswordField registerPassword_1;
	private JPasswordField registerPassword_2;
	private JPasswordField loginPassword_1;
	private JButton btnChild;
	private JButton btnParent;
	private JButton btnRegister;
	private JButton btnLogin;
	

	public int i = 5;
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					mainMenu frame = new mainMenu();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
		
	}
	public mainMenu() {
		
		fileOperations fileOps = new fileOperations();
		try {
			// UYGULAMA AÇILMADAN ÖNCE SİSTEMDEKİ ÇOCUK/EBEVEYNLERİN DOSYALARI OLUŞTURULUR
			fileOps.createPWFile();
			fileOps.createParentFile();
			fileOps.createResultFiles();
			fileOps.createScoreTable();
			fileOps.createCSVFiles();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		try {
			dispose();
			// EĞER SİSTEME ÜYE OLMUŞ EBEVEYN YOKSA EBEVEYN EKLEME EKRANINI AÇAR
			if(!fileOps.parentControl()) {
				setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				setBounds(100, 100, 645, 674);
				contentPane = new JPanel();
				contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
				
				setContentPane(contentPane);
				contentPane.setLayout(null);
				
				JPanel panel = new JPanel();
				panel.setBounds(314, 10, 1, 1);
				contentPane.add(panel);
				panel.setLayout(null);
				
				JPanel panel_1 = new JPanel();
				panel_1.setBounds(305, 21, 10, 10);
				contentPane.add(panel_1);
				panel_1.setLayout(null);
				
				
				JLabel lblParentRegister = new JLabel("Ebeveyn Kayıt");
				lblParentRegister.setHorizontalAlignment(SwingConstants.CENTER);
				lblParentRegister.setFont(new Font("Calibri", Font.BOLD, 55));
				lblParentRegister.setBounds(20, 22, 586, 84);
				contentPane.add(lblParentRegister);
				
				registerName = new JTextField();
				registerName.setColumns(10);
				registerName.setBounds(148, 154, 288, 20);
				contentPane.add(registerName);
				
				registerSurname = new JTextField();
				registerSurname.setColumns(10);
				registerSurname.setBounds(148, 222, 288, 20);
				contentPane.add(registerSurname);
				
				registerPassword_1 = new JPasswordField();
				registerPassword_1.setBounds(148, 291, 288, 20);
				contentPane.add(registerPassword_1);
				
				JLabel lblNewLabel_4 = new JLabel("İsim");
				lblNewLabel_4.setFont(new Font("Calibri", Font.BOLD, 17));
				lblNewLabel_4.setBounds(148, 132, 89, 20);
				contentPane.add(lblNewLabel_4);
				
				registerPassword_2 = new JPasswordField();
				registerPassword_2.setBounds(148, 359, 288, 20);
				contentPane.add(registerPassword_2);
				
				JLabel lblNewLabel_7 = new JLabel("Şifre");
				lblNewLabel_7.setFont(new Font("Calibri", Font.BOLD, 17));
				lblNewLabel_7.setBounds(148, 332, 89, 32);
				contentPane.add(lblNewLabel_7);
				
				JButton btnRegister = new JButton("Kayıt Ol");
				btnRegister.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						char[] pwRegister1 = registerPassword_1.getPassword();
		                String pwRegister1_String = new String(pwRegister1);
		                char[] pwRegister2 = registerPassword_2.getPassword();
		                String pwRegister2_String = new String(pwRegister2);
		                String nameRegister = registerName.getText();
		                String surnameRegister = registerSurname.getText();
		                // KAYIT SIRASINDA GİRİLEN İKİ ŞİFRENİN EŞİTLİĞİNİ KONTROL ETME
		                if(!pwRegister1_String.equals(pwRegister2_String)) {
		                	
		                	final JPanel panel = new JPanel();
		                    JOptionPane.showMessageDialog(panel, "Şifre Uyuşmazlığı", "Warning",JOptionPane.WARNING_MESSAGE);
		                }
		                else {
		                	User user = new User(nameRegister, surnameRegister, pwRegister1_String,"parent");
			                fileOperations fileOps = new fileOperations();
			                try {
			                	// EBEVEYNİ SİSTEME EKLEME
								fileOps.addNewUser(nameRegister, surnameRegister, pwRegister1_String, "parent");
								final JPanel panel = new JPanel();
			                    JOptionPane.showMessageDialog(panel, "Ebeveyn Başarıyla Kaydedildi", "Warning",JOptionPane.WARNING_MESSAGE);
								EventQueue.invokeLater(new Runnable() {
									public void run() {
										try {
											mainMenu frame = new mainMenu();
											frame.setVisible(true);
										} catch (Exception e) {
											e.printStackTrace();
										}
									}
								});
								dispose();
							} catch (IOException e1) {
								e1.printStackTrace();
							}
		                }
					}
				});
				btnRegister.setFont(new Font("Calibri", Font.BOLD, 19));
				btnRegister.setBounds(235, 423, 128, 37);
				contentPane.add(btnRegister);
				
				JLabel lblNewLabel_6 = new JLabel("Şifre");
				lblNewLabel_6.setFont(new Font("Calibri", Font.BOLD, 17));
				lblNewLabel_6.setBounds(148, 264, 89, 32);
				contentPane.add(lblNewLabel_6);
				
				JLabel lblNewLabel_5 = new JLabel("Soyad");
				lblNewLabel_5.setFont(new Font("Calibri", Font.BOLD, 17));
				lblNewLabel_5.setBounds(148, 197, 89, 21);
				contentPane.add(lblNewLabel_5);
			}
			// SİSTEMDE HALİ HAZIRDA BİR EBEVEYN VARSA NORMAL GİRİŞ/KAYIT EKRANINI AÇAR
			else {
				setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				setBounds(100, 100, 1186, 727);
				contentPane = new JPanel();
				contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

				setContentPane(contentPane);
				contentPane.setLayout(null);
				
				JPanel panel = new JPanel();
				panel.setBounds(557, 10, 10, 10);
				contentPane.add(panel);
				
				loginName = new JTextField();
				loginName.setBounds(747, 155, 288, 20);
				contentPane.add(loginName);
				loginName.setColumns(10);
				
				JLabel lblNewLabel = new JLabel("Çarpım Tablosu Alıştırması");
				lblNewLabel.setFont(new Font("Calibri", Font.BOLD, 55));
				lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
				lblNewLabel.setBounds(206, 31, 729, 84);
				contentPane.add(lblNewLabel);
				
				loginSurname = new JTextField();
				loginSurname.setColumns(10);
				loginSurname.setBounds(747, 211, 288, 20);
				contentPane.add(loginSurname);
				
				registerSurname = new JTextField();
				registerSurname.setColumns(10);
				registerSurname.setBounds(85, 209, 288, 20);
				contentPane.add(registerSurname);
				
				registerName = new JTextField();
				registerName.setColumns(10);
				registerName.setBounds(85, 153, 288, 20);
				contentPane.add(registerName);
				
				lblNewLabel_3 = new JLabel("Şifre");
				lblNewLabel_3.setFont(new Font("Calibri", Font.BOLD, 17));
				lblNewLabel_3.setBounds(747, 243, 89, 21);
				contentPane.add(lblNewLabel_3);
				
				lblNewLabel_2 = new JLabel("Soyad");
				lblNewLabel_2.setFont(new Font("Calibri", Font.BOLD, 17));
				lblNewLabel_2.setBounds(747, 186, 89, 21);
				contentPane.add(lblNewLabel_2);
				
				lblNewLabel_1 = new JLabel("İsim");
				lblNewLabel_1.setFont(new Font("Calibri", Font.BOLD, 17));
				lblNewLabel_1.setBounds(747, 131, 89, 20);
				contentPane.add(lblNewLabel_1);
				
				lblNewLabel_4 = new JLabel("İsim");
				lblNewLabel_4.setFont(new Font("Calibri", Font.BOLD, 17));
				lblNewLabel_4.setBounds(85, 131, 89, 20);
				contentPane.add(lblNewLabel_4);
				
				lblNewLabel_5 = new JLabel("Soyisim");
				lblNewLabel_5.setFont(new Font("Calibri", Font.BOLD, 17));
				lblNewLabel_5.setBounds(85, 186, 89, 21);
				contentPane.add(lblNewLabel_5);
				
				lblNewLabel_6 = new JLabel("Şifre");
				lblNewLabel_6.setFont(new Font("Calibri", Font.BOLD, 17));
				lblNewLabel_6.setBounds(85, 237, 89, 32);
				contentPane.add(lblNewLabel_6);
				
				
				lblNewLabel_7 = new JLabel("Şifre Tekrar");
				lblNewLabel_7.setFont(new Font("Calibri", Font.BOLD, 17));
				lblNewLabel_7.setBounds(85, 293, 89, 32);
				contentPane.add(lblNewLabel_7);
				
				registerPassword_1 = new JPasswordField();
				registerPassword_1.setBounds(85, 320, 288, 20);
				contentPane.add(registerPassword_1);
				
				registerPassword_2 = new JPasswordField();
				registerPassword_2.setBounds(85, 262, 288, 20);
				contentPane.add(registerPassword_2);
				
				loginPassword_1 = new JPasswordField();
				loginPassword_1.setBounds(747, 262, 288, 20);
				contentPane.add(loginPassword_1);
				JRadioButton parentSelect = new JRadioButton("Ebeveyn");
				JRadioButton childSelect = new JRadioButton("Çocuk");
				childSelect.setFont(new Font("Calibri", Font.BOLD, 19));
				childSelect.setBounds(180, 351, 128, 37);
				contentPane.add(childSelect);
				// EKLENEN KULLANICININ ÇOCUK/EBEVEYN OLMASINI SEÇME
				childSelect.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						i = 1;
						parentSelect.setSelected(false);
					}
				});
				
				
				parentSelect.setFont(new Font("Calibri", Font.BOLD, 19));
				parentSelect.setBounds(80, 351, 100, 37);
				contentPane.add(parentSelect);
				// EKLENEN KULLANICININ ÇOCUK/EBEVEYN OLMASINI SEÇME
				parentSelect.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						i = 0;
						childSelect.setSelected(false);
					}
				});				
				btnRegister = new JButton("Kayıt Ol");
				btnRegister.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						char[] pwRegister1 = registerPassword_1.getPassword();
		                String pwRegister1_String = new String(pwRegister1);
		                char[] pwRegister2 = registerPassword_2.getPassword();
		                String pwRegister2_String = new String(pwRegister2);
		                String nameRegister = registerName.getText();
		                String surnameRegister = registerSurname.getText();
		                // KAYIT EKRANINDA BOŞ BIRAKILAN SATIR OLUP OLMADIĞINI KOTNROL ETME
		                if((pwRegister1_String.isBlank()) || (pwRegister2_String.isBlank()) || (nameRegister.isBlank()) || (surnameRegister.isBlank())) {
		                	final JPanel panel = new JPanel();
		                    JOptionPane.showMessageDialog(panel, "Tüm Alanları Doldurun", "Warning",JOptionPane.WARNING_MESSAGE);
		                }
		                // KAYIT SIRASINDA GİRİLEN İKİ ŞİFRENİN EŞİTLİĞİNİ KONTROL ETME
		                else if(!pwRegister1_String.equals(pwRegister2_String)) {
		                	final JPanel panel = new JPanel();
		                    JOptionPane.showMessageDialog(panel, "Şifre Uyuşmazlığı", "Warning",JOptionPane.WARNING_MESSAGE);
		                }
		                
		                else {
		                	if(i==0) {
			                	User user = new User(nameRegister, surnameRegister, pwRegister1_String,"parent");
			                	fileOperations fileOps = new fileOperations();
			                	try {
			                		// EBEVEYNİ SİSTEME KAYDETME
									fileOps.addNewUser(nameRegister, surnameRegister, pwRegister1_String, "parent");
									registerSurname.setText("");
									registerName.setText("");
									registerPassword_1.setText("");
									registerPassword_2.setText("");
									childSelect.setSelected(false);
									parentSelect.setSelected(false);
									final JPanel panel = new JPanel();
				                    JOptionPane.showMessageDialog(panel, "Ebeveyn Başarıyla Kaydedildi", "Warning",JOptionPane.WARNING_MESSAGE);
									
								} catch (IOException e1) {
									e1.printStackTrace();
								}
			                }
			                else if(i==1) {
			                	User user = new User(nameRegister, surnameRegister, pwRegister1_String,"child");
			                	fileOperations fileOps = new fileOperations();
			                	try {
			                		// ÇOCUĞU SİSTEME KAYDETME
									fileOps.addNewUser(nameRegister, surnameRegister, pwRegister1_String, "child");
									fileOps.createScoreTable();
									registerSurname.setText("");
									registerName.setText("");
									registerPassword_1.setText("");
									registerPassword_2.setText("");
									childSelect.setSelected(false);
									parentSelect.setSelected(false);
									final JPanel panel = new JPanel();
				                    JOptionPane.showMessageDialog(panel, "Çocuk Başarıyla Kaydedildi", "Warning",JOptionPane.WARNING_MESSAGE);
								} catch (IOException e1) {
									e1.printStackTrace();
								}
			                }
			                else {
			                	final JPanel panel = new JPanel();
			                	JOptionPane.showMessageDialog(panel, "Parent/Child Seçme İşlemi Yapılmadı", "Warning",JOptionPane.WARNING_MESSAGE);
			                }
		                }
		                
					}
				});
				btnRegister.setFont(new Font("Calibri", Font.BOLD, 19));
				btnRegister.setBounds(163, 424, 128, 37);
				contentPane.add(btnRegister);
				btnLogin = new JButton("Giriş Yap");
				btnLogin.addActionListener(new ActionListener() {
					// GİRİŞ YAPMA İŞLEMİ
					public void actionPerformed(ActionEvent e) {
						char[] pwLogin1 = loginPassword_1.getPassword();
		                String pwLogin1_String = new String(pwLogin1);
		                String nameLogin = loginName.getText();
		                String surnameLogin = loginSurname.getText();
		                fileOperations fileOps = new fileOperations();
		                try {
							// SİSTEMDE BÖYLE BİR KULLANICI OLUP OLMADIĞINI KONTROL ETME
		                	if(fileOps.findChild(nameLogin, surnameLogin)) {
		                		try {
		    	                	User user = fileOps.Oku(nameLogin, surnameLogin, pwLogin1_String);
		    	                	// GİRİŞ YAPACAK KULLANICININ EBEVEYN OLUP OLMADIĞINI KONTROL ETME
		    	                	if(user == null) {
		    	                		final JPanel panel = new JPanel();
					                	JOptionPane.showMessageDialog(panel, "Hatalı Şifre", "Warning",JOptionPane.WARNING_MESSAGE);
		    	                	}
		    	                	else {
		    	                		if(user.getUserType().equalsIgnoreCase("parent")) {
			    	                		dispose();
			    	                        EventQueue.invokeLater(new Runnable() {
			    	                			public void run() {
			    	                				try {
			    	                					parentPanel frame = new parentPanel(user);
			    	                					frame.setVisible(true);
			    	                				} catch (Exception e) {
			    	                					e.printStackTrace();
			    	                				}
			    	                			}
			    	                		});
			    	                	}
			    	                	// GİRİŞ YAPACAK KULLANICININ ÇOCUK OLUP OLMADIĞINI KONTROL ETME
			    	                	else if(user.getUserType().equalsIgnoreCase("child")) {
			    	                		
			    	                		dispose();
			    	                		EventQueue.invokeLater(new Runnable() {
			    	                			public void run() {
			    	                				try {
			    	                					childMenu frame = new childMenu(user);
			    	                					frame.setVisible(true);
			    	                				} catch (Exception e) {
			    	                					e.printStackTrace();
			    	                				}
			    	                			}
			    	                		});
			    	                	}
		    	                	}
		    	                	
		    	                	
		    					} catch (IOException e1) {
		    						
		    						e1.printStackTrace();
		    					}	
		                	}
		                	else {
		                		final JPanel panel = new JPanel();
		                        JOptionPane.showMessageDialog(panel, "Sistemde Böyle Bir Kullanıcı Yok", "Warning",JOptionPane.WARNING_MESSAGE);
		                	}
							
						} catch (IOException e1) {
							e1.printStackTrace();
						}
		                
		                
		                
					}
				});
				btnLogin.setFont(new Font("Calibri", Font.BOLD, 19));
				btnLogin.setBounds(836, 320, 128, 37);
				contentPane.add(btnLogin);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
}
