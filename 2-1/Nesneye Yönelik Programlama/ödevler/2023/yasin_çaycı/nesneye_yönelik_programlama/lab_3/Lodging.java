package selahattinyasincayci;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map.Entry;
import java.util.Scanner;

public class Lodging {
	private int counter = 0;
	private HashMap<Personnel, Apartment> hm = new HashMap<>();
	private List<Personnel> p_list = new ArrayList<>();
	private List<Apartment> a_list = new LinkedList<>();
	
	public void placement(List<Personnel> p_list, List<Apartment> a_list) {
		for (Apartment apartment : a_list) {
			hm.put(p_list.get(counter), apartment);
			counter++;
		}
	}
	
	public void placement(Apartment apartment) {
		int counter;
		for (Personnel personel : p_list) {
			counter = 0;
			for (Entry<Personnel, Apartment> m : hm.entrySet()) {
				if(personel.equals(m.getKey())) {
					counter = 1;
				}
			}
			if(counter == 0) {
				hm.put(personel, apartment);
			}
		}
	}
	
	
	public void returnApartment(Personnel p) {
		int counter;
		if(p_list.contains(p)) {
			Apartment apartment = hm.remove(p);
			for (Personnel personel : p_list) {
				counter = 0;
				for (Entry<Personnel, Apartment> m : hm.entrySet()) {
					if(personel.equals(m.getKey())) {
						counter = 1;
					}
				}
				if(counter == 0) {
					hm.put(personel, apartment);
				}
			}
			System.out.println("P_Id: "+ p.getId() + " personel returned the Apartmnt_Id: "+ apartment.getId() + " and new personnel was placed in it.");
		}else {
			System.out.println(p.getId()+","+p.getName()+" has already returned the daire.");
		}
	}
	
	public void mapPrint() {
		for (Entry<Personnel, Apartment> m : hm.entrySet()) {
			System.out.println("P_Id: " + m.getKey().getId()+" personel lives in -> "  + m.getValue().getId());
		}
	}
	
	public boolean match() {
		int counter;
		for (Personnel personel : p_list) {
			counter = 0;
			for (Entry<Personnel, Apartment> m : hm.entrySet()) {
				if(personel.equals(m.getKey())) {
					counter = 1;
					return true;
				}
			}
			if(counter == 0) {
				return false;
			}
		}
		return true;
	}
	
	public void newApartment() {
		String ap_id, type;
		System.out.println("Enter apartment id: ");
		Scanner scanIn = new Scanner(System.in);
		ap_id = scanIn.nextLine();

		System.out.println("Enter type: ");
		type = scanIn.nextLine();
		scanIn.close();
		
		Apartment apartment = new Apartment(Integer.parseInt(ap_id), type);
		
		if(!a_list.contains(apartment)) {
			a_list.add(apartment);
			if(!match()) {
				placement(apartment);
			} else {
				System.out.println("P_Id: "+apartment.getId()+ " has been returned, however, no placement was made because there was no other staff waiting in the line.");
			}
			
		} else {
			try {
				throw  new ApartmentException("Lodging has this apartment!”");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
	}	
	
}
