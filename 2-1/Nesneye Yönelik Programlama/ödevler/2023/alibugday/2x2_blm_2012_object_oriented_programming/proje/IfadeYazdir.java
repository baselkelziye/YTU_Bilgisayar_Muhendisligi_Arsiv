package NYO_proje_19011076;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.*;


//oyun kaydet classi

public class IfadeYazdir {
	ArrayList<Ifade> ifadeler;
	
	public IfadeYazdir(ArrayList<Ifade> ifadeler) {
		this.ifadeler = ifadeler;
	}
	
	
	
	public ArrayList<Ifade> getIfadeler() {
		return ifadeler;
	}



	public void setIfadeler(ArrayList<Ifade> ifadeler) {
		this.ifadeler = ifadeler;
	}



	public  void yaz(IfadeYazdir objeler) {
		
		try {
			String fileName = "oyun_kayit.dat";
			ObjectOutputStream yazici = new ObjectOutputStream( 
					new FileOutputStream( fileName )  );
			yazici.writeObject( objeler.getIfadeler() );
			yazici.close();
			System.out.println("The information you have entered has "
					+ "been successfully saved in file " + fileName);
		} 
		catch( IOException e ) {
			System.out.println("An exception has occured during writing to file.");
			e.printStackTrace();
		}
	}
	
	
	public ArrayList<Ifade> oku() {
		String fileName = "oyun_kayit.dat";
		try {
			ObjectInputStream reader = new ObjectInputStream( 
					new FileInputStream( fileName ));
			@SuppressWarnings("unchecked")
			ArrayList<Ifade> ifadeler = (ArrayList<Ifade>)reader.readObject();
			setIfadeler(ifadeler);
			for( Ifade i : ifadeler ) {
					System.out.println(i);
			}
			reader.close();
		} 
		catch( IOException e ) {
			System.out.println("An exception has occured during file reading.");
			e.printStackTrace();
		} 
		catch( ClassNotFoundException e ) {
			System.out.println("An exception has occured while processing read records.");
			e.printStackTrace();
		}
		
		return ifadeler; 
	}
	
	public static void main(String[] args) {
		ArrayList<Ifade> ifadeler = new ArrayList<Ifade>() ;
		
		IfadeYazdir objeler = new IfadeYazdir(ifadeler);
		
		objeler.oku();
		
		objeler.getIfadeler().get(0).setCurrentRow(2);
		
		objeler.yaz(objeler);
		
		objeler.oku();
		
		//oyun oyn1 = new oyun(objeler.getIfadeler());
		
		System.out.println(objeler.getIfadeler());
		
		
	}
	
}
