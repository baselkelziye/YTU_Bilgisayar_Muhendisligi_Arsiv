package proje;

public class Main {

	public static void main(String[] args) {
		Distributor distributor=new Distributor();
		
		Individual individual1=new Individual("Yusuf Safa Koksal","Samsun");
		Individual individual2=new Individual("Necip Fazil Kisakurek","Istanbul");
		Individual individual3=new Individual("Osman Yuksel Serdengecti","Antalya");
		
		Journal journal1=new Journal("Ahlak","0001",1000,100);
		Journal journal2=new Journal("Erdem","0002",800,60);
		
		distributor.addJournal(journal1);
		distributor.addJournal(journal2);
		distributor.searchJournal("0001");
		
		distributor.addSubscriber(individual1);
		distributor.addSubscriber(individual2);
		distributor.addSubscriber(individual3);
		distributor.searchSubscriber("Yusuf Safa Koksal");
		
		DateInfo date1=new DateInfo(3,2023);
		Subscription subscription1=new Subscription(date1, 5, journal1, individual1);
		Subscription subscription2=new Subscription(date1, 10, journal1, individual2);
		Subscription subscription3=new Subscription(date1, 15, journal2, individual1);
		Subscription subscription4=new Subscription(date1, 12, journal2, individual2);
		Subscription subscription5=new Subscription(date1, 12, journal1, individual3);
		Subscription subscription6=new Subscription(date1, 200, journal2, individual3);
		
		journal1.addSubscription(subscription1);
		journal1.addSubscription(subscription2);
		journal1.addSubscription(subscription5);
		journal2.addSubscription(subscription3);
		journal2.addSubscription(subscription4);
		journal2.addSubscription(subscription6);
		
		subscription1.acceptPayment(1000);
		subscription2.acceptPayment(5000);
		subscription3.acceptPayment(10000);
		
		//distributor.saveState("data.ser");
		//distributor.loadState("data.ser");
		
		distributor.report(2, 2025);
		//distributor.listSubscriptionsByIssn("0001");
		//distributor.listAllSendingOrders(4,2023);
		//distributor.listSendingOrders("0002", 4, 2023);
	}

}
