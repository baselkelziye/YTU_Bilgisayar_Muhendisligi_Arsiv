package nypProje;

public interface ServiceProvider {
	
	public void addSubscriptionPlan(SubscriptionPlan subscriptionPlan);  
	public SubscriptionPlan findSubscriptionPlan(String name);
	public String getName();
	public void setName(String name);
}
