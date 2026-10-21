package yelizCengiz;

import static org.junit.jupiter.api.Assertions.*;

import java.io.IOException;
import java.util.Date;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

class TestClass {

	static CRS crs;
	static CRS crs1;
	static Hospital hospital1;
	static Hospital hospital2;
	static Section sec1;
	static Section sec2;
	static Doctor dr1;
	static Doctor dr2;
	static Patient pat1;
	static Patient pat2;
	static Rendezvous rendezvous;
	
	@BeforeAll
	public static void setUp() {
		crs=new CRS();
		crs1=new CRS();
		
		hospital1=new Hospital(123, "hospital1");
		hospital2=new Hospital(456, "hospital2");
		crs.addHospital(123, hospital1);
		crs.addHospital(456, hospital2);
		
		sec1 =new Section(1, "sec1");
		sec2 =new Section(2, "sec2");
		hospital1.addSection(sec1);
		hospital1.addSection(sec2);
			
		dr1 =new Doctor("dr1", 245, 125,4);
		dr2 =new Doctor("dr2", 246, 126,5);
		sec1.addDoctor(dr1);
		sec2.addDoctor(dr2);
		
		pat1=new Patient("patient1", 987);
		pat2=new Patient("patient2", 654);
		crs.addPatient(987, pat1);
		crs.addPatient(654, pat2);
		
		rendezvous=new Rendezvous(new Date(125, 3-1, 9), pat1, dr1);
	}
	
	//schedule
	@Test
	public void testAddRendezvous() {
		assertNotNull(dr1.getSchedule().addRendezvous(pat1, new Date(125, 3-1, 12)));
	}
	@Test
	public void testGetMaxRendezvous() {
		assertEquals(dr2.getSchedule().getMaxPatientPerDay(), 6);
	}
	
	
	//rendezvous
	@Test
	public void testGetPatient() {
		assertEquals(rendezvous.getPatient(), pat1);
	}
	@Test
	public void testGetDateTime() {
		assertEquals(rendezvous.getDateTime(), new Date(125, 3-1, 9));
	}
	
	//doctor
	@Test
	public void testGetDiplomaId() {
		assertEquals(dr1.getDiplomaId(), 125);
	}
	@Test
	public void testGetDoctorNationalId() {
		assertEquals(dr2.getNationalId(), 246);
	}
	
	//patient
	@Test
	public void testGetPatientName() {
		assertEquals(pat1.getName(), "patient1");
	}
	@Test
	public void testAddPatient() {
		Patient pat3=new Patient("patient3", 321);
		crs.addPatient(321, pat3);
		
		assertEquals(crs.getPatients().get((long)321), pat3);
	}
	
	
	//hospital
	@Test
	public void testGetHospitalName() {
		assertEquals(hospital1.getName(),"hospital1");
	}
	
	@Test
	public void testGetSection() {
		assertEquals(hospital1.getSection(2), sec2);
	}
	
	//section	
	@Test
	public void testSearchDoctorInSection() {
		assertEquals(sec1.getDoctor(125), dr1);
	}
	
	@Test
	public void testScheduleToString() {
		assertEquals(sec2.getDoctor(126).getSchedule().getMaxPatientPerDay(), 6);
	}
	
	
	//CRS	
	@SuppressWarnings("deprecation")
	@Test
	public void testMakeRendezvous() {
		assertTrue(crs.makeRendezvous((long)987, 123, 1, 125, new Date(125, 3-1, 9)));
	}

	@Test
	public void testSaveCRS() throws IOException {
		assertTrue(crs.saveTablesToDisk("crs.ser"));
	}
	@Test
	public void testLoadCRS() throws IOException {
		testSaveCRS();
		assertNotNull(crs1.loadTablesToDisk("crs.ser"));
	}
}
