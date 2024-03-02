package nyp01d;

import java.util.Scanner;

public class MainTest {
	   public static void main( String[] args ) {
		      Car aCar;
		      Scanner input = new Scanner( System.in );
		      System.out.print("Enter a license plate: ");
		      String plateNr =  input.nextLine( );
		      aCar = new Car( plateNr );
		      aCar.introduceSelf( );
		      input.close();
		   }

}
