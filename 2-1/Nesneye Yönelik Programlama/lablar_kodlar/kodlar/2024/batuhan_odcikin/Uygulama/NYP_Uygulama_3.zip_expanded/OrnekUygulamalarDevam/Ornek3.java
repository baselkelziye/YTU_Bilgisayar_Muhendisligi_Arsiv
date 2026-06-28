package OrnekUygulamalarDevam;

import java.util.Iterator;
import java.util.LinkedList;

public class Ornek3 {

	public static void main(String[] args) {
		LinkedList<Character> harf = new LinkedList<Character>(); 
		harf.add('Y');
		harf.add('E');
		harf.add('K');
		
		Iterator<Character> itr = harf.iterator();
		
		while(itr.hasNext()) {
			System.out.println(itr.next());
		}
		
		
	}

}
