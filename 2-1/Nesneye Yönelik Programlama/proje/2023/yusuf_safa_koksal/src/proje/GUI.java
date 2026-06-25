package proje;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.FlowLayout;
import javax.swing.JLabel;
import java.awt.Font;

import javax.swing.ButtonGroup;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JLayeredPane;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;
import java.awt.CardLayout;
import javax.swing.JTextField;
import java.awt.Color;
import javax.swing.JToggleButton;
import javax.swing.JRadioButton;
import javax.swing.JFormattedTextField;
import javax.swing.JComboBox;
import javax.swing.JList;
import javax.swing.AbstractListModel;
import javax.swing.JScrollPane;
import javax.swing.DefaultComboBoxModel;
import javax.swing.event.ListSelectionListener;
import javax.swing.event.ListSelectionEvent;
import javax.swing.JScrollBar;
import javax.swing.JTextArea;

public class GUI extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPanel;
	private JPanel journalPanel;
	private JPanel individualPanel;
	private JPanel corparationPanel;
	private JLayeredPane layeredPane;
	private JLayeredPane paymentLayeredPane;
	private JTextField nameText;
	private JTextField issnText;
	private JTextField frequencyText;
	private JTextField issuePriceText;
	private ButtonGroup btnGroup;
	private JTextField subNameText;
	private JTextField subAdressText;
	private static Distributor distributor;
	private JPanel addSubscriberPanel;
	private JPanel addJournalPanel;
	private JPanel addSubscriptionPanel;
	private JTextField copiesText;
	private JTextField creditCardNrText;
	private JTextField cvvText;
	private JTextField bankCodeText;
	private JTextField bankNameText;
	private JTextField accountNumberText;
	private JTextField amountText;
	private JTextField amountCorpText;
	private JList journalList;
	private JList subscriberList;
	private JList subscriptionList;
	private JTextField monthReportText;
	private JTextField yearReportText;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		distributor=new Distributor();
		
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GUI frame = new GUI();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	
	public void switchPanel(JPanel panel) {
		layeredPane.removeAll();
		layeredPane.add(panel);
		layeredPane.repaint();
		layeredPane.revalidate();
	}
	
	public void switchPaymentPanel(JPanel panel) {
		paymentLayeredPane.removeAll();
		paymentLayeredPane.add(panel);
		paymentLayeredPane.repaint();
		paymentLayeredPane.revalidate();
	}
	
	public void getData() {
		distributor.loadState("data.ser");
		switchPanel(addSubscriptionPanel);
		DefaultListModel<Journal> listModelJournal=new DefaultListModel<Journal>();
		for(Journal journal:distributor.getJournals()) {
			listModelJournal.addElement(journal);
		}
		
		DefaultListModel<Subscriber> listModelSubscriber=new DefaultListModel<Subscriber>();
		for(Subscriber sub:distributor.getSubscribers()) {
			listModelSubscriber.addElement(sub);
		}

		journalList.setModel(listModelJournal);
		subscriberList.setModel(listModelSubscriber);
	}
	
	public GUI() {
		setTitle("A Journal Distribution Information System");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(370, 150, 700, 550);
		contentPanel = new JPanel();
		contentPanel.setBackground(new Color(0, 128, 255));
		journalPanel=new JPanel();
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPanel);
		contentPanel.setLayout(null);
		
		layeredPane = new JLayeredPane();
		layeredPane.setBackground(new Color(255, 255, 255));
		layeredPane.setBounds(140, 0, 546, 513);
		contentPanel.add(layeredPane);
		layeredPane.setLayout(null);
		
		addSubscriptionPanel = new JPanel();
		layeredPane.setLayer(addSubscriptionPanel, 0);
		addSubscriptionPanel.setBounds(0, -11, 546, 524);
		layeredPane.add(addSubscriptionPanel);
		addSubscriptionPanel.setLayout(null);
		
		journalList = new JList();
		journalList.setFont(new Font("Century Gothic", Font.BOLD, 17));
		journalList.setBounds(54, 113, 194, 132);
		addSubscriptionPanel.add(journalList);
		
		JLabel lblNewLabel_1 = new JLabel("Dergi seçiniz");
		lblNewLabel_1.setFont(new Font("Century Gothic", Font.BOLD, 16));
		lblNewLabel_1.setBounds(101, 76, 110, 47);
		addSubscriptionPanel.add(lblNewLabel_1);
		
		subscriberList = new JList();
		subscriberList.setFont(new Font("Century Gothic", Font.BOLD, 16));
		subscriberList.setBounds(302, 114, 194, 132);
		addSubscriptionPanel.add(subscriberList);
		
		JLabel lblNewLabel_2 = new JLabel("Abone seçiniz");
		lblNewLabel_2.setFont(new Font("Century Gothic", Font.BOLD, 16));
		lblNewLabel_2.setBounds(342, 89, 110, 21);
		addSubscriptionPanel.add(lblNewLabel_2);
		
		JLabel lblNewLabel_6 = new JLabel("Aylık dergi miktarı:");
		lblNewLabel_6.setFont(new Font("Century Gothic", Font.BOLD, 16));
		lblNewLabel_6.setBounds(54, 292, 177, 34);
		addSubscriptionPanel.add(lblNewLabel_6);
		
		JComboBox monthComboBox = new JComboBox();
		monthComboBox.setFont(new Font("Century Gothic", Font.BOLD, 16));
		monthComboBox.setModel(new DefaultComboBoxModel(new String[] {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"}));
		monthComboBox.setBounds(117, 345, 110, 34);
		addSubscriptionPanel.add(monthComboBox);
		
		copiesText = new JTextField();
		copiesText.setFont(new Font("Century Gothic", Font.BOLD, 16));
		copiesText.setBounds(214, 293, 133, 34);
		addSubscriptionPanel.add(copiesText);
		copiesText.setColumns(10);
		
		JLabel lblNewLabel_7 = new JLabel("Ay:");
		lblNewLabel_7.setFont(new Font("Century Gothic", Font.BOLD, 16));
		lblNewLabel_7.setBounds(77, 351, 59, 23);
		addSubscriptionPanel.add(lblNewLabel_7);
		
		JLabel lblNewLabel_8 = new JLabel("Yıl:");
		lblNewLabel_8.setFont(new Font("Century Gothic", Font.BOLD, 16));
		lblNewLabel_8.setBounds(277, 349, 39, 27);
		addSubscriptionPanel.add(lblNewLabel_8);
		
		JComboBox yearComboBox = new JComboBox();
		yearComboBox.setFont(new Font("Century Gothic", Font.BOLD, 16));
		yearComboBox.setModel(new DefaultComboBoxModel(new String[] {"2024", "2025", "2026", "2027", "2028", "2029", "2030", "2031", "2032"}));
		yearComboBox.setBounds(302, 345, 110, 34);
		addSubscriptionPanel.add(yearComboBox);
		
		JLabel lblNewLabel_9 = new JLabel("Not: Abonelikler 1 yıl süreyle geçerli olmaktadır.");
		lblNewLabel_9.setFont(new Font("Century Gothic", Font.BOLD, 12));
		lblNewLabel_9.setBounds(77, 388, 325, 13);
		addSubscriptionPanel.add(lblNewLabel_9);
		
		JButton addSubscriptionBtn = new JButton("Ekle");
		addSubscriptionBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					int month=Integer.parseInt((String)monthComboBox.getSelectedItem());
					int year=Integer.parseInt((String)yearComboBox.getSelectedItem());
					int copies=Integer.parseInt(copiesText.getText());
					DateInfo date=new DateInfo(month,year);
					Journal journal=(Journal)journalList.getSelectedValue();
					Subscriber sub=(Subscriber)subscriberList.getSelectedValue();
					Subscription subscription=new Subscription(date,copies,journal,sub);
					journal.addSubscription(subscription);
					distributor.saveState("data.ser");
					JOptionPane.showMessageDialog(null, "Abonelik başarıyla oluşturuldu.");
				} catch (Exception e2) {
					JOptionPane.showMessageDialog(null, "Hatalı bilgi girişi!");
				}
				
			}
		});
		addSubscriptionBtn.setBackground(new Color(0, 128, 0));
		addSubscriptionBtn.setFont(new Font("Century Gothic", Font.BOLD, 26));
		addSubscriptionBtn.setBounds(197, 437, 119, 47);
		addSubscriptionPanel.add(addSubscriptionBtn);
		
		JButton deleteJournalBtn = new JButton("Dergiyi Sil");
		deleteJournalBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Journal journal=(Journal)journalList.getSelectedValue();
				if(journal!=null && distributor.deleteJournal(journal.getIssn())) {
					JOptionPane.showMessageDialog(null, journal.getName()+" isimli dergi silindi.");
					distributor.saveState("data.ser");
					getData();
				}
				else
					JOptionPane.showMessageDialog(null, "Dergi silinirken hata oluştu.");
			}
		});
		deleteJournalBtn.setFont(new Font("Century Gothic", Font.BOLD, 15));
		deleteJournalBtn.setBounds(90, 255, 119, 21);
		addSubscriptionPanel.add(deleteJournalBtn);
		
		JButton deleteSubscriberBtn = new JButton("Aboneyi Sil");
		deleteSubscriberBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Subscriber sub=(Subscriber)subscriberList.getSelectedValue();
				if(sub!=null && distributor.deleteSubscriber(sub)) {
					JOptionPane.showMessageDialog(null, sub.getName()+" isimli abone silindi.");
					distributor.saveState("data.ser");
					getData();
				}
				else
					JOptionPane.showMessageDialog(null, "Abone silinirken hata oluştu.");
			}
		});
		deleteSubscriberBtn.setFont(new Font("Century Gothic", Font.BOLD, 15));
		deleteSubscriberBtn.setBounds(342, 256, 119, 21);
		addSubscriptionPanel.add(deleteSubscriberBtn);
		
		addJournalPanel = new JPanel();
		addJournalPanel.setBounds(0, -11, 546, 524);
		layeredPane.add(addJournalPanel);
		addJournalPanel.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Dergi Adı:");
		lblNewLabel.setFont(new Font("Century Gothic", Font.BOLD, 16));
		lblNewLabel.setBounds(121, 42, 124, 40);
		addJournalPanel.add(lblNewLabel);
		
		JLabel lblNewLabel_3 = new JLabel("ISSN Numarası: ");
		lblNewLabel_3.setFont(new Font("Century Gothic", Font.BOLD, 16));
		lblNewLabel_3.setBounds(83, 116, 124, 50);
		addJournalPanel.add(lblNewLabel_3);
		
		JLabel lblNewLabel_4 = new JLabel("Yıllık Basım Sayısı:");
		lblNewLabel_4.setFont(new Font("Century Gothic", Font.BOLD, 16));
		lblNewLabel_4.setBounds(68, 189, 145, 50);
		addJournalPanel.add(lblNewLabel_4);
		
		JLabel lblNewLabel_5 = new JLabel("Basım Fiyatı:");
		lblNewLabel_5.setFont(new Font("Century Gothic", Font.BOLD, 16));
		lblNewLabel_5.setBounds(108, 266, 124, 40);
		addJournalPanel.add(lblNewLabel_5);
		
		JButton btnNewButton = new JButton("Ekle");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					int frequency=Integer.parseInt(frequencyText.getText());
					double issuePrice=Double.parseDouble(issuePriceText.getText());
					
					Journal journal=new Journal(nameText.getText(),issnText.getText(),frequency,issuePrice);
					distributor.addJournal(journal);
					distributor.saveState("data.ser");
					
					JOptionPane.showMessageDialog(null,nameText.getText() +" dergisi başarıyla eklendi.");
					
				} catch (Exception e2) {
					JOptionPane.showMessageDialog(null, "Hatalı bilgi girişi!");
				}
			}
		});
		btnNewButton.setFont(new Font("Century", Font.BOLD, 26));
		btnNewButton.setBackground(new Color(0, 128, 0));
		btnNewButton.setForeground(new Color(0, 0, 0));
		btnNewButton.setBounds(190, 364, 145, 59);
		addJournalPanel.add(btnNewButton);
		
		nameText = new JTextField();
		nameText.setFont(new Font("Century Gothic", Font.BOLD, 16));
		nameText.setBounds(217, 46, 150, 33);
		addJournalPanel.add(nameText);
		nameText.setColumns(10);
		
		issnText = new JTextField();
		issnText.setFont(new Font("Century Gothic", Font.BOLD, 16));
		issnText.setBounds(217, 125, 150, 33);
		addJournalPanel.add(issnText);
		issnText.setColumns(10);
		
		frequencyText = new JTextField();
		frequencyText.setFont(new Font("Century Gothic", Font.BOLD, 16));
		frequencyText.setBounds(217, 198, 150, 33);
		addJournalPanel.add(frequencyText);
		frequencyText.setColumns(10);
		
		issuePriceText = new JTextField();
		issuePriceText.setFont(new Font("Century Gothic", Font.BOLD, 16));
		issuePriceText.setBounds(217, 273, 150, 33);
		addJournalPanel.add(issuePriceText);
		issuePriceText.setColumns(10);
		
		addSubscriberPanel = new JPanel();
		layeredPane.setLayer(addSubscriberPanel, 0);
		addSubscriberPanel.setBounds(0, -11, 546, 524);
		layeredPane.add(addSubscriberPanel);
		addSubscriberPanel.setLayout(null);
		
		JLabel subTypeLabel = new JLabel("Abone Türü:");
		subTypeLabel.setHorizontalAlignment(SwingConstants.RIGHT);
		subTypeLabel.setFont(new Font("Century Gothic", Font.BOLD, 16));
		subTypeLabel.setBounds(62, 68, 98, 37);
		addSubscriberPanel.add(subTypeLabel);
		
		JRadioButton rdBtnIndividual = new JRadioButton("Kişisel");
		rdBtnIndividual.setFont(new Font("Century Gothic", Font.BOLD, 16));
		rdBtnIndividual.setBounds(194, 76, 103, 21);
		addSubscriberPanel.add(rdBtnIndividual);
		
		JRadioButton rdBtnCorparation = new JRadioButton("Şirket");
		rdBtnCorparation.setFont(new Font("Century Gothic", Font.BOLD, 16));
		rdBtnCorparation.setBounds(315, 76, 103, 21);
		addSubscriberPanel.add(rdBtnCorparation);
		
		btnGroup = new ButtonGroup();
        btnGroup.add(rdBtnIndividual);
        btnGroup.add(rdBtnCorparation);
        
        JLabel nameLabel = new JLabel("İsim:");
        nameLabel.setHorizontalAlignment(SwingConstants.RIGHT);
        nameLabel.setFont(new Font("Century Gothic", Font.BOLD, 16));
        nameLabel.setBounds(73, 149, 87, 26);
        addSubscriberPanel.add(nameLabel);
        
        JLabel adressLabel = new JLabel("Adres:");
        adressLabel.setFont(new Font("Century Gothic", Font.BOLD, 16));
        adressLabel.setHorizontalAlignment(SwingConstants.RIGHT);
        adressLabel.setBounds(62, 218, 98, 26);
        addSubscriberPanel.add(adressLabel);
        
        subNameText = new JTextField();
        subNameText.setFont(new Font("Century Gothic", Font.BOLD, 16));
        subNameText.setBounds(194, 149, 136, 26);
        addSubscriberPanel.add(subNameText);
        subNameText.setColumns(10);
        
        subAdressText = new JTextField();
        subAdressText.setFont(new Font("Century Gothic", Font.BOLD, 16));
        subAdressText.setBounds(194, 218, 136, 26);
        addSubscriberPanel.add(subAdressText);
        subAdressText.setColumns(10);
        
        JButton btnNewButton_1 = new JButton("Ekle");
        btnNewButton_1.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		if(rdBtnCorparation.isSelected()) {
        			Corparation sub=new Corparation(subNameText.getText(),subAdressText.getText());
        			distributor.addSubscriber(sub);
        			JOptionPane.showMessageDialog(null,subNameText.getText()+" isimli abonelik başarıyla eklendi.");
        		}
        		else if(rdBtnIndividual.isSelected()) {
        			Individual sub=new Individual(subNameText.getText(),subAdressText.getText());
        			distributor.addSubscriber(sub);
        			JOptionPane.showMessageDialog(null,subNameText.getText()+" isimli abonelik başarıyla eklendi.");
        		}
        		else {
        			JOptionPane.showMessageDialog(null,"Lütfen bir abonelik türü seçin!");
        		}
        		distributor.saveState("data.ser");
        	}
        });
        btnNewButton_1.setBackground(new Color(0, 128, 0));
        btnNewButton_1.setFont(new Font("Century Gothic", Font.BOLD, 26));
        btnNewButton_1.setBounds(204, 356, 136, 53);
        addSubscriberPanel.add(btnNewButton_1);
        
        JPanel menuPanel = new JPanel();
        layeredPane.setLayer(menuPanel, 1);
        menuPanel.setBounds(0, 0, 546, 513);
        layeredPane.add(menuPanel);
        menuPanel.setLayout(null);
        
        monthReportText = new JTextField();
        monthReportText.setFont(new Font("Century Gothic", Font.BOLD, 16));
        monthReportText.setBounds(107, 56, 119, 28);
        menuPanel.add(monthReportText);
        monthReportText.setColumns(10);
        
        yearReportText = new JTextField();
        yearReportText.setFont(new Font("Century Gothic", Font.BOLD, 16));
        yearReportText.setBounds(311, 56, 119, 28);
        menuPanel.add(yearReportText);
        yearReportText.setColumns(10);
        
        JLabel lblNewLabel_25 = new JLabel("Ay");
        lblNewLabel_25.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_25.setBounds(151, 21, 75, 36);
        menuPanel.add(lblNewLabel_25);
        
        JLabel lblNewLabel_26 = new JLabel("Yıl");
        lblNewLabel_26.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_26.setBounds(354, 27, 66, 25);
        menuPanel.add(lblNewLabel_26);
        
        JTextArea reportText = new JTextArea();
        reportText.setFont(new Font("Century Gothic", Font.BOLD, 12));
        reportText.setBounds(40, 168, 453, 296);
        menuPanel.add(reportText);
        
        JButton btnNewButton_3 = new JButton("Report");
        btnNewButton_3.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		int month=Integer.parseInt(monthReportText.getText());
        		int year=Integer.parseInt(yearReportText.getText());
        		String result=distributor.report(month, year);
        		reportText.setText(result);
        	}
        });
        btnNewButton_3.setFont(new Font("Century Gothic", Font.BOLD, 23));
        btnNewButton_3.setBounds(205, 109, 119, 28);
        menuPanel.add(btnNewButton_3);
        
        JPanel paymentPanel = new JPanel();
        layeredPane.setLayer(paymentPanel, 0);
        paymentPanel.setBounds(0, 0, 546, 513);
        layeredPane.add(paymentPanel);
        paymentPanel.setLayout(null);
        
        JLabel lblNewLabel_10 = new JLabel("Abonelik seç");
        lblNewLabel_10.setBounds(225, 24, 103, 37);
        lblNewLabel_10.setFont(new Font("Century Gothic", Font.BOLD, 16));
        paymentPanel.add(lblNewLabel_10);
        
        subscriptionList = new JList();
        subscriptionList.addListSelectionListener(new ListSelectionListener() {
        	public void valueChanged(ListSelectionEvent e) {
        		Subscription subscription=(Subscription)subscriptionList.getSelectedValue();
        		if(subscription!=null && subscription.getSubscriber() instanceof Individual) {
        			switchPaymentPanel(individualPanel);
        		}
        		else {
        			switchPaymentPanel(corparationPanel);
        		}
        	}
        });
        
        subscriptionList.setBounds(104, 62, 349, 147);
        paymentPanel.add(subscriptionList);
        
        paymentLayeredPane = new JLayeredPane();
        paymentLayeredPane.setBounds(10, 234, 536, 279);
        paymentPanel.add(paymentLayeredPane);
        
        individualPanel = new JPanel();
        individualPanel.setBounds(0, 0, 536, 279);
        paymentLayeredPane.add(individualPanel);
        individualPanel.setLayout(null);
        
        JLabel lblNewLabel_11 = new JLabel("Kart No:");
        lblNewLabel_11.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_11.setBounds(48, 46, 62, 21);
        individualPanel.add(lblNewLabel_11);
        
        JLabel lblNewLabel_12 = new JLabel("Son Kullanım Tarihi");
        lblNewLabel_12.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_12.setBounds(48, 92, 149, 27);
        individualPanel.add(lblNewLabel_12);
        
        JLabel lblNewLabel_13 = new JLabel("CVV:");
        lblNewLabel_13.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_13.setBounds(405, 46, 40, 21);
        individualPanel.add(lblNewLabel_13);
        
        JComboBox cardYearComboBox = new JComboBox();
        cardYearComboBox.setModel(new DefaultComboBoxModel(new String[] {"24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34"}));
        cardYearComboBox.setBounds(405, 94, 50, 21);
        individualPanel.add(cardYearComboBox);
        
        JLabel lblNewLabel_14 = new JLabel("Yıl:");
        lblNewLabel_14.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_14.setBounds(375, 95, 29, 20);
        individualPanel.add(lblNewLabel_14);
        
        JLabel lblNewLabel_15 = new JLabel("Ay:");
        lblNewLabel_15.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_15.setBounds(242, 94, 26, 23);
        individualPanel.add(lblNewLabel_15);
        
        JComboBox cardMonthComboBox = new JComboBox();
        cardMonthComboBox.setModel(new DefaultComboBoxModel(new String[] {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"}));
        cardMonthComboBox.setBounds(278, 96, 50, 21);
        individualPanel.add(cardMonthComboBox);
        
        creditCardNrText = new JTextField();
        creditCardNrText.setFont(new Font("Century Gothic", Font.BOLD, 16));
        creditCardNrText.setBounds(120, 43, 236, 27);
        individualPanel.add(creditCardNrText);
        creditCardNrText.setColumns(10);
        
        cvvText = new JTextField();
        cvvText.setFont(new Font("Century Gothic", Font.BOLD, 16));
        cvvText.setBounds(446, 43, 50, 27);
        individualPanel.add(cvvText);
        cvvText.setColumns(10);
        
        JButton payBtnIndividual = new JButton("Ödeme Yap");
        payBtnIndividual.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		try {
        			int cvv=Integer.parseInt(cvvText.getText());
            		int expireMonth=Integer.parseInt((String)cardMonthComboBox.getSelectedItem());
            		int expireYear=Integer.parseInt((String)cardYearComboBox.getSelectedItem());
            		double payAmount=Double.parseDouble(amountText.getText());
            		Subscription subscription=(Subscription)subscriptionList.getSelectedValue();
            		Individual individual=(Individual)subscription.getSubscriber();
            		individual.setPaymentInfo(creditCardNrText.getText(),expireMonth , expireYear, cvv);
            		subscription.acceptPayment(payAmount);
            		JOptionPane.showMessageDialog(null,payAmount+"TL tutarında ödeme başarıyla yapıldı");
				} catch (Exception e2) {
					JOptionPane.showMessageDialog(null,"HATA! Ödeme gerçekleştirilemedi.");
				}
        	}
        });
        payBtnIndividual.setBackground(new Color(0, 128, 0));
        payBtnIndividual.setFont(new Font("Century Gothic", Font.BOLD, 25));
        payBtnIndividual.setBounds(175, 215, 190, 41);
        individualPanel.add(payBtnIndividual);
        
        JLabel lblNewLabel_23 = new JLabel("Ödenecek Tutar:");
        lblNewLabel_23.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_23.setBounds(86, 154, 130, 21);
        individualPanel.add(lblNewLabel_23);
        
        amountText = new JTextField();
        amountText.setFont(new Font("Century Gothic", Font.BOLD, 16));
        amountText.setBounds(232, 154, 96, 23);
        individualPanel.add(amountText);
        amountText.setColumns(10);
        
        corparationPanel = new JPanel();
        paymentLayeredPane.setLayer(corparationPanel, 1);
        corparationPanel.setBounds(0, 0, 536, 279);
        paymentLayeredPane.add(corparationPanel);
        corparationPanel.setLayout(null);
        
        JLabel lblNewLabel_16 = new JLabel("Banka No:");
        lblNewLabel_16.setBounds(39, 55, 82, 21);
        lblNewLabel_16.setFont(new Font("Century Gothic", Font.BOLD, 16));
        corparationPanel.add(lblNewLabel_16);
        
        bankCodeText = new JTextField();
        bankCodeText.setFont(new Font("Century Gothic", Font.BOLD, 16));
        bankCodeText.setBounds(131, 55, 207, 27);
        corparationPanel.add(bankCodeText);
        bankCodeText.setColumns(10);
        
        JLabel lblNewLabel_17 = new JLabel("Banka Adı:");
        lblNewLabel_17.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_17.setBounds(35, 10, 86, 24);
        corparationPanel.add(lblNewLabel_17);
        
        bankNameText = new JTextField();
        bankNameText.setFont(new Font("Century Gothic", Font.BOLD, 16));
        bankNameText.setBounds(131, 10, 207, 27);
        corparationPanel.add(bankNameText);
        bankNameText.setColumns(10);
        
        JLabel lblNewLabel_18 = new JLabel("Hesap No:");
        lblNewLabel_18.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_18.setBounds(39, 97, 82, 21);
        corparationPanel.add(lblNewLabel_18);
        
        accountNumberText = new JTextField();
        accountNumberText.setFont(new Font("Century Gothic", Font.BOLD, 16));
        accountNumberText.setBounds(131, 94, 207, 27);
        corparationPanel.add(accountNumberText);
        accountNumberText.setColumns(10);
        
        JLabel lblNewLabel_19 = new JLabel("Tarih:");
        lblNewLabel_19.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_19.setBounds(47, 139, 45, 13);
        corparationPanel.add(lblNewLabel_19);
        
        JLabel lblNewLabel_20 = new JLabel("Gün:");
        lblNewLabel_20.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_20.setBounds(131, 139, 45, 13);
        corparationPanel.add(lblNewLabel_20);
        
        JComboBox dayCorpComboBox = new JComboBox();
        dayCorpComboBox.setModel(new DefaultComboBoxModel(new String[] {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30"}));
        dayCorpComboBox.setFont(new Font("Century Gothic", Font.BOLD, 16));
        dayCorpComboBox.setBounds(175, 135, 45, 21);
        corparationPanel.add(dayCorpComboBox);
        
        JLabel lblNewLabel_21 = new JLabel("Ay:");
        lblNewLabel_21.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_21.setBounds(257, 131, 26, 27);
        corparationPanel.add(lblNewLabel_21);
        
        JComboBox monthCorpComboBox = new JComboBox();
        monthCorpComboBox.setModel(new DefaultComboBoxModel(new String[] {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"}));
        monthCorpComboBox.setFont(new Font("Century Gothic", Font.BOLD, 16));
        monthCorpComboBox.setBounds(293, 135, 45, 21);
        corparationPanel.add(monthCorpComboBox);
        
        JLabel lblNewLabel_22 = new JLabel("Yıl:");
        lblNewLabel_22.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_22.setBounds(372, 137, 29, 16);
        corparationPanel.add(lblNewLabel_22);
        
        JComboBox yearCorpComboBox = new JComboBox();
        yearCorpComboBox.setModel(new DefaultComboBoxModel(new String[] {"2024", "2025", "2026", "2027", "2028", "2029", "2030", "2031", "2032", "2033"}));
        yearCorpComboBox.setFont(new Font("Century Gothic", Font.BOLD, 16));
        yearCorpComboBox.setBounds(404, 135, 61, 21);
        corparationPanel.add(yearCorpComboBox);
        
        JButton payBtnCorporation = new JButton("Ödeme Yap");
        payBtnCorporation.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		try {
        			int bankCode=Integer.parseInt(bankCodeText.getText());
            		int accountNumber=Integer.parseInt((String)accountNumberText.getText());
            		int issueDay=Integer.parseInt((String)dayCorpComboBox.getSelectedItem());
            		int issueMonth=Integer.parseInt((String)monthCorpComboBox.getSelectedItem());
            		int issueYear=Integer.parseInt((String)yearCorpComboBox.getSelectedItem());
            		double payAmount=Double.parseDouble(amountCorpText.getText());
            		Subscription subscription=(Subscription)subscriptionList.getSelectedValue();
            		Corparation corparation=(Corparation)subscription.getSubscriber();
            		corparation.setPaymentInfo(bankCode,bankNameText.getText(),issueDay,issueMonth,issueYear,accountNumber);
            		subscription.acceptPayment(payAmount);
            		JOptionPane.showMessageDialog(null,payAmount+"TL tutarında ödeme başarıyla yapıldı");
				} catch (Exception e2) {
					JOptionPane.showMessageDialog(null,"HATA! Ödeme gerçekleştirilemedi.");
				}
        	}
        });
        payBtnCorporation.setFont(new Font("Century Gothic", Font.BOLD, 25));
        payBtnCorporation.setBackground(new Color(0, 128, 0));
        payBtnCorporation.setBounds(175, 215, 190, 41);
        corparationPanel.add(payBtnCorporation);
        
        JLabel lblNewLabel_24 = new JLabel("Ödenecek Tutar:");
        lblNewLabel_24.setFont(new Font("Century Gothic", Font.BOLD, 16));
        lblNewLabel_24.setBounds(39, 166, 130, 21);
        corparationPanel.add(lblNewLabel_24);
        
        amountCorpText = new JTextField();
        amountCorpText.setFont(new Font("Century Gothic", Font.BOLD, 16));
        amountCorpText.setBounds(175, 162, 108, 27);
        corparationPanel.add(amountCorpText);
        amountCorpText.setColumns(10);
		
		JButton addJournalButton = new JButton("Dergi Ekle");
		addJournalButton.setForeground(new Color(255, 255, 255));
		addJournalButton.setBackground(new Color(255, 128, 128));
		addJournalButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				switchPanel(addJournalPanel);
			}
		});
		addJournalButton.setFont(new Font("Century", Font.BOLD, 15));
		addJournalButton.setBounds(0, 293, 140, 55);
		contentPanel.add(addJournalButton);
		
		JButton addSubscriberButton = new JButton("Abone Ekle");
		addSubscriberButton.setForeground(new Color(255, 255, 255));
		addSubscriberButton.setBackground(new Color(255, 128, 128));
		addSubscriberButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				switchPanel(addSubscriberPanel);
			}
		});
		addSubscriberButton.setFont(new Font("Century", Font.BOLD, 15));
		addSubscriberButton.setBounds(0, 103, 140, 55);
		contentPanel.add(addSubscriberButton);
		
		JButton btnAboneliknOlutur = new JButton("Abonelik Ekle");
		btnAboneliknOlutur.setForeground(new Color(255, 255, 255));
		btnAboneliknOlutur.setBackground(new Color(255, 128, 128));
		btnAboneliknOlutur.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				getData();
			}
		});
		btnAboneliknOlutur.setFont(new Font("Century", Font.BOLD, 15));
		btnAboneliknOlutur.setBounds(0, 198, 140, 55);
		contentPanel.add(btnAboneliknOlutur);
		
		JButton menuButton = new JButton("Menü");
		menuButton.setForeground(new Color(255, 255, 255));
		menuButton.setBackground(new Color(255, 128, 128));
		menuButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				switchPanel(menuPanel);
			}
		});
		menuButton.setFont(new Font("Century Gothic", Font.BOLD, 15));
		menuButton.setBounds(0, 21, 140, 55);
		contentPanel.add(menuButton);
		
		JButton btnNewButton_2 = new JButton("Ödeme Yap");
		btnNewButton_2.setForeground(new Color(255, 255, 255));
		btnNewButton_2.setBackground(new Color(255, 128, 128));
		btnNewButton_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				paymentLayeredPane.removeAll();
				switchPanel(paymentPanel);
				DefaultListModel<Subscription> listModelSubscription=new DefaultListModel<Subscription>();
				for(Journal journal:distributor.getJournals()) {
					for(Subscription subscription:journal.getSubscriptions()) {
						if(subscription!=null)
							listModelSubscription.addElement(subscription);
					}
				}
				subscriptionList.setModel(listModelSubscription);
			}
		});
		btnNewButton_2.setFont(new Font("Century", Font.BOLD, 15));
		btnNewButton_2.setBounds(0, 390, 140, 55);
		contentPanel.add(btnNewButton_2);
	}
}
