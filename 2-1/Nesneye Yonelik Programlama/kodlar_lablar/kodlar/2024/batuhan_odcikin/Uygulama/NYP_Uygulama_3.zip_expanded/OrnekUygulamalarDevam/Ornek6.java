package OrnekUygulamalarDevam;

import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

public class Ornek6 {
	
	public static void main(String[] args) {
		

		Map<Integer, String> map = new HashMap<Integer, String>();
		map.put(5, "Fatih");
		map.put(1, "Yasin");
		map.put(17, "Furkan");
		
		
		System.out.println(map);
		
		System.out.println(map.get(5));
		
		System.out.println(map.size());
		
		
		for (Entry<Integer, String> m : map.entrySet()) {
			System.out.println(m.getValue() + ", " + m.getKey());
		}
		map.replace(17, "Furkan", "Tarık");  //map.put(17,"Tarık");
		System.out.println(map);
		
		map.remove(5);
		System.out.println(map);
		
		map.clear();
		System.out.println(map.get(17));
		
		
	}

}
