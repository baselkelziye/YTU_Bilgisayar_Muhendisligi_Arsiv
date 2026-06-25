package res_sys_pkg;

public class Reservation {
	private Customer customer;
	private String time;
	
	public Reservation(Customer customer, String time) {
		this.customer = customer;
		this.time = time;
	}

	public Customer getCustomer() {
		return customer;
	}

	public String getTime() {
		return time;
	}

	@Override
	public String toString() {
		return "Reservation || Customer Info: " +customer.getName() + " || " + customer.getPhone_nbr() + " Time: " + this.time;
	}

}
