package nyp11;

import java.util.*;

public class MarketShelf {
	private LinkedList<Item> items;
	
	public MarketShelf() {
		items = new LinkedList<Item>();
	}
	public boolean doesExist( Item anItem ) {
		for( Item item : items )
			if( item == anItem )
				return true;
		return false;
	}
	public boolean addItem( Item anItem ) {
		if( doesExist(anItem) )
			return false;
		items.add(anItem);
		return true;
	}
	public void printExpiredItems( ) {
		boolean hasExpiredItem = false;
		System.out.println("Expired item(s): ");
		for( Item item : items ) {
		    if( item instanceof Food )
		    	if( ((Food)item).isExpired() ) {
		    		hasExpiredItem = true;
		    		System.out.println(item);
		    	}
		}
		if( hasExpiredItem == false )
		    System.out.println("All items are fresh!");
	}
	public void printAllItems( ) {
		System.out.println("All item(s): ");
		for( Item item : items ) {
		    System.out.println(item);
		}
		if( items.size()==0 )
		    System.out.println("There are no items!");
	}
	public static void main( String[] args ) {
		MarketShelf shelf = new MarketShelf();
		Calendar cal = Calendar.getInstance();
		cal.add(Calendar.DAY_OF_MONTH,1);
		Date future = cal.getTime();
		cal.set(Calendar.YEAR, 2010);
		cal.set(Calendar.MONTH, 0); 	//0: January
		cal.set(Calendar.DATE, 13);
		Date past = cal.getTime();
		shelf.addItem( new Food(past) );
		shelf.addItem( new Food(future) );
		shelf.addItem( new Electronics() );
		shelf.printExpiredItems();
		shelf.printAllItems();
	}
}
