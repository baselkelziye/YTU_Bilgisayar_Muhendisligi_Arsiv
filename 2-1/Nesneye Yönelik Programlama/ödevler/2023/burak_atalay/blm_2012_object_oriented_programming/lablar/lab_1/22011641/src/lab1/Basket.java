package lab1;

public class Basket {
	private int ID;
	private Item[] items;
	private MarketCard card;
	public Basket(int ID) {
		this.ID = ID;
		items = new Item[2];
	}
	public void setCard(MarketCard card) {
		this.card = card;
	}
	
	public void addItem(Item item) {
		if(items[0] == null) {
			items[0] = item;
		}
		else if(items[1] == null) {
			items[1] = item;
		}
		else {
			System.out.println("You've reached the maximum amount of items in your basket");
		}
	}
	
	public void basketInfo() {
		String result = "Basket ID: " + ID + " Number of items: ";
		double price = 0.0;
		int i=0;
		while(i<2 && items[i] != null) {
			price += items[i].getPrice();
			i++;
		}
		result += i + " Total Price: " + price;
		if(card != null) {
			card.addPoints(price);
		}
		System.out.println(result);
	}
}
