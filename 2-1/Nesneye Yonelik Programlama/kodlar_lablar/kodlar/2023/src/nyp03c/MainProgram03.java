package nyp03c;

public class MainProgram03 {

	public static void main(String[] args) {
		Person oktay = new Person("Oktay Sinanoðlu");
		Car rover = new Car("06 OS 1934");
		rover.setOwner(oktay);

		Person aziz = new Person("Aziz Sancar");
		Car honda = new Car("47 AS 1946",aziz);

		
		//honda.setOwner(oktay); //will lead to an illogical case!
		 
		System.out.println( oktay.introduceSelf() );
		System.out.println( rover.introduceSelf() );
		System.out.println( aziz.introduceSelf() );
		System.out.println( honda.introduceSelf() );
	}

}
