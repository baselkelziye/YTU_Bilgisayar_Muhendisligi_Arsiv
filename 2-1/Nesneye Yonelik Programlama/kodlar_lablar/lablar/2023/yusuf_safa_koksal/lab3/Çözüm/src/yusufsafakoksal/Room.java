package yusufsafakoksal;

import java.util.ArrayList;

public class Room {
	private static int nextRoomNumber=1;
	private int roomNumber;
	private int durationOfStay;
	private ArrayList<Treatment> treatments;
	
	public Room(int durationOfStay) {
		this.durationOfStay = durationOfStay;
		roomNumber=nextRoomNumber;
		nextRoomNumber++;
		treatments=new ArrayList<Treatment>();
	}
	
	public int getRoomNumber() {
		return roomNumber;
	}
	
	public void addTreatments(Treatment treatment) {
		if(!treatments.contains(treatment)) {
			treatments.add(treatment);
		}
	}

	@Override
	public String toString() {
		return "Allocated Room: [Room=" + roomNumber + ", Duration of Stay="
				+ durationOfStay + " days]";
	}
}
