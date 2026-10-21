package AutoparkProject;

public class AutoPark {
	private SubscribedVehicle[] subscribedVehicles;
	private ParkRecord[] parkRecords;
	private double hourlyFee, incomeDaily;
	private int capacity;
	public AutoPark(double hourlyFee, double incomeDaily, int capacity) {
		this.hourlyFee = hourlyFee;
		this.incomeDaily = incomeDaily;
		this.capacity = capacity;
	}
	public SubscribedVehicle searchVehicle(String plate) {
		for(int i=0; i<subscribedVehicles.length; i++) {
			if(subscribedVehicles[i].getPlate().compareTo(plate) == 0) 
				return subscribedVehicles[i]; 	 
		}
		return null;
	}
	public boolean isParked(String plate) { //park record olmalı ama officialCar ise olmaz
		for(int i=0; i<parkRecords.length; i++) {
			if(parkRecords[i].getVehicle().getPlate().compareTo(plate) == 0) 
				return true;	
		}
		return false;
	}
	private void enlargeVehicleArray(int newCapacity) {
		
	}
	
	
}
