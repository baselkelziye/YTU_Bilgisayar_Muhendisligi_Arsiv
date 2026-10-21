public class AutoPark {
	private SubscribedVehicle[] subscribedVehicles;
	private ParkRecord[] parkRecords;
	private double hourlyFee,incomeDaily=0;
	private int capacity;
	
	/*
	 * GETTERS
	 */
	public SubscribedVehicle[] getSubscribedVehicles() {
		return subscribedVehicles;
	}

	public ParkRecord[] getParkRecords() {
		return parkRecords;
	}

	public double getHourlyFee() {
		return hourlyFee;
	}

	public double getIncomeDaily() {
		return incomeDaily;
	}

	public int getCapacity() {
		return capacity;
	}

	/*
	 * SETTERS
	 */
	public void setSubscribedVehicles(SubscribedVehicle[] subscribedVehicles) {
		this.subscribedVehicles = subscribedVehicles;
	}

	public void setParkRecords(ParkRecord[] parkRecords) {
		this.parkRecords = parkRecords;
	}

	public void setHourlyFee(double hourlyFee) {
		this.hourlyFee = hourlyFee;
	}

	public void setIncomeDaily(double incomeDaily) {
		this.incomeDaily = incomeDaily;
	}

	public void setCapacity(int capacity) {
		this.capacity = capacity;
	}
	
	/*
	 * CONSTRUCTORS
	 */
	public AutoPark(double hourlyFee, int capacity) {
		this.hourlyFee = hourlyFee;
		this.capacity = capacity;
		parkRecords = new ParkRecord[capacity];
		subscribedVehicles = new SubscribedVehicle[capacity];
	}
	
	/*Functions for Test Cases
	 * 
	 */
	
	/**
	  * @description this function return Element i in the subscription vehicles array.
	  * @param int $i - Element i in the array
	  * @return SubscribedVehicle - success (SubscribedVehicle) or failure(null)
	  */
	public SubscribedVehicle getSubscribedVehicleFromArray(int i) {
		return subscribedVehicles[i];
	}
	
	/**
	  * @description this function return length of the subscription vehicles array.
	  * @return int - number of elements in array
	  */
	public int getSubsArrayLenght() {
		return subscribedVehicles.length;
	}
	
	
	/*
	 * Functions from UML
	 */
	
	
	/**
	  * @description this function search subscribed vehicle from subscribed vehicles array 
	  * @param String $plate - the plate for searching in array
	  * @return SubscribedVehicle - success (SubscribedVehicle) or failure(null)
	  */
	public SubscribedVehicle searchVehicle(String plate) {
		if(plate != null) {
			int i=0;
			while(i<subscribedVehicles.length && subscribedVehicles[i] != null) {
				String plateTMP= subscribedVehicles[i].getPlate();
				if(plateTMP.compareTo(plate) == 0) {
					return subscribedVehicles[i];
				}
				i++;
			}
			
		}
		return null;
	}
	
	/**
	  * @description this function add subscribed vehicle to subscribed vehicle array 
	  * @param SubscribedVehicle $vehicle - object( type: SubscribedVehicle) for adding to array
	  * @return boolean - success or failure
	  */
	public boolean addVehicle(SubscribedVehicle vehicle) {
		if(vehicle != null) {
			if(searchVehicle(vehicle.getPlate()) == null){
				int i=0;
				while(i<subscribedVehicles.length && subscribedVehicles[i] != null) {
					i++;
				}
				if(i == subscribedVehicles.length) {
					enlargeVehicleArray();
				}
				subscribedVehicles[i]=vehicle;
				return true;
			} else {
				System.err.println("Bu araç daha önce eklendi");
			}
		}
		return false;
	}
	
	/**
	  * @description this function checks whether this vehicle is in the Array of parkRecords according to the given plate.
	  * @param String $plate - the plate for searching in array
	  * @return boolean - success or failure
	  */
	public boolean isParked(String plate) {

		if(plate != null) {
			int i=0;
			while(i<parkRecords.length) {
				if(parkRecords[i] != null) {
					String plateTMP= parkRecords[i].getVehicle().getPlate();
					if(plateTMP.compareTo(plate) == 0) {
						return true;
					}
				}
				i++;
			}
		}
		return false;
	}
	
	/**
	  * @description this function enlarge the Vehicle Array. If the number of elements of the array is less than 100, it increases by 10 each time. 
	  * Increases by 20% if greater than 100.
	  * @return void 
	  */
	private void enlargeVehicleArray() {
		int incCap;
		if(subscribedVehicles.length>100) {
			incCap = subscribedVehicles.length + subscribedVehicles.length/20;
		}
		else{
			incCap = subscribedVehicles.length + 10;
		}
		SubscribedVehicle[] tempArray = new SubscribedVehicle[incCap];
		for(int i=0; i < subscribedVehicles.length;i++) {
			tempArray[i]=subscribedVehicles[i];
		}
		subscribedVehicles = tempArray;
	}
	
	/**
	  * @description this function add the vehicle to parkRecords
	  * @param String $plate - the plate for add the vehicle
	  * @param Time $enter - enter time
	  * @param Boolean $isOfficial - check the vehicle is official
	  * @return boolean - success or failure
	  */
	public boolean vehicleEnters(String plate,Time enter,Boolean isOfficial) {
		if(plate != null && enter != null) {
			int i = 0;
			while(i<capacity && parkRecords[i] != null) {
				i++;
			}
			if(i<capacity) {
				if(!isParked(plate)) {
					SubscribedVehicle sV = searchVehicle(plate);
					if( sV != null) {
						parkRecords[i]= new ParkRecord(enter,sV);
						return true;
					} else {
						if(isOfficial) {
							OfficialVehicle oV = new OfficialVehicle(plate);
							parkRecords[i]= new ParkRecord(enter,oV);
							return true;
						} else {
							RegularVehicle rV = new RegularVehicle(plate);
							parkRecords[i]= new ParkRecord(enter,rV);
							return true;
						}
					}
				} else {
					System.err.println("Bu araç parkedilmiş ");
				}
			}
		}
		return false;
	}
	
	/**
	  * @description this function remove the vehicle from parkRecords. 
	  * @description If the vehicle, official vehicle or subscription is a valid vehicle will not pay. 
	  * @description If the vehicle is not a member vehicle or its subscription is an invalid vehicle, it will pay.
	  * @param String $plate - the plate for add the vehicle
	  * @param Time $exit - exit time
	  * @return boolean - success or failure
	  */
	public boolean vehicleExits(String plate, Time exit) {
		if(plate != null && exit != null) {
			for(int i = 0; i<parkRecords.length; i++) {
				if(parkRecords[i]!=null) {
					if(parkRecords[i].getVehicle().getPlate().compareTo(plate) == 0) {
						parkRecords[i].setExitTime(exit);
						if(parkRecords[i].getVehicle().getSubscription() != null) {
							if(parkRecords[i].getVehicle().getSubscription().isValid() == false){
								incomeDaily = incomeDaily + Math.abs((hourlyFee * parkRecords[i].getParkingDuration())); 
							}
						}else {
							incomeDaily = incomeDaily + Math.abs((hourlyFee * parkRecords[i].getParkingDuration())); 
						}
						parkRecords[i] = null;
						return true;
					}
				}
				
			}
				
		
		}
		return false;	
	}
	
}
