package nypproject;

import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Date;
import java.util.HashMap;
import java.util.LinkedList;

public class CRS {
	private HashMap<Long,Patient> patients;
	private LinkedList<Rendezvous> rendezvous;
	private HashMap<Integer,Hospital> hospitals;
	public static boolean GUIMode = false;
	
	
	public CRS(boolean gui) 
	{
		patients = new HashMap<Long,Patient>();
		rendezvous = new LinkedList<Rendezvous>();
		hospitals = new HashMap<Integer,Hospital>();
		GUIMode = gui;
	}
	
	public boolean makeRandezvous(long patientID, int hospitalID, int sectionID,int diplomaID,Date desiredDate) 
	{
		if(checkMatchingID(patients.keySet(),patientID) && checkMatchingID(hospitals.keySet(),hospitalID)) 
		{
			Schedule schedule = hospitals.get(hospitalID).getSection(sectionID).
					getDoctor(diplomaID).getSchedule();
			if(schedule.addRendezvous(patients.get(patientID), desiredDate))
			{
				rendezvous.add(schedule.getLastAddedRendezvous());
				return true;
			}
			System.out.println("Max rendezvous limit exceeded.");
			return false;
		}
		else
		{
			System.out.println("Not matching id when creating a new rendezvous.");
			return false;
		}
	}
	
	
	private <T> boolean checkMatchingID(Collection<T> collection, T id) 
	{
		if(collection.contains(id)) 
		{
			return true;
		}
		else 
		{
			if(GUIMode) 
			{
				return false;
			}
			else
			{
				throw new IDException("Invalid id");
			}
		}
	}
	
	public void saveTablesToDisk(String fullpath) 
	{
		//try-with-resources .close() işlemini otomatik olarak yapıtığı için ekstra koymadım
		try(FileOutputStream fos = new FileOutputStream(fullpath);
		ObjectOutputStream oos = new ObjectOutputStream(fos);)
		{
			
			for(Hospital hospital : hospitals.values()) {
				oos.writeObject(hospital);
			}
			for(Patient patient : patients.values()) {
				oos.writeObject(patient);
			}
			for(Rendezvous singularRendezvous: rendezvous) {
				oos.writeObject(singularRendezvous);
			}
			
		}
		catch(IOException error)
		{
			error.printStackTrace();
		}
	}
	
	public void loadTablesToDisk(String fullpath) 
	{
	    File file = new File(fullpath);
		if (!file.exists()) {
	        try {
	            if (file.createNewFile()) {
	                System.out.println("File created: " + file.getName());
	            }
	        } catch (IOException e) {
	            System.err.println("Error creating the file: " + e.getMessage());
	            e.printStackTrace();
	            return;
	        }
	    }
		
		if (file.length() == 0) {
	        System.out.println("File is empty.");
	        return;
	    }
		
		try (FileInputStream fis = new FileInputStream(fullpath);
	    ObjectInputStream ois = new ObjectInputStream(fis);) 
		{
			Object obj;
	        while (true) {
	            try 
	            {
	                obj = ois.readObject();
	            } 
	            catch (EOFException e) 
	            {
	                break;
	            }
	            if (obj instanceof Hospital) 
	            {
	                Hospital hospital = (Hospital) obj;
	                hospitals.put(hospital.getID(), hospital);
	            } 
	            else if (obj instanceof Patient) 
	            {
	                Patient patient = (Patient) obj;
	                patients.put(patient.getNationalID(), patient);
	            }
	            else if (obj instanceof Rendezvous) 
	            {
	                Rendezvous singularRendezvous = (Rendezvous) obj;
	                rendezvous.add(singularRendezvous);
	            }
	        }
	    } 
		catch (IOException | ClassNotFoundException e) 
		{
	        e.printStackTrace();
	    }
	}
	
	public boolean addPatient(Patient patient) 
	{
		if(searchNatIDInPerson(patient.getNationalID())) 
		{
			patients.put(patient.getNationalID(),patient);
			return true;
		}
		else 
		{
			return false;
		}
		
	}
	
