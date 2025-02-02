package proje;

import junit.framework.TestCase;

public class TestDateInfo extends TestCase {
	private DateInfo dateInfo;
	
	protected void setUp() {
		dateInfo=new DateInfo(1,2024);
	}
	
	public void testGetStartMonth() {
		int result=dateInfo.getStartMonth();
		assertEquals(result, 1);
	}
	
	public void testGetEndMonth() {
		int result=dateInfo.getEndMonth();
		assertEquals(result, 12);
	}
}
