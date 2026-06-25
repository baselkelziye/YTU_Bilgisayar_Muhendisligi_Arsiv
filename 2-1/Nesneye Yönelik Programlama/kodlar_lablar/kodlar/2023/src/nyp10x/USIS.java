package nyp10x;

public class USIS {

	public static void main(String[] args) {
		Course oop = new Course("0112562", "Obj. Or. Prog.", 3);
		Student yasar = new Student("09011034","Yaþar Nuri Öztürk");
		if( !oop.addStudent(yasar) )
			System.out.println("Problem #1");
		if( oop.addStudent(yasar) )
			System.out.println("Problem #2");
		Student yunus = new Student("09011045","Yunus Emre Selçuk");
		oop.addStudent(yunus);
		Student fatih = new Student("09011046","Fatih Çýtlak");
		oop.addStudent(fatih);
		Student cemal = new Student("09011047","Cemalnur Sargut");
		if( oop.addStudent(cemal) )
			System.out.println("Problem #3");
		if( oop.findStudent("09011046") != fatih )
			System.out.println("Problem #4");
		if( oop.findStudent(fatih.getNumber()) == null )
			System.out.println("Problem #5");
		System.out.println("End of test");
		oop.showClassList();
		
		
		
	}

}
