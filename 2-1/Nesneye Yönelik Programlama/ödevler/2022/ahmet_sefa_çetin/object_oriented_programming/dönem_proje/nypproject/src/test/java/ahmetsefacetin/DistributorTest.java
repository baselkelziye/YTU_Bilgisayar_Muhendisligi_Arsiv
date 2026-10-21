package ahmetsefacetin;

import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class DistributorTest {
    Distributor distributor = new Distributor();
    Journal journal = new Journal("Football", "342", 4, 50);

    Subscriber individual = new Individual(123, "Sefa", "Home", 1000, "1234-6789", 11, 2024, 123);

    @Test
    public void addJournal() {
        distributor.addJournal(journal);
        assertTrue(distributor.searchJournal("342").equals(journal));
    }

    @Test
    public void addSubscriber() {
        distributor.addSubscriber(individual);
        assertTrue(distributor.searchSubscriber(123).equals(individual));
    }
}