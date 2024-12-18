package Lab3;

public class Main {
	public static void main(String args[]) {
		Ders a = new Ders("ogrenci.ser");
		a.dosyaOku("ogrenci.ser");
		a.hesapla();
		a.ekranaYazdir();
	}

}
