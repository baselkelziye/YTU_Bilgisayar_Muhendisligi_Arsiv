package yusufsafakoksal;

public class Basket {
	private int ID;
	private Item items[];
	private MarketCard card;
	
	public Basket(int ID) {
		this.ID = ID;
		items=new Item[2];
	}
	
	public void addItem(Item item) {
		for(int i=0;i<items.length;i++) {
			if(items[i]==null) {
				items[i]=item;
				return;
			}
		}
		System.out.println("You have reached the maximum amount of items in your basket");
	}
	
	public void basketInfo() {
		int itemsAmount=0;
		double totalPrice=0;
		
		while(itemsAmount<items.length && items[itemsAmount]!=null) {
			totalPrice+=items[itemsAmount].getPrice();
			itemsAmount++;
		}
		
		System.out.println("Basket ID: "+ID+"  Number of items: "+itemsAmount+"  Total price: "+totalPrice);
		
		if(this.card!=null) {
			this.card.addPoints(totalPrice/10);
		}
	}
	
	public void setCard(MarketCard marketCard) {
		this.card=marketCard;
	}
	
}
