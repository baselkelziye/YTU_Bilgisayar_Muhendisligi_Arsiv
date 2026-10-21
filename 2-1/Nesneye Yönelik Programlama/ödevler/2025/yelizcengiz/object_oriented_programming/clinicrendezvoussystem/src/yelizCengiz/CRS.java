package yelizCengiz;

import java.io.*;
import java.util.Date;
import java.util.Hashtable;
import java.util.LinkedList;

import javax.swing.JFrame;

public class CRS implements Serializable  {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Hashtable<Long, Patient> patients;
	private LinkedList<Rendezvous> rendezvous;
	private Hashtable<Integer, Hospital> hospitals;
	public static JFrame pano;
	
	
	public CRS() {
		patients= new Hashtable<Long, Patient>();
		rendezvous= new LinkedList<Rendezvous>();
		hospitals= new Hashtable<Integer, Hospital>();
	}
	
	public boolean addHospital(int id,Hospital hospital) {
		if(!hospitals.containsKey(id)) {
			hospitals.put(id, hospital);
			return true;
		}
		return false;
	}
	
	public boolean addPatient(long patientId,Patient patient) {
		if(!patients.containsKey(patientId)) {
			patients.put(patientId, patient);
			return true;
		}
		return false;
	}
	
	public Hashtable<Long, Patient> getPatients() {
		return patients;
	}

	public LinkedList<Rendezvous> getRendezvous() {
		return rendezvous;
	}

	public Hashtable<Integer, Hospital> getHospitals() {
		return hospitals;
	}

	
	public synchronized boolean makeRendezvous(Long patientId,int hospitalId,int sectionId,int diplomaId,Date desiredDate) throws IDException{
		Patient patient = patients.get(patientId);
		if(patient==null) {
			throw new IDException("bu ıdye sahip hasta yok");
		}
		if(hospitals.containsKey(hospitalId)==false) {
			//throw new IDException("bu ıdye sahip hastane yok");
		}
		if(hospitals.get(hospitalId).getSection(sectionId)==null) {
			throw new IDException("bu hastanede bu ıdye sahip section yok");
		}
		Doctor dr =hospitals.get(hospitalId).getSection(sectionId).getDoctor(diplomaId);
		if(dr==null) {
			throw new IDException("bu sectionda bu ıdye sahip doktor yok");
		}

		Rendezvous rendezvous=dr.getSchedule().addRendezvous(patient, desiredDate);
        if (dr.getSchedule().addRendezvous(patient, desiredDate)==null) {
        	if(Main.mode==1){//guı
        		return false;
        	}else {
        		throw new RuntimeException("Max patients");
        	}
        }
        else {
        	this.rendezvous.add(rendezvous);
        	patient.setRendezvous(rendezvous);
        	return true;
        }
	}
	
	public boolean saveTablesToDisk(String fullPath) throws IOException {
		FileOutputStream fos = null;
		ObjectOutputStream oos = null;
		boolean flag=false;
		try {
			fos =new FileOutputStream(fullPath);
			oos = new ObjectOutputStream(fos);
			oos.writeObject(this);
			flag=true;
		} catch (IOException e) {
			throw new IOException("save error");
		}
		finally {
			oos.close();
			fos.close();
		}
		return flag;
	}
	
	public CRS loadTablesToDisk(String fullPath) throws IOException {
		FileInputStream fis = null;
		ObjectInputStream ois = null;
		CRS crs=new CRS();
		try {
			fis=new FileInputStream(fullPath);
			ois=new ObjectInputStream(fis);
			
			crs= (CRS)ois.readObject();
		
			return crs;
		} catch (Exception e) {
			// TODO: handle exception
		}
		
		finally {
			fis.close();
			ois.close();
		}
		return crs;
	}
	
	public String toString() {
		return "\npatients:"+patients.toString()+"\nhospital:"+ hospitals.toString()+"\nrendezvous:"+rendezvous.toString();
	}
	
	
}
