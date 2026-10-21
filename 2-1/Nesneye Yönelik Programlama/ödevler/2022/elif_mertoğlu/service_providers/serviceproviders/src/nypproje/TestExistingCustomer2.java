package nypProje;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class TestExistingCustomer2 { //TESTING GETCITIZENSHIPNR

	@Test
	void test() {
		ExistingCustomer testCustomer = new ExistingCustomer("55555555555");
		testCustomer.setCitizenshipNr("44444444444");
		assertEquals("44444444444",testCustomer.getCitizenshipNr());
	}

}
