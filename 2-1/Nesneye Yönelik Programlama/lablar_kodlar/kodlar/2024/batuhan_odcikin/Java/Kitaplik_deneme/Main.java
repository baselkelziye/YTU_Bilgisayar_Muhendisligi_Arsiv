package deneme;

public class Main {
	public static void main(String[] args) {
//		Car car = new Car("34 AA 341", "138421452");
//		
//		System.out.println(car.getPlate()); 
//		System.out.println(car.getChassis()); 
		
		int rafSayisi = 5;
		Kitaplik kitaplik = new Kitaplik(rafSayisi);
		
		Kitap ktp1,ktp2,ktp3;
		
		ktp1 = new Kitap("Bozkurtların Ölümü", "Atsız", "123123", 1, 1);
		ktp2 = new Kitap("Bozkurtların Doğuşu", "Atsız", "321321");
		ktp3 = new Kitap("Zehram", "Batuhan", "1111");
		
		if(kitaplik.kitapEkle(ktp1)) 
			System.out.println("Kitap eklenmiştir");
		else 
			System.out.println("Kitap ekleme hatası!!");
	}
}
