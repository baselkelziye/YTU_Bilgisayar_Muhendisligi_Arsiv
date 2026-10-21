package nypProje;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class TestPossibleCustomer2 {  //TESTING SETMAIL

	@Test
	void test() {
		PossibleCustomer testCustomer = new PossibleCustomer("55555555555");
		testCustomer.setMail("testCustomer@gmail.com");
		String testedMail = testCustomer.getMail();
		assertEquals("testCustomer@gmail.com",testedMail);
	}

}
