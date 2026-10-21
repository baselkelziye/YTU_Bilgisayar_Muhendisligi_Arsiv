package ahmetsefacetin;

import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class SubscriptionTest {

    Journal journal = new Journal("Football", "342", 4, 50);

    Subscriber subscriber = new Individual(123, "Sefa", "Home", 1000, "1234-6789", 11, 2024, 123);
    PaymentInfo payment = new PaymentInfo(0.3);
    Subscription subscription = new Subscription(journal, subscriber, payment);


    @Test
    public void canSend() {
        subscription.setCopies(1);
        double amount = journal.getIssuePrice() * (1 - payment.getDiscountRatio()) * subscription.getCopies();
        assertEquals(subscriber.getBalance() >= amount, subscription.canSend());
    }

    @Test
    public void getJournal() {
        assertEquals(subscription.getJournal(), journal);
    }

}