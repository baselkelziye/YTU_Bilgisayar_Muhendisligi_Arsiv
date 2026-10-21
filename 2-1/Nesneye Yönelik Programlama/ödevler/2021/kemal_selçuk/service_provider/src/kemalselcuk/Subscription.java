package kemalselcuk;

import java.util.Date;

public class Subscription {
	private Date subscriptionStartDate; //attributes
	private SubscriptionPlan subscriptionPlan;
	public Subscription(Date subscriptionStartDate, SubscriptionPlan subscriptionPlan) { //constructor 
		this.subscriptionStartDate = subscriptionStartDate;
		this.subscriptionPlan = subscriptionPlan;
	}
	public Date getSubscriptionStartDate() {
		return subscriptionStartDate;
	}
	public void setSubscriptionStartDate(Date subscriptionStartDate) {
		this.subscriptionStartDate = subscriptionStartDate;
	}
	public SubscriptionPlan getSubscriptionPlan() {
		return subscriptionPlan;
	}
	public void setSubscriptionPlan(SubscriptionPlan subscriptionPlan) {
		this.subscriptionPlan = subscriptionPlan;
	}
	
}
