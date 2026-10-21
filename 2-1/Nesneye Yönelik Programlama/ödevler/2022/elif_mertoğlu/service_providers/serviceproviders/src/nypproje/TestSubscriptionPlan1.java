package nypProje;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class TestSubscriptionPlan1 {   //TESTING GETSERVICEPROVIDER

	@Test
	void test() {
		GSMProvider testProvider = new GSMProvider("TURKCELL");
		SubscriptionPlan testSubscriptionPlan = new SubscriptionPlan("4GB",testProvider);
		assertEquals(testProvider,testSubscriptionPlan.getServiceProvider());
	}

}
