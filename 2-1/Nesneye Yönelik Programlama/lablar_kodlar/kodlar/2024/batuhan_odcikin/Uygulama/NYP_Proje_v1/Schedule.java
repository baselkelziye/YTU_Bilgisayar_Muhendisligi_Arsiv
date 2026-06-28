package nyp_project;

import java.util.Date;
import java.util.Calendar;
import java.io.Serializable;
import java.util.ArrayList;

public class Schedule implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private ArrayList<Randezvous> sessions;
	private int maxPatientPerDay;
	
	public Schedule(int maxPatientPerDay) {
		this.maxPatientPerDay = maxPatientPerDay;
		sessions = new ArrayList<Randezvous>();
		
	}

	public boolean addRandezvous(Patient p, Date desired,Doctor doctor) {
		Randezvous randezvous = new Randezvous(p, desired,doctor);
		int randezvouz_ctr = 0;
		
		Calendar desiredCalendar = Calendar.getInstance();
	    desiredCalendar.setTime(desired);
	    
		for(Randezvous r: sessions) {
			Calendar existingCalendar = Calendar.getInstance();
	        existingCalendar.setTime(r.getDatetime());
	        
	        if (desiredCalendar.get(Calendar.YEAR) == existingCalendar.get(Calendar.YEAR) &&
	                desiredCalendar.get(Calendar.DAY_OF_YEAR) == existingCalendar.get(Calendar.DAY_OF_YEAR)) {
	    			randezvouz_ctr++;
	        	if(randezvouz_ctr >= maxPatientPerDay) 
	    			return false;
	    		
	            }
		}
		

		sessions.add(randezvous);
		return true;
	}
		
	public ArrayList<Randezvous> getSessions() {
		return sessions;
	}
}
