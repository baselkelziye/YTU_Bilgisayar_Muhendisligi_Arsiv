package nypProje;

public class GSMProvider implements ServiceProvider {

	private String name;
	private SubscriptionPlan[] subscriptionPlans;
	
	public GSMProvider(String name) {
		this.name=name;
		this.subscriptionPlans = new SubscriptionPlan[10];
	}
	
	
	public void addSubscriptionPlan(SubscriptionPlan subscriptionPlan){
		int i=0;
		while(i<subscriptionPlans.length && subscriptionPlans[i]!=null) {
			i++;
		}
		subscriptionPlans[i]=subscriptionPlan;
	}
	
	public SubscriptionPlan findSubscriptionPlan(String name) {
		SubscriptionPlan subsPlan;
		subsPlan=null;
		for(SubscriptionPlan sp : subscriptionPlans) {
			if(sp!=null) {
				if(name.compareTo(sp.getName())==0) {
					subsPlan=sp;
				}
			}
		}
		return subsPlan;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name=name;
	}
}
