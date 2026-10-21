package pkg19011070_proje1;

public interface ServiceProvider {
    
    public void addSubscriptionPlan(SubscriptionPlan name);
    public SubscriptionPlan findSubscriptionPlan(String name);
    public String getName();
    public void setName(String name);
    public int getSubPlanCounter();
    public void setSubPlanCounter(int subPlanCounter);
}
