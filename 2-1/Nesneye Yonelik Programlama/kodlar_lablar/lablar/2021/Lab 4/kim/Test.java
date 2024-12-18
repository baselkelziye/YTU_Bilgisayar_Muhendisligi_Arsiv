package lab4_2021;


import java.util.LinkedList;

public class Test {
	public static void main(String[] args) {
		
	
	Room r1 = new Room(101,300);
	Room r2 = new Room(102,500);
	Room r3 = new Room(201,1000);
	Room r4 = new Room(202,2000);

	Customer c1 = new Customer(123, "Joe Deen", 5, r1);
	Customer c2 = new Customer(234,"Zoey Cripp", 3, r2);
	Customer c3 = new Customer(345,"Frank Zone", 7, r3);
	Customer c4 = new Customer(456, "Alan Stanley", 10, r4);
	
	LinkedList <Customer> list = new LinkedList<>();
	list.add(c1);
	list.add(c2);
	list.add(c3);


	
	Management mng = new Management("Big Five Hotel");
	mng.saveBookings(list);
	
	mng.customerInfo(c4);
	
	System.out.println("*************************");
	mng.customerInfo(c3);
	
	System.out.println("*************************");
	mng.changeBooking(c3, 10);
	mng.customerInfo(c3);
	System.out.println("*************************");
	
	
}
}

