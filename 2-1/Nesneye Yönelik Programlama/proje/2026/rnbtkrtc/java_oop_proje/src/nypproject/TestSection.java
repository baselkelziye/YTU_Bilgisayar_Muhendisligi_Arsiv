package nypproject;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

class TestSection {

	private static Section section;
	private static Doctor firstDoctor;
	private static Doctor secondDoctor;
	
	@BeforeAll
	private static void setup(){
		section = new Section(13213,"Section1");
		firstDoctor = new Doctor("Ali",23214,15214);
		secondDoctor = new Doctor("Mehmet",41231,15654);
	}
	@AfterEach
	private void afterEach() 
	{
		section.clearDoctorList();
	}

	@Test
	public void checkAddDoctors() {
		assertNull(section.getDoctor(15214));
		section.addDoctor(firstDoctor);
		assertNotNull(section.getDoctor(15214));
	}
	
	@Test
	public void checkDuplicateDoctors() {
		section.addDoctor(firstDoctor);
		section.addDoctor(secondDoctor);
		assertThrows(DuplicateInfoException.class,() -> {
			section.addDoctor(secondDoctor);
		});
	}

}
