package batuhanodcikin;

import java.util.HashMap;
import java.util.List;

public class Customer {
 private final String name;
 private final String location;
 private final HashMap<Product,Integer> purchasedProducts;
 
 public Customer(String name, String location) {
	this.name = name;
	this.location = location;
	this.purchasedProducts = new HashMap<Product,Integer>();
}
 
public String getName() {
	return name;
 }
 public String getLocation() {
	return location;
 }
 
 public static List<Customer> createCustomerList(){
	 List<Customer> customers = new List<Customer>();
	 
	 Customer customer1 = new Customer("Alan","Washington");
	 Customer customer2 = new Customer("Jhon","NYC");
	 Customer customer3 = new Customer("Lily","Kansas");
	 Customer customer4 = new Customer("Arthur","Detroit");
	 Customer customer5 = new Customer("Frank","NYC");
	 Customer customer6 = new Customer("Joe","Seattle");
	 
	 customers.add(customer1);
	 customers.add(customer2);
	 customers.add(customer3);
	 customers.add(customer4);
	 customers.add(customer5);
	 customers.add(customer6);
	 
	
	 return customers;
 }
 
 public HashMap<Product,Integer> getPurchasedProducts(){
	 return purchasedProducts;
 }
 
 public void puchaseProduct(Product product, int quantity) {
	 try {
		 product.reduceStock(quantity);
		 
	 } catch (InsufficientStockError e) {
		 System.out.println(e.getMessage());
		 System.out.println("Can't purchase product!");
	 }
 }
 
 public static <Z> void showListCustomer(List<Z> customers) {
	 for(Z c: customers) {
		 System.out.println(c);
	 }
 }
 
}
