package Uyg3;
import java.util.ArrayList;

public class User implements Identifiable {

    private String id;
    private String name;
    private ArrayList<Book> borrowedBooks;

    public User(String id, String name) {
        this.id = id;
        this.name = name;
        this.borrowedBooks = new ArrayList<>();
    }

    @Override
    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public void borrow(Book book) {
        borrowedBooks.add(book);
    }

    public void returnBook(String isbn) {
        int i = 0;

        while (i < borrowedBooks.size()) { //liste boş ise borrowedBooks.size()==0 olur ve while'a girmez.
            if (borrowedBooks.get(i).getIsbn().equalsIgnoreCase(isbn)) {
                borrowedBooks.remove(i);
            } else {
                i++; 
            }
        }
    }

    public void printBorrowed() {
        if (borrowedBooks.isEmpty()) {
            System.out.println(name + " şu anda ödünç kitap bulundurmuyor.");
        }
        else
        {
            System.out.println(name + " şu anda ödünç aldıkları:");
            for (Book b : borrowedBooks) {
                System.out.println("- " + b);
        }

        }
    }
}
