package tests;
import junit.framework.*;

public class TestOfAllClasses {

    public static Test suite() {
        TestSuite suite = new TestSuite();
        suite.addTestSuite(PaymentInfoTest.class);
        suite.addTestSuite(SubscriptionTest.class);
        suite.addTestSuite(JournalTest.class);
        suite.addTestSuite(IndividualTest.class);
        suite.addTestSuite(DistributorTest.class);
        suite.addTestSuite(DateInfoTest.class);
        suite.addTestSuite(CorporationTest.class);
        return suite;
    }



}
