package proje;

import java.io.Serializable;
import java.util.ArrayList;

public class Journal implements Serializable{
	private static final long serialVersionUID = -8859965265940288505L;
	private String name;
	private String issn;
	private int frequency;
	private double issuePrice;
	private ArrayList<Subscription> subscriptions;
	
	public Journal(String name, String issn, int frequency, double issuePrice) {
		this.name = name;
		this.issn = issn;
		this.frequency = frequency;
		this.issuePrice = issuePrice;
		subscriptions=new ArrayList<Subscription>();
	}

	public void addSubscription(Subscription sub) {
		if(!subscriptions.contains(sub)) {
			if(sub.getCopies()*12<frequency) {
				frequency-=sub.getCopies()*12;
				subscriptions.add(sub);
				System.out.println(sub.getSubscriber().getName()+ " adli abone icin "+this.getName()+" dergisine abonelik olusturuldu.");
			}
			else {
				System.out.println("Yeterli "+this.getName()+" dergisi olmadigindan "+sub.getSubscriber().getName()+" icin abonelik olusturulamadi.");
			}
			
		}
	}
	
	public ArrayList<Subscription> getSubscriptions() {
		return subscriptions;
	}

	public String getName() {
		return name;
	}

	public String getIssn() {
		return issn;
	}

	public int getFrequency() {
		return frequency;
	}

	public double getIssuePrice() {
		return issuePrice;
	}

	@Override
	public String toString() {
		return this.name;
	}
	
}
