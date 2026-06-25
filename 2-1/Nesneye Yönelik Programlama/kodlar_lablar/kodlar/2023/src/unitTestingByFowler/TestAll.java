package unitTestingByFowler;

import junit.framework.*;
public class TestAll {
	public static Test suite( ) {
		TestSuite suite = new TestSuite("Bütün testler");
		suite.addTestSuite(TestCustomer.class);
		suite.addTestSuite(TestMovie.class);
		return suite;
	}
}
