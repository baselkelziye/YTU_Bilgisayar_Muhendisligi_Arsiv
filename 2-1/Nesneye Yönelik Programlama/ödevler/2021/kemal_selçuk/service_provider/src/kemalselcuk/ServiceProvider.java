package kemalselcuk;

public interface ServiceProvider {
	public void addSubscriptionPlan(SubscriptionPlan plan);		//abstract methods
	public SubscriptionPlan findSubscriptionPlan(String s);
	public String getName();
	public void setName(String name);
}
