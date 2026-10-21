package nypProje;

import static org.junit.jupiter.api.Assertions.*;

import java.text.SimpleDateFormat;
import java.util.Date;
import org.junit.jupiter.api.Test;
import java.text.ParseException;

class TestSubscription2 {  //TESTING GETSUBSCRIPTIONDATE

	@Test
	void test() throws ParseException{
		String testStartDate = "07/06/2021";
		SubscriptionPlan testSubscriptionPlan = new SubscriptionPlan("4GB");
		Date testDate=null;
		SimpleDateFormat testFormat = new SimpleDateFormat("dd/MM/yyyy");
		if(testStartDate!=null && testStartDate.trim().length() > 0){
            testDate = testFormat.parse(testStartDate);
       }
		Subscription testSubscription = new Subscription(testDate,testSubscriptionPlan);
		assertEquals(testDate,testSubscription.getSubscriptionStartDate());
	}
}
