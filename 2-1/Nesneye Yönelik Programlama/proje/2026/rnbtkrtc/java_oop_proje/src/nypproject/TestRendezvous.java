package nypproject;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Date;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

class TestRendezvous {
	
	private static Rendezvous rendezvous;
	
	@BeforeAll
	private static void setup() 
	{
		Date date = new Date();
		Doctor doctor = new Doctor("Ali",123445,123412);
		Patient patient = new Patient("Mehmet", 123123);
		rendezvous = new Rendezvous(date,patient,doctor);
	}
	
	@Test
	public void checkPatient() 
	{
		assertEquals(rendezvous.getPatient().getName(),"Mehmet");
	}
	@Test
	public void checkDoctor() {
		assertEquals(rendezvous.getDoctor().getName(),"Ali");
	}

}
