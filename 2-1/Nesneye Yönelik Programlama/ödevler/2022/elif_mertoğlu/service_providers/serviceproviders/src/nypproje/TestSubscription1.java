package nypProje;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;
import java.util.Date;
class TestSubscription1 {  //TESTING GETSUBSCRIPTIONPLAN

	@Test
	void test() {
		SubscriptionPlan testSubscriptionPlan = new SubscriptionPlan("4GB");
		Date testDate = new Date();
		Subscription testSubscription = new Subscription(testDate,testSubscriptionPlan);
		assertEquals(testSubscriptionPlan,testSubscription.getSubscriptionPlan());
	}

}
