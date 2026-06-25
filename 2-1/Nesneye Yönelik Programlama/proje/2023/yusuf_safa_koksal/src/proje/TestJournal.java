package proje;

import java.util.Hashtable;

import junit.framework.TestCase;

public class TestJournal extends TestCase {
	private Journal journal;
	
	protected void setUp() {
		journal=new Journal("Etik Dergisi","test",100,1);
	}
	
	public void testGetName() {
		String result=journal.getName();
		assertEquals(result, "Etik Dergisi");
	}
	
	public void testGetFrequency() {
		int result=journal.getFrequency();
		assertEquals(result, 100);
	}
}
