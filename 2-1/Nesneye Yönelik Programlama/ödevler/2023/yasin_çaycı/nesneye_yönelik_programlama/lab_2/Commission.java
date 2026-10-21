package selahattinyasincayci;

public class Commission {
	private int commission_id;
	private String name;
	
	public Commission(int commission_id, String name) {
		this.commission_id = commission_id;
		this.name = name;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getCommission_id() {
		return commission_id;
	}

	
}
