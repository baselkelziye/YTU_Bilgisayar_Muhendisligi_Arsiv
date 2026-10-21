package nypProje;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class TestPossibleCustomer1 {

	@Test
	void test() {
		PossibleCustomer testCustomer = new PossibleCustomer("55555555555");
		testCustomer.setName("Elif");
		assertEquals("Elif",testCustomer.getName());
	}

}
