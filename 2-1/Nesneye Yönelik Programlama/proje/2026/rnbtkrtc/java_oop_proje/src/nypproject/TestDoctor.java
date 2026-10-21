package nypproject;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

class TestDoctor {
	
	private static Doctor doctor;

	@BeforeAll
	private static void setup(){
		doctor = new Doctor("Ali",123213,124141);
	}

	@Test
	public void checkDiplomaID() {
		assertEquals(doctor.getDiplomaID(),124141);
	}
	
	@Test
	public void checkScheduleInitialization() {
		Schedule schedule = doctor.getSchedule();
		assertNotNull(schedule);
	}

}
