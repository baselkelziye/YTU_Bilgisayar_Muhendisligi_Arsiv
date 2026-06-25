package nyp02;
import java.util.*;
public class MainProgram02 {

	public static void main(String[] args) {
		System.out.println(args[0] + " " + args[1]);
		Scanner gir = new Scanner(System.in);
		Person oktay;
		System.out.print("Kiþi ismi girin: ");
		String str = gir.nextLine();
		oktay = new Person( str );
		System.out.print("Kiþinin arabasý var mý (e/h)");
		String secim = gir.nextLine();
		if( secim.contains("e") || secim.contains("E") ) {
			System.out.print("Aracýn plakasýný gir");
			Car rover = new Car( gir.nextLine() );
			oktay.setCar( rover );
		}
		System.out.println( oktay.introduceSelf() );
		gir.close();
	}

}
