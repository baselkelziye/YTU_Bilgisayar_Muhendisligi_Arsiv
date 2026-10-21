
public class OfficialVehicle implements Vehicle{
	private String plate;
	private Subscription Subscription;
	public boolean isOfficial=true;
	
	/*
	 * SETTERS
	 */
	public void setPlate(String plate) {
		this.plate = plate;
	}

	public void setSubscription(Subscription subscription) {
		this.Subscription = subscription;
	}
	
	public void setIsOfficial(boolean isOfficial) {
		this.isOfficial = isOfficial; 
	}


	/*
	 * GETTERS from interface
	 */
	@Override
	public String getPlate() {
		return plate;
	}

	@Override
	public Subscription getSubscription() {
		return Subscription;
	}

	@Override
	public boolean isOfficial() {
		return isOfficial;
	}

	/*
	 * CONSTRUCTORS
	 */
	public OfficialVehicle(String plate) {
		this.plate = plate;
		Date end = new Date(31,12,2099);
		Subscription = new Subscription(Date.getToday(),end,plate);
	}
	
	
}
