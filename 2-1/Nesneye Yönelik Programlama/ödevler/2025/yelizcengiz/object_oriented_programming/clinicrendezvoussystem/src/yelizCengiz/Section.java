package yelizCengiz;

import java.io.Serializable;
import java.util.LinkedList;

public class Section implements Serializable{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private final int id;
	private String name;
	private LinkedList<Doctor> doctors;
	
	public Section(int id, String name) {
		this.id = id;
		this.name = name;
		doctors=new LinkedList<Doctor>();
	}
	
	public int getId() {
		return id;
	}
	
	public String getName() {
		return name;
	}
	
	public LinkedList<Doctor> listDoctors(){
		return doctors;
	}
	
	public Doctor getDoctor(int diploma_id) {
		for(Doctor d: doctors) {
			if(d.getDiplomaId()==diploma_id) {
				return d;
			}
		}
		return null;
	}
	public Doctor getDoctor(String name) {
		for(Doctor d: doctors) {
			if(d.getName()==name) {
				return d;
			}
		}
		return null;
	}
	
	public boolean addDoctor(Doctor doctor) throws DuplicateInfoException{
		for(Doctor d: doctors) {
			if(d.getDiplomaId()==doctor.getDiplomaId()) {
				throw new DuplicateInfoException("ayni idye sahip doktor girisi");
			}
		}
		doctors.add(doctor);
		return true;
	}
	
	public String toString() {
		return this.name;
	}
	
}
