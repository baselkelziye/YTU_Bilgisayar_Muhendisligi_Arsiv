package pkg19011070_proje1;

import java.util.Date; // for sub start date

public class Subscription {

    private Date subscriptionStartDate;
    private SubscriptionPlan subscriptionPlan;
    
    public Subscription(Date date, SubscriptionPlan plan) {
        this.subscriptionStartDate = date;
        this.subscriptionPlan = plan;
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
