package nypProje;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class TestGSMProvider1 { //TESTING ADDSUBSCRIPTIONPLAN

	@Test
	void test() {
		SubscriptionPlan testSubscriptionPlan = new SubscriptionPlan("4GB");
		GSMProvider testProvider = new GSMProvider("testProvider");
		testProvider.addSubscriptionPlan(testSubscriptionPlan);
		assertEquals(testSubscriptionPlan,testProvider.findSubscriptionPlan("4GB"));
	}

}
