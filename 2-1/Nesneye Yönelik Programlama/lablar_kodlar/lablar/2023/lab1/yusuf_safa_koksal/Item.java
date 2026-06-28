package yusufsafakoksal;

public class Item {
	private int barcodeNo;
	private String name;
	private double price;
	
	public Item(int barcodeNo, String name, double price) {
		this.barcodeNo = barcodeNo;
		this.name = name;
		this.price = price;
	}

	public double getPrice() {
		return price;
	}
	
	@Override
	public String toString() {
		String info="Item [barcodeNo="+barcodeNo+", name="+name+", price="+price+"]";
		return info;
	}
}
