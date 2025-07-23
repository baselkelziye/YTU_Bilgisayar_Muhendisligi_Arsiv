package batu;

public class VendingMachine{
	private Product product;
	private double cache;
	private int productCount;
	
	public VendingMachine(Product product, int productCount) {
		this.product = product;
		this.productCount = productCount;
		this.cache = 0.0;
	}
	
	public boolean enterCoin(double amount) {
		if(amount == 0.10 || amount == 0.25 || amount == 0.50 || amount == 1 ) {
			this.cache += amount;
			return false;
		}
		
		else {
			System.out.println("Not a valid amount!");
			return true;
		}
	}
	
	public int buyProduct() {
		int givenItem = (int)(cache / product.getPrice());
		if(productCount >= givenItem) {
			productCount -= givenItem;
			return givenItem;
		}
		else {
			givenItem = productCount;
			productCount = 0;
			return givenItem;	
		}
	}
}