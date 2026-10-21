package NYO_proje_19011076;

import java.io.File;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class istatistik {
	String n;//oyun sayisi
	private String yaridaKalan;
	private String basarili;
	private String basarisiz;
	private String ortSatir;
	private String zaman; 
	
	public istatistik() {//initilaing constructor
		
	}
	
	public istatistik(String n, String yaridaKalan, String basarili, String basarisiz, String ortSatir, String zaman) {//initilaing constructor
		this.n = n;
		this.yaridaKalan = yaridaKalan;
		this.basarili = basarili;
		this.basarisiz = basarisiz;
		this.ortSatir = ortSatir;
		this.zaman = zaman;
	}
	
	
	
	public String getN() {
		return n;
	}

	public void setN(String n) {
		this.n = n;
	}

	public String getYaridaKalan() {
		return yaridaKalan;
	}

	public void setYaridaKalan(String yaridaKalan) {
		this.yaridaKalan = yaridaKalan;
	}

	public String getBasarili() {
		return basarili;
	}

	public void setBasarili(String basarili) {
		this.basarili = basarili;
	}

	public String getBasarisiz() {
		return basarisiz;
	}

	public void setBasarisiz(String basarisiz) {
		this.basarisiz = basarisiz;
	}

	public String getOrtSatir() {
		return ortSatir;
	}

	public void setOrtSatir(String ortSatir) {
		this.ortSatir = ortSatir;
	}

	public String getZaman() {
		return zaman;
	}

	public void setZaman(String zaman) {
		this.zaman = zaman;
	}

	public void write() {
		try{    
           FileWriter fw=new FileWriter("istatistik.txt");
           String newLine = System.getProperty("line.separator");
           fw.write(n + newLine);
           fw.write(yaridaKalan + newLine);
           fw.write(basarili + newLine);
           fw.write(basarisiz + newLine);
           fw.write(ortSatir + newLine);
           fw.write(zaman + newLine);
           fw.close();      
	    }
		catch(Exception e){System.out.println(e);}    
	    System.out.println("Success...");  
	}
	
	public void read() {
		try {
		      File myObj = new File("istatistik.txt");
		      Scanner myReader = new Scanner(myObj);
		      
		      n = myReader.nextLine();
		      yaridaKalan = myReader.nextLine();
		      basarili = myReader.nextLine();
		      basarisiz = myReader.nextLine();
		      ortSatir = myReader.nextLine();
		      zaman = myReader.nextLine();
		      //System.out.println(n + "-" + yaridaKalan+ "-" + Double.parseDouble(zaman));
		      myReader.close();
		    } 
		catch (FileNotFoundException e) {
		      System.out.println("An error occurred.");
		      e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		istatistik var = new istatistik();
		var.read();
		var.setN(Integer.parseInt(var.getN())+1+"");
		var.write();
		System.out.println();
		
		

	}

}
