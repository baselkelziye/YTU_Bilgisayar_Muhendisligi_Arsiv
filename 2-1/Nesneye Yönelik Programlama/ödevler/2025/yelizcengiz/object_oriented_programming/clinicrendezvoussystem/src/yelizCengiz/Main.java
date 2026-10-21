package yelizCengiz;

import java.awt.Dimension;
import java.awt.Font;
import java.awt.Toolkit;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

import javax.swing.DefaultComboBoxModel;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class Main {
	public static ArrayList<JComponent> components;
	public static JFrame frame;
	public static CRS crs;
	public static CRS crsConsole=new CRS();
	public static Scanner scanner= new Scanner(System.in);
	public static int mode;
	
	public static String hospitalArray[]= {};
	public static String sectionArray[]= {};
	public static String doctorArray[]= {};
	
	private static void setMenuVisible(String menuName) {
		for(JComponent c:components) {
			if(c.getName().contains(menuName)) {
				if(c instanceof JTextField) {
					((JTextField) c).setText("");
				}
				c.setVisible(true);
			}else {
				c.setVisible(false);
			}
			if(menuName!="main"&&c.getName().contains("backToMain")) {
				c.setVisible(true);
			}
		}	
	}	
	
	public static void saveToDisk() throws IOException {
		crs.saveTablesToDisk("crs.ser");
	}
	public static void loadToDisk() throws IOException {
		File file =new File("crs.ser");
		if(file.exists()) {
			crs=crs.loadTablesToDisk("crs.ser");
			for(JComponent c:components) {
				if(c.getName().contains("MenuHospital")) {
					((JComboBox) c).setModel(new DefaultComboBoxModel<>(crs.getHospitals().values().toArray()));
				}	
			}
		}
		else {
			JOptionPane.showMessageDialog(frame, "Saved file not found!", "Warning", JOptionPane.WARNING_MESSAGE);
			return;
		}
		
		
	}
	
	public static void createAllLabels() {
		GUIMethods.addLabel("Hospital Id", frame.getWidth()/2-150, frame.getHeight()/2-100, 100, 30,"hospitalMenu");
		GUIMethods.addLabel("Hospital Name", frame.getWidth()/2-150, frame.getHeight()/2-20, 100, 30,"hospitalMenu");
		GUIMethods.addLabel("Section Id", frame.getWidth()/2-150, frame.getHeight()/2-180, 100, 30,"sectionMenu");
		GUIMethods.addLabel("Section Name", frame.getWidth()/2-150, frame.getHeight()/2-100, 100, 30,"sectionMenu");
		GUIMethods.addLabel("Hospital", frame.getWidth()/2-150, frame.getHeight()/2-20, 100, 30,"sectionMenu");
		GUIMethods.addLabel("National Id", frame.getWidth()/2-150, frame.getHeight()/2-240, 100, 30,"doctorMenu");
		GUIMethods.addLabel("Name", frame.getWidth()/2-150, frame.getHeight()/2-180, 100, 30,"doctorMenu");
		GUIMethods.addLabel("Diploma Id", frame.getWidth()/2-150, frame.getHeight()/2-120, 100, 30,"doctorMenu");
		GUIMethods.addLabel("Max Patient Per Day", frame.getWidth()/2-150, frame.getHeight()/2-60, 150, 30,"doctorMenu");
		GUIMethods.addLabel("Hospital", frame.getWidth()/2-150, frame.getHeight()/2, 100, 30,"doctorMenu");
		GUIMethods.addLabel("Section", frame.getWidth()/2-150, frame.getHeight()/2+60, 100, 30,"doctorMenu");
		GUIMethods.addLabel("National Id", frame.getWidth()/2-150, frame.getHeight()/2-100, 100, 30,"patientMenu");
		GUIMethods.addLabel("Name", frame.getWidth()/2-150, frame.getHeight()/2-20, 100, 30,"patientMenu");
		GUIMethods.addLabel("Patient National Id", frame.getWidth()/2-150, frame.getHeight()/2-200, 150, 30,"rendezvousMenu");
		GUIMethods.addLabel("Hospital", frame.getWidth()/2-150, frame.getHeight()/2-140, 100, 30,"rendezvousMenu");
		GUIMethods.addLabel("Section", frame.getWidth()/2-150, frame.getHeight()/2-80, 100, 30,"rendezvousMenu");
		GUIMethods.addLabel("Doctor Name", frame.getWidth()/2-150, frame.getHeight()/2-20, 100, 30,"rendezvousMenu");
		GUIMethods.addLabel("Date", frame.getWidth()/2-150, frame.getHeight()/2+40, 100, 30,"rendezvousMenu");
		GUIMethods.addLabel("", 100, 50, 900, 500,"display");
	}
	public static void createAllTextFields() {
		GUIMethods.addTextField("", frame.getWidth()/2, frame.getHeight()/2-100, 200, 30,"hospitalMenuId");
		GUIMethods.addTextField("", frame.getWidth()/2, frame.getHeight()/2-20, 200, 30,"hospitalMenuName");
		GUIMethods.addTextField("", frame.getWidth()/2, frame.getHeight()/2-180, 200, 30,"sectionMenuId");
		GUIMethods.addTextField("", frame.getWidth()/2, frame.getHeight()/2-100, 200, 30,"sectionMenuName");
		GUIMethods.addTextField("", frame.getWidth()/2, frame.getHeight()/2-240, 200, 30,"doctorMenuNationalId");
		GUIMethods.addTextField("", frame.getWidth()/2, frame.getHeight()/2-180, 200, 30,"doctorMenuName");
		GUIMethods.addTextField("", frame.getWidth()/2, frame.getHeight()/2-120, 200, 30,"doctorMenuDiplomaId");
		GUIMethods.addTextField("", frame.getWidth()/2, frame.getHeight()/2-60, 200, 30,"doctorMenuMaxPatient");
		GUIMethods.addTextField("", frame.getWidth()/2, frame.getHeight()/2-100, 200, 30,"patientMenuId");
		GUIMethods.addTextField("", frame.getWidth()/2, frame.getHeight()/2-20, 200, 30,"patientMenuName");
		GUIMethods.addTextField("", frame.getWidth()/2, frame.getHeight()/2-200, 200, 30,"rendezvousMenuId");
		GUIMethods.addTextField("", frame.getWidth()/2, frame.getHeight()/2+40, 30, 30,"rendezvousMenuDay");
		GUIMethods.addTextField("", frame.getWidth()/2+30, frame.getHeight()/2+40, 30, 30,"rendezvousMenuMonth");
		GUIMethods.addTextField("", frame.getWidth()/2+60, frame.getHeight()/2+40, 60, 30,"rendezvousMenuYear");
	}
	public static void createAllComboBoxes() {
		GUIMethods.addComboBox(frame.getWidth()/2, frame.getHeight()/2-20, 200, 30,"sectionMenuHospital", hospitalArray);
		GUIMethods.addComboBox( frame.getWidth()/2, frame.getHeight()/2, 200, 30,"doctorMenuHospital", hospitalArray);
		GUIMethods.addComboBox( frame.getWidth()/2, frame.getHeight()/2+60, 200, 30,"doctorMenuSection", sectionArray);
		GUIMethods.addComboBox( frame.getWidth()/2, frame.getHeight()/2-140, 200, 30,"rendezvousMenuHospital", hospitalArray);
		GUIMethods.addComboBox( frame.getWidth()/2, frame.getHeight()/2-80, 200, 30,"rendezvousMenuSection", sectionArray);
		GUIMethods.addComboBox( frame.getWidth()/2, frame.getHeight()/2-20, 200, 30,"rendezvousMenuDoctor", doctorArray);
	}
	public static void createAllButtons() {
		GUIMethods.addButton("Main Menu", 20, 10, 100, 40,"backToMain", "backToMainMenu");
		GUIMethods.addButton("Save", 20, 60, 100, 40,"main", "saveToDisk");
		GUIMethods.addButton("Load", 20, 110, 100, 40,"main", "loadToDisk");
		GUIMethods.addButton("Add Hospital", frame.getWidth()/2-100, frame.getHeight()/2-200, 200, 40,"main", "addHospitalButton");
		GUIMethods.addButton("Add Section", frame.getWidth()/2-100, frame.getHeight()/2-120, 200, 40,"main", "addSectionButton");
		GUIMethods.addButton("Add Doctor", frame.getWidth()/2-100, frame.getHeight()/2-40, 200, 40,"main", "addDoctorButton");
		GUIMethods.addButton("New Patient Registration", frame.getWidth()/2-100, frame.getHeight()/2+40, 200, 40,"main", "newPatientButton");
		GUIMethods.addButton("Make Rendezvous", frame.getWidth()/2-100, frame.getHeight()/2+120, 200, 40,"main", "makeRendezvousButton");
		GUIMethods.addButton("Display Rendezvous", frame.getWidth()/2-100, frame.getHeight()/2+200, 200, 40,"main", "displayRendezvousButton");
		GUIMethods.addButton("Add Hospital", frame.getWidth()/2-100, frame.getHeight()/2+120, 200, 40,"hospitalMenu", "saveHospitalButton");
		GUIMethods.addButton("Add Section", frame.getWidth()/2-100, frame.getHeight()/2+120, 200, 40,"sectionMenu", "saveSectionButton");
		GUIMethods.addButton("Add Doctor", frame.getWidth()/2-100, frame.getHeight()/2+150, 200, 40,"doctorMenu", "saveDoctorButton");
		GUIMethods.addButton("Register Patient", frame.getWidth()/2-100, frame.getHeight()/2+120, 200, 40,"patientMenu", "savePatientButton");	
		GUIMethods.addButton("Make Rendezvous", frame.getWidth()/2-100, frame.getHeight()/2+120, 200, 40,"rendezvousMenu", "saveRendezvousButton");
	}
	public static void createAllGUIComponents() {
		createAllLabels();
		createAllTextFields();
		createAllComboBoxes();
		createAllButtons();
	}
	
	public static void displayRendezvousButton() {
		StringBuilder str = new StringBuilder("<html>");
		str.append("Doctor Name - ").append("Patient Name - ").append("Date").append("<br>");
		for (Rendezvous r : crs.getRendezvous()) {
		    str.append("<br>").append(r.getDoctor()).append("-").append(r.getPatient()).append("-").append(r.getDateTime().getDate()).append(" / ").append(r.getDateTime().getMonth() + 1).append(" / ").append(r.getDateTime().getYear() + 1900).append("<br>"); 
		}str.append("</html>");

		for(JComponent c:components) {
			if(c.getName().contains("display")) {
				((JLabel)c).setText(str.toString());
				((JLabel)c).setFont(new Font("Arial",Font.CENTER_BASELINE , 20));
			}
		}
		setMenuVisible("display");
		frame.setTitle("Display Rendezvous Menu");
	}
	
	public static void saveHospitalButton() {
		int id=0;
		String name="";
		for(JComponent c:components) {
			if(c.getName().contains("hospitalMenuId")) {
				id=Integer.parseInt(((JTextField) c).getText().trim());
				if(id<0) {
					JOptionPane.showMessageDialog(frame, "Invalid ID!", "ID Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
				else if(crs.getHospitals().containsKey(id)) {
					JOptionPane.showMessageDialog(frame, "There is another hospital with this ID!", "ID Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
			}
			else if(c.getName().contains("hospitalMenuName")) {
				name=((JTextField) c).getText().trim();
				if(name.isEmpty()) {
					JOptionPane.showMessageDialog(frame, "Hospital name cannot be left blank!", "Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
				for(Hospital h : crs.getHospitals().values()) {
					if(h.getName().contains(name)) {
						JOptionPane.showMessageDialog(frame, "There is another hospital with this name!", "Warning", JOptionPane.WARNING_MESSAGE);
						return;
					}
				}
			}			
		}
		Hospital hospital= new Hospital(id, name);
		if(crs.addHospital(id, hospital)) {
			JOptionPane.showMessageDialog(frame, "Hospital saved");
			updateHospitalComboBoxes();
		}
		else {
			JOptionPane.showMessageDialog(frame, "Hospital not saved because there is another hospital with the same ID!", "Warning", JOptionPane.WARNING_MESSAGE);
		}
	}
	public static void saveSectionButton() {
		int id=0;
		String name="";
		Hospital hospital = null;
		
		for(JComponent c:components) {
			if(c.getName().contains("sectionMenuId")) {
				id=Integer.parseInt(((JTextField) c).getText().trim());
				if(id<0) {
					JOptionPane.showMessageDialog(frame, "Invalid ID!", "ID Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
			}
			else if(c.getName().contains("sectionMenuName")) {
				name=((JTextField) c).getText().trim();
				boolean isValid = name.matches("[a-zA-ZğüşöçıİĞÜŞÖÇ ]+");
				if(!isValid) {
					JOptionPane.showMessageDialog(frame, "Invalid section name!", "Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
			}
			else if(c.getName().contains("sectionMenuHospital")) {
				JComboBox<Hospital> hospitalCombo= (JComboBox<Hospital>) c;
				hospital = (Hospital) hospitalCombo.getSelectedItem();				
			}
		}
		
		if(hospital.getSection(id)!=null) {
			JOptionPane.showMessageDialog(frame, "There is another section in the hospital with this ID!", "ID Warning", JOptionPane.WARNING_MESSAGE);
			return;
		}
		if(hospital.getSection(name)!=null) {
			JOptionPane.showMessageDialog(frame, "There is already a section with this name in the hospital!", "ID Warning", JOptionPane.WARNING_MESSAGE);
			return;
		}
		
		Section section=new Section(id, name);
		
		if(hospital.addSection(section)) {
			JOptionPane.showMessageDialog(frame, "Section Saved");
			for(JComponent c:components) {
				if(c.getName().contains("MenuSection")) {
					 JComboBox<Section> sectionComboBox = (JComboBox<Section>) c;
			            DefaultComboBoxModel<Section> model = new DefaultComboBoxModel<>();
			            for(Section s: hospital.getSections()) {
			                model.addElement(s);
			            }
			            sectionComboBox.setModel(model);
			            
			            sectionComboBox.addActionListener(e -> {
		                    if(sectionComboBox.getSelectedItem()!=null) {
		                        Section selectedSection= (Section) sectionComboBox.getSelectedItem();
		                        updateDoctorComboBoxes(selectedSection);
		                    }
		                });
			    }
			}
		}
		else {
			JOptionPane.showMessageDialog(frame, "Hospital not saved because there is another section with the same name or ID!", "Warning", JOptionPane.WARNING_MESSAGE);
		}
	}
	public static void saveDoctorButton() {
		long natId=0;
		String name="";
		int diplomaId=0;
		int maxPatient=0;
		Hospital hospital = null;
		Section section=null;
		
		for(JComponent c:components) {
			if(c.getName().contains("doctorMenuNationalId")) {
				natId=Long.parseLong(((JTextField) c).getText().trim());
				if(natId<0) {
					JOptionPane.showMessageDialog(frame, "Invalid national ID", "ID Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
			}
			else if(c.getName().contains("doctorMenuName")) {
				name=((JTextField) c).getText().trim();
				boolean isValid = name.matches("[a-zA-ZğüşöçıİĞÜŞÖÇ ]+");
				if(!isValid) {
					JOptionPane.showMessageDialog(frame, "Invalid name!", "Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
			}
			else if(c.getName().contains("doctorMenuDiplomaId")) {
				diplomaId=Integer.parseInt(((JTextField) c).getText().trim());
				if(diplomaId<0) {
					JOptionPane.showMessageDialog(frame, "Invalid diploma ID", "ID Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
			}
			else if(c.getName().contains("doctorMenuMaxPatient")) {
				maxPatient=Integer.parseInt(((JTextField) c).getText().trim());
				if(maxPatient>20 ||maxPatient<0) {
					JOptionPane.showMessageDialog(frame, "Max patient per day is too high", "ID Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
			}
			else if(c.getName().contains("doctorMenuHospital")) {
				JComboBox<Hospital> hospitalCombo = (JComboBox<Hospital>) c;
				hospital = (Hospital) hospitalCombo.getSelectedItem();
			}
			else if(c.getName().contains("doctorMenuSection")) {
				JComboBox<Section> sectionCombo = (JComboBox<Section>) c;
				section = (Section) sectionCombo.getSelectedItem();
			}	
		}
		
		
		Doctor doctor=new Doctor(name, natId, diplomaId, maxPatient);
		
		if(section.addDoctor(doctor)){
			JOptionPane.showMessageDialog(frame, "Doctor Saved");
			updateDoctorComboBoxes(section);
		}
		else {
			JOptionPane.showMessageDialog(frame, "Doctor Not Saved");
		}
	}
	public static void savePatientButton() {
		long id=0;
		String name="";
		for(JComponent c:components) {
			if(c.getName().contains("patientMenuId")) {
				id=Long.parseLong(((JTextField) c).getText().trim());
				if(id<0) {
					JOptionPane.showMessageDialog(frame, "Invalid national ID", "ID Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
			}
			else if(c.getName().contains("patientMenuName")) {
				name=((JTextField) c).getText().trim();
				boolean isValid = name.matches("[a-zA-ZğüşöçıİĞÜŞÖÇ ]+");
				if(!isValid) {
					JOptionPane.showMessageDialog(frame, "Invalid name!", "Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
			}			
		}
		for(Patient p : crs.getPatients().values()) {
			if(p.getNationalId()==id) {
				JOptionPane.showMessageDialog(frame, "There is another patient with this ID!", "Warning", JOptionPane.WARNING_MESSAGE);
				return;
			}
		}
		
		Patient patient=new Patient(name, id);
		if(crs.addPatient(id, patient)) {
			JOptionPane.showMessageDialog(frame, "Patient Saved");
		}
		else {
			JOptionPane.showMessageDialog(frame, "Patient Not Saved");
		}
	}
	public static void saveRendezvousButton() {
		long natId=0;
		Hospital hospital = null;
		Section section=null;
		Doctor doctor=null;
		int day=0;
		int month=0;
		int year=0;
		
		for(JComponent c:components) {
			if(c.getName().contains("rendezvousMenuId")) {
				if(((JTextField) c).getText().trim().isEmpty()) {
					JOptionPane.showMessageDialog(frame, "National ID must be entered", "ID Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
				natId=Long.parseLong(((JTextField) c).getText().trim());
				if(!crs.getPatients().containsKey(natId)) {
					JOptionPane.showMessageDialog(frame, "There is no patient with this ID", "ID Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
				else if(natId<0) {
					JOptionPane.showMessageDialog(frame, "Invalid national ID", "ID Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
			}
			else if(c.getName().contains("rendezvousMenuHospital")) {
				JComboBox<Hospital> hospitalCombo= (JComboBox<Hospital>)c;
				hospital= (Hospital)hospitalCombo.getSelectedItem();
			}
			else if(c.getName().contains("rendezvousMenuSection")) {
				JComboBox<Section> sectionCombo= (JComboBox<Section>)c;
				section= (Section)sectionCombo.getSelectedItem();
			}
			else if(c.getName().contains("rendezvousMenuDoctor")) {
				JComboBox<Doctor> doctorCombo= (JComboBox<Doctor>)c;
				doctor=(Doctor)doctorCombo.getSelectedItem();
			}
			else if(c.getName().contains("rendezvousMenuDay")) {
				day=Integer.parseInt(((JTextField) c).getText().trim());
				if(((JTextField) c).getText().trim().isEmpty()) {
					JOptionPane.showMessageDialog(frame, "Day must be entered", "ID Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
				if(day<1||day>31) {
					JOptionPane.showMessageDialog(frame, "Invalid day", "Date Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
			}
			else if(c.getName().contains("rendezvousMenuMonth")) {
				month=Integer.parseInt(((JTextField) c).getText().trim());
				if(((JTextField) c).getText().trim().isEmpty()) {
					JOptionPane.showMessageDialog(frame, "Month must be entered", "ID Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
				if(month<1||month>12) {
					JOptionPane.showMessageDialog(frame, "Invalid month", "Date Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
			}
			else if(c.getName().contains("rendezvousMenuYear")) {
				year=Integer.parseInt(((JTextField) c).getText().trim());
				if(((JTextField) c).getText().trim().isEmpty()) {
					JOptionPane.showMessageDialog(frame, "Month must be entered", "ID Warning", JOptionPane.WARNING_MESSAGE);
					return;
				}
			}	
		}
		Date desired =new Date(year-1900,month-1,day);
		Date currentDate = new Date();

		if (desired.before(currentDate)) {
			JOptionPane.showMessageDialog(frame, "Rendezvous cannot be made for a past date!", "Date Warning", JOptionPane.WARNING_MESSAGE);
			return;
		}
		
		RendezvousThread rendezvousThread = new RendezvousThread(crs, natId, hospital, section, doctor, desired, frame);
		Thread thread = new Thread(rendezvousThread);
		thread.start();
	}
	
	
	private static void updateDoctorComboBoxes(Section section) {
        for(JComponent c:components) {
            if(c.getName().contains("MenuDoctor")) {
                JComboBox<Doctor> doctorComboBox=(JComboBox<Doctor>) c;
                DefaultComboBoxModel<Doctor> model= new DefaultComboBoxModel<>();
                for(Doctor d: section.listDoctors()) {
                    model.addElement(d);
                }
                doctorComboBox.setModel(model);
            }
        }
    }
	private static void updateSectionComboBox(Hospital hospital) {
	    for(JComponent c:components) {
	        if(c.getName().contains("MenuSection")) {
	            JComboBox<Section> sectionComboBox=(JComboBox<Section>) c;
	            DefaultComboBoxModel<Section> model= new DefaultComboBoxModel<>();
	            
	            for(Section s: hospital.getSections()) {
	                model.addElement(s);
	            }     
	            sectionComboBox.setModel(model);
	        }
	    }
	}
	private static void updateHospitalComboBoxes() {
		   for(JComponent c:components) {
		       if(c.getName().contains("MenuHospital")) {
		           JComboBox<Hospital> hospitalComboBox=(JComboBox<Hospital>) c;
		           DefaultComboBoxModel<Hospital> model= new DefaultComboBoxModel<>();
		           
		           for(Hospital h: crs.getHospitals().values()) {
		               model.addElement(h);
		           }    
		           hospitalComboBox.setModel(model);
		       }
		   }
	}
	
	public static void addHospitalButton() {
		setMenuVisible("hospitalMenu");
		frame.setTitle("Adding Hospital Menu");
	}
	public static void addSectionButton() {
		for(JComponent c : components) {
		       if(c.getName().contains("sectionMenuHospital")) {
		           JComboBox<Hospital> hospitalComboBox=(JComboBox<Hospital>) c;
		           DefaultComboBoxModel<Hospital> model= new DefaultComboBoxModel<>();
		           
		           for(Hospital h:crs.getHospitals().values()) {
		               model.addElement(h);
		           }
		           hospitalComboBox.setModel(model);
		           
		           hospitalComboBox.addActionListener(e -> {
		               Hospital selectedHospital=(Hospital) hospitalComboBox.getSelectedItem();
		               if(selectedHospital!=null) {
		                   updateSectionComboBox(selectedHospital);
		               }
		           });
		       }
		   }
		   frame.setTitle("Adding Section Menu");
		   setMenuVisible("sectionMenu");
	}
	public static void addDoctorButton() {
		for(JComponent c : components) {
	        if(c.getName().contains("MenuHospital")) {
	            JComboBox<Hospital> hospitalComboBox= (JComboBox<Hospital>) c;
	            DefaultComboBoxModel<Hospital> model= new DefaultComboBoxModel<>();
	            
	            for(Hospital h : crs.getHospitals().values()) {
	                model.addElement(h);
	            }   
	            hospitalComboBox.setModel(model);
	            
	            hospitalComboBox.addActionListener(e -> {//hospitale gore section
	                Hospital selectedHospital= (Hospital)hospitalComboBox.getSelectedItem();
	                if(selectedHospital!=null) {
	                    updateSectionComboBox(selectedHospital);
	                    
	                    for(JComponent comp : components) {
	                        if(comp.getName().contains("MenuSection")) {
	                            JComboBox<Section> sectionComboBox= (JComboBox<Section>) comp;
	                        }
	                    }
	                }
	            });
	        }
	    }
		
		setMenuVisible("doctorMenu");
		frame.setTitle("Adding Doctor Menu");
	}
	public static void newPatientButton() {
		setMenuVisible("patientMenu");
		frame.setTitle("Adding New Patient Menu");
	}
	public static void makeRendezvousButton() {
	    for(JComponent c : components) {
	        if(c.getName().contains("MenuHospital")) {
	            JComboBox<Hospital> hospitalComboBox= (JComboBox<Hospital>) c;
	            DefaultComboBoxModel<Hospital> model= new DefaultComboBoxModel<>();
	            
	            for(Hospital h : crs.getHospitals().values()) {
	                model.addElement(h);
	            }   
	            hospitalComboBox.setModel(model);
	            
	            hospitalComboBox.addActionListener(e -> {//hospitale gore section
	                Hospital selectedHospital= (Hospital)hospitalComboBox.getSelectedItem();
	                if(selectedHospital!=null) {
	                    updateSectionComboBox(selectedHospital);
	                    
	                    for(JComponent comp : components) {
	                        if(comp.getName().contains("MenuSection")) {
	                            JComboBox<Section> sectionComboBox= (JComboBox<Section>) comp;
	                            sectionComboBox.addActionListener(event -> {//sectiona gore doctor
	                                Section selectedSection= (Section)sectionComboBox.getSelectedItem();
	                                if(selectedSection!=null) {
	                                    updateDoctorComboBoxes(selectedSection);
	                                }
	                            });
	                        }
	                    }
	                }
	            });
	        }
	    }

	    setMenuVisible("rendezvousMenu");
	    frame.setTitle("Making Rendezvous Menu");
	}
	public static void backToMainMenu() {	
		setMenuVisible("main");
		frame.setTitle("Clinic Rezervation System");
	}
	
	public static void selectionOfProcess() throws IOException {
		System.out.println("Select the process you want:\n1-Adding Hospital\n2-Adding Section\n3-Adding Doctor\n4-New Patient Registration\n5-Make Rendezvous\n6-Save\n7-Load\n8-Exit");
		int input=scanner.nextInt();
		switch (input) {
		case 1:
			addHospitalConsole();		
			break;
		case 2:
			addSectionConsole();			
			break;
		case 3:
			addDoctorConsole();		
			break;
		case 4:
			addNewPatientConsole();		
			break;		
		case 5:
			addRendezvousConsole();		
			break;
		case 6:
			saveCrsConsole();		
			break;
		case 7:
			loadCrsConsole();		
			break;
		case 8:
			scanner.close();
			System.exit(0);			
			break;
		}
	}
	public static void addHospitalConsole() throws IOException {
		System.out.println("Hospital ID: ");
		int id=scanner.nextInt();
		scanner.nextLine();
		System.out.println("Hospital name: ");
		String name=scanner.nextLine();
		
		Hospital hospital=new Hospital(id, name);
		if(crsConsole.addHospital(id, hospital)) {
			System.out.println("Hospital saved");
		}
		
		selectionOfProcess();
	}
	public static void addSectionConsole() throws IOException {
		System.out.println("Section ID: ");
		int id=scanner.nextInt();
		scanner.nextLine();
		System.out.println("Section name: ");
		String name=scanner.nextLine();
		System.out.println("Hospital ID: ");
		int hospitalId=scanner.nextInt();
		scanner.nextLine();
		while(crsConsole.getHospitals().get(hospitalId)==null) {
			System.out.println("There is no hospital with this ID");
			System.out.println("Hospital ID: ");
			hospitalId=scanner.nextInt();
			scanner.nextLine();
		}
		
		Section section=new Section(id, name);
		
		if(crsConsole.getHospitals().get(hospitalId).addSection(section)) {
			System.out.println("Section saved");
		}
	
		selectionOfProcess();
	}
	public static void addDoctorConsole() throws IOException {
		System.out.println("Doctor ID: ");
		long id=scanner.nextLong();
		scanner.nextLine();
		System.out.println("Doctor name: ");
		String name=scanner.nextLine();
		System.out.println("Diploma ID: ");
		int dipId=scanner.nextInt();
		scanner.nextLine();
		System.out.println("Hospital ID: ");
		int hospitalId=scanner.nextInt();
		scanner.nextLine();
		while(crsConsole.getHospitals().get(hospitalId)==null) {
			System.out.println("There is no hospital with this ID");
			System.out.println("Hospital ID: ");
			hospitalId=scanner.nextInt();
			scanner.nextLine();
		}
		System.out.println("Section ID: ");
		int sectionId=scanner.nextInt();
		scanner.nextLine();
		while(crsConsole.getHospitals().get(hospitalId).getSection(sectionId)==null) {
			System.out.println("There is no section with this ID");
			System.out.println("Section ID: ");
			sectionId=scanner.nextInt();
			scanner.nextLine();
		}
		System.out.println("Max patient per day: ");
		int maxPat=scanner.nextInt();
		scanner.nextLine();
		
		if(maxPat<1) {
			maxPat=3;
		}
		Doctor doctor=new Doctor(name, id, dipId, maxPat);
		
		
		if(crsConsole.getHospitals().get(hospitalId).getSection(sectionId).addDoctor(doctor)) {
			System.out.println("Doctor saved");
		}
		selectionOfProcess();
	}
	public static void addNewPatientConsole() throws IOException {
		System.out.println("Patient ID: ");
		long id=scanner.nextLong();
		scanner.nextLine();
		System.out.println("Patient name: ");
		String name=scanner.nextLine();
		
		Patient patient=new Patient(name, id);
		if(crsConsole.addPatient(id, patient)) {
			System.out.println("Patient saved");
		}
		
		selectionOfProcess();
	}
	public static void addRendezvousConsole() throws IOException {
		System.out.println("Patient ID: ");
		long patId=scanner.nextLong();
		scanner.nextLine();
		System.out.println("Hospital ID: ");
		int hospitalId=scanner.nextInt();
		scanner.nextLine();
		while(crsConsole.getHospitals().get(hospitalId)==null) {
			System.out.println("There is no hospital with this ID");
			System.out.println("Hospital ID: ");
			hospitalId=scanner.nextInt();
			scanner.nextLine();
		}
		System.out.println("Section ID: ");
		int sectionId=scanner.nextInt();
		scanner.nextLine();
		while(crsConsole.getHospitals().get(hospitalId).getSection(sectionId)==null) {
			System.out.println("There is no section with this ID");
			System.out.println("Section ID: ");
			sectionId=scanner.nextInt();
			scanner.nextLine();
		}
		System.out.println("Doctor Diploma ID: ");
		int dipId=scanner.nextInt();
		scanner.nextLine();
		while(crsConsole.getHospitals().get(hospitalId).getSection(sectionId).getDoctor(dipId)==null) {
			System.out.println("There is no doctor with this ID");
			System.out.println("Doctor Diploma ID: ");
			dipId=scanner.nextInt();
			scanner.nextLine();
		}
		System.out.print("Date(dd.mm.yyyy or dd/mm/yyyy): ");
		String dateInput=scanner.nextLine();
		String[] dateData = dateInput.split("[./]");
		int day = Integer.parseInt(dateData[0]);
        int month = Integer.parseInt(dateData[1]);
        int year = Integer.parseInt(dateData[2]);
		Date date=new Date(year-1900,month-1,day);
		while(date.before(new Date())) {
			System.out.println("Rendezvous cannot be made for a past date!");
			System.out.print("Date(dd.mm.yyyy or dd/mm/yyyy): ");
			dateInput=scanner.nextLine();
			dateData = dateInput.split("[./]");
			day = Integer.parseInt(dateData[0]);
	        month = Integer.parseInt(dateData[1]);
	        year = Integer.parseInt(dateData[2]);
			date=new Date(year-1900,month-1,day);
		}
			
		Doctor dr=crsConsole.getHospitals().get(hospitalId).getSection(sectionId).getDoctor(dipId);
		Rendezvous rendezvous=new Rendezvous(date, crsConsole.getPatients().get(patId), dr);
		if(dr.getSchedule().addRendezvous(crsConsole.getPatients().get(patId), date)!=null) {
			System.out.println("Rendezvous saved");
		}
		
		selectionOfProcess();
	}
	
	public static void saveCrsConsole() throws IOException {
		crsConsole.saveTablesToDisk("crs.ser");
		selectionOfProcess();
	}
	public static void loadCrsConsole() throws IOException {
		crsConsole=crsConsole.loadTablesToDisk("crs.ser");
		selectionOfProcess();
	}

	public static void main(String[] args) throws InterruptedException, IOException {
		crs=new CRS();
		components= new ArrayList<JComponent>();
		mode = 0;
		System.out.println("Choose Mode\n1-GUI mode\n2-ConsoleMode");
		mode=scanner.nextInt();
		scanner.nextLine();
		switch (mode) {
			case 1: {
				Dimension screenSize=Toolkit.getDefaultToolkit().getScreenSize();
				int screenHeight = (int)(screenSize.height*0.8f);
				int screenWidth = (int)(screenSize.width*0.8f);
				
				frame =new JFrame("Clinic Rezervation System");
				frame.setSize(screenWidth, screenHeight);
				createAllGUIComponents();
				setMenuVisible("main");
				
				
				frame.setLayout(null);
				frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				frame.setVisible(true);
				break;
			}
			case 2: {
				selectionOfProcess();
				break;
			}			
		}
	}

	
}