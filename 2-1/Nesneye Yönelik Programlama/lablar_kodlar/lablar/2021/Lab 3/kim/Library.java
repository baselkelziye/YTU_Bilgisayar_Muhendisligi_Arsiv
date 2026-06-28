package lab3_2021;


import java.util.HashMap;
import java.util.List;
import java.util.Scanner;
import java.util.Map.Entry;

public class Library {
	
	HashMap<Student,Book> hm = new HashMap<Student,Book>();
	List <Student> s_list;
	List <Book> b_list;
	Student snext;
	boolean flag=false;
	
	
    public void borrowBook(List<Student> s_list, List<Book> b_list ){
    	this.s_list = s_list;
    	this.b_list = b_list;
    	int i = 0;
    
    	while(i != b_list.size() ){
    		hm.put(s_list.get(i), b_list.get(i));
    		i++;
    	}
    	
    	snext = s_list.get(i);
   
    }

	public void returnBook(Student s) {
		Book book = null;
		
		for(Entry<Student, Book> m : hm.entrySet())
			if(m.getKey().getId()==s.getId())
				book = m.getValue();

		
		if(book!=null){
			hm.remove(s);
			if(flag!=true){
				hm.put(snext, book);
				if(snext==s_list.get(s_list.size()-1))
					flag=true;
			}
		}
		else {
			System.out.println(s.getName() +" has already returned the book.");
			return;
		}
			
		
		int i=0;
		while(i!= s_list.size()-1){
			if(s_list.get(i) == snext){
				snext = s_list.get(i+1);
				break;
			}
			i++;
		}
	}

	
	public void mapPrint() {
		for (Entry<Student, Book> m : hm.entrySet()) {
			System.out.println(m.getKey().getId() + " numbered student borrowed -> " + m.getValue().getName());

		}
		if(hm.isEmpty()==true)
			System.out.println("No students to borrow book");
		
	}
	
	public void newBook() throws BookException{
		
		Scanner in = new Scanner(System.in);
		System.out.println("Enter book name: ");
		String b_name = in.nextLine();
		System.out.println("Enter author name: ");
		String a_name = in.nextLine();
		in.close();
		
		int i=0;
		while(i!=b_list.size()){
			if(b_list.get(i).getName().equalsIgnoreCase(b_name)  && b_list.get(i).getAuthor().equalsIgnoreCase(a_name)){
				throw new BookException("Library has this book!");
			}
			i++;
		}
		
		b_list.add(new Book(b_name,a_name));
		System.out.println("New book added.");
		
	}
	

		
    
    

}
