package lab3_2023;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;
import java.util.Iterator;

public class Lodging {
	private static int counter = 0;
	private HashMap<Personnel, Apartment> hm = new HashMap<>();
	private ArrayList<Personnel> p_list = new ArrayList<>();
	private LinkedList<Apartment> a_list = new LinkedList<>();
	
	public void placement(ArrayList<Personnel> p_list,LinkedList<Apartment> a_list) {
		this.p_list = p_list;
        this.a_list = a_list;
        Iterator<Personnel> pIterator = p_list.iterator();
        Iterator<Apartment> aIterator = a_list.iterator();

        while (pIterator.hasNext() && aIterator.hasNext()) {
             Personnel personnel = pIterator.next();
             Apartment apartment = aIterator.next();
             hm.put(personnel, apartment);
             counter++;
        }
	}	
	public void placement(Apartment apartment) {
		a_list.add(apartment);
		if(p_list.get(counter) != null) {
			hm.put(p_list.get(counter), apartment);
			System.out.println("P_Id"+ p_list.get(counter).getId() + "personel returned the Aprtmnt_Id: " + apartment.getId() +" and new personnel was placed in it" );
			counter++;
			return;
		}
	}
	public void mapPrint() {
		for (Map.Entry<Personnel, Apartment> entry : hm.entrySet()) {
            Personnel p = entry.getKey();
            Apartment a = entry.getValue();
            System.out.println("P_Id: " + p.getId()+"personel lives in -> Apartment "+ a.getId());
        }
	}
	public void returnApartment(Personnel p) {
		Apartment apt = hm.get(p);
		if(apt == null) {
			System.out.println(p.getId()+","+p.getName()+"has already returned the daire");
			return;
		}
		hm.remove(p);
		counter--;
		placement(apt);
	}
	
	public void newApartment() throws ApartmentException {
		Scanner scanner = new Scanner(System.in);

        System.out.print("Daire ID'sini girin: ");
        int id = scanner.nextInt();
        scanner.nextLine(); 

        System.out.print("Daire tipini girin: ");
        String type = scanner.nextLine();
        
        Apartment apt = new Apartment(id,type);
        for (Apartment apartment : a_list) {
			if((apartment.getId() == id) ) {
				throw new ApartmentException("Lodging has this apartment!");
			}
		}
	}
	
	
}
