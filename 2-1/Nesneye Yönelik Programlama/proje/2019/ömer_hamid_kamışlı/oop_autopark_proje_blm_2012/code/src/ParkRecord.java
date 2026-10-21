
public class ParkRecord {
	private Time enterTime,exitTime;
	private Vehicle vehicle;
	
	/*
	 * GETTERS
	 */
	public Time getEnterTime() {
		return enterTime;
	}

	public Time getExitTime() {
		return exitTime;
	}

	public Vehicle getVehicle() {
		return vehicle;
	}

	/*
	 * SETTERS
	 */
	public void setEnterTime(Time enterTime) {
		this.enterTime = enterTime;
	}

	public void setExitTime(Time exitTime) {
		this.exitTime = exitTime;
	}

	public void setVehicle(Vehicle vehicle) {
		this.vehicle = vehicle;
	}

	/*
	 * CONSTRUCTORS
	 */
	public ParkRecord(Time enterTime, Vehicle vehicle) {
		this.enterTime = enterTime;
		this.vehicle = vehicle;
	}
	
	public ParkRecord(Time enterTime, Time exitTime,Vehicle vehicle) {
		this.enterTime = enterTime;
		this.exitTime = exitTime;
		this.vehicle = vehicle;
	}

	/*
	 * Functions from UML
	 */
	public int getParkingDuration() {
		return exitTime.getDifference(enterTime);
	}
}
