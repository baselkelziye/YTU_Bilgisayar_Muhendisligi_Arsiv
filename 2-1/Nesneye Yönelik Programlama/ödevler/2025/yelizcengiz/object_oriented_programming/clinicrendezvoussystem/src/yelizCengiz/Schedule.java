package yelizCengiz;

import java.io.Serializable;
import java.util.Calendar;
import java.util.Date;
import java.util.LinkedList;

public class Schedule implements Serializable{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private LinkedList<Rendezvous> sessions;
	private int maxPatientPerDay;
	private Doctor doctor;
	
	public Schedule(int maxPatientPerDay,Doctor doctor) {
		this.maxPatientPerDay = maxPatientPerDay+1;
		this.doctor=doctor;
		sessions=new LinkedList<Rendezvous>();
	}
	
	public Rendezvous addRendezvous(Patient p,Date desired) {
		Calendar desiredCal = Calendar.getInstance();
	    desiredCal.setTime(desired);

	    int count = 0;
	    for (Rendezvous r : sessions) {
	        Calendar sessionCal = Calendar.getInstance();
	        sessionCal.setTime(r.getDateTime());

	        if (sessionCal.get(Calendar.YEAR) == desiredCal.get(Calendar.YEAR) &&
	        		sessionCal.get(Calendar.DAY_OF_YEAR) == desiredCal.get(Calendar.DAY_OF_YEAR)) {
	            count++;
	        }
	    }
		if (count > maxPatientPerDay) {
            return null;
        }
        else {
        	Rendezvous rendezvous=new Rendezvous(desired,p,doctor);
        	sessions.add(rendezvous);
            return rendezvous;
        }
        
	}
	
	public int getMaxPatientPerDay() {
		return maxPatientPerDay;
	}

	public Doctor getScheduleDoctor() {
		return doctor;
	}
	
	@Override
	public String toString() {
		String str="";
		for(Rendezvous r:sessions) {
			str+=r.getPatient().toString()+"\t"+r.getDateTime().toLocaleString()+"\n";
		}
		return str;
	}
}