	//kimlik numarası kişiye özel 
	private boolean searchNatIDInPerson(long id){
		
		for(Patient patient:patients.values()) 
		{
			if(id == patient.getNationalID()) 
			{
				return false;
			}
		}
		for(Hospital hospital :hospitals.values()) 
		{
			for(Section section : hospital.getSections()) 
			{
				for(Doctor doctor : section.getDoctors()) 
				{
					if(id == doctor.getNationalID()) {
						return false;
					}
				}
			}
		}
		return true;
	}
	
	public boolean searchDipIDInDoctors(int id) {
		for(Hospital hospital :hospitals.values()) 
		{
			for(Section section : hospital.getSections()) 
			{
				for(Doctor doctor : section.getDoctors()) 
				{
					if(id == doctor.getDiplomaID()) {
						return false;
					}
				}
			}
		}
		return true;
	}
	
	public void removePatient(long id) 
	{
		patients.remove(id);
	}
	
	public boolean addHospital(Hospital hospital) 
	{
		for(Hospital existingHospital : hospitals.values()) {
			if(existingHospital.getID() == hospital.getID()) {
				return false;
			}
		}
		hospitals.put(hospital.getID(),hospital);
		return true;
	}
	
	
	public void removeHospital(int id) 
	{
		hospitals.remove(id);
	}
	
	public void clearRendezvous() 
	{
		rendezvous.clear();
	}
	
	public ArrayList<Patient> getPatients(){
		return new ArrayList<Patient>(patients.values());
	}
	
	public Patient getPatient(long natID) {
		return patients.get(natID);
	}
	
	public ArrayList<Hospital> getHospitals(){
		return new ArrayList<Hospital>(hospitals.values());
	}
	
	public ArrayList<Doctor> getDoctors(){
		ArrayList<Doctor> doctors = new ArrayList<Doctor>();
		for(Hospital hospital: hospitals.values()) {
			for(Section section :hospital.getSections()) {
				for(Doctor doctor: section.getDoctors()) {
					doctors.add(doctor);
				}
			}
		}
		return doctors;
	}
	
	public Hospital getHospital(int id) {
		return hospitals.get(id);
	}
	
	public Doctor getDoctor(int dipID) {
		for(Hospital hospital: hospitals.values()) {
			for(Section section :hospital.getSections()) {
				for(Doctor doctor: section.getDoctors()) {
					if(doctor.getDiplomaID() == dipID) {
						return doctor;
					}
				}
			}
		}
		return null;
	}
	
	public ArrayList<Section> getSections(){
		ArrayList<Section> sections = new ArrayList<Section>();
		for(Hospital hospital: hospitals.values()) {
			for(Section section :hospital.getSections()) {
				sections.add(section);
			}
		}
		return sections;
	}
	
	public LinkedList<Rendezvous> getAllRendezvous() {
		return rendezvous;
	}
	
	public Rendezvous getMatchingRendezvous(String doctorStr, String patientStr, String dateStr) {
		for(Rendezvous singularRendezvous : rendezvous) {
			if(singularRendezvous.getDoctor().toString().equals(doctorStr) &&
			   singularRendezvous.getPatient().toString().equals(patientStr) &&
			   singularRendezvous.getDate().toString().equals(dateStr)) {
				return singularRendezvous;
			}
			else {
				System.out.println(singularRendezvous.getDoctor().toString());
				System.out.println(singularRendezvous.getPatient().toString());
				System.out.println(singularRendezvous.getDate().toString());
				System.out.println(doctorStr);
				System.out.println(patientStr);
				System.out.println(dateStr);
				System.out.println(doctorStr.equals(singularRendezvous.getDoctor().toString()));
				System.out.println(singularRendezvous.getPatient().toString().equals(patientStr));
				System.out.println(singularRendezvous.getDate().toString().equals(dateStr));
			}
		}
		return null;
	}
	
	public boolean removeRendezvous(String doctorStr, String patientStr, String dateStr) {
		return rendezvous.remove(getMatchingRendezvous(doctorStr, patientStr,dateStr));
	}
	
	public void resetEverything(){
		hospitals.clear();
		rendezvous.clear();
		patients.clear();
	}
	
	
}
