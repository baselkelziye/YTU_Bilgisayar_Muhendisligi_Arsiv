package res_sys_pkg;

public class Restaurant_System {

	public static void main(String[] args) {
		Customer customer1 = new Customer("Batuhan Odçıkın", "123-852");
		Reservation reservation1 = new Reservation(customer1, "Thursday 19.00 PM");
		Reservation reservation2 = new Reservation(customer1, "Wednesday 13.00 PM");
		Reservation reservation3 = new Reservation(customer1, "Thursday 11.00 AM");
		Reservation reservation4 = new Reservation(customer1, "Monday 18.00 PM");
		
		customer1.addReservation(reservation1);
		customer1.addReservation(reservation2);
		customer1.addReservation(reservation3);
		customer1.addReservation(reservation4);
		customer1.addReservation(reservation1);
		
		customer1.listReservations();
		
	}
}
