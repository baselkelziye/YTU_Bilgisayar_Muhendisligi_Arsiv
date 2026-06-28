package unitTestingByFowler;

import java.util.*;

public class Customer {
	private String _name;
	private Vector<Rental> _rentals = new Vector<Rental>();
	public Customer (String name){
		_name = name;
	}
	public void addRental(Rental arg) {
		_rentals.addElement(arg);
	}
	public String getName (){
		return _name;
	}
	public String statement( ) {
		Enumeration<Rental> rentals = _rentals.elements();
		String result = "Rental Record for " + getName() + "\n";
		while (rentals.hasMoreElements()) {
			Rental aRental = rentals.nextElement();
			//show figures for this rental
			result += "\t" + aRental.getMovieTitle()+ "\t" +
			String.valueOf(aRental.getCharge()) + "\n";
		}
		//add footer lines
		result += "Amount owed is " + getTotalCharge() + "\n";
		result += "You earned " + getTotalBonus()
				+ " frequent renter points";
		return result;
	}
	public double getTotalCharge( ) {
		double result = 0;
		for( Rental each : _rentals )
			result += each.getCharge();
		return result;
	}
	public int getTotalBonus( ) {
		int result = 0;
		for( Rental each : _rentals )
			result += each.getBonus( );
		return result;
	}
}
