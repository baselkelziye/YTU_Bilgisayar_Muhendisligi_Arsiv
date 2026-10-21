package NYO_proje_19011076;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class saniyeKaydet {
	public void kayit(long n) {
		try{    
	           FileWriter fw=new FileWriter("saniyeKayit.txt");    
	           fw.write(String.valueOf(n));    
	           fw.close();    
	          }
		catch(Exception e){System.out.println(e);}    
	    System.out.println("Success...");        
	}
	
	public int oku() {
		String data = null;
		try {
		      File myObj = new File("saniyeKayit.txt");
		      Scanner myReader = new Scanner(myObj);
		      while (myReader.hasNextLine()) {
		        data = myReader.nextLine();
		      }
		      myReader.close();
		    } 
		catch (FileNotFoundException e) {
		      System.out.println("An error occurred.");
		      e.printStackTrace();
		}
		return Integer.parseInt(data);
		 
	}
	public static void main(String[] args) {
		long value;
		saniyeKaydet var = new saniyeKaydet();
		var.kayit(5);
		value = var.oku();
		System.out.println(value);
	}

}
