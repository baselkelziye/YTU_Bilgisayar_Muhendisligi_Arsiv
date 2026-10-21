package nypProje;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;
import java.util.Date;
class TestExistingCustomer1 {  //TESTING SETSUBSCRIPTION

	@Test
	void test() {
		Date date = new Date();
		SubscriptionPlan testSubscriptionPlan = new SubscriptionPlan("4GB");
		Subscription testSubscription = new Subscription(date,testSubscriptionPlan);
		ExistingCustomer testCustomer = new ExistingCustomer("55555555555");
		testCustomer.setsubscription(testSubscription);
		assertEquals(testSubscription,testCustomer.getSubscription());
	}

}
