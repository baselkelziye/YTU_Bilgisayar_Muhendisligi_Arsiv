package OrnekUygulamalarDevam;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;



public class Ornek5 {

	public static void main(String[] args) {
		List<Book> kitaplar = new LinkedList<Book>();
		Book b1 = new Book(1, "Pera Palas'ta Gece Yarısı", "Charles King", "Kitap Yayınevi");  
	    Book b2 = new Book(1, "Bir Türk Ailesinin Öyküsü", "İrfan Orga", "Everest Yayınları");  
	    
	    kitaplar.add(b1);
	    kitaplar.add(b2);
	    

		List<Student> stu_list = new ArrayList<>();	    
        Student s1 = new Student(17011001,"Mehmet Akif Ersoy", 20);  
		Student s2 = new Student(17011010,"Abdülhak Hamit Tarhan", 22);  
		Student s3 = new Student(17011100,"Mithat Cemal Kuntay", 19);
		
		stu_list.add(s1);
		stu_list.add(s2);
		stu_list.add(s3);
		
		System.out.println(stu_list.get(0));
		System.out.println(kitaplar.get(1));
		
		stu_list.add(0, s2);
		System.out.println(stu_list.get(0));
		
		
	}

	

}
