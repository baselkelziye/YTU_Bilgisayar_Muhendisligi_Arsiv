package Uyg3;
public class Book implements Identifiable, Comparable<Book> {

    private String isbn;
    private String title;

    public Book(String isbn, String title) {
        this.isbn = isbn;
        this.title = title;
    }

    @Override
    public String getId() {
        return isbn; // benzersiz kimlik olarak ISBN
    }

    public String getIsbn() {
        return isbn;
    }

    public String getTitle() {
        return title;
    }

    @Override
    public int compareTo(Book other) {
        return this.title.compareToIgnoreCase(other.title);
    }

	@Override
	public String toString() {
		return "Book [isbn=" + isbn + ", title=" + title + "]";
	}

	


    
}
