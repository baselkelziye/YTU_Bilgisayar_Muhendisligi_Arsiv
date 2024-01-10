package nyp01c;

public class StringOps02 {
	   public static void main( String args[] ) {
			String strA = "Ýstanbul", strB = "Yýldýz";
			System.out.println(strA.contains(strB));
			strB = "tan";
			System.out.println(strA.contains(strB));
			strB.toUpperCase();
			System.out.println(strB);
			System.out.println(strA.contains(strB));
			strB = strB.toUpperCase();
			System.out.println(strB);
			System.out.println(strA.contains(strB));
		   }
}
