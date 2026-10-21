package nypproject;

import java.io.Serializable;
import java.util.Calendar;
import java.util.Date;
import java.util.LinkedList;

public class Schedule implements Serializable {
	private static final long serialVersionUID = 1L;
	
	private LinkedList<Rendezvous> sessions;
	private Doctor owner;
	private int maxPatientPerDay;
	private Rendezvous lastAddedRendezvous;
	
	public Schedule(int maxPatientPerDay,Doctor owner) {
		this.maxPatientPerDay = maxPatientPerDay;
		this.owner = owner;
		sessions = new LinkedList<Rendezvous>();
	}
	
	public boolean addRendezvous(Patient p, Date desired) {
		Calendar desiredCalendar = Calendar.getInstance();
	    Calendar checkCalendar = Calendar.getInstance();
	    
	    desiredCalendar.setTime(desired);
	    
	    int desiredDay = desiredCalendar.get(Calendar.DAY_OF_YEAR);
	    int desiredYear = desiredCalendar.get(Calendar.YEAR);
	    
	    int count = 0;

	    for (Rendezvous session : sessions) {
	        checkCalendar.setTime(session.getDate());
	        int checkYear = checkCalendar.get(Calendar.YEAR);
	        int checkDay = checkCalendar.get(Calendar.DAY_OF_YEAR);
	        
	        if(checkYear == desiredYear && checkDay == desiredDay)
	        {
	        	count++;
	        	if(count >= maxPatientPerDay) {
	        		return false;
	        	}
	        }
	    }
	    lastAddedRendezvous = new Rendezvous(desired,p,owner);
	    sessions.add(lastAddedRendezvous);
	    return true;
	}
	
	public Rendezvous getLastAddedRendezvous() 
	{
		return lastAddedRendezvous;
	}
}
