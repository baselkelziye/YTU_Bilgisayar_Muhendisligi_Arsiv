package yusufsafakoksal;

import java.util.ArrayList;
import java.util.Random;

public class Doctor implements ISurgeon,IMedicalPersonel {
	private static ArrayList<Doctor> doctorList=new ArrayList<Doctor>(); //***
	private String name;
	private double experience;
	private int surgeries=2;
	
	public Doctor(String name) {
		this.name=name;
		this.experience=0;
		doctorList.add(this);
	}
	
	public static ArrayList<Doctor> getDoctorList() {
		return doctorList;
	}

	public int getSurgery() {
		return surgeries;
	}

	@Override
	public void performSurgery() throws SurgeryUnsuccessfulException{
		double random=new Random().nextDouble();
		
		if(random>=0.2 && surgeries>0) {
			experience+=2.5;
			surgeries--;
		}
		else {
			surgeries-=2;
			throw new SurgeryUnsuccessfulException("Treatment Fail Error!!!!");
		}
	}
	
	@Override
	public String getName() {
		return this.name;
	}

	@Override
	public String toString() {
		return "Doctor [name=" + name + ", experience=" + experience + ", surgeries="
				+ surgeries + "]";
	}
}
