package batuhanodcikin;

import java.util.List;

public class Product  implements IProduct{
 private static int idCounter = 0;
 private final int id;
 private final String name;
 private final double price;
 private int stock = 100;
 

 public Product(String name, double price) {
	this.id = idCounter++;
	this.name = name;
	this.price = price;
}

public int getId() {
	return id;
 }

 public String getName() {
	return name;
 }

 public double getPrice() {
	return price;
 }

 public int getStock() {
	return stock;
 }
 
 public void reduceStock(int quantity) throws InsufficientStockError {
	 int newStock = stock - quantity;
	 if(newStock >= 0)
		 stock = newStock;
	 else
		 throw new InsufficientStockError("Stock error!!\n");
 }
 
 public static void printInventoryWithIds(List<Product> products) {
	 for(Product p:products) {
		 System.out.println("Id: "+ p.getId()+ "Name: " + p.getName() + "Price: " + p.getPrice() + "Stock:" + p.getStock());
	 }
 }
 
 public static List<Product> createProductList() {
	 List<Product> products;
	 
	 
	 
	 
 }
 
 
 
 
}
