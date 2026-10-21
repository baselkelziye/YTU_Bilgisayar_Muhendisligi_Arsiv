package nypproject;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Date;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

class TestSchedule {

	private static Schedule schedule;
	
	@BeforeAll
	private static void setup(){
		Doctor doctor = new Doctor("Ali",12321,132113);
		schedule = new Schedule(3,doctor);
	}

	@Test
	public void checkmaxPatientLimit() {
		Patient patient = new Patient("Mehmet",131242);
		schedule.addRendezvous(patient, new Date());
		schedule.addRendezvous(patient, new Date());
		schedule.addRendezvous(patient, new Date());
		assertFalse(schedule.addRendezvous(patient, new Date()));
	}
	
	@Test
	public void checklastAddedRendezvous() {
		Patient patient = new Patient("Mehmet",131242);
		schedule.addRendezvous(patient, new Date());
		assertEquals(schedule.getLastAddedRendezvous().getPatient().getName(),"Mehmet");
	}
	
	

}
