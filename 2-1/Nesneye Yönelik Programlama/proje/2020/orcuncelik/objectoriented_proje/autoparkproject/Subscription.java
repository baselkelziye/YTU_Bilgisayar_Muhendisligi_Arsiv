package AutoparkProject;

public class Subscription {
	private Date begin, end;
	private SubscribedVehicle vehicle;
	public Subscription(Date begin, Date end, String plate) {
		this.begin = begin;
		this.end = end;
		vehicle.setPlate(plate);
	}
	public boolean isValid() { //gün hesaplamasıyla geçerlilik kontrolü
		if(end.getYear()*365 + end.getMonth()*30 + end.getDay()
				> begin.getYear()*365 + begin.getMonth()*30 +
				begin.getDay()) 
			return true;
		return false;

	}

}
