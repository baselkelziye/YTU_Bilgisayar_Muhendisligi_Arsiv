package yusufsafakoksal;

public class Main {

	public static void main(String[] args) {
		MarketCard mc=new MarketCard(110110);
		
		Basket b1= new Basket(101);
		Basket b2= new Basket(102);
		
		Item item1= new Item(100011, "milk", 30);
		Item item2= new Item(100012, "cheese", 100);
		Item item3= new Item(100013, "bread", 8);
		
		System.out.println(item1);
		
		b1.addItem(item1);
		b1.addItem(item2);
		b1.addItem(item3);
		b1.setCard(mc);
		b1.basketInfo();
		
		b2.addItem(item3);
		b2.setCard(mc);
		b2.basketInfo();
		
		System.out.println(mc.getPoints());
	}

}
