package kemalselcuk;

public class GSMProvider implements ServiceProvider{
	private String name;
	private SubscriptionPlan[] subscriptionPlans = new SubscriptionPlan[20];	//attributes
	public GSMProvider(String name) {	//constructor
		this.name = name;
	}
	
	@Override
	public void addSubscriptionPlan(SubscriptionPlan plan) { 	//Checking null pointer exception and adding sub plan into the array
		int i = 0;
		while(i<subscriptionPlans.length && subscriptionPlans[i] != null) {
			i++;
		}
		subscriptionPlans[i] = plan;
	}
	@Override
	public SubscriptionPlan findSubscriptionPlan(String s) {	//Checking the sub plans array, comparing the names and returning
		for(SubscriptionPlan iter: subscriptionPlans) {
			if(iter != null && iter.getName().equals(s)) {
				return iter;
			}
		}
		return null;
		
	}
	@Override
	public String getName() {
		return this.name;
	}
	@Override
	public void setName(String name) {
		this.name = name;
		
	}
	
	
	
}
