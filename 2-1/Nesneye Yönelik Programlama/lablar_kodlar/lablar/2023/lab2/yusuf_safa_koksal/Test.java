package yusufsafakoksal;

public class Test {

	public static void main(String[] args) {
		// nesne oluşturma
				NormalKisi kisi1 = new NormalKisi("A", 1, 100);
				NormalKisi kisi2 = new NormalKisi("B", 2, 50);
				Abonman abone1 = new Abonman("C", 1, 15, 4);
				Abonman abone2 = new Abonman("D", 1, 0, 2);

				Sandalye s1 = new Sandalye(1);
				Sandalye s2 = new Sandalye(2);
				Sandalye s3 = new Sandalye(3);
				Sandalye s4 = new Sandalye(4);
				Sandalye s5 = new Sandalye(5);

				Masa masa1 = new Masa();
				Masa masa2 = new Masa();

				//masaya-sandalye ekleme-silme
				masa1.sandalyeEkle(s1);
				masa1.sandalyeEkle(s2);
				masa1.sandalyeEkle(s3);
				// masa1.masaDolulukGoster();

				masa1.sandalyeEkle(s4);
				masa1.sandalyeSil(s2);
				// System.out.println("masa1'den sandalye silme sonrası:");
				// masa1.masaDolulukGoster();

				// System.out.println();
				masa1.sandalyeEkle(s2, 1);
				// System.out.println("masa1'e sandalye ekleme sonrası:");
				// masa1.masaDolulukGoster();

				masa2.sandalyeEkle(s4);
				masa2.sandalyeEkle(s5);

				// System.out.println("masa2'ye sandalye ekleme sonrası:");
				// masa2.masaDolulukGoster();

				System.out.println("----- LAB2 -----");

				KitapKafe kafe = new KitapKafe(2);
				kafe.masaEkle(masa1);
				kafe.masaEkle(masa2);

				// System.out.println("\nkafedeki tüm masaları göster");
				// kafe.tumMasalariGoster();

				System.out.println("\nAtama onceki durum:\t" + kisi1);
				kafe.yerAyir(kisi1);
				System.out.println("Atama sonrası durum:\t" + kisi1);

				System.out.println("\nAtama onceki durum:\t" + kisi2);
				kafe.yerAyir(kisi2);
				System.out.println("Atama sonrası durum:\t" + kisi2);

				System.out.println("\nAtama onceki durum:\t" + abone1);
				kafe.yerAyir(abone1);
				System.out.println("Atama sonrası durum:\t" + abone1);

				System.out.println("\nAtama onceki durum:\t" + abone1);
				kafe.yerAyir(abone1);
				System.out.println("Atama sonrası durum:\t" + abone1);

				System.out.println("\nAtama onceki durum:\t" + abone2);
				kafe.yerAyir(abone2);
				System.out.println("Atama sonrası durum:\t" + abone2);

				System.out.println("\nAtama onceki durum:\t" + kisi1);
				kafe.yerAyir(kisi1);
				System.out.println("Atama sonrası durum:\t" + kisi1);

				System.out.println("\nAtama onceki durum:\t" + kisi1);
				kafe.yerAyir(kisi1);
				System.out.println("Atama sonrası durum:\t" + kisi1);

				System.out.println("\nkafedeki tüm masaları göster");
				kafe.tumMasalariGoster();
	}

}
