package myPackage;

import static org.junit.Assert.*;


import org.junit.Test;

public class EquationTest {
	@Test
	
	
	public void testGenerateEquation() {
		int n=15;
		EquationClass[] testInstance = new EquationClass[n];
		for(int i=0;i<n;i++) {
			testInstance[i]=new EquationClass();
			DenklemKontrol denklemInstance = new DenklemKontrol(testInstance[i].getEsitlik());
			assertTrue(denklemInstance.isCorrect());
		}
	}
	@Test
	
	
	public void testDenklemYanlisKontrol() {
		int n=8;
		EquationClass[] testInstance = new EquationClass[n];
		for(int i=0;i<n;i++) {
			testInstance[i]=new EquationClass();
		}
		testInstance[0].setEsitlik("15+13=22");
		testInstance[1].setEsitlik("15*13=22");
		testInstance[2].setEsitlik("15/13=22");
		testInstance[3].setEsitlik("15-13=22");
		testInstance[4].setEsitlik("15+123=28");
		testInstance[5].setEsitlik("27/26=1");
		testInstance[6].setEsitlik("112*2100=22400");
		testInstance[7].setEsitlik("12+13=-1");
		for(int i=0;i<n;i++) {
			DenklemKontrol denklemInstance = new DenklemKontrol(testInstance[i].getEsitlik());
			assertFalse(denklemInstance.isCorrect());
		}
	}
	@Test
	
	public void testDenklemDogruKontrol() {
		int n=8;
		EquationClass[] testInstance = new EquationClass[n];
		for(int i=0;i<n;i++) {
			testInstance[i]=new EquationClass();
		}
		testInstance[0].setEsitlik("11-12=-1");
		testInstance[1].setEsitlik("15*13=195");
		testInstance[2].setEsitlik("15/15=1");
		testInstance[3].setEsitlik("1-1+1/1=1");
		testInstance[4].setEsitlik("15+123=138");
		testInstance[5].setEsitlik("27-26/13=25");
		testInstance[6].setEsitlik("112*200=22400");
		testInstance[7].setEsitlik("12-13=-1");
		for(int i=0;i<n;i++) {
			DenklemKontrol denklemInstance = new DenklemKontrol(testInstance[i].getEsitlik());
			assertTrue(denklemInstance.isCorrect());
		}
	}
	@Test
	public void testOperatorVarMi() {
		int n=8;
		EquationClass[] testInstance = new EquationClass[n];
		for(int i=0;i<n;i++) {
			testInstance[i]=new EquationClass();
			assertTrue(testInstance[i].getEsitlik().contains(Character.toString('-'))
					|| testInstance[i].getEsitlik().contains(Character.toString('*'))
							|| testInstance[i].getEsitlik().contains(Character.toString('/'))
									|| testInstance[i].getEsitlik().contains(Character.toString('+')));
		}
		
	}
	@Test
	
	
	public void testEsittirVarMi() {
		int n=8;
		EquationClass[] testInstance = new EquationClass[n];
		for(int i=0;i<n;i++) {
			testInstance[i]=new EquationClass();
			assertTrue(testInstance[i].getEsitlik().contains(Character.toString('=')));
		}
	}
	@Test
	
	
	public void testEsittirdenSonraSayiVarMi() {
		int n=8;
		EquationClass[] testInstance = new EquationClass[n];
		for(int i=0;i<n;i++) {
			testInstance[i]=new EquationClass();
			int index=testInstance[i].getEsitlik().indexOf('=');
			assertTrue(Integer.parseInt(Character.toString(testInstance[i].getEsitlik().charAt(index+1)))>0 || 
					Integer.parseInt(Character.toString(testInstance[i].getEsitlik().charAt(index+1)))<1000 
					||(Integer.parseInt(Character.toString(testInstance[i].getEsitlik().charAt(index+2)))>0
							 || Integer.parseInt(Character.toString(testInstance[i].getEsitlik().charAt(index+2)))<1000));}
		
	}
	private boolean isNumber(char c) {
		return c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9' || c=='0';
	}
	@Test
	
	public void testEnAzIkiSayiVarMi() {
		int n=8;
		EquationClass[] testInstance = new EquationClass[n];
		for(int i=0;i<n;i++) {
			testInstance[i]=new EquationClass();
			int j=0;
			int test=0;
			int operatorCounter=0;
			while(j<testInstance[i].getEsitlik().length() && test<2) {
				if(isNumber(testInstance[i].getEsitlik().charAt(j))) { 
					if(test<=operatorCounter) {
						test++;
					}
				}
				else{
					operatorCounter++;
				}
				j++;
			}
			assertTrue(test==2);
		}
	}
	
	

}
