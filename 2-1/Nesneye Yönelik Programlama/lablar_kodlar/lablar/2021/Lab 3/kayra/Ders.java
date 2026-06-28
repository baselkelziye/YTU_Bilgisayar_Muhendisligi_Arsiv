package Lab3;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.LinkedList;

import java.io.FileInputStream;

public class Ders{
	private String dersAdi;
	private LinkedList<Ogrenci> ogrenciler;
	private int subeASayisi;
	private int subeBSayisi;
	private int ogrenciSayisi;
	public Ders(String dersAdi) {
		this.dersAdi=dersAdi;
		this.subeASayisi=0;
		this.subeBSayisi=0;
		this.ogrenciSayisi=0;
		ogrenciler = new LinkedList<Ogrenci>();
	}
	public void gruplaraAyir() {
		subeBSayisi=ogrenciler.size()/2;
		subeASayisi=(ogrenciler.size()+1)/2;
		ogrenciSayisi=ogrenciler.size();
	}
	public String getDersAdi() {
		return dersAdi;
	}
	public LinkedList<Ogrenci> getOgrenciler() {
		return ogrenciler;
	}
	public void dosyaOku(String dosyaAdi) {
		try{
            FileInputStream fis = new FileInputStream(dosyaAdi);
            ObjectInputStream objIn = new ObjectInputStream(fis);
            ogrenciler = (LinkedList<Ogrenci>) objIn.readObject();
            objIn.close();
            fis.close();
        } catch (IOException e){
            System.out.println(e);
        } catch(ClassNotFoundException e){
            e.printStackTrace();
        }
	}
	public class Hesapla implements Runnable {
		private LinkedList<Ogrenci> A;
		public void run() {
			for(int i=0;i<A.size();i++) {
				A.get(i).genelNotHesapla();
			}
		}
		public Hesapla(LinkedList<Ogrenci> A) {
			this.A=A;
		}
		}
	public  void hesapla() {
		LinkedList<Ogrenci> A = new LinkedList<>();
		LinkedList<Ogrenci> B = new LinkedList<>();
		for(int i=0;i<ogrenciler.size();i++) {
			if(i<subeASayisi) {
				A.add(ogrenciler.get(i));
			}
			else {
				B.add(ogrenciler.get(i));
			}
		}
		Thread hesapla1= new Thread(new Hesapla(A));
		Thread hesapla2= new Thread(new Hesapla(B));
		hesapla1.start();
		hesapla2.start();
		try {
			hesapla1.join();
			hesapla2.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	public synchronized void ekranaYazdir() {
		for(Ogrenci myOgrenci: ogrenciler) {
			System.out.println(myOgrenci);
		}
	}
}
