package nyp07;

/* Class code is incomplete.
 * No need to dwell on arrays as we will move on to generic lists and maps. */
public class VehicleRegistrationSystem {
	private CommercialVehicle commercialVehicles[];
	private PersonalVehicle personalVehicles[];
	private int commercialVehicleCount, personalVehicleCount;
	private int maxCapacity = 30;
	
	public VehicleRegistrationSystem() {
		commercialVehicles = new CommercialVehicle[maxCapacity];
		personalVehicles = new PersonalVehicle[maxCapacity];
	}
	
	public CommercialVehicle searchCommercialVehicle( String plate ) {
		for( CommercialVehicle vehicle : commercialVehicles ) {
			if( vehicle.getPlate().equalsIgnoreCase(plate) )
				return vehicle;
		}
		return null;
	}
	
	public boolean registerCommercialVehicle( CommercialVehicle vehicle ) {
		if( searchCommercialVehicle(vehicle.getPlate()) != null 
				|| searchPersonalVehicle(vehicle.getPlate()) != null )
			return false;
		commercialVehicles[commercialVehicleCount] = vehicle;
		commercialVehicleCount++;
		return true;
	}

	public PersonalVehicle searchPersonalVehicle( String plate ) {
		for( PersonalVehicle vehicle : personalVehicles ) {
			if( vehicle.getPlate().equalsIgnoreCase(plate) )
				return vehicle;
		}
		return null;
	}

	public boolean registerPersonalVehicle( PersonalVehicle vehicle ) {
		if( searchCommercialVehicle(vehicle.getPlate()) != null 
				|| searchPersonalVehicle(vehicle.getPlate()) != null )
			return false;
		personalVehicles[personalVehicleCount] = vehicle;
		personalVehicleCount++;
		return true;
	}
}
