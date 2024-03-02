package nyp10c;

/* Example of using a primitive key that is automatically transformed 
 * to its Wrapper (auto-boxing in Java terminology).
 * */
public class USIS {

	public static void main(String[] args) {
		Course oop = new Course("0112562", "Obj. Or. Prog.", 30);
		Student yasar = new Student(9011034,"Yaþar Nuri Öztürk");
		if( !oop.addStudent(yasar) )
			System.out.println("Problem #1");
		if( oop.addStudent(yasar) )
			System.out.println("Problem #2");
		Student yunus = new Student(9011045,"Yunus Emre Selçuk");
		oop.addStudent(yunus);
		Student fatih = new Student(9011046,"Fatih Çýtlak");
		oop.addStudent(fatih);
		Student cemal = new Student(9011047,"Cemalnur Sargut");
		if( !oop.addStudent(cemal) )
			System.out.println("Problem #3");
		if( oop.findStudent(9011046) != fatih )
			System.out.println("Problem #4");
		System.out.println("End of test");
		Student std = new Student(11011007,"james Bond");
		oop.addStudent(std);
		Student nur = new Student(11011007,"Hayat Nur Arttýran");
		oop.addStudent(nur); //bunu yapabilmemiz bir sorun olacaktýr! 
		if(oop.findStudent(11011007)==nur)
			System.out.println("Problem #5");
		if(oop.findStudent(11011007)!=std)
			System.out.println("Problem #6");
		
		oop.showClassList();
	}

}
