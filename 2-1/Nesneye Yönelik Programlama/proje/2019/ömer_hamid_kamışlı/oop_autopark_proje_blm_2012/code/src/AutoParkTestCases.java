import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

class AutoParkTestCases {
	
	AutoPark autoPark = new AutoPark(10,10);
	SubscribedVehicle Test;
	
	@Test
	void testAddVehicle() {
		Date end = new Date(12,12,2020);
		Subscription sB1 = new Subscription(Date.getToday(),end,"34 YTU 1000");
		SubscribedVehicle Test= sB1.getVehicle();
		autoPark.addVehicle(Test);
		assertEquals(Test,autoPark.getSubscribedVehicleFromArray(0));
	}
	
	@Test
	void testEnlargeVehicleArray() {
		Date end = new Date(12,12,2020);
		for(int i=0;i<15;i++) {
			Subscription sB1 = new Subscription(Date.getToday(),end,"34 YTU 200"+i);
			SubscribedVehicle sV= sB1.getVehicle();
			autoPark.addVehicle(sV);
		}
		assertEquals(20,autoPark.getSubsArrayLenght());
	}
	
	@Test
	void testSearchVehicle() {
		assertEquals(Test,autoPark.searchVehicle("34 YTU 1000"));
	}
	
	@Test
	void testVehicleEnterSubscription() {
		autoPark.addVehicle(Test);
		Time enter = new Time(1,0);
		assertTrue(autoPark.vehicleEnters("34 YTU 1000", enter, false));
	}
	
	@Test
	void testVehicleEnterRegular() {
		Time enter = new Time(1,0);
		assertTrue(autoPark.vehicleEnters("34 YTU 1001", enter, false));
	}
	
	@Test
	void testVehicleEnterOfficial() {
		Time enter = new Time(1,0);
		assertTrue(autoPark.vehicleEnters("34 YTU 1002", enter, true));
	}
	
	@Test
	void testisParkedSubscription() {
		autoPark.addVehicle(Test);
		Time enter = new Time(1,0);
		autoPark.vehicleEnters("34 YTU 1000", enter, false);
		assertTrue(autoPark.isParked("34 YTU 1000"));
	}
	
	@Test
	void testisParkedRegular() {
		Time enter = new Time(1,0);
		autoPark.vehicleEnters("34 YTU 1001", enter, false);
		assertTrue(autoPark.isParked("34 YTU 1001"));
	}
	
	@Test
	void testisParkedOfficial() {
		Time enter = new Time(1,0);
		autoPark.vehicleEnters("34 YTU 1002", enter, true);
		assertTrue(autoPark.isParked("34 YTU 1002"));
	}
	
	@Test
	void testVehicleExitsSubscriptionIsValid() {
		Date end = new Date(12,12,2020);
		Subscription sB1 = new Subscription(Date.getToday(),end,"34 YTU 1000");
		SubscribedVehicle sV= sB1.getVehicle();
		autoPark.addVehicle(sV);
		Time enter = new Time(1,0);
		Time exit = new Time(2,7);
		autoPark.vehicleEnters("34 YTU 1000", enter, false);
		autoPark.vehicleExits("34 YTU 1000", exit);
		assertEquals(0,autoPark.getIncomeDaily());
	}
	
	@Test
	void testVehicleExitsSubscriptionIsNOTValid() {
		Date end = new Date(10,5,2019);
		Subscription sB1 = new Subscription(Date.getToday(),end,"34 YTU 1000");
		SubscribedVehicle sV= sB1.getVehicle();
		autoPark.addVehicle(sV);
		Time enter = new Time(1,0);
		Time exit = new Time(2,7);
		autoPark.vehicleEnters("34 YTU 1000", enter, false);
		autoPark.vehicleExits("34 YTU 1000", exit);
		assertEquals(10,autoPark.getIncomeDaily());
	}
	
	@Test
	void testVehicleExitsSubscriptionSAMEDAY() {
		Date end = new Date(10,5,2019);
		Subscription sB1 = new Subscription(end,end,"34 YTU 1000");
		SubscribedVehicle sV= sB1.getVehicle();
		autoPark.addVehicle(sV);
		Time enter = new Time(1,0);
		Time exit = new Time(2,7);
		autoPark.vehicleEnters("34 YTU 1000", enter, false);
		autoPark.vehicleExits("34 YTU 1000", exit);
		assertEquals(10,autoPark.getIncomeDaily());
	}
	
	@Test
	void testVehicleExitsRegular() {
		Time enter = new Time(1,0);
		Time exit = new Time(6,7);
		autoPark.vehicleEnters("34 YTU 1001", enter, false);
		autoPark.vehicleExits("34 YTU 1001", exit);
		assertEquals(50,autoPark.getIncomeDaily());
	}
	
	@Test
	void testVehicleExitsOfficial() {
		Time enter = new Time(1,0);
		Time exit = new Time(2,7);
		autoPark.vehicleEnters("34 YTU 1002", enter, true);
		autoPark.vehicleExits("34 YTU 1002", exit);
		assertEquals(0,autoPark.getIncomeDaily());
	}
	

}
