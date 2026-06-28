package nyp_project;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Date;
import java.util.HashMap;
import java.util.LinkedList;

public class CRS {
	private HashMap<Long,Patient> patients;
	private LinkedList<Randezvous>  randezvous;
	private HashMap<Integer,Hospital> hospitals;

	public CRS() {
		this.patients = new HashMap<Long,Patient>() ;
		this.randezvous = new LinkedList<Randezvous>();
		this.hospitals = new HashMap<Integer,Hospital>();
	}
	
	public void addPatient(String name, long id) {
		Patient patient = new Patient(name ,id);
		patients.put(id,patient);
	}
	
	public void addHospital(int id, String name) {
		Hospital hospital = new Hospital(id ,name);
		hospitals.put(id,hospital);
	}
	
	public void addSection(int hospital_id, int id, String name) {
		Section section = new Section(id,name);
		hospitals.get(hospital_id).AddSection(section);
	}
	
	public void addSection(String hospital_name, int id, String name) {
		Section section = new Section(id,name);
		for(Hospital h:hospitals.values()) {
			if(h.getName() == hospital_name) {
				h.AddSection(section);
			}
		}
	}
	
	public void addDoctor(String hospital_name,String section_name, String name, int national_id, int diploma_id, int maxPatientPerDay) {
		Doctor doctor = new Doctor(name, national_id, national_id, maxPatientPerDay);
		for(Hospital h:hospitals.values()) {
			if(h.getName() == hospital_name) {
				h.getSection(section_name).AddDoctor(doctor);
			}
		}
	}
	
	public void addDoctor(int hospital_id,int section_id, String name, int national_id, int diploma_id, int maxPatientPerDay) {
		Doctor doctor = new Doctor(name, national_id, diploma_id, maxPatientPerDay);
		hospitals.get(hospital_id).getSection(section_id).AddDoctor(doctor);
	}
	
	public void listAll() {
		System.out.println("Hospitals:");
	    for (Integer id : hospitals.keySet()) {
	        Hospital hospital = hospitals.get(id);
	        System.out.println("ID: " + id + ", Name: " + hospital.getName());
	        for(Section s:hospital.getSections()) {
	        	System.out.println("	ID: " + s.getId() + ", Name: " + s.getName());
	        	for(Doctor d:s.getDoctors()) {
	        		System.out.println("		ID: " + d.getNational_id() + ", Name: " + d.getName() + ", Diploma ID: " + d.getDiploma_id());
	        	}
	        }
	        System.out.print("\n");
	        
	    }
	}
	
	public void listHospitals() {
		for (Integer id : hospitals.keySet()) {
	        Hospital hospital = hospitals.get(id);
	        System.out.println(id + "- " + hospital.getName());
	        System.out.print("\n");
		}
	}
		
	
	public void listSections(int hospital_id) {
		hospitals.get(hospital_id).listSections();
	}
	
	public void listDoctors(int hospital_id,int section_id) {
		hospitals.get(hospital_id).getSection(section_id).ListDoctors();
		
	}
	
	public void listRandezvous() {
		System.out.println("Randezvous:");
		for(Randezvous r:randezvous) {
			System.out.println("Patient: " + r.getPatient() + " Date: " + r.getDatetime() + "Doctor" + r.getDoctor());
		}
	}
	
	public void listPatients() {
		System.out.println("Patients:");
		for(Long id: patients.keySet()) {
			Patient patient = patients.get(id);
			System.out.println("ID: " + id + ", Name: " + patient.getName());
		}
	}
	
	public boolean makeRandezvous(long patientID, int hospitalID,int sectionID,int diplomaID,Date desiredDate) throws IDException {
		boolean add_flag;
		Patient patient = patients.get(patientID);
		if (patient == null) {throw new IDException("IDException exception! - Patient can't found!"); }
		
		Hospital hospital = hospitals.get(hospitalID);
		if (hospital == null) {throw new IDException("IDException exception! - Hospital can't found!"); }
		
		Section section = hospital.getSection(sectionID);
		if (section == null) {throw new IDException("IDException exception! - Section can't found!"); }
		
		Doctor doctor = section.getDoctor(diplomaID);
		if (doctor == null) {throw new IDException("IDException exception! - Doctor can't found!"); }
		
		add_flag = doctor.getSchedule().addRandezvous(patient, desiredDate,doctor);
		
		if(add_flag == true) {
			randezvous.add(doctor.getSchedule().getSessions().getLast());
		}
		return add_flag;
	}
	
	public boolean saveTablesToDisk(String fullPath) {
		System.out.println("Save tables to disk: ");
		FileOutputStream fos = null;
		ObjectOutputStream oos = null;
		boolean flag = true;
		
		try {
			fos = new FileOutputStream(fullPath);
			oos = new ObjectOutputStream(fos);
			
			oos.writeObject(patients);
			oos.writeObject(randezvous);
			oos.writeObject(hospitals);

			oos.close();
			fos.close();
			flag = true;
		}
		catch(FileNotFoundException e) {
			e.printStackTrace();
			flag = false;
		}
		catch(IOException e) {
			e.printStackTrace();
			flag = false;
		}
		return flag;
	}
	
	public boolean loadTablesToDisk(String fullPath) {
		boolean flag = true;
			System.out.println("Load tables from disk: ");

			FileInputStream fis = null;
			ObjectInputStream ois = null;
			
			try {

				fis = new FileInputStream(fullPath);
				ois = new ObjectInputStream(fis);
				patients = (HashMap<Long,Patient>) ois.readObject();
				randezvous = (LinkedList<Randezvous>) ois.readObject();
				hospitals = (HashMap<Integer,Hospital>) ois.readObject();

				ois.close();
				fis.close();
				
				flag = true;
				
			}
			catch(ClassNotFoundException e) {
				e.printStackTrace();
				flag = false;
			}
			catch(IOException e) {
				e.printStackTrace();
				flag = false;
			}
			return flag;
		}

	public HashMap<Long, Patient> getPatients() {
		return patients;
	}

	public LinkedList<Randezvous> getRandezvous() {
		return randezvous;
	}

	public HashMap<Integer, Hospital> getHospitals() {
		return hospitals;
	}
	
}
