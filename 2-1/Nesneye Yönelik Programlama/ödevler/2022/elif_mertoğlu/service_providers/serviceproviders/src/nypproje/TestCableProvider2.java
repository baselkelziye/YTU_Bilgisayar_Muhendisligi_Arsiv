package nypProje;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class TestCableProvider2 {   //TESTING GETNAME

	@Test
	void test() {
		CableProvider testProvider = new CableProvider("testCableName");
		assertEquals("testCableName",testProvider.getName());
	}

}
