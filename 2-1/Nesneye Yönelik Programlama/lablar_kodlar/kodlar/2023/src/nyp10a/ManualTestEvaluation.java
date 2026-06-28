package nyp10a;

public class ManualTestEvaluation {

	public static void main(String[] args) {
		Course oop = new Course("0112562", "Obj. Or. Prog.", 3);
		Student yasar = new Student("09011034","Yaşar Nuri Öztürk");
		if( !oop.addStudent(yasar) )
			System.out.println("Problem #1");
		boolean result;
		result = oop.addStudent(yasar);
		if( result == true )
			System.out.println("Problem #2");
		Student cemalnur = new Student("09011045","Cemalnur Sargut");
		oop.addStudent(cemalnur);
		Student fatih = new Student("09011046","Fatih Çıtlak");
		oop.addStudent(fatih);
		Student yunus = new Student("09011047","Yunus Emre Selçuk");
		if( oop.addStudent(yunus) )
			System.out.println("Problem #3");
		if( oop.findStudent("09011046") != fatih )
			System.out.println("Problem #4");
		if( oop.findStudent(fatih.getNumber()) == null )
			System.out.println("Problem #5");
		oop.increaseCapacity(4);
		if( !oop.addStudent(yunus) )
			System.out.println("Problem #6");
		System.out.println("End of test\n");
	}

}
