package AutoparkProject;

public class ParkRecord {
	Time enterTime;
	Time exitTime;
	Vehicle vehicle;
	public ParkRecord(Time enterTime, Time exitTime, Vehicle vehicle) {
		this.enterTime = enterTime;
		this.exitTime = exitTime;
		this.vehicle = vehicle;
	}
	public int getParkingDuration(){//returning duration time in minutes.
		int difference = (exitTime.getHour()*60 + exitTime.getMinute() -
				enterTime.getHour()*60 + enterTime.getMinute());
 	return difference;
	}
	public Vehicle getVehicle() {
		return vehicle;
	}
	
	
	

}
