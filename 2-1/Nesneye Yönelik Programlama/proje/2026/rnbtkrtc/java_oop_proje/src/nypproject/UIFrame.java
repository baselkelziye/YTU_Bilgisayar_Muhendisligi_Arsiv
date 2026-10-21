package nypproject;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.text.AttributeSet;
import javax.swing.text.BadLocationException;
import javax.swing.text.DocumentFilter;
import javax.swing.text.PlainDocument;


import javax.swing.JTable;


import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.LinkedList;
import java.awt.event.ActionEvent;
import javax.swing.SwingConstants;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JLabel;
import java.awt.CardLayout;
import java.awt.Dimension;

import javax.swing.BoxLayout;
import javax.swing.JScrollPane;
import java.awt.Component;
import java.awt.Color;
import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.Box;
import java.awt.Font;
import javax.swing.table.DefaultTableModel;

public class UIFrame extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	
	private CRS crs;
	private String path = Paths.get(System.getProperty("user.home"), "nypprojectstorage").toString(); 
	
	private JTextField doctorNameTextField;
	private JTextField doctorNatIDTextField;
	private JTextField doctorDipIDTextField;
	private JTextField patientNameTextField;
	private JTextField patientNatIDTextField;
	private JTextField sectionNameTextField;
	private JTextField sectionIDTextField;
	private JTextField hospitalNameTextField;
	private JTextField hospitalIDTextField;
	private CardLayout cardLayout;
	private JPanel mainPanel;
	private JScrollPane tableScrollPanel;
	private JButton deleteRowButton;
	private JTextField rendezvousDayTextField;
	private JTextField rendezvousMonthTextField;
	private JTextField rendezvousYearTextField;
	private JTextField rendezvousHourTextField;
	private JTextField rendezvousMinuteTextField;


	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					UIFrame frame = new UIFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}


	public UIFrame() {
		crs = new CRS(true);
		crs.loadTablesToDisk(path);
		
		this.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
		this.addWindowListener(new WindowAdapter() {
		    @Override
		    public void windowClosing(WindowEvent e) {
		        crs.saveTablesToDisk(path);
		        System.out.println("Window is closing. Running cleanup...");
		        UIFrame.this.dispose();
		        System.exit(0);
		    }
		});
		
		setBounds(100, 100, 908, 519);
		
		contentPane = new JPanel();
		setContentPane(contentPane);
		contentPane.setLayout(new BoxLayout(contentPane, BoxLayout.X_AXIS));
		
		Component horizontalStrut = Box.createHorizontalStrut(10);
		contentPane.add(horizontalStrut);
		
		mainPanel = new JPanel();
		contentPane.add(mainPanel);
		cardLayout = new CardLayout(0, 0);
		mainPanel.setLayout(cardLayout);
		
		JPanel infoPanel = new JPanel();
		mainPanel.add(infoPanel, "infoPanel");
		infoPanel.setLayout(new BoxLayout(infoPanel, BoxLayout.Y_AXIS));
		
		Component infoVerticalStrut = Box.createVerticalStrut(20);
		infoVerticalStrut.setPreferredSize(new Dimension(0, 10));
		infoVerticalStrut.setMinimumSize(new Dimension(0, 10));
		infoVerticalStrut.setMaximumSize(new Dimension(32767, 10));
		infoPanel.add(infoVerticalStrut);
		
		JLabel infoLabel = new JLabel("Welcome to the CRS app:");
		infoLabel.setFont(new Font("Tahoma", Font.PLAIN, 14));
		infoPanel.add(infoLabel);
		
		Component infoVerticalStrut2 = Box.createVerticalStrut(20);
		infoVerticalStrut2.setPreferredSize(new Dimension(0, 10));
		infoVerticalStrut2.setMinimumSize(new Dimension(0, 10));
		infoVerticalStrut2.setMaximumSize(new Dimension(32767, 10));
		infoPanel.add(infoVerticalStrut2);
		
		JLabel infoLabel2 = new JLabel("Info about implementation:");
		infoLabel2.setFont(new Font("Tahoma", Font.PLAIN, 13));
		infoPanel.add(infoLabel2);
		
		Component infoVerticalStrut3 = Box.createVerticalStrut(20);
		infoVerticalStrut3.setPreferredSize(new Dimension(0, 10));
		infoVerticalStrut3.setMinimumSize(new Dimension(0, 10));
		infoVerticalStrut3.setMaximumSize(new Dimension(32767, 10));
		infoPanel.add(infoVerticalStrut3);
		
		JLabel infoLabel3 = new JLabel("-A person cannot share a national id with another person(doctor or patient).\r\n");
		infoPanel.add(infoLabel3);
		
		JLabel infoLabel4 = new JLabel("-A doctor cannot share a diploma id with another doctor.");
		infoPanel.add(infoLabel4);
		
		JLabel infoLabel5 = new JLabel("-Two sections in the same hospital cannot share the same ID.");
		infoPanel.add(infoLabel5);
		
		JLabel infoLabel6 = new JLabel("-At most 3 rendezvous can be made with the same doctor on a single day.");
		infoPanel.add(infoLabel6);
		
		JPanel addDoctorPanel = new JPanel();
		addDoctorPanel.setAlignmentX(Component.LEFT_ALIGNMENT);
		addDoctorPanel.setAlignmentY(Component.TOP_ALIGNMENT);
		mainPanel.add(addDoctorPanel, "addDoctorPanel");
		addDoctorPanel.setLayout(new BoxLayout(addDoctorPanel, BoxLayout.Y_AXIS));
		
		Component doctorVerticalStrut = Box.createVerticalStrut(20);
		addDoctorPanel.add(doctorVerticalStrut);
		
		JLabel addDoctorLabel = new JLabel("Add Doctor:");
		addDoctorLabel.setFont(new Font("Tahoma", Font.PLAIN, 14));
		addDoctorPanel.add(addDoctorLabel);
		
		Component doctorVerticalStrut2 = Box.createVerticalStrut(20);
		doctorVerticalStrut2.setMaximumSize(new Dimension(32767, 10));
		doctorVerticalStrut2.setPreferredSize(new Dimension(0, 10));
		doctorVerticalStrut2.setMinimumSize(new Dimension(0, 10));
		addDoctorPanel.add(doctorVerticalStrut2);
		
		JLabel doctorErrorLabel = new JLabel("");
		doctorErrorLabel.setForeground(Color.RED);
		addDoctorPanel.add(doctorErrorLabel);
		
		JLabel doctorLabel = new JLabel("Name:");
		addDoctorPanel.add(doctorLabel);
		
		doctorNameTextField = new JTextField();
		setOnlyAlphabeticFilter(doctorNameTextField, 50);
		doctorNameTextField.setMaximumSize(new Dimension(300, 20));
		doctorNameTextField.setAlignmentX(Component.LEFT_ALIGNMENT);
		doctorNameTextField.setColumns(10);
		addDoctorPanel.add(doctorNameTextField);
		
		JLabel doctorLabel2 = new JLabel("National ID:");
		addDoctorPanel.add(doctorLabel2);
		
		doctorNatIDTextField = new JTextField();
		setOnlyDigitsFilter(doctorNatIDTextField, 12);
		doctorNatIDTextField.setMaximumSize(new Dimension(300, 20));
		doctorNatIDTextField.setAlignmentX(Component.LEFT_ALIGNMENT);
		doctorNatIDTextField.setColumns(10);
		addDoctorPanel.add(doctorNatIDTextField);
		
		JLabel doctorLabel3 = new JLabel("Diploma ID:");
		addDoctorPanel.add(doctorLabel3);
		
		doctorDipIDTextField = new JTextField();
		setOnlyDigitsFilter(doctorDipIDTextField, 9);
		doctorDipIDTextField.setAlignmentX(Component.LEFT_ALIGNMENT);
		doctorDipIDTextField.setMaximumSize(new Dimension(300, 20));
		doctorDipIDTextField.setColumns(10);
		addDoctorPanel.add(doctorDipIDTextField);
		
		JLabel doctorLabel4 = new JLabel("Section:");
		addDoctorPanel.add(doctorLabel4);
		
		JComboBox<String> doctorSectionComboBox = new JComboBox<String>();
		doctorSectionComboBox.setAlignmentX(Component.LEFT_ALIGNMENT);
		doctorSectionComboBox.setMaximumSize(new Dimension(300, 20));
		addDoctorPanel.add(doctorSectionComboBox);
		
		Component doctorVerticalStrut3 = Box.createVerticalStrut(20);
		addDoctorPanel.add(doctorVerticalStrut3);
		
		JButton createDoctorButton = new JButton("Add");
		createDoctorButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//aynı diploma numarasına sahip iki doktor bulunamaz
				doctorErrorLabel.setForeground(Color.RED);
				String name = doctorNameTextField.getText();
				String natID = doctorNatIDTextField.getText();
				String dipID = doctorDipIDTextField.getText();
				Object sectionObject = doctorSectionComboBox.getSelectedItem();
				Section section;
				
				if(name.isEmpty() || name.startsWith(" ")){
					doctorErrorLabel.setText("Invalid name!");
					return;
				}
				if(natID.isEmpty()) {
					doctorErrorLabel.setText("Invalid national ID!");
					return;
				}
				if(dipID.isEmpty()) {
					doctorErrorLabel.setText("Invalid diploma ID!");
				}
				if(sectionObject == null || !(sectionObject instanceof String)) {
					doctorErrorLabel.setText("Please select a valid section!");
					return;
				}
				if(!crs.searchDipIDInDoctors(Integer.parseInt(dipID))) {
					doctorErrorLabel.setText("A doctor with this diploma id already exists!");
					return;
				}
				else {
					String sectionText = (String)(sectionObject);
					int locationOfFirstSeperator = sectionText.indexOf("-");
					int locationOfSecondSeperator = sectionText.indexOf("-",locationOfFirstSeperator+1);
					int sectionID = Integer.parseInt(sectionText.substring(locationOfFirstSeperator+1,locationOfSecondSeperator));
					int hospitalID = Integer.parseInt(sectionText.substring(locationOfSecondSeperator+1));
					section = crs.getHospital(hospitalID).getSection(sectionID);
				}
				// aynı diploma numaralı doktorları önceden kontrol ettiğim için burada
				// bir daha kontrol etmeye gerek yok
				Doctor doctor = new Doctor(name,Long.parseLong(natID),Integer.parseInt(dipID));
				section.addDoctor(doctor);
				doctor.setSection(section);
				doctorNameTextField.setText("");
				doctorNatIDTextField.setText("");
				doctorDipIDTextField.setText("");
				doctorErrorLabel.setForeground(Color.GREEN);
				doctorErrorLabel.setText("Doctor successfully added!");
			}
		});
		addDoctorPanel.add(createDoctorButton);
		
		JPanel addPatientPanel = new JPanel();
		mainPanel.add(addPatientPanel, "addPatientPanel");
		addPatientPanel.setLayout(new BoxLayout(addPatientPanel, BoxLayout.Y_AXIS));
		
		Component patientVerticalStrut = Box.createVerticalStrut(20);
		addPatientPanel.add(patientVerticalStrut);
		
		JLabel addPatientLabel = new JLabel("Add Patient:");
		addPatientLabel.setFont(new Font("Tahoma", Font.PLAIN, 14));
		addPatientPanel.add(addPatientLabel);
		
		Component patientVerticalStrut2 = Box.createVerticalStrut(20);
		patientVerticalStrut2.setPreferredSize(new Dimension(0, 10));
		patientVerticalStrut2.setMinimumSize(new Dimension(0, 10));
		patientVerticalStrut2.setMaximumSize(new Dimension(32767, 10));
		addPatientPanel.add(patientVerticalStrut2);
		
		JLabel patientErrorLabel = new JLabel("");
		patientErrorLabel.setForeground(Color.RED);
		addPatientPanel.add(patientErrorLabel);
		
		JLabel patientLabel = new JLabel("Name:");
		addPatientPanel.add(patientLabel);
		
		patientNameTextField = new JTextField();
		patientNameTextField.setMaximumSize(new Dimension(300, 20));
		patientNameTextField.setColumns(10);
		patientNameTextField.setAlignmentX(0.0f);
		setOnlyAlphabeticFilter(patientNameTextField, 50);
		addPatientPanel.add(patientNameTextField);
		
		JLabel patientLabel2 = new JLabel("National ID:");
		addPatientPanel.add(patientLabel2);
		
		patientNatIDTextField = new JTextField();
		patientNatIDTextField.setMaximumSize(new Dimension(300, 20));
		patientNatIDTextField.setColumns(10);
		patientNatIDTextField.setAlignmentX(0.0f);
		setOnlyDigitsFilter(patientNatIDTextField, 12);
		addPatientPanel.add(patientNatIDTextField);
		
		Component patientVerticalStrut3 = Box.createVerticalStrut(20);
		addPatientPanel.add(patientVerticalStrut3);
		
		JButton createPatientButton = new JButton("Add");
		createPatientButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				patientErrorLabel.setForeground(Color.RED);
				String name = patientNameTextField.getText();
				String natID = patientNatIDTextField.getText();
				
				if(name.isEmpty() || name.startsWith(" ")){
					patientErrorLabel.setText("Invalid name!");
					return;
				}
				if(natID.isEmpty()) {
					patientErrorLabel.setText("Invalid ID!");
					return;
				}
				Patient patient = new Patient(name,Long.parseLong(natID));
				if(crs.addPatient(patient)) {
					patientNameTextField.setText("");
					patientNatIDTextField.setText("");
					patientErrorLabel.setForeground(Color.GREEN);
					patientErrorLabel.setText("Patient successfully added!");
				}
				else {
					patientErrorLabel.setText("A person with this national id already exists!");
				}
				// patientNatIDTextField.getText()'in integer yapılabilinmesinin kontrolüne
				// gerek yok çünkü bu durum setOnlyDigitsFilter ile zaten sağlanıyor
			}
		});
		addPatientPanel.add(createPatientButton);
		
		JPanel addSectionPanel = new JPanel();
		mainPanel.add(addSectionPanel, "addSectionPanel");
		addSectionPanel.setLayout(new BoxLayout(addSectionPanel, BoxLayout.Y_AXIS));
		
		Component sectionVerticalStrut = Box.createVerticalStrut(20);
		addSectionPanel.add(sectionVerticalStrut);
		
		JLabel addSectionLabel = new JLabel("Add Section:");
		addSectionLabel.setFont(new Font("Tahoma", Font.PLAIN, 14));
		addSectionPanel.add(addSectionLabel);
		
		Component sectionVerticalStrut2 = Box.createVerticalStrut(20);
		sectionVerticalStrut2.setPreferredSize(new Dimension(0, 10));
		sectionVerticalStrut2.setMinimumSize(new Dimension(0, 10));
		sectionVerticalStrut2.setMaximumSize(new Dimension(32767, 10));
		addSectionPanel.add(sectionVerticalStrut2);
		
		JLabel sectionErrorLabel = new JLabel("");
		sectionErrorLabel.setForeground(Color.RED);
		addSectionPanel.add(sectionErrorLabel);
		
		JLabel addSectionLabel2 = new JLabel("Name:");
		addSectionPanel.add(addSectionLabel2);
		
		sectionNameTextField = new JTextField();
		setOnlyAlphabeticFilter(sectionNameTextField, 50);
		sectionNameTextField.setMaximumSize(new Dimension(300, 20));
		sectionNameTextField.setColumns(10);
		sectionNameTextField.setAlignmentX(0.0f);
		addSectionPanel.add(sectionNameTextField);
		
		JLabel addSectionLabel3 = new JLabel("ID:");
		addSectionPanel.add(addSectionLabel3);
		
		sectionIDTextField = new JTextField();
		setOnlyDigitsFilter(sectionIDTextField, 9);
		sectionIDTextField.setMaximumSize(new Dimension(300, 20));
		sectionIDTextField.setColumns(10);
		sectionIDTextField.setAlignmentX(0.0f);
		addSectionPanel.add(sectionIDTextField);
		
		JLabel addSectionLabel4 = new JLabel("Hospital:");
		addSectionPanel.add(addSectionLabel4);
		
		JComboBox<String> sectionHospitalComboBox = new JComboBox<String>();
		sectionHospitalComboBox.setMaximumSize(new Dimension(300, 20));
		sectionHospitalComboBox.setAlignmentX(0.0f);
		addSectionPanel.add(sectionHospitalComboBox);
		
		Component sectionVerticalStrut3 = Box.createVerticalStrut(20);
		addSectionPanel.add(sectionVerticalStrut3);
		
		JButton createSectionButton = new JButton("Add");
		createSectionButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				sectionErrorLabel.setForeground(Color.RED);
				String name = sectionNameTextField.getText();
				String id = sectionIDTextField.getText();
				Object hospitalObject = sectionHospitalComboBox.getSelectedItem();
				Hospital hospital;
				
				if(name.isEmpty() || name.startsWith(" ")){
					sectionErrorLabel.setText("Invalid name!");
					return;
				}
				if(id.isEmpty()) {
					sectionErrorLabel.setText("Invalid ID!");
					return;
				}
				if(hospitalObject == null || !(hospitalObject instanceof String)) {
					sectionErrorLabel.setText("Please select a valid hospital!");
					return;
				}
				else {
					String hospitalText = (String)(hospitalObject);
					int hospitalID = Integer.parseInt(hospitalText.substring(hospitalText.indexOf("-")+1));
					hospital = crs.getHospital(hospitalID);
				}
				
				//UMLde addSection void döndürdüğü için ondan output alamıyorum. Bu yüzden
				//manuel olarak addSection'da kontrol edilecek olmasına rağmen bir daha
				//kontrol yapıyorum
				
				//farklı iki hastanede aynı idli sectionlar bulunabilir
				if(hospital != null) {
					if(hospital.getSection(Integer.parseInt(id)) == null) {
						Section section = new Section(Integer.parseInt(id),name);
						section.setHospital(hospital);
						hospital.addSection(section);
						sectionNameTextField.setText("");
						sectionIDTextField.setText("");
						sectionErrorLabel.setForeground(Color.GREEN);
						sectionErrorLabel.setText("Section successfully added!");
					}
					else {
						sectionErrorLabel.setText("A section with this id already exists!");
					}
				}
				else {
					sectionErrorLabel.setText("An unexpected error occoured.");
				}
			}
		});
		addSectionPanel.add(createSectionButton);
		
		JPanel addHospitalPanel = new JPanel();
		mainPanel.add(addHospitalPanel, "addHospitalPanel");
		addHospitalPanel.setLayout(new BoxLayout(addHospitalPanel, BoxLayout.Y_AXIS));
		
		Component hospitalVerticalStrut = Box.createVerticalStrut(20);
		addHospitalPanel.add(hospitalVerticalStrut);
		
		JLabel addHospitalLabel = new JLabel("Add Hospital:");
		addHospitalLabel.setFont(new Font("Tahoma", Font.PLAIN, 14));
		addHospitalPanel.add(addHospitalLabel);
		
		Component hospitalVerticalStrut2 = Box.createVerticalStrut(20);
		hospitalVerticalStrut2.setPreferredSize(new Dimension(0, 10));
		hospitalVerticalStrut2.setMinimumSize(new Dimension(0, 10));
		hospitalVerticalStrut2.setMaximumSize(new Dimension(32767, 10));
		addHospitalPanel.add(hospitalVerticalStrut2);
		
		JLabel hospitalErrorLabel = new JLabel("");
		hospitalErrorLabel.setForeground(Color.RED);
		addHospitalPanel.add(hospitalErrorLabel);
		
		JLabel hospitalLabel = new JLabel("Name:");
		addHospitalPanel.add(hospitalLabel);
		
		hospitalNameTextField = new JTextField();
		setOnlyAlphabeticFilter(hospitalNameTextField,50);
		hospitalNameTextField.setMaximumSize(new Dimension(300, 20));
		hospitalNameTextField.setColumns(10);
		hospitalNameTextField.setAlignmentX(0.0f);
		addHospitalPanel.add(hospitalNameTextField);
		
		JLabel hospitalLabel2 = new JLabel("ID:");
		addHospitalPanel.add(hospitalLabel2);
		
		hospitalIDTextField = new JTextField();
		setOnlyDigitsFilter(hospitalIDTextField,9);
		hospitalIDTextField.setMaximumSize(new Dimension(300, 20));
		hospitalIDTextField.setColumns(10);
		hospitalIDTextField.setAlignmentX(0.0f);
		addHospitalPanel.add(hospitalIDTextField);
		
		Component hospitalVerticalStrut3 = Box.createVerticalStrut(20);
		addHospitalPanel.add(hospitalVerticalStrut3);
		
		JButton createHospitalButton = new JButton("Add");
		createHospitalButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				hospitalErrorLabel.setForeground(Color.RED);
				String name = hospitalNameTextField.getText();
				String id = hospitalIDTextField.getText();
				
				if(name.isEmpty() || name.startsWith(" ")){
					hospitalErrorLabel.setText("Invalid name!");
					return;
				}
				if(id.isEmpty()) {
					hospitalErrorLabel.setText("Invalid ID!");
					return;
				}
				Hospital hospital = new Hospital(Integer.parseInt(id),name);
				if(crs.addHospital(hospital)) {
					hospitalNameTextField.setText("");
					hospitalIDTextField.setText("");
					hospitalErrorLabel.setForeground(Color.GREEN);
					hospitalErrorLabel.setText("Hospital successfully added!");
				}
				else {
					hospitalErrorLabel.setText("A hospital with this id already exists!");
				}
			}
		});
		addHospitalPanel.add(createHospitalButton);
		
		JPanel addRendezvousPanel = new JPanel();
		mainPanel.add(addRendezvousPanel, "addRendezvousPanel");
		addRendezvousPanel.setLayout(new BoxLayout(addRendezvousPanel, BoxLayout.Y_AXIS));
		
		Component rendezvousVerticalStrut = Box.createVerticalStrut(20);
		addRendezvousPanel.add(rendezvousVerticalStrut);
		
		JLabel addRendezvousLabel = new JLabel("Add Rendezvous:");
		addRendezvousLabel.setFont(new Font("Tahoma", Font.PLAIN, 14));
		addRendezvousPanel.add(addRendezvousLabel);
		
		Component rendezvousVerticalStrut2 = Box.createVerticalStrut(20);
		rendezvousVerticalStrut2.setPreferredSize(new Dimension(0, 10));
		rendezvousVerticalStrut2.setMinimumSize(new Dimension(0, 10));
		rendezvousVerticalStrut2.setMaximumSize(new Dimension(32767, 10));
		addRendezvousPanel.add(rendezvousVerticalStrut2);
		
		JLabel rendezvousErrorLabel = new JLabel("");
		rendezvousErrorLabel.setForeground(Color.RED);
		addRendezvousPanel.add(rendezvousErrorLabel);
		
		JLabel rendezvousLabel = new JLabel("Patient:");
		addRendezvousPanel.add(rendezvousLabel);
		
		JComboBox<String> rendezvousPatientComboBox = new JComboBox<String>();
		rendezvousPatientComboBox.setMaximumSize(new Dimension(300, 20));
		rendezvousPatientComboBox.setAlignmentX(0.0f);
		addRendezvousPanel.add(rendezvousPatientComboBox);
		
		JLabel rendezvousLabel2 = new JLabel("Doctor:");
		addRendezvousPanel.add(rendezvousLabel2);
		
		JComboBox<String> rendezvousDoctorComboBox = new JComboBox<String>();
		rendezvousDoctorComboBox.setMaximumSize(new Dimension(300, 20));
		rendezvousDoctorComboBox.setAlignmentX(0.0f);
		addRendezvousPanel.add(rendezvousDoctorComboBox);
		
		JLabel rendezvousLabel3 = new JLabel("Date: (dd-mm-yyyy/hh:mm)");
		addRendezvousPanel.add(rendezvousLabel3);
		
		JPanel datePanel = new JPanel();
		datePanel.setAlignmentX(Component.LEFT_ALIGNMENT);
		datePanel.setMaximumSize(new Dimension(300, 20));
		addRendezvousPanel.add(datePanel);
		datePanel.setLayout(new BoxLayout(datePanel, BoxLayout.X_AXIS));
		
		rendezvousDayTextField = new JTextField();
		rendezvousDayTextField.setHorizontalAlignment(SwingConstants.CENTER);
		setOnlyDigitsFilter(rendezvousDayTextField, 2);
		datePanel.add(rendezvousDayTextField);
		rendezvousDayTextField.setColumns(2);
		
		JLabel dateLabel = new JLabel("-");
		datePanel.add(dateLabel);
		
		rendezvousMonthTextField = new JTextField();
		rendezvousMonthTextField.setHorizontalAlignment(SwingConstants.CENTER);
		setOnlyDigitsFilter(rendezvousMonthTextField, 2);
		datePanel.add(rendezvousMonthTextField);
		rendezvousMonthTextField.setColumns(2);
		
		JLabel dateLabel2 = new JLabel("-");
		datePanel.add(dateLabel2);
		
		rendezvousYearTextField = new JTextField();
		rendezvousYearTextField.setHorizontalAlignment(SwingConstants.CENTER);
		setOnlyDigitsFilter(rendezvousYearTextField, 4);
		datePanel.add(rendezvousYearTextField);
		rendezvousYearTextField.setColumns(4);
		
		JLabel dateLabel3 = new JLabel("/");
		datePanel.add(dateLabel3);
		
		rendezvousHourTextField = new JTextField();
		rendezvousHourTextField.setHorizontalAlignment(SwingConstants.CENTER);
		setOnlyDigitsFilter(rendezvousHourTextField, 2);
		datePanel.add(rendezvousHourTextField);
		rendezvousHourTextField.setColumns(2);
		
		JLabel dateLabel4 = new JLabel(":");
		datePanel.add(dateLabel4);
		
		rendezvousMinuteTextField = new JTextField();
		rendezvousMinuteTextField.setHorizontalAlignment(SwingConstants.CENTER);
		setOnlyDigitsFilter(rendezvousMinuteTextField, 2);
		datePanel.add(rendezvousMinuteTextField);
		rendezvousMinuteTextField.setColumns(2);

		Component rendezvousVerticalStrut3 = Box.createVerticalStrut(20);
		addRendezvousPanel.add(rendezvousVerticalStrut3);
		
		JButton createRendezvousButton = new JButton("Add");
		createRendezvousButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rendezvousErrorLabel.setForeground(Color.RED);
				Object patientObject = rendezvousPatientComboBox.getSelectedItem();
				Object doctorObject = rendezvousDoctorComboBox.getSelectedItem();
				String dayStr = rendezvousDayTextField.getText();
				String monthStr = rendezvousMonthTextField.getText();
				String yearStr = rendezvousYearTextField.getText();
				String hourStr = rendezvousHourTextField.getText();
				String minuteStr = rendezvousMinuteTextField.getText();
				if(patientObject == null || !(patientObject instanceof String)) {
					rendezvousErrorLabel.setText("Please select a valid patient!");
					return;
				}
				if(doctorObject == null || !(doctorObject instanceof String)) {
					rendezvousErrorLabel.setText("Please select a valid doctor!");
					return;
				}
				if(dayStr.isEmpty()) {
					rendezvousErrorLabel.setText("Please select a day!");
					return;
				}
				if(monthStr.isEmpty()) {
					rendezvousErrorLabel.setText("Please select a month!");
					return;
				}
				if(yearStr.isEmpty()) {
					rendezvousErrorLabel.setText("Please select a year!");
					return;
				}
				if(hourStr.isEmpty()) {
					rendezvousErrorLabel.setText("Please select an hour!");
					return;
				}
				if(minuteStr.isEmpty()) {
					rendezvousErrorLabel.setText("Please select a minute!");
					return;
				}
				int day = Integer.parseInt(dayStr);
				int month = Integer.parseInt(monthStr);
				int year = Integer.parseInt(yearStr);
				int hour = Integer.parseInt(hourStr);
				int minute = Integer.parseInt(minuteStr);
				
				if(!isValidDate(year,month,day)) {
					rendezvousErrorLabel.setText("Invalid day!");
					return;
				}
				if(!(0 < month && month < 13)) {
					rendezvousErrorLabel.setText("Invalid month!");
					return;
				}
				if(!(0 <= hour && hour < 24)) {
					rendezvousErrorLabel.setText("Invalid hour!");
					return;
				}
				if(!(0 <= minute && minute < 60)) {
					rendezvousErrorLabel.setText("Invalid minute!");
					return;
				}
				
				Calendar calendar = Calendar.getInstance();
		        calendar.set(year, month, day, hour, minute, 0);
		        Date date = calendar.getTime();
		        String patientStr = (String)patientObject;
		        String doctorStr = (String)doctorObject;
		        long patientNatID = Long.parseLong(patientStr.substring(patientStr.indexOf("-")+1));
		        int doctorDipID = Integer.parseInt(doctorStr.substring(doctorStr.indexOf("-",doctorStr.indexOf("-")+1)+1));
		        Doctor doctor = crs.getDoctor(doctorDipID);
		        
		        if(doctor != null) {
		        	if(crs.makeRandezvous(patientNatID,doctor.getSection().getHospital().getID() , doctor.getSection().getID(), doctorDipID, date)) {
		        		clearRendezvousDateFields();
		        		rendezvousErrorLabel.setForeground(Color.GREEN);
			        	rendezvousErrorLabel.setText("Rendezvous succesfully added!");
		        	}
		        	else {
		        		rendezvousErrorLabel.setText("Maximum rendezvous limit for "
		        				+ "the chosen day is already met. Please choose a different day!");
		        	}
		        }
		        else {
		        	System.out.println(doctorDipID);
		        	
		        }
			}
		});
		addRendezvousPanel.add(createRendezvousButton);
		
		JPanel showTablePanel = new JPanel();
		mainPanel.add(showTablePanel, "showTablePanel");
		showTablePanel.setLayout(new BoxLayout(showTablePanel, BoxLayout.Y_AXIS));
		
		tableScrollPanel = new JScrollPane();
		showTablePanel.add(tableScrollPanel);
		
		
		JPanel panel = new JPanel();
		panel.setMaximumSize(new Dimension(32767, 100));
		showTablePanel.add(panel);
		
		deleteRowButton = new JButton("Delete Selected Row");
		panel.add(deleteRowButton);
		
		JLabel deleteRowLabel = new JLabel("Please click on a row to select it");
		panel.add(deleteRowLabel);

		JPanel sidePanel = new JPanel();
		
        sidePanel.setPreferredSize(new Dimension(120, 50));
        sidePanel.setMaximumSize(new Dimension(120, Short.MAX_VALUE));
        
		contentPane.add(sidePanel);
		
		JButton addHospitalButton = new JButton("Add Hospital");
		addHospitalButton.setForeground(Color.BLACK);
		addHospitalButton.setPreferredSize(new Dimension(150, 25));
		addHospitalButton.setMaximumSize(new Dimension(150, Short.MAX_VALUE));
		
		addHospitalButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				cardLayout.show(mainPanel, "addHospitalPanel");
			}
		});
		sidePanel.add(addHospitalButton);
		
		JButton addSectionButton = new JButton("Add Section");
		addSectionButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				sectionHospitalComboBox.removeAllItems();
				for(Hospital hospital : crs.getHospitals()) {
					sectionHospitalComboBox.addItem(hospital.toString());
				}
				cardLayout.show(mainPanel, "addSectionPanel");
			}
		});
		addSectionButton.setPreferredSize(new Dimension(150, 25));
		addSectionButton.setMaximumSize(new Dimension(150, Short.MAX_VALUE));
		
		sidePanel.add(addSectionButton);
		
		JButton addDoctorButton = new JButton("Add Doctor");
		addDoctorButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				doctorSectionComboBox.removeAllItems();
				for(Hospital hospital : crs.getHospitals()) {
					for(Section section:hospital.getSections()) {
						doctorSectionComboBox.addItem(section.toString());
					}
				}
				cardLayout.show(mainPanel, "addDoctorPanel");
			}
		});
		addDoctorButton.setPreferredSize(new Dimension(150, 25));
		addDoctorButton.setMaximumSize(new Dimension(150, Short.MAX_VALUE));
		
		sidePanel.add(addDoctorButton);
		
		JButton addPatientButton = new JButton("Add Patient");
		addPatientButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				cardLayout.show(mainPanel, "addPatientPanel");
			}
		});
		addPatientButton.setPreferredSize(new Dimension(150, 25));
		addPatientButton.setMaximumSize(new Dimension(150, Short.MAX_VALUE));
		
		sidePanel.add(addPatientButton);
		
		JButton addRendezvousButton = new JButton("Add Rendezvous");
		addRendezvousButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rendezvousDoctorComboBox.removeAllItems();
				for(Hospital hospital : crs.getHospitals()) {
					for(Section section:hospital.getSections()) {
						for(Doctor doctor:section.getDoctors()) {
							rendezvousDoctorComboBox.addItem(doctor.toString());
						}
					}
				}
				rendezvousPatientComboBox.removeAllItems();
				for(Patient patient : crs.getPatients()) {
					rendezvousPatientComboBox.addItem(patient.toString());
				}
				cardLayout.show(mainPanel, "addRendezvousPanel");
			}
		});
		addRendezvousButton.setPreferredSize(new Dimension(150, 25));
		addRendezvousButton.setMaximumSize(new Dimension(150, Short.MAX_VALUE));
		sidePanel.add(addRendezvousButton);
		
		JButton resetButton = new JButton("Delete Eveything");
		resetButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
                int result = JOptionPane.showConfirmDialog(null,
                        "Are you sure you want to delete everything? \nThis will remove every doctor"
                        + ", section, hospital etc.",
                        "Confirmation",
                        JOptionPane.YES_NO_OPTION);
                if(result == JOptionPane.YES_OPTION) {
                	crs.resetEverything();
                	cardLayout.show(mainPanel, "infoPanel");
                }
			}
		});
		sidePanel.add(resetButton);
		
		JMenuBar menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		
		JButton showHospitalsButton = new JButton("Hospitals");
		showHospitalsButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tableScrollPanel.getViewport().removeAll(); 
				String[] collumns = {"Name","ID","Sections"};
				ArrayList<Hospital> hospitals = crs.getHospitals();
				Object[][] data = new Object[hospitals.size()][3];
				System.out.print(hospitals.size());
				for (int i = 0; i < hospitals.size(); i++) 
				{
					Hospital hospital = hospitals.get(i);
					data[i][0] = hospital.getName();
					data[i][1] = hospital.getID();
					String sectionsString = "";
					LinkedList<Section> sections = hospital.getSections();
					if(hospital.getSections().isEmpty()) 
					{
						sectionsString = "none";
					}
					else 
					{
						for (int j = 0; j < sections.size(); j++) 
						{
							Section section = sections.get(j);
							sectionsString += section.getName();
							if (j < sections.size() - 1) 
							{
								sectionsString += ", ";
							}
						} 
					}
					data[i][2] = sectionsString;
				}
				DefaultTableModel model = new DefaultTableModel(data,collumns);
				JTable table = new JTable(model);
				tableScrollPanel.setViewportView(table);
				table.setDefaultEditor(Object.class, null);
				tableScrollPanel.revalidate();
				tableScrollPanel.repaint();
				
                for (ActionListener listener : deleteRowButton.getActionListeners()) {
                    deleteRowButton.removeActionListener(listener);
                }
				deleteRowButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						int selectedRow = table.getSelectedRow();
						if(selectedRow != -1) {
							Object value = table.getValueAt(selectedRow, 1);
							if(value instanceof Integer) {
								crs.removeHospital((int)(value));
								model.removeRow(selectedRow);
							}
						}
					}
				});
				cardLayout.show(mainPanel,"showTablePanel");
			}
		});
		menuBar.add(showHospitalsButton);
		
		JButton showPatientsButton = new JButton("Patients");
		showPatientsButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tableScrollPanel.getViewport().removeAll(); 
				String[] collumns = {"Name","National ID"};
				ArrayList<Patient> patients = crs.getPatients();
				Object[][] data = new Object[patients.size()][2];
				System.out.print(patients.size());
				for (int i = 0; i < patients.size(); i++) 
				{
					Patient patient = patients.get(i);
					data[i][0] = patient.getName();
					data[i][1] = patient.getNationalID();
				}
				DefaultTableModel model = new DefaultTableModel(data,collumns);
				JTable table = new JTable(model);
				tableScrollPanel.setViewportView(table);
				table.setDefaultEditor(Object.class, null);
				tableScrollPanel.revalidate();
				tableScrollPanel.repaint();
				
                for (ActionListener listener : deleteRowButton.getActionListeners()) {
                    deleteRowButton.removeActionListener(listener);
                }
				deleteRowButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						int selectedRow = table.getSelectedRow();
						if(selectedRow != -1) {
							Object value = table.getValueAt(selectedRow, 1);
							if(value instanceof Long) {
								crs.removePatient((long)(value));
								model.removeRow(selectedRow);
							}
						}
					}
				});
				cardLayout.show(mainPanel,"showTablePanel");
			}
		});
		
		JButton showSectionsButton = new JButton("Sections");
		showSectionsButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tableScrollPanel.getViewport().removeAll(); 
				String[] collumns = {"Name","ID","Hospital"};
				ArrayList<Section> sections = crs.getSections();
				Object[][] data = new Object[sections.size()][3];
				for (int i = 0; i < sections.size(); i++) 
				{
					Section section = sections.get(i);
					data[i][0] = section.getName();
					data[i][1] = section.getID();
					data[i][2] = section.getHospital().toString(); //name-id
				}
				DefaultTableModel model = new DefaultTableModel(data,collumns);
				JTable table = new JTable(model);
				tableScrollPanel.setViewportView(table);
				table.setDefaultEditor(Object.class, null);
				tableScrollPanel.revalidate();
				tableScrollPanel.repaint();
				
                for (ActionListener listener : deleteRowButton.getActionListeners()) {
                    deleteRowButton.removeActionListener(listener);
                }
				deleteRowButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						int selectedRow = table.getSelectedRow();
						if(selectedRow != -1) {
							Object valueID = table.getValueAt(selectedRow, 1);
							Object valueHospital = table.getValueAt(selectedRow, 2);
							if(valueID instanceof Integer && valueHospital instanceof String) {
								String hospitalText = (String)valueHospital;
								int hospitalID = Integer.parseInt(hospitalText.substring(hospitalText.indexOf("-")+1));
								Hospital hospital = crs.getHospital(hospitalID);
								if(hospital != null) {
									hospital.removeSection((int)valueID);
									model.removeRow(selectedRow);
								}
							}
						}
					}
				});
				cardLayout.show(mainPanel,"showTablePanel");
			}
		});
		menuBar.add(showSectionsButton);
		
		JButton showDoctorsButton = new JButton("Doctors");
		showDoctorsButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tableScrollPanel.getViewport().removeAll(); 
				String[] collumns = {"Name","National ID","Diploma ID","Section"};
				ArrayList<Doctor> doctors = crs.getDoctors();
				Object[][] data = new Object[doctors.size()][4];
				for (int i = 0; i < doctors.size(); i++) 
				{
					Doctor doctor = doctors.get(i);
					data[i][0] = doctor.getName();
					data[i][1] = doctor.getNationalID();
					data[i][2] = doctor.getDiplomaID();
					data[i][3] = doctor.getSection().toString(); //name-id
				}
				DefaultTableModel model = new DefaultTableModel(data,collumns);
				JTable table = new JTable(model);
				tableScrollPanel.setViewportView(table);
				table.setDefaultEditor(Object.class, null);
				tableScrollPanel.revalidate();
				tableScrollPanel.repaint();
				
                for (ActionListener listener : deleteRowButton.getActionListeners()) {
                    deleteRowButton.removeActionListener(listener);
                }
				deleteRowButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						int selectedRow = table.getSelectedRow();
						if(selectedRow != -1) {
							Object valueDipID = table.getValueAt(selectedRow, 2);
							Object valueSection = table.getValueAt(selectedRow, 3);
							if(valueDipID instanceof Integer && valueSection instanceof String) {
								String sectionText = (String)valueSection;
								int locationOfFirstSeperator =  sectionText.indexOf("-");
								int locationOfSecondSeperator = sectionText.indexOf("-",locationOfFirstSeperator+1);
								int sectionID = Integer.parseInt(sectionText.substring(locationOfFirstSeperator+1,locationOfSecondSeperator));
								int hospitalID = Integer.parseInt(sectionText.substring(locationOfSecondSeperator+1));
								Section section = crs.getHospital(hospitalID).getSection(sectionID);
								if(section != null) {
									section.removeDoctor((int)valueDipID);
									model.removeRow(selectedRow);
								}
							}
						}
					}
				});
				cardLayout.show(mainPanel,"showTablePanel");
			}
		});
		menuBar.add(showDoctorsButton);
		menuBar.add(showPatientsButton);
		
		JButton showRendezvousButton = new JButton("Rendezvous");
		showRendezvousButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tableScrollPanel.getViewport().removeAll(); 
				String[] collumns = {"Patient","Doctor","Date"};
				LinkedList<Rendezvous> rendezvous = crs.getAllRendezvous();
				Object[][] data = new Object[rendezvous.size()][3];
				for (int i = 0; i < rendezvous.size(); i++) 
				{
					Rendezvous rendezvousSingular = rendezvous.get(i);
					data[i][0] = rendezvousSingular.getPatient().toString();
					data[i][1] = rendezvousSingular.getDoctor().toString();
					data[i][2] = rendezvousSingular.getDate().toString();
				}
				DefaultTableModel model = new DefaultTableModel(data,collumns);
				JTable table = new JTable(model);
				tableScrollPanel.setViewportView(table);
				table.setDefaultEditor(Object.class, null);
				tableScrollPanel.revalidate();
				tableScrollPanel.repaint();
				
                for (ActionListener listener : deleteRowButton.getActionListeners()) {
                    deleteRowButton.removeActionListener(listener);
                }
				deleteRowButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						int selectedRow = table.getSelectedRow();
						if(selectedRow != -1) {
							Object valueDoctor = table.getValueAt(selectedRow, 1);
							Object valuePatient = table.getValueAt(selectedRow, 0);
							Object valueDate = table.getValueAt(selectedRow, 2);
							if(valueDoctor instanceof String && valuePatient instanceof String && valueDate instanceof String) {
								String doctorString = (String)valueDoctor;
								String patientString = (String)valuePatient;
								String dateString = (String)valueDate;
								if(crs.removeRendezvous(doctorString, patientString, dateString)) {
									model.removeRow(selectedRow);
								}
								else {
									System.out.println("error while removing rendezvous");
								}
							}
						}
					}
				});
				cardLayout.show(mainPanel,"showTablePanel");
			}
		});
		menuBar.add(showRendezvousButton);
		
		
	}
	
    private void setOnlyDigitsFilter(JTextField textField, int maxLength) 
    {
        PlainDocument doc = (PlainDocument) textField.getDocument();
        doc.setDocumentFilter(new DocumentFilter() {
            public void insertString(FilterBypass fb, int offset, String string, AttributeSet attr) throws BadLocationException {
                if (string.matches("\\d*") && fb.getDocument().getLength() + string.length() <= maxLength) {
                    super.insertString(fb, offset, string, attr);
                }
            }
            public void replace(FilterBypass fb, int offset, int length, String text, AttributeSet attrs) throws BadLocationException {
                if (text.matches("\\d*") && fb.getDocument().getLength() - length + text.length() <= maxLength) {
                    super.replace(fb, offset, length, text, attrs);
                }
            }
        });
    }

    
    private void setOnlyAlphabeticFilter(JTextField textField, int maxLength) 
    {
        PlainDocument doc = (PlainDocument) textField.getDocument();
        doc.setDocumentFilter(new DocumentFilter() {
            public void insertString(FilterBypass fb, int offset, String string, AttributeSet attr) throws BadLocationException {
                if (string.matches("[a-zA-ZçğıöşüÇĞİÖŞÜ ]*") && fb.getDocument().getLength() + string.length() <= maxLength) {
                    super.insertString(fb, offset, string, attr);
                }
            }
            public void replace(FilterBypass fb, int offset, int length, String text, AttributeSet attrs) throws BadLocationException {
                if (text.matches("[a-zA-ZçğıöşüÇĞİÖŞÜ ]*") && fb.getDocument().getLength() - length + text.length() <= maxLength) {
                    super.replace(fb, offset, length, text, attrs);
                }
            }
        });
    }
    
    private boolean isValidDate(int year, int month, int day) {
        Calendar calendar = Calendar.getInstance();
        calendar.set(year, month - 1, 1);
        int maxDay = calendar.getActualMaximum(Calendar.DAY_OF_MONTH);
        return day >= 1 && day <= maxDay;
    }
    
    private void clearRendezvousDateFields() {
    	rendezvousDayTextField.setText("");
    	rendezvousMonthTextField.setText("");
    	rendezvousYearTextField.setText("");
    	rendezvousHourTextField.setText("");
    	rendezvousMinuteTextField.setText("");

    }
}
