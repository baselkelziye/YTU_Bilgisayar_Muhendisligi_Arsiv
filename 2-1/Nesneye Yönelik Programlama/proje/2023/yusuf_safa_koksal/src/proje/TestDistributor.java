package proje;

import java.util.Hashtable;
import java.util.Vector;
import junit.framework.TestCase;

public class TestDistributor extends TestCase{
	private Distributor distributor;
	private Journal journal;
	
	protected void setUp() {
		distributor=new Distributor();
		journal=new Journal("Ahlak","0001",1000,100);
		distributor.addJournal(journal);
	}
	
	public void testAddJournal() { 
		assertFalse(distributor.addJournal(journal));
	}
	
	public void testSearchJournal() {
		assertEquals(distributor.searchJournal(journal.getIssn()), journal);
	}
}
