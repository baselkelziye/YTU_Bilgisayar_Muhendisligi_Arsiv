package nyp04;

public class MainProgram04 {

	public static void main(String[] args) {
		Gallery cars4U = new Gallery("Cars 4 U", 
				new Person("Yunus Emre Selçuk"),30);
		Car bmw = new Car("34 RA 440", null);
		Car audi = new Car("06 AC 432",null);
		if( cars4U.addCar(bmw) ) {
			System.out.println("Adding operation succeeded");
		}
		else {
			System.out.println("Adding operation failed");
		}
		cars4U.addCar(audi);
		System.out.println(cars4U.introduceSelf());
		System.out.println(bmw.introduceSelf());
		if( cars4U.searchCar(bmw) == true ) {
			System.out.println("Search is successful");
		}
		else
			System.out.println("Search has failed");
		if( cars4U.removeCar(audi.getPlate()) == audi )
			System.out.println("Remove operation succeeded");
		else
			System.out.println("Remove operation failed");
		if( cars4U.searchCar(audi) == false ) 
			System.out.println("Last operation has correctly failed");
		else
			System.out.println("Last operation has incorrectly succeeded");
	}
}
