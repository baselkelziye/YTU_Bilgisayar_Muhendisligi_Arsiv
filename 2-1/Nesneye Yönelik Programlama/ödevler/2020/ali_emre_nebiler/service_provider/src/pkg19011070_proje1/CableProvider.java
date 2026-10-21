package pkg19011070_proje1;

public class CableProvider implements ServiceProvider{

    private String name;
    private final SubscriptionPlan[] subscriptionPlans;
    private int subPlanCounter = 0;
    private final static int maxSubPlan = 20;
    
    public CableProvider(String name) {
        this.name = name;
        subscriptionPlans = new SubscriptionPlan[maxSubPlan];
    }

    @Override
    public void addSubscriptionPlan(SubscriptionPlan plan) {
        // if the plan doesn't exist, add it
        // if it exists, don't add it and give a warning, get the name again
        if(findSubscriptionPlan(plan.getName()) == null){
            subscriptionPlans[getSubPlanCounter()] = plan;
            setSubPlanCounter(getSubPlanCounter() + 1);
        }else{
            System.out.println("(!) This subscription plan is already added, "
                    + "try another one (!)");
        }
    }
    
    @Override
    public SubscriptionPlan findSubscriptionPlan(String name) {
        int i = 0;
        boolean found = false;
        
        while(!found && i<getSubPlanCounter()){
            // if the name exists, finish searching, continue else
            if(name.equals(subscriptionPlans[i].getName())){
                found = true;
            }else{
                i++;
            }
        }
        // if found, return the found one, return null else
        if(found){
            return subscriptionPlans[i];
        }else{
            return null;
        }
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public void setName(String name) {
        this.name = name;
    }
        
    @Override
    public int getSubPlanCounter() {
        return subPlanCounter;
    }
    
    @Override
    public void setSubPlanCounter(int subPlanCounter) {
        this.subPlanCounter = subPlanCounter;
    }
}
