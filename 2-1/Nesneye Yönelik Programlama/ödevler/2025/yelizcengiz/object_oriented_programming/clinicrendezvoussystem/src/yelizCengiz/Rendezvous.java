package yelizCengiz;

import java.io.Serializable;
import java.util.Date;

public class Rendezvous implements Serializable{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Date dateTime;
	private Patient patient;
	private Doctor doctor;
	
	public Rendezvous(Date dateTime, Patient patient,Doctor doctor) {
		this.dateTime = dateTime;
		this.patient = patient;
		this.doctor=doctor;
	}
	public Date getDateTime() {
        return dateTime;
    }
	public Patient getPatient() {
		return patient;
	}
	public Doctor getDoctor() {
		return doctor;
	}
	public void setDateTime(Date dateTime) {
		this.dateTime = dateTime;
	}
	public String  toString() {
		return "\ndr:"+doctor.getName()+"\tpatient:"+patient.getName()+"\tDate:"+getDateTime();
	}

}
