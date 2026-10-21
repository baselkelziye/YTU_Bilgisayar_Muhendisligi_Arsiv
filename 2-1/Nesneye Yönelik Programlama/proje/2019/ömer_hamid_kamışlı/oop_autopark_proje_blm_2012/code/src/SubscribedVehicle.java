
public class SubscribedVehicle implements Vehicle{
	private String plate;
	private Subscription subscription;
	private boolean isOfficial=false;
	
	/*
	 * SETTERS
	 */
	public void setPlate(String plate) {
		this.plate = plate;
	}

	public void setSubscription(Subscription subscription) {
		this.subscription = subscription;
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
		return subscription;
	}

	@Override
	public boolean isOfficial() {
		return isOfficial;
	}

	/*
	 * CONSTRUCTORS
	 */
	public SubscribedVehicle(Subscription subscription,String plate) {
		this.plate = plate;
		this.subscription = subscription;
	}
	
}
