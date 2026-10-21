package NYO_proje_19011076;

import java.io.*;
import java.util.Scanner;

public class currentRowKayit {
	public void kayit(int n) {
		try{    
	           FileWriter fw=new FileWriter("currentRow.txt");    
	           fw.write(String.valueOf(n));    
	           fw.close();    
	          }
		catch(Exception e){System.out.println(e);}    
	    System.out.println("Success...");        
	}
	
	public int oku() {
		String data = null;
		try {
		      File myObj = new File("currentRow.txt");
		      Scanner myReader = new Scanner(myObj);
		      while (myReader.hasNextLine()) 
		      {
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
		currentRowKayit var = new currentRowKayit();
		var.kayit(2);
		int var2 = var.oku();
		System.out.println("sonuc:"+var2);

	}

}
