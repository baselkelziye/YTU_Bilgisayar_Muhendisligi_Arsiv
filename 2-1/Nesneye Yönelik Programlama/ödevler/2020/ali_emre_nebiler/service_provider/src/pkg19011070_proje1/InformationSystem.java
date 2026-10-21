package pkg19011070_proje1;
/*
    by Ali Emre Nebiler
*/
import java.util.Scanner;

// for date type
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;


public class InformationSystem {

    public static void main(String[] args) throws ParseException {
        Scanner scan = new Scanner(System.in);
        
        // get name of the provider
        System.out.print("GSM SERVICE PROVIDER ? : ");
        String providerName = scan.nextLine();
        
        // get the number of sub plans
        System.out.print("NUMBER OF SUBSCRIPTION PLANS ? : ");
        int subNum = scan.nextInt(); scan.nextLine();
        // extra scan to solve scan problem
        
        // create the provider, the name and the sub plan that will added
        ServiceProvider provider1 = new GSMProvider(providerName);
        SubscriptionPlan subPlan = new SubscriptionPlan(null);
        String planName;
        
        // get names of sub plans and add them
        while(provider1.getSubPlanCounter()<subNum){
            System.out.print("NAME OF THE PLAN #" + provider1.getSubPlanCounter()
                    + " ? : ");
            planName = scan.nextLine();
            subPlan = new SubscriptionPlan(planName, provider1);         
            provider1.addSubscriptionPlan(subPlan);
        }
        
        // get citizenship no of the customer
        System.out.print("CUSTOMER CITIZENSHIP NUMBER ? : ");
        String citizenshipNo = scan.nextLine();
        
        // get name of the customer and create the customer
        System.out.print("CUSTOMER NAME ? : ");
        String customerName = scan.nextLine();
        Customer customer1 = new ExistingCustomer(citizenshipNo, customerName);
        
        // get name of the plan to be subscribed and find it
        // continue getting names until find an existing plan
        do{
            System.out.print("NAME OF THE PLAN TO BE SUBSCRIBED ? : ");
            planName = scan.nextLine();
            if(provider1.findSubscriptionPlan(planName) != null){
                subPlan.setName(planName);
                subPlan.setServiceProvider(provider1);
            }else{
                System.out.println("(!) Subscription plan couldn't be found, "
                        + "try again. (!)");
            }
        }while(provider1.findSubscriptionPlan(planName) == null);
        
        // get start date of the subscription
        System.out.print("START DATE FOR SUBSCRIPTION (MM/DD/YYYY)? : ");
        String date = scan.nextLine();
        Date endDate = new SimpleDateFormat("MM/dd/yyyy").parse(date);
        
        // create the subscription and set the customer's subscription
        Subscription sub = new Subscription(endDate, subPlan);
        ((ExistingCustomer)customer1).setSubscription(sub);
        
        // print the final info
        System.out.println("-----------------------------------------------------");
        System.out.println("CUSTOMER CITIZENSHIP NUMBER = " + customer1.
                getCitizenshipNr());
        System.out.println("CUSTOMER NAME = " + customer1.getName());
        System.out.println("SERVICE PROVIDER : " + ((ExistingCustomer)customer1).
                getSubscription().getSubscriptionPlan().getServiceProvider().getName());
        
        // print only the date, not the time
        Calendar cal = Calendar.getInstance();
        cal.setTime(((ExistingCustomer)customer1).getSubscription().
                getSubscriptionStartDate());
        System.out.println("SUBSCRIPTION START DATE : " + (cal.get(Calendar.MONTH)+1) +
                "/" + cal.get(Calendar.DAY_OF_MONTH) + "/" + cal.get(Calendar.YEAR));
        
        System.out.println("SUBSCRIPTION PLAN NAME : " + ((ExistingCustomer)customer1).
                getSubscription().getSubscriptionPlan().getName());
        System.out.println("-----------------------------------------------------");
    }
}
