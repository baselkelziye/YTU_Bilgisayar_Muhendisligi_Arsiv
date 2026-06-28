package OrnekUygulamalarDevam;

import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

class Book {  //default erişim belirteci. sadece aynı paket içindeki sınıflardan erişim yapılır.
	int id;
	String name, author, publisher; 
	public Book(int id, String name, String author, String publisher) {  
		this.id = id;  
		this.name = name;  
		this.author = author;  
		this.publisher = publisher;  
		 
	}
	@Override
	public String toString() {
		return "Book [id=" + id + ", name=" + name + ", author=" + author + ", publisher=" + publisher + "]";
	}  
	
	
}

public class Ornek4 {

	public static void main(String[] args) {
		List<Book> kitaplar = new LinkedList<Book>();
		Book b1 = new Book(1, "Pera Palas'ta Gece Yarısı", "Charles King", "Kitap Yayınevi");  
	    Book b2 = new Book(2, "Bir Türk Ailesinin Öyküsü", "İrfan Orga", "Everest Yayınları");  
	    
	    kitaplar.add(b1);
	    kitaplar.add(b2);
	    
	    System.out.println("Kitap listesi for each ile...");
	    for (Book kitap : kitaplar) {
			System.out.println(kitap.name + ", " + kitap.author);
		}
	    
	    
	    System.out.println("\nKitap listesi ListIterator ile...");
	    ListIterator<Book> itr = kitaplar.listIterator();
	    
	    while(itr.hasNext()) {
	    	System.out.println(itr.next().name);	
	    }
	    
	    
	    while(itr.hasPrevious()) {
	    	System.out.println(itr.previous().name);
	    }
	    
	}

}
