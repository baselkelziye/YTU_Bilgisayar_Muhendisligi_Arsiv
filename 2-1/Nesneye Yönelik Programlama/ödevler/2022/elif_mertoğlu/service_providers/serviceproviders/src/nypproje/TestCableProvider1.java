package nypProje;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class TestCableProvider1 { //TESTING FINDSUBSCRIPTIONPLAN

	@Test
	void test() {
		SubscriptionPlan testSubscriptionPlan = new SubscriptionPlan("5GB");
		CableProvider testProvider = new CableProvider("testProvider");
		testProvider.addSubscriptionPlan(testSubscriptionPlan);
		assertEquals(testSubscriptionPlan,testProvider.findSubscriptionPlan("5GB"));
	}

}
