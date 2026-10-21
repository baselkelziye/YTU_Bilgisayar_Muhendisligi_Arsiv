package tariktaskin;

import java.util.LinkedList;

public class Victim {
	private String name;
	private LinkedList<EmergencyProcedure> emergencyProcedures; 

	public Victim(String name) {
		super();
		this.name = name;
		emergencyProcedures = new LinkedList<EmergencyProcedure>();
	}

	public LinkedList<EmergencyProcedure> getEmergencyProcedures() {
		return emergencyProcedures;
	}
	

	@Override
	public String toString() {
		return "Victim: " + name;
	}
	
	
}
