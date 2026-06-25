package nyp_project;

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
		doctors = new LinkedList<Doctor>();
	}
	
	public int getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public void ListDoctors() {
		System.out.println("== List of "+ this.name +"Doctors ==");
		for(Doctor d:doctors) {
			System.out.println(d.toString());
		}
	}
	
	public Doctor getDoctor(int diploma_id) {
		for(Doctor d:doctors) {
			if(d.getDiploma_id() == diploma_id)
				return d;
		
		}
		return null;
	}
	
	public void AddDoctor(Doctor doctor) throws DuplicateException{
		for(Doctor d:doctors) {
			if(d.getDiploma_id() == doctor.getDiploma_id()) {
				throw new DuplicateException(" Duplicate error! - Already a doctor added with same id.");
			}	
		}
		doctors.add(doctor);
	}

	public LinkedList<Doctor> getDoctors() {
		return doctors;
	}
	
	
	
}
