package nypproject;

import java.io.Serializable;
import java.util.Date;

public class Rendezvous implements Serializable {
	private static final long serialVersionUID = 1L;
	
	private Date dateTime;
	private Patient patient;
	private Doctor doctor;
	
	public Rendezvous(Date dateTime,Patient patient,Doctor doctor) {
		this.dateTime = dateTime;
		this.patient = patient;
		this.doctor = doctor;
	}
	
	public Date getDate() {
		return dateTime;
	}
	
	public Doctor getDoctor() {
		return doctor;
	}
	
	public Patient getPatient() {
		return patient;
	}
	
	public void setDoctor(Doctor doctor) {
		this.doctor = doctor;
	}
	
	public void setPatient(Patient patient) {
		this.patient = patient;
	}
}
