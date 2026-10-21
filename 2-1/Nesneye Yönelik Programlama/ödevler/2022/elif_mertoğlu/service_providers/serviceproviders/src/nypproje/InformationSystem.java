package nypProje;

import java.util.Date;
import java.util.Scanner;
import java.text.SimpleDateFormat;
import java.text.ParseException;

public class InformationSystem {

	public static void main(String[] args) throws ParseException {
		                      
		            //KULLANICIDAN INPUT ALMA KISMI
		String servProvName;
		String whichOne;
		String PorE;
		String[] nameOfThePlans = new String[15];
		int subsPlanNum;
		String ctznShipNr=" ";
		String cusName=" ";
		String nameOfThePlan2BeSubs;
		String startDate;
		Scanner in = new Scanner(System.in);
		ServiceProvider serProv=null; //hangi tür service provider seçileceði bilinmediði için burada null atanýr
		Customer newCustomer=null; //hangi tür customer olacaðý bilinmediði için burada null atanýr.
		System.out.println("GSM or Cable?");
		whichOne = in.nextLine();
		if(whichOne.compareTo("GSM")==0) {
			System.out.println("GSM SERVICE PROVIDER?");
			servProvName=in.nextLine();
			serProv = new GSMProvider(servProvName); //gsm provider nesnesi yaratýlýr.
		}else if(whichOne.compareTo("Cable")==0) {
			System.out.println("CABLE SERVICE PROVIDER?");
			servProvName=in.nextLine();
			serProv = new CableProvider(servProvName); //cable provider nesnesi yaratýlýr.
		}else {
			System.out.println("Hatalý giriþ yaptýnýz. Lütfen tekrar deneyiniz.");
			in.close();
			return;
		}
		System.out.println("NUMBER OF SUBSCRIPTION PLANS?");
		subsPlanNum=in.nextInt();
		in.nextLine();
		SubscriptionPlan[] subsPlans = new SubscriptionPlan[subsPlanNum]; 
		
		for(int i=0;i<subsPlanNum;i++) {
			System.out.println("NAME OF THE PLAN #" +i); //planlarýn isimleri kullanýcýdan alýnýr.
			nameOfThePlans[i]=in.nextLine();
		}
		for(int i=0;i<subsPlans.length;i++) {
			subsPlans[i]=new SubscriptionPlan(nameOfThePlans[i],serProv); //subsPlans dizisinin her bir elemaný kullanýcýdan alýnan isim ve service provider bilgisi eklenerek oluþturulur. 
			//System.out.println(subsPlans[i]);                               
		}
		for(int i=0;i<subsPlans.length;i++) {
			if(subsPlans[i]!=null) {
				serProv.addSubscriptionPlan(subsPlans[i]); //subscriptionPlans dizisinin elemanlarý tek tek serviceProvider'ýna eklenir.
			}
		}
		System.out.println("POSSIBLE OR EXISTING?");
		PorE = in.nextLine();
		if(PorE.compareTo("EXISTING")==0) {
			newCustomer = new ExistingCustomer(ctznShipNr); //existing customer nesnesi yaratýlýr.
			System.out.println("CUSTOMER CITIZENSHIP NUMBER?");
			newCustomer.setCitizenshipNr(in.nextLine());
			System.out.println("CUSTOMER NAME?");
			cusName=in.nextLine();
			newCustomer.setName(cusName);
			
		}else if(PorE.compareTo("POSSIBLE")==0) {
			newCustomer = new PossibleCustomer(ctznShipNr); //possible customer nesnesi yaratýlýr.
			System.out.println("CUSTOMER CITIZENSHIP NUMBER?");
			newCustomer.setCitizenshipNr(in.nextLine());
			System.out.println("CUSTOMER NAME?");
			newCustomer.setName(in.nextLine());
			System.out.println("CUSTOMER TEL?");
			newCustomer.setTel(in.nextLine());
			System.out.println("CUSTOMER MAIL?");
			newCustomer.setMail(in.nextLine());
			System.out.println("CUSTOMER CITIZENSHIP NUMBER = " + newCustomer.getCitizenshipNr());
			System.out.println("CUSTOMER NAME = " + newCustomer.getName());
			System.out.println("CUSTOMER TEL = " + newCustomer.getTel());
			System.out.println("CUSTOMER MAIL = " + newCustomer.getMail());
			in.close();
			return;
		}else {
			System.out.println("Hatalý giriþ yaptýnýz. Lütfen tekrar deneyiniz.");
		}
		
		System.out.println("NAME OF THE PLAN TO BE SUBSCRIBED?");
		nameOfThePlan2BeSubs=in.nextLine();
		Subscription newSubscription = null;
		SubscriptionPlan theOne = serProv.findSubscriptionPlan(nameOfThePlan2BeSubs); //kullanýcýnýn girdiði, subscribe olunacak planýn serviceProvider'ýnda olup olmadýðý kontrol edilir.
		Date date = null;
		if(theOne!=null) { //eðer kullanýcýnýn subscribe olmak istediði plan serviceProvider'ýnda varsa:
			System.out.println("START DATE FOR SUBSCRIPTION (MM/DD/YYYY)?");
			startDate = in.nextLine();
			SimpleDateFormat format = new SimpleDateFormat("MM/dd/yyyy");
			if(startDate!=null && startDate.trim().length() > 0){
	             date = format.parse(startDate);
	        }
			newSubscription = new Subscription(date,theOne); //kullanýcýdan alýnan baþlama tarihi ve subscribe olunmak istenen plan bilgileriyle birlikte Subscription nesnesi oluþturulur.
			newCustomer = new ExistingCustomer(newCustomer.getCitizenshipNr(),newSubscription);//hangi tip customer seçilmiþse(possible veya existing) output kýsmýnda kullanmak üzere newCustomer tekrardan initialize edilir.
			newCustomer.setName(cusName);
		}else {
			System.out.println("Aranan plan bulunamadý.");
			in.close();
			return;
		}
		
		               //---------------output bölümü--------------------
		
		System.out.println("CUSTOMER CITIZENSHIP NUMBER = " + newCustomer.getCitizenshipNr());
		System.out.println("CUSTOMER NAME = " + newCustomer.getName());
		System.out.println("SERVICE PROVIDER : " + serProv.getName());
		System.out.println("SUBSCRIPTION START DATE : " + startDate);
		System.out.println("SUBSCRIPTION PLAN NAME : " + newSubscription.getSubscriptionPlan().getName());
		
		in.close();
	}

}
