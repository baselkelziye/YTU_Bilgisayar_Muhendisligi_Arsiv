public class Book implements Identifiable, Comparable<Book> {
    private String isbn;
    private String title;

    public Book(String isbn, String title) {
        this.isbn = isbn;
        this.title = title;
    }

    public String getIsbn() {
        return isbn;
    }

    public String getId() {
        return getIsbn();
    }

    public String getTitle() {
        return title;
    }

    public int compareTo(Book other) {
        return this.title.compareToIgnoreCase(other.title);
    }

    public String toString() {
        return "Book{" + "isbn=" + isbn + ", title=" + title + '}';
    }
}
