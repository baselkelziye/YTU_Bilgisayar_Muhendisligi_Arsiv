package Lab3;

import Lab3.Ders.hesapla;

public class Test {

	public static void main(String[] args) {
		Ders aDers = new Ders("NYP");
		aDers.dosyaOku();
		aDers.gruplaraAyir();
		
		hesapla subeA = aDers.new hesapla(0,aDers.getSubeASayisi());
		hesapla subeB = aDers.new hesapla(aDers.getSubeASayisi(), aDers.getSubeBSayisi());
		
		Thread t1 = new Thread(subeA);
		Thread t2 = new Thread(subeB);
		t1.start();
		t2.start();
		
		aDers.ekranaYazdir();

	}

}
