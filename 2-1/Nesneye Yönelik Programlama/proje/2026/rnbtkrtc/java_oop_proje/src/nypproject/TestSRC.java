package nypproject;

import static org.junit.jupiter.api.Assertions.*;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Date;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

class TestSRC {

	private static CRS crs;
	private static Hospital hospital;
	private static Section section;
	private static Doctor doctor;
	private static Patient patient;	
	private Path path = Paths.get(System.getProperty("user.home"), "nypprojectstorage");
	@BeforeAll
	private static void setup(){
		crs = new CRS(false);
		hospital = new Hospital(151315,"Hospital1");
		section = new Section(132141,"Section1");
		doctor = new Doctor("Ali", 12351, 12381);
		patient = new Patient("Mehmet", 15312);
		crs.addHospital(hospital);
		hospital.addSection(section);
		section.addDoctor(doctor);
		crs.addPatient(patient);
		
	}
	
	@AfterEach
	private void afterEach() {
		crs.clearRendezvous();
	}

	@Test
	public void checkCreatingRandezvousExistingID() {
		assertTrue(crs.makeRandezvous(15312, 151315, 132141, 12381, new Date()));
	}
	
	@Test
	public void checkCreatingRandezvousFalseID() {
		assertThrows(IDException.class,() -> {
			crs.makeRandezvous(99999, 151315, 132141, 12381, new Date());
		});
	}
	
	@Test
	public void checkSaveAndLoad() {
		crs.saveTablesToDisk(path.toString());
		crs.loadTablesToDisk(path.toString());
		assertTrue(crs.makeRandezvous(15312, 151315, 132141, 12381, new Date()));
		
	}

}
