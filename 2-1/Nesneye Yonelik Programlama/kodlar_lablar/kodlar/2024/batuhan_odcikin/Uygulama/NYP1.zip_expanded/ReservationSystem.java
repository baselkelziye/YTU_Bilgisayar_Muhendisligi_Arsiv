package nyp1;

public class ReservationSystem {

	public static void main(String[] args) {
		
	        Customer cust1 = new Customer("John Doe", "123-456-7890");
	        Table table1 = new Table(1, 4);
	        Reservation res1 = new Reservation(cust1, "12:00 PM");
	        Reservation res2 = new Reservation(cust1, "13:00 PM");
	        Reservation res3 = new Reservation(cust1, "14:00 PM");
	        Reservation res4 = new Reservation(cust1, "15:00 PM");
	        Reservation res5 = new Reservation(cust1, "16:00 PM");

	        cust1.addReservation(res1);
	        
	        table1.addReservation(res1);
	        table1.addReservation(res2);
	        table1.addReservation(res3);
	        table1.addReservation(res4);
	        table1.addReservation(res5); //yer olmadıgı icin eklenmeyecek
	        
	        
	        System.out.println();
	        
	      //test
	        table1.removeReservation(res3);
	        table1.addReservation(res5);
	        
	        System.out.println();
	        
	      //test 
	        
	        table1.getReservations();
	    }

	}

