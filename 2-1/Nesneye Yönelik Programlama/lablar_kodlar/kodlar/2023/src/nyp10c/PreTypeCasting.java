package nyp10c;
import java.util.*;

/* Object içeren eski generic olmayan veri yapýlarý kullaným örneði.
 * Ek soru geldiði için yaptým, yoksa anlatmaya gerek yok.
 * Typecasting obsession örneði olarak belki verilebilir, yine soru gelirse.
 * */
public class PreTypeCasting {
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public static void main(String[] args) {
		LinkedList list = new LinkedList();
		Course oop = new Course("0112562", "Obj. Or. Prog.", 30);
		Student yasar = new Student(9011034,"Yaþar Nuri Öztürk");
		Student yunus = new Student(9011045,"Yunus Emre Selçuk");
		Student fatih = new Student(9011046,"Fatih Çýtlak");
		list.add(oop);
		list.add(yasar);
		list.add(yunus);
		list.add(fatih);
		for( Object iter : list ) {
			System.out.println(iter);
		}
		for( Object iter : list ) {
			if( iter instanceof Course ) {
				Course c = (Course)iter;
				c.addStudent(new Student(111111,"Ahmet Çalýþkan"));
			}
			else if( iter instanceof Student ) {
				Student std = (Student)iter;
				oop.addStudent(std);
			}
		}
		oop.showClassList();
		

	}

}
