package proje;

import java.io.Serializable;

public abstract class Subscriber implements Serializable {
	private static final long serialVersionUID = 1293198859917624303L;
	private String name;
	private String address;
	
	public Subscriber(String name, String address) {
		this.name = name;
		this.address = address;
	}
	
	public String getName() {
		return name;
	}

	public String getAddress() {
		return address;
	}

	@Override
	public String toString() {
		return this.name;
	}

	abstract public String getBillingInformation();
}
