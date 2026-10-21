package nypproject;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

class TestHospital {
	
	private static Hospital hospital;
	private static Section firstSection;
	private static Section secondSection;
	
	@BeforeAll
	private static void setup(){
		hospital = new Hospital(12321321,"Hospital1");
		firstSection = new Section(12423,"Section1");
		secondSection = new Section(13413,"Section2");
	}
	
	@AfterEach
	private void afterEach() 
	{
		hospital.clearSectionList();
	}
	
	@Test
	public void checkAddSections() {
		assertNull(hospital.getSection(12423));
		hospital.addSection(firstSection);
		assertNotNull(hospital.getSection(12423));
	}
	
	@Test
	public void checkDuplicateSections() {
		hospital.addSection(firstSection);
		hospital.addSection(secondSection);
		assertThrows(DuplicateInfoException.class,() -> {
			hospital.addSection(secondSection);
		});
	}
}
