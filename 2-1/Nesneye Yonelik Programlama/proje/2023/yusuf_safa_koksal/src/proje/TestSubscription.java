package proje;

import junit.framework.TestCase;

public class TestSubscription extends TestCase {
	private Subscription subscription;
	private Journal journal;
	private Subscriber subscriber;
	
	protected void setUp() {
		journal=new Journal("Ahlak","0001",100,1);
		subscriber=new Individual("Yusuf Safa Köksal","Samsun");
		subscription=new Subscription(new DateInfo(1,1),5,journal,subscriber);
	}
	
	public void testGetJournal() {
		Journal result=subscription.getJournal();
		assertEquals(result,journal);
	}
	
	public void testGetSubscriber() {
		Subscriber result=subscription.getSubscriber();
		assertEquals(result,subscriber);
	}
}
