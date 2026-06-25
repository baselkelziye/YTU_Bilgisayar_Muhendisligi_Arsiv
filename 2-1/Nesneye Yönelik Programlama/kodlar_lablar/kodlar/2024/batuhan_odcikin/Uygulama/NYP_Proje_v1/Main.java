package nyp_project;

import java.io.File;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

import javax.swing.*;

public class Main{	
	public static String file_path = System.getProperty("user.dir") + "/data.txt";
	public static void main (String []args) {
		Scanner s = new Scanner(System.in);
	    int input_int;
	    String input_string;
	    
	    CRS crs = new CRS();   
	    File file = new File(file_path);
	    
	    if (file.exists() && !file.isDirectory()) {
	    	
	        crs.loadTablesToDisk(file_path);
	    } else {

	        System.out.println("File not found. Saving tables to disk first...");
	        crs.saveTablesToDisk(file_path);
	        System.out.println("File saved. Loading tables...");
	        crs.loadTablesToDisk(file_path);
	    }
	    
		System.out.print("1- Console Mode \n2- GUI Mode \n0- Exit \nInput: ");
	    
	    input_int = s.nextInt();
	    s.nextLine();
	    
	    switch(input_int) {
	    case 1:
	    	consoleMode(crs);
	    	break;
	    case 2:
	    	guiMode(crs);
	    	break;
	    case 0:
	    	System.exit(0);
	    	break;
	    }
	    
//		CRS crs = new CRS();
//		CRS crs1 = new CRS();
//		Calendar calendar = Calendar.getInstance();
//		calendar.set(2024, Calendar.JANUARY, 20, 14, 30, 00); // Year, Month (0-based), Day
//		Date date = calendar.getTime();
//		
//		crs.addPatient("Batuhan", 123);
//		crs.addPatient("Ahmet", 222);
//		crs.addPatient("Nesli", 111);
//		
//		crs.addHospital(01,"Beylikdüzü Medicana");
//		crs.addHospital(02,"Avcılar Medicana");
//		
//		crs.addSectionToHospital_byID(01, 001,"KBB");
//		crs.addSectionToHospital_byID(01, 002, "Dahiliye");
//		crs.addSectionToHospital_byID(02, 001,"KBB");
//		crs.addSectionToHospital_byID(02, 002, "Dahiliye");
//		
//		crs.addDoctor(01, "KBB", "Mehmet", 112, 123123,1);
//		crs.addDoctor(01, "Dahiliye", "Ayse", 113, 321321,1);
//		
//		crs.addDoctor(02, "KBB", "Faruk", 114, 232343,1);
//		crs.addDoctor(02, "Dahiliye", "Yurdagul", 115, 422334,1);
//		
//		crs.makeRandezvous(123, 01, 001, 112, date);
//		crs.makeRandezvous(123, 01, 001, 112, date);
//		crs.makeRandezvous(123, 01, 001, 112, date);
//		crs.makeRandezvous(123, 01, 001, 112, date);
//		crs.makeRandezvous(123, 01, 001, 112, date);
//		
////		crs.listHospitals();
////		crs.listRandezvous();
////		crs.listPatients();
//		
//		crs.saveTablesToDisk(file_path);
//		
//		crs1.loadTablesToDisk(file_path);
//		
//		crs1.listHospitals();
//		crs1.listRandezvous();
//		crs1.listPatients();
//		
		
	}
	
