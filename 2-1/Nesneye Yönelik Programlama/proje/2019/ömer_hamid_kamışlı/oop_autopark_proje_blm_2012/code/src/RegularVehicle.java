
public class RegularVehicle implements Vehicle{
	private String plate;
	public boolean isOfficial=false;
	
	/*
	 * SETTERS
	 */
	public void setPlate(String plate) {
		this.plate = plate;
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
		return null;
	}

	@Override
	public boolean isOfficial() {
		return isOfficial;
	}

	/*
	 * CONSTRUCTORS
	 */
	public RegularVehicle(String plate) {
		this.plate = plate;
	}
	
}
