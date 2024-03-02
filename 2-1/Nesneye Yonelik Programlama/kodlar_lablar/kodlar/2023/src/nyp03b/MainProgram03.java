package nyp03b;

public class MainProgram03 {

	public static void main(String[] args) {
		
		Person oktay = new Person("Oktay Sinanoðlu");
		Car rover = new Car("06 OS 1934");
		//oktay.setCar(rover);
		rover.setOwner(oktay);
		System.out.println( oktay.introduceSelf() );
		System.out.println( rover.introduceSelf() );

		Person aziz = new Person("Aziz Sancar");
		Car honda = new Car("47 AS 1946");
		aziz.setCar(honda);
		//honda.setOwner(aziz);
		System.out.println( aziz.introduceSelf() );
		System.out.println( honda.introduceSelf() );
	}

}
