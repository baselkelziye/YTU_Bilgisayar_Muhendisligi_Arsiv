import java.util.ArrayList;

public class User implements Identifiable{
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

    public void returnBook(Book book) {
        int i = 0;

        while (i < borrowedBooks.size()) {
            if (borrowedBooks.get(i).getId().equalsIgnoreCase(book.getId())) {
                borrowedBooks.remove(i);
            }
            else {
                i++;
            }
        }
    }

    public void printBorrowed() {
        if (borrowedBooks.isEmpty()) {
            System.out.println("No books borrowed");
        }

        for (Book book : borrowedBooks) {
            System.out.println(book);
        }
    }
}
