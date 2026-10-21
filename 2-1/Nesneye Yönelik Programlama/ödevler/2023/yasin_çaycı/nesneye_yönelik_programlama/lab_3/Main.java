package selahattinyasincayci;

import java.util.ArrayList;
import java.util.LinkedList;

public class Main {

	public static void main(String[] args) {

		Personnel p1 = new Personnel(101, "Ellie Brown");
		Personnel p2 = new Personnel(102, "Mike Garret");

		Personnel p3 = new Personnel(103, "John Doens");
		Personnel p4 = new Personnel(104, "Zoey Capp");
		Personnel p5 = new Personnel(105, "Eric Palm");

		ArrayList<Personnel> per_list = new ArrayList<>();
		per_list.add(p1);
		per_list.add(p2);

		per_list.add(p3);
		per_list.add(p4);
		per_list.add(p5);

		Apartment d1 = new Apartment(1, "standart");
		Apartment d2 = new Apartment(2, "dublex");
		Apartment d3 = new Apartment(3, "standart");

		LinkedList<Apartment> daire_list = new LinkedList<>();
		daire_list.add(d1);
		daire_list.add(d2);
		daire_list.add(d3);

		System.out.println("********* info *********");
		InfoClass.getObjectInfo(p2);
		InfoClass.getObjectInfo(d1);
		InfoClass.getListInfo(per_list);

		Lodging lb = new Lodging();
		lb.placement(per_list, daire_list);

		System.out.println("\n******* current match *********");
		lb.mapPrint();

		System.out.println("\n******* after p2 returned the daire *********");
		lb.returnApartment(p2);
		lb.mapPrint();

		System.out.println("\n******* after p1 returned the book *********");
		lb.returnApartment(p1);
		lb.mapPrint();

		System.out.println("\n******* wrong personal *********");
		lb.returnApartment(p1);

		System.out.println("\n******* after p4 returned the apartment *********");
		lb.returnApartment(p4);
		lb.mapPrint();

		System.out.println("\n******* after p3 returned the apartment *********");
		lb.returnApartment(p3);
		lb.mapPrint();

		System.out.println("\n******* after p5 returned the apartment *********");
		lb.returnApartment(p5);
		lb.mapPrint();

		Personnel p7 = new Personnel(107, "Daniel Hammer");
		per_list.add(p7);

		System.out.println("\n******* new apartment to lodging *********");

		//gerekli düzenlemeleri yapmanız gerektiğini unutmayınız (try-catch).
		try {
		lb.newApartment();
		} catch(Exception e) {
			e.printStackTrace();
		}
		


	}

}