	public static void consoleMode(CRS crs) {
		Scanner s = new Scanner(System.in);
	    int input_int;
	    String input_string;
	    int flag = 0;
	    
	    while (flag == 0) {
	    	
		System.out.print("1- Add Patient \n2- Add Doctor \n3- Add Section \n4- Add Hospital \n5- Add Randezvous  \n6- Save to File \n7- Load From File\n8- Delete File\n 9-List All CRS Data\n 10-List Randezvous\n 11- List Patients\n 0- Exit\nInput:");
		input_int = s.nextInt();
		s.nextLine();
		
		
		
		switch(input_int) {
		case 1:
			System.out.println("1- Add Patient");
			System.out.print("Name: ");
			input_string = s.nextLine();
			System.out.print("National ID: ");
			input_int = s.nextInt();
			s.nextLine();
			crs.addPatient(input_string, input_int);
			System.out.println("Patient Added!");
			System.out.println("List of Patients:");
			crs.listPatients();
			break;
		case 2:
			main_addDoctor(crs);
			break;
		case 3:
			main_addSection(crs);
			break;
		case 4:
			main_addHospital(crs);
			break;
		case 5:
			main_addRandezvous(crs);
			break;
		case 6:
			crs.saveTablesToDisk(file_path);
			break;
		case 7:
			crs.loadTablesToDisk(file_path);
			break;
		case 8:
			System.out.println("Delete all database ?\n 1- Yes 0- No");
			input_int = s.nextInt();
			s.nextLine();
			if(input_int == 1){
				crs = new CRS();
				crs.saveTablesToDisk(file_path);
				System.out.println("Database deleted succesfuly");
			}
			else
				System.out.println("Database secured");
			break;
		case 9:
			crs.listAll();
			break;
		case 10:
			crs.listRandezvous();
			break;
		case 11:
			crs.listPatients();
			break;
		case 0:
			flag = 1;
			break;
		default:
			System.out.println("Wrong input");
			break;
		}
	    }
	}
	
	public static void main_addDoctor(CRS crs) {
	    Scanner s = new Scanner(System.in);
	    try {
	        System.out.println("Available Hospitals:");
	        crs.listHospitals();

	        System.out.print("Enter Hospital ID to add doctor: ");
	        int hospital_id = Integer.parseInt(s.nextLine());
	        if (!crs.getHospitals().containsKey(hospital_id)) {
	            System.out.println("Invalid Hospital ID! Returning to menu.");
	            return;
	        }

	        crs.listSections(hospital_id);
	        System.out.print("Enter Section ID to add doctor: ");
	        int section_id = Integer.parseInt(s.nextLine());
	        if (crs.getHospitals().get(hospital_id).getSection(section_id) == null) {
	            System.out.println("Invalid Section ID! Returning to menu.");
	            return;
	        }

	        System.out.print("Name: ");
	        String name = s.nextLine();
	        System.out.print("National ID: ");
	        int national_id = Integer.parseInt(s.nextLine());
	        System.out.print("Diploma ID: ");
	        int diploma_id = Integer.parseInt(s.nextLine());
	        System.out.print("Max Patients Per Day: ");
	        int max_patient = Integer.parseInt(s.nextLine());

	        crs.addDoctor(hospital_id, section_id, name, national_id, diploma_id, max_patient);
	        System.out.println("Doctor added successfully!");
	    } catch (NumberFormatException e) {
	        System.out.println("Invalid input! Please enter valid numbers.");
	    } catch (Exception e) {
	        System.out.println("An error occurred: " + e.getMessage());
	    }
	}

	
	public static void main_addHospital(CRS crs) {
	    Scanner s = new Scanner(System.in);
	    try {
	        System.out.print("Enter Hospital Name: ");
	        String name = s.nextLine();
	        System.out.print("Enter Hospital ID: ");
	        int id = Integer.parseInt(s.nextLine());

	        if (crs.getHospitals().containsKey(id)) {
	            System.out.println("A hospital with this ID already exists. Returning to menu.");
	            return;
	        }

	        crs.addHospital(id, name);
	        System.out.println("Hospital added successfully!");
	    } catch (NumberFormatException e) {
	        System.out.println("Invalid input! Please enter a valid number for the ID.");
	    } catch (Exception e) {
	        System.out.println("An error occurred: " + e.getMessage());
	    }
	}

	
	public static void main_addSection(CRS crs) {
	    Scanner s = new Scanner(System.in);
	    try {
	        System.out.println("Available Hospitals:");
	        crs.listHospitals();

	        System.out.print("Enter Hospital ID to add section: ");
	        int hospital_id = Integer.parseInt(s.nextLine());
	        if (!crs.getHospitals().containsKey(hospital_id)) {
	            System.out.println("Invalid Hospital ID! Returning to menu.");
	            return;
	        }

	        System.out.print("Enter Section Name: ");
	        String name = s.nextLine();
	        System.out.print("Enter Section ID: ");
	        int id = Integer.parseInt(s.nextLine());

	        crs.addSection(hospital_id, id, name);
	        System.out.println("Section added successfully!");
	    } catch (NumberFormatException e) {
	        System.out.println("Invalid input! Please enter valid numbers.");
	    } catch (Exception e) {
	        System.out.println("An error occurred: " + e.getMessage());
	    }
	}

	
	public static void main_addRandezvous(CRS crs) {
		Scanner s = new Scanner(System.in);
    	int id,hospital_id,section_id,doctor_id,patient_id;
    	String name,hospital_name;
		Date date;
		
		crs.listAll();
//    	crs.listHospitals();
    	
    	System.out.print("Hospital to Add Section: ");
	    hospital_id = s.nextInt();
	    s.nextLine();
	    
//	    crs.listSections(hospital_id);
	    System.out.print("Select Section: ");
	    section_id = s.nextInt();
	    s.nextLine();
	    
//	    crs.listDoctors(hospital_id, section_id);
	    
	    System.out.println("Select Doctor by diploma ID: ");
	    doctor_id = s.nextInt();
	    s.nextLine();
	    
	    System.out.println("Enter Patient ID: ");
	    patient_id = s.nextInt();
	    s.nextLine();
	    
	    System.out.println("Enter date (dd/MM/yyyy HH:mm): ");
	    String dateInput = s.nextLine();

	    try {
	        SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy HH:mm");
	        date = dateFormat.parse(dateInput);
	    } catch (Exception e) {
	        System.out.println("Invalid date format! Please use the format dd/MM/yyyy HH:mm.");
	        return; 
	    }

	    try {
	        boolean success = crs.makeRandezvous(patient_id, hospital_id, section_id, doctor_id, date);
	        if (success) {
	            System.out.println("Rendezvous successfully created!");
	        } else {
	            System.out.println("Failed to create rendezvous. The doctor's schedule might be full.");
	        }
	    } catch (IDException e) {
	        System.out.println("Error: " + e.getMessage());
	    }	}

