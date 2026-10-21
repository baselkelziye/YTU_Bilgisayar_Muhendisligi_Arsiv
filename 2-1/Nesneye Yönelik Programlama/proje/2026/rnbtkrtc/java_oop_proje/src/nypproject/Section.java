package nypproject;

import java.io.Serializable;
import java.util.Collection;
import java.util.LinkedList;

public class Section implements Serializable {
	private static final long serialVersionUID = 1L;
	
	private final int id;
	private String name;
	private LinkedList<Doctor> doctors;
	private Hospital ownerHospital; // GUI'da hangi sectionın hangi hospitala ait olduğuna
									// daha kolay bir şekilde erişmek için kullanılıyor
	
	public Section(int id,String name) 
	{
		this.id = id;
		this.name = name;
		doctors = new LinkedList<Doctor>();
	}
	
	public void setHospital(Hospital hospital) {
		ownerHospital = hospital;
	}
	
	public Hospital getHospital() {
		return ownerHospital;
	}
	
	public Section(int id,String name,LinkedList<Doctor> doctors) 
	{
		this.id = id;
		this.name = name;
		this.doctors = doctors;
	}
	
	public int getID() 
	{
		return id;
	}
	
	public String getName() 
	{
		return name;
	}
	
	public void listDoctors() 
	{
		for(Doctor doctor : doctors)
		{
			System.out.println(doctor);
		}
	}
	
	public Doctor getDoctor(int diploma_id)
	{
		for(Doctor doctor : doctors) 
		{
			if(doctor.getDiplomaID() == diploma_id) 
			{
				return doctor;
			}
		}
		System.out.println("Doctor with id " + diploma_id + " couldn't be found!");
		return null;
	}
	
	public Collection<Doctor> getDoctors(){
		return doctors;
	}
	
	
	public void addDoctor(Doctor doctor) 
	{
		if(getDoctor(doctor.getDiplomaID()) != null) 
		{
			if(CRS.GUIMode)
				return;
			throw new DuplicateInfoException("A doctor with this id already exists!");
		}
		else 
		{
			doctors.add(doctor);
		}
	}
	
	public void removeDoctor(int diplomaID) {
		Doctor doctor = getDoctor(diplomaID);
		doctors.remove(doctor);
	}
	
	public void clearDoctorList() {
		doctors.clear();
	}
	
	public String toString() {
		return name+"-"+id+"-"+ownerHospital.getID();
	}

}
