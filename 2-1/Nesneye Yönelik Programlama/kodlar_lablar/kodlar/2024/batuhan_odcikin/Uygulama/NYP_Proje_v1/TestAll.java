package nyp_project;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.util.Date;

import org.junit.Before;
import org.junit.Test;

public class TestAll {
	
	private CRS crs;
	private Doctor doctor;
	private Patient patient;
	public static String file_path = System.getProperty("user.dir") + "/data.txt";
	
	@Before
	public void setUp() {
		crs = new CRS();
		Date date = new Date(19,05,2024);
		
		patient = new Patient("Batuhan2", 1233);
		doctor = new Doctor("Mehmet2", 112, 123123,1);

}
	
	
	@Test
	public void testDoctorGetName() {
		assertEquals("Mehmet2", doctor.getName());
	}
	
	@Test
	public void testDoctortoString() {
		Doctor doctor = new Doctor("Hüseyin",453632,12,5);
		assertEquals("Person [name=" + "Hüseyin" + ", national_id=" + 453632 + "]", doctor.toString());
	}
	
	@Test
	public void testHospital_AddSection() throws DuplicateException{
		 Hospital hospital = new Hospital(1, "Test Hastane");
		    Section section1 = new Section(101, "Kardiyoloji");
		    Section section2 = new Section(102, "Neroloji");
		    Section duplicateSection = new Section(101, "Duplicate");

		    hospital.AddSection(section1);
		    assertEquals(1, hospital.getSections().size());

		    hospital.AddSection(section2);
		    assertEquals(2, hospital.getSections().size());

		    Exception exception = null;
		    try {
		        hospital.AddSection(duplicateSection);
		    } catch (DuplicateException e) {
		        exception = e;
		    }
		    assertEquals("Duplicate error! - Already a section added with same id.", exception.getMessage());

	}
	
	@Test
	public void testHospital_getSection() throws DuplicateException{
		Hospital hospital = new Hospital(1, "Test Hastane");
	    Section section1 = new Section(101, "Kardiyoloji");
	    Section section2 = new Section(102, "Nöroloji");

	    hospital.AddSection(section1);
	    hospital.AddSection(section2);

	    assertEquals(section1, hospital.getSection(101));
	    assertEquals(section2, hospital.getSection(102));

	    assertEquals(section1, hospital.getSection("Kardiyoloji"));
	    assertEquals(section2, hospital.getSection("Nöroloji"));

	    assertEquals(null, hospital.getSection(999));
	    assertEquals(null, hospital.getSection("NonExistent"));
	}
	
	@Test
	public void testAddRendezvous_Success() {

	    Schedule schedule = new Schedule(3);
	    Patient patient1 = new Patient("Patient1", 101);
	    Patient patient2 = new Patient("Patient2", 102);
	    Doctor doctor = new Doctor("Doctor",453234,12,10);
	    Date date = new Date();

	    boolean result1 = schedule.addRandezvous(patient1, date,doctor);
	    assertEquals(result1,true);
	    assertEquals(1, schedule.getSessions().size());

	    boolean result2 = schedule.addRandezvous(patient2, date,doctor);
	    assertEquals(result2,true);
	    assertEquals(2, schedule.getSessions().size());
	}
	
	@Test
	public void testAddRendezvous_MaxLimitExceeded() {

	    Schedule schedule = new Schedule(2);
	    Patient patient1 = new Patient("Patient1", 101);
	    Patient patient2 = new Patient("Patient2", 102);
	    Patient patient3 = new Patient("Patient3", 103);
	    
	    Doctor doctor = new Doctor("Doctor", 345234, 12, 10);
	    
	    Date date = new Date(); 

	    assertEquals(schedule.addRandezvous(patient1, date,doctor),true);
	    assertEquals(schedule.addRandezvous(patient2, date,doctor),true);

	    boolean result = schedule.addRandezvous(patient3, date,doctor);
	    assertEquals(result,false);
	    assertEquals(2, schedule.getSessions().size()); // The size should still be 2
	}
	
	@Test
	public void testPerson_ConstructorAndToString() {

	    Person person = new Person("Ahmet Veli", 123456789L);

	    String expectedString = "Person [name=Ahmet Veli, national_id=123456789]";
	    assertEquals(expectedString, person.toString());
	}

	@Test
	public void testPerson_Getters() {

	    Person person = new Person("Altay", 987654321L);

	    assertEquals("Altay", person.getName());
	    assertEquals(987654321L, person.getNational_id());
	}
	
	@Test
	public void testPatient_ConstructorAndGetters() {
	    Patient patient = new Patient("Altay", 123456789L);

	    assertEquals("Altay", patient.getName());
	    assertEquals(123456789L, patient.getNational_id());
	}

	@Test
	public void testPatient_ToString() {

	    Patient patient = new Patient("Mehmet", 987654321L);

	    String expectedString = "Person [name=Mehmet, national_id=987654321]";
	    assertEquals(expectedString, patient.toString());
	}
	
	@Test
	public void testAddDoctor_Success() throws DuplicateException {

	    Section section = new Section(101, "Kardiyoloji");

	    Doctor doctor = new Doctor("Mehmet", 123, 987654321, 10);

	    section.AddDoctor(doctor);
	    assertEquals(1, section.getDoctors().size());
	    assertEquals(doctor, section.getDoctors().get(0));
	}
	@Test
	public void testSaveTables() {
		assertEquals(crs.saveTablesToDisk(file_path),true);
	}
	
	@Test
	public void testLoadTables() {
		crs.saveTablesToDisk(file_path);
		assertEquals(crs.loadTablesToDisk(file_path),true);
	}

}
