package nypProje;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class TestGSMProvider2 {   //TESTING SETNAME

	@Test
	void test() {
		GSMProvider testProvider = new GSMProvider("testProviderName");
		testProvider.setName("TURKCELL");
		assertEquals("TURKCELL",testProvider.getName());
	}

}
