package Uyg3;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Basit kitaplar
        Book b1 = new Book("111", "Temiz Kod");
        Book b2 = new Book("222", "Veri Yapıları");
        Book b3 = new Book("333", "Algoritmalar");

        // Repository: Generics + HashMap
        Repository<Book> bookRepo = new Repository<>();
        bookRepo.add(b1);
        bookRepo.add(b2);
        bookRepo.add(b3);

        // Interface + ArrayList: User borrowed list
        User ali = new User("U1", "Ali");
        ali.borrow(b1);
        ali.borrow(b3);
        ali.printBorrowed();

        // Kitap arama: Repository + Exception
        System.out.println("\n=== Kitap arama ===");
        try {
            Book found = bookRepo.findById("222");
            System.out.println("Bulunan: " + found);

            // Olmayan ID -> ItemNotFoundException
            bookRepo.findById("999");
        } catch (ItemNotFoundException e) {
            System.out.println("Hata yakalandı: " + e.getMessage());
        }

        // Comparable + Collections.sort: kitapları ada göre sırala
        System.out.println("\n=== Ada göre sıralı kitaplar ===");
        List<Book> allBooks = new ArrayList<>(bookRepo.getAll());
        Collections.sort(allBooks); //compareTo metodunda neye göre sıralanacağı yazıldı.
        for (Book b : allBooks) {
            System.out.println("- " + b);
        }

        // Ali bir kitabı iade etsin
        System.out.println("\nAli -> Temiz Kod'u iade ediyor");
        ali.returnBook("111");
        ali.printBorrowed();
    }
}
