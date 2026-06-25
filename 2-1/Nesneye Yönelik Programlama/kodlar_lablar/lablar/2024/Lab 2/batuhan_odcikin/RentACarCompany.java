package batuhanodcikin;

import java.util.ArrayList;
import java.util.zip.CRC32;

public class RentACarCompany {
	private String name;
	private ArrayList<Car> carList;
	private ArrayList<CustomerCompany> customerList;
	
	public RentACarCompany(String name) {
		this.name = name;
		carList = new ArrayList<Car>();
		customerList = new ArrayList<CustomerCompany>();
	}
	
	public void rentCar(CustomerCompany customer, Car car) {
		if(!customerList.contains(customer)) { customerList.add(customer); }
		
		for(CustomerCompany cstmr:customerList) {
			if(cstmr.equals(customer)) {
				customer.rentCar(car);
			}
		}
	}
	
	public String mostFrequentCustomer() {
		int max = 0;
		String max_customer_name = "";
		
		for(CustomerCompany cstmr:customerList) {
			if(cstmr.getRentalCount() > max) {
				max = cstmr.getRentalCount();
				max_customer_name = cstmr.getName();
			}
		}
		return max_customer_name;
	}
	
	public void calculateTotalCost(int rentalDays) {
		double total_cost;
		
		for(CustomerCompany cstmr:customerList) {
			total_cost = 0;
			
			for(Car car:cstmr.getRentedCars()) {
				total_cost += car.dailyRentalPrice * rentalDays;
			}
			System.out.println(cstmr.getName() + "'s total cost for " + rentalDays + " days: " + total_cost + " TL");
		}
	}
	
	public ArrayList<Car> getCarList(){
		return carList;
	}
	
}
