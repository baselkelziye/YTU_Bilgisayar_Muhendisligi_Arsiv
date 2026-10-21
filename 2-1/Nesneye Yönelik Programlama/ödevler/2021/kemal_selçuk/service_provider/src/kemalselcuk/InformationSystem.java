package kemalselcuk;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class InformationSystem {
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in); //Created Scanner object to get inputs
		System.out.println("Gsm Service Provider?");
		String a = scan.nextLine();
		GSMProvider prov = new GSMProvider(a);	//Created a GSMProvider object
		System.out.println("Number of subscription plans?");
		int b = scan.nextInt();
		System.out.println("Name of the plans?");
		for(int i=0;i<=b;i++) {
			String c = scan.nextLine();				
			SubscriptionPlan plan = new SubscriptionPlan(c,prov);	//Created a SubscriptionPlan object
			prov.addSubscriptionPlan(plan);	//Added this obj to SubscriptionPlans
		}
		System.out.println("Customer citizenship number?");
		String d = scan.nextLine();
		ExistingCustomer customer = new ExistingCustomer(d);	//Created an ExistingCustomer object which inherited from Customer
		System.out.println("Customer name?");
		String e = scan.nextLine();
		customer.setName(e);	//Setting the name of the customer
		System.out.println("Name of the plan to be subscribed?");
		String f = scan.nextLine();
		System.out.println("Start date for subscription(mm/dd/yyyy)?");
		String g = scan.nextLine();
		Date sdf = null;	
		try {
			sdf = new SimpleDateFormat("MM/dd/yyyy").parse(g);	//Changed String type date to Date type date
		} catch (ParseException e1) {
			e1.printStackTrace();
		}
		Subscription sub = new Subscription(sdf,prov.findSubscriptionPlan(f)); //Creating a Subscription object with inputs date and sub plan
		SimpleDateFormat sdf2 = new SimpleDateFormat("MM/dd/yyyy"); //to changed date format to mm/dd/yyyy
		
		System.out.println("CUSTOMER CITIZENSHIP NUMBER = " + customer.getCitizenshipNr());
		System.out.println("CUSTOMER NAME = " + customer.getName());
		System.out.println("SERVICE PROVIDER: " + prov.getName());
		System.out.println("SUBSCRIPTION START DATE: " + sdf2.format(sub.getSubscriptionStartDate() ));	//printing date in the wanted format
		System.out.println("SUBSCRIPTION PLAN NAME: " + sub.getSubscriptionPlan().getName());
		
		scan.close();
		
	}
}
