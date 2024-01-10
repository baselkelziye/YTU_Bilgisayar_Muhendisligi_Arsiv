package lab3_2021;

import java.util.ArrayList;
import java.util.LinkedList;


public class Test {
	
	public static void main(String[] args) {
		
		Student s1 = new Student (101, "Ellie Brown");
		Student s2 = new Student (102, "Mike Garret");
		Student s3 = new Student (103, "John Doens");
		Student s4 = new Student (104, "Zoey Capp");
		Student s5 = new Student (105, "Eric Palm");
		
		Book b1 = new Book ("1st Book" ,"1st Author");
		Book b2 = new Book ("2nd Book" ,"2nd Author");
		Book b3 = new Book ("3rd Book" ,"3rd Author");
		
		ArrayList<Student> stu_list = new ArrayList<>();
		stu_list.add(s1);
		stu_list.add(s2);
		stu_list.add(s3);
		stu_list.add(s4);
		stu_list.add(s5);
		
		LinkedList<Book> book_list = new LinkedList<>();
		book_list.add(b1);
		book_list.add(b2);
		book_list.add(b3);
		
		System.out.println("********* info *********");
		MyInfoClass.getObjectInfo(s2);
		MyInfoClass.getObjectInfo(b1);
		MyInfoClass.getListInfo(stu_list);
		
		Library lb = new Library();
		lb.borrowBook(stu_list, book_list);
		
		System.out.println("\n******* current match *********");
		lb.mapPrint();
		
		System.out.println("\n******* after s2 returned the book *********");
		lb.returnBook(s2);
		lb.mapPrint();
		
		System.out.println("\n******* after s1 returned the book *********");
		lb.returnBook(s1);
		lb.mapPrint();
		
		System.out.println("\n******* wrong student *********");
		lb.returnBook(s1);
		
		System.out.println("\n******* after s4 returned the book *********");
		lb.returnBook(s4);
		lb.mapPrint();
		
		System.out.println("\n******* after s3 returned the book *********");
		lb.returnBook(s3);
		lb.mapPrint();
		
		System.out.println("\n******* after s5 returned the book *********");
		lb.returnBook(s5);
		lb.mapPrint();
		
		System.out.println("\n******* new book to library *********");
		
		try {
			lb.newBook();
		} catch (BookException e) {
			e.printStackTrace();
		}  
		
		
		
		
		
		

		
	
		
		
		
	}
	

}
