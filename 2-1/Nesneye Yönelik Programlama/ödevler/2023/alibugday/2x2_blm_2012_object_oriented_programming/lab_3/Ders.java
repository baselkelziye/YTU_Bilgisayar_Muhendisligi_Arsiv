package Lab3;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.LinkedList;



public class Ders {
	private String dersAdi;
	private LinkedList<Ogrenci> ogrenciler;
	private int subeASayisi;
	private int subeBSayisi;
	private int ogrenciSayisi;
	
	public Ders(String dersAdi) {
		this.dersAdi = dersAdi;
	}
	
	

	public int getSubeASayisi() {
		return subeASayisi;
	}



	public int getSubeBSayisi() {
		return subeBSayisi;
	}



	public String getDersAdi() {
		return dersAdi;
	}

	public LinkedList<Ogrenci> getOgrenciler() {
		return ogrenciler;
	}
	
	public void dosyaOku() {
		try {
	         FileInputStream fileIn = new FileInputStream("ogrenci.ser");
	         ObjectInputStream in = new ObjectInputStream(fileIn);
	         
	         //Employee e = (Employee) in.readObject();  //tek bir kayıt göndermiş olsam bu şekilde deserialize ederdim.
	         ogrenciler = (LinkedList<Ogrenci>) in.readObject();
	    
	         in.close();
	         fileIn.close();
	      } catch (IOException i) {
	         i.printStackTrace();
	         return;
	      } catch (ClassNotFoundException c) {
	         System.out.println("Employee class not found");
	         c.printStackTrace();
	         return;
	      }
	}
	
	public void gruplaraAyir() {
		ogrenciSayisi = ogrenciler.size();
		subeASayisi = ogrenciSayisi/2;
		subeBSayisi = ogrenciSayisi;  
	}
	
	class hesapla implements  Runnable {
		private int startindis;
		private int lastindis;
		public hesapla(int startindis, int lastindis) {
			this.lastindis = lastindis;
			this.startindis = startindis;
		}
		
		@Override
		public void run() {
			for(int i = startindis;i<lastindis;i++) {
				ogrenciler.get(i).genelNotHesapla();
			}
		}
	    
	  }
	
	public void ekranaYazdir() {
		for(Ogrenci iter:ogrenciler) {
			System.out.println(iter.toString());
		}
	}
	
}
