package nyp08;

import java.util.*;

public class Subscription {
	private Tariff tariff;
	private Date begin;

	public Subscription(Tariff tariff) {
		this.tariff = tariff;
		begin = new Date();
	}
	
	public String toString() {
		return "Tariff: " + tariff.toString() + ", begin: " + begin;
	}

}
