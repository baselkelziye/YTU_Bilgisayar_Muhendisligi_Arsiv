package nyp07b;

/* Class code is incomplete.
 * No need to dwell on arrays as we will move on to generic lists and maps. */
public class VehicleRegistrationSystem {
	private CommercialVehicle commercialVehicles[];
	private PersonalVehicle personalVehicles[];
	
	public CommercialVehicle searchCommercialVehicle( String plate ) {
		for( CommercialVehicle vehicle : commercialVehicles )
			if( vehicle.getPlate().equalsIgnoreCase(plate) )
				return vehicle;
		return null;
	}
	
	public boolean registerCommercialVehicle( CommercialVehicle vehicle ) {
		if( searchCommercialVehicle(vehicle.getPlate()) != null )
			return false;
		return true;
	}

}
