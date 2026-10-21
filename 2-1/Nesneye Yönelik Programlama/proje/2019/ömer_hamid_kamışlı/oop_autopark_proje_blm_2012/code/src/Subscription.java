
public class Subscription {
	private Date begin;
	private Date end;
	private SubscribedVehicle vehicle;
	
	/*
	 * GETTERS
	 */
	public Date getBegin() {
		return begin;
	}

	public Date getEnd() {
		return end;
	}

	public SubscribedVehicle getVehicle() {
		return vehicle;
	}

	/*
	 * SETTERS
	 */
	public void setBegin(Date begin) {
		this.begin = begin;
	}

	public void setEnd(Date end) {
		this.end = end;
	}

	public void setVehicle(SubscribedVehicle vehicle) {
		this.vehicle = vehicle;
	}
	
	/*
	 * CONSTRUCTORS
	 */
	public Subscription(Date begin,Date end,String Plate) {
		if(begin != null && end != null && Plate != null) {
			this.begin = begin;
			this.end = end;
			vehicle = new SubscribedVehicle(this,Plate);
		}
	}
	
	/*
	 * Functions from UML
	 */
	public boolean isValid() {
		return Date.getToday().isAfterThan(end);
	}
}
