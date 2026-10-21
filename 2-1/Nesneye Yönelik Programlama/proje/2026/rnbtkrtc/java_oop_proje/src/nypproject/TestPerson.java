package nypproject;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

class TestPerson {
	private static Person person;
	
	@BeforeAll
	private static void setup() {
		person = new Person("Ali",121314);
	}
	
	@Test
	public void checkPersonID() {
		assertEquals(person.getNationalID(),121314);
	}
	@Test
	public void checkPersonName() {
		assertEquals(person.getName(),"Ali");
	}

}
