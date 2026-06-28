package nyp06;

public abstract class Item { 
	private String barcode, description;
	public Item(String barcode, String description) {
		this.barcode = barcode;
		this.description = description;
	}
	public String getBarcode() {
		return barcode;
	}
	public String getDescription() {
		return description;
	}

	public abstract boolean isSuitable(Child aChild);


}
