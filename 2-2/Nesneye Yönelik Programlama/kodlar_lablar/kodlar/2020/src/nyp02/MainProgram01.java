package nyp02;

public class MainProgram01 {

	public static void main(String[] args) {
		Person oktay;
		oktay = new Person( "Oktay Sinanoðlu" );
		Car rover = new Car( "34 OS 1934" );
		oktay.setCar( rover );
		System.out.println( oktay.introduceSelf() );
		Person aziz = new Person( "Aziz Sancar" );
		System.out.println( aziz.introduceSelf() );
	}
}
