package nypProje;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class TestSubscriptionPlan2 {

	@Test
	void test() {
		GSMProvider testProvider = new GSMProvider("TURKCELL");
		GSMProvider testProvider2 = new GSMProvider("TURKCELL");
		SubscriptionPlan testSubscriptionPlan = new SubscriptionPlan("4GB",testProvider);
		testSubscriptionPlan.setServiceProvider(testProvider2);
		assertEquals(testProvider2,testSubscriptionPlan.getServiceProvider());
	}

}
