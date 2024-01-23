package lab3_2021;

import java.util.List;

public class MyInfoClass {

	
	public static <T> void getObjectInfo(T obj){
		
		System.out.println(obj);
	//	System.out.println(obj.toString());  // bu şekilde de çağırabiliriz.
}

	public static <E> void getListInfo(List<E> list){
	
		for(E itr : list )
			System.out.println(itr);
	
}

}