	@SuppressWarnings("rawtypes")
	
	public static JFrame pano;
	private final static int panoX = 1000, panoY = 500;
	
	public static void guiMode(CRS crs) {

	    pano = new JFrame("Hospital CRS System");
	    pano.setSize(panoX, panoY);
	    pano.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    pano.setLayout(null);

	    JLabel hospitalLabel = new JLabel("Hastane:");
	    hospitalLabel.setBounds(20, 50, 100, 30);
	    pano.add(hospitalLabel);

	    JComboBox<String> hospitalComboBox = new JComboBox<>();
	    hospitalComboBox.setBounds(120, 50, 200, 30);
	    pano.add(hospitalComboBox);

	    JLabel sectionLabel = new JLabel("Bölüm:");
	    sectionLabel.setBounds(20, 100, 100, 30);
	    pano.add(sectionLabel);

	    JComboBox<String> sectionComboBox = new JComboBox<>();
	    sectionComboBox.setBounds(120, 100, 200, 30);
	    sectionComboBox.setEnabled(false);
	    pano.add(sectionComboBox);

	    JLabel doctorLabel = new JLabel("Doktor:");
	    doctorLabel.setBounds(20, 150, 100, 30);
	    pano.add(doctorLabel);

	    JComboBox<String> doctorComboBox = new JComboBox<>();
	    doctorComboBox.setBounds(120, 150, 200, 30);
	    doctorComboBox.setEnabled(false);
	    pano.add(doctorComboBox);

	    JLabel dateLabel = new JLabel("Tarih:");
	    dateLabel.setBounds(20, 200, 100, 30);
	    pano.add(dateLabel);

	    JTextField dateField = new JTextField("dd/MM/yyyy HH:mm");
	    dateField.setBounds(120, 200, 200, 30);
	    pano.add(dateField);
	    
	    JLabel patientLabel = new JLabel("Patient ID: ");
	    patientLabel.setBounds(20, 250, 100, 30);
	    pano.add(patientLabel);

	    JTextField patientField = new JTextField();
	    patientField.setBounds(120, 250, 200, 30);
	    pano.add(patientField);

	    JButton createButton = new JButton("Randevu Oluştur");
	    createButton.setBounds(120, 300, 200, 30);
	    createButton.setEnabled(false);
	    pano.add(createButton);

	 // Add Patient //	 
	    
	    JLabel patientNameLabel = new JLabel("Patient Name: ");
	    patientNameLabel.setBounds(420, 50, 100, 30);
	    pano.add(patientNameLabel);
    	    
	    JTextField patientNameField = new JTextField();
	    patientNameField.setBounds(520, 50, 200, 30);
	    pano.add(patientNameField);
	    
	    JLabel patientIDLabel = new JLabel("Patient ID: ");
	    patientIDLabel.setBounds(420, 100, 100, 30);
	    pano.add(patientIDLabel);

	    JTextField patientIDField = new JTextField();
	    patientIDField.setBounds(520, 100, 200, 30);
	    pano.add(patientIDField);
	    
	    JButton patientAddButton = new JButton("Hasta Ekle");
	    patientAddButton.setBounds(520, 150, 200, 30);
	    patientAddButton.setEnabled(true);
	    pano.add(patientAddButton);
	    
	    
	    JButton saveButton = new JButton("Sisteme Kaydet");
	    saveButton.setBounds(20, 350, 200, 30);
	    saveButton.setEnabled(true);
	    pano.add(saveButton);
	    
	    JButton listPatientButton = new JButton("Hastaları Listele");
	    listPatientButton.setBounds(270, 350, 200, 30);
	    listPatientButton.setEnabled(true);
	    pano.add(listPatientButton);
	    
	    JButton listRandezvousButton = new JButton("Randevuları Listele");
	    listRandezvousButton.setBounds(520, 350, 200, 30);
	    listRandezvousButton.setEnabled(true);
	    pano.add(listRandezvousButton);
	    
	    saveButton.addActionListener(e -> {
	    	crs.saveTablesToDisk(file_path);
	    });
	    
	    listPatientButton.addActionListener(e -> {
	    	StringBuilder patientList = new StringBuilder("Patients:\n");
	        for (Patient patient : crs.getPatients().values()) {
	            patientList.append("ID: ").append(patient.getNational_id())
	                       .append(", Name: ").append(patient.getName()).append("\n");
	        }
	        
	        JOptionPane.showMessageDialog(pano, patientList.toString(), "Patient List", JOptionPane.INFORMATION_MESSAGE);
	    });
	    
	    listRandezvousButton.addActionListener(e -> {
	    	StringBuilder randezvousList = new StringBuilder("Rendezvous:\n");
	    	
	    	for (Randezvous r: crs.getRandezvous()) {
	    		randezvousList.append("Doctor: ").append(r.getDoctor().getDiploma_id()).append(" ").append(r.getDoctor().getName()).append(" Patient: ").append(r.getPatient()).append(" Date: ").append(r.getDatetime()).append("\n");
	        }
	    	
	        JOptionPane.showMessageDialog(pano, randezvousList.toString(), "Rendezvous List", JOptionPane.INFORMATION_MESSAGE);

	    });
	    
	    for (Hospital hospital : crs.getHospitals().values()) {
	        hospitalComboBox.addItem(hospital.getId() + " - " + hospital.getName());
	    }

	    hospitalComboBox.addActionListener(e -> {
	        sectionComboBox.removeAllItems();
	        doctorComboBox.removeAllItems();
	        doctorComboBox.setEnabled(false);
	        sectionComboBox.setEnabled(true);

	        String selectedHospital = (String) hospitalComboBox.getSelectedItem();
	        if (selectedHospital != null) {
	            int hospitalId = Integer.parseInt(selectedHospital.split(" - ")[0]);
	            for (Section section : crs.getHospitals().get(hospitalId).getSections()) {
	                sectionComboBox.addItem(section.getId() + " - " + section.getName());
	            }
	        }
	    });

	    sectionComboBox.addActionListener(e -> {
	        doctorComboBox.removeAllItems();
	        doctorComboBox.setEnabled(true);

	        String selectedHospital = (String) hospitalComboBox.getSelectedItem();
	        String selectedSection = (String) sectionComboBox.getSelectedItem();
	        if (selectedHospital != null && selectedSection != null) {
	            int hospitalId = Integer.parseInt(selectedHospital.split(" - ")[0]);
	            int sectionId = Integer.parseInt(selectedSection.split(" - ")[0]);

	            for (Doctor doctor : crs.getHospitals().get(hospitalId).getSection(sectionId).getDoctors()) {
	                doctorComboBox.addItem(doctor.getDiploma_id() + " - " + doctor.getName());
	            }
	        }
	    });

	    doctorComboBox.addActionListener(e -> createButton.setEnabled(true));

	    createButton.addActionListener(e -> {
	        String selectedHospital = (String) hospitalComboBox.getSelectedItem();
	        String selectedSection = (String) sectionComboBox.getSelectedItem();
	        String selectedDoctor = (String) doctorComboBox.getSelectedItem();
	        String dateInput = dateField.getText();

	        if (selectedHospital != null && selectedSection != null && selectedDoctor != null) {
	            int hospitalId = Integer.parseInt(selectedHospital.split(" - ")[0]);
	            int sectionId = Integer.parseInt(selectedSection.split(" - ")[0]);
	            int doctorId = Integer.parseInt(selectedDoctor.split(" - ")[0]);
	            int patientId = Integer.parseInt(patientField.getText());
	            
	            try {
	                SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy HH:mm");
	                Date date = dateFormat.parse(dateInput);

	                boolean success = crs.makeRandezvous(patientId, hospitalId, sectionId, doctorId, date); // 0: Hasta ID (örnek olarak)
	                if (success) {
	                    JOptionPane.showMessageDialog(pano, "Randevu başarıyla oluşturuldu!");
	                } else {
	                    JOptionPane.showMessageDialog(pano, "Randevu oluşturulamadı. Doktorun programı dolu.");
	                }
	            } 
	            catch (IDException id_e) {
	            	JOptionPane.showMessageDialog(pano, id_e.getMessage());
	            	
	            }
	            catch (Exception ex) {
	                JOptionPane.showMessageDialog(pano, "Geçersiz tarih formatı! Lütfen dd/MM/yyyy HH:mm formatında girin.");
	            }
	        }
	    });
	    
	    patientAddButton.addActionListener(e -> {
	    	
	    	 String patientName = patientNameField.getText().trim();
	    	 String patientID = patientIDField.getText().trim();
	    	    
	    	 if (patientName.isEmpty() || patientID.isEmpty()) {
	    	        JOptionPane.showMessageDialog(pano, "İsim ve ID'yi giriniz!");
	    	        return;
	    	    }

	    	    try {
	    	        int p_id = Integer.parseInt(patientID);
	    	        crs.addPatient(patientName, p_id);
	    	        JOptionPane.showMessageDialog(pano, "Hasta Kayıt Başarılı!");
	    	    } catch (NumberFormatException ex) {
	    	        JOptionPane.showMessageDialog(pano, "Geçerli bir hasta ID'si giriniz!");
	    	    }
	    });
	    
	    pano.setVisible(true);
	}


}


