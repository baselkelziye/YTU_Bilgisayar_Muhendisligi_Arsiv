package nyp1;

public class Reservation {
	
	private Customer customer;
	private String reservationTime;
	
	// constructor
	public Reservation(Customer customer, String reservationTime) {
		super();
		this.customer = customer;
		this.reservationTime = reservationTime;
	}
	
	// getters
	public Customer getCustomer() {
		return customer;
	}
	
	public String getReservationTime() {
		return reservationTime;
	}

    @Override
    public String toString() {
        return "Reservation informations: " + customer.getName() +
               ", Time: " + reservationTime;
    }

	
}
