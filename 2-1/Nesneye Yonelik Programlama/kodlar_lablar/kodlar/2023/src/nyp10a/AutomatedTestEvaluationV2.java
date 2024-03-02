package nyp10a;

import static org.junit.Assert.*;
import org.junit.*;

public class AutomatedTestEvaluationV2 {
	private Course oop;
	private Student yasar, cemalnur, fatih, yunus;

	@Before
	public void setUp() throws Exception {
		oop = new Course("0112562", "Obj. Or. Prog.", 3);
		yasar = new Student("09011034","Yaşar Nuri Öztürk");
		fatih = new Student("09011046","Fatih Çıtlak");
		cemalnur = new Student("09011047","Cemalnur Sargut");
		yunus = new Student("09011045","Yunus Emre Selçuk");
	}
	
	public void populateCourse( ) throws Exception {
		oop.addStudent(yasar);
		oop.addStudent(cemalnur);
		oop.addStudent(fatih);
	}

	@Test
	public void testAddingStudentOnceAndTwice() {
		assertTrue(oop.addStudent(yasar));
		assertFalse(oop.addStudent(yasar));
	}

	@Test
	public void testAddingStudentWhenCapacityIsFull() throws Exception {
		populateCourse();
		assertFalse(oop.addStudent(yunus));
	}

	@Test
	public void testFindingStudentsWithDirectID() throws Exception {
		populateCourse();
		assertEquals(oop.findStudent("09011046"), fatih);
	}

	@Test
	public void testFindingStudentsWithGeterMethod() throws Exception {
		populateCourse();
		assertNotNull(oop.findStudent(fatih.getNumber()));
	}
	@Test
	public void testIncreasingCapacityAndAddingNewStudent() throws Exception {
		populateCourse();
		oop.increaseCapacity(4);
		assertTrue(oop.addStudent(yunus));
	}
}
