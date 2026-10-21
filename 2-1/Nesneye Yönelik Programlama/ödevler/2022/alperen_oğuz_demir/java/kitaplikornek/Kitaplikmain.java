package kitaplikornek;
import java.util.Scanner;
public class Kitaplikmain {
	
	public static void main(String[] args) {
		int rafsayisi=5;
		Scanner scan=new Scanner(System.in);
		Kitaplik kitaplik=new Kitaplik(rafsayisi);
		Kitap ktp1,ktp2,ktp3,ktp4;
		ktp1 = new Kitap("Pera Palas'ta Gece Yarýsý", "Charles King", "978-605-105-148-2",
				1, 1);
		ktp2 = new Kitap("Ali Emîrî'nin Ýzinde ", "M. Serhan Tayþi",
				"978-975-263-956-0", 1, 0);
		ktp3 = new Kitap("Bir Türk Ailesinin Öyküsü", "Ýrfan Orga", "978-975-289-567-6", 2,
				2);
		ktp4 = new Kitap("Ýnsanlýðýmý Yitirirken", "Osamu Dazai", "435-323-132-643-2",4,3);	
		kitaplik.kitapEkle(ktp1);
		kitaplik.kitapEkle(ktp2);
		kitaplik.kitapEkle(ktp3);
		kitaplik.kitapEkle(ktp4);
		kitaplik.gosterRaf(0);
		kitaplik.gosterRaf(1);
		kitaplik.kitapSil(ktp1);
		kitaplik.gosterRaf(1);
		kitaplik.gosterRaf(2);
		int no;
		do{
		System.out.println("Raf numarasý giriniz: ");
		no = scan.nextInt();
		}while(!kitaplik.rafKontrol(no));
		kitaplik.gosterRaf(no);
		scan.close();
	}
}
