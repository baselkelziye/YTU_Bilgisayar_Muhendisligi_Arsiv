package tariktaskin;

import java.util.ArrayList;

public class EmergencyRoom {
	private static int nextEmergencyRoomNumber = 1;
	private int emergencyRoomNumber;
	private int durationOfStay;
	private ArrayList<EmergencyProcedure> emergencyProcedures;

	public EmergencyRoom(int durationOfStay) {
		super();
		this.durationOfStay = durationOfStay;
		emergencyProcedures = new ArrayList<EmergencyProcedure>();
		emergencyRoomNumber = nextEmergencyRoomNumber;
		nextEmergencyRoomNumber++;
		
	}

	public int getEmergencyRoomNumber() {
		return emergencyRoomNumber;
	}
	
	
	public void addEmergencyProcedure(EmergencyProcedure procedure) {
		emergencyProcedures.add(procedure);
	}

	@Override
	public String toString() {
		return "EmergencyRoom: " + getEmergencyRoomNumber() + " , Duration of Stay: " + durationOfStay;
	}
	
	
}
