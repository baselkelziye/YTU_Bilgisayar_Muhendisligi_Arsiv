package batuhanodcikin;

import java.util.List;
import java.util.Random;

public class Shipping implements IShipping {
	private static Random random;
		
	public boolean shipProduct(String productName, String customerName) {
		if(Math.random() < 0.25)
			return true;
		else 
			return false;
	
	}
	
	public void simulateShipping(List<Customer> customers) {
		
	}
}
