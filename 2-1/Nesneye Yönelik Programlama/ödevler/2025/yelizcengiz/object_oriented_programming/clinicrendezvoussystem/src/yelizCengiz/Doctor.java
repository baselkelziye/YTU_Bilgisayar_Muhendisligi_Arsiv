package yelizCengiz;

import java.util.Date;

public class Doctor extends Person{

	private final int diploma_id;
	private Schedule schedule;
	
	public Doctor(String name, long national_id, int diploma_id) {
		super(name, national_id);
		this.diploma_id = diploma_id;
		schedule= new Schedule(3,this);
	}
	public Doctor(String name, long national_id, int diploma_id,int maxPatientPerDay) {
		super(name, national_id);
		this.diploma_id = diploma_id;
		schedule= new Schedule(maxPatientPerDay,this);
	}
	
	public int getDiplomaId() {
		return diploma_id;
	}
	
	public Schedule getSchedule() {
		return schedule;
	}


	@Override
	public String toString() {
		return getName();
	}
	
}
