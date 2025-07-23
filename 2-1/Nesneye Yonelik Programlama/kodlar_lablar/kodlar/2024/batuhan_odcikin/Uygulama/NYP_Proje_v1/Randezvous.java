package nyp_project;

import java.io.Serializable;
import java.util.Date;

public class Randezvous implements Serializable{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Date datetime;
	private Patient patient;
	private Doctor doctor;

	public Randezvous(Patient patient, Date datetime) {
		this.datetime = datetime;
		this.patient = patient;
	}
	
	public Randezvous(Patient patient, Date datetime,Doctor doctor) {
		this.datetime = datetime;
		this.patient = patient;
		this.doctor = doctor;
	}
	
	public Date getDatetime() {
		return datetime;
	}

	public Patient getPatient() {
		return patient;
	}
	
	public Doctor getDoctor() {
		return doctor;
	}

	public void setDoctor(Doctor doctor) {
		this.doctor = doctor;
	}
	
}